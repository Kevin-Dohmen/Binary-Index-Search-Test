#include "sort.h"

void Sort(int* arr, int n) {
    for (int i = 0; i < n; i++){
        int a = arr[i];
        for (int j = i + 1; j < n; j++){
            int b = arr[j];
            if (b > a){
                arr[i] = b;
                arr[j] = a;
                a = b;
            }
        }
    }
}