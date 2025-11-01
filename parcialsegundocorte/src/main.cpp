/**
 * @file main.cpp
 * @brief Aplicación de gestión académica de estudiantes
 * 
 * Este programa simula un sistema de gestión académica que permite:
 * - Registrar múltiples estudiantes
 * - Actualizar notas y créditos
 * - Consultar resúmenes individuales
 * - Calcular promedio general
 * - Generar reportes en formato .txt
 */

#include "Estudiante.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

/**
 * @brief Muestra el menú principal del sistema
 */
void mostrarMenu() {
    cout << "\n========== SISTEMA DE GESTION ACADEMICA ==========\n";
    cout << "1. Registrar nuevo estudiante\n";
    cout << "2. Registrar nota de estudiante\n";
    cout << "3. Mostrar resumen de un estudiante\n";
    cout << "4. Mostrar todos los estudiantes\n";
    cout << "5. Calcular promedio general\n";
    cout << "6. Verificar requisitos de grado\n";
    cout << "7. Generar reporte TXT\n";
    cout << "0. Salir\n";
    cout << "==================================================\n";
    cout << "Seleccione una opcion: ";
}

/**
 * @brief Calcula el promedio general de todos los estudiantes
 * @param estudiantes Vector de estudiantes registrados
 * @return float Promedio general o 0.0 si no hay estudiantes
 */
float calcularPromedioGeneral(const vector<Estudiante>& estudiantes) {
    if (estudiantes.empty()) return 0.0f;
    
    float suma = 0.0f;
    for (const auto& est : estudiantes) {
        suma += est.getPromedio();
    }
    return suma / estudiantes.size();
}

/**
 * @brief Genera un reporte en archivo de texto con la información de los estudiantes
 * @param estudiantes Vector de estudiantes a incluir en el reporte
 */
void generarReporteTXT(const vector<Estudiante>& estudiantes) {
    ofstream archivo("reporte_estudiantes.txt");
    
    if (!archivo.is_open()) {
        cout << "Error al crear el archivo de reporte.\n";
        return;
    }
    
    archivo << "========================================\n";
    archivo << "    REPORTE ACADEMICO DE ESTUDIANTES\n";
    archivo << "========================================\n\n";
    
    archivo << fixed << setprecision(2);
    
    for (const auto& est : estudiantes) {
        archivo << "Nombre: " << est.getNombre() << "\n";
        archivo << "Promedio: " << est.getPromedio() << "\n";
        archivo << "Creditos Aprobados: " << est.getCreditosAprobados() << "\n";
        archivo << "----------------------------------------\n";
    }
    
    archivo << "\nPromedio General: " << calcularPromedioGeneral(estudiantes) << "\n";
    archivo << "Total de Estudiantes: " << estudiantes.size() << "\n";
    
    archivo.close();
    cout << "\n[EXITO] Reporte generado: reporte_estudiantes.txt\n";
}

/**
 * @brief Función principal del programa
 */
int main() {
    vector<Estudiante> estudiantes;
    int opcion;
    

    estudiantes.push_back(Estudiante("Juan Perez", 2301, 4.2f, 80));
    estudiantes.push_back(Estudiante("Maria Garcia", 2302, 4.5f, 90));
    estudiantes.push_back(Estudiante("Carlos Rodriguez", 2301, 3.8f, 75));
    
    cout << "[INFO] Sistema iniciado con 3 estudiantes precargados.\n";
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1: { 
                string nombre;
                int programa, creditos;
                float promedio;
                
                cout << "\n--- Registrar Nuevo Estudiante ---\n";
                cin.ignore();
                cout << "Nombre: ";
                getline(cin, nombre);
                cout << "Codigo de programa: ";
                cin >> programa;
                cout << "Promedio inicial: ";
                cin >> promedio;
                cout << "Creditos aprobados: ";
                cin >> creditos;
                
                estudiantes.push_back(Estudiante(nombre, programa, promedio, creditos));
                cout << "\n[EXITO] Estudiante registrado correctamente.\n";
                break;
            }
            
            case 2: { 
                if (estudiantes.empty()) {
                    cout << "\n[AVISO] No hay estudiantes registrados.\n";
                    break;
                }
                
                cout << "\n--- Estudiantes Registrados ---\n";
                for (size_t i = 0; i < estudiantes.size(); i++) {
                    cout << i << ". " << estudiantes[i].getNombre() << "\n";
                }
                
                size_t indice;
                float nota;
                int creditos;
                
                cout << "Seleccione estudiante (numero): ";
                cin >> indice;
                
                if (indice >= estudiantes.size()) {
                    cout << "\n[ERROR] Indice invalido.\n";
                    break;
                }
                
                cout << "Nota obtenida (0.0 - 5.0): ";
                cin >> nota;
                cout << "Creditos de la materia: ";
                cin >> creditos;
                
                estudiantes[indice].registrarNota(nota, creditos);
                cout << "\n[EXITO] Nota registrada y promedio actualizado.\n";
                break;
            }
            
            case 3: { 
                if (estudiantes.empty()) {
                    cout << "\n[AVISO] No hay estudiantes registrados.\n";
                    break;
                }
                
                cout << "\n--- Estudiantes Registrados ---\n";
                for (size_t i = 0; i < estudiantes.size(); i++) {
                    cout << i << ". " << estudiantes[i].getNombre() << "\n";
                }
                
                size_t indice;
                cout << "Seleccione estudiante (numero): ";
                cin >> indice;
                
                if (indice >= estudiantes.size()) {
                    cout << "\n[ERROR] Indice invalido.\n";
                    break;
                }
                
                cout << "\n--- Resumen del Estudiante ---\n";
                cout << estudiantes[indice].obtenerResumen() << "\n";
                break;
            }
            
            case 4: { 
                if (estudiantes.empty()) {
                    cout << "\n[AVISO] No hay estudiantes registrados.\n";
                    break;
                }
                
                cout << "\n========== LISTADO DE ESTUDIANTES ==========\n";
                for (size_t i = 0; i < estudiantes.size(); i++) {
                    cout << "\n[" << i << "]\n";
                    cout << estudiantes[i].obtenerResumen() << "\n";
                    cout << "--------------------------------------------\n";
                }
                break;
            }
            
            case 5: { 
                if (estudiantes.empty()) {
                    cout << "\n[AVISO] No hay estudiantes registrados.\n";
                    break;
                }
                
                float promedioGral = calcularPromedioGeneral(estudiantes);
                cout << fixed << setprecision(2);
                cout << "\n--- Estadisticas Generales ---\n";
                cout << "Total de estudiantes: " << estudiantes.size() << "\n";
                cout << "Promedio general: " << promedioGral << "\n";
                break;
            }
            
            case 6: { 
                if (estudiantes.empty()) {
                    cout << "\n[AVISO] No hay estudiantes registrados.\n";
                    break;
                }
                
                int creditosRequeridos;
                cout << "\nCreditos requeridos para graduacion: ";
                cin >> creditosRequeridos;
                
                cout << "\n--- Estudiantes Aptos para Graduacion ---\n";
                int aptos = 0;
                for (const auto& est : estudiantes) {
                    if (est.cumpleRequisitosGrado(creditosRequeridos)) {
                        cout << "✓ " << est.getNombre() 
                             << " (" << est.getCreditosAprobados() << " creditos)\n";
                        aptos++;
                    }
                }
                
                if (aptos == 0) {
                    cout << "Ningun estudiante cumple con los requisitos.\n";
                } else {
                    cout << "\nTotal aptos: " << aptos << " de " << estudiantes.size() << "\n";
                }
                break;
            }
            
            case 7: { 
                if (estudiantes.empty()) {
                    cout << "\n[AVISO] No hay estudiantes registrados.\n";
                    break;
                }
                
                generarReporteTXT(estudiantes);
                break;
            }
            
            case 0:
                cout << "\n[INFO] Saliendo del sistema...\n";
                break;
                
            default:
                cout << "\n[ERROR] Opcion invalida. Intente nuevamente.\n";
        }
        
    } while (opcion != 0);
    
    cout << "\nGracias por usar el Sistema de Gestion Academica.\n";
    return 0;
}