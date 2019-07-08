
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
find_max_subarray(int* array, int size)
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


int 
main(int argc, char* argv[])
{
    std::cout << "Starting brute force max subarray implementation..." << std::endl;

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

    std::cout << "Running brute force algorithm..." << std::endl;

    MaxSubArrayResult result = find_max_subarray(data, size);
    
    std::cout << "Finished running brute force algorithm!" << std::endl;
    std::cout << "left index:  " << result.left_index << std::endl;
    std::cout << "right index: " << result.right_index << std::endl;
    std::cout << "sum:         " << result.sum << std::endl;

    return 0;
}

