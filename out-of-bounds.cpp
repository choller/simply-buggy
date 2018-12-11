/*
 * out-of-bounds - A simple multi-signature out-of-bounds demo.
 *
 * WARNING: This program neither makes sense nor should you code like it is
 *          done in this program. It is purely for demo purposes and uses
 *          bad and meaningless coding habits on purpose.
 */
#include <cstring>
#include <iostream>

void printFirst(char* data, size_t count) {
  std::string first(data, count);
  std::cout << first << std::endl;
}

void printLast(char* data, size_t count) {
  std::string last(data + strlen(data) - count, count);
  std::cout << last << std::endl;
}

int validateAndPerformAction(char* action, char* data, size_t count) {
  if (!count) {
    std::cerr << "count must be non-zero." << std::endl;
    return 1;
  }

  // Forgot to check count vs. the length of data here, doh!

  if (!strcmp(action, "first")) {
    printFirst(data, count);
    return 0;
  } else if (!strcmp(action, "last")) {
    printLast(data, count);
    return 0;
  } else {
    std::cerr << "Action must either be 'first' or 'last'." << std::endl;
    return 1;
  }
}

int main(int argc, char** argv) {
  if (argc < 4) {
    std::cerr << "Usage is: " << argv[0] << " <first|last> <data> <count>" << std::endl;
    exit(1);
  }

  // Simulate data on the heap, as argc/argv have some special behavior with ASan
  char* data = (char*)malloc(strlen(argv[2]) + 1);
  strcpy(data, argv[2]);

  return validateAndPerformAction(argv[1], data, atol(argv[3]));
}
