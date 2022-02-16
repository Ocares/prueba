// connect motor controller pins to Arduino digital pins
// motor one
#include <SoftwareSerial.h> //Librería para usar otros pines como Serial
SoftwareSerial BT1(4,2);
#define CW 8 //CW is defined as pin #7//

#define CCW 9 //CCW is defined as pin #8//
int val;
int led = 10;
void setup()
{
  // set all the motor control pins to outputs
  pinMode(CW, OUTPUT); //Set CW as an output//

pinMode(CCW, OUTPUT); //Set CCW as an output//
   BT1.begin(9600); //Lo que sería seríal se reemplaza con BT1
  pinMode(led, OUTPUT); //Declaramos al pin 13 como salida
}


void loop()
{
  if (BT1.available()>0) {
    val = BT1.read(); //Se lee la información
    //Declaramos la condiciones. La app envía un caracter distinto
    //depeniendo del botón que presiones y se alamcena en la variable val.
    if ( val == 'A' )
    {
    digitalWrite(CW,HIGH); //Motor runs clockwise//
   digitalWrite(CCW, LOW); //Motor stops//
     Serial.println("A");
    }

    if ( val == 'B' )
    {
    digitalWrite(CCW, HIGH);//Motor runs counter-clockwise//
   digitalWrite(CW, LOW); //Motor stops//
     Serial.println("B");
    }
    if ( val == 'C' )
    {
    digitalWrite(CCW, LOW);
    digitalWrite(CW, LOW); 
    digitalWrite(led, LOW);
      Serial.println("C");
    }
     if ( val == 'D' )
    {
    digitalWrite(led, HIGH);
      Serial.println("D");
    }
     if ( val == 'E' )
    {
  
    }
  }

}
