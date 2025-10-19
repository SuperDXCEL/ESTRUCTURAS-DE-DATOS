#ifndef LISTA_H
#define LISTA_H

#include "../header/NodoLista.h"
#include "../header/Aficionado.h"

class Lista {
 public:
  Lista();
  ~Lista();
  void insert(Aficionado* aficionado);
 private:
  NodoLista* first_element_;
  int size_;
  Aficionado* operator[](int index);
};

#endif //LISTA_H
