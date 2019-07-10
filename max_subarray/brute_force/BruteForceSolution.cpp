
#include <bits/stdc++.h>

#include <BruteForceSolution.h>


BruteForceSolution::~BruteForceSolution()
{

}


MaxSubArrayResult
BruteForceSolution::find_max_subarray(int* array, int size)
{
    int max_sum = INT_MIN;
    int left_index = 0;
    int right_index = 0;

    for (int i = 0; i < size-1; i++)
    {
        int sum = array[i];

        for (int j = i+1; j < size; j++)
        {
            sum += array[j];
            
            if (sum > max_sum)
            {
                max_sum = sum;
                left_index = i;
                right_index = j;
            }
        }
    }

    MaxSubArrayResult result;
    result.sum = max_sum;
    result.left_index = left_index;
    result.right_index = right_index;

    return result;
}


