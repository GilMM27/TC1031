#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// Estructura para almacenar una incidencia
struct Incidencia {
    string mes;
    int dia;
    string hora;
    string ipOrigen;
    string ipDestino;
    string razon;
};

// Leer el archivo y construir la lista de adyacencia
void leerArchivo(const string& nombreArchivo, map<string, set<string> >& listaAdyacencia) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string mes, hora, ipOrigen, razon;
        int dia;
        ss >> mes >> dia >> hora >> ipOrigen;

        // Limpiar el puerto de la IP origen
        string ipOrigenSinPuerto = ipOrigen.substr(0, ipOrigen.find(':'));

        // Leer la razón (resto de la línea)
        getline(ss, razon);

        // Simular IP destino (en este caso, se asume que es derivado del registro)
        string ipDestino = razon.substr(razon.find_last_of(' ') + 1);

        // Agregar la conexión a la lista de adyacencia
        listaAdyacencia[ipOrigenSinPuerto].insert(ipDestino);
    }

    archivo.close();
}

// Calcular el fan-out de cada nodo y determinar el nodo con mayor fan-out
string calcularFanOut(const map<string, set<string> >& listaAdyacencia, map<string, int>& fanOut) {
    int maxFanOut = 0;
    string nodoConMayorFanOut;

    for (const auto& par : listaAdyacencia) {
        int conexionesUnicas = par.second.size();
        fanOut[par.first] = conexionesUnicas;

        if (conexionesUnicas > maxFanOut) {
            maxFanOut = conexionesUnicas;
            nodoConMayorFanOut = par.first;
        }
    }

    return nodoConMayorFanOut;
}

// Mostrar los resultados
void mostrarResultados(const map<string, int>& fanOut, const string& nodoConMayorFanOut) {
    cout << "Fan-out de cada nodo:" << endl;
    for (const auto& par : fanOut) {
        cout << "IP: " << par.first << ", Fan-out: " << par.second << endl;
    }

    cout << "\nNodo con mayor fan-out: " << nodoConMayorFanOut
         << " con " << fanOut.at(nodoConMayorFanOut) << " conexiones unicas." << endl;

    cout << "\nPresumiblemente, el bot master se encuentra en: " << nodoConMayorFanOut << endl;
}

// Función principal
int main() {
    map<string, set<string> > listaAdyacencia; // Lista de adyacencia
    map<string, int> fanOut;                 // Fan-out de cada nodo

    // Leer el archivo y construir la lista de adyacencia
    leerArchivo("./bitacora.txt", listaAdyacencia);

    // Calcular el fan-out y determinar el nodo con mayor fan-out
    string nodoConMayorFanOut = calcularFanOut(listaAdyacencia, fanOut);

    // Mostrar los resultados
    mostrarResultados(fanOut, nodoConMayorFanOut);

    return 0;
}
