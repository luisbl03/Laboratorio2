#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
#include <random>
#include "Hilo.hpp"
#include "rang.hpp"
#include "Resultado_busqueda.hpp"

/*DEFINICION DE FUNCIONES*/
int contarLineas(std::string fichero);
void mostrarResultados(priority_queue<ResultadoBusqueda> resultados, vector<Hilo> hilos);



int main(int argc, char const *argv[]) {
    /*comprobamos el numero de parametros que se le introduce al programa*/
    if (argc != 4) {
        std::cout << rang::fg::red<< "Error: se esperaban 3 parametros: archivo palabra nº hilos  "<< rang::fg::reset << std::endl;
        return 1;
    }
    std::priority_queue<ResultadoBusqueda> resultados;
    std::string fichero = argv[1];
    std::cout<< rang::fg::yellow;
    std::cout << "";
    std::cout << "Fichero: " << fichero << std::endl;
    std::string palabra = argv[2];
    std::cout << "Palabra: " << palabra << std::endl;
    int nHilos = std::stoi(argv[3]);
    std::cout << "Numero de hilos: " << nHilos << std::endl;
    std::cout << rang::fg::reset;
    std::vector<Hilo> hilos;
    std::vector<std::thread> exec_hilos;
    /*contamos las lineas para repartirlas entre los hilos*/
    int lineas = contarLineas(fichero);
    int nLineasHilo = lineas / nHilos;

    for (int i = 1; i<= nHilos; i++) {
        int inicio = (i - 1) * nLineasHilo;
        int fin = i * nLineasHilo - 1;
        if (i == nHilos) {
            fin = lineas - 1;
        }
        Hilo h(resultados,i, inicio, fin, palabra, fichero);
        hilos.push_back(h);
        exec_hilos.push_back(std::thread(h));
    }
    std::for_each(exec_hilos.begin(),exec_hilos.end(),std::mem_fn(&std::thread::join));
    if (!resultados.empty()) {
        cout << rang::fg::green << "Resultados encontrados: " << resultados.size() << rang::fg::reset << endl;
    }
    else {
        cout << rang::fg::red << "No se han encontrado resultados" << rang::fg::reset << endl;
        return 1;
    }
    mostrarResultados(resultados,hilos);
    return 0;
}

/*Funcion para contar las lineas del fichero, las devuelve*/
int contarLineas(std::string fichero) {
    std::ifstream archivo(fichero);
    /*comprobamos que el archivo existe*/
    if (!archivo) {
        std::cout << rang::fg::red << "Error: no se ha podido abrir el archivo" << rang::fg::reset << std::endl;
        exit(1);
    }
    std::string linea;
    int lineas = 0;
    while (std::getline(archivo, linea)) {
        lineas++;
    }
    return lineas;
}

/*Funcion para mostrar por pantalla los resultados*/
void mostrarResultados(priority_queue<ResultadoBusqueda> resultados, vector<Hilo> hilos){
    while(!resultados.empty()){
        for (Hilo hilo : hilos) {
            while (!resultados.empty()) {
                ResultadoBusqueda resultado = resultados.top();
                if ((resultado.getLinea() >= hilo.getLineaInicio()) and (resultado.getLinea() <= hilo.getLineaFin())) {
                    cout << rang::fg::cyan; 
                    cout << "[Hilo " << hilo.getId() << " inicio:" << hilo.getLineaInicio() << " fin:" << hilo.getLineaFin() << "] ";
                    cout << rang::fg::reset;
                    cout << " :: línea " << resultado.getLinea() << " :: ";
                    cout << "..." << resultado.getPalabraAnterior() << " " ;
                    cout << rang::fg::green << hilo.getPalabra() << rang::fg::reset << " ";
                    cout << resultado.getPalabraPosterior() << "..." << endl;
                    resultados.pop();
                } else {
                    break;
                }
            }
        }
    }
}

