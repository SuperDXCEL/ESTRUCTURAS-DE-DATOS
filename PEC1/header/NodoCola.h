#ifndef NODO_COLA_H_
#define NODO_COLA_H_

#include "Aficionado.h"
#include <ostream>

//class Cola;

class NodoCola {
 public:
  NodoCola(Aficionado* aficionado, NodoCola* next);
  ~NodoCola();
  Aficionado* get_aficionado();
  NodoCola* get_next();
  void set_next(NodoCola* nodo);
 private:
  Aficionado* aficionado_;
  NodoCola* next_;
  friend class Cola;
};

#endif //NODO_PILA_H_
