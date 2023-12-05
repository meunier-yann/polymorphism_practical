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

//BONUS
void test_traveled_distance();


int main (){
  //Les fonctions suivantes ne marchent plus suite au changement de Character en classe abstracte :/
  //On pourrait les adapter en remplaçant Character par Yoshi ou Mario
  // test_create_character();
  // test_accelerate();
  // test_break();

  //Les fonctions suivantes marchent :)
  // test_Mario();
  // test_Yoshi();
  // test_race();
  // test_crests();

  //BONUS
  test_traveled_distance();
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

void test_Mario(){ //On test le constructeur de Mario
  Mario m;
  std::cout << "Je suis " << m.WhatAmI() << " avec une vitesse de " << m.max_speed() << std::endl;
}

void test_Yoshi(){ //On test le constructeur de Yoshi et ses spécificités
  Yoshi y;
  std::cout << "Je suis " << y.WhatAmI() << " avec une vitesse de " << y.max_speed() << std::endl;
  y.Accelerate();y.Accelerate();
  std::cout <<"Après 2 accélérations Yoshi a une vitesse de " << y.speed()<< std::endl;
  y.Accelerate();y.Accelerate();y.Accelerate();y.Accelerate();y.Accelerate(); //test du respect de max_speed_
  std::cout <<"Après 7 accélérations au total Yoshi a une vitesse de " << y.speed()<< std::endl;
  y.Break(); y.Break();
  std::cout <<"Après 2 freinages, Yoshi a une vitesse de " << y.speed()<< std::endl;
}

void test_race(){ //On va faire une comparaison de vitesse entre Mario et Yoshi pendant 3 tours
  std::vector<Character*> racers; //Ce sont des ptr pour permettre de garder les spécificités des sous-classes
  racers.push_back(new Yoshi);
  racers.push_back(new Mario);

  float vitesse = 0;
  std::string gagnant = "";


  std::cout << "Méthode avec itérateurs" << std::endl;
  for (int i = 1; i< 4; ++i){
    for (auto it = begin (racers); it != end (racers); ++it) { //iterators
      (*it)->Accelerate ();
      std::cout << "Après " << i << " tour(s), la vitesse de " << (*it)->WhatAmI() << " est de "
                                                               << (*it)->speed() << std::endl;
      if ((*it)->speed() > vitesse) { //le gagnant sera celui ayant atteint la vitesse la plus grande
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
     for (const auto& racer : racers) { //range-based
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

  for (const auto& racer : racers) { //on delete les pointeurs pour ne pas avoir de leaks
   delete racer;
 }

}

void test_crests(){ //On va vérifier si les Yoshis se créent avec le bon nombre de cretes
  std::vector<Yoshi*> yoshis;
  for (int i = 1; i < 6; ++i) {
    yoshis.push_back(new Yoshi(i));
    std::cout << "Yoshi " << i << " is " << yoshis[i-1]->WhatAmI() << std::endl;
  }
  std::cout << "Default Yoshi is  " << Yoshi().WhatAmI() << std::endl;

  for (const auto& yoshi : yoshis) { //on delete les pointeurs pour ne pas avoir de leaks
    delete yoshi;
  }
}

//BONUS
void test_traveled_distance(){
  Yoshi y;
  std::cout << y.traveled_ditance() << std::endl;
  y.set_traveled_ditance(5.0);
  std::cout << y.traveled_ditance() << std::endl;
}
