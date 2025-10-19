#include <iostream>

int main() {
  int x, y, *p, *q;
  p = &x;
  *p = 5;
  q = &y;
  *q = 23;
  std::cout << p << " " << q << std::endl;
  q = p;
  *p = 35;
  std::cout << p << " " << q << std::endl;
  q = NULL;
  std::cout << x << " " << y << std::endl;
}
