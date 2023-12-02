#include <iostream>
#include <vector>


#define CALL(func, argument) { func(argument); }

#define passengerCountInput(train) { \
   for (int i = 0; i < 10; i++){\
      int passengerCount; \
      std::cout << std::endl << "Enter the count of passangers in " << i + 1 << " carriage: ";\
      std::cin >> passengerCount;\
      train[i] = passengerCount;\
   }\
}

#define passengerAnalysis(train) { \
   int pasTrainCount = 0; \
   for (int i = 0; i < 10; i++){ \
      pasTrainCount += train[i]; \ 
      if (train[i] > 20){ \
         std::cout << std::endl << "Carriage " << i + 1 << " is crowded"; \
      }else if (train[i] == 0) std::cout << std::endl << "Carriage " << i + 1 << " is empty";  \
   } \
   std::cout << std::endl << "Pasangers count in train: " << pasTrainCount; \
}

void print(std::string str) {
   std::cout << str << std::endl;
}

int main(){
   std::vector<int> train(10);
   passengerCountInput(train);
   passengerAnalysis(train);
}