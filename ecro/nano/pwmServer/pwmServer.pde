//--------------------------------------------------------------
//-- A server for byte-sized commands, first 2 most significant
//-- bits reserved for direction, rest for PWM ms.
//--------------------------------------------------------------
//-- (c) Juan G Victores, Jun 2012
//-- (c) Juan Gonzalez-Gomez (Obijuan), Dec 2011
//-- GPL license
//--------------------------------------------------------------

#include <Servo.h> 

//-- Mapping between the servo name (in the skymega board) and the
//-- arduino pins
const int SERVO2 = 8;
const int SERVO4 = 9;
const int SERVO6 = 10;
const int SERVO8 = 11;

//-- Array for accesing the 2 servos
Servo myservo[4];  

int incomingByte = 0;   // for incoming serial data

void setup() 
{
  //-- Attaching the 4 servos
  myservo[0].attach(SERVO2);
  myservo[1].attach(SERVO4);
  myservo[2].attach(SERVO6);
  myservo[3].attach(SERVO8);
  
  Serial.begin(9600);
}  

void loop() { 
  
    if (Serial.available() > 0) {  // wait to receive data...
        // read the incoming byte:
        incomingByte = Serial.read();

        // say what you got:
        Serial.print("I received 0x");
        Serial.println(incomingByte, HEX);
        
        int dir = incomingByte >> 6;
        Serial.print("--> direction: ");
        Serial.println(dir, DEC);

        int vel = (incomingByte & 0x3f) * 46;
        Serial.print("--> velocity: ");
        Serial.println(vel, DEC);

        myservo[dir].writeMicroseconds(vel);
        
/*        if(incomingByte==97) {
            Serial.println("It was a");
            myservo[0].writeMicroseconds(1500);
        } else if (incomingByte==98) {
            Serial.println("It was b");
            myservo[0].writeMicroseconds(2100);
        } else if (incomingByte==99) {
            Serial.println("It was c");
            myservo[0].writeMicroseconds(900);
        }*/
        
    }       
} 




