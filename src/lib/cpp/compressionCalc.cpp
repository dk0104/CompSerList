#include "compressionCalc.h"
using namespace CSL;

CompressionRateCalculator::CompressionRateCalculator() {}
CompressionRateCalculator::~CompressionRateCalculator() {}

int CompressionRateCalculator::calculateCompressionRate(
    const std::vector<int> &numbers, const std::string &compressed) {
  int inputSize = numbers.size() * sizeof(int);
  int compressedSize = compressed.size();
  return (compressedSize * 100) / inputSize;
}
