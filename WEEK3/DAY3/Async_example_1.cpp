#include <iostream>
#include <vector>
#include <future>
/*
    SOC -> Like Processor,WIFI,drives ...etc.
    - Core: One Available Working node in the microprocessor
    - Thread: A set of Instructions to be executed.

    Hyper Threading - A single thread can do 2 process.When there is a delay in one
    process for a time processor or OS could take different process (context switching)
    and run untill first delay completes.

    parallel- running all programs at same time.

    concurrent - Running a program without waiting for other
    program to execute by using complete hardware capacity eg:async thread

    atomic variable - a lockless program where mutex use is not there.
*/

float AverageofNValues(std::future<int> &ft)
{
    /* First 3 lines do not need or have an effect of input
    so async style coding can be done. */
    std::vector<int> data{10, 20, 30, 40, 50};
    float sum = 0.0f;
    int count = 0;
    int N = ft.get();
    if (data.size() < N || N <= 0)
    {
        throw std::runtime_error("Invalid N!");
    }
    // auto itr = data.begin();
    // for (; count < N; count++)
    // {
    //     sum = sum + *itr;
    //     itr++;
    // }
    for (int val : data)
    {
        sum = sum + val;
        count++;
        if (count == N)
        {
            break;
        }
    }
    return sum / N;
}
int main()
{
    std::promise<int> pr; // Behaves like an object
    std::future<int> ft = pr.get_future();

    // any parameter we pass to asyn ,bind or thread with a function pointer
    // SUCH THAT parameter must be received by the function as Reference,
    // YOU MUST PASS SUCH PARAMETERS BY USING std::ref
    // IF NOT PASSED it might give segmentation error.
    std::future<float> result = std::async(std::launch::async, AverageofNValues, std::ref(ft));
    // ft has to be passed by reference as it makes a duplication of ft object and pr cannot
    // communicate with ft as it is duplicated.

    int val{0};
    std::cin >> val;
    pr.set_value(val); // Assigning the value.

    std::cout << result.get() << std::endl;
}

// Assigning values taken by "promise"
// Fetching data(average) is taken care by "future".

/*
    Step 1: Enter the car. Start the Accessories of the car.(software setup)
    Step 2: 2 Activities
            a) Sync phone data with car.
            b) Find Directions to my destination.

    async :- start activity 1 and in waiting time go for activity 2 and start
    and run untill activity 1 completes.

*/

/*
std::launch::differ :- on same thread in different time.
std::launch::async :- on same time parallely executes threads.
std::launch :- if no parameter then os will select the best one.
*/
/*
 reference of x or pointer to x
    &x  : if there is no data type to the left of x,it is pointer

    int& x: this is reference to int;
    
*/