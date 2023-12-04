#ifndef YOSHI_H_
#define YOSHI_H_


#include "Character.h"
#include <string>

class Yoshi : public Character{
  public:
    Yoshi() = default;
    ~Yoshi() = default;
    std::string WhatAmI() const override;
    void Accelerate() override;
};


#endif // YOSHI_H_
