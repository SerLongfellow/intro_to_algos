#pragma once


struct MaxSubArrayResult
{
    int left_index;
    int right_index;
    int sum;
};

class Solution
{
    public:
        virtual ~Solution();

        virtual MaxSubArrayResult find_max_subarray(int* array, int size) = 0;
};

