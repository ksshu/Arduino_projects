const int trigPin = 9;
const int echoPin = 10;
const int red=2;
const int yellow=3;
const int green=13;
int relay=8;
long duration;
int distance;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  
  // Set the trigPin as an OUTPUT
  pinMode(trigPin, OUTPUT);
  
  // Set the echoPin as an INPUT
  pinMode(echoPin, INPUT);
  pinMode(relay,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Trigger the sensor by setting the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, which returns the time (duration) the pulse has traveled
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  // Speed of sound wave divided by 2 (go and back)
  distance = duration * 0.034 / 2;

  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
 // Serial.print(" cm");
    
  if(distance>12)
  {
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(relay,HIGH);
    
    
  }
  else if((distance>=7)or(distance<=12))
  {
    digitalWrite(yellow,HIGH);
    digitalWrite(red,LOW);
     digitalWrite(green,LOW);
    digitalWrite(relay,HIGH);
   
  }
  else if(distance<=3)
  { 
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
     digitalWrite(relay,LOW);
        
  }
  else
     digitalWrite(red,LOW);
     digitalWrite(yellow,LOW);
     digitalWrite(green,LOW);
  // Wait for a short time before the next loop
  delay(1000);
}
