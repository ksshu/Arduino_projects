#include <SoftwareSerial.h>

int i;
SoftwareSerial mySerial(9, 10);

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
     Serial.println("Sending text Message through GSM Module");
     mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918722956277\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("Hello from GSM Module");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
      break;

     case 'r':
      mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
      delay(1000);
      break;

      case 'c':
      //if(i==0)//i variable to ensure that only one call request will be sent by gsm during pressing and holding the pushbutton;
        {
          Serial.println("Calling through GSM  Module");
          delay(1000);
          mySerial.println("ATD+918722956277;"); // ATDxxxxxxxxxx; semicolon should be at the last ;AT command that follows UART protocol;
          Serial.println("Calling 8722956277");
          delay(1000);
          //i++;
         }
   //i=0;
      
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}