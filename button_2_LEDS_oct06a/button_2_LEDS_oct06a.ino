//--------------------------------------------------------------
//Define Variables
//constant values
  //outputs
  const int ledPin1 = 10; //arduino pin for LED1
  const int ledPin2 = 11; //arduino pin for LED2
  //inputs
  const int buttonPin = 3; //arduino pin for button input

//changing variables
  int brightness = 0;    // how bright the LED is
  int fadeAmount = 5;    // how many points to fade the LED by
//--------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonPin)==HIGH){
    //digitalWrite(ledPin1,HIGH);
    //digitalWrite(ledPin2,HIGH);
    // set the brightness of pin 9:
      analogWrite(ledPin1, brightness);
      analogWrite(ledPin2, brightness);
    // change the brightness for next time through the loop:
      brightness = brightness + fadeAmount;
    // reverse the direction of the fading at the ends of the fade:
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ;
    }
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }else{
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
  }
}
