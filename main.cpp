#include <iostream>
#include <vector>
#include <stdlib.h> //para random
#include <algorithm> //para sort
#include "funciones.h"
#include "busqueda.h"


using namespace std;

template<typename T>
void ImprimirVector(vector<T>arr,int n){
    for(size_t i=0;i<arr.size()&&i<n;i++){
        cout << arr[i]<<", ";
    }
    cout <<endl;
}

template<typename T>
void CompararVectores(vector<T> a, vector<T> b, string message=""){
    cout <<endl<< message << " ";
    //checar si son iguales
    if (a==b){
        cout << "La implementación es correcta!" << endl;
    }
    else{
        cout << "La implementación es incorrecta :(" <<endl;
    }
}

int main()
{
    Funciones<int> F;
    int n;
    int busqueda;
    int num;
    int opciones;
    
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;
    srand(time(0));
    //generar vector random
    vector<int> arrF;
    for (size_t i=0;i<n;i++){
            arrF.push_back((int)rand()%1000);
        }

    //copias del vector que se van a ordenar
    vector<int> arr1(arrF);
    vector<int> arr2(arrF);
    vector<int> arr3(arrF);
    
    //crear linea base usando sort
    sort(arrF.begin(),arrF.end());

    //imprime vector desordenado
    cout<< "Vector desordenado: " << endl;
    ImprimirVector(arrF,n);
    Busqueda<int> b;

    //cantidad de búsquedas
    cout << "¿Cuántas búsquedas desea realizar?: "<<endl;
    cin >> busqueda;
    cout << endl;
    for (int i=0;i<busqueda;i++){
        cout << "¿Qué número desea buscar?: ";
        cin >> num;

        cout << "Con Busqueda Secuencial.El número que busca se encuentra en la posición: " << b.BusquedaSecuencial(arrF,num)<< endl;
        bool val=false;
        while(val==false){
            cout << "¿Qué algoritmo de ordenamiento desea utilizar?"<<endl<<
            "1. Insertion sort" << endl<< "2. Bubble sort" << endl<< "3.Quick sort" << endl;
            cin >> opciones;
            if(opciones>0 && opciones<=3){
                val=true;
            }
        }

        if(opciones==1){
            F.OrdenaInsercion(arr1);
            CompararVectores(arrF,arr1,"Insertion Sort: ");
            ImprimirVector(arr1,n);
            cout << "Con Busqueda Binaria. El número que busca se encuentra en la posición: " << b.BusquedaBinaria(arr1, 0,n,num)<< endl;
        }
        if(opciones==2){
            F.OrdenaBurbuja(arr2);

            CompararVectores(arrF,arr2,"Bubble Sort: ");
            ImprimirVector(arr2,n);
            cout << "Con Busqueda Binaria. El número que busca se encuentra en la posición: " << b.BusquedaBinaria(arr2, 0,n,num)<< endl;
        }

        if(opciones==3){
            F.OrdenaQuick(arr3,0,arr3.size()-1);
            CompararVectores(arrF,arr3,"Quick Sort: ");
            ImprimirVector(arr3,n);
            cout << "Con Busqueda Binaria. El número que busca se encuentra en la posición: " << b.BusquedaBinaria(arr3, 0,n,num)<< endl;
        }

    }
        
}