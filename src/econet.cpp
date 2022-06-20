#include "econet.h"

void EcoNet::init(int tx_pin, int boudrate)
{
    serial_485.serial_open(tx_pin, boudrate);
}

void EcoNet::run()
{   
    uint8_t header[10];
    uint8_t payload[1024];
    uint8_t message[1024];
    
    if(serial_485.serial_read_byte() == frame_begin)
    {
        header[0] = frame_begin;
        for(int i = 1; i < 8; i++)
        {
            header[i] = serial_485.serial_read_byte();
        }
        if (debug==1)
        {
            mqtt->publish("avshrs/devices/EcoNet_01/status/header", 
                            buffer_to_string(header, 8).c_str());
        }
        Ecomax_920_Frame_Header ecomax_header = *reinterpret_cast<Ecomax_920_Frame_Header*>(header);    
        
        serial_485.serial_read_bytes(payload, ecomax_header.frame_size);
        int message_size = ecomax_header.frame_size;
        
        for(unsigned int i = 0; i < message_size; i++)
        {
            if (i < 8)
            {
                message[i] = header[i];
            }
            else
            {
                message[i] = payload[i-8];
            }
        }

        if (debug==1)
            {
                mqtt->publish("avshrs/devices/EcoNet_01/status/message", 
                               buffer_to_string(message, message_size).c_str());
            }

        uint8_t crc_hex = crc(message, message_size - 2);

        if(crc_hex == static_cast<uint8_t>(message[message_size - 2]))
        {

            if(ecomax_header.src_address == ecomax_address 
                && ecomax_header.payload_type == ecomax_live_data_frame)
            {
                if (debug==2)
                {
                    mqtt->publish("avshrs/devices/EcoNet_01/status/Ecomax_920_Live_Data_Frame_payload", 
                                    buffer_to_string(message, message_size).c_str());
                }
                ecomax920_payload = *reinterpret_cast<Ecomax_920_Live_Data_Frame_payload*>(payload);
                update_statuses(false);

            }
            else if(ecomax_header.src_address == ecomax_address 
                && ecomax_header.payload_type == ecomax_settings_frame)
            {   
                if (debug==2)
                {
                    mqtt->publish("avshrs/devices/EcoNet_01/status/Ecomax_settings_Frame_payload", 
                                    buffer_to_string(message, message_size).c_str());
                }
                ecomax920_settings_payload = *reinterpret_cast<Ecomax_settings_Frame_payload*>(payload);
                update_statuses(false);
            }
            else if(ecomax_header.src_address == ecoster_address
                && ecomax_header.payload_type == ecoster_frame )
            {
                if (debug==2)
                {
                    mqtt->publish("avshrs/devices/EcoNet_01/status/Ecoster_Live_Data_Frame_payload", 
                                    buffer_to_string(message, message_size).c_str());
                }
                ecoster_payload = *reinterpret_cast<Ecoster_Live_Data_Frame_payload*>(payload);
                update_statuses(false);
            }            
            else if(ecomax_header.src_address == ecoster_address 
                && ecomax_header.payload_type == ecoster_settings_frame)
            {
                if (debug==2)
                {
                    mqtt->publish("avshrs/devices/EcoNet_01/status/Ecoster_Settings_Frame_payload", 
                                    buffer_to_string(message, message_size).c_str());
                }
                ecoster_settings_payload = *reinterpret_cast<Ecoster_Settings_Frame_payload*>(payload);
                update_statuses(false);

            } 

            
        }
        else
        {
            if (debug==1)
            {
                mqtt->publish("avshrs/devices/EcoNet_01/status/crc", "not ok");
                mqtt->publish("avshrs/devices/EcoNet_01/status/crc_hex", 
                               buffer_to_string(crc_hex).c_str());
                mqtt->publish("avshrs/devices/EcoNet_01/status/crc_readed", 
                               buffer_to_string(message[message_size - 2]).c_str());
            }
        }
    }
}


uint8_t EcoNet::crc(uint8_t *message, int size)
{   // crc for frame only with data
    uint8_t tmp = message[0];
    for(int i = 1 ; i < size; i++ )
    {
        tmp = tmp^message[i];
    }
    return tmp;
}

void EcoNet::register_mqtt(PubSubClient *mqtt_)
{
    mqtt = mqtt_;
}


String EcoNet::get_operating_status()
{
    
    switch (ecomax920_payload.operating_status)
    {
        case 0:
            return "Turned Off";
        case 1:
            return "Fire Up";
        case 2:
            return "Work";
        case 3:
            return "3";
        case 4:
            return "Burning Off";
        case 5:
            return "Halted";
        case 6:
            return "6";
        case 7:
            return "7";                    
        case 8:
            return "Cleaning";                    
        case 9:
            return "9";                    
        case 10:
            return "10";   
        default:
            return "NN";
    }

}
String EcoNet::buffer_to_string(uint8_t buf )
{
    return String(buf, HEX);
     
}

String EcoNet::buffer_to_string(uint8_t *buf, int size )
{

    String stream;
    
    if (size > 0)
    {
        for(int i =0; i<size ; i++)
        {
        stream +=  " 0x"+String(buf[i], HEX);
        }
        return stream;
    }
    return " ";
}

String EcoNet::get_boiler_on_off()
{
    if(ecomax920_payload.operating_status > 0)
        return "on";
    else
        return "off";
}

String EcoNet::get_huw_temp()
{
    return String(ecomax920_payload.huw_temp, 1);
}
String EcoNet::get_feeder_temp()
{
    return String(ecomax920_payload.feeder_temp, 1);
}
String EcoNet::get_boiler_temp()
{
    return String(ecomax920_payload.boiler_temp, 1);
}
String EcoNet::get_weather_temp()
{
    return String(ecomax920_payload.weather_temp, 1);
}
String EcoNet::get_exhaust_temp()
{
    return String(ecomax920_payload.exhaust_temp, 1);
}
String EcoNet::get_mixer_temp()
{
    return String(ecomax920_payload.mixer_temp, 1);
}
String EcoNet::get_boiler_return_temp()
{
    return String(ecomax920_payload.boiler_return_temp, 1);
}
String EcoNet::get_upper_buffer_temp()
{
    return String(ecomax920_payload.upper_buffer_temp, 1);
}
String EcoNet::get_lower_buffer_temp()
{
    return String(ecomax920_payload.lower_buffer_temp, 1);
}
String EcoNet::get_flame_sensor()
{
    return String(ecomax920_payload.flame_sensor, 1);
}
String  EcoNet::get_huw_temp_target()
{
    return String(ecomax920_payload.huw_temp_target);
}
String  EcoNet::get_boiler_temp_target()
{
    return String(ecomax920_payload.boiler_temp_target);
}
String  EcoNet::get_mixer_temp_target()
{
    return String(ecomax920_payload.mixer_temp_target);
}
String  EcoNet::get_fuel_level()
{
    return String(ecomax920_payload.fuel_level);
}
String  EcoNet::get_fan_out_power()
{
    return String(ecomax920_payload.fan_out_power);
}
String  EcoNet::get_fan_in_power()
{
    return String(ecomax920_payload.fan_in_power);
}
String EcoNet::get_fuel_stream()
{
    return String(ecomax920_payload.fuel_stream, 1);
}
String EcoNet::get_boiler_power_kw()
{
    return String(ecomax920_payload.boiler_power_kw, 1);
}
String EcoNet::get_power_max_time()
{
    return String(ecomax920_payload.power_max_time);
}
String EcoNet::get_power_medium_time()
{
    return String(ecomax920_payload.power_medium_time);
}
String EcoNet::get_power_min_time()
{
    return String(ecomax920_payload.power_min_time);
}
String EcoNet::get_feeder_time()
{
    return String(ecomax920_payload.feeder_time);
}
String EcoNet::get_ignitions()
{
    return String(ecomax920_payload.ignitions);
}
String EcoNet::get_ignitions_fails()
{
    return String(ecomax920_payload.ignitions_fails);
}
String EcoNet::get_ecoster_home_temp()
{
    return String(ecoster_payload.room_thermostat_home_temp, 1);
}
String EcoNet::get_ecoster_home_temp_target()
{
    return String(ecoster_payload.room_thermostat_temp_target, 1);
} 
String EcoNet::get_huw_pomp_state()
{
    return String(ecomax920_payload.huw_pomp_state);
} 
String EcoNet::get_boiler_pomp_state()
{
    return String(ecomax920_payload.boiler_pomp_state);
} 

void EcoNet::set_huw_temp(uint8_t temp)
{
    if(temp <= 70 && temp >=20)
    {
        uint8_t buf[16] = {0x68, 0x10, 0x00, 0x45, 0x56, 0x30, 0x05, 0x57, 0x01, 0x00, 0x04, 0x01 ,0x05, temp, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size);
    }
    else
    {
        Serial.println("set_huw_temp out of range 20 - 70");
    }
}

void EcoNet::set_huw_min_temp(uint8_t temp)
{
    if(temp <= 69 && temp >=20 && temp < get_huw_temp_target().toInt() && get_huw_temp_target().toInt() > 35)
    {
        uint8_t target_t = get_huw_temp_target().toInt();
        uint8_t hysteresis = target_t - temp; 
        set_huw_temp_hysteresis(hysteresis);
    }
    else
    {
        Serial.println("set_huw_temp out of range 20 - 69");
    }
}

void EcoNet::set_huw_max_temp(uint8_t temp)
{
    if(temp <= 70 && temp >=20)
    {
        uint8_t buf[16] = {0x68, 0x10, 0x00, 0x45, 0x56, 0x30, 0x05, 0x57, 0x01, 0x00, 0x04, 0x01 ,0x05, temp, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size);
    }
    else
    {
        Serial.println("set_huw_temp out of range 20 - 70");
    }
}

void EcoNet::set_huw_temp_hysteresis(uint8_t hysteresis)
{
    if(hysteresis <= 30 && hysteresis >= 1)
    {   
        uint8_t buf[16] = {0x68, 0x0e, 0x00, 0x45, 0x56, 0x30, 0x05, 0x56, 0x05, 0x01, 0x3a, hysteresis, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size);
    }
    else
    {
        Serial.println("set_huw_temp_hysteresis hysteresis out of range 1 - 30");
    }
}


void EcoNet::set_huw_pump_mode(String pump_mode)
{
    uint8_t value = 0xff;
    if(pump_mode == "Priority" || pump_mode == "heat")
        value = 0x01;
    else if(pump_mode == "No_Priority" || pump_mode == "auto")
        value = 0x02;

    else if(pump_mode == "Off"|| pump_mode == "off")
        value = 0x00;
    else
        Serial.println("<set_huw_pump_mode out of range: priority | no_priority | off");
 
    if(value != 0xff)
    {
        uint8_t buf[16] = {0x68, 0x0e, 0x00, 0x45, 0x56, 0x30, 0x05, 0x56, 0x05, 0x01, 0x39, value, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size);
    }
}


void EcoNet::set_huw_container_disinfection(bool state)
{
    uint8_t value = 0xff;

    if(state)
        value = 0x01;
    else
        value = 0x00;

    if (value != 0xff)
    {
        uint8_t buf[16] = {0x68, 0x0e, 0x00, 0x45, 0x56, 0x30, 0x05, 0x56, 0x05, 0x01, 0x3b, value, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size);
    }
}

void EcoNet::set_room_thermostat_summer_winter_mode(String state)
{
    uint8_t value = 0xff;

    if(state == "Winter" || state == "heat")
    {
        value = 0x00;
    }
    else if (state == "Summer" || state == "off")
    {
        value = 0x01;
    }
    else if (state == "Auto" || state == "auto")
    {
        value = 0x02;
    }
    else
    {
        Serial.println("set_room_thermostat_summer_winter_mode winter | summer | auto");
    }

    if (value != 0xff)
    {
        uint8_t buf[16] = {0x68, 0x0e, 0x00, 0x45, 0x56, 0x30, 0x05, 0x56, 0x05, 0x01, 0x3d, value, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size);    
    }

}

void EcoNet::set_boiler_temp(uint8_t temp)
{
    if(temp <= 80 && temp >=35)
    {
        uint8_t buf[16] = {0x68, 0x10, 0x00, 0x45, 0x56, 0x30, 0x05, 0x57, 0x01, 0x00, 0x04, 0x00, 0x05, temp, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size);    
    }
    else
    {
        Serial.println("set_boiler_temp out of range 35 - 80");
    }
}

void EcoNet::set_boiler_on_off(bool state)
{
    uint8_t value = 0xff;

    if(state)
        value = 0x01; 
    else
        value = 0x00;
    
    if (value != 0xff)
    {
        uint8_t buf[16] = {0x68, 0x0b, 0x00, 0x45, 0x56, 0x30, 0x05, 0x3b, value, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size); 
    }
}

void EcoNet::set_mixer_temp(uint8_t temp)
{
    if(temp <= 70 && temp >=20)
    {
        uint8_t buf[16] = {0x68, 0x10, 0x00, 0x45, 0x56, 0x30, 0x05, 0x57, 0x01, 0x00, 0x04, 0x07, 0x05, temp, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size); 
    }
    else
    {
        Serial.println("set_mixer_temp out of range 20 - 70");
    }
}


void EcoNet::set_room_thermostat_night_temp(float temp_)
{
    
    if(temp_ <= 35 && temp_ >=10)
    {
        short temp = temp_*10;
        
        uint8_t uin[2] = {0};
        
        uin[0] = static_cast<uint8_t>(temp);
        uin[1] = static_cast<uint8_t>(temp >> 8);

        uint8_t buf[16] = {0x68, 0x0d, 0x00, 0x45, 0x56, 0x30, 0x05, 0x5d,  0x0b, uin[0], uin[1], 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size); 
    }
    else
    {
        Serial.println("set_room_thermostat_night_temp temp out of range 10 - 35");
    }
}

void EcoNet::set_room_thermostat_day_temp(float temp_)
{
    if(temp_ <= 35 && temp_ >=10)
    {
        short temp = temp_*10;
        
        uint8_t uin[2] = {0};
        
        uin[0] = static_cast<uint8_t>(temp);
        uin[1] = static_cast<uint8_t>(temp >> 8);
        uint8_t buf[16] = {0x68, 0x0d, 0x00, 0x45, 0x56, 0x30, 0x05, 0x5d, 0x0a, uin[0], uin[1], 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size); 
    }
    else
    {
        Serial.println("set_room_thermostat_day_temp temp out of range 10 - 35");
    }
}


void EcoNet::set_room_thermostat_operating_mode(String state)
{   
    uint8_t value = 0xff;
    if (state == "Schedule" || state == "auto")
    {
        value = 0x00;
    }
    else if (state == "Economy")
    {
        value = 0x01;
    }
    else if(state == "Comfort" || state == "heat")
    {
        value = 0x02;
    }
    else if (state == "Outside" || state == "cool")
    {
        value = 0x03;
    }
    else if (state == "Ventilation")
    {
        value = 0x04;
    }
    else if (state == "Party")
    {
        value = 0x05;
    }
    else if (state == "Holiday")
    {
        value = 0x06;
    }
    else if (state == "Frost_protection" || state == "off")
    {
        value = 0x07;
    }
    else
    {
        Serial.println("set_room_thermostat_operating_mode temp out of range comfort | economy | schedule | outside ");
    }
    if (value != 0xff)
    {
        uint8_t buf[16] = {0x68, 0x0c, 0x00, 0x45, 0x56, 0x30, 0x05, 0x5d, 0x01, value, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size); 
    }
}
void EcoNet::set_room_thermostat_hysteresis(float hysteresis)
{

    if(hysteresis <= 5 ) //0x05 0.5C //0x15 1.5C
    {
        uint8_t buf[16] = {0x68, 0x0c, 0x00, 0x45, 0x56, 0x30, 0x05, 0x5d, 0x09, static_cast<unsigned int>(hysteresis*10), 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size); 
    }
    else
    {
        Serial.println("set_room_thermostat_hysteresis out of range 0 - 5");
    }
}

void EcoNet::set_boiler_max_power_kw(uint8_t power_kw)
{
    if(power_kw <= 18 && power_kw >=5)
    {
        uint8_t buf[16] = {0x68, 0x0e, 0x00, 0x45, 0x56, 0x30, 0x05, 0x56, 0x05, 0x01, 0x00, power_kw , 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size); 
    }
    else
    {
        Serial.println("set_boiler_max_power_kw out of range 9 - 18");
    }
}

void EcoNet::set_boiler_mid_power_kw(uint8_t power_kw)
{
    if(power_kw <= 18 && power_kw >=4)
    {
        uint8_t buf[16] = {0x68, 0x0e, 0x00, 0x45, 0x56, 0x30, 0x05, 0x56, 0x05, 0x01, 0x01, power_kw, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size); 
    }
    else
    {
        Serial.println("set_boiler_mid_power_kw out of range 9 - 18");
    }
}
void EcoNet::set_boiler_min_power_kw(uint8_t power_kw)
{
    if(power_kw <= 12 && power_kw >=2)
    {
        uint8_t buf[16] = {0x68, 0x0e, 0x00, 0x45, 0x56, 0x30, 0x05, 0x56, 0x05, 0x01, 0x02, power_kw , 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size); 
    }
    else
    {
        Serial.println("set_boiler_min_power_kw out of range 2 - 6");
    }
}
void EcoNet::set_boiler_max_power_fan(uint8_t fun_max)
{
    if(fun_max <= 60 && fun_max >=28)
    {
        uint8_t buf[16] = {0x68, 0x0e, 0x00, 0x45, 0x56, 0x30, 0x05, 0x56, 0x05, 0x01, 0x03, fun_max, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size);  
    }
    else
    {
        Serial.println("set_boiler_max_power_fan out of range 28 - 60");
    }
}

void EcoNet::set_boiler_mid_power_fan(uint8_t fun_mid)
{
    if(fun_mid <= 30 && fun_mid >=25)
    {
        uint8_t buf[16] = {0x68, 0x0e, 0x00, 0x45, 0x56, 0x30, 0x05, 0x56, 0x05, 0x01, 0x04, fun_mid, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size);      
    }
    else
    {
        Serial.println("set_boiler_mid_power_fan out of range 25 - 30");
    }
}
void EcoNet::set_boiler_min_power_fan(uint8_t fun_min)
{
    if(fun_min <= 25 && fun_min >=17)
    {
        uint8_t buf[16] = {0x68, 0x0e, 0x00, 0x45, 0x56, 0x30, 0x05, 0x56, 0x05, 0x01, 0x05, fun_min, 0x00, 0x16};
        uint8_t size = buf[2];
        buf[size-2] = crc(buf, size -2);
        serial_485.serial_send(buf, size);      
    }
    else
    {
        Serial.println("set_boiler_min_power_fan out of range 17 - 25");
    }
}

String EcoNet::get_huw_pump_mode()
{
    String value;
    if(ecomax920_settings_payload.huw_mode == 0x01)
        // value = "Priority"; //default
        value = "heat";
    else if(ecomax920_settings_payload.huw_mode == 0x02)
        // value = "No_Priority"; //default
        value = "auto";
    else if(ecomax920_settings_payload.huw_mode == 0x00)
        // value = "Off"; //default
        value = "off";        
    return value;
}

String EcoNet::get_huw_temp_hysteresis()
{
    return String(static_cast<unsigned int>(ecomax920_settings_payload.huw_temp_hysteresis));
}

String EcoNet::get_huw_container_disinfection()
{
    return String(static_cast<unsigned int>(ecomax920_settings_payload.huw_container_disinfection));
}

String EcoNet::get_boiler_max_power_kw()
{
    return String(static_cast<unsigned int>(ecomax920_settings_payload.boiler_max_power_kw));
}

String EcoNet::get_boiler_mid_power_kw()
{
    return String(static_cast<unsigned int>(ecomax920_settings_payload.boiler_mid_power_kw));
}

String EcoNet::get_boiler_min_power_kw()
{
    return String(static_cast<unsigned int>(ecomax920_settings_payload.boiler_min_power_kw));
}

String EcoNet::get_boiler_max_power_fan()
{
    return String(static_cast<unsigned int>(ecomax920_settings_payload.boiler_max_power_fan));
}

String EcoNet::get_boiler_mid_power_fan()
{
    return String(static_cast<unsigned int>(ecomax920_settings_payload.boiler_mid_power_fan));
}
String EcoNet::get_boiler_min_power_fan()
{
    return String(static_cast<unsigned int>(ecomax920_settings_payload.boiler_min_power_fan));
}

String EcoNet::get_room_thermostat_summer_winter_mode()
{    
    String value;
     if(ecomax920_settings_payload.boiler_summer_winter_mode == 0x00)
        // value = "Winter"; //default
        value = "heat";
     else if(ecomax920_settings_payload.boiler_summer_winter_mode == 0x01)
        // value = "Summer"; //default
        value = "off";
     else if(ecomax920_settings_payload.boiler_summer_winter_mode == 0x02)
        // value = "Auto"; //default
        value = "auto";  
    return value;
}
String EcoNet::get_room_thermostat_night_temp()
{   
    String value;
    value = String(static_cast<unsigned int>(ecoster_settings_payload.room_thermostat_night_temp_int));
    value += ".";
    value += String(static_cast<unsigned int>(ecoster_settings_payload.room_thermostat_night_temp_fract));
    return value;
}
String EcoNet::get_room_thermostat_day_temp()
{
    String value;
    value = String(static_cast<unsigned int>(ecoster_settings_payload.room_thermostat_day_temp_int));
    value += ".";
    value += String(static_cast<unsigned int>(ecoster_settings_payload.room_thermostat_day_temp_fract));
    return value;
}
String EcoNet::get_room_thermostat_operating_mode()
{
    String value;
    if(ecoster_settings_payload.room_thermostat_operating_mode == 0x00)
        // value = "Schedule";     //default
        value = "auto";     // auto
    else if(ecoster_settings_payload.room_thermostat_operating_mode == 0x01)
        // value = "Economy";      //default
        value = "Economy";   
    else if(ecoster_settings_payload.room_thermostat_operating_mode == 0x02)
        // value = "Comfort";      //default
        value = "heat";      //default
    else if(ecoster_settings_payload.room_thermostat_operating_mode == 0x03)
        // value = "Outside";     //default  
        value = "off";     //default  
    else if(ecoster_settings_payload.room_thermostat_operating_mode == 0x04)
        // value = "Ventilation";      //default   
        value = "off";     //default  
    else if(ecoster_settings_payload.room_thermostat_operating_mode == 0x05)
        // value = "Party";      //default 
        value = "off";     //default  
    else if(ecoster_settings_payload.room_thermostat_operating_mode == 0x06)
        // value = "Holiday";      //default 
        value = "off";     //default   
    else if(ecoster_settings_payload.room_thermostat_operating_mode == 0x07)
        // value = "Frost_protection";      //default
        value = "off";     //default  
    return value;
}

String EcoNet::get_room_thermostat_hysteresis()
{
    float dat = static_cast<unsigned int>(ecoster_settings_payload.room_thermostat_hysteresis);
    float dat2 = static_cast<float>(dat / 10);
    return String(dat2, 1);
}

void EcoNet::update_statuses(bool force)
{
    String topic = "avshrs/devices/EcoNet_01/state/";

    if(force || ecomax920_buffer.huw_temp != get_huw_temp().toFloat())
    {
        mqtt->publish(String(topic + "huw/temp").c_str(), get_huw_temp().c_str());
        ecomax920_buffer.huw_temp = get_huw_temp().toFloat();
    }

    if(force || ecomax920_buffer.operating_status != get_operating_status().toFloat())
    {
        mqtt->publish(String(topic + "boiler/operating_status").c_str(), get_operating_status().c_str());
        mqtt->publish(String(topic + "boiler/on_off").c_str(), get_boiler_on_off().c_str());
        ecomax920_buffer.operating_status = get_operating_status().toFloat();
    }

    if(force || ecomax920_buffer.feeder_temp != get_feeder_temp().toFloat())
    {
        mqtt->publish(String(topic + "boiler/feeder_temp").c_str(), get_feeder_temp().c_str());
        ecomax920_buffer.feeder_temp = get_feeder_temp().toFloat();
    }

    if(force || ecomax920_buffer.boiler_temp != get_boiler_temp().toFloat())
    {
        mqtt->publish(String(topic + "boiler/boiler_temp").c_str(), get_boiler_temp().c_str());
        ecomax920_buffer.boiler_temp = get_boiler_temp().toFloat();
    }
  
    if(force || ecomax920_buffer.boiler_return_temp != get_boiler_return_temp().toFloat())
    {
        mqtt->publish(String(topic + "boiler/return_temp").c_str(), get_boiler_return_temp().c_str());
        ecomax920_buffer.boiler_return_temp = get_boiler_return_temp().toFloat();
    }
    
    if(force || ecomax920_buffer.flame_sensor != get_flame_sensor().toFloat())
    {
        mqtt->publish(String(topic + "boiler/flame_sensor").c_str(), get_flame_sensor().c_str());
        ecomax920_buffer.flame_sensor = get_flame_sensor().toFloat();
    }

    if(force || ecomax920_buffer.upper_buffer_temp != get_upper_buffer_temp().toFloat())
    {
        mqtt->publish(String(topic + "huw/upper_buffer_temp").c_str(), get_upper_buffer_temp().c_str());
        ecomax920_buffer.upper_buffer_temp = get_upper_buffer_temp().toFloat();
    }

    if(force || ecomax920_buffer.lower_buffer_temp != get_lower_buffer_temp().toFloat())
    {
        mqtt->publish(String(topic + "huw/lower_buffer_temp").c_str(), get_lower_buffer_temp().c_str());
        ecomax920_buffer.lower_buffer_temp = get_lower_buffer_temp().toFloat();
    }

    if(force || ecomax920_buffer.weather_temp != get_weather_temp().toFloat())
    {
        mqtt->publish(String(topic + "weather_temp").c_str(), get_weather_temp().c_str());
        ecomax920_buffer.weather_temp = get_weather_temp().toFloat();
    }
 
    if(force || ecomax920_buffer.exhaust_temp != get_exhaust_temp().toFloat())
    {
        mqtt->publish(String(topic + "boiler/exhaust_temp").c_str(), get_exhaust_temp().c_str());
        ecomax920_buffer.exhaust_temp = get_exhaust_temp().toFloat();
    }

    if(force || ecomax920_buffer.mixer_temp != get_mixer_temp().toFloat())
    {
        mqtt->publish(String(topic + "mixer/temp").c_str(), get_mixer_temp().c_str());
        ecomax920_buffer.mixer_temp = get_mixer_temp().toFloat();
    }
    
    if(force || ecomax920_buffer.boiler_power_kw != get_boiler_power_kw().toFloat())
    {
        mqtt->publish(String(topic + "boiler/boiler_power_kw").c_str(), get_boiler_power_kw().c_str());
        ecomax920_buffer.boiler_power_kw = get_boiler_power_kw().toFloat();
    }

    if(force || ecomax920_buffer.fuel_stream != get_fuel_stream().toFloat())
    {
        mqtt->publish(String(topic + "boiler/fuel_stream").c_str(), get_fuel_stream().c_str());
        ecomax920_buffer.fuel_stream = get_fuel_stream().toFloat();
    }

    if(force || ecomax920_buffer.huw_temp_target != get_huw_temp_target().toFloat())
    {
        mqtt->publish(String(topic + "huw/temp_target").c_str(), get_huw_temp_target().c_str());
        ecomax920_buffer.huw_temp_target = get_huw_temp_target().toFloat();
    }

    if(force || ecomax920_buffer.boiler_temp_target != ecomax920_payload.boiler_temp_target)
    {
        mqtt->publish(String(topic + "boiler/temp_target").c_str(), get_boiler_temp_target().c_str());
        ecomax920_buffer.boiler_temp_target = ecomax920_payload.boiler_temp_target;
    }

    if(force || ecomax920_buffer.mixer_temp_target != ecomax920_payload.mixer_temp_target)
    {
        mqtt->publish(String(topic + "mixer/temp_target").c_str(), get_mixer_temp_target().c_str());
        ecomax920_buffer.mixer_temp_target = ecomax920_payload.mixer_temp_target;
    }

    if(force || ecomax920_buffer.fuel_level != ecomax920_payload.fuel_level)
    {
        mqtt->publish(String(topic + "boiler/fuel_level").c_str(), get_fuel_level().c_str());
        ecomax920_buffer.fuel_level = ecomax920_payload.fuel_level;
    }

    if(force || ecomax920_buffer.fan_in_power != ecomax920_payload.fan_in_power)
    {
        mqtt->publish(String(topic + "boiler/fan_in_power").c_str(), get_fan_in_power().c_str());
        ecomax920_buffer.fan_in_power = ecomax920_payload.fan_in_power;
    }
   
    if(force || ecomax920_buffer.fan_out_power != ecomax920_payload.fan_out_power)
    {
        mqtt->publish(String(topic + "boiler/fan_out_power").c_str(), get_fan_out_power().c_str());
        ecomax920_buffer.fan_out_power = ecomax920_payload.fan_out_power;
    }

    if(force || ecomax920_buffer.boiler_power_kw != get_boiler_power_kw().toFloat())
    {
        mqtt->publish(String(topic + "boiler/boiler_power_kw").c_str(), get_boiler_power_kw().c_str());
        ecomax920_buffer.boiler_power_kw = get_boiler_power_kw().toFloat();
    }

    if(force || ecomax920_buffer.huw_pomp_state != ecomax920_payload.huw_pomp_state)
    {
        mqtt->publish(String(topic + "huw/pomp_state").c_str(), get_huw_pomp_state().c_str());
        ecomax920_buffer.huw_pomp_state = ecomax920_payload.huw_pomp_state;
    }

    if(force || ecomax920_buffer.boiler_pomp_state != ecomax920_payload.boiler_pomp_state)
    {
        mqtt->publish(String(topic + "boiler/pomp_state").c_str(), get_boiler_pomp_state().c_str());
        ecomax920_buffer.boiler_pomp_state = ecomax920_payload.boiler_pomp_state;
    }

    if(force || ecomax920_buffer.power_max_time != ecomax920_payload.power_max_time)
    {
        mqtt->publish(String(topic + "boiler/power_max_time").c_str(), get_power_max_time().c_str());
        ecomax920_buffer.power_max_time = ecomax920_payload.power_max_time;
    }    

    if(force || ecomax920_buffer.power_medium_time != ecomax920_payload.power_medium_time)
    {
        mqtt->publish(String(topic + "boiler/power_medium_time").c_str(), get_power_medium_time().c_str());
        ecomax920_buffer.power_medium_time = ecomax920_payload.power_medium_time;
    }

    if(force || ecomax920_buffer.power_min_time != ecomax920_payload.power_min_time)
    {
        mqtt->publish(String(topic + "boiler/power_min_time").c_str(), get_power_min_time().c_str());
        ecomax920_buffer.power_min_time = ecomax920_payload.power_min_time;
    }

    if(force || ecomax920_buffer.feeder_time != ecomax920_payload.feeder_time)
    {
        mqtt->publish(String(topic + "boiler/feeder_time").c_str(), get_feeder_time().c_str());
        ecomax920_buffer.feeder_time = ecomax920_payload.feeder_time;
    }

    if(force || ecomax920_buffer.ignitions != ecomax920_payload.ignitions)
    {
        mqtt->publish(String(topic + "boiler/ignitions").c_str(), get_ignitions().c_str());
        ecomax920_buffer.ignitions = ecomax920_payload.ignitions;
    }

    if(force || ecomax920_buffer.ignitions_fails != ecomax920_payload.ignitions_fails)
    {
        mqtt->publish(String(topic + "boiler/ignitions_fails").c_str(), get_ignitions_fails().c_str());
        ecomax920_buffer.ignitions_fails = ecomax920_payload.ignitions_fails;
    }
   
    if(force || ecoster_buffer.room_thermostat_temp_target != get_ecoster_home_temp_target().toFloat())
    {
        mqtt->publish(String(topic + "room_thermostat/ecoster_home_temp_target").c_str(), get_ecoster_home_temp_target().c_str());
        ecoster_buffer.room_thermostat_temp_target = get_ecoster_home_temp_target().toFloat();
    }

    if(force || ecoster_buffer.room_thermostat_home_temp != get_ecoster_home_temp().toFloat())
    {
        mqtt->publish(String(topic + "room_thermostat/ecoster_home_temp").c_str(), get_ecoster_home_temp().c_str());
        ecoster_buffer.room_thermostat_home_temp = get_ecoster_home_temp().toFloat();
    }

    if(force || ecomax920_settings_buffer.huw_mode != ecomax920_settings_payload.huw_mode)
    {
        mqtt->publish(String(topic + "huw/pump_mode").c_str(), get_huw_pump_mode().c_str());
        ecomax920_settings_buffer.huw_mode = ecomax920_settings_payload.huw_mode;
    }


    if(force || ecomax920_settings_buffer.huw_temp_hysteresis != ecomax920_settings_payload.huw_temp_hysteresis)
    {
        mqtt->publish(String(topic + "huw/temp_hysteresis").c_str(), get_huw_temp_hysteresis().c_str());
        
        uint8_t min_temp = get_huw_temp_target().toInt() - get_huw_temp_hysteresis().toInt();

        mqtt->publish(String(topic + "huw/temp_min_target").c_str(), String(min_temp).c_str());
        ecomax920_settings_buffer.huw_temp_hysteresis = ecomax920_settings_payload.huw_temp_hysteresis;
    }

    if(force || ecomax920_settings_buffer.huw_container_disinfection != ecomax920_settings_payload.huw_container_disinfection)
    {
        mqtt->publish(String(topic + "huw/container_disinfection").c_str(), get_huw_container_disinfection().c_str());
        ecomax920_settings_buffer.huw_container_disinfection = ecomax920_settings_buffer.huw_container_disinfection;
    }
   

    if(force || ecomax920_settings_buffer.boiler_max_power_kw != ecomax920_settings_payload.boiler_max_power_kw)
    {
        mqtt->publish(String(topic + "boiler/max_power_kw").c_str(), get_boiler_max_power_kw().c_str());
        ecomax920_settings_buffer.boiler_max_power_kw = ecomax920_settings_payload.boiler_max_power_kw;
    }

    if(force || ecomax920_settings_buffer.boiler_mid_power_kw != ecomax920_settings_payload.boiler_mid_power_kw)
    {
        mqtt->publish(String(topic + "boiler/mid_power_kw").c_str(), get_boiler_mid_power_kw().c_str());
        ecomax920_settings_buffer.boiler_mid_power_kw = ecomax920_settings_payload.boiler_mid_power_kw;
    }

    if(force || ecomax920_settings_buffer.boiler_min_power_kw != ecomax920_settings_payload.boiler_min_power_kw)
    {
        mqtt->publish(String(topic + "boiler/min_power_kw").c_str(), get_boiler_min_power_kw().c_str());
        ecomax920_settings_buffer.boiler_min_power_kw = ecomax920_settings_payload.boiler_min_power_kw;
    }

    if(force || ecomax920_settings_buffer.boiler_max_power_fan != ecomax920_settings_payload.boiler_max_power_fan)
    {
        mqtt->publish(String(topic + "boiler/max_power_fan").c_str(), get_boiler_max_power_fan().c_str());
        ecomax920_settings_buffer.boiler_max_power_fan = ecomax920_settings_payload.boiler_max_power_fan;
    }

    if(force || ecomax920_settings_buffer.boiler_mid_power_fan != ecomax920_settings_payload.boiler_mid_power_fan)
    {
        mqtt->publish(String(topic + "boiler/mid_power_fan").c_str(), get_boiler_mid_power_fan().c_str());
        ecomax920_settings_buffer.boiler_mid_power_fan = ecomax920_settings_payload.boiler_mid_power_fan;
    }

    if(force || ecomax920_settings_buffer.boiler_min_power_fan != ecomax920_settings_payload.boiler_min_power_fan)
    {
        mqtt->publish(String(topic + "boiler/min_power_fan").c_str(), get_boiler_min_power_fan().c_str());
        ecomax920_settings_buffer.boiler_min_power_fan = ecomax920_settings_payload.boiler_min_power_fan;
    }

    if(force || ecomax920_settings_buffer.boiler_summer_winter_mode != ecomax920_settings_payload.boiler_summer_winter_mode)
    {
        mqtt->publish(String(topic + "room_thermostat/summer_winter_mode").c_str(), get_room_thermostat_summer_winter_mode().c_str());
        ecomax920_settings_buffer.boiler_summer_winter_mode = ecomax920_settings_payload.boiler_summer_winter_mode;
    }

    if(force || ecoster_settings_buffer.room_thermostat_night_temp_int != ecoster_settings_payload.room_thermostat_night_temp_int || 
        ecoster_settings_buffer.room_thermostat_night_temp_fract != ecoster_settings_payload.room_thermostat_night_temp_fract)
     {
        mqtt->publish(String(topic + "room_thermostat/night_temp").c_str(), get_room_thermostat_night_temp().c_str());
        ecoster_settings_buffer.room_thermostat_night_temp_int = ecoster_settings_payload.room_thermostat_night_temp_int;
        ecoster_settings_buffer.room_thermostat_night_temp_fract = ecoster_settings_payload.room_thermostat_night_temp_fract;
    }

    if(force || ecoster_settings_buffer.room_thermostat_day_temp_int != ecoster_settings_payload.room_thermostat_day_temp_int
        || ecoster_settings_buffer.room_thermostat_day_temp_int != ecoster_settings_payload.room_thermostat_day_temp_int)
     {
        mqtt->publish(String(topic + "room_thermostat/day_temp").c_str(), get_room_thermostat_day_temp().c_str());
        ecoster_settings_buffer.room_thermostat_day_temp_int = ecoster_settings_payload.room_thermostat_day_temp_int;
        ecoster_settings_buffer.room_thermostat_day_temp_fract = ecoster_settings_payload.room_thermostat_day_temp_fract;
     }

    if(force || ecoster_settings_buffer.room_thermostat_operating_mode != ecoster_settings_payload.room_thermostat_operating_mode)
    {
        mqtt->publish(String(topic + "room_thermostat/operating_mode").c_str(), get_room_thermostat_operating_mode().c_str());
        ecoster_settings_buffer.room_thermostat_operating_mode = ecoster_settings_payload.room_thermostat_operating_mode;
    }
       
    if(force || ecoster_settings_buffer.room_thermostat_hysteresis != ecoster_settings_payload.room_thermostat_hysteresis)
    {
        mqtt->publish(String(topic + "room_thermostat/hysteresis").c_str(), get_room_thermostat_hysteresis().c_str());
        ecoster_settings_buffer.room_thermostat_hysteresis = ecoster_settings_payload.room_thermostat_hysteresis;
    }

}

