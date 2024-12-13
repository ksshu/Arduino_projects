

#include <BluetoothSerial.h>



BluetoothSerial SerialBT;

int LED= 2;

int value;
char Char_value;

char ON ='1';
char OFF ='0';


void setup() 
{
  Serial.begin(115200);
  SerialBT.begin("ESP32"); 

  pinMode(LED, OUTPUT);
 
}

void loop() 
{
   Char_value =SerialBT.read();

  if (SerialBT.available()) 
  {
    
    SerialBT.print("Received:");
    SerialBT.println(Char_value);      
       

    if(Char_value == ON)
    {
     SerialBT.println("LED ON:");
 
     digitalWrite(LED, HIGH);
       
    }

    if(Char_value== OFF)
    {
     SerialBT.println("LED OFF:");
    
      digitalWrite(LED, LOW);
    }    
     
  

  }
  delay(20);
}