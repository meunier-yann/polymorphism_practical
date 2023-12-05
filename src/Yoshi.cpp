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


Yoshi::Yoshi(int nb_crests) :
  Character(){
  nb_crests_ = new int {nb_crests};
}


Yoshi::Yoshi() :
  Character(){
  nb_crests_ = new int {1};
}
