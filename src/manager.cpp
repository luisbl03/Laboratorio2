#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <fstream>
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
    std::string palabra = argv[2];
    int nHilos = std::stoi(argv[3]);

    /*contamos las lineas para repartirlas entre los hilos*/
    int lineas = contarLineas(fichero);
    int nLineasHilo = lineas / nHilos;

    std::queue<std::thread> hilos;
    for (int i = 1; i<= nHilos; i++) {
        int inicio = (i - 1) * nLineasHilo;
        int fin = i * nLineasHilo - 1;
        if (i == nHilos) {
            fin = lineas - 1;
        }
        hilos.push(std::thread(Hilo(i, inicio, fin, palabra, fichero)));
    }

    while (!hilos.empty()) {
        hilos.front().join();
        hilos.pop();
    }

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