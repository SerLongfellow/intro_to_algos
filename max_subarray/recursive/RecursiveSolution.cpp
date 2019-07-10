
#include <iostream>
#include <bits/stdc++.h>

#include <RecursiveSolution.h>


RecursiveSolution::~RecursiveSolution()
{

}


MaxSubArrayResult
RecursiveSolution::find_max_subarray(int* array, int size)
{
    return find_max_subarray_recurse(array, 0, size-1);
}


MaxSubArrayResult
RecursiveSolution::find_max_subarray_cross(int* array, int low, int mid, int high)
{
    MaxSubArrayResult result;

    int left_sum = INT_MIN;
    int left_index = mid;
    int sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum += array[i];

        if (sum > left_sum)
        {
            left_sum = sum;
            left_index = i;
        }
    }
    
    int right_sum = INT_MIN;
    int right_index = mid;
    sum = 0;

    for (int i = mid+1; i < high; i++)
    {
        sum += array[i];

        if (sum > right_sum)
        {
            right_sum = sum;
            right_index = i;
        }
    }

    result.left_index = left_index;
    result.right_index = right_index;
    result.sum = left_sum + right_sum;

    if ((left_sum == INT_MIN || right_sum == INT_MIN) && result.sum > 0)
        result.sum = INT_MIN;

    return result;
}


MaxSubArrayResult
RecursiveSolution::find_max_subarray_recurse(int* array, int low, int high)
{
    MaxSubArrayResult result;

    if (low == high)
    {
        result.left_index = low;
        result.right_index = high;
        result.sum = array[low];
        return result;
    }

    int mid = (low + high) / 2;
    
    MaxSubArrayResult left_result = find_max_subarray_recurse(array, low, mid);
    MaxSubArrayResult right_result = find_max_subarray_recurse(array, mid+1, high);
    MaxSubArrayResult cross_result = find_max_subarray_cross(array, low, mid, high);

    if (left_result.sum > right_result.sum && left_result.sum > cross_result.sum)
    {
        return left_result;
    }
    else if (right_result.sum > left_result.sum && right_result.sum > cross_result.sum)
    {
        return right_result;
    }
    else
    {
        return cross_result;
    }
}


