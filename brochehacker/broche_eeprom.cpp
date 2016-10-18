#include "brochehacker.h"
#include <EEPROM.h>

// todo:
// - AnimationStorage must be stored in 512byte EEPROM
// - serial interface for replacing animations and text from external device


void saveEEPROM() {
  // save AnimationStorage into eeprom
  extern AnimationStorage *store;
  EEPROM.put(0, *store);
}

void loadEEPROM() {
  // loads eeprom contents into AnimationStorage. likely only called during boot
  extern AnimationStorage *store;
  EEPROM.get(0, *store);
}
