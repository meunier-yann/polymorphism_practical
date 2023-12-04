#include <iostream>
#include "Character.h"
#include "Mario.h"
#include "Yoshi.h"
#include <string>


void test_create_character();
void test_accelerate();
void test_break();
void test_Mario();
void test_Yoshi();


int main (){
  // test_create_character();
  // test_accelerate();
  // test_break();
  //test_Mario();
  test_Yoshi();
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

void test_Yoshi(){
  Yoshi y;
  std::cout << y.WhatAmI() << y.max_speed() << std::endl;
  y.Accelerate();y.Accelerate();y.Accelerate();y.Accelerate();y.Accelerate();y.Accelerate();y.Accelerate();
  std::cout << y.speed()<< std::endl;

}
