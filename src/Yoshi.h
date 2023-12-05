#ifndef YOSHI_H_
#define YOSHI_H_


#include "Character.h"
#include <string>

class Yoshi : public Character{
  public:
    Yoshi(int nb_crests);
    Yoshi();
    ~Yoshi();
    std::string WhatAmI() const override;
    void Accelerate() override;

    inline int* nb_crests() const{
      return nb_crests_;
    }

  protected:
    int* nb_crests_;
};


#endif // YOSHI_H_
