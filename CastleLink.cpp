#include "CastleLink.h"

CastleLink::CastleLink(unsigned int nPinID[4], uint8_t devID){
  for( int i = 0; i < 4; ++i)
  {
    pinID[i] = nPinID[i];
  }
  ID = devID;
}
void CastleLink::Clear_Cont() {
  digitalWrite(pinID[3], LOW);
  for(int i = 0; i < 5; ++i){
    SPI.transfer(0);
  }
  digitalWrite(pinID[3], HIGH);
  return;
}
uint8_t CastleLink::getHighBit(uint16_t x){
  uint16_t y = x;
  uint8_t highBit = ((y>>8) & 0xff);//HIGH
  return highBit;
}
uint8_t CastleLink::getLowBit(uint16_t x){
  uint16_t y = x;
  uint8_t lowBit = ((y>>0) & 0xff);//LOW
  return lowBit;
}
void CastleLink::command(uint8_t bytes[5]){
  digitalWrite(pinID[3], LOW);
  SPI.transfer(bytes[0]);
  SPI.transfer(bytes[1]);
  //SPI.transfer(data);
  SPI.transfer(bytes[2]);
  SPI.transfer(bytes[3]);
  SPI.transfer(bytes[4]);
  digitalWrite(pinID[3],HIGH);  
  return;
}
void CastleLink::Speed_Cont(uint8_t reg, uint16_t data) {
  dataArray[0] = getHighBit(data);
  dataArray[1] = getLowBit(data);
  byte0 = ID >> 1;
  byte0+=128;
  uint8_t checksum = 0-(byte0 + reg + dataArray[0] + dataArray[1]);
  //uint8_t checksum = 0;
  uint8_t comBytes[5] = {byte0, reg, dataArray[0], dataArray[1], checksum};
  command(comBytes);
 /* digitalWrite(Nsspin, LOW);
  SPI.transfer(byte0);
  SPI.transfer(reg);
  //SPI.transfer(data);
  SPI.transfer(dataArray[0]);
  SPI.transfer(dataArray[1]);
  SPI.transfer(checksum);
  digitalWrite(nsspin,HIGH); */ 
  return;
}
unsigned int CastleLink::getDataPin(int ID){
  return pinID[ID];
}
