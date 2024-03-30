#include "Buscador.hpp"
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
vector<string> AgenteBuscador::separarPorEspacios(string linea){
    vector<string> palabras;
    istringstream division(linea);
    string l_palabra;
    while(division >> l_palabra)
        palabras.push_back(l_palabra);
    return palabras;
}
vector<vector<string>> AgenteBuscador::buscarPalabras(vector<string>palabras, string palabra){
    vector<vector<string>> vectorBusqueda;
    for(int i=0; i < palabras.size();i++){
        vector<string> palabrasEncontradas;
        string palabraVector = palabras[i];
        if(palabraVector == palabra){
            if((i-1) == -1)
                palabrasEncontradas.push_back(NULL);
            else
                palabrasEncontradas.push_back(palabras[i-1]);

            palabrasEncontradas.push_back(palabras[i]);

            if((i+1) == palabrasEncontradas.size())
                palabrasEncontradas.push_back(NULL);
            else
                palabrasEncontradas.push_back(palabras[i+1]);
            vectorBusqueda.push_back(palabrasEncontradas);
        }
    }
            return vectorBusqueda;
}