#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Buscador{
    private:
        string nombreFichero;
        string palabra;
        int l_inicio;
        int l_fin;
        void eliminarCaracteresEspeciales(vector<string>& s){
            string caracteresAEliminar = ',;.:()¿?!"´';
            for(int i=; i<s.size(); i++){
                s.erase(remove_if(s.begin(), s.end(), 
                [&caracteresAEliminar](char c) { 
                return caracteresAEliminar.find(c) != std::string::npos; 
                }),
                s.end());
            } 
}