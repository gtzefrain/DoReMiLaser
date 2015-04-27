int octaveup=A0;
//variab
const int ledPin =  13; 
int octave=24;  
int octaveupstate = 0; 

long previousMillisButtons = 0;  

long intervalButtons = 200;

void setup() {
  //MIDI.begin(4);
  // 115200 hairless MIDI
  pinMode(ledPin, OUTPUT); 
  pinMode(octaveup, INPUT);
  Serial.begin(9600);
  
}
void loop() {
   octaveupstate = digitalRead(octaveup);
   unsigned long currentMillisButtons = millis();
   
   if(currentMillisButtons - previousMillisButtons > intervalButtons){
       previousMillisButtons = currentMillisButtons; 
   
     if (octaveupstate == HIGH){
       digitalWrite(ledPin, HIGH);
        if (octave  < 64 ){
          octave = octave + 12;
        }
     }else {
     digitalWrite(ledPin, LOW);
     }
   
  Serial.println(octave);
}
}
