#include "../header/NodoLista.h"

NodoLista::~NodoLista() {
  delete aficionado_;
  delete next_;
}
Aficionado* NodoLista::get_aficionado() {
  return aficionado_;
}
NodoLista* NodoLista::get_next() {
  return next_;
}
void NodoLista::set_next(NodoLista* next) {
  next_ = next;
}
