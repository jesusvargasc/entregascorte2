/**
 * @file Estudiante.cpp
 * @brief Implementación de los métodos de la clase Estudiante
 */

#include "Estudiante.h"
#include <sstream>
#include <iomanip>

Estudiante::Estudiante(std::string nombre, int programa, float promedio, int creditosAprobados)
    : nombre(nombre), programa(programa), promedio(promedio), creditosAprobados(creditosAprobados) {
}

void Estudiante::registrarNota(float nota, int creditos) {

    float sumaTotal = (promedio * creditosAprobados) + (nota * creditos);
    creditosAprobados += creditos;
    promedio = sumaTotal / creditosAprobados;
}

void Estudiante::agregarCreditos(int creditos) {
    creditosAprobados += creditos;
}

std::string Estudiante::obtenerResumen() {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "Estudiante: " << nombre << "\n";
    oss << "Programa: " << programa << "\n";
    oss << "Promedio: " << promedio << "\n";
    oss << "Créditos Aprobados: " << creditosAprobados;
    return oss.str();
}

std::string Estudiante::getNombre() const {
    return nombre;
}

float Estudiante::getPromedio() const {
    return promedio;
}

int Estudiante::getCreditosAprobados() const {
    return creditosAprobados;
}

int Estudiante::getPrograma() const {
    return programa;
}
