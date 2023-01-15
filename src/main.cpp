#include <Arduino.h>

#ifndef LED_BUILTIN
# warning Development kit has no built-in LED. Using GPIO4 as default.
# define LED_BUILTIN 4
#endif

static uint32_t timeBase = 0;

void setup(void)
{

    Serial.begin(115200); // prepare serial debug port
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop(void)
{

    if (millis() - timeBase > 500) {
        timeBase = millis();
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
}
