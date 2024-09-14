#include "PIOT.h"
#include <Arduino.h> 

/**
* We will listen data from PHP and control pin Mode 
*/

PIOT::PIOT() {
}

void PIOT::begin() {
    pinMode(13,OUTPUT);
}

void PIOT::listen() {
      if (Serial.available() > 0) {
        String receivedData = Serial.readString();
        /**
        * Led
        * We use pin 13 for led default 
        */
        if(receivedData.toInt() == 131) {
            digitalWrite(13,HIGH);
        } else if(receivedData.toInt() == 130) {
            digitalWrite(13,LOW);
        }
        Serial.println(receivedData);
        
    }
    
}
