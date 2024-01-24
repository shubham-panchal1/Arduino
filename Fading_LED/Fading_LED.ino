/*
  https://www.cheers2engineering.com/guided-projects/
     Fade LED using PWM

  Make sure to use PWM capable pin. 
  PWM pins are marked with the negation "~" sign, These pins can generate a pulse as per the given inputs.
  Arduino Uno R3 has 6 PWM pins that are ~3, ~5, ~6, ~9, ~10 and ~11.. These sign “ ~ “. 
*/

int ledPin = 9;         // LED is attached to PWM pin9 
int ledBrightness = 0;  
int fadeAmount = 1;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(ledPin , OUTPUT);
}

void loop() {
  //analogWrite() function uses PWM
  // set the brightness of pin 9
  analogWrite(ledPin, ledBrightness);

  // change the brightness 
  ledBrightness = ledBrightness + fadeAmount;

  // change the fadeAmount at the ends of the fade so it will fade in or fade out
  if (ledBrightness <= 0 || ledBrightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  
  delay(10);
}
