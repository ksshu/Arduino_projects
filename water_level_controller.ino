
#include <LCD-I2C.h>


LCD_I2C lcd(0x27, 16, 2);

#define TRIG_PIN 9
#define ECHO_PIN 10

const int red=2;
const int yellow=3;
const int green=13;
int relay=8;
long duration;
int distance;


void setup() 
{
     lcd.begin();
    lcd.display();
    lcd.backlight();
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
 
  Serial.begin(9600);
   pinMode(relay,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  long duration;
  int distance;
  

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);


  distance = duration * 0.034 / 2;

 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <5) 
  {
    digitalWrite(yellow,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(relay,HIGH);
    lcd.setCursor(0, 1); // Or setting the cursor in the desired position.
    lcd.print("Tank is full");
    Serial.println("Tank is full");
    digitalWrite(relay,LOW);
     delay(3000);
    
  } else if (distance <10)
  {
    digitalWrite(yellow,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    //digitalWrite(relay,HIGH);
    lcd.setCursor(0, 1); // Or setting the cursor in the desired position.
    lcd.print("Tank is is half filled");
    Serial.println("Tank is is half filled");
      digitalWrite(relay,LOW);
     delay(3000);
 
  } 
  else 
  {
     digitalWrite(green,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    
    lcd.setCursor(0, 1); // Or setting the cursor in the desired position.
    lcd.print("Tank is Full");
    Serial.println("Tank is empty");
    digitalWrite(relay,HIGH);
    delay(3000);
  }

  delay(500); // Wait for 500 milliseconds before the next loop
}
