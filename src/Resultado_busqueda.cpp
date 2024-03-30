#include "Resultado_busqueda.hpp"

    ResultadoBusqueda::ResultadoBusqueda(string palabra_anterior, string palabra_posterior, int linea) : palabraAnterior(palabra_anterior), palabraPosterior(palabra_posterior), linea(linea) {}
    void ResultadoBusqueda::imprimir_resultado() {
        cout << "Palabra anterior: " << palabraAnterior << " Palabra posterior: " << palabraPosterior << " Linea: " << linea << endl;
    }