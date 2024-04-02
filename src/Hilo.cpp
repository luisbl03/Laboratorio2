#include "Buscador.hpp"
#include <mutex>
#include "Hilo.hpp"
#include "Resultado_busqueda.hpp"

mutex Hilo::semaforo;
Hilo::Hilo(priority_queue<ResultadoBusqueda> &rb_final,int id, int l_inicio, int l_fin, string palabra, string n_archivo) : 
    resultadoBusquedaFinal(rb_final), id(id), l_inicio(l_inicio), l_fin(l_fin), palabra(palabra), archivo(n_archivo) {}
// Implementación de la función de operador de llamada
int Hilo::getLineaInicio(){return l_inicio;}
int Hilo::getLineaFin(){return l_fin;}
int Hilo::getId(){return id;}
string Hilo::getPalabra(){return palabra;}
void Hilo::operator() (){
    priority_queue<ResultadoBusqueda> resultados;
    buscar(resultados);
    insertarCola(resultados);
}
void Hilo::buscar(priority_queue<ResultadoBusqueda>& resultados){
    AgenteBuscador ab;
    string linea;
    ifstream archivoStream(archivo); // Open the file
        for(int n_linea = 0; getline(archivoStream,linea); n_linea++){
            if(n_linea >= l_inicio and n_linea <= l_fin){
                vector<string> palabras = ab.separarPorEspacios(linea);
                ab.eliminarCaracteresEspeciales(palabras);
                vector<vector<string>> vectorBusqueda = ab.buscarPalabras(palabras,palabra);
                for(vector<string> palabrasEncontradas : vectorBusqueda){
                    ResultadoBusqueda resultado(palabrasEncontradas[0],palabrasEncontradas[2],n_linea + 1); // Check the constructor of ResultadoBusqueda class
                    resultados.push(resultado);
                }
            }      
        }
    archivoStream.close();
}
void Hilo::insertarCola(priority_queue<ResultadoBusqueda>& resultados){
    semaforo.lock();
    while(!resultados.empty()){
        resultadoBusquedaFinal.push(resultados.top());
        resultados.pop();
    }
    semaforo.unlock();
}
