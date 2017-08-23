#ifndef CASTLELINK_h
#define CASTLELINK_h
#include "Arduino.h"
#include "SPI.h"
class CastleLink{
  private:
    unsigned int pinID[4]; //Mosi, Miso, Sck, Nss
    uint8_t ID;
    uint8_t byte0;
    uint8_t dataArray[2];
  public:
  CastleLink(unsigned int nPinID[4], uint8_t devID);
  void Clear_Cont();
  uint8_t getHighBit(uint16_t x);
  uint8_t getLowBit(uint16_t x);
  void command(uint8_t bytes[5]);
  void Speed_Cont(uint8_t reg, uint16_t data);
  unsigned int getDataPin(int ID);
};

#endif