#include <iostream>
#include "persona.hpp"
#include <cstring>
#include <time.h>
#include <stdlib.h>

bool random_boolean() {
  return (bool) rand() % 2;
}

void random_nine_digit_number(char number[10]) {
  for (int i = 0; i < 9; i++) {
    number[i] = (rand() % 10) + '0';
  }
}

char random_letter() {
  int value = rand() % (90-65+1) + 65;
  return char(value);
}

Persona::Persona(int edad) : edad_(edad) {
  srand(time(nullptr));
  gender_ = random_boolean();
  char number[10];
  random_nine_digit_number(number);
  char letter = random_letter();
  number[9] = letter;
  strncpy(dni_, number, 10);
};

int Persona::getEdad() {
  return edad_;
}

bool Persona::esMujer() {
  return gender_ == 1;
}

void Persona::setEdad(int edad) {
  edad_ = edad;
}

void Persona::mostrar() {
  std::cout << gender_ << " " << edad_ << " " << dni_ << std::endl;
}
