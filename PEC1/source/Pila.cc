#include <cstddef>
#include <iostream>
#include "../header/Pila.h"

Pila::Pila() : top_element_(nullptr), size_(0) {}
Pila::Pila(Pila* stack) : top_element_(nullptr), size_(0) {
  if (stack) {
  NodoPila* aux = stack->top_element_;
  NodoPila* head = new NodoPila(nullptr, nullptr);
  NodoPila* dummy = head;
  while (aux) {
    NodoPila* node = new NodoPila(aux->aficionado_, nullptr);
    head->next_ = node;
    head = head->next_;
    aux = aux->next_;
    std::cout << "enters infinite loop?" << std::endl;
  }
  top_element_ = dummy->next_;
  size_ = stack->size_;
  std::cout << "ended infinite loop?" << std::endl;
  }
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
    Aficionado* copy = aux->aficionado_;
    // This creates a dangling pointer when you pop the last element
    // Since top_element will still point to the next pointer.
    //        top_element_ = top_element_->next_;
//    if (top_element_->next_) {
//      top_element_ = top_element_->next_;
//    }
    top_element_ = top_element_->next_;
    delete aux;
    size_--;
    return copy;
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
