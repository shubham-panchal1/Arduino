/*
  https://www.cheers2engineering.com/guided-projects/advanced-grades-9-12/arduino-advanced/arduino-blinking-light-without-delay

   LED Blinking Light - without delay
   ON Board LED - LED_BUILTIN

  */
// These variables store the flash pattern
// and the current state of the LED
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMilli = 0;        // will store last time LED was updated
unsigned long currentMilli = 0;
long OnTime = 250;           // on-time in millisecond
long OffTime = 500;          // off-time in millisecond

// setup function - runs once when user press reset or power the board
void setup() 
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT); 
}

// loop function runs over and over again
void loop()
{  
  currentMilli = millis(); 
  // check previousMilli to see if it's time to change the state of the LED
  if((ledState == HIGH) && (currentMilli - previousMilli >= OnTime))
  {
    ledState = LOW;  // Turn LED off
    previousMilli = currentMilli;  // Remember the time
    digitalWrite(LED_BUILTIN, ledState);  // turn OFF the LED
  }
  else if ((ledState == LOW) && (currentMilli - previousMilli >= OffTime))
  {
    ledState = HIGH;  // turn LED ON
    previousMilli = currentMilli;   // Remember the time
    digitalWrite(LED_BUILTIN, ledState);	  // turn ON the LED
  }
}
