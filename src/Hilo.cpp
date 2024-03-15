/*CLASE QUE GESTIONA LA INFORMACION DE TRABAJO DE UN HILO*/
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
        string archivo;
        }
    public:
        Hilo(int id, int l_inicio, int l_fin, string palabra, string n_archivo) : id(id), l_inicio(l_inicio), l_fin(l_fin), palabra(palabra), archivo(n_archivo) {}
        void operator () () const
        {
            string linea;
            for(int n_lineas = 0; getline(archivo,linea); n_lineas++){
                if(n_lineas == l_inicio){
                    vector<string> palabras;
                    isstringstream division(linea);
                    string l_palabra;
                    while(division >> l_palabra)
                        palabras.push_back(l_palabra);
                    eliminarCaracteresEspeciales(s);


                }
            }
        }
};