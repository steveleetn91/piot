#ifndef PIOT_H
#define PIOT_H
#include <Arduino.h> 
class PIOT {
public:
    PIOT();
    void begin();
    void listen();
    void phpEvent(String receivedData);
private:
    
};

#endif
