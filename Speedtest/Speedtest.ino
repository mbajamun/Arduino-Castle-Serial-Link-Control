#include <SPI.h>
const unsigned int ss = 10;

void setup() {
  pinMode(ss,OUTPUT);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  Serial.begin(9600);
}
void setspeed(uint8_t reg, uint16_t throttle)
{
  //write
  SPI.beginTransaction(SPISettings(16000000, MSBFIRST, SPI_MODE0));
  digitalWrite(ss,LOW);
  uint8_t in0 = SPI.transfer(129);//Device ID plus needed thing yu know
  uint8_t in1 = SPI.transfer(reg);
  uint8_t in2 = SPI.transfer(highByte(throttle));
  uint8_t in3 = SPI.transfer(lowByte(throttle));
  uint8_t checksum = 0-(129+reg+highByte(throttle)+lowByte(throttle));
  uint8_t in4 = SPI.transfer(checksum);
  digitalWrite(10,HIGH);
  SPI.endTransaction();
  //read
  Serial.print(in0);
  Serial.print("\t");
  Serial.print(in1);
  Serial.print("\t");
  Serial.print(in2);
  Serial.print("\t");
  Serial.print(in3);
  Serial.print("\t");
  Serial.print(in4);
  Serial.print("\n");
}

void loop() {
  setspeed(128,65535);
}
