/*Plant watering system with new blynk update
   
*/
//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>



char auth[] = "BYoAa3XT0P5jIA_YnfqE0lYRDDuaot9D";//Enter your Auth token
char ssid[] = "vishnu";//Enter your WIFI name
char pass[] = "vishnu@123";//Enter your WIFI password

BlynkTimer timer;
bool Relay = 0;

//Define component pins
#define light1 D3
#define light2 D4
#define light3 D5
#define fan1 D6
#define fan2 D7


void setup() {
  Serial.begin(9600);
  pinMode(light1, OUTPUT);
  digitalWrite(light1, HIGH);
   pinMode(light2, OUTPUT);
  digitalWrite(light2, HIGH);
   pinMode(light3, OUTPUT);
  digitalWrite(light3, HIGH);
   pinMode(fan1, OUTPUT);
  digitalWrite(fan1, HIGH);
   pinMode(fan2, OUTPUT);
  digitalWrite(fan2, HIGH);

  

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  }



//Get the button value
BLYNK_WRITE(V0) 
{
  Relay = param.asInt();

  if (Relay == 1) {
    digitalWrite(light1, LOW);
    
  } else {
    digitalWrite(light1, HIGH);
    
  }
}

BLYNK_WRITE(V1)
 {
  Relay = param.asInt();

  if (Relay == 1) {
    digitalWrite(light2, LOW);
    
  } else {
    digitalWrite(light2, HIGH);
    
  }
}

BLYNK_WRITE(V2) 
{
  Relay = param.asInt();

  if (Relay == 1) {
    digitalWrite(light3, LOW);
    
  } else {
    digitalWrite(light3, HIGH);
    
  }
}

BLYNK_WRITE(V3) 
{
  Relay = param.asInt();

  if (Relay == 1) {
    digitalWrite(fan1, LOW);
    
  } else {
    digitalWrite(fan1, HIGH);
    
  }
}

BLYNK_WRITE(V4)
 {
  Relay = param.asInt();

  if (Relay == 1) {
    digitalWrite(fan2, LOW);
    
  } else {
    digitalWrite(fan2, HIGH);
    
  }
}



void loop() 
{
  Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
}
