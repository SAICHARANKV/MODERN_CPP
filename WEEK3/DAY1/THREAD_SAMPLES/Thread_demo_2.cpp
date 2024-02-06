/*
    amount = x;
    100 times I will withdraw 10 rupees
    100 times I will deposit 10 rupees
*/
#include <iostream>
#include <thread>
#include <mutex>

int amount = 1000;
std::mutex mt;
void Withdraw()
{
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        mt.lock();
        amount = amount - 10;
        mt.unlock();
    }
}

void Deposit()
{
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        mt.lock();
        amount = amount + 10; // Critical Section
        mt.unlock();
    }
}

// Terminal for loop for((i=0;i<50;i++)); do ./app; done

int main()
{
    std::thread t1(Withdraw);
    std::thread t2(Deposit);

    t1.join();
    t2.join();

    std::cout << "Amount left : " << amount << "\n";
}

/*
                                DATA
    ALU [registers] <-------------------------->CACHE<-->RAM

    After calculation        
    ALU [registers] ----------->CACHE----------->RAM

*/