/*
***************************************************
-----STANDUINO-------EEPROM_TOOL-------------------
***************************************************
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
tool to manipulate EEPROM
-clear
-export to serial port
-write to eeprom from flash memory
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
*/

  
#include <EEPROM.h>
#include <avr/pgmspace.h>

#define CLEAR 0
#define EXPORT 1
#define WRITE 2

unsigned char whatToDo=EXPORT;  // here say what you want to do with your EEPROM chose from CLEAR EXPORT WRITE


#define CLEAR_TO 255 // which value to put in the EEPROM when clearing


void setup()
{

  Serial.begin(9600);
  
  switch(whatToDo){

  case CLEAR:
    ClearEEPROM(CLEAR_TO);
    break;


  case EXPORT:
    ExportEEPROM();

    break;

  case WRITE:

    WriteToEEPROM();

    break;



  }

  // turn the LED on when we're done
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);


}

void loop()
{
}

void ClearEEPROM(unsigned char _CLEAR_VAL){
  for(int i=0;i<1024;i++){
    EEPROM.write(i,_CLEAR_VAL);
  } 
}

void ExportEEPROM(){
  Serial.print("prog_uchar flashPreset[1024] PROGMEM = {");
  for (int i = 0; i < 1024; i++){
    if(i%32==0) Serial.println();

    Serial.print(EEPROM.read(i));
    Serial.print(",");

  }
  Serial.println("};");
}




