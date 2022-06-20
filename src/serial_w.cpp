#include "serial_w.h"

void Serial_rs485::serial_open(int tx_enable_pin, int boudrate)
{
    Serial2.begin(115200);
    EnTxPin = tx_enable_pin;
    pinMode(EnTxPin, OUTPUT);  
    digitalWrite(EnTxPin, LOW);
}   

String buffer_to_string(uint8_t *buf, int size )
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

void Serial_rs485::serial_send(uint8_t *tx_buffer, int size)
{ 	
    digitalWrite(EnTxPin, HIGH);
    Serial.print(size);

    Serial.print( " | ");
    Serial.println(buffer_to_string(tx_buffer, size));
    Serial2.flush();
    while( !Serial2.availableForWrite()){}
    Serial2.write(tx_buffer, size);   
    delay(3); 
    uint8_t buf[1] = {0};
    Serial2.write(buf, 1);   
    digitalWrite(EnTxPin, LOW);
} 

void Serial_rs485::serial_read_bytes(uint8_t* rx_buffer, int size)
{	
    for (int i = 0; i < size; i++)
    {
        while(!Serial2.available()){}
        rx_buffer[i] = Serial2.read();
    }
}

uint8_t Serial_rs485::serial_read_byte()
{
    // unsigned long mtime = millis();
    while(!Serial2.available()) {}
    // {
    //     if(millis() - mtime > 100 )
    //         return 0xff;
    // }
    return Serial2.read();
}

