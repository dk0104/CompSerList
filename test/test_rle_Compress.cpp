#include "TestChunks.h"
#include "compressionCalc.h"
#include "process.h"
#include "gtest/gtest.h"
#include <ostream>

using namespace CSL;
using namespace std;
using ::testing::TestWithParam;

class TestProcess : public TestWithParam<TestChunk *> {
public:
  ~TestProcess() {
    if (testInput != nullptr) {
      delete testInput;
    }
  }
  virtual void SetUp() {
    std::cout << "SetUp" << std::endl;

    process = new Process();
    compressionCalc = new CompressionRateCalculator();
    testInput = GetParam();
  }
  virtual void TearDown() {
    std::cout << "TearDown" << std::endl;
    delete process;
    delete compressionCalc;
  }

  Process *process;
  CSL::CompressionRateCalculator *compressionCalc;
  TestChunk *testInput;
};

TEST_P(TestProcess, compress_input_valid_decompress_valid_comp_rate) {
  if (testInput != nullptr) {
    string compressed;
    process->compress(testInput->input, compressed);

    // Assert compressed result contains only ascii characters
    for (int i = 0; i < compressed.length(); i++) {
      ASSERT_TRUE(isascii(compressed[i]));
    }

    // Check if compressed result is smaller than input
    int compressionRate =
        compressionCalc->calculateCompressionRate(testInput->input, compressed);
    ASSERT_TRUE(compressionRate > testInput->rate);

    // Assert decompressed result is equal to input
    std::vector<int> decompressed;
    process->decompress(compressed, decompressed);
    ASSERT_EQ(testInput->input, decompressed);
  } else {
    cout << "TestInput is null" << endl;
  }
}

// Simple test chunk with 100 numbers with 1 digit
TestChunk *fiftyRandomOneDigitNumbers = new TestChunk(50, 1, 50);
TestChunk *hundredRandomOneDigitNumbers = new TestChunk(100, 1, 50);
TestChunk *fiveHundredRandomOneDigitNumbers = new TestChunk(500, 1, 50);
TestChunk *thousandRandomOneDigitNumbers = new TestChunk(1000, 1, 50);

// Simple test chunk with 100 numbers with 2 digits
TestChunk *fiftyRandomTwoDigitNumbers = new TestChunk(50, 2, 50);
TestChunk *hundredRandomTwoDigitNumbers = new TestChunk(100, 2, 50);
TestChunk *fiveHundredRandomTwoDigitNumbers = new TestChunk(500, 2, 50);
TestChunk *thousandRandomTwoDigitNumbers = new TestChunk(1000, 2, 50);

// Simple test chunk with 100 numbers with 3 digits
TestChunk *fiftyRandomThreeDigitNumbers = new TestChunk(50, 3, 50);
TestChunk *hundredRandomThreeDigitNumbers = new TestChunk(100, 3, 50);
TestChunk *fiveHundredRandomThreeDigitNumbers = new TestChunk(500, 3, 50);
TestChunk *thousandRandomThreeDigitNumbers = new TestChunk(1000, 3, 50);

// Tet with 900 numbers 3 times the same number
TestChunk *nineHundredSameNumbers = new TestChunk(900, 0, 50);

TestInput allCombinations{fiftyRandomOneDigitNumbers,
                          hundredRandomOneDigitNumbers,
                          fiveHundredRandomOneDigitNumbers,
                          thousandRandomOneDigitNumbers,
                          fiftyRandomTwoDigitNumbers,
                          hundredRandomTwoDigitNumbers,
                          fiveHundredRandomTwoDigitNumbers,
                          thousandRandomTwoDigitNumbers,
                          fiftyRandomThreeDigitNumbers,
                          hundredRandomThreeDigitNumbers,
                          fiveHundredRandomThreeDigitNumbers,
                          thousandRandomThreeDigitNumbers,
                          nineHundredSameNumbers};

INSTANTIATE_TEST_SUITE_P(compress_input_valid_decompress_valid_comp_rate,
                         TestProcess, ::testing::ValuesIn(allCombinations));
