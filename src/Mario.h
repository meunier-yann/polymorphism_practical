#include "Character.h"
#include <string>

class Mario : public Character{
  public:
    Mario();
    ~Mario() = default;
    std::string WhatAmI() const = 0 override;
};


#endif // CHARACTER_H_
