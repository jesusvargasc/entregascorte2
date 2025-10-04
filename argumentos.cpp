#include <iostream>
#include <string>
#include <stdexcept> 
using namespace std;
float sumar(float a, float b) { return a + b; }
float restar(float a, float b) { return a - b; }
float multiplicar(float a, float b) { return a * b; }
float dividir(float a, float b) { 
    if (b == 0) {
        throw runtime_error("Error: División entre cero");
    }
    return a / b; 
}

void realizarOperacion(float (*operacion)(float, float), float numero1, float numero2) {
    cout << "Resultado: " << operacion(numero1, numero2) << endl;
}

int main(int argc, char* argv[]) {

    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <numero1> <operador> <numero2>\n";
        return 1;
    }

    try {

        float numero1 = stof(argv[1]);
        string operador = argv[2];
        float numero2 = stof(argv[3]);

    
        float (*operacion)(float, float) = nullptr;

    
        if (operador == "+") {
            operacion = sumar;
        } else if (operador == "-") {
            operacion = restar;
        } else if (operador == "*" || operador == "x" || operador == "X") {
            operacion = multiplicar;
        } else if (operador == "/") {
            operacion = dividir;
        } else {
            cerr << "Error: Operador no válido. Use +, -, *, x o /.\n";
            return 1;
        }

        
        realizarOperacion(operacion, numero1, numero2);
    }
    catch (const invalid_argument& e) {
        cerr << "Error: Argumento no numérico detectado.\n";
        return 1;
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl; 
        return 1;
    }
    catch (...) {
        cerr << "Error desconocido.\n";
        return 1;
    }

    return 0;
}

