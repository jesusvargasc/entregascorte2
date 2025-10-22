#include <iostream>
#include <limits>
#include "Biblioteca.h"
#include "Libro.h"
using namespace std;

void mostrarMenu() {
    cout << "\n===== MENU BIBLIOTECA =====\n";
    cout << "1. Agregar libro\n";
    cout << "2. Eliminar libro\n";
    cout << "3. Buscar libro por titulo\n";
    cout << "4. Mostrar todos los libros\n";
    cout << "5. Salir\n";
    cout << "===========================\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    Biblioteca miBiblioteca;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
        case 1: {
            string titulo, autor, isbn;
            cout << "\nIngrese el titulo del libro: ";
            getline(cin, titulo);
            cout << "Ingrese el autor del libro: ";
            getline(cin, autor);
            cout << "Ingrese el ISBN del libro: ";
            getline(cin, isbn);

            Libro nuevo(titulo, autor, isbn);
            miBiblioteca.agregarLibro(nuevo);
            break;
        }

        case 2: {
            string isbn;
            cout << "\nIngrese el ISBN del libro a eliminar: ";
            getline(cin, isbn);
            miBiblioteca.eliminarLibro(isbn);
            break;
        }

        case 3: {
            string titulo;
            cout << "\nIngrese el titulo a buscar: ";
            getline(cin, titulo);
            miBiblioteca.buscarPorTitulo(titulo);
            break;
        }

        case 4:
            miBiblioteca.mostrarLibros();
            break;

        case 5:
            cout << "\nSaliendo del programa... ¡Hasta luego!\n";
            break;

        default:
            cout << "\nOpcion no valida. Intente de nuevo.\n";
            break;
        }

    } while (opcion != 5);

    return 0;
}
