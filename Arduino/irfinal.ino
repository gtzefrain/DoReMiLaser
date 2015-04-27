#include <MIDI.h>

int laser1 = 1; //C //Do
int laser2 = 2; //C# 
int laser3 = 3; //D //Re
int laser4 = 4; //D#
int laser5 = 5; //E //Mi
int laser6 = 6; //F //Fa
int laser7 = 7; //F# 
int laser8 = 8; //G //Sol
int laser9 = 9; //G#
int laser10 = 10; //A //La
int laser11 = 11; //A#
int laser12 = 12; //B //Si

int octaveup=A0;
int octavedown=A1;

int laserstate1 = 0;
int lasernote1 = 0;
int laserstate2 = 0;
int lasernote2 = 0;
int laserstate3 = 0;
int lasernote3 = 0;
int laserstate4 = 0;
int lasernote4 = 0;
int laserstate5 = 0;
int lasernote5 = 0;
int laserstate6 = 0;
int lasernote6 = 0;
int laserstate7 = 0;
int lasernote7 = 0;
int laserstate8 = 0;
int lasernote8 = 0;
int laserstate9 = 0;
int lasernote9 = 0;
int laserstate10 = 0;
int lasernote10 = 0;
int laserstate11 = 0;
int lasernote11 = 0;
int laserstate12 = 0;
int lasernote12 = 0;

int octave = 24;

int octavedownstate = 0;
int octaveupstate = 0;

long previousMillisLasers = 0;
long previousMillisButtons = 0;  

long intervalLasers = 1;
long intervalButtons = 200;

void setup (){  
  MIDI.begin(4);
  // 115200 hairless MIDI
  Serial.begin(115200);
  pinMode(laser1, INPUT);
  pinMode(laser2,INPUT);
  pinMode(laser2, INPUT);
  pinMode(laser3, INPUT);
  pinMode(laser4, INPUT);
  pinMode(laser5, INPUT);
  pinMode(laser6, INPUT);
  pinMode(laser7, INPUT);
  pinMode(laser8, INPUT);
  pinMode(laser9, INPUT);
  pinMode(laser10, INPUT);
  pinMode(laser11, INPUT);
  pinMode(laser12, INPUT);
  pinMode(octavedown, INPUT);
  pinMode(octaveup, INPUT);
}
void loop(){
  
 int laserstate1 = digitalRead(laser1);
 int laserstate2 = digitalRead(laser2);
 int laserstate3 = digitalRead(laser3);
 int laserstate4 = digitalRead(laser4);
 int laserstate5 = digitalRead(laser5);
 int laserstate6 = digitalRead(laser6);
 int laserstate7 = digitalRead(laser7);
 int laserstate8 = digitalRead(laser8);
 int laserstate9 = digitalRead(laser9);
 int laserstate10 = digitalRead(laser10);
 int laserstate11 = digitalRead(laser11);
 int laserstate12 = digitalRead(laser12);
 
 int octavedownstate= digitalRead(octavedown);
 int octaveupstate = digitalRead(octaveup);

 unsigned long currentMillisLasers = millis();
 unsigned long currentMillisButtons = millis();
 
  if(currentMillisButtons - previousMillisButtons > intervalButtons){
   previousMillisButtons = currentMillisButtons; 
    
 //octave down
 if (octavedownstate == HIGH){
   if (octave > 0 ){
        octave = octave - 12;
   }
 }

 //octave up
  if (octaveupstate == HIGH){
   if (octave < 64 ){
        octave = octave + 12;
      }
   }
 }
  
 if(currentMillisLasers - previousMillisLasers > intervalLasers){
   previousMillisLasers = currentMillisLasers;  
   
     //primer laser
 if (laserstate1 == HIGH) {
    // if note not playing
    if (lasernote1 == 0) {
      //C4, MAX vel, channel 1
      MIDI.sendNoteOff((octave+1),0,1);
      // note is playing
      lasernote1 = 1;
    }
  // when button released
  } else {
    // if note playing
    if (lasernote1 == 1) {
      // if playing - stop
      MIDI.sendNoteOn(octave,100,1);
    }
    // if button released note is off
    lasernote1 = 0;
  }
  
  //segundo laser
  if (laserstate2 == HIGH) {
    if (lasernote2 == 0) {
       MIDI.sendNoteOff((octave+2),0,1);
      
      lasernote2 = 1;
    }
  } else {
    if (lasernote2 == 1) {
     MIDI.sendNoteOn((octave+2),100,1);
    }
    lasernote2 = 0;
  }
   
  
  //tercer laser
  if (laserstate3 == HIGH) {
    if (lasernote3 == 0) {
      MIDI.sendNoteOff((octave+3),0,1);
      lasernote3 = 1;
    }
  } else {
    if (lasernote3 == 1) {
      MIDI.sendNoteOn((octave+3),100,1);
    }
    lasernote3 = 0;
  }  
  
  //cuarto laser
  if (laserstate4 == HIGH) {
    if (lasernote4 == 0) {
      lasernote4 = 1;
    }
  } else {
    if (lasernote4 == 1) {
      MIDI.sendNoteOn((octave+4),100,1);
    }
    lasernote4 = 0;
  }

  //quinto laser
  if (laserstate5 == HIGH) {
    if (lasernote5 == 0) {
      MIDI.sendNoteOff((octave+5),0,1);
      lasernote5 = 1;
    }
  } else {
    if (lasernote5 == 1) {      
      MIDI.sendNoteOn((octave+5),100,1);
    }
    lasernote5 = 0;
  }
 
   //sexto laser
  if (laserstate6 == HIGH) {
    if (lasernote6 == 0) {
      MIDI.sendNoteOff((octave+6),0,1);
      lasernote6 = 1;
    }
  } else {
    if (lasernote6 == 1) {
      MIDI.sendNoteOn((octave+6),100,1);
    }
    lasernote6 = 0;
  }
 
   //septimo laser
  if (laserstate7 == HIGH) {
    if (lasernote7 == 0) {
      MIDI.sendNoteOff((octave+7),0,1);
      lasernote7 = 1;
    }
  } else {
    if (lasernote7 == 1) {
      MIDI.sendNoteOn((octave+7),100,1);
    }
    lasernote7 = 0;
  }
 
   //octavo laser
  if (laserstate8 == HIGH) {
    if (lasernote8 == 0) {
      MIDI.sendNoteOff((octave+8),0,1);
      lasernote8 = 1;
    }
  } else {
    if (lasernote8 == 1) {
      MIDI.sendNoteOn((octave+8),100,1);
    }
    lasernote8 = 0;
  } 
  
    //noveno laser
  if (laserstate9 == HIGH) {
    if (lasernote9 == 0) {
      MIDI.sendNoteOff((octave+9),0,1);
      lasernote9 = 1;
    }
  } else {
    if (lasernote9 == 1) {
      MIDI.sendNoteOn((octave+9),100,1);
    }
    lasernote9 = 0;
  }
  
    //decimo laser
  if (laserstate10 == HIGH) {
    if (lasernote10 == 0) {
      MIDI.sendNoteOff((octave+10),0,1);
      lasernote10 = 1;
    }
  } else {
    if (lasernote10 == 1) {
      
      MIDI.sendNoteOn((octave+10),100,1);
    }
    lasernote10 = 0;
  }
  
    //onceavo laser
  if (laserstate11 == HIGH) {
    if (lasernote11 == 0) {
      MIDI.sendNoteOff((octave+11),0,1);
      lasernote11 = 1;
    }
  } else {
    if (lasernote11 == 1) {
      MIDI.sendNoteOn((octave+11),100,1);
    }
    lasernote11 = 0;
  }
  
    //doceavo laser
  if (laserstate12 == HIGH) {
    if (lasernote12 == 0) {
      MIDI.sendNoteOff((octave+12),0,1);
      lasernote12 = 1;
    }
  } else {
    if (lasernote12 == 1) {
      MIDI.sendNoteOn((octave+12),100,1);
    }
    lasernote12 = 0;
  }
 } 
  
}

