#include <iostream>
#include <thread>
#include <vector>
#include <functional>

int main()
{
    std::vector<int> data{1, 2, 3, 4, 5};
    using functiontype = std::function<void(std::vector<int> &)>;
    using FnContainer = std::vector<functiontype>;
    FnContainer fns;
    auto square = [](const auto &data) -> void
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        for (int ele : data)
        {
            std::cout << "Square is: " << ele * ele << "\n";
        }
    };

    auto cube = [](const auto &data) -> void
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        for (int ele : data)
        {
            std::cout << "Cube is: " << ele * ele * ele << "\n";
        }
    };
    fns.emplace_back(square);
    fns.emplace_back(cube);

    for (auto val : fns)
    {
        val(data);
    }

    std::thread t1(square, data);
    std::thread t2(cube, data);
    t1.join();
    t2.join();
}