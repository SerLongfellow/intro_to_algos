
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>


struct MaxSubArrayResult
{
    int left_index;
    int right_index;
    int sum;
};


MaxSubArrayResult
find_max_subarray_cross(int* array, int low, int mid, int high)
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
find_max_subarray_recurse(int* array, int low, int high)
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


MaxSubArrayResult
find_max_subarray(int* array, int size)
{
    return find_max_subarray_recurse(array, 0, size-1);
}


int 
main(int argc, char* argv[])
{
    std::cout << "Starting recursive max subarray implementation..." << std::endl;

    if (argc < 2)
    {
        std::cerr << "No data file specified!" << std::endl;
        exit(1);
    }

    char* data_file = argv[1];
    std::fstream in(data_file);
    
    if (!in.good()) 
    {
        std::cerr << "Could not open file: " << data_file << std::endl;
        exit(1);
    }

    int* data = nullptr;
    int size = 0;

    std::string line;
    int line_num = 0;
    while (!in.eof())
    {
        std::getline(in, line);

        if (line.empty())
            continue;

        int n = std::stoi(line);

        if (line_num == 0)
        {
            size = n;
            data = new int[size];
        }
        else
        {
            if (data == nullptr)
            {
                std::cerr << "We're fucked!" << std::endl;
                exit(1);
            }

            data[line_num - 1] = n;
        }

        line_num += 1;
    }

    std::cout << "Finished reading in data!" << std::endl << std::endl;

    for (int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Running recursive algorithm..." << std::endl;

    MaxSubArrayResult result = find_max_subarray(data, size);
    
    std::cout << "Finished running recursive algorithm!" << std::endl;
    std::cout << "left index:  " << result.left_index << std::endl;
    std::cout << "right index: " << result.right_index << std::endl;
    std::cout << "sum:         " << result.sum << std::endl;

    return 0;
}

