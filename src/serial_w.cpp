#include "serial_w.h"

void SerialW::serial_open(int tx_pin)
{
    Serial2.begin(115200);
    lead_z = 0;
    EnTxPin = 18;
    pinMode(EnTxPin, OUTPUT);  
    digitalWrite(EnTxPin, LOW);
    Serial2.setTimeout(100);
}   

void SerialW::serial_send(std::vector<uint8_t> &tx_buffer)
{ 	
    digitalWrite(EnTxPin, HIGH);

    Serial2.flush();

    while(!Serial2.availableForWrite()){}
    Serial2.write(tx_buffer.data(), tx_buffer.size());   

    digitalWrite(EnTxPin, LOW);
} 

void SerialW::serial_read_header(std::vector<uint8_t> &rx_buffer,int size)
{	
    while(!Serial2.available()){}
    if(Serial2.read() == 0x68)
    {
        rx_buffer.push_back(0x68);
        for (int i = 1; i < size; i++)
        {
            while(!Serial2.available()){}
            rx_buffer.push_back(Serial2.read());
        }
    }
    else
        rx_buffer.push_back(0xff);
}
void SerialW::serial_read_payload(std::vector<uint8_t> &rx_buffer, short size)
{	
    for (short i = 0; i < size - 8; i++)
    {
        while(!Serial2.available()){}
        rx_buffer.push_back(Serial2.read());
    }
}

