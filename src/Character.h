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
    virtual void Break();
    virtual std::string WhatAmI() const = 0;

    inline float speed() const{
      return speed_;
    }
    inline float max_speed() const{
      return max_speed_;
    }

    inline float traveled_ditance() const{
      return traveled_ditance_;
    }

    inline void set_traveled_ditance(float td){
       traveled_ditance_ = td;
    }
  protected:
    float speed_;
    float max_speed_;
    float traveled_ditance_ = 0.0;
};


#endif // CHARACTER_H_
