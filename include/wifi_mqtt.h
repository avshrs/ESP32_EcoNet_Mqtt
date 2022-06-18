#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>


#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
unsigned long currentMillis;

WiFiClient espClient;
PubSubClient client(espClient);
String IpAddress2String(const IPAddress& ipAddress)
{
  return String(ipAddress[0]) + String(".") +\
  String(ipAddress[1]) + String(".") +\
  String(ipAddress[2]) + String(".") +\
  String(ipAddress[3])  ; 
}

unsigned long old_mils = 60000;
struct Sensors_Get{
    String unique_name;
    String name;
    String state_topic;
    String unit_of_measurement;
    String icon;
    
} ;

struct Sensors_Set{
    String unique_name;
    String name;
    String state_topic;
    String command_topic;
    String min;
    String max;
    String step;
    String unit_of_measurement;
    String icon;
    
} ;

Sensors_Get sensors_get[50];
Sensors_Set sensors_set[10];

void init_config()
{
sensors_get[0] = {"ecoNet_get_operating_status", "Status Palnika",                  "boiler/operating_status", "none", "none"};
sensors_get[1] = {"ecoNet_get_huw_temp", "Ciepła woda",                             "huw/temp", "°C", "mdi:thermometer",  };
sensors_get[2] = {"ecoNet_get_upper_buffer_temp", "Ciepła woda top",                "huw/upper_buffer_temp", "°C", "mdi:thermometer" };
sensors_get[3] = {"ecoNet_get_lower_buffer_temp", "Ciepła woda bottom",             "huw/lower_buffer_temp", "°C", "mdi:thermometer"};
sensors_get[4] = {"ecoNet_get_feeder_temp", "Podajnik temperatura",                 "boiler/feeder_temp", "°C", "mdi:thermometer"};
sensors_get[5] = {"ecoNet_get_boiler_temp", "Piec temperatura",                     "boiler/boiler_temp", "°C", "mdi:thermometer"};
sensors_get[6] = {"ecoNet_get_weather_temp", "Czujnik pogodowy",                    "weather_temp", "°C", "mdi:thermometer"};
sensors_get[7] = {"ecoNet_get_exhaust_temp", "Spaliny temperatura",                 "boiler/exhaust_temp", "°C", "mdi:thermometer"};
sensors_get[8] = {"ecoNet_get_mixer_temp", "Zasilanie na Grzejniki temperatura",    "mixer/temp", "°C", "mdi:thermometer"};
sensors_get[9] = {"ecoNet_get_boiler_return_temp", "Powrót do Pieca temperatura",   "boiler/return_temp", "°C", "mdi:thermometer"};
sensors_get[10] = {"ecoNet_get_flame_sensor", "Czujnik Płomienia",                  "boiler/flame_sensor", "%", "mdi:fire"};
sensors_get[11] = {"ecoNet_get_ecoster_home_temp", "Dom temperatura", "room_thermostat/ecoster_home_temp", "°C", "mdi:thermometer"};
sensors_get[12] = {"ecoNet_get_ecoster_home_temp_target", "Dom zadana temperatura", "room_thermostat/ecoster_home_temp_target", "°C", "mdi:thermometer"};
sensors_get[13] = {"ecoNet_get_huw_temp_target", "Ciepła woda zadana temperatura", "huw/temp_target", "°C", "mdi:thermometer"};
sensors_get[14] = {"ecoNet_get_boiler_temp_target", "Piec zadana temperatura", "boiler/temp_target", "°C", "mdi:thermometer"};
sensors_get[15] = {"ecoNet_get_mixer_temp_target", "Grzejniki Zasilanie zadana temperatura", "mixer/temp_target", "°C", "mdi:thermometer"};
sensors_get[16] = {"ecoNet_get_fuel_level", "Poziom paliwa", "boiler/fuel_level", "%", "mdi:fuel"};
sensors_get[17] = {"ecoNet_get_fan_out_power", "Wiatrak wyciągowy", "boiler/fan_out_power", "%", "mdi:fan"};
sensors_get[18] = {"ecoNet_get_fan_in_power", "Nadmuch pieca", "boiler/fan_in_power", "%", "mdi:fan"};
sensors_get[19] = {"ecoNet_get_huw_pomp_state", "Pompa Ciepłej wody", "huw/pomp_state", "none", "none"};
sensors_get[20] = {"ecoNet_get_boiler_pomp_state", "Pompa Pieca", "boiler/pomp_state", "none", "none"};
sensors_get[21] = {"ecoNet_get_fuel_stream", "Strumień paliwa", "boiler/fuel_stream", "kg/h", "mdi:fuel"};
sensors_get[22] = {"ecoNet_get_boiler_power_kw", "Moc pieca", "boiler/boiler_power_kw", "kW", "mdi:fire"};
sensors_get[23] = {"ecoNet_get_power_max_time", "Palink czas pracy na max mocy", "boiler/power_max_time", "h", "mdi:fire"};
sensors_get[24] = {"ecoNet_get_power_medium_time", "Palink czas pracy na mid mocy", "boiler/power_medium_time", "h", "mdi:fire"};
sensors_get[25] = {"ecoNet_get_power_min_time", "Palink czas pracy na min mocy", "boiler/power_min_time", "h", "mdi:fire"};
sensors_get[26] = {"ecoNet_get_feeder_time", "Podajnik czas pracy", "boiler/feeder_time",  "h", "mdi:fire"};
sensors_get[27] = {"ecoNet_get_ignitions", "Rozpalenia", "boiler/ignitions", "", "mdi:fire"};
sensors_get[28] = {"ecoNet_get_ignitions_fails", "Rozpalenia nieudane", "boiler/ignitions_fails", "", "mdi:fire"};
sensors_get[29] = {"ecoNet_get_huw_pump_mode", "Tryb pracy Ciepłej wody", "huw/pump_mode", "", "mdi:fire"};
sensors_get[30] = {"ecoNet_get_huw_temp_hysteresis", "Ciepł Woda Histereza", "huw/temp_hysteresis", "°C", "mdi:thermometer"};
sensors_get[31] = {"ecoNet_get_huw_container_disinfection", "Ciepła woda Sterylizacja Bojlera", "huw/container_disinfection", "none", "none"};
sensors_get[32] = {"ecoNet_get_boiler_max_power_kw", "Palnik Max Moc", "boiler/max_power_kw", "kW", "mdi:fire"};
sensors_get[33] = {"ecoNet_get_boiler_mid_power_kw", "Palnik Mid Moc", "boiler/mid_power_kw", "kW", "mdi:fire"};
sensors_get[34] = {"ecoNet_get_boiler_min_power_kw", "Palnik Min Moc", "boiler/min_power_kw", "kW", "mdi:fire"};
sensors_get[35] = {"ecoNet_get_boiler_max_power_fan", "Palnik Max Moc Wiatrak", "boiler/max_power_fan", "%", "mdi:fan"};
sensors_get[36] = {"ecoNet_get_boiler_mid_power_fan", "Palnik Mid Moc Wiatrak", "boiler/mid_power_fan", "%", "mdi:fan"};
sensors_get[37] = {"ecoNet_get_boiler_min_power_fan", "Palnik Min Moc Wiatrak", "boiler/min_power_fan", "%", "mdi:fan"};
sensors_get[38] = {"ecoNet_get_room_thermostat_summer_winter_mode", "Palnik Tryb pracy", "room_thermostat/summer_winter_mode", "", "mdi:fire"};
sensors_get[39] = {"ecoNet_get_room_thermostat_night_temp", "Termostat nocna temperatura", "room_thermostat/night_temp", "°C", "mdi:fire"};
sensors_get[40] = {"ecoNet_get_room_thermostat_day_temp", "Termostat dzienna temperatura", "room_thermostat/day_temp", "°C", "mdi:fire"};
sensors_get[41] = {"ecoNet_get_room_thermostat_operating_mode", "Termostat tryb pracy", "room_thermostat/operating_mode", "", "mdi:fire"};
sensors_get[42] = {"ecoNet_get_room_thermostat_hysteresis", "Termostat Histereza", "room_thermostat/hysteresis", "°C", "mdi:fire"};
sensors_get[43] = {"ecoNet_get_room_thermostat_hysteresis", "Termostat Histereza", "room_thermostat/hysteresis", "°C", "mdi:fire"};
sensors_get[44] = {"ecoNet_get_room_thermostat_hysteresis", "Termostat Histereza", "room_thermostat/hysteresis", "°C", "mdi:fire"};

sensors_set[0] = {"ecoNet_set_huw_temp_hysteresis", "Termostat Histereza", "huw/temp_hysteresis", "huw/temp_hysteresis", "0", "15", "1", "°C", "mdi:thermometer"};
sensors_set[1] = {"ecoNet_set_boiler_temp_target", "Piec zadana temperatura", "boiler/temp_target", "boiler/temp_target","20", "75", "1", "°C", "mdi:thermometer"};
sensors_set[2] = {"ecoNet_set_huw_temp", "Ciepła woda", "huw/temp", "huw/temp", "20", "70", "1",  "°C", "mdi:thermometer"};
sensors_set[3] = {"ecoNet_set_boiler_max_power_kw", "Palnik Max Moc", "boiler/max_power_kw", "boiler/max_power_kw", "4", "18", "1",  "kW", "mdi:fire"};
sensors_set[4] = {"ecoNet_set_boiler_min_power_kw", "Palnik Mid Moc", "boiler/mid_power_kw", "boiler/mid_power_kw", "5", "18", "1",  "kW", "mdi:fire"};
sensors_set[5] = {"ecoNet_set_boiler_min_power_kw", "Palnik Min Moc", "boiler/min_power_kw", "boiler/min_power_kw", "2", "12", "1",  "kW", "mdi:fire"};
sensors_set[6] = {"ecoNet_set_boiler_max_power_fan", "Palnik Max Moc Wiatrak", "boiler/max_power_kw", "boiler/max_power_kw", "15", "60", "1",  "%", "mdi:fan"};
sensors_set[7] = {"ecoNet_set_boiler_mid_power_fan", "Palnik Mid Moc Wiatrak", "boiler/mid_power_kw", "boiler/mid_power_kw", "15", '35', "1",  "%", "mdi:fan"};
sensors_set[8] = {"ecoNet_set_boiler_min_power_fan", "Palnik Min Moc Wiatrak", "boiler/min_power_kw", "boiler/min_power_kw", "15", "35", "1",  "%", "mdi:fan"};
sensors_set[9] = {"ecoNet_set_mixer_temp_target", "Grzejniki Zasilanie zadana temperatura", "mixer/temp_target", "mixer/temp_target", '15', "65", "1",  "%", "mdi:fan"};
sensors_set[10] = {"ecoNet_set_room_thermostat_night_temp", "Termostat nocna temperatura", "room_thermostat/night_temp", "room_thermostat/night_temp", "15", "25", "0.1",  "%", "mdi:fan"};
sensors_set[11] = {"ecoNet_set_room_thermostat_day_temp", "Termostat dzienna temperatura", "room_thermostat/day_temp", "room_thermostat/day_temp", "15", "25", "0.1",  "%", "mdi:fan"};
sensors_set[12] = {"ecoNet_get_huw_temp_target", "Ciepła woda zadana temperatura", "huw/temp_target", "huw/temp_target", "20", "70", "1",  "%", "mdi:fan"};
sensors_set[13] = {"ecoNet_get_huw_temp_min_target", "Cepła woda min zadana temperaturaatura", "huw/temp_min_target", "huw/temp_min", "15", "25", "0.1",  "%", "mdi:fan"};
}




String make_discover(String dev_type_, String dev_name_, String dev_name_ha, String sens_name, String unique_id, String entity_settings)
{
String md = (String)"{\"avty\":{\"topic\":\"avshrs/devices/" + (String)dev_name_ ;
md += (String)"/status/connected\",\"payload_available\":\"true\",\"payload_not_available\":\"false\"},\"~\":\"avshrs/devices/"+(String)dev_name_+"\",";
md += (String)"\"device\":{\"ids\":\"" + (String)dev_name_ + (String)"\",\"mf\":\"Avshrs\",\"name\":\""+ (String)dev_name_ha + (String)"\",\"sw\":\"0.0.1\"},";
md += (String)"\"name\":\""+ (String)sens_name + (String)"\",\"uniq_id\":\""+ (String)unique_id + "\",\"qos\":0," ;
md += (String)entity_settings;
return md;
}




void prepare_conf()
{
    String c1 = "\"current_temperature_topic\":\"~/state/room_thermostat/ecoster_home_temp\"," ;
    c1 += "\"mode_command_topic\":\"~/set_state/room_thermostat/operating_mode\"," ;
    c1 += "\"mode_state_topic\":\"~/state/room_thermostat/operating_mode\"," ;
    c1 += "\"temperature_low_command_topic\":\"~/set_state/room_thermostat/night_temp\"," ;
    c1 += "\"temperature_low_state_topic\":\"~/state/room_thermostat/night_temp\"," ;
    c1 += "\"temperature_high_command_topic\":\"~/set_state/room_thermostat/day_temp\"," ;
    c1 += "\"temperature_high_state_topic\":\"~/state/room_thermostat/day_temp\"," ;
    c1 += "\"min_temp\":\"15\"," ;
    c1 += "\"max_temp\":\"25\"," ;
    c1 += "\"temp_step\":\"0.1\"," ;
    c1 += "\"modes\":[\"heat\", \"cool\",\"auto\",\"off\"]," ;
    c1 += "\"send_if_off\":\"true\"}" ;
    
    String c1_ = make_discover("climate", "EcoNet_01", "EcoNet_920", "Regulator temperatury dom 01", "ecoNet_regulator_temperatury_dom_01",c1);
    client.publish("homeassistant/climate/EcoNet_01_thermostat/config", c1_.c_str(), true);

    String C2 = "\"current_temperature_topic\":\"~/state/huw/temp\"," ;
    C2 += "\"mode_command_topic\":\"~/set_state/huw/pump_mode\"," ;
    C2 += "\"mode_state_topic\":\"~/state/huw/pump_mode\"," ;
    C2 += "\"temperature_high_command_topic\":\"~/set_state/huw/temp\"," ;
    C2 += "\"temperature_high_state_topic\":\"~/state/huw/temp_target\"," ;
    C2 += "\"temperature_low_command_topic\":\"~/set_state/huw/temp_min\"," ;
    C2 += "\"temperature_low_state_topic\":\"~/state/huw/temp_min_target\"," ;
    C2 += "\"min_temp\":\"45\"," ;
    C2 += "\"max_temp\":\"60\"," ;
    C2 += "\"temp_step\":\"1\"," ;
    C2 += "\"modes\":[\"heat\", \"auto\",\"off\"]," ;
    C2 += "\"send_if_off\":\"true\"}" ;
    
    String C2_ = make_discover("climate", "EcoNet_01", "EcoNet_920", "Ciepła woda 01", "ecoNet_regulator_ciepla_woda_01",C2);
    client.publish("homeassistant/climate/EcoNet_01_huw/config", C2_.c_str(), true);

    String C3 = "\"current_temperature_topic\":\"~/state/mixer/temp\"," ;
    C3 += "\"mode_command_topic\":\"~/set_state/room_thermostat/summer_winter_mode\"," ;
    C3 += "\"mode_state_topic\":\"~/state/room_thermostat/summer_winter_mode\"," ;
    C3 += "\"temperature_command_topic\":\"~/set_state/mixer/temp\"," ;
    C3 += "\"temperature_state_topic\":\"~/state/mixer/temp_target\"," ;
    C3 += "\"min_temp\":\"35\"," ;
    C3 += "\"max_temp\":\"65\"," ;
    C3 += "\"temp_step\":\"1\"," ;
    C3 += "\"modes\":[\"heat\", \"auto\",\"off\"]," ;
    C3 += "\"send_if_off\":\"true\"}" ;
    
    String C3_ = make_discover("climate", "EcoNet_01", "EcoNet_920", "Grzejniki zasilanie 01", "ecoNet_regulator_grzejniki_01",C3);
    client.publish("homeassistant/climate/EcoNet_01_heater/config", C3_.c_str(), true);


    for (int i =0 ; i < 43 ; i++)
    {
        String s1 = "\"state_topic\":\"~/state/" + sensors_get[i].state_topic + "\"";
        if (sensors_get[i].unit_of_measurement !="none")
        {
            s1 += ",\"unit_of_measurement\":\"" + sensors_get[i].unit_of_measurement +"\"";
        }
        if (sensors_get[i].icon !="none")
        {
            s1 += ",\"icon\":\""+ sensors_get[i].icon +"\"";
        }
        s1 += "}";
        
        String s1_ = make_discover("switch", "EcoNet_01", "EcoNet_920", sensors_get[i].name, String(sensors_get[i].unique_name+"_01"), s1);
        String topic = "homeassistant/sensor/EcoNet_01/" + sensors_get[i].unique_name + "/config";
        client.publish(topic.c_str(), s1_.c_str(), true);
    }   



}

void reconnect() 
{
  // Loop until we're reconnected
    if (!client.connected())
    { 
        if (millis() - old_mils > 60000)
        {
            old_mils = millis();
            Serial.print("Attempting MQTT connection...");
            // Create a random client ID
            String clientId = "ESP_EcoNet";
            
            clientId += String(random(0xffff), HEX);
            // Attempt to connect
            if (client.connect(clientId.c_str(),"mqttuser", "mqttuser")) 
            {
                Serial.println("connected to MQTT server");
                // MQTT subscription
                client.subscribe("avshrs/devices/EcoNet_01/set_state/room_thermostat/operating_mode");                
                client.subscribe("avshrs/devices/EcoNet_01/set_state/room_thermostat/night_temp");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/room_thermostat/day_temp");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/set_state/huw/pump_mode");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/huw/temp");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/huw/temp_min");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/room_thermostat/summer_winter_mode");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/mixer/temp");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/huw/temp_hysteresis");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/huw/container_disinfection");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/boiler/temp");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/boiler/on_off");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/boiler/max_power_kw");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/boiler/mid_power_kw");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/boiler/min_power_kw");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/boiler/max_power_fan");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/boiler/mid_power_fan");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/boiler/min_power_fan");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/mixer/temp");
                client.subscribe("avshrs/devices/EcoNet_01/set_state/room_thermostat/hysteresis");

                client.subscribe("avshrs/devices/EcoNet_01/set_state/debug");

                client.subscribe("avshrs/devices/EcoNet_01/esp_led");
                prepare_conf();

            } 
        }
    }
}


String uptime(unsigned long milli)
{
  static char _return[32];
  unsigned long secs=milli/1000, mins=secs/60;
  unsigned int hours=mins/60, days=hours/24;
  milli-=secs*1000;
  secs-=mins*60;
  mins-=hours*60;
  hours-=days*24;
  sprintf(_return,"Uptime %d days %2.2d:%2.2d:%2.2d.%3.3d", (byte)days, (byte)hours, (byte)mins, (byte)secs, (int)milli);
  String ret =  _return;
  return ret;
}


void wifi_status()
{
    String ip = IpAddress2String(WiFi.localIP());
    client.publish("avshrs/devices/EcoNet_01/status/wifi_ip", ip.c_str());
    String mac = WiFi.macAddress();
    client.publish("avshrs/devices/EcoNet_01/status/wifi_mac", mac.c_str());
    snprintf (msg, MSG_BUFFER_SIZE, "%i", WiFi.RSSI());
    client.publish("avshrs/devices/EcoNet_01/status/wifi_rssi", msg);
    int signal = 2*(WiFi.RSSI()+100);
    snprintf (msg, MSG_BUFFER_SIZE, "%i", signal);
    client.publish("avshrs/devices/EcoNet_01/status/wifi_signal_strength", msg);
    
    client.publish("avshrs/devices/EcoNet_01/status/uptime", uptime(currentMillis).c_str());
}


void setup_wifi() 
{
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    randomSeed(micros());

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

