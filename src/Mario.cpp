#include "Mario.h"
#include <string>


std::string Mario::WhatAmI() const { //on override WhatAmI()
  return "Mario";
}

void Mario::Break(){
  if (speed_ - 0.25  >= 0.0){ //on pose une condition pour que la vitesse ne soit jamais nulle
    speed_ -= 0.25;
  }
}
