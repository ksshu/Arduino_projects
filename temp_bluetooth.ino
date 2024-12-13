
#include <BluetoothSerial.h>
#include "DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT11

DHT dht( DHTTYPE,DHTPIN);

BluetoothSerial SerialBT; 

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32_BT_Server"); // Set a name for Bluetooth server
  dht.begin();
}

void loop()
 {
  delay(2000);

  float h = dht.readHumidity();

  float t = dht.readTemperature();
  
  if(SerialBT.available())
    
    {
      SerialBT.println("Temperature");
      SerialBT.println(t);
      SerialBT.println("Humidity");
      SerialBT.println(h);
    }

 }


   
    
