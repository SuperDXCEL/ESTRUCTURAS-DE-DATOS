#ifndef AFICIONADO_H_
#define AFICIONADO_H_

#include <ostream>

class Aficionado {
 public:
  Aficionado(int id, int arrival_time);
  ~Aficionado();
  int get_id();
  int get_arrival_time();
  bool get_member();
 private:
  int id_;
  int arrival_time_;
  bool member_;
  friend std::ostream& operator<<(std::ostream& os, Aficionado* aficionado);
};
#endif //AFICIONADO_H_
