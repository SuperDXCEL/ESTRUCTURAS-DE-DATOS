#include "../header/NodoCola.h"

NodoCola::NodoCola(Aficionado* fan, NodoCola* next) : aficionado_(fan), next_(next) {}
NodoCola::~NodoCola() {}
Aficionado* NodoCola::get_aficionado() {
  return aficionado_;
}
NodoCola* NodoCola::get_next() {
  return next_;
}
void NodoCola::set_next(NodoCola* next) {
  next_ = next;
}
