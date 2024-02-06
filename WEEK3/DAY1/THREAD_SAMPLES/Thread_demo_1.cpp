#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using Container = std::vector<int>;
std::mutex mt; // LOCK!!!
/*
    Synchrnously, in a single process,single thread mode
*/

void Square(Container &data)
{
    for (int val : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mt.lock();
        std::cout << "Square of number: " << val << " is: " << val * val << "\n";
        mt.unlock();
    }
}

void Cube(Container &data)
{
    for (int val : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mt.lock();
        std::cout << "Cube of number: " << val << " is: " << val * val * val << "\n";
        mt.unlock();
    }
}

int main()
{
    std::vector<int> data{10, 20, 30};
    /*
        Direct calling throws an error as rvalue wont accept
        using std::ref sends a reference of data forcly
    */

    /*
        Creates a thread object,assigned a function
        to the thread,accepts all arguments required by the thread

        thread will now run like a mini-program

        t1 is now available for scheduling by the OS
    */
    std::thread t1(Square, std::ref(data));
    std::thread t2(Cube, std::ref(data));
    /*
        This may lead to race condition(compiler doesnot know which thread task to do first and
        also both process in main are going simultaneously. )
    */

    t1.join(); // main should wait till t1 is finished.Then go to nextline
    t2.join(); // Main will wait for t2 to finsh. if it is finished go to next line

    /* Outputs will be sent to console screen through a buffer*/
}