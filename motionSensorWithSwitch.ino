
int motionDetect= 0;
int manualSwitch = 0;
int motionSwitch = LOW;

void setup() {
pinMode(13, OUTPUT);
//pinMode(2, INPUT);
pinMode(2, INPUT);
//pinMode(11, INPUT);
digitalWrite(13, LOW);
}

void loop() {

motionSwitch = digitalRead (2);
/*
manualSwitch = digitalRead (11);

if (motionSwitch == HIGH) // Motion Mode
{
  motionDetect = digitalRead(2);
  if (motionDetect == HIGH)
     {
     digitalWrite(13, HIGH);
     //delay (180000); //Optional 3 minute delayed off
     //digitalWrite(13, LOW);
     }
      else {
        digitalWrite(13, LOW);
     }
}
else if (manualSwitch == HIGH) // Manual On
{
  digitalWrite(13, HIGH);
}
else // Manual Off

{
  digitalWrite(13, LOW);
}
*/
if(motionSwitch == HIGH)
{
  digitalWrite(13, HIGH);
}
else
{
  digitalWrite(13,LOW);
}

} 

