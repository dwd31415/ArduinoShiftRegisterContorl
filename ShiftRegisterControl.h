#ifndef _SHIFT_REGISTER_CONTROL_
#define _SHIFT_REGISTER_CONTROL_

class ShiftRegister
{
   public:
    ShiftRegister(byte latchPin,byte clockPin,byte dataPin);
    void setPin(byte number,bool on);
    void flush();
    bool getPin(byte number);
  private:
    bool pins[8];
    byte latchPin = 8;
    byte clockPin = 12;
    byte dataPin = 11;
};

#endif
