#include <iostream>
#include "Character.h"
#include "Mario.h"
#include "Yoshi.h"
#include <string>
#include <vector>


void test_create_character();
void test_accelerate();
void test_break();
void test_Mario();
void test_Yoshi();
void test_race();


int main (){
  // test_create_character();
  // test_accelerate();
  // test_break();
  //test_Mario();
  //test_Yoshi();
  test_race();
  return EXIT_SUCCESS;
}

// void test_create_character(){
//   Character s; //Création ne marche plus mtn que la classe est abstracte
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
//   Character s; //Création ne marche plus mtn que la classe est abstracte
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

void test_race(){
  std::vector<Character*> racers;
  racers.push_back(new Yoshi);
  racers.push_back(new Mario);

  float vitesse = 0;
  std::string gagnant = "";

  
  std::cout << "Méthode avec itérateurs" << std::endl;
  for (int i = 1; i< 4; ++i){
    for (auto it = begin (racers); it != end (racers); ++it) {
      (*it)->Accelerate ();
      std::cout << "Après " << i << " tour(s), la vitesse de " << (*it)->WhatAmI() << " est de "
                                                               << (*it)->speed() << std::endl;
      if ((*it)->speed() > vitesse) {
        gagnant = (*it)->WhatAmI();
        vitesse = (*it)->speed();
      }

    }
  }

  std::cout << "Le gagnant est " << gagnant <<  '\n';

}
