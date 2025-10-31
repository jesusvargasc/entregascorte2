#include <iostream>
#include <string>
#include <vector>
#include <iomanip>  
using namespace std;
class Producto {
public:
    string nombre;
    double precio;
    int stock;
    Producto() {}
    Producto(string n, double p, int s) : nombre(n), precio(p), stock(s) {}
};
class ItemCarrito {
public:
    Producto producto;
    int cantidad;
    ItemCarrito(Producto p, int c) : producto(p), cantidad(c) {}
    double subtotal() const {
        return producto.precio * cantidad;
    }
};
class CarritoCompras {
private:
    vector<ItemCarrito> items;
public:
    void agregarProducto(const Producto& p, int cantidad) {
        items.push_back(ItemCarrito(p, cantidad));
        cout << "Producto agregado al carrito exitosamente.\n";
    }
    void eliminarProducto(const string& nombre) {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].producto.nombre == nombre) {
                items.erase(items.begin() + i);
                cout << "Producto eliminado del carrito.\n";
                return;
            }
        }
        cout << "Producto no encontrado en el carrito.\n";
    }
    void mostrarCarrito() const {
        if (items.empty()) {
            cout << "El carrito está vacío.\n";
            return;
        }
        cout << left << setw(15) << "Producto" 
             << setw(10) << "Precio" 
             << setw(10) << "Cant." 
             << setw(10) << "Subtotal" << endl;
        cout << string(45, '-') << endl;
        for (const auto& item : items) {
            cout << left << setw(15) << item.producto.nombre
                 << setw(10) << fixed << setprecision(2) << item.producto.precio
                 << setw(10) << item.cantidad
                 << setw(10) << fixed << setprecision(2) << item.subtotal()
                 << endl;
        }
        cout << "\nTotal: $" << fixed << setprecision(2) << calcularTotal() << endl;
    }
    double calcularTotal() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.subtotal();
        }
        return total;
    }
    bool vacio() const {
        return items.empty();
    }
    void vaciar() {
        items.clear();
    }
    const vector<ItemCarrito>& obtenerItems() const {
        return items;
    }
};
class Usuario {
public:
    string nombre;
    vector<vector<ItemCarrito>> historial;
    Usuario(string n) : nombre(n) {}
    void guardarCompra(const CarritoCompras& carrito) {
        if (!carrito.vacio()) {
            historial.push_back(carrito.obtenerItems());
            cout << "Compra guardada en el historial.\n";
        } else {
            cout << "No hay productos en el carrito para guardar.\n";
        }
    }
    void mostrarHistorial() const {
        if (historial.empty()) {
            cout << "No hay compras en el historial.\n";
            return;
        }
        cout << "\n=== Historial de Compras de " << nombre << " ===\n";
        for (size_t i = 0; i < historial.size(); ++i) {
            cout << "\nCompra #" << i + 1 << ":\n";
            double total = 0;
            for (const auto& item : historial[i]) {
                cout << " - " << item.producto.nombre << " x" << item.cantidad 
                     << " ($" << item.producto.precio << " c/u)" << endl;
                total += item.subtotal();
            }
            cout << "   Total: $" << total << endl;
        }
    }
};
int main() {
    CarritoCompras carrito;
    string nombreUsuario;
    cout << "Ingrese su nombre: ";
    getline(cin, nombreUsuario);
    Usuario usuario(nombreUsuario);
    int opcion;
    do {
        cout << "\nMENU PRINCIPAL\n";
        cout << "1. Agregar producto al carrito\n";
        cout << "2. Eliminar producto del carrito\n";
        cout << "3. Ver carrito\n";
        cout << "4. Finalizar compra\n";
        cout << "5. Ver historial de compras\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();
        if (opcion == 1) {
            string nombre;
            double precio;
            int stock, cantidad;
            cout << "Nombre del producto: ";
            getline(cin, nombre);
            cout << "Precio: ";
            cin >> precio;
            cout << "Cantidad disponible (stock): ";
            cin >> stock;
            cout << "Cantidad a comprar: ";
            cin >> cantidad;
            Producto p(nombre, precio, stock);
            carrito.agregarProducto(p, cantidad);
        } 
        else if (opcion == 2) {
            string nombre;
            cout << "Ingrese el nombre del producto a eliminar: ";
            getline(cin, nombre);
            carrito.eliminarProducto(nombre);
        } 
        else if (opcion == 3) {
            carrito.mostrarCarrito();
        } 
        else if (opcion == 4) {
            usuario.guardarCompra(carrito);
            carrito.vaciar();
        } 
        else if (opcion == 5) {
            usuario.mostrarHistorial();
        } 
        else if (opcion == 0) {
            cout << "Gracias por usar el programa\n";
        } 
        else {
            cout << "Opción no válida.\n";
        }
    } while (opcion != 0);
    return 0;
}
    


   
