// include MIDI library
#include <MIDI.h>
 
// read digital pins number 2, 4, 7
int pushButton7 = 7;
//int octaveup=7;
// checks if the button is pressed

int buttonState7 = 0;
 
// play/stop notes in relation to buttons pressed

int note7 = 0;
 

// read potentiometer value
int analogValue = 0;
// maximum MIDI value is 127, first/previous potentiometer
// move has to always be different than previous value
int lastAnalogValue = 128;


 
int octave=60;

int octaveupstate = 0; 
 
 
void setup() {
  MIDI.begin(4);
  // 115200 hairless MIDI
  Serial.begin(115200);
  pinMode(pushButton7, INPUT);
  //pinMode(octaveup, INPUT);
}
 
void loop() {
  // read state of buttons
  int buttonState7 = digitalRead(pushButton7);

  
  // Button 7
  if (buttonState7 == 1) {
    if (note7 == 0) {
      MIDI.sendNoteOff(octave,0,1);
      note7 = 1;
    }
  } else {
    if (note7 == 1) {
      
       MIDI.sendNoteOn(octave,127,1);
    }
    note7 = 0;
  }
 
  delay(1);
}
