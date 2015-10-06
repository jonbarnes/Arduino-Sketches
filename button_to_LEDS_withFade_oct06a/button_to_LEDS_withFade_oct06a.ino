//--------------------------------------------------------------
//Define Variables
//constant values
  //outputs
    const int ledPin1 = 10; //arduino pin for LED1
    const int ledPin2 = 11; //arduino pin for LED2
  //inputs
    const int buttonPin = 3; //arduino pin for button input
    const int analogKnob = A0; //arduino pin for analog Knob

   const int maxBrightness = 100; //how bright Arduino Gets
//changing variables
   int brightness = 0;    // how bright the LED is
   int fadeAmount = 5;    // how many points to fade the LED by
//--------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
    pinMode(ledPin1,OUTPUT);
    pinMode(ledPin2,OUTPUT);
    pinMode(buttonPin,INPUT);
  // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonPin)== LOW){
    //digitalWrite(ledPin1,HIGH);
    //digitalWrite(ledPin2,HIGH);
    // set the brightness of pin 9:
      analogWrite(ledPin1, brightness);
      analogWrite(ledPin2, brightness);
    // change the brightness for next time through the loop:
      brightness = brightness + fadeAmount;

    // read the input on analog pin 0:
       int sensorValue = analogRead(analogKnob);
    //convert input to fadeAmount
      int voltage = sensorValue * (5.0 / 1023.0);
      //Serial.println(voltage);
      fadeAmount = voltage;
      //Serial.println(fadeAmount);
    
    // reverse the direction of the fading at the ends of the fade:
    if (brightness == 0 || brightness == maxBrightness) {
      fadeAmount = -fadeAmount ;
    }
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }else{
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
  }
//Serial.println(brightness);
Serial.println(fadeAmount);
}

