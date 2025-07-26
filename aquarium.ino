#define sensorPower 7
#define sensorPin A0
#define buzzer 7
#include<Servo.h>
Servo Myservo;
const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

// Value for storing water level
int val = 0;

void setup() {
  pinMode(buzzer, OUTPUT); 
    pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Myservo.attach(9);
  // Set D7 as an OUTPUT
  pinMode(sensorPower, OUTPUT);
   
  // Set to LOW so no power flows through the sensor
  digitalWrite(sensorPower, LOW);
  
  Serial.begin(9600);
}

void loop(){
  Myservo.write(220);
  //get the reading from the function below and print it
  int level = readSensor();
  int value=level;
  Serial.print("Water level: ");
  Serial.println(level);
  if (value<70){
tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
  }
  delay(1000);
  distance=dist();
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance<5 ){
  for(int pos=220;pos>=170;pos--){
  Myservo.write(pos);
  Serial.println(pos);
  delay(5);
  }
  delay(1000);
  for(int pos=170;pos<=220;pos++){
  Myservo.write(pos);
  Serial.println(pos);
  delay(5);
  }
  
 // Myservo.write(300);
  }
}

//This is a function used to get the reading
int readSensor() {
  digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
  delay(10);              // wait 10 milliseconds
  val = analogRead(sensorPin);    // Read the analog value form sensor
  digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
  return val;             // send current reading
}



int dist()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  return distance;
}
/*
void loop() {
  distance=dist();
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance<5 ){
  for(int pos=0;pos<=45;pos++){
  Myservo.write(pos);
  delay(15);
  }
  delay(1000);
  for(int pos=45;pos>=0;pos--){
  Myservo.write(pos);
  delay(15);
  }
  }
  //delay(1000);
  delay(100);
}
*/
