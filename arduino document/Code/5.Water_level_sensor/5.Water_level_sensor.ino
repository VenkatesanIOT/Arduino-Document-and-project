/*
 * TamilZorous info tech 
*/

#define led    2
#define POWER_PIN   7
#define SIGNAL_PIN  A5
#define THRESHOLD   300

int value = 0; // variable to store the sensor value

void setup() {
  Serial.begin(9600);
  pinMode(led,   OUTPUT);   // configure D2 pin as an OUTPUT
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  digitalWrite(led,   LOW); // turn LED OFF
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  if (value > THRESHOLD) {
    Serial.print("The water is detected");
    digitalWrite(led, HIGH);  // turn LED ON
  } else {
    digitalWrite(led, LOW);   // turn LED OFF
  }
}
