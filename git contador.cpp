#include <iostream>
#include <cmath> // Para la función sqrt() (raíz cuadrada) y pow() (potencia)

using namespace std;

// 1. Estructura para representar un punto en 2D
struct Punto {
    double x;
    double y;
};

// Función auxiliar para calcular la distancia euclidiana entre dos puntos
double calcularDistancia(Punto p1, Punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// 2. Función tipo CodeRunner: Encuentra la distancia al punto más cercano
double calcularDistanciaMasCercana(Punto origen, Punto arregloPuntos[], int cantidad) {
    // Inicializamos la distancia menor con la distancia al primer punto
    double menorDistancia = calcularDistancia(origen, arregloPuntos[0]);

    for (int i = 1; i < cantidad; i++) {
        double distanciaActual = calcularDistancia(origen, arregloPuntos[i]);
        if (distanciaActual < menorDistancia) {
            menorDistancia = distanciaActual;
        }
    }

    return menorDistancia;
}

// 3. Función main() principal
int main() {
    Punto puntoOrigen;
    int n;

    cout << "=== PROGRAMA: PUNTO MAS CERCANO ===" << endl;

    // Solicitar punto de origen al usuario
    cout << "\nIngrese las coordenadas del punto de origen:" << endl;
    cout << "X: ";
    cin >> puntoOrigen.x;
    cout << "Y: ";
    cin >> puntoOrigen.y;

    // Solicitar cantidad de puntos a comparar
    cout << "\n¿Cuantos puntos desea ingresar para comparar?: ";
    cin >> n;

    // Validar que la cantidad sea válida
    if (n <= 0) {
        cout << "Debe ingresar al menos 1 punto." << endl;
        return 1;
    }

    // Construir el arreglo de puntos
    Punto puntos[n];

    cout << "\n--- Ingreso de los puntos ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Punto " << i + 1 << ":" << endl;
        cout << "  X: ";
        cin >> puntos[i].x;
        cout << "  Y: ";
        cin >> puntos[i].y;
    }

    // Llamar a la función implementada
    double distanciaCercana = calcularDistanciaMasCercana(puntoOrigen, puntos, n);

    // Mostrar resultados
    cout << "\n===================================" << endl;
    cout << "La distancia al punto mas cercano es: " << distanciaCercana << endl;
    cout << "===================================" << endl;

    return 0;
}