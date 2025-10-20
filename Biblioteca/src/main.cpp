#include "Biblioteca.h"
#include "Libro.h"
#include <iostream>


int main() {
Biblioteca b;



Libro l1("Cien Años de Soledad", "Gabriel García Márquez", "978-84-376-0494-7");
Libro l2("Don Quijote de la Mancha", "Miguel de Cervantes", "978-84-376-0495-4");
Libro l3("El Aleph", "Jorge Luis Borges", "978-84-376-0496-1");


b.agregarLibro(l1);
b.agregarLibro(l2);
b.agregarLibro(l3);



b.mostrarLibrosDisponibles();



std::cout << "\nBuscando 'El Aleph'...\n";
const Libro* encontrado = b.buscarPorTitulo("El Aleph");
if (encontrado)
encontrado->mostrarInfo();
else
std::cout << "Libro no encontrado.\n";

std::cout << "\nEliminando libro con ISBN 978-84-376-0495-4...\n";
if (b.eliminarLibroPorISBN("978-84-376-0495-4")) {
std::cout << "Libro eliminado correctamente.\n";
} else {
std::cout << "No se encontró el libro.\n";
}



std::cout << "\nDespués de eliminar:\n";
b.mostrarLibrosDisponibles();


return 0;
}