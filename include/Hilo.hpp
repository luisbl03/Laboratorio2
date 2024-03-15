#ifndef HILO_H
#define HILO_H

#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <sstream>
#include <fstream>
using namespace std;

class Hilo {
    private:
        int id;
        int l_inicio;
        int l_fin;
        string palabra;
        queue<ResultadoBusqueda> resultados;
        ifstream archivo;
        
    public:
        Hilo(int id, int l_inicio, int l_fin, string palabra, string n_archivo);
        void operator () () const;
};