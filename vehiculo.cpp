#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Vehiculo {
protected:
    string marca;
    string modelo;
    string placa;
    bool disponible;

public:
    Vehiculo(string m, string mo, string p)
        : marca(m), modelo(mo), placa(p), disponible(true) {}

    virtual ~Vehiculo() {}

    bool estaDisponible() const { return disponible; }

    void alquilar() { disponible = false; }
    void devolver() { disponible = true; }

    string getPlaca() const { return placa; }

   
    virtual void mostrarInformacion() const {
        cout << "Marca: " << marca << "\nModelo: " << modelo
             << "\nPlaca: " << placa << "\nDisponible: "
             << (disponible ? "Sí" : "No") << endl;
    }
};

class Auto : public Vehiculo {
private:
    int capacidadPasajeros;

public:
    Auto(string m, string mo, string p, int cap)
        : Vehiculo(m, mo, p), capacidadPasajeros(cap) {}

    void mostrarInformacion() const override {
        cout << "AUTO\n";
        Vehiculo::mostrarInformacion();
        cout << "Capacidad de pasajeros: " << capacidadPasajeros << "\n\n";
    }
};

class Bicicleta : public Vehiculo {
private:
    bool tieneCanasta;

public:
    Bicicleta(string m, string mo, string p, bool canasta)
        : Vehiculo(m, mo, p), tieneCanasta(canasta) {}

    void mostrarInformacion() const override {
        cout << "BICICLETA\n";
        Vehiculo::mostrarInformacion();
        cout << "Tiene canasta: " << (tieneCanasta ? "Sí" : "No") << "\n\n";
    }
};


class SistemaAlquiler {
private:
    vector<Vehiculo*> vehiculos;

public:
    void registrarVehiculo(Vehiculo* v) {
        vehiculos.push_back(v);
        cout << "Vehículo registrado correctamente.\n";
    }

    void mostrarDisponibles() const {
        cout << "\n--- Vehículos Disponibles ---\n";
        for (auto v : vehiculos) {
            if (v->estaDisponible())
                v->mostrarInformacion();
        }
    }

    void alquilarVehiculo(string placa) {
        for (auto v : vehiculos) {
            if (v->getPlaca() == placa) {
                if (v->estaDisponible()) {
                    v->alquilar();
                    cout << "Vehículo " << placa << " alquilado exitosamente.\n";
                } else {
                    cout << "El vehículo ya está alquilado.\n";
                }
                return;
            }
        }
        cout << "No se encontró un vehículo con esa placa.\n";
    }

    void devolverVehiculo(string placa) {
        for (auto v : vehiculos) {
            if (v->getPlaca() == placa) {
                if (!v->estaDisponible()) {
                    v->devolver();
                    cout << "Vehículo devuelto correctamente.\n";
                } else {
                    cout << "El vehículo ya estaba disponible.\n";
                }
                return;
            }
        }
        cout << "No se encontró un vehículo con esa placa.\n";
    }
};


int main() {
    SistemaAlquiler sistema;
    int opcion;

    do {
        cout << "\n===== SISTEMA DE ALQUILER DE VEHÍCULOS =====\n";
        cout << "1. Registrar vehículo\n";
        cout << "2. Mostrar vehículos disponibles\n";
        cout << "3. Alquilar vehículo\n";
        cout << "4. Devolver vehículo\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int tipo;
            cout << "¿Qué tipo de vehículo desea registrar?\n1. Auto\n2. Bicicleta\nOpción: ";
            cin >> tipo;

            string marca, modelo, placa;
            cout << "Marca: "; cin >> marca;
            cout << "Modelo: "; cin >> modelo;
            cout << "Placa: "; cin >> placa;

            if (tipo == 1) {
                int capacidad;
                cout << "Capacidad de pasajeros: ";
                cin >> capacidad;
                sistema.registrarVehiculo(new Auto(marca, modelo, placa, capacidad));
            } else if (tipo == 2) {
                int canasta;
                cout << "¿Tiene canasta? (1 = Sí, 0 = No): ";
                cin >> canasta;
                sistema.registrarVehiculo(new Bicicleta(marca, modelo, placa, canasta));
            } else {
                cout << "Tipo inválido.\n";
            }
            break;
        }

        case 2:
            sistema.mostrarDisponibles();
            break;

        case 3: {
            string placa;
            cout << "Ingrese la placa del vehículo a alquilar: ";
            cin >> placa;
            sistema.alquilarVehiculo(placa);
            break;
        }

        case 4: {
            string placa;
            cout << "Ingrese la placa del vehículo a devolver: ";
            cin >> placa;
            sistema.devolverVehiculo(placa);
            break;
        }

        case 0:
            cout << " Saliendo del sistema...\n";
            break;

        default:
            cout << "Opción inválida.\n";
        }

    } while (opcion != 0);

    return 0;
}
