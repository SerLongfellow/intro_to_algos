
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

#include <Solution.h>
#include <brute_force/BruteForceSolution.h>
#include <recursive/RecursiveSolution.h>


int 
main(int argc, char* argv[])
{
    std::cout << "Starting max subarray solution..." << std::endl;

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
    Solution* solution = new BruteForceSolution();
    MaxSubArrayResult result = solution->find_max_subarray(data, size);
    delete solution;
    
    std::cout << "Finished running recursive algorithm!" << std::endl;
    std::cout << "left index:  " << result.left_index << std::endl;
    std::cout << "right index: " << result.right_index << std::endl;
    std::cout << "sum:         " << result.sum << std::endl;


    std::cout << "Running recursive algorithm..." << std::endl;
    solution = new RecursiveSolution();
    result = solution->find_max_subarray(data, size);
    delete solution;
    
    std::cout << "Finished running recursive algorithm!" << std::endl;
    std::cout << "left index:  " << result.left_index << std::endl;
    std::cout << "right index: " << result.right_index << std::endl;
    std::cout << "sum:         " << result.sum << std::endl;

    return 0;
}

