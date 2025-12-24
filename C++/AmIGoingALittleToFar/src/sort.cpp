#include "sort.hpp"

template<typename pT, typename vT>
void sort::BubbleSortInPlace(std::vector<IndexValue<pT, vT>>& toSort) {
    size_t size = toSort.size();

    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (toSort[j].Value > toSort[j + 1].Value) {
                IndexValue<pT, vT> temp = toSort[j];
                toSort[j] = toSort[j + 1];
                toSort[j + 1] = temp;
            }
        }
    }
}

template void sort::BubbleSortInPlace<uint32_t,int32_t>(std::vector<IndexValue<uint32_t,int32_t>>&);

template<typename pT, typename vT>
void merge(std::vector<IndexValue<pT, vT>>& arr, const size_t left, const size_t mid, const size_t right) {
    const size_t nl = mid - left + 1;
    const size_t nr = right - mid;

    std::vector<IndexValue<pT, vT>> L(nl);
    std::vector<IndexValue<pT, vT>> R(nr);

    // copy
    for (size_t i = 0; i < nl; i++) {
        L[i] = arr[left + i];
    }
    for (size_t j = 0; j < nr; j++) {
        R[j] = arr[mid + j + 1];
    }

    size_t i = 0;
    size_t j = 0;
    size_t k = left;

    // merge
    while (i < nl && j < nr) {
        if (L[i].Value <= R[j].Value) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
        k++;
    }

    // fill remaining
    while (i < nl) {
        arr[k++] = L[i++];
    }
    while (i < nr) {
        arr[k++] = R[j++];
    }
}

template<typename pT, typename vT>
void mergeSort(std::vector<IndexValue<pT, vT>>& arr, const size_t left, const size_t right) {
    if (left < right) {
        const size_t mid = (left + right) / 2;
        mergeSort(arr, left, mid); // merge left
        mergeSort(arr, mid + 1, right); // merge right
        merge(arr, left, mid, right); // merge current
    }
}

template<typename pT, typename vT>
void sort::MergeSortInPlace(std::vector<IndexValue<pT, vT>>& toSort) {
    const size_t len = toSort.size();
    mergeSort(toSort, 0, len - 1);
}

template void sort::MergeSortInPlace<uint32_t, int32_t>(std::vector<IndexValue<uint32_t, int32_t>>& toSort);

template<typename pT, typename vT>
bool sort::CheckSorted(std::vector<IndexValue<pT, vT>>& toSort) {
    for (size_t i = 1; i < toSort.size(); i++) {
        if (toSort[i - 1].Value > toSort[i].Value) {
            return false;
        }
    }
    return true;
}

template bool sort::CheckSorted<uint32_t, int32_t>(std::vector<IndexValue<uint32_t, int32_t>>& toSort);
