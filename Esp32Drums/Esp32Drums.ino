 #include <hellodrum.h>
 #include <MIDI.h>
 MIDI_CREATE_DEFAULT_INSTANCE();

 //Please name your piezo.
 //The piezo named snare is connected to the A0 pin
 HelloDrum snare(35);

 //Setting
 byte SNARE[6] = {
   100, //sensitivity 
   5, //threshold
   20, //scantime
   70, //masktime
   38, //note
   0   //curve type
 }; 

  int volt;
  long t1;
  int t2;
 void setup()
 {
     Serial.begin(38400);
//     MIDI.begin(10);
     snare.setCurve(SNARE[5]); //Set velocity curve 
 }

 void loop()
 {
    
//    volt = analogRead(34);
//    if ( volt > 100 ) {
//      Serial.println("");
//      Serial.print(volt);
//      Serial.print(" - VOLT 1 ");
//      Serial.println("");Serial.println("");
//    }
     //Sensing
     snare.singlePiezo(SNARE[0], SNARE[1], SNARE[2], SNARE[3]); //(sensitivity, threshold, scantime, masktime)

     //Sending MIDI signals
     if (snare.hit == true) {
//        t1 = millis();
         MIDI.sendNoteOn(SNARE[4], snare.velocity, 10);  //(note, velocity, channel)
         MIDI.sendNoteOff(SNARE[4], 0, 10);
         Serial.println("");
//         t2 = millis() - t1;
//         Serial.print(" t2 - ");
//         Serial.print( t2 );
//         Serial.println("");
//         Serial.println("");
//         Serial.println( snare.velocity );
//        Serial.println("");
         Serial.print( analogRead(35));
         Serial.println("");
         Serial.println( snare.velocity );
//          Serial.print( " - analog Voltage ");
//        Serial.println("");
//        delay(100);
     }
//     Serial.println( analogRead(34));
//     Serial.println("");
//     delay(100);
 }
