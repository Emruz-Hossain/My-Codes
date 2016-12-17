/*   DEVELOPER: John van den Elzen
   PROGRAM: Random Name Generator
   PURPOSE: Exercise C++ programming */

#include <iostream>
#include <ctime>
#include <string>
#include<stdlib.h>
using namespace std;

int main(){

   srand(time(NULL));

   string prefixArray[7] = {"Almighty","Enormous","Godly","Hunters","Insane","Kings","Poisonous"};
   string suffixArray[7] = {"Walkingstick","Greatsword","Axe","Crossbow","Katana","Fistblade","Dagger"};


   for(int i = 0 ; i < 10 ; i++){

      cout << prefixArray[(rand() % 7)] << " " << suffixArray[(rand() % 7)] << endl;

   }



   system("PAUSE");
   return 0;
}
