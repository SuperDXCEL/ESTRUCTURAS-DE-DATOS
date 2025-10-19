#ifndef PILA_H_
#define PILA_H_

#include "NodoPila.h"

class Pila {
 public:
  Pila();
  ~Pila();
  Aficionado* top();
  Aficionado* pop();
  void push(Aficionado* node);
  int get_size();
 private:
  NodoPila* top_element_;
  int size_;
};

#endif //PILA_H_
