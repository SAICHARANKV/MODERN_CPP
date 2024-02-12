#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

/*
Condition Variable:all consumers will be in a sleep mode until "data" becomes available
and "threads" consumes the resource variable and goes back to sleep after "data" consumed
completely.
*/
std::mutex mt;
int amount = 0;
std::condition_variable cv;
bool flag = false;

void CalculateSquare()
{
    std::unique_lock<std::mutex> lk(mt);
    cv.wait(lk, []()
            { return flag; }); // here lambda function is a predicate(returns true or false)
    // lk is unlocked,t1 thread goes to sleep
    std::cout << amount * amount << "\n";
}

int main()
{
    // STEP 1 : CREATE AND SCHEDULE T1!!!
    std::thread t1(CalculateSquare);
    std::cin >> amount;
    flag = true;
    // SENDING SIGNAL
    cv.notify_one();
    t1.join(); // cpp 20: jthread
}