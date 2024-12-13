#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#include<Wire.h>
#include<dht.h>

#define DHTTYPE 11
#define DHTPIN 2
dht DHT;
DHT dht(DHTTYPE,DHTPIN);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);


void setup() 
{
  dht.begin();
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC,0X3c))
  {
    Serial.println("FAILED");
  }  
  display.clearDisplay();
 
}

void loop() 
{
display.setTextSize(1.0);
display.setTextColor(WHITE);
display.setCursor(0,0);
//display.println("hello shanthavvallll");
DHT.read11(DHTPIN);

display.print("RUTURAJ GAYAKWAD");
display.println(DHT.temperature);

display.print("humidity=");
display.print(DHT.humidity);

display.display(); 

}
