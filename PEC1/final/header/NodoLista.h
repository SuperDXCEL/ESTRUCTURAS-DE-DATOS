#ifndef NODO_LISTA_H_
#define NODO_LISTA_H_

#include "Aficionado.h"

class NodoLista {
 public:
  NodoLista(Aficionado* aficionado, NodoLista* next) : aficionado_(aficionado), next_(next) {}
  ~NodoLista();
  Aficionado* get_aficionado();
  NodoLista* get_next();
  void set_next(NodoLista* nodo);
 private:
  Aficionado* aficionado_;
  NodoLista* next_;
  friend class Lista;
};

#endif //NODO_LISTA_H_