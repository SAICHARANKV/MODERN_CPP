//<--------------- Version 3 Of Program---------------->
// Addition of corner cases and expections
// Mutex Unlocking

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <array>
#include <functional>

using VectorContainer = std::vector<std::vector<int>>;
using ThreadArray = std::array<std::thread, 3>;
std::mutex mt; // illegal declaration  == solution : save as a data member in class

/* Fill Data in Container */
void FillData(VectorContainer &inputs)
{
    inputs.emplace_back(std::vector<int>{10, 20, 30});
    inputs.emplace_back(std::vector<int>{10, 20, 30});
    inputs.emplace_back(std::vector<int>{10, 20, 30});
}

// Function wrapper
// Lambda Function for average logic
// return type is full signature of lambda in void
std::function<void(std::vector<int> &data)> MakeLambda()
{
    // Declaration of Lambda function
    auto f1 = [](std::vector<int> &data) -> void
    {
        float total = 0.0f;
        for (int val : data)
        {
            total = total + val;
        }
        std::lock_guard<std::mutex> lg(mt); // !!!  NEW CONCEPT - solved dead lock
        std::cout << "Average is: " << total / data.size() << "\n";
    };

    return f1;
}

// Mapping threads to array
void MapThreadsToAction(
    VectorContainer &inputs,
    ThreadArray &arr,
    std::function<void(std::vector<int> &data)> &fn)
{
    // Mapping of thread array
    auto itr = inputs.begin();

    for (std::thread &th : arr)
    {
        th = std::thread(fn, std::ref(*itr));
        itr++;
    }
}

// Joining Threads to Main
void JoinThreads(ThreadArray &arr)
{
    // joining of threads
    for (std::thread &th : arr)
    {
        if (th.joinable()) // u can add thread if true
        {
            th.join();
        }
    }
}

int main()
{
    // Creating and Filling data
    VectorContainer inputs;

    // Declaration of Thread Array
    ThreadArray arr;
    auto fn = MakeLambda();

    // Function calls
    FillData(inputs);

    // Mapping of Threads
    MapThreadsToAction(inputs, arr, fn);

    // Joining of threads
    JoinThreads(arr);
}