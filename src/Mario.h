#ifndef MARIO_H_
#define MARIO_H_


#include "Character.h"
#include <string>

class Mario : public Character{
  public:
    Mario(const Mario&) = delete;
    Mario(Mario&&) = delete;
    Mario& operator=(const Mario&) = delete;
    Mario& operator=(Mario&&) = delete;

    Mario() = default;
    virtual ~Mario() = default; 
    std::string WhatAmI() const override; //on override WhatAmI()
};


#endif // MARIO_H_
