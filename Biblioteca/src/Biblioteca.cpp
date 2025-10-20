#include "Biblioteca.h"
#include <algorithm>
#include <iostream>


void Biblioteca::agregarLibro(const Libro& libro) {
libros.push_back(libro);
}


bool Biblioteca::eliminarLibroPorISBN(const std::string& isbn) {
auto it = std::find_if(libros.begin(), libros.end(), [&](const Libro& l){
return l.getISBN() == isbn;
});


if (it != libros.end()) {
libros.erase(it);
return true;
}
return false;
}


const Libro* Biblioteca::buscarPorTitulo(const std::string& titulo) const {
auto it = std::find_if(libros.begin(), libros.end(), [&](const Libro& l){
return l.getTitulo() == titulo;
});


if (it != libros.end()) {
return &(*it);
}
return nullptr;
}


void Biblioteca::mostrarLibrosDisponibles() const {
std::cout << "--- Libros disponibles en la biblioteca ---\n";
bool alguno = false;


for (const auto& libro : libros) {
if (libro.isDisponible()) {
libro.mostrarInfo();
alguno = true;
}
}


if (!alguno)
std::cout << "No hay libros disponibles.\n";
}