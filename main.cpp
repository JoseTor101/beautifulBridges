#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
long long h, a, b;
vector<long long> x, y;

int main() {
    // #puntos, altura deseada, factores costo
    cin >> n >> h >> a >> b;

    // Perfil piso (puntos)
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Izquierda y derecha máxima a la que podemos ir
    vector<long long> maxDistDer(n, 0), maxDistIzq(n, 0);
    for (int i = 0; i < n; i++) {
        maxDistDer[i] = 2 * (h - y[i]);
        maxDistIzq[i] = 2 * (h - y[i]);
    }

    //Recorremos los pares
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            // Valores para armar el arco
            long long arcoX = abs(x[i] - x[j]);
            long long arcoY = h - y[j];

            // Distancias máximas izquierda y derecha desde i
            long long mover = static_cast<long long>(2 * (arcoX + arcoY + sqrt(2 * arcoX * arcoY)) + 1e-9);

            // Actualizamos el lado
            if (i < j)
                maxDistDer[i] = min(maxDistDer[i], mover);
            else
                maxDistIzq[i] = min(maxDistIzq[i], mover);
        }
    }

    vector<long long> distanciaPuente(n, numeric_limits<long long>::max());
    distanciaPuente[0] = 0;

    // i+1 es la columna derecha a partir de la cual vamos a empezar a construir
    for (int i = 1; i < n; i++) {
        //Construimos un arco de 0 a j, luego uno solo de j a i+1
        for (int j = i - 1; j >= 0; j--) {
            //j evita que construyamos arco de j a i
            if (x[j] + maxDistDer[j] < x[i]) continue;
            //Hemos llegado tan lejos que no podemos salir
            if (x[i] - maxDistIzq[i] > x[j]) break;
            // No hay construccion posible
            if (distanciaPuente[j] == numeric_limits<long long>::max()) continue;

            // Mejor respuesta obtenida
            long long valorActualizado = distanciaPuente[j] + a * (h - y[i]) + b * (x[i] - x[j]) * (x[i] - x[j]);

            // Actualizamos en caso de que la anterior no fuera la menor
            distanciaPuente[i] = min(distanciaPuente[i], valorActualizado);
        }
    }

    if (distanciaPuente[n - 1] == numeric_limits<long long>::max())
        cout << "impossible" << endl;
    else
        cout << distanciaPuente[n - 1] + a * (h - y[0]) << endl;

    return 0;
}
