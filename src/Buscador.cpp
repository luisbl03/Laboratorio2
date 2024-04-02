#include "Buscador.hpp"

/*Funcion usada para eliminar los diferentes caraceteres especiales del texto*/
void AgenteBuscador::eliminarCaracteresEspeciales(vector<string>& s){
    string caracteresAEliminar = ",;.:()¿?!\"";
    for(auto& str : s){
        str.erase(remove_if(str.begin(), str.end(), 
        [&caracteresAEliminar](char c) { 
        return caracteresAEliminar.find(c) != std::string::npos; 
        }),
        str.end());
    }
}
/*Funcion para separar por espacios las palabras, devuelve las palabras separadas*/
vector<string> AgenteBuscador::separarPorEspacios(string linea){
    vector<string> palabras;
    istringstream division(linea);
    string l_palabra;
    while(division >> l_palabra)
        palabras.push_back(l_palabra);
    return palabras;
}

/*Funcion para buscar las palabras anterior, posterior y buscada, devuelve los resultados*/
vector<vector<string>> AgenteBuscador::buscarPalabras(vector<string>palabras, string palabra){
    vector<vector<string>> vectorBusqueda;
    for (int i = 0; i < palabras.size(); i++) {
            if (palabras[i].compare(palabra) == 0) {
                vector<string> palabrasEncontradas;
            if (i - 1 >= 0) // Verificar límite izquierdo
                palabrasEncontradas.push_back(palabras[i - 1]);
            else
                palabrasEncontradas.push_back(""); // Otra opción si no hay elemento anterior

            palabrasEncontradas.push_back(palabras[i]);

            if (i + 1 < palabras.size()) // Verificar límite derecho
                palabrasEncontradas.push_back(palabras[i + 1]);
            else
                palabrasEncontradas.push_back(""); // Otra opción si no hay elemento posterior

            vectorBusqueda.push_back(palabrasEncontradas);
        }
    }
    return vectorBusqueda;
}

