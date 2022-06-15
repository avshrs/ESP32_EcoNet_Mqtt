#include "serial_w.h"

void SerialW::serial_open(int tx_pin)
{
    Serial2.begin(19200);
    lead_z = 0;
    EnTxPin = tx_pin;
    pinMode(EnTxPin, OUTPUT);  
    digitalWrite(EnTxPin, LOW);
}   

void SerialW::serial_send(std::vector<uint8_t> &tx_buffer)
{ 	
    digitalWrite(EnTxPin, HIGH);

    Serial2.flush();

    while(!Serial2.availableForWrite()){}
    Serial2.write(tx_buffer.data(), tx_buffer.size());   

    digitalWrite(EnTxPin, LOW);
} 

void SerialW::serial_read_header(std::vector<uint8_t> &rx_buffer)
{	
    
    while (Serial2.read() == 0x68){}
    rx_buffer.push_back(0x68);
    for (int i = 1; i < (int)rx_buffer.size(); i++)
    {
        while(!Serial2.available()){}
        rx_buffer.push_back(Serial2.read());
    }
}
void SerialW::serial_read_payload(std::vector<uint8_t> &rx_buffer, short size)
{	
    uint8_t buf = 0;
    for (short i = 1; 0 < size - 8; i++)
    {
        while(!Serial2.available()){}
        buf = Serial2.read();
        rx_buffer.push_back(buf);
    }
}

