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
  // Serialize the numbers to ASCII
  void serializeToASCII(const std::vector<int> &numbers,
                        std::string &serialized);
  void desirializeFromASCII(const std::string &asciiser,
                            std::vector<int> &numbers);
};
} // namespace CSL
