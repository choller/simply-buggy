/*
 * simple-crash - A simple NULL crash.
 *
 * WARNING: This program neither makes sense nor should you code like it is
 *          done in this program. It is purely for demo purposes and uses
 *          bad and meaningless coding habits on purpose.
 */

int crash() {
  int* p = (int*)0x1;
  *p = 0xDEADBEEF;
  return *p;
}

int main(int argc, char** argv) {
  return crash();
}
