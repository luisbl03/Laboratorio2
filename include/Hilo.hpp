
#ifndef HILO_H
#define HILO_H
#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <sstream>
#include <fstream>
#include <mutex>
#include "Resultado_busqueda.hpp"
using namespace std;
class Hilo {
    private:
        std::priority_queue<ResultadoBusqueda>& resultadoBusquedaFinal;
        int id;
        int l_inicio;
        int l_fin;
        static std::mutex semaforo;
        string palabra;
        string archivo;
        void buscar(priority_queue<ResultadoBusqueda>& resultados);
        void insertarCola(priority_queue<ResultadoBusqueda>& resultados);
    public:
        int getLineaInicio();
        int getLineaFin();
        int getId();
        string getPalabra();
        Hilo(priority_queue<ResultadoBusqueda>& rb_final,int id, int l_inicio, int l_fin, string palabra, string n_archivo);
        void operator () ();
};

#endif