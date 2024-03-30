#include "Hilo.hpp"
Hilo::Hilo(int id, int l_inicio, int l_fin, string palabra, string n_archivo) : 
    id(id), l_inicio(l_inicio), l_fin(l_fin), palabra(palabra), archivo(n_archivo) {}
// Implementación de la función de operador de llamada
void Hilo::operator()() const {
    queue<ResultadoBusqueda> resultados;
    AgenteBuscador ab;
    string linea;
    ifstream archivoStream(archivo); // Open the file
        for(int n_linea = 0; getline(archivoStream,linea); n_linea++){
            if(n_linea >= l_inicio and n_linea <= l_fin){
                vector<string> palabras = ab.separarPorEspacios(linea);
                cout << "Palabras separadas y ahora eliminar los caracteres especiales\n" << endl;
                ab.eliminarCaracteresEspeciales(palabras);
                cout << "Caracteres especiales eliminados\n" << endl;
                vector<vector<string>> vectorBusqueda = ab.buscarPalabras(palabras,palabra);
                cout << "Palabras encontradas\n" << endl;
                for(vector<string> palabrasEncontradas : vectorBusqueda){
                    ResultadoBusqueda resultado(palabrasEncontradas[0],palabrasEncontradas[1],n_linea); // Check the constructor of ResultadoBusqueda class
                    resultados.push(resultado);
                }
            }      
        }
}


    

