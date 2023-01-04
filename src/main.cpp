#include <Arduino.h>
#include <ModbusMaster.h>


void ModbusSetup();
void ModbusRead();
void ModbusRead1();
void ModbusRead2();
void ModbusRead3();

ModbusMaster node;

void setup() {
  Serial.begin(9600);  
  Serial1.begin(9600, SERIAL_8E1);
  node.begin(1, Serial1); 
}

void loop() {
  ModbusRead3();

  delay(5000);
}

void ModbusRead(){
  uint8_t result;  
  result = node.readHoldingRegisters(0xE, 2); // 0xE Voltage

  uint16_t data[2];
  data[0] = node.getResponseBuffer(0);
  data[1] = node.getResponseBuffer(1);
  float x;
  unsigned long *p;

  p = (unsigned long*)&x;
  *p = (unsigned long)data[0] <<16 | data[1];

  if(result == node.ku8MBSuccess){
    Serial.print("Voltage L1: ");
    Serial.println(x, 1);
  
  } else{
    Serial.print("fout ");
  }
}

void ModbusRead1(){
uint8_t result;  
  result = node.readHoldingRegisters(0x1E, 2); // 0xE Voltage

  uint16_t data[2];
  data[0] = node.getResponseBuffer(0);
  data[1] = node.getResponseBuffer(1);
  float x;
  unsigned long *p;

  p = (unsigned long*)&x;
  *p = (unsigned long)data[0] <<16 | data[1];

  if(result == node.ku8MBSuccess){
    Serial.print("KW: ");
    Serial.println(x);
  
  } else{
    Serial.print("fout ");
  }
}

void ModbusRead2(){
uint8_t result;  
  result = node.readHoldingRegisters(0x14, 2); // 0xE Voltage

  uint16_t data[2];
  data[0] = node.getResponseBuffer(0);
  data[1] = node.getResponseBuffer(1);
  float x;
  unsigned long *p;

  p = (unsigned long*)&x;
  *p = (unsigned long)data[0] <<16 | data[1];

  if(result == node.ku8MBSuccess){
    Serial.print("Frequency: ");
    Serial.println(x);
  
  } else{
    Serial.print("fout ");
  }
}

void ModbusRead3(){
uint8_t result;  
  result = node.readHoldingRegisters(0x9, 2); // 0xE Voltage

  uint16_t data[2];
  data[0] = node.getResponseBuffer(0);
  data[1] = node.getResponseBuffer(1);
  float x;
  unsigned long *p;

  p = (unsigned long*)&x;
  *p = (unsigned long)data[0] <<16 | data[1];

  if(result == node.ku8MBSuccess){
    Serial.print("Software version: ");
    Serial.println(x);
  
  } else{
    Serial.print("fout ");
  }
}





