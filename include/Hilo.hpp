#ifndef HILO_H
#define HILO_H

#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <sstream>
#include <fstream>
#include "Resultado_busqueda.hpp"
#include "Buscador.hpp"
#include <mutex>
using namespace std;
mutex semaforo;
queue<ResultadoBusqueda> busquedaFinal;
class Hilo {
    private:
        int id;
        int l_inicio;
        int l_fin;
        string palabra;
        string archivo;
    public:
        Hilo(int id, int l_inicio, int l_fin, string palabra, string n_archivo);
        void operator () () const;
        
};void mostrarResultados(string palabra);

#endif