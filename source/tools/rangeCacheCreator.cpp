#include "../Collatz.cpp"
#include <iostream>
#include <string>
#include <sstream>

const int DIVIDE = 1000;

int main(int argc, char** argv){
   int end = 1000000;
   int gap = end / DIVIDE;
   std::stringstream ss;
   ss << "{";
   for(int i = 1; i <= 1000001; i += gap){
      ss << collatz_eval(i, i+gap-1) << ", ";
   }
   std::string result = ss.str();
   result.erase(result.end()-2, result.end());
   result.append("}");
   std::cout << result << std::endl;
   return 0;
}
