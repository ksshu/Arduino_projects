
#include "DHT.h"

 
#include <LCD-I2C.h>

//Temperature sensor is connected to arduino pin2
#define DHTPIN 2 
int moist=A0;
int sensorValue;
int dryValue = 800;  // Example value for dry soil
int wetValue = 300; //Example value of wet soil

int motor=11;

#define DHTTYPE DHT11
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
    Serial.begin(9600);
    lcd.begin();
    lcd.display();
    lcd.backlight();
     dht.begin();
     pinMode(motor,OUTPUT);
}

void loop()
{
    sensorValue = analogRead(moist);
    float h = dht.readHumidity();
  
    float t = dht.readTemperature();

     if (isnan(h) || isnan(t) )
      {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
      }
    lcd.print("Temperature:");
    lcd.print(t); 
    lcd.setCursor(0, 1); 
    lcd.print("Humidity");
    lcd.print(h);
    Serial.println(sensorValue);

     if (sensorValue > dryValue) 
      {
       digitalWrite(motor,HIGH);
      } 
      
      else if (sensorValue < wetValue) 
      {
          digitalWrite(motor,LOW);
      } 
      else 
      {
      digitalWrite(motor,LOW);
      }
    delay(3000);

    
    lcd.clear();
    delay(500);
}
