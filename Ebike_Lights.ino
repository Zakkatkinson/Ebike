/*
Simple Headlight/Taillight/Brakelight control for my Ebike
By: Zakk Atkinson
http://Zakkblog.com
*/

int buttonState0 = 0; //Variable for Brake Button 0
int buttonState1 = 0; //Variable for Brake Button 1
int switchState = 0; //Variable for Headlight/Taillight Switch


void setup()
{
	pinMode(4, OUTPUT); //HeadLights
	pinMode(5, OUTPUT); // TailLight
    pinMode(7, INPUT_PULLUP); //Lights switch
	pinMode (12, INPUT_PULLUP); //Brake Button 0
	pinMode (11, INPUT_PULLUP); //Brake Button 1
	pinMode(8, OUTPUT); //Relay (Main controller brake line)
}


void loop()
{

  buttonState0 = digitalRead(12); //Check state of Brake Button 0
  buttonState1 = digitalRead(11); //Check state of Brake Button 1
  switchState = digitalRead(7); //Check state of Light Switch

	if(switchState == LOW) //If Headlight/Taillight switch is in the on position
	{
		analogWrite(5, 127); //Turn Taillight on 50%
		digitalWrite(4, HIGH); //Turn Headlights on 100%
	} //End of If Switch is on
	else //If switch is Off
	{
   		analogWrite(5, 0); //Turn off Taillight
  		digitalWrite(4, LOW); //Turn off Headlights
	} //End of if switch is Off

  if(buttonState0 == LOW || buttonState1 == LOW) //If either Brake button is pressed (depending on switch orientation, use "HIGH" to reverse operation)
  {
  	digitalWrite(8, HIGH); //Trigger relay to activate switch for main controller
  	analogWrite(5, 255); //Turn Taillight on 100%
  } //End of if brake is pressed
   else //If brake is not pressed
  { 
  	digitalWrite(8, LOW); //Make sure relay is off
  }

}//loop end
