#ifndef CHARACTER_H_
#define CHARACTER_H_


class Character{
  public:
    Character();
    void Accelerate();
    inline float speed(){
      return speed_;
    }
    inline float max_speed(){
      return max_speed_;
    }
  protected:
    float speed_;
    float max_speed_;
};


#endif // CHARACTER_H_
