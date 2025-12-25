#include "search.hpp"

#include <iostream>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//                     Binary
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

template<typename pT, typename vT>
size_t search::BinarySearchIndex(std::vector<IndexValue<pT, vT>>& toSearch, const vT target) {
    size_t len = toSearch.size();
    size_t low = 0;
    size_t high = len;

    while (low <= high) {
        size_t probeIdx = (low + high) / 2;
        vT probeValue = toSearch[probeIdx].Value;

        if (probeValue == target) {
            return probeIdx;
        }

        if (probeValue < target) {
            low = probeIdx + 1;
        } else {
            high = probeIdx - 1;
        }
    }

    return SIZE_MAX;
}

template<typename pT, typename vT>
IndexValue<pT, vT>* search::BinarySearchUnique(std::vector<IndexValue<pT, vT>>& toSearch, const vT target) {
    size_t index = BinarySearchIndex(toSearch, target);
    if (index == SIZE_MAX)
        return nullptr;
    return &toSearch[index];
}
template IndexValue<uint32_t,int32_t>* search::BinarySearchUnique(std::vector<IndexValue<uint32_t,int32_t>>&, const int32_t);

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//                     Interpolation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

template<typename pT, typename vT>
size_t search::InterpolationSearchIndex(std::vector<IndexValue<pT, vT>>& toSearch, const vT target) {
    size_t len = toSearch.size();
    size_t low = 0;
    size_t high = len - 1;

    vT lowerValue = toSearch[low].Value;
    vT upperValue = toSearch[high].Value;

    while (low <= high) {

        // detect pool
        if (lowerValue == upperValue) {
            if (lowerValue == target) {
                return low; // all match
            } else {
                return SIZE_MAX; // won't find it here
            }
        }

        double ratio = static_cast<double>(target - lowerValue) / (upperValue - lowerValue);
        size_t probeOffset = static_cast<size_t>((high - low) * ratio);
        size_t probeIdx = low + probeOffset;
        const vT probeValue = toSearch[probeIdx].Value;

        if (probeValue == target) {
            return probeIdx;
        }

        if (probeValue < target) {
            low = probeIdx + 1;
            lowerValue = toSearch[low].Value;
        } else {
            high = probeIdx - 1;
            upperValue = toSearch[high].Value;
        }
    }

    return SIZE_MAX;
}

template<typename pT, typename vT>
IndexValue<pT, vT>* search::InterpolationSearchUnique(std::vector<IndexValue<pT, vT>>& toSearch, const vT target) {
    size_t index = InterpolationSearchIndex(toSearch, target);
    if (index == SIZE_MAX)
        return nullptr;
    return &toSearch[index];
}

template IndexValue<uint32_t, int32_t>* search::InterpolationSearchUnique(std::vector<IndexValue<uint32_t, int32_t>>& toSearch, const int32_t target);
