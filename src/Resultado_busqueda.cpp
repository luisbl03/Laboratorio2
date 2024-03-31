#include "Resultado_busqueda.hpp"

ResultadoBusqueda::ResultadoBusqueda(int n_hilo, string palabra_anterior, string palabra_posterior, int linea) : numeroHilo(n_hilo),palabraAnterior(palabra_anterior), palabraPosterior(palabra_posterior), linea(linea) {}
string ResultadoBusqueda::getPalabraAnterior() { return palabraAnterior; }
string ResultadoBusqueda::getPalabraPosterior() { return palabraPosterior; }
int ResultadoBusqueda::getNumeroHilo() { return numeroHilo;}
int ResultadoBusqueda::getLinea() { return linea; }
bool ResultadoBusqueda::operator<(const ResultadoBusqueda& otro) const {
    return linea > otro.linea;
}

