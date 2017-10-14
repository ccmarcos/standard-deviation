#include <iostream> //para funciones principales como imprimir
#include <fstream> //para el manejo de archivos
#include <math.h> //para funciones matematicas
#include <stdlib.h> //para exit()
using namespace std;

int main() {
    int sum=0,contador=0, contador2=0, x;
    int *array = new int[contador];
    float suma2 = 0, media, varianza, desviacion_estandar;

    ifstream inFile;

    inFile.open("ejemplo.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (inFile >> x) {
        contador++;
    }

    inFile.close();

    inFile.open("ejemplo.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (inFile >> x) {
        array[contador2] = x;
        contador2++;
    }

    inFile.close();

    for(int i=0; i<contador; i++)
        sum = sum + array[i];
    media = (float)sum/contador;

    for(int i=0; i<contador; i++)
        suma2 += (float)pow(array[i]-media,2);

    varianza = suma2/(contador-1);
    desviacion_estandar = sqrt(varianza);

    printf("media = %.4f\n", media);
    printf("desviacion estandar = %.4f\n", desviacion_estandar);

    delete [] array;
    return 0;
}
