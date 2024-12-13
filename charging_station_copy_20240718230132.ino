#include <LCD-I2C.h>
const int IR = 9;
//const int echoPin = 10;
const int relayPin = 8;



LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

void setup() 
{
    lcd.begin();
    lcd.display();
    lcd.backlight();

  pinMode(IR, INPUT);
  //pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{ 
   lcd.setCursor(0, 0);
   lcd.clear();
 
  int value=digitalRead(IR);

  if(value==0)
  {    
    digitalWrite(relayPin,HIGH);
    lcd.println("EV1:");
    lcd.setCursor(0, 1);
    lcd.print("car1 is charging");
  }
  
  else if(value==1
  )
  {
  lcd.print("EV1:");
  lcd.setCursor(0, 1);
  lcd.print("Not charging");
    digitalWrite(relayPin,LOW);

  }
  else
  {
  lcd.println("Internal error");
  }
}
