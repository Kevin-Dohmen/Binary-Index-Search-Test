#pragma once

#include <cstdint>

template<typename pT = uint32_t, typename vT = int32_t>
struct IndexValue{
public:
    pT Pointer;
    vT Value;

    IndexValue(pT pointer, vT value) {
        Pointer = pointer;
        Value = value;
    }

    IndexValue() {
        Pointer = 0;
        Value = 0;
    }
};
