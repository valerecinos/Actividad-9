#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    
    
    int ids[n];
    string nombres[n];
    string apellidos[n];
    float notas[4][n];
    
    
    for (int i = 0; i < n; i++) {
        cout << "-------ESTUDIANTE----------" << i+1 << endl;
        cout << "ID: ";
        cin >> ids[i];
        cout << "Nombres: ";
        cin.ignore();
        getline(cin, nombres[i]);
        cout << "Apellidos: ";
        getline(cin, apellidos[i]);
        
        
        float promedio = 0;
        for (int j = 0; j < 4; j++) {
            cout << "Nota " << j+1 << ": ";
            cin >> notas[j][i];
            promedio += notas[j][i];
        }
        promedio /= 4;
        
        
        string clase = (promedio >= 60) ? "APROBADO" : "REPROBADO";
        
    
        cout << "Codigo: " << ids[i] << endl;
        cout << "Nombres: " << nombres[i] << endl;
        cout << "Apellidos: " << apellidos[i] << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "ESTADO DE LA CLASE:  " << clase  << endl;
    }
    
    return 0;
}

