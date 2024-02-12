#include "Functionalities.h"
#include <thread>
#include <array>
#include <future>
int main()
{
    std::cout << "Creating Objects!!!!" << std::endl;
    AccountContainer accounts; // Empty Container
    MapContainer data;

    // std::array<std::thread, 5> threadsArr;
    std::future<void> r1 = std::async(std::launch::async, CreateObjects, std::ref(accounts), std::ref(data));
    r1.get();
    // Object creation need to complete first then other threads needs to run.or else error
    // get() can be called only once on.one future object == one get() better store to variable
    // CreateObjects(accounts, data); // adding data into vector using shared_ptr
    try
    {

        std::future<float> ans = std::async(std::launch::async, FindTotalBankBalance, std::ref(data));
        std::future<unsigned int> res = std::async(std::launch::async, CountAbove50000BalanceAmount, std::ref(data));
        std::future<bool> ans1 = std::async(std::launch::async, IsAnyAccountWithNoCard, std::ref(data));
        bool flag = ans1.get();
        std::future<std::optional<float>> result1 = std::async(std::launch::async, FindBalanceById, std::ref(data), 722719L);
        std::optional<float> result = result1.get();

        std::cout << "\n-----------------------------\n";
        std::cout << "FindTotalBankBalance: " << ans.get() << "\n";
        std::cout << "-----------------------------\n";
        std::cout << "CountAbove50000BalanceAmount: " << res.get() << "\n";
        std::cout << "-----------------------------\n";
        if (flag)
        {
            std::cout << "At least one account with null card exists\n";
        }
        else
        {
            std::cout << "No Such Account Exists\n";
        }
        std::cout << "-----------------------------\n";
        if (result.has_value())
        {
            std::cout << "Account Found With Balance: " << result.value() << "\n";
        }
        else
        {
            std::cerr << "Account Not Found\n";
        }
        std::cout << "-----------------------------\n";
    }
    catch (std::runtime_error &ex)
    {
        std::cerr << ex.what() << "\n";
    }

    return 0;
}