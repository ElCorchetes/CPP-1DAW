

#include <iostream>
#include <cmath>
using namespace std;

void input(double& a, double& b, double& c);
int calc(double a, double b, double c, double& x1, double& x2);
void out(double x1, double x2, int numSols);

int main()
{
    double a, b, c = 0;
    double x1, x2 = 0;
    input(a, b, c);
    int numSols = calc(a, b, c, x1, x2);
    out(x1, x2, numSols);
}

void out(double x1, double x2, int numSols) {
    switch (numSols) {
    case 0:
        cout << "El discriminante es invalido";
        break;
    case 1:
        cout << "la raiz es 0, solo hay un unico resultado: " << x1;
        break;
    case 2:
        cout << "El resutlado es: " << x1 << "," << x2;
        break;
    default:

        break;
    }
}

int calc(double a, double b, double c, double& x1, double& x2) {

    int disc = (b * b) - (4 * a * c);
    int raiz = (sqrt(disc));

    if (disc < 0) {
        return 0;
    }
    else if (disc == 0) {
        x1 = -b / (2 * a);
        return 1;
    }
    else {
        x1 = (-b + raiz) / (2 * a);
        x2 = (-b - raiz) / (2 * a);
        return 2;
    }
}

void input(double& a, double& b, double& c) {
    cout << "Introduce el valor a: ", cin >> a, cout << "\n";
    cout << "Introduce el valor b: ", cin >> b, cout << "\n";
    cout << "Introduce el valor c: ", cin >> c, cout << "\n";
}