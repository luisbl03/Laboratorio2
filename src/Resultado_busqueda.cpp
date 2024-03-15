#include <iostream>


class Resultado_busqueda {
    private:
        std::string palabra_anterior;
        std::string palabra_posterior;
        int linea;
    
    public:
        Resultado_busqueda(std::string palabra_anterior, std::string palabra_posterior, int linea) : palabra_anterior(palabra_anterior), palabra_posterior(palabra_posterior), linea(linea) {}
        void imprimir_resultado() {
            std::cout << "Palabra anterior: " << palabra_anterior << " Palabra posterior: " << palabra_posterior << " Linea: " << linea << std::endl;
        }
};