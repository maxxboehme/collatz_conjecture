#include <iostream>
#include <random>

int main(){
   std::random_device rd;
   std::mt19937 e2(rd());
   std::uniform_int_distribution<int> dist(1, 1000000);

   for (int i = 0; i < 10; ++i){
      std::cout << dist(e2) << " " << dist(e2) << std::endl;
   }
   return 0;
}
