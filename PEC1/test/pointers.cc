#include "../header/NodoPila.h"
#include <iostream>

// Aficionado* Pila::pop() {
//   if (top_element_) {
//     NodoPila* aux = top_element_;
//     NodoPila* copy = aux;
//     if (top_element_->next_) {
//       top_element_ = top_element_->next_;
//     }
//     delete copy;
//     size_--;
//     std::cout << "JUST POPPED: " << aux->aficionado_ << std::endl;
//     return aux->aficionado_; 
//   }
//   return nullptr;
// }

int main() {
  Aficionado* fan = new Aficionado(10, 4);
  NodoPila* head = new NodoPila(fan, nullptr);
  Aficionado* aux = head->get_aficionado();
  NodoPila* copy = head;
  delete copy;
  std::cout << aux << std::endl;
  std::cout << head->get_aficionado() << std::endl;
}
