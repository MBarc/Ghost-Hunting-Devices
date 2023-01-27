/*
 * Author: Michael and Alex
 * 
 * Description: This code is for the Ghost Motion Detector. 
 * If the PIR sensor detects motion, the passive buzzer will play sound until the PIR sensor no longer detects motion.
 * 
 */

const int pirPin = 8;           // choose the digital input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
const int buzzerPin = 3;        // choose the digital output pin (for passive buzzer)

void setup() {

  // Declaring PIR sensor as input
  pinMode(pirPin, INPUT);

  // Declaring passive buzzer as output
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);

  // playing a little melody so users know the device has booted
  startupMelody();
  
}
 
void loop(){

  // Checking to see if the PIR sensor is detecting motion
  val = digitalRead(pirPin);

  // If the PIR sensor is detecting motion
  if (val == HIGH)
  {           

    // If the last time we checked the PIR sensor it did not detect motion
    if (pirState == LOW) 
    {
      // Outputing that the sensor has detected motion
      Serial.println("Motion detected!");
      
      // Playing a beep so the users know motion was detected
      tone(buzzerPin, 784); // G4
      
      // Changing the PIR state
      pirState = HIGH;
    }
  } 
  else 
  {

    // If the last time we checked the PIR sensor it detected motion
    if (pirState == HIGH)
    {

      // Outputing that the sensor is no longer detecting motion
      Serial.println("Motion ended!");

      // No more motion detected so we can stop the buzzer
      noTone(buzzerPin);

      // Changing the PIR state
      pirState = LOW;
    }
  }
}

void startupMelody(){
  /* Plays a little 3 note melody on startup */
  
  tone(buzzerPin, 440); // A4
  delay(200);
  
  tone(buzzerPin, 587); // D4
  delay(200);
  
  tone(buzzerPin, 784); // G4
  delay(200);
  
  noTone(buzzerPin);
  delay(200);
}
