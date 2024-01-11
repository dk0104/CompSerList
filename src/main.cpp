#include "lib/hpp/process.h"
#include <iostream>
#include <random>
#include <vector>

using namespace CSL;
using namespace std;

int main() {
  // Generate a list of random numbers from 0 to 300
  const int SIZE = 1000;
  std::vector<int> numbers(SIZE);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 300);

  for (int i = 0; i < SIZE; ++i) {
    numbers[i] = dis(gen);
  }

  // compress the list of numbers
  std::string compressed;
  Process process;
  process.compress(numbers, compressed);
  cout << "Compressed string: " << compressed << endl;

  return 0;
}
