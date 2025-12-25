#pragma once

#include <cstdint>
#include <vector>
#include "index.hpp"

namespace search {

    /// @param toSearch Ascending ordered index vector.
    /// @param target The target value to search for.
    /// @return Index of found item or SIZE_MAX if not found.
    template<typename pT, typename vT>
    size_t BinarySearchIndex(std::vector<IndexValue<pT, vT>>& toSearch, const vT target);

    /// @param toSearch Ascending ordered index vector.
    /// @param target The target value to search for.
    /// @return The found item. or nullptr if none are found.
    template<typename pT, typename vT>
    IndexValue<pT, vT>* BinarySearchUnique(std::vector<IndexValue<pT, vT>>& toSearch, const vT target);

    /// @param toSearch Ascending ordered index vector.
    /// @param target The target value to search for.
    /// @return Index of found item or SIZE_MAX if not found.
    template<typename pT, typename vT>
    size_t InterpolationSearchIndex(std::vector<IndexValue<pT, vT>>& toSearch, const vT target);

    /// @param toSearch Ascending ordered index vector.
    /// @param target The target value to search for.
    /// @return The found item. or nullptr if none are found.
    template<typename pT, typename vT>
    IndexValue<pT, vT>* InterpolationSearchUnique(std::vector<IndexValue<pT, vT>>& toSearch, const vT target);
} // search
