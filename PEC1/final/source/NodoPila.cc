#include <ostream>
#include "../header/NodoPila.h"
#include "../header/Aficionado.h"

//NodoPila::NodoPila(Aficionado* aficionado, NodoPila* next) : aficionado_(aficionado), next_(next) {}
//NodoPila::~NodoPila() {}

Aficionado* NodoPila::get_aficionado() {
  return aficionado_;
}
NodoPila* NodoPila::get_next() {
  return next_;
}
void NodoPila::set_next(NodoPila* next) {
  next_ = next;
}
