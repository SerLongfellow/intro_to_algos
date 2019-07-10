#pragma once

#include <Solution.h>


class RecursiveSolution : public Solution
{
    public:
        virtual ~RecursiveSolution();
        virtual MaxSubArrayResult find_max_subarray(int* array, int size);

    private:
        MaxSubArrayResult find_max_subarray_cross(int* array, int low, int mid, int high);
        MaxSubArrayResult find_max_subarray_recurse(int* array, int low, int high);
};


