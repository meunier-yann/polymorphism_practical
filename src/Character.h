#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>

class Character{
  public:
    Character(const Character&) = delete;
    Character(Character&&) = delete;
    Character& operator=(const Character&) = delete;
    Character& operator=(Character&&) = delete;

    Character();
    virtual ~Character() = default;
    virtual void Accelerate();
    void Break();
    virtual std::string WhatAmI() const = 0;

    inline float speed() const{
      return speed_;
    }
    inline float max_speed() const{
      return max_speed_;
    }
  protected:
    float speed_;
    float max_speed_;
};


#endif // CHARACTER_H_
