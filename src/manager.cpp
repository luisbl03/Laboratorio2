#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <fstream>

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
    int n_hilos = std::stoi(argv[3]);

    /*Preparamos la cola de hilos*/
    std::queue<std::thread> hilos;
    
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