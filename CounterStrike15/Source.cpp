#include <stdbool>
#include <memory>
#include <iostream>
#include <vector.h>
#include <string.h> 
#include "Windows.h"

#include "hacks/Lazer/Lazer.hpp"
#include "hacks/FlyHack/FlyHack.hpp"

#include "ui/ui.hpp"
#include "Signature.hpp"
#include "Process.hpp"

extern "C" __declspec(dllexport) int main(void);

int main(void) {
  gl_main();
  return 0x0000;
}
