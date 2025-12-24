#pragma once

#include <cstdint>
#include <vector>
#include "index.hpp"

namespace sort {
    template<typename pT, typename vT>
    void BubbleSortInPlace(std::vector<IndexValue<pT, vT>>&);

    template<typename pT, typename vT>
    void MergeSortInPlace(std::vector<IndexValue<pT, vT>>& toSort);

    template<typename pT, typename vT>
    bool CheckSorted(std::vector<IndexValue<pT, vT>>& toSort);
} // sort
