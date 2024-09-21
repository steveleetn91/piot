#include "PIOT.h"
#include <Arduino.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,4);
/**
* We will listen data from PHP and control pin Mode 
*/
bool LCD1604INIT = false;
int LCDRow = 0;
int LCDCol = 0;

String receivedData = "";

PIOT::PIOT() {
}

void PIOT::begin() {
    pinMode(13,OUTPUT);
}

void PIOT::listen() {
      if (Serial.available() > 0) {
        // String receivedData = Serial.readString();
        receivedData += Serial.readString();
        receivedData.replace("\n", "");
        receivedData.replace("\r", "");
            if (receivedData.indexOf("[END]") != -1) {
                receivedData.replace("[END]","");
                Serial.println(receivedData);
                phpEvent(receivedData);
                receivedData = "";  
            } 
    }
}

void PIOT::phpEvent(String receivedData) {
    
         String text = receivedData;
         
        /**
        * Led
        * We use pin 13 for led default 
        */
        if(receivedData.toInt() == 131) {
            digitalWrite(13,HIGH);
        } else if(receivedData.toInt() == 130) {
            digitalWrite(13,LOW);
        }
        /**
        * LCD 1604
        * CONNECT IC2
        */
        // init 
        if(receivedData == "LCD1604INIT" && LCD1604INIT == false) {
             LCD1604INIT = true;
             lcd.init();                    
             lcd.backlight(); 
             lcd.setCursor(0,0);
             lcd.print("Wating ....");
        }

        // control
        if(receivedData.indexOf("A45") != -1 ) {
                if(LCD1604INIT == true) {
                    
                    text.replace("A45","");

                    for(int i=0;i<4;i++) {
                            if(text.indexOf("r" + String(i)) != -1) {
                                text.replace("r" + String(i),"");
                                for(int e=0;e<16;e++) {
                                if(text.indexOf("c" + String(e)) != -1) {
                                    text.replace("c" + String(e),"");
                                        LCDRow = i;
                                        LCDCol = e;
                                        lcd.setCursor(e,i);
                                        lcd.print(text);
                                    }
                                }
                        }
                    }
                    // on and off 
                    if(text.indexOf("A450") != -1) {
                        lcd.noBacklight();
                    } else if(text.indexOf("A451") != -1) {
                        lcd.backlight();
                    }
                    // clear screen 
                    if(text.indexOf("A45EMPTY") != -1) {
                        lcd.clear();
                    } 
            }
        }
}