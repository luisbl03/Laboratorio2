#include "Hilo.hpp"
#include "Resultado_busqueda.hpp"
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
                vector<string> palabras = ab.separarPorEspacios(linea);
                ab.eliminarCaracteresEspeciales(palabras);
                vector<vector<string>> vectorBusqueda = ab.buscarPalabras(palabras,palabra);
                for(vector<string> palabrasEncontradas : vectorBusqueda){
                    ResultadoBusqueda resultado(id,palabrasEncontradas[0],palabrasEncontradas[2],n_linea + 1); // Check the constructor of ResultadoBusqueda class
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
void Hilo::mostrarResultadosHilo(string palabra){
    while(!busquedaFinal.empty()){
        ResultadoBusqueda resultado = busquedaFinal.front();
        cout << " :: línea " << resultado.getLinea() << " :: ... " << resultado.getPalabraAnterior() << " " << palabra << " " << resultado.getPalabraPosterior() << " ..." << endl;
    }
}

    

