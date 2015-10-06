const int potPin = A0;    // select the input pin for the potentiometer

void setup() {
  pinMode(potPin, INPUT);  // set Knob as Input

  // initialize the terminal as an output:
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potPin);    // read the value from the sensor
  Serial.write(val);
}
