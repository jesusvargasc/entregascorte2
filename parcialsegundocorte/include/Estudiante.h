/**
 * @file Estudiante.h
 * @brief Definición de la clase Estudiante para la gestión de información académica
 * @author Sistema de Gestión Académica
 * @date 2025
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

/**
 * @class Estudiante
 * @brief Clase que representa un estudiante universitario con su información académica
 * 
 * Esta clase permite gestionar la información básica de un estudiante incluyendo
 * su nombre, programa académico, promedio ponderado y créditos aprobados.
 */
class Estudiante {
private:
    std::string nombre;           ///< Nombre completo del estudiante
    int programa;                 ///< Código del programa académico
    float promedio;               ///< Promedio ponderado acumulado
    int creditosAprobados;        ///< Total de créditos aprobados

public:
    /**
     * @brief Constructor parametrizado de la clase Estudiante
     * @param nombre Nombre completo del estudiante
     * @param programa Código del programa académico
     * @param promedio Promedio inicial del estudiante
     * @param creditosAprobados Créditos iniciales aprobados
     */
    Estudiante(std::string nombre, int programa, float promedio, int creditosAprobados);

    /**
     * @brief Registra una nueva nota y actualiza el promedio ponderado
     * @param nota Calificación obtenida en la materia (0.0 - 5.0)
     * @param creditos Número de créditos de la materia cursada
     * 
     * Este método actualiza el promedio ponderado considerando los créditos
     * previamente aprobados y los nuevos créditos de la materia.
     */
    void registrarNota(float nota, int creditos);

    /**
     * @brief Incrementa el número total de créditos aprobados
     * @param creditos Cantidad de créditos a agregar
     */
    void agregarCreditos(int creditos);

    /**
     * @brief Genera un resumen con la información del estudiante
     * @return std::string Cadena con nombre, programa, promedio y créditos
     * 
     * Devuelve una descripción formateada con todos los datos relevantes
     * del estudiante para visualización o reportes.
     */
    std::string obtenerResumen();

    /**
     * @brief Verifica si el estudiante cumple con los requisitos para graduarse
     * @param creditosRequeridos Número mínimo de créditos necesarios para el grado
     * @return true si el estudiante ha aprobado suficientes créditos, false en caso contrario
     * 
     * IMPLEMENTACIÓN:
     * Este método compara los créditos aprobados del estudiante con los créditos
     * requeridos para determinar si cumple con los requisitos de graduación.
     */
    bool cumpleRequisitosGrado(int creditosRequeridos) {
        return creditosAprobados >= creditosRequeridos;
    }

    /**
     * @brief Obtiene el nombre del estudiante
     * @return std::string Nombre del estudiante
     */
    std::string getNombre() const;

    /**
     * @brief Obtiene el promedio del estudiante
     * @return float Promedio ponderado actual
     */
    float getPromedio() const;

    /**
     * @brief Obtiene los créditos aprobados del estudiante
     * @return int Total de créditos aprobados
     */
    int getCreditosAprobados() const;

    /**
     * @brief Obtiene el código del programa académico
     * @return int Código del programa
     */
    int getPrograma() const;
};

#endif // ESTUDIANTE_H