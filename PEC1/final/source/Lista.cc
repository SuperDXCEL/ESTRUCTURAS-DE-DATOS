#include "../header/Lista.h"
#include <iostream>

Lista::Lista() : first_element_(nullptr), last_element_(nullptr), size_(0) {}
Lista::Lista(const Lista& lista) : first_element_(nullptr), size_(lista.size_) {
  if (lista.size_ > 0) {
	  NodoLista* aux = lista.first_element_;
	  while (aux) {
      append(aux->aficionado_);
      // std::cout << "appending..." << aux->aficionado_ << "\n";
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
int Lista::get_size() {
  return size_;
}
void Lista::append(Aficionado* aficionado) {
  NodoLista* node = new NodoLista(aficionado, nullptr);
  if (first_element_) {
    last_element_->next_ = node;
  } else {
    first_element_ = node;
  }
  last_element_ = node;
  // std::cout << "NODE ADDRESS: " << node << std::endl;
  size_++;
}
void Lista::order_by_id() {
  if (size_ <= 1) return;
  
  NodoLista* i = first_element_;
  
  while (i != nullptr) {
    NodoLista* min = i;
    NodoLista* j = i->next_;
    
    // Buscar el mínimo en el resto de la lista
    while (j != nullptr) {
      if (j->aficionado_->get_id() < min->aficionado_->get_id()) {
        min = j;
      }
      j = j->next_;
    }
    
    // Intercambiar si encontramos uno menor
    if (min != i) {
      Aficionado* temp = i->aficionado_;
      i->aficionado_ = min->aficionado_;
      min->aficionado_ = temp;
    }
    
    i = i->next_;
  }
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
