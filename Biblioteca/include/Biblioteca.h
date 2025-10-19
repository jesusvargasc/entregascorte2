#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H


#include "Libro.h"
#include <vector>
#include <string>


class Biblioteca {
private:
std::vector<Libro> libros;


public:

void agregarLibro(const Libro& libro);


bool eliminarLibroPorISBN(const std::string& isbn);


const Libro* buscarPorTitulo(const std::string& titulo) const;



void mostrarLibrosDisponibles() const;
};


#endif 