#include <iostream>
#include <string>
using namespace std;
class ResultadoBusqueda {
    private:
        string palabraAnterior;
        string palabraPosterior;
        int linea;
    
    public:
        ResultadoBusqueda(string palabra_anterior, string palabra_posterior, int linea) : palabraAnterior(palabra_anterior), palabraPosterior(palabra_posterior), linea(linea) {}
        void imprimir_resultado() {
            cout << "Palabra anterior: " << palabraAnterior << " Palabra posterior: " << palabraPosterior << " Linea: " << linea << endl;
        }
};