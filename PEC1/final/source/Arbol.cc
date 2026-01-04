#include "../header/Arbol.h"
#include <sstream>

using namespace std;

Arbol::Arbol() { 
    Aficionado* aficionado = new Aficionado(0, 0);
    raiz = new NodoArbol(aficionado); 
}
NodoArbol* Arbol::get_raiz() {
    return raiz;
}
void Arbol::insertar(Aficionado* aficionado) {
    // Decidir si va a izquierda (socio) o derecha (simpatizante)
    if(aficionado->get_member()) {
        raiz->izq = insertarEnArbol(raiz->izq, aficionado);
    } else {
        raiz->der = insertarEnArbol(raiz->der, aficionado);
    }
}
NodoArbol* Arbol::insertarEnArbol(NodoArbol* nodo, Aficionado* aficionado) {
    if(!nodo)
        return new NodoArbol(aficionado);
    
    if(aficionado->get_id() < nodo->dato->get_id())
        nodo->izq = insertarEnArbol(nodo->izq, aficionado);
    else if(aficionado->get_id() > nodo->dato->get_id())
        nodo->der = insertarEnArbol(nodo->der, aficionado);
    
    return nodo;
}
void Arbol::pintar() {
    pintar(raiz);
    cout << '\n';
}
void Arbol::pintar(NodoArbol* nodo) {
    if(!nodo)
        return;
    pintar(nodo->izq);
    cout << nodo->dato << " ";
    pintar(nodo->der);
}
int Arbol::altura(NodoArbol* nodo) {
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}
void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, NodoArbol* nodo, int nivel, int p,
                        char linkChar) {
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        Aficionado* aficionado = nodo->izq->dato;
        std::ostringstream oss;
        oss << aficionado;
        string aficionadoAImprimir = to_string(aficionado->get_id()) + " " + to_string(aficionado->get_arrival_time()) + " " + to_string(aficionado->get_member()); 
        string izqdato = SP + aficionadoAImprimir + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    Aficionado* aficionado = nodo->dato;
    std::ostringstream oss;
    oss << aficionado;
    string aficionadoAImprimir = to_string(aficionado->get_id()) + " " + to_string(aficionado->get_arrival_time()) + " " + to_string(aficionado->get_member()); 
    string nododato = SP + aficionadoAImprimir + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}
void Arbol::dibujar() {
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

Arbol::~Arbol() {}