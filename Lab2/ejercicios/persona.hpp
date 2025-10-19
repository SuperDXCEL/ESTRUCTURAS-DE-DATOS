class Persona {
 private:
  bool gender_;
  int edad_;
  char dni_[10];
 public:
  Persona() {}
  Persona(int edad);
  int getEdad();
  bool esMujer();
  void setEdad(int edad);
  void mostrar();
};
