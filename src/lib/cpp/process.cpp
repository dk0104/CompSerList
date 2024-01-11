#include "../hpp/process.h"
#include <cstddef>
#include <vector>
using namespace CSL;
using namespace std;

Process::Process() {}
Process::~Process() {}

// Serilaise numbers to ASSII and Compress it using RLE
void Process::compress(const vector<int> &numbers, string &compressed) {
  string asciiser;
  serializeToASCII(numbers, asciiser);
  char current_char = asciiser[0];
  int count = 1;
  for (size_t i = 1; i < asciiser.size(); ++i) {
    if (asciiser[i] == current_char) {
      count++;
    } else {
      compressed += current_char;
      compressed += static_cast<char>(count);
      compressed += asciiser[i];
      count = 1;
    }
  }
  compressed += current_char;
  compressed += static_cast<char>(count);
}

// Decompress the compressed string and deserialize it to vector of numbers
void Process::decompress(const string &compressed, vector<int> &decompressed) {
  string decompressedASCII;
  for (size_t i = 0; i < compressed.size(); i += 2) {
    char asciiChar = compressed[i];
    int count = static_cast<int>(compressed[i + 1]);
    for (int j = 0; j < count; ++j) {
      decompressedASCII.push_back(asciiChar);
    }
  }
  desirializeFromASCII(decompressedASCII, decompressed);
}

void Process::serializeToASCII(const vector<int> &numbers, string &serialized) {
  for (auto &number : numbers) {
    char asciiChar = static_cast<char>(number % 128 + 100);
    serialized += asciiChar;
  }
}

void Process::desirializeFromASCII(const std::string &asciiser,
                                   vector<int> &numbers) {
  for (char asciiChar : asciiser) {
    int number = static_cast<int>(asciiChar) - 100;
    numbers.push_back(number);
  }
}
