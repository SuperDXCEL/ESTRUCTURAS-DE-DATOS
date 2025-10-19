#include "../header/NodoCola.h"

Aficionado* NodoCola::get_aficionado() {
  return aficionado_;
}
NodoCola* NodoCola::get_next() {
  return next_;
}
void NodoCola::set_next(NodoCola* next) {
  next_ = next;
}
