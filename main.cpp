#include <iostream>
using namespace std;
int main() {
    ListaEnlazada lista;

    lista.agregarEstudiante("Juan", 7.5);
    lista.agregarEstudiante("Maria", 8.0);
    lista.agregarEstudiante("Carlos", 6.8);

    lista.imprimirLista();

    cout << "Promedio de notas: " << lista.calcularPromedioRecursivo()<< endl;

    return 0;
}
