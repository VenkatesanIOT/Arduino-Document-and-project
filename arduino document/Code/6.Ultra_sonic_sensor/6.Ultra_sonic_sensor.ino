/*
 * TamilZorous info tech 
*/
#define echoPin 10 // attach pin D3 Arduino to pin Echo of HC-SR04
#define trigPin 9 //attach pin D10 Arduino to pin Trig of HC-SR04
int buzzer =11;//attach relays in to D5 of Arduino(DC Pump is connected to Arduino)
int redLED =13;
int duration, distance; 
int i=0;
int maxnum=10;
int count=0;

void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
pinMode(buzzer, OUTPUT);// sets the relaypin as OUTPUT
pinMode(redLED,OUTPUT);
}
void loop() {
// Clears the trigPin condition
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);  
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

if((distance<10)&&(count<maxnum))
{
digitalWrite(buzzer, HIGH);//LOW for the relay to be on
delay(1000 );//For how many milliseconds your Pump works for pumping the liquid
digitalWrite(buzzer, LOW);//HIGH for the relay to be off
delay(2500);//For how many milliseconds your Pump  NOT works for pumping the liquid
count++;
Serial.print("distance :");
Serial.println( distance);
Serial.print("count :");
Serial.println( count);
}
else if(count == 10){   
digitalWrite(redLED, HIGH);//LOW for the relay to be on
delay(1000 );//redLED blink and alart 
Serial.println( "Alert");
digitalWrite(redLED, LOW);//HIGH for the relay to be off
delay(500);
count=0;
//exit(0);
}
}
