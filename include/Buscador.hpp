#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class AgenteBuscador {
    public:
        void eliminarCaracteresEspeciales(vector<string>& s);
        vector<string> separarPorEspacios(string linea);
        vector<vector<string>> buscarPalabras(vector<string> palabras,string palabra);
};

#endif