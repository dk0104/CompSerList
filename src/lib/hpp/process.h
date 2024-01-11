#pragma once
#include <string>
#include <vector>

namespace CSL {
class Process {
public:
  Process();
  ~Process();

  // Compress the numbers and save the result in compressed
  void compress(const std::vector<int> &numbers, std::string &compressed);

  // Decompress the compressed string and save the result in decompressed
  void decompress(const std::string &compressed,
                  std::vector<int> &decompressed);

private:
};
} // namespace CSL
