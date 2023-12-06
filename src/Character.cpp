#include "Character.h"


Character::Character(){
  this->speed_ = 0.0;
  this->max_speed_ = 10.0;
}


void Character::Accelerate(){
  if (speed_ + 1 <= max_speed_){
    ++speed_;
  }
}


void Character::Break(){
  if (speed_ - 1  >= 0.0){ //on pose une condition pour que la vitesse ne soit jamais nulle
    --speed_;
  }
}
