#include <AD9850.h>

const int W_CLK_PIN = 8;
const int FQ_UD_PIN = 9;
const int DATA_PIN = 10;
const int RESET_PIN = 11;

//double freq = 5000; //10000000;
double trimFreq = 124999500;
long value;

int phase = 0;

void setup(){
  DDS.begin(W_CLK_PIN, FQ_UD_PIN, DATA_PIN, RESET_PIN);
  DDS.calibrate(trimFreq);
  Serial.begin(9600);
}

void loop(){

  String str;
  while(str = Serial.readString()){
     Serial.print("Srting: ");
  Serial.println(str);
  value = str.toInt(); 
  Serial.print("Frequency: ");
  Serial.println(value);
  DDS.setfreq(value, phase);
  while(!Serial.available());
  }
  
  
  
 
}
