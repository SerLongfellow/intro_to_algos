#pragma once

#include <Solution.h>


class BruteForceSolution : public Solution
{
    public:
        virtual ~BruteForceSolution();
        virtual MaxSubArrayResult find_max_subarray(int* array, int size);
};


