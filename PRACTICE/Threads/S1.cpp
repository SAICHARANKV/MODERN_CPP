#include <thread>
#include <iostream>
#include <vector>
#include <array>
#include <mutex>

int main()
{
    std::mutex mt;
    std::vector<int> data{1, 2, 3, 4, 5};

    auto square = [&](std::vector<int> &data)
    {
        for (int val : data)
        {
            // Making it to run concurrently with time delay
            std::this_thread::sleep_for(std::chrono::seconds(2));
            mt.lock();
            std::cout << val * val << "\t";
            mt.unlock();
        }
        std::cout << "\n";
    };
    std::thread t1(square, std::ref(data));
    std::cout << "Printing Threads" << std::endl;
    std::thread t2(square, std::ref(data));

    t1.join();
    t2.join();
}