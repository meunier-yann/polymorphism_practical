#include <iostream>
#include "Character.h"

void test_create_character();


int main (){
  test_create_character();
  return EXIT_SUCCESS;
}

void test_create_character(){
  Character s;
  std::cout << " max speed de: " << s.max_speed_ << " et speed: " << s.speed_ << std::endl;
}
