#include "ShiftRegisterControl.h"

ShiftRegister::ShiftRegister(byte latchPin,byte clockPin,byte dataPin)
{
  this->latchPin = latchPin;
  this->clockPin = clockPin;
  this->dataPin = dataPin;
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pins[0] = false;
  pins[1] = false;
  pins[2] = false;
  pins[3] = false;
  pins[4] = false;
  pins[5] = false;
  pins[6] = false;
  pins[7] = false;
}

void ShiftRegister::setPin(byte number,bool on){
   pins[number] = on;
};
void ShiftRegister::flush(){
  byte pattern = 0;
  for(byte i=0;i<(byte)8;i++)
  {
    if(pins[i])
    {
     bitSet(pattern, i);
    }
  }
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, pattern);
  digitalWrite(latchPin, HIGH);
};
bool ShiftRegister::getPin(byte number){
  return pins[number];
};
