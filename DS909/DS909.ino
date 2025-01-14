/*
 __    _  _____   ___      ___ _  _     __    _ ______ _    
/__|_|/ \(_  |     | |\|    | |_)|_||\|(_ |  |_| |  | / \|\|
\_|| |\_/__) |    _|_| |    | | \| || |__)|__| | | _|_\_/| |

DS909
v1.0

https://ghostintranslation.bandcamp.com
https://www.instagram.com/ghostintranslation
https://github.com/ghostintranslation
https://www.ghostintranslation.com
*/

#include <Audio.h>
#include "DS909.h"

// Instanciation of DS9
DS909 * ds909 = DS909::getInstance();

// Connecting DS9 to general audio output
AudioOutputI2S  i2s2;
AudioConnection patchCord1(*ds909->getOutput(), 0, i2s2, 0);
AudioConnection patchCord2(*ds909->getOutput(), 0, i2s2, 1);
AudioControlSGTL5000 audioBoard;
 
void setup() {
  Serial.begin(115200);
  
  ds909->init();

  // Audio connections require memory to work.
  AudioMemory(40);

  audioBoard.enable();
  audioBoard.volume(0.5);
  
  while (!Serial && millis() < 2500); // wait for serial monitor

  // Starting sequence
  Serial.println("Ready!");
}

void loop() {
  ds909->update();
}
