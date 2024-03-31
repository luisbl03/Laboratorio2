#include "Resultado_busqueda.hpp"
#include <iostream>
#include <string>
ResultadoBusqueda::ResultadoBusqueda(string palabra_anterior, string palabra_posterior, int linea) : palabraAnterior(palabra_anterior), palabraPosterior(palabra_posterior), linea(linea) {}
string ResultadoBusqueda::getPalabraAnterior() { return palabraAnterior; }
string ResultadoBusqueda::getPalabraPosterior() { return palabraPosterior; }
int ResultadoBusqueda::getLinea() { return linea; }
bool ResultadoBusqueda::operator<(const ResultadoBusqueda& otro) const {
    return linea > otro.linea;
}

