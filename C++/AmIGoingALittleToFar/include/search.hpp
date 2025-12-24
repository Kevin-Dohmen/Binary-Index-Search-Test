#pragma once

#include <cstdint>
#include <vector>
#include "index.hpp"

namespace search {

    // Expects an unique ascending ordered vector as input.
    template<typename pT, typename vT>
    IndexValue<pT, vT>* BinarySearchUnique(std::vector<IndexValue<pT, vT>>& toSearch, const vT& target);

    // Expects an unique ascending ordered vector as input.
    template<typename pT, typename vT>
    IndexValue<pT, vT>* InterpolationSearchUnique(std::vector<IndexValue<pT, vT>>& toSearch, vT& target);
} // search
