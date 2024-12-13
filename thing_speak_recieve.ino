  
 #include <ESP8266WiFi.h>  
 #include <WiFiClient.h>  
 #include <ThingSpeak.h>



  
 const char* ssid = "123";  
 const char* password = "8722956277";  


 WiFiClient client;  
 long myChannelNumber = 2352803;  
 char * myReadAPIKey = "3BYLPS288MZ9AO1H";  


  


 void setup()  
 {  
  Serial.begin(9600);  
   


  Serial.print("Connecting to ");  
  Serial.println(ssid);  


  WiFi.begin(ssid, password); 
 
  while (WiFi.status() != WL_CONNECTED)  
  {  
    
   Serial.print(".");  
  }  


  Serial.println("WiFi connected");  
  Serial.println(WiFi.localIP()); 


  ThingSpeak.begin(client); 
}  
 

void loop()
{   
    Serial.println(WiFi.localIP()); 
    Serial.print("Temperature=");
    Serial.println((ThingSpeak.readFloatField(myChannelNumber,1,"myReadAPIKey")));
    Serial.print("Humidity=");
    Serial.println((ThingSpeak.readFloatField(myChannelNumber,2,"myReadAPIKey")));
    delay(3000);

}

