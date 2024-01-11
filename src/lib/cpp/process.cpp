#include "../hpp/process.h"
#include <cstddef>
#include <sstream>
#include <vector>
using namespace CSL;
using namespace std;

Process::Process() {}
Process::~Process() {}

// Serilaise numbers to ASSII and Compress it using RLE
void Process::compress(const vector<int> &numbers, string &compressed) {
  stringstream ss;
  for (int num : numbers) {
    ss << static_cast<char>('0' + num / 100)
       << static_cast<char>('0' + (num / 10) % 10)
       << static_cast<char>('0' + num % 10);
  }
  compressed = ss.str();
}

// Decompress the compressed string and deserialize it to vector of numbers
void Process::decompress(const string &compressed, vector<int> &decompressed) {
  for (size_t i = 0; i < compressed.size(); i += 3) {
    int num = (compressed[i] - '0') * 100 + (compressed[i + 1] - '0') * 10 +
              (compressed[i + 2] - '0');
    decompressed.push_back(num);
  }
}
