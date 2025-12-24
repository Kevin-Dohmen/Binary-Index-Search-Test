#include "search.hpp"

template<typename pT, typename vT>
IndexValue<pT, vT>* search::BinarySearchUnique(std::vector<IndexValue<pT, vT>>& toSearch, const vT& target) {
    size_t len = toSearch.size();
    size_t lowerIdx = 0;
    size_t upperIdx = len;

    while (lowerIdx != upperIdx) {
        size_t middleIdx = lowerIdx + (upperIdx - lowerIdx) / 2;
        IndexValue<pT, vT>& middleIdxRow = toSearch[middleIdx];
        vT middleValue = middleIdxRow.Value;

        if (middleValue == target) {
            return &middleIdxRow; // return address of element (not address of local)
        }

        if (middleValue < target) {
            lowerIdx = middleIdx + 1;
        } else {
            upperIdx = middleIdx;
        }
    }

    return nullptr;
}

// Explicit instantiation for the types you use (prevents undefined references)
template IndexValue<uint32_t,int32_t>* search::BinarySearchUnique<uint32_t,int32_t>(std::vector<IndexValue<uint32_t,int32_t>>&, const int32_t&);
