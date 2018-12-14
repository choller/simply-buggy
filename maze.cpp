/*
 * maze - A simple constant maze that crashes at some point.
 *
 * WARNING: This program neither makes sense nor should you code like it is
 *          done in this program. It is purely for demo purposes and uses
 *          bad and meaningless coding habits on purpose.
 */

#include <cstdlib>
#include <iostream>

int boom() {
  int* p = (int*)0x1;
  *p = 0xDEADBEEF;
  return *p;
}

int main(int argc, char** argv) {
  if (argc != 5) {
    std::cerr << "All I'm asking for is four numbers..." << std::endl;
    return 1;
  }

  int num1 = atoi(argv[1]);
  if (num1 > 0) {
    int num2 = atoi(argv[2]);
    if (num1 > 2040109464) {
      if (num2 < 0) {
        std::cerr << "You found secret 1" << std::endl;
        return 0;
      }
    } else {
      if ((unsigned int)num2 == 3735928559) {
        unsigned int num3 = atoi(argv[3]);
        if (num3 == 3405695742) {
          int num4 = atoi(argv[4]);
          if (num4 == 1111638594) {
            std::cerr << "You found secret 2" << std::endl;
            boom();
            return 0;
          }
        }
      }
    }
  }

  return 0;
}
