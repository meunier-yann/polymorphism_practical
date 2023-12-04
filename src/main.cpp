#include <iostream>
#include "Character.h"

void test_create_character();
void test_accelerate();


int main (){
  test_create_character();
  test_accelerate();
  return EXIT_SUCCESS;
}

void test_create_character(){
  Character s;
  std::cout << " max speed de: " << s.max_speed_ << " et speed: " << s.speed_ << std::endl;
}

void test_accelerate(){
  Character s;
  for (int i = 0; i < 12; i++) {
    s.Accelerate();
    std::cout << "Vitesse de: " << s.speed_ << std::endl;
  }
}
