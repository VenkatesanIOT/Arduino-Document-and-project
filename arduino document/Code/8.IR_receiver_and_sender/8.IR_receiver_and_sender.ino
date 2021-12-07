/*
 * TamilZorous info tech 
*/ 
int analogPin = A5;
int out = 13;
int sensorValue = 0;
void setup() {
Serial.begin(9600);
pinMode(out, OUTPUT);
pinMode(analogPin, INPUT);
}
void loop() {
 sensorValue = analogRead(analogPin);
 
 Serial.print("sensor =");
 Serial.println(sensorValue);
 
 delay(200);

 if( sensorValue>700)
 {
  digitalWrite(out,1);
 }
 else
 {
  digitalWrite(out,0);
 }
}
