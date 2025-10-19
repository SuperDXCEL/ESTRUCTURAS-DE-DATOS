#Defines
CC=g++
CFLAGS=-c -Wall
SOURCES = main.cpp ../source/Gestor.cc ../source/Cola.cc ../source/Lista.cc ../source/Aficionado.cc ../source/Pila.cc ../source/NodoCola.cc ../source/NodoPila.cc ../source/NodoLista.cc

#Build Rules

all: $(CC) $(CFLAGS) $(SOURCES)
