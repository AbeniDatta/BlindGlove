#define trigPin D7
#define echoPin D6
#define led D10

void setup()

{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop()

{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance < 15)
  {
    digitalWrite(led, HIGH);
  }

  else
  {
    digitalWrite(led, LOW);
  }

  Serial.print(distance);
  Serial.println(" cm");
  delay(500);

}

/* Ultrasonic sensor: vcc-vv, trig-D7, echo-D6, gnd-G 
 *  1st wire of led and buzzer- G, 2nd wire of led and buzzer-TX/D10
 */
