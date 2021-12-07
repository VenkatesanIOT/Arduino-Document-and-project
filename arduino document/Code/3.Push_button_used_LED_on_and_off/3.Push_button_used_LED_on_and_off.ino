/*
 * TamilZorous info tech 
*/
#define led 3
#define pushButton 2
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pushButton, INPUT);
}
void loop() {
  if (digitalRead(pushButton) == HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
