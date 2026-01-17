#include <iostream>
using namespace std;

//================================================================================= <- para no confundirme
class Estudiante
{
private:
    string nombre;
    float nota;

    friend class ListaEnlazada;

public:
    Estudiante(string nombreEstudiante, float notaEstudiante);
    void imprimir();
};

Estudiante::Estudiante(string nombreEstudiante, float notaEstudiante)
{
    nombre = nombreEstudiante;
    nota = notaEstudiante;
}
void Estudiante::imprimir()
{
    cout << "Nombre del estudiante: " << nombre << "|| nota: " << nota << "\n";
}
//================================================================================= <- para no confundirme
struct nodo
{
    Estudiante *estudiante;
    nodo *siguiente;
};

class ListaEnlazada
{
private:
    nodo *Inicio;

public:
    ListaEnlazada();
    void agregarEstudiante(string nombreEstudiante, float notaEstudiante);
    void imprimirLista(nodo *recursivo);
    void imprimirLista2();
    float calcularPromedioRecursivo();
    int contarEstudiantes(nodo *n);
    float sumarNotas(nodo *n);
    void mostrarPromedio();
};

ListaEnlazada::ListaEnlazada()
{
    Inicio = NULL;
}

void ListaEnlazada::agregarEstudiante(string nombre, float nota)
{
    nodo *nuevo = new nodo;
    nuevo->estudiante = new Estudiante(nombre, nota);
    nuevo->siguiente = Inicio;
    Inicio = nuevo;
}

void ListaEnlazada::imprimirLista(nodo *recursivo)
{
    if (recursivo != NULL)
    {
        recursivo->estudiante->imprimir();
        imprimirLista(recursivo->siguiente);
    }
}

void ListaEnlazada::imprimirLista2()
{
    imprimirLista(Inicio);
}

int ListaEnlazada::contarEstudiantes(nodo *n)
{
    if (n == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + contarEstudiantes(n->siguiente);
    }
}

float ListaEnlazada::sumarNotas(nodo *n)
{
    if (n == nullptr)
    {
        return 0;
    }
    else
    {
        return n->estudiante->nota + sumarNotas(n->siguiente);
    }
}

void ListaEnlazada::mostrarPromedio()
{
    int cantidad = contarEstudiantes(Inicio);
    if (cantidad == 0)
    {
        cout << "No hay estudiantes\n";
        return;
    }

    float suma = sumarNotas(Inicio);
    float promedio = suma / cantidad;
    cout << "Promedio total: " << promedio << "\n";
}

int main()
{
    ListaEnlazada lista;

    lista.agregarEstudiante("Juan", 7.5);
    lista.agregarEstudiante("Maria", 8.1);
    lista.agregarEstudiante("Carlos", 6.8);

    cout << "\n======== Lista de estudiantes ========" << endl;
    lista.imprimirLista2();

    cout << "\n======== Promedio de estudiantes ========" << endl;
    lista.mostrarPromedio();
    cout << "\n";
}