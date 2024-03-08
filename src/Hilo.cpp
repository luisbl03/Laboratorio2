/*CLASE QUE GESTIONA LA INFORMACION DE TRABAJO DE UN HILO*/
#include <iostream>
#include <string>
#include <thread>
#include <queue>

class Hilo {
    private:
        int id;
        int l_inicio;
        int l_fin;
        std::string nombre;
        std::queue<resultado> resultados;

    public:
        Hilo(int id, int l_inicio, int l_fin, std::string nombre) : id(id), l_inicio(l_inicio), l_fin(l_fin), nombre(nombre) {}
};