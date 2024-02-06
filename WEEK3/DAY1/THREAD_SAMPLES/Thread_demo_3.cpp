    #include <iostream>
    #include <thread>
    #include <vector>
    #include <mutex>

    //<------ Version 1 of Program----->
    /*
            [   v1     v2      v3  ]
                for(auto val:data)
                {
                    fn(val);
                }
                // Might give output but takes time and not used resources accurately

            Option 2: Use Separate Threads
                thread t1(fn,v1);
                thread t2(fn,v2);
                thread t3(fn,v3); // uses all resources(cpu's)
    */

    std::mutex mt;
    int main()
    {
        std::vector<std::vector<int>> inputs{
            std::vector<int>{10, 20, 30},
            std::vector<int>{10, 20, 30},
            std::vector<int>{10, 20, 30},
        };

        auto f1 = [](std::vector<int> &data)
        {
            float total = 0.0f;
            for (int val : data)
            {
                total = total + val;
            }
            mt.lock();
            std::cout << "Average is: " << total / data.size() << "\n";
            mt.unlock();
        };

        std::array<std::thread, 3> arr;

        // Mapping
        auto itr = inputs.begin();

        for (std::thread &th : arr)
        {
            th = std::thread(f1, std::ref(*itr));
            itr++;
        }

        for (std::thread &th : arr)
        {
            if (th.joinable()) // u can add thread if true
            {
                th.join();
            }
        }
    }               