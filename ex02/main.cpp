#include "Base.h"

int main(void) {
  Base *something = generate();
  identify(something);
  identify(*something);
  delete something;
}
