#include <ESP8266WiFi.h>

const char *ssid =  "Realme Narzo 20";    
const char *pass =  "git12345";

//WiFiClient client;
 
void setup() 
{
       Serial.begin(9600);
       
               
       Serial.println("Connecting to ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      //Serial.println("");
      
}
 
void loop() 
{      
  Serial.println("WiFi connected"); 
      Serial.println (WiFi.localIP ());
      delay(500);
}

