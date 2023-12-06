#ifndef LUIGI_H_
#define LUIGI_H_


#include "Character.h"
#include <string>

class Luigi : public Character{
  public:
    Luigi(const Luigi&) = delete;
    Luigi(Luigi&&) = delete;
    Luigi& operator=(const Luigi&) = delete;
    Luigi& operator=(Luigi&&) = delete;

    Luigi() = default;
    virtual ~Luigi() = default;
    std::string WhatAmI() const override; //on override WhatAmI()
    void Break() override;
    void Accelerate() override; 
};



#endif // LUIGI_H_
