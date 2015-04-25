#ifndef _SHIFT_REGISTER_CONTROL_
#define _SHIFT_REGISTER_CONTROL_

class ShiftRegister
{
   public:
    ShiftRegister(byte latchPin,byte clockPin,byte dataPin)
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
    };
    void setPin(byte number,bool on){
       pins[number] = on;
    };
    void flush(){
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
    bool getPin(byte number){
      return pins[number];
    };
  private:
    bool pins[8];
    byte latchPin = 8;
    byte clockPin = 12;
    byte dataPin = 11;
};

#endif
