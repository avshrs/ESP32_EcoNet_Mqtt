#pragma once
#include <Arduino.h>
#include <Wire.h>
#include "vars.h"


class Serial_rs485
{
  public:
    int EnTxPin =  18;  // HIGH:Transmitter, LOW:Receiver
  
  public:
    void serial_open(int tx_enable_pin, int boudrate);

    void serial_send(uint8_t *tx_buffer, int size);
    uint8_t serial_read_byte();  
    void serial_read_bytes(uint8_t *rx_buffer, int size);  
    
};

