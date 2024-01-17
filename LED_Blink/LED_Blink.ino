// setup function - runs once when user press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// loop function runs over and over again
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on
  delay(1000);                      // wait for one second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off 
  delay(1000);                      // wait for one second
}
