#include<SPI.h>

void setup() {
  pinMode(4,OUTPUT);
  SPI.begin();
}
int calc;
int n;
void loop() {
  SPI.beginTransaction(SPISettings(20000000,MSBFIRST, SPI_MODE1));
    
    
  for(n=0;n<=900;n++){
    digitalWrite(4,LOW);
    SPI.transfer(0);
    calc = n * (65000/900);
    SPI.transfer16(calc);
    digitalWrite(4,HIGH);
    }

     for(n=0;n<=100;n++){
    digitalWrite(4,LOW);
    SPI.transfer(0);
    calc = (100-n) * (65000/100);
    SPI.transfer16(calc);
    digitalWrite(4,HIGH);
    }
    
    SPI.endTransaction();
//first commit
}
