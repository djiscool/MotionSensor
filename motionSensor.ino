int inPin1 = 11;   // switch connected to digital pin 11
int inPin2 = 12;   // switch connected to digital pin 12

int ssrPin = 13;
int pirPin = 2;
int motionDetect= 0;
int manualSwitch = 0;
int motionSwitch = 0;

void setup() {
pinMode(ssrPin, OUTPUT);
pinMode(pirPin, INPUT);
pinMode(inPin1, INPUT);
pinMode(inPin2, INPUT);
digitalWrite(ssrPin, LOW);
}

void loop() {

motionSwitch = digitalRead (inPin1);
manualSwitch = digitalRead (inPin2);

if (motionSwitch == HIGH) // Motion Mode
{
  motionDetect = digitalRead(pirPin);
  if (motionDetect == HIGH)
     {
     digitalWrite(ssrPin, HIGH);
     //delay (180000); //Optional 3 minute delayed off
     digitalWrite(ssrPin, LOW);
     }
}
else if (manualSwitch == HIGH) // Manual On
{
  digitalWrite(ssrPin, HIGH);
}
else // Manual Off

{
  digitalWrite(ssrPin, LOW);
}
} 
