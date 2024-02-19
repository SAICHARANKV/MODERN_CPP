#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <array>
#include <functional>

using VectorContainer = std::vector<std::vector<int>>;
using ThreadArray = std::array<std::thread, 3>;
std::mutex mt;
using FnContainer = std::vector<std::function<void(std::vector<int> &data)>>;

void FillData(VectorContainer &inputs)
{
    inputs.emplace_back(std::vector<int>{10, 20, 30});
    inputs.emplace_back(std::vector<int>{10, 20, 30});
    inputs.emplace_back(std::vector<int>{10, 20, 30});
}

void MakeLambda(FnContainer &fn)
{
    auto f1 = [](std::vector<int> &data) -> void
    {
        float total = 0.0f;
        for (int val : data)
        {
            total = total + val;
        }
        std::lock_guard<std::mutex> lg(mt);
        std::cout << "Average is: " << total / data.size() << "\n";
    };

    auto f2 = [](std::vector<int> &data) -> void
    {
        int max = 0;
        for (int val : data)
        {
            if (val > max)
                max = val;
        }
        std::lock_guard<std::mutex> lg(mt);
        std::cout << "Max Value is: " << max << "\n";
    };

    auto f3 = [](std::vector<int> &data) -> void
    {
        int min = data.empty() ? 0 : data[0]; // Initialize min with first element
        for (int val : data)
        {
            if (val < min)
                min = val;
        }
        std::lock_guard<std::mutex> lg(mt);
        std::cout << "Min Value is: " << min << "\n";
    };

    fn = {f1, f2, f3}; // Store lambdas in fn container
}

void MapThreadsToAction(
    VectorContainer &inputs,
    ThreadArray &arr,
    FnContainer &fn)
{
    auto itr = inputs.begin();
    auto ftr = fn.begin();
    
    for (std::thread &th : arr)
    {
        th = std::thread(*ftr, std::ref(*itr)); // Execute the corresponding function for each thread
        ++ftr;
        ++itr;
    }
}

void JoinThreads(ThreadArray &arr)
{
    for (std::thread &th : arr)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}

int main()
{
    VectorContainer inputs;
    FnContainer fn;

    ThreadArray arr;
    FillData(inputs);
    MakeLambda(fn); // Assign lambda functions to fn container

    MapThreadsToAction(inputs, arr, fn);
    JoinThreads(arr);
}
