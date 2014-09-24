#include <iostream>
#include <string>
#include <sstream>

int collatz_cycle(int num){
   int cycle = 1;
   while(num != 1){
      if(num & 1){
         num = (num * 3 + 1) >> 1;
         ++cycle;
      } else {
         num = num >> 1;
      }
      ++cycle;
   }
   return cycle;
}

int collatz_max_cycle(int min, int max){
   int maxCycles = 0;
   for(int num = min; num <= max; num++){
      int cycle = collatz_cycle(num);
      if(cycle > maxCycles){
          maxCycles = cycle;
      }
   }
   return maxCycles;
}

int main(int argc, char* argv[]){
   std::string line;
   int min, max;
   while(std::cin >> min >> max){
      int maxNumCycles = collatz_max_cycle(min, max);
      std::cout << min << " " << max << " " << maxNumCycles << std::endl;
   }
   return 0;
}
