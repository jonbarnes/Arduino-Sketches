/*
 * lots of help from http://www.arduino-hacks.com/converting-integer-to-character-vice-versa/
 */

//get rid of magic numbers, define variable values early on
#define ONE_SECOND 1000
#define COUNTER_INIITIAL_NUMBER 0
#define COUNTER_FINAL_NUMBER 10
#define COUNTER_STEP_SIZE 1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.write("HEADER (this program will end when counter is at 10)");

  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    int counter = COUNTER_INIITIAL_NUMBER;  //declaring integer
    char counter_string[3];                 //declaring character array
    String str;                             //declaring string
    
    while (counter < COUNTER_FINAL_NUMBER){
      counter += COUNTER_STEP_SIZE;
      str = String(counter);                //converting integer into a string
      str.toCharArray(counter_string,3);    //passing the value of the string to the character array
  
      Serial.write( "...loop");
      Serial.write("...Value of counter_string is \t");
      Serial.println(counter_string);       //display that value
      
      digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);              // wait for a second
      digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
      delay(1000);              // wait for a second
    }
    exit(0);
}
