#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H

#include <iostream>
#include "Aficionado.h"

class NodoArbol {
 public:
  NodoArbol(Aficionado* aficionado);
  ~NodoArbol();
  Aficionado* get_dato();
  NodoArbol* get_izq();
  NodoArbol* get_der();
  void set_izq(NodoArbol* nodo);
  void set_der(NodoArbol* nodo);
 private:
  Aficionado* dato;
  NodoArbol* izq;
  NodoArbol* der;
  
  friend class Arbol;
};

#endif // NODO_ARBOL_H
