#include "../header/Lista.h"

Lista::Lista() {
  first_element_ = nullptr;
  size_ = 0;
}
Lista::~Lista() {
  NodoLista* aux = first_element_;
  while (aux) {
    NodoLista* copy = aux;
    aux = aux->next_;
    delete copy;
  }
}
void Lista::insert(Aficionado* aficionado) {
  NodoLista* node = new NodoLista(aficionado, nullptr);
  if (first_element_) {
    first_element_->next_ = node;
  } else {
  first_element_ = node;
  }
  size_++;
}
Aficionado* Lista::operator[](int index) {
  if (index == 0 && first_element_) {
    return first_element_->aficionado_;
  }
  NodoLista* aux = first_element_;
  while (index != 0) {
    //Should implement try catch here to avoid accessing non existing positions
    aux = aux->next_;
    index--;
  }
  return aux->aficionado_;
}
