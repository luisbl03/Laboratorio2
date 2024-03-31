#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
#include "Hilo.hpp"
/*DEFINICION DE FUNCIONES*/
int contarLineas(std::string fichero);

int main(int argc, char const *argv[]) {
    /*comprobamos el numero de parametros que se le introduce al programa*/
    if (argc != 4) {
        std::cout << "Error: se esperaban 4 parametros" << std::endl;
        return 1;
    }
    std::string fichero = argv[1];
    std::cout << "Fichero: " << fichero << std::endl;
    std::string palabra = argv[2];
    std::cout << "Palabra: " << palabra << std::endl;
    int nHilos = std::stoi(argv[3]);
    std::cout << "Numero de hilos: " << nHilos << std::endl;
    std::vector<std::thread> exec_hilos;
    std::vector<Hilo> hilos;
    /*contamos las lineas para repartirlas entre los hilos*/
    int lineas = contarLineas(fichero);
    std::cout << "Numero de lineas: " << lineas << std::endl;
    int nLineasHilo = lineas / nHilos;

    for (int i = 1; i<= nHilos; i++) {
        int inicio = (i - 1) * nLineasHilo;
        int fin = i * nLineasHilo - 1;
        if (i == nHilos) {
            fin = lineas - 1;
        }
        exec_hilos.push_back(std::thread(Hilo(i, inicio, fin, palabra, fichero)));
    }
    std::for_each(exec_hilos.begin(),exec_hilos.end(),std::mem_fn(&std::thread::join));
    return 0;
}

int contarLineas(std::string fichero) {
    std::ifstream archivo(fichero);
    std::string linea;
    int lineas = 0;
    while (std::getline(archivo, linea)) {
        lineas++;
    }
    return lineas;
}