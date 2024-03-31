#ifndef RESULTADO_BUSQUEDA_H
#define RESULTADO_BUSQUEDA_H

#include <iostream>
#include <string>
using namespace std;

class ResultadoBusqueda {
    private:
        string palabraAnterior;
        string palabraPosterior;
        int linea;
    public:
        ResultadoBusqueda(string palabra_anterior, string palabra_posterior, int linea);
        string getPalabraAnterior();
        string getPalabraPosterior();
        int getLinea();
        bool operator<(const ResultadoBusqueda& otro) const;
};

#endif
