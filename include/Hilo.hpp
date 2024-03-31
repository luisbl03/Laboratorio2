
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
        int id;
        int l_inicio;
        int l_fin;
        static std::mutex semaforo;
        static std::queue<ResultadoBusqueda> busquedaFinal;
        string palabra;
        string archivo;
    public:
       
        Hilo(int id, int l_inicio, int l_fin, string palabra, string n_archivo);
        void operator () () const;
        static void mostrarResultados(vector<Hilo> hilos);
};

#endif