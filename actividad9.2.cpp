#include <iostream>
using namespace std;

struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    float nota1, nota2, nota3, nota4, promedio;
};

void Promedio(Estudiante *est) {
    est->promedio = (est->nota1 + est->nota2 + est->nota3 + est->nota4) / 4.0;
}

void Estado(Estudiante *est) {
    if (est->promedio >= 60) {
        cout << "El estudiante " << est->nombres << " " << est->apellidos << " APROBADO " << endl;
    } else {
        cout << "El estudiante " << est->nombres << " " << est->apellidos << " REPROBADO " << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de estudiantes: ";
    cin >> n;

    Estudiante *estudiantes = new Estudiante[n];

    for (int i = 0; i < n; i++) {
        cout << "---------ESTUDIANTE------------" << i+1 << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "Nombres: ";
        cin >> estudiantes[i].nombres;
        cout << "Apellidos: ";
        cin >> estudiantes[i].apellidos;
        cout << "Nota 1: ";
        cin >> estudiantes[i].nota1;
        cout << "Nota 2: ";
        cin >> estudiantes[i].nota2;
        cout << "Nota 3: ";
        cin >> estudiantes[i].nota3;
        cout << "Nota 4: ";
        cin >> estudiantes[i].nota4;

        Promedio(&estudiantes[i]);
        Estado(&estudiantes[i]);
    }

    delete[] estudiantes;
    return 0;
}

