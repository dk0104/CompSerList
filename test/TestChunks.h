#include <cstddef>
#include <random>
#include <string>
#include <vector>

struct TestChunk {
  TestChunk(int size, int digits, int rate) : rate(rate) {
    createRandomInput(size, digits);
  };
  void createRandomInput(int size, int digits) {
    std::random_device rd;
    std::mt19937 gen(rd());
    if (digits == 1) {
      std::uniform_int_distribution<> dis(0, 9);
      for (int i = 0; i < size; ++i) {
        input.push_back(dis(gen));
      }
      return;
    }
    if (digits == 2) {
      std::uniform_int_distribution<> dis(10, 99);
      for (int i = 0; i < size; ++i) {
        input.push_back(dis(gen));
      }
      return;
    }
    if (digits == 3) {
      std::uniform_int_distribution<> dis(100, 300);
      for (int i = 0; i < size; ++i) {
        input.push_back(dis(gen));
      }
      return;
    }
  }
  std::vector<int> input;
  int rate;
};

typedef TestChunk *TestInput[];
