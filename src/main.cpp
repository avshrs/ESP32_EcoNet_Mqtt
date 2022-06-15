#include <string.h>
#include <Wire.h>
#include "passwd.h"
#include "wifi_mqtt.h"
#include "econet.h"


int d = 1; 
unsigned long previousMillis = 0;  
unsigned long previousMillis2 = 0;  
EcoNet econet;

void callback(char* topic, byte* payload, unsigned int length) 
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    String st;
    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
        st +=(char)payload[i];
    }
    Serial.println();
    if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/room_thermostat/operating_mode") == 0) 
    {
        econet.set_room_thermostat_operating_mode(st);
    } 
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/room_thermostat/night_temp") == 0) 
    {
        econet.set_room_thermostat_night_temp(st.toFloat());
    } 
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/room_thermostat/day_temp") == 0) 
    {
        econet.set_room_thermostat_day_temp(st.toFloat());
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/set_state/huw/pump_mode") == 0) 
    {
        econet.set_huw_pump_mode(st);
    } 
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/huw/temp") == 0) 
    {
        econet.set_huw_temp(st.toInt());
    } 
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/room_thermostat/summer_winter_mode") == 0) 
    {
        econet.set_room_thermostat_summer_winter_mode(st);
    } 
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/mixer/temp") == 0) 
    {
        econet.set_mixer_temp(st.toInt());
    } 
    
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/huw/temp_hysteresis") == 0) 
    {
        econet.set_huw_temp_hysteresis(st.toInt());
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/huw/container_disinfection") == 0) 
    {
        if(st == "ON")
            econet.set_huw_container_disinfection(true);
        else if(st == "OFF")
            econet.set_huw_container_disinfection(false);
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/boiler/temp") == 0) 
    {
        econet.set_boiler_temp(st.toInt());
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/boiler/on_off") == 0) 
    {
        if(st == "ON")
            econet.set_boiler_on_off(true);
        else if(st == "OFF")
            econet.set_boiler_on_off(false);
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/boiler/max_power_kw") == 0) 
    {
        econet.set_boiler_max_power_kw(st.toInt());
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/boiler/mid_power_kw") == 0) 
    {
        econet.set_boiler_mid_power_kw(st.toInt());
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/boiler/min_power_kw") == 0) 
    {
        econet.set_boiler_min_power_kw(st.toInt());
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/boiler/max_power_fan") == 0) 
    {
        econet.set_boiler_max_power_fan(st.toInt());
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/boiler/mid_power_fan") == 0) 
    {
        econet.set_boiler_mid_power_fan(st.toInt());
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/boiler/min_power_fan") == 0) 
    {
        econet.set_boiler_min_power_fan(st.toInt());
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/mixer/temp") == 0) 
    {
        econet.set_mixer_temp(st.toInt());
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/set_state/room_thermostat/hysteresis") == 0) 
    {
        econet.set_room_thermostat_hysteresis(st.toFloat());
    }
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/esp_led") == 0 && (char)payload[0] == '1') 
    {
        Serial.println("BUILTIN_LED_low");
        digitalWrite(BUILTIN_LED, LOW);   
    } 
    else if (strcmp(topic,"avshrs/devices/EcoNet_01/esp_led") == 0 && (char)payload[0] == '0') 
    {
        Serial.println("BUILTIN_LED_high");
        digitalWrite(BUILTIN_LED, HIGH); 
    }


}

void setup() 
{
    int EnTxPin =  18;
    Wire.begin();
    econet.init(EnTxPin);

    Serial.begin(1000000);
    Serial2.begin(115200);
    pinMode(EnTxPin, OUTPUT);  
    digitalWrite(EnTxPin, LOW);
    pinMode(BUILTIN_LED, OUTPUT);  
    digitalWrite(BUILTIN_LED, LOW);   
    setup_wifi();

    client.setServer(mqtt_server, 1883);
    client.setBufferSize(1024);
    client.setCallback(callback);
    
    reconnect();
    econet.register_mqtt(&client);
    
    init_config();
    prepare_conf();
    client.publish("avshrs/devices/EcoNet_01/state/light", "OFF");
}

void loop() 
{
    currentMillis = millis();

    if (!client.connected()) 
    {
        reconnect();
    }
    client.loop();
    Serial.println("client");
    econet.run();
    Serial.println("econet.run");

    econet.update_statuses(false);
    Serial.println("econet.update_statuses");
    
    if (currentMillis - previousMillis >= 60000) 
    {
        previousMillis = currentMillis;
        wifi_status();
        econet.update_statuses(true);
        snprintf (msg, MSG_BUFFER_SIZE, "true");
        client.publish("avshrs/devices/EcoNet_01/status/connected", msg);
    }


    
}