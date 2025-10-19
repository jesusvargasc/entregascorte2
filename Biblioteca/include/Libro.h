#ifndef LIBRO_H
#define LIBRO_H


#include <string>


class Libro {
private:
std::string titulo;
std::string autor;
std::string isbn;
bool disponible;


public:
Libro(const std::string& titulo, const std::string& autor, const std::string& isbn, bool disponible = true);


const std::string& getTitulo() const;
const std::string& getAutor() const;
const std::string& getISBN() const;
bool isDisponible() const;


void setDisponible(bool d);


void mostrarInfo() const;
};


#endif 