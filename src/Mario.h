#ifndef MARIO_H_
#define MARIO_H_


#include "Character.h"
#include <string>

class Mario : public Character{
  public:
    Mario() = default;
    ~Mario() = default;
    std::string WhatAmI() const override;
};


#endif // MARIO_H_
