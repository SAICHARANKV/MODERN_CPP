#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mt;

int main()
{
    std::vector<std::vector<int>> data{
        std::vector<int>{1, 2, 3, 4},
        std::vector<int>{1, 2, 3, 4},
        std::vector<int>{1, 2, 3, 4}};

    auto f1 = [](std::vector<int> &data)
    {
        float total = 0.0f;
        for (int val : data)
        {
            total += val;
        }
        mt.lock();
        std::cout << "Average is: " << total / data.size() << "\n";
        mt.unlock();
    };

    std::array<std::thread, 3> d;
    auto itr = data.begin();
    for (std::thread &th : d)
    {
        th = std::thread(f1, std::ref(*itr));
        itr++;
    }

    for (std::thread &th : d)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}