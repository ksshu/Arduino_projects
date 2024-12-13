

const int trigPin = 1;
const int echoPin = 5;

long duration;
float distance1, distance2, speed;


int IR1=2;
int IR2=3;
int IR3=4;
int IR4=7;

int LED1=8;
int LED2=9;
int LED3=10;
int LED4=6;
void setup()
{
  Serial.begin(9600);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(LED1,OUTPUT);
   pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);



}

float measureDistance() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  return (duration * 0.034 / 2);
}

void loop()
{
   distance1 = measureDistance();
  delay(100);  // Wait for 100 milliseconds (0.1 second)
  distance2 = measureDistance();

  speed = (distance2 - distance1) / 0.1;  // Calculate speed (cm/s)
  
  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.print(" cm, Distance2: ");
  Serial.print(distance2);
  Serial.print(" cm, Speed: ");
  Serial.print(speed);
  Serial.println(" cm/s");

  delay(1000);

  int value1=digitalRead(IR1);

  if (value1==0)
  {
    digitalWrite(LED1,HIGH);
  }
  else
  {
     digitalWrite(LED1,LOW);
  }
  int value2=digitalRead(IR2);

  if (value2==0)
  {
    digitalWrite(LED2,HIGH);
  }
  else
  {
     digitalWrite(LED2,LOW);
  }
  int value3=digitalRead(IR3);

  if (value3==0)
  {
    digitalWrite(LED3,HIGH);
  }
  else
  {
     digitalWrite(LED3,LOW);
  }

  int value4=digitalRead(IR4);

  if (value4==0)
  {
    digitalWrite(LED4,HIGH);
  }
  else
  {
     digitalWrite(LED4,LOW);
  }
}