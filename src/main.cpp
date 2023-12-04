#include <iostream>
#include "Character.h"
#include "Mario.h"
#include <string>

void test_create_character();
void test_accelerate();
void test_break();
void test_Mario();


int main (){
  // test_create_character();
  // test_accelerate();
  // test_break();
  test_Mario();
  return EXIT_SUCCESS;
}

// void test_create_character(){
//   Character s;
//   std::cout << " max speed de: " << s.max_speed() << " et speed: " << s.speed()<< std::endl;
// }
//
// void test_accelerate(){
//   Character s;
//   for (int i = 0; i < 12; i++) {
//     s.Accelerate();
//     std::cout << "Vitesse de: " << s.speed() << std::endl;
//   }
// }
//
// void test_break(){
//   Character s;
//   s.Accelerate();
//   s.Accelerate();
//   s.Accelerate();
//   for (int i = 0; i < 12; i++) {
//     s.Break();
//     std::cout << "Vitesse de: " << s.speed() << std::endl;
//   }
// }

void test_Mario(){
  Mario m;
  std::cout << m.WhatAmI() << m.max_speed() << std::endl;
}
