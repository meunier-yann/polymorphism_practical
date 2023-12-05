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
void test_crests();


int main (){
  // test_create_character();
  // test_accelerate();
  // test_break();
  //test_Mario();
  //test_Yoshi();
  //test_race();
  test_crests();
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

  std::cout  << std::endl;
  vitesse = 0.0; //reset de vitesse entre les courses
  std::cout << "Méthode range-based" << std::endl;
  for (int i = 1; i< 4; ++i){
     for (const auto& racer : racers) {
      racer->Accelerate ();
      std::cout << "Après " << i << " tour(s), la vitesse de " << racer->WhatAmI() << " est de "
                                                               << racer->speed() << std::endl;
      if (racer->speed() > vitesse) {
        gagnant = racer->WhatAmI();
        vitesse = racer->speed();
      }

    }
  }
  std::cout << "Le gagnant est " << gagnant <<  '\n';

  for (const auto& racer : racers) {
   delete racer;
 }
}

void test_crests(){
  std::vector<Yoshi*> yoshis;
  for (int i = 1; i < 6; ++i) {
    yoshis.push_back(new Yoshi(i));
    std::cout << "Yoshi " << i << " is " << yoshis[i-1]->WhatAmI() << std::endl;
  }
  std::cout << "Default Yoshi is  " << Yoshi().WhatAmI() << std::endl;

  for (const auto& yoshi : yoshis) {
    delete yoshi;
  }
}
