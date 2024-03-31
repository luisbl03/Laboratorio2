#include "Buscador.hpp"
#include <mutex>
#include "Hilo.hpp"
#include "Resultado_busqueda.hpp"

mutex Hilo::semaforo;
queue<ResultadoBusqueda> Hilo::busquedaFinal;
Hilo::Hilo(int id, int l_inicio, int l_fin, string palabra, string n_archivo) : 
    id(id), l_inicio(l_inicio), l_fin(l_fin), palabra(palabra), archivo(n_archivo) {}
// Implementación de la función de operador de llamada
void Hilo::operator()() const {
    priority_queue<ResultadoBusqueda> resultados;
    AgenteBuscador ab;
    string linea;
    ifstream archivoStream(archivo); // Open the file
        for(int n_linea = 0; getline(archivoStream,linea); n_linea++){
            if(n_linea >= l_inicio and n_linea <= l_fin){
                cout << "separar" << endl;
                vector<string> palabras = ab.separarPorEspacios(linea);
                cout << "eliminar" << endl;
                ab.eliminarCaracteresEspeciales(palabras);
                cout << "buscar" << endl;
                vector<vector<string>> vectorBusqueda = ab.buscarPalabras(palabras,palabra);
                for(vector<string> palabrasEncontradas : vectorBusqueda){
                    ResultadoBusqueda resultado(palabrasEncontradas[0],palabrasEncontradas[2],n_linea + 1); // Check the constructor of ResultadoBusqueda class
                    resultados.push(resultado);
                }
            }      
        }
    semaforo.lock();
    while(!resultados.empty()){
        busquedaFinal.push(resultados.top());
        resultados.pop();
    }
    semaforo.unlock();
    archivoStream.close(); // Close the file
}
void Hilo::mostrarResultados(vector<Hilo> hilos){
    while(!busquedaFinal.empty()){
         /*vamos recorriendo el vector de hilos, obteniendo su informacion*/
         for (Hilo hilo : hilos) {
            ResultadoBusqueda resultado = busquedaFinal.front();
            while ((resultado.getLinea() >= hilo.l_inicio) and (resultado.getLinea() <= hilo.l_fin)) {
                cout << "[Hilo " << hilo.id << " inicio:" << hilo.l_inicio << " fin:" << hilo.l_fin << "] ";
                cout << " :: línea " << resultado.getLinea() << " :: ";
                cout << "..." << resultado.getPalabraAnterior() << hilo.palabra << resultado.getPalabraPosterior() << "..." << endl;
            }
            busquedaFinal.pop();
         }
    }
}

    

