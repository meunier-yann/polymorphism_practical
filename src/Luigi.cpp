#include "Luigi.h"
#include <string>

std::string Luigi::WhatAmI() const { //on override WhatAmI()
  return "Luigi";
}

void Luigi::Break(){
  if (speed_ - 0.75  >= 0.0){ //on pose une condition pour que la vitesse ne soit jamais nulle
    speed_ -= 0.75;
  }
}


void Luigi::Accelerate(){
  if (speed_ < max_speed_ - 1.5){
    speed_ = speed_ + 1.5;
  }
  else if (speed_ < max_speed_){
    speed_ = max_speed_;
  }
}
