 #include <DHT.h>  
 #include <ESP8266WiFi.h>  
 #include <WiFiClient.h>  
 #include <ThingSpeak.h>
 #include <Adafruit_Sensor.h>


 #define DHTPIN 4  
 #define DHTTYPE DHT11  
 DHT dht(DHTPIN, DHTTYPE);
  
 const char* ssid = "123";  
 const char* password = "8722956277";  


 WiFiClient client;  
 long myChannelNumber = 2469627;  
 char * myWriteAPIKey ="7NMLWUKXEU7ZTE93";  


  


 void setup()  
 {  
  Serial.begin(9600);  
  dht.begin();  


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

  float temperature = dht.readTemperature();  
  float humidity = dht.readHumidity();  


  Serial.print("Temperature Value is :");  
  Serial.print(temperature);  
   
  Serial.print("Humidity Value is :");  
  Serial.print(humidity);  
    
 
   ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);  
   ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);  
  delay(3000); // ThingSpeak will only accept updates every 3 seconds.  
 }


