/*
 * out-of-bounds - A simple multi-signature out-of-bounds demo.
 *
 * WARNING: This program neither makes sense nor should you code like it is
 *          done in this program. It is purely for demo purposes and uses
 *          bad and meaningless coding habits on purpose.
 */
#include <cstring>
#include <fstream>
#include <iostream>

void printFirst(char* data, size_t count) {
  std::string first(data, count);
  std::cout << first << std::endl;
}

void printLast(char* data, size_t count) {
  std::string last(data + strlen(data) - count, count);
  std::cout << last << std::endl;
}

int validateAndPerformAction(char* buffer, size_t size) {
  if (size < 2) {
    std::cerr << "Buffer is too short." << std::endl;
    return 1;
  }

  uint8_t action = buffer[0];
  uint8_t count = buffer[1];
  char* data = buffer + 2;

  if (!count) {
    std::cerr << "count must be non-zero." << std::endl;
    return 1;
  }

  // Forgot to check count vs. the length of data here, doh!

  if (!action) {
    printFirst(data, count);
    return 0;
  } else if (action == 1) {
    printLast(data, count);
    return 0;
  } else {
    std::cerr << "Action must either be 'first' or 'last'." << std::endl;
    return 1;
  }
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Usage is: " << argv[0] << " <file>" << std::endl;
    exit(1);
  }

  std::ifstream input(argv[1], std::ifstream::binary);
  if (!input) {
    std::cerr << "Error opening file." << std::endl;
    exit(1);
  }

  input.seekg(0, input.end);
  int size = input.tellg();
  input.seekg(0, input.beg);

  if (size < 0) {
    std::cerr << "Error seeking in file." << std::endl;
    exit(1);
  }

  char* buffer = new char[size];
  input.read(buffer, size);

  if (!input) {
    std::cerr << "Error while reading file." << std::endl;
    exit(1);
  }

  int ret = validateAndPerformAction(buffer, size);

  delete[] buffer;
  return ret;
}
