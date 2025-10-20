#include "../header/Lista.h"
#include <iostream>

Lista::Lista() : first_element_(nullptr), last_element_(nullptr), size_(0) {}
Lista::Lista(const Lista& lista) : first_element_(nullptr), size_(lista.size_) {
  if (lista.size_ > 0) {
	  NodoLista* aux = lista.first_element_;
	  while (aux) {
      append(aux->aficionado_);
      std::cout << "appending..." << aux->aficionado_ << "\n";
	    aux = aux->next_;
	  }
	  size_ = lista.size_;
  }
}
Lista::~Lista() {
  NodoLista* aux = first_element_;
  while (aux) {
    NodoLista* copy = aux;
    aux = aux->next_;
    delete copy;
  }
}
void Lista::append(Aficionado* aficionado) {
  NodoLista* node = new NodoLista(aficionado, nullptr);
  if (first_element_) {
    last_element_->next_ = node;
  } else {
    first_element_ = node;
  }
  last_element_ = node;
  std::cout << "NODE ADDRESS: " << node << std::endl;
  size_++;
}
int Lista::get_size() {
  return size_;
}
Aficionado* Lista::operator[](int index) {
  if (!first_element_) {
    return nullptr;
  }
  NodoLista* aux = first_element_;
  while (index != 0) {
    //Should implement try catch here to avoid accessing non existing positions
    aux = aux->next_;
    index--;
  }
  return aux->aficionado_;
}
