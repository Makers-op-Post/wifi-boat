#define BLYNK_PRINT Serial 
#include  <ESP8266WiFi.h>
#include <Servo.h>
#include  <BlynkSimpleEsp8266.h>

Servo mijnServo;
int pos = 0;

// You should get Auth Token in the Blynk App. 
// Go to the Project Settings (nut icon). 
char auth[] = "***PUT BLYNK AUTH TOKEN HERE***"; 

// Your WiFi credentials. 
// Set password to "" for open networks. 
//char ssid[] = "WiFi-2.4-A73D"; 
char ssid[] = "***PUT WIFI SSID HERE**"; 
char pass[] = "***PUT WIFI CODE HERE"; 

int PWMA=5;//Right side 
int PWMB=4;//Left side 
int DA=0;//Right reverse 
int DB=2;//Left reverse 

void setup(){ 
 // Debug console 
 Serial.begin(9600); 
 Blynk.begin(auth, ssid, pass); 
 pinMode(PWMA, OUTPUT); 
 pinMode(PWMB, OUTPUT); 
 pinMode(DA, OUTPUT); 
 pinMode(DB, OUTPUT); 

 mijnServo.attach(2);
} 

void loop(){ 
Blynk.run(); 
  
} 

// Handling Joystick data 
BLYNK_WRITE(V1){ 
int x = (param[0].asInt() - 512);
int servoPos = param[0].asInt() /6;
//Serial.print("servoPos = ");
//Serial.println(servoPos);
int y = param[1].asInt() - 512;  
Serial.print("x = ");
Serial.print(x);
Serial.print(" / y = ");
Serial.println(y);

/*if(x==-1 && y==-1){*/             //Backward and Left   
if(x<0 && y<0){
  Serial.println("Backward and Left");
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, HIGH); 

  mijnServo.write(servoPos);

/*}else if(x==-1 && y==1){*/        //Forward and Left 
}else if(x<0 && y>0){
  Serial.println("Forward and Left");
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, LOW); 
     
  mijnServo.write(servoPos);

/*}else if(x==1 && y==-1){*/        //Backward and Right      
}else if(x>0 && y<0){
  Serial.println("Backward and Right");
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, HIGH); 
     
  mijnServo.write(servoPos);
 
/*}else if(x==1 && y==1){*/        //Forward and Right  
}else if(x>0 && y>0){
  Serial.println("Forward and Right");
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, LOW);
     
  mijnServo.write(servoPos);

/*}else if(x==-1 && y==0){*/        //Left Turn  
}else if(x<0 && y==0){
  Serial.println("Left Turn");
  digitalWrite(PWMA, 450); 
  digitalWrite(DA, HIGH); 
     
  mijnServo.write(servoPos);

/*}else if(x==1 && y==0){*/        //Right turn 
}else if(x>0 && y==0){
  Serial.println("Right Turn");
  digitalWrite(PWMA, 450); 
  digitalWrite(DA, LOW); 
     
  mijnServo.write(servoPos);

/*}else if(x==0 && y==-1){*/
}else if(x==0 && y<0){        //Backward     
  Serial.println("Backward");
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, HIGH); 

/*}else if(x==0 && y==0){*/        //Stay 
}else if(x==0 && y==0){
  Serial.println("Stay");
  digitalWrite(PWMA, LOW); 
  digitalWrite(DA, LOW); 

/*}else if(x==0 && y==1){*/        //Forward 
}else if(x==0 && y>0){ 
  Serial.println("Forward");
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, LOW); 


 } 
 Serial.println("-------------------------------");
} 
