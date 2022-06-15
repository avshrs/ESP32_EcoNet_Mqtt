#pragma once
#include <Arduino.h>
#include <Wire.h>
#include "vars.h"
#include <Vector.h>


class SerialW
{
  public:
    int lead_z = 0 ;
    int EnTxPin =  4;  // HIGH:Transmitter, LOW:Receiver
     
    int loop = 0;
    void serial_open(int tx_pin);
    void serial_send(std::vector<uint8_t> &tx_buffer);
    void serial_read_payload(std::vector<uint8_t> &rx_buffer, short size);  
    void serial_read_header(std::vector<uint8_t> &rx_buffer);
};
  


