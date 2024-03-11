const unsigned int TRIG_PIN1=13;
const unsigned int ECHO_PIN1=12;
const unsigned int BAUD_RATE=9600;

void setup() {
pinMode(TRIG_PIN1, OUTPUT);// Sets the trigPin as an Output
pinMode(ECHO_PIN1, INPUT);// Sets the echoPin as an Input
Serial.begin(BAUD_RATE);
}

void loop() {
   // Clears the trigPin
digitalWrite(TRIG_PIN1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(TRIG_PIN1, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
const unsigned long duration1= pulseIn(ECHO_PIN1, HIGH);
// Calculating the distance
int distance1= duration1/29/2;
if(duration1==0){
Serial.println("Warning: no pulse from sensor");
}
else{
Serial.print("distance to nearest object:");
Serial.println(distance1);
Serial.println(" cm");
}
delay(100);
}
