#include <iostream>
#include "Character.h"
#include "Mario.h"
#include "Yoshi.h"
#include <string>
#include <vector>
#include <time.h>
#include<unistd.h>
#include <map>
//#include<windows.h>

void test_create_character();
void test_accelerate();
void test_break();
void test_Mario();
void test_Yoshi();
void test_race();
void test_crests();

//BONUS
void test_traveled_distance();
void test_refresh_traveled_distance();
void test_randomness();
void advanced_race();
void random_event(Character* ptr, int i, std::map<int, std::string> Players);



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
  // test_traveled_distance();
  // test_refresh_traveled_distance();
  advanced_race();
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

void test_refresh_traveled_distance(){
  Yoshi y;
  std::cout << y.traveled_ditance() << std::endl;
  y.Accelerate();
  y.refresh_traveled_ditance();
  std::cout << y.traveled_ditance() << std::endl;
}

void test_randomness(){
  srand (time(NULL));
  std::cout << rand() % 2;
  srand (time(NULL)-1);
  std::cout << rand() % 2;
  srand (time(NULL)-3);
  std::cout << rand() % 2;
  srand (time(NULL)-3);
  std::cout << rand() % 2;
  srand (time(NULL)-3);
  std::cout << rand() % 2;
  std::cout << std::endl;
}

void advanced_race(){
  //création de la hash map avec les événements
  std::map<int, std::string> Players;
  Players.insert(std::pair<int, std::string>(0, " a pris un boost."));
  Players.insert(std::pair<int, std::string>(1, " a pris une banane."));
  Players.insert(std::pair<int, std::string>(2, " n' a rien pris."));
  Players.insert(std::pair<int, std::string>(3, " a le vent dans le dos."));
  Players.insert(std::pair<int, std::string>(4, " a trébuché."));

  Yoshi* y1 = new Yoshi;
  Yoshi* y2 = new Yoshi (2);
  Mario* m1 = new Mario();
  std::vector<Character*> racers; //Ce sont des ptr pour permettre de garder les spécificités des sous-classes
  racers.push_back(y1);
  racers.push_back(y2);
  racers.push_back(m1);
  float longest_distance = 0.0;
  std::string gagnant = "";
  int nb_secondes = 5;
  int nb_tours = 10;

  std::cout << "Les coureurs sont:" << std::endl;
  for (const auto& racer : racers) { //on delete les pointeurs pour ne pas avoir de leaks
    std::cout << racer->WhatAmI() << std::endl;
  }
  std::cout << "----------------------------------------------" << std::endl;
  sleep(nb_secondes);
  for (int i = 1; i< nb_tours+1; ++i){
     for (const auto& racer : racers) { //range-based
      random_event(racer, i, Players);

        for (int j = 0; j< nb_secondes; ++j){
          racer->refresh_traveled_ditance();
        }

      std::cout << "Après " << i*nb_secondes << " secondes, la vitesse de " << racer->WhatAmI() << " est de "
                                << racer->speed() << "m/s. Il a parcouru " << racer->traveled_ditance() << "m." << std::endl;
      if (racer->speed() > longest_distance) {
        gagnant = racer->WhatAmI();
        longest_distance = racer->speed();
      }
    }
    sleep(3);
    std::cout << "----------------------------------------------" << std::endl;
  } std::cout << "A l'issu de ces " << nb_tours*nb_secondes << "secondes de course, le gagnant est " << gagnant <<  '\n';

  for (const auto& racer : racers) { //on delete les pointeurs pour ne pas avoir de leaks
    delete racer;
  }
}

void random_event(Character* ptr, int i, std::map<int, std::string> Players){
  srand (time(NULL)-i-int(ptr->WhatAmI()[0])); //on fait en sorte que chq perso ait son propre random_event à chq tour
  int prob = rand() % 5;
  if (prob == 0 || prob == 3) {
    ptr->Accelerate ();
  }
  else if (prob == 1 || prob == 4){
    ptr->Break ();
  } // si prob == 3 on veut que la vitesse reste la même
  std::cout << ptr->WhatAmI() << Players[prob] << std::endl;
}
