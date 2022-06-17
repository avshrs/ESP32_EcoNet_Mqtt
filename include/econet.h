#pragma once

#include "vars.h"
#include "serial_w.h"
#include "PubSubClient.h"
#include <Vector.h>

class Mqtt_Client;

class EcoNet{
    private:
        SerialW serial_w;
        PubSubClient *mqtt;
         std::vector<uint8_t> header;
         std::vector<uint8_t> payload;
          std::vector<uint8_t> message;
        Econet_Mqtt econet_set_values;
    
        Ecomax_920_Live_Data_Frame_payload ecomax920_payload;
        Ecomax_920_Live_Data_Frame_payload ecomax920_buffer;

        Ecomax_settings_Frame_payload ecomax920_settings_payload;
        Ecomax_settings_Frame_payload ecomax920_settings_buffer;

        Ecoster_Live_Data_Frame_payload ecoster_payload;
        Ecoster_Live_Data_Frame_payload ecoster_buffer;
        
        Ecoster_Settings_Frame_payload ecoster_settings_payload;
        Ecoster_Settings_Frame_payload ecoster_settings_buffer;
        
        uint8_t frame_begin = 0x68;
        uint8_t frame_end = 0x16;

        uint8_t econet_address = 0x56;
        uint8_t econet_frame = 0xb0;  //??
        uint8_t econet_frame_2 = 0x57; //??
        uint8_t econet_frame_3 = 0x89; //??

        uint8_t eco____address = 0x50; //??

        uint8_t ecomax_address = 0x45; // master address
        uint8_t ecomax_live_data_frame = 0x08; // broadcast with live data 
        uint8_t ecomax_frame2 = 0x35; // some kind of broadcast 
        uint8_t ecomax_frame3 = 0x0a; // ask slaves for data / hartbeet  
        uint8_t ecomax_settings_frame = 0xe1; 
        
        uint8_t ecoster_address = 0x51;
        uint8_t ecoster_frame = 0x89;
        uint8_t ecoster_settings_frame = 0xa7;

     
    public:
        bool debug = false;
        void init(int tx_pin);
        void run();
        void register_mqtt(PubSubClient *mqtt_);
        void update_statuses(bool force);
    private:
        void print_buffer(uint8_t *buf, int len);
        String date();
        uint8_t crc(std::vector<uint8_t> &message);
        uint8_t crc_set(std::vector<uint8_t> &message);
        

    public:
        String get_operating_status();
        String get_huw_temp();
        String get_feeder_temp();
        String get_boiler_temp();
        String get_weather_temp();
        String get_exhaust_temp();
        String get_mixer_temp();
        String get_boiler_return_temp();
        String get_upper_buffer_temp();
        String get_lower_buffer_temp();
        String get_flame_sensor();
        String get_ecoster_home_temp();
        String get_ecoster_home_temp_target();
        String get_huw_temp_target();
        String get_boiler_temp_target();
        String get_mixer_temp_target();
        String get_fuel_level();
        String get_fan_out_power();
        String get_fan_in_power();
        String get_huw_pomp_state();
        String get_boiler_pomp_state();
        String get_fuel_stream();
        String get_boiler_power_kw();
        String get_power_max_time();
        String get_power_medium_time();
        String get_power_min_time();
        String get_feeder_time();
        String get_ignitions();
        String get_ignitions_fails();

    public:
        String get_huw_pump_mode();
        String get_huw_temp_hysteresis();
        String get_huw_container_disinfection();
        String get_boiler_on_off();
        String get_boiler_max_power_kw();
        String get_boiler_mid_power_kw();
        String get_boiler_min_power_kw();
        String get_boiler_max_power_fan();
        String get_boiler_mid_power_fan();
        String get_boiler_min_power_fan();
        String get_room_thermostat_summer_winter_mode();
        String get_room_thermostat_night_temp();
        String get_room_thermostat_day_temp();
        String get_room_thermostat_operating_mode();
        String get_room_thermostat_hysteresis();
        String buffer_to_string(uint8_t *buf, int size );
        String buffer_to_string(uint8_t buf );


    public:
        void set_huw_temp(uint8_t temp);
        void set_huw_min_temp(uint8_t temp);
        void set_huw_max_temp(uint8_t temp);
        void set_huw_pump_mode(String pump_mode);
        void set_huw_temp_hysteresis(uint8_t hysteresis);
        void set_huw_container_disinfection(bool state);
        void set_boiler_temp(uint8_t temp);
        void set_boiler_on_off(bool state);
        void set_boiler_max_power_kw(uint8_t power_kw);
        void set_boiler_mid_power_kw(uint8_t power_kw);
        void set_boiler_min_power_kw(uint8_t power_kw);
        void set_boiler_max_power_fan(uint8_t fun_max);
        void set_boiler_mid_power_fan(uint8_t fun_max);
        void set_boiler_min_power_fan(uint8_t fun_max);
        void set_mixer_temp(uint8_t temp);
        void set_room_thermostat_summer_winter_mode(String state);
        void set_room_thermostat_night_temp(float temp);
        void set_room_thermostat_day_temp(float temp);
        void set_room_thermostat_operating_mode(String state);
        void set_room_thermostat_hysteresis(float hysteresis);
};

