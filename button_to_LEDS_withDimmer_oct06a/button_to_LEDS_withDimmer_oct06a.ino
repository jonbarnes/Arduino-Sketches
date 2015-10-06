//--------------------------------------------------------------
//Define Variables
//constant values
  //outputs
    const int ledPin1 = 10; //arduino pin for LED1
    const int ledPin2 = 11; //arduino pin for LED2
  //inputs
    const int buttonPin = 3; //arduino pin for button input
    const int analogKnob = A0; //arduino pin for analog Knob

//changing variables
   int brightness = 255;    // how bright the LED is
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
    // read the input on analog pin A0:
      int sensorValue = analogRead(analogKnob);
    //convert input to brightness
      int brightness = sensorValue * (255.0 / 1023.0);
    //print the brightness value to the monitor
      Serial.println(brightness);

    //turn led on to the brightness values
      analogWrite(ledPin1, brightness);
      analogWrite(ledPin2, brightness);
  }else{
    //if button is pressed turn it off
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
  }
}

