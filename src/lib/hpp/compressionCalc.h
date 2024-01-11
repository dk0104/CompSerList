#pragma once
#include <string>
#include <vector>

namespace CSL {
class CompressionRateCalculator {
public:
  CompressionRateCalculator();
  ~CompressionRateCalculator();

  // Calculate the compression rate of the compressed string
  int calculateCompressionRate(const std::vector<int> &numbers,
                               const std::string &compressed);
};
} // namespace CSL
