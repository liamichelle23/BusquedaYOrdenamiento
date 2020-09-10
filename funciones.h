#ifndef funciones_h
#define funciones_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

template<typename T>
class Funciones
{
    public:
    void Intercambiar(int i, int j, vector<T>&arr){
        T aux=arr[i];
        arr[i]=arr[j];
        arr[j]=aux;
    }
    void OrdenaInsercion(vector<T>&arr){
        T llave; //número que se está moviendo
        for(size_t i=1;i<arr.size();i++){
            llave=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>llave){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=llave;
        }
    };
    void OrdenaBurbuja(vector<T>&arr){
        for (size_t i=0;i<arr.size();i++){
            bool noSwap=true;
            for(size_t j=0;j<arr.size()-i-1;j++){
                if(arr[j]>arr[j+1]){
                    Intercambiar(j,j+1,arr);
                    noSwap=false;
                }
            }
            if(noSwap){break;}
        }
    };
    void OrdenaQuick(vector<T>&arr, int low, int high){
        if(low<high){
            int pi=Partition(arr,low,high);
            OrdenaQuick(arr,low,pi-1);
            OrdenaQuick(arr,pi+1,high);
        }
    }

    int Partition(vector<T> &arr, int low, int high){
        T pivot=arr[high];
        int i=(low-1);
        for(int j=low;j<=high-1;j++){
            if(arr[j]<pivot){
                i++;
                Intercambiar(i,j,arr);
            }
        }
        Intercambiar(i+1,high,arr);
        return (i+1);
    }
    
};
#endif