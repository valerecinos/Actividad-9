#include <iostream>
#include <fstream>

using namespace std;


struct Estudiante {
    int codigo;
    string nombres;
    string apellidos;
    double notas[4];
    double promedio;
    string resultado;
};


void Actualizar(Estudiante* estudiantes, int n) {
    for (int i = 0; i < n; i++) {
        cout << "____ESTUDIANTE____" << i+1 << endl;
        cout << "Codigo: ";
        cin >> estudiantes[i].codigo;
        cout << "Nombres: ";
        cin >> estudiantes[i].nombres;
        cout << "Apellidos: ";
        cin >> estudiantes[i].apellidos;
        for (int j = 0; j < 4; j++) {
            cout << "Nota " << j+1 << ": ";
            cin >> estudiantes[i].notas[j];
        }
        double promedio = 0;
        for (int j = 0; j < 4; j++) {
            promedio += estudiantes[i].notas[j];
        }
        estudiantes[i].promedio = promedio / 4;
        if (estudiantes[i].promedio >= 60) {
            estudiantes[i].resultado = "APROBADO";
        } else {
            estudiantes[i].resultado = "REPROBADO";
        }
    }
}


void Escribir(Estudiante* estudiantes, int n) {
    ofstream archivo("notas.dat", ios::binary);
    if (archivo.is_open()) {
        for (int i = 0; i < n; i++) {
            archivo.write(reinterpret_cast<char*>(&estudiantes[i]), sizeof(Estudiante));
        }
        archivo.close();
        cout << "---Los datos se han almacenado---" << endl;
    } else {
        cout << "***NO SE PUDO ABRIR EL ARCHIVO***" << endl;
    }
}


void Leer() {
    ifstream archivo("notas.dat", ios::binary);
    if (archivo.is_open()) {
        Estudiante estudiante;
        while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
            cout << "Codigo: " << estudiante.codigo << endl;
            cout << "Nombres: " << estudiante.nombres << endl;
            cout << "Apellidos: " << estudiante.apellidos << endl;
            for (int i = 0; i < 4; i++) {
                cout << "Nota " << i+1 << ": " << estudiante.notas[i] << endl;
            }
            cout << "Promedio: " << estudiante.promedio << endl;
            cout << "Resultado: " << estudiante.resultado << endl;
            cout << endl;
        }
        archivo.close();
    } else {
        cout << "***NO SE PUDO ABRIR EL ARCHIVO***" << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    
    Estudiante* estudiantes = new Estudiante[n];

    Actualizar(estudiantes, n);

    Escribir(estudiantes, n);

    Leer();

    
    delete[] estudiantes;

    return 0;
}


