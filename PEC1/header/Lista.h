#ifndef LISTA_H
#define LISTA_H

#include "../header/NodoLista.h"
#include "../header/Aficionado.h"

class Lista {
 public:
  Lista();
  Lista(const Lista& lista);
  ~Lista();
  void append(Aficionado* aficionado);
  int get_size();
  Aficionado* operator[](int index);
 private:
  NodoLista* first_element_;
  NodoLista* last_element_;
  int size_;
};

#endif //LISTA_H
