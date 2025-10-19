#ifndef NODO_PILA_H_
#define NODO_PILA_H_

#include "Aficionado.h"
#include <ostream>

class Pila;

class NodoPila {
 public:
  NodoPila(Aficionado* aficionado, NodoPila* next) : aficionado_(aficionado), next_(next) {}
//  ~NodoPila();
  Aficionado* get_aficionado();
  NodoPila* get_next();
  void set_next(NodoPila* nodo);
 private:
  Aficionado* aficionado_;
  NodoPila* next_;
  friend class Pila;
};

#endif //NODO_PILA_H_
