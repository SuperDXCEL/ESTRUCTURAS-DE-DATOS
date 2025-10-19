#include <cstddef>
#include "../header/Pila.h"

Pila::Pila() {
  top_element_ = NULL;
  size_ = 0;
}
Pila::~Pila() {
  NodoPila* aux = top_element_;
  while (size_ > 0) {
    Aficionado* fan = pop();
    delete fan;
  }
}
Aficionado* Pila::top() {
  return top_element_->aficionado_;
}
Aficionado* Pila::pop() {
  if (top_element_) {
    NodoPila* aux = top_element_;
    NodoPila* copy = aux;
    if (top_element_->next_) {
      top_element_ = top_element_->next_;
    }
    delete copy;
    size_--;
    return aux->aficionado_; 
  }
  return nullptr;
}
void Pila::push(Aficionado* fan) {
  NodoPila* node = new NodoPila(fan, nullptr);
  if (top_element_) {
    node->next_ = top_element_;
  }
  top_element_ = node;
  size_++;
}
int Pila::get_size() {
  return size_;
}
