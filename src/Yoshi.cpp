#include "Yoshi.h"
#include <string>


std::string Yoshi::WhatAmI() const {
  return "Yoshi";
}


void Yoshi::Accelerate(){
  if (speed_ < max_speed_ - 1){
    speed_ = speed_ + 2;
  }
  else if (speed_ < max_speed_){
    speed_ = max_speed_;
  }
}
