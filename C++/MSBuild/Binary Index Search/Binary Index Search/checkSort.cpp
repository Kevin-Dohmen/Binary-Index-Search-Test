#include "checkSort.hpp"

bool CheckIsSorted(int* arr, int n) {
    bool isSorted = true;
    int prev = arr[0];

    for (int i = 0; i < n && isSorted; i++) {
        int curr = arr[i];

        if (curr > prev) {
            isSorted = false;
        }

        prev = curr;
    }

    return isSorted;
}
