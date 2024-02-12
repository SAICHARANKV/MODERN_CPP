#include "Functionalities.h"
#include <iostream>

int main()
{
    std::cout << "Creating Objects!!!!" << std::endl;
    AccountContainer accounts; // Empty Container
    MapContainer data;
    CreateObjects(accounts, data); // adding data into vector using shared_ptr
    try
    {
        std::cout << "\n-----------------------------\n";

        float ans = FindTotalBankBalance(data);
        std::cout << "FindTotalBankBalance: " << ans << "\n";
        std::cout << "-----------------------------\n";

        unsigned int res = CountAbove50000BalanceAmount(data);
        std::cout << "CountAbove50000BalanceAmount: " << res << "\n";
        std::cout << "-----------------------------\n";

        if (bool ans1 = IsAnyAccountWithNoCard(data))
        {
            std::cout << "At least one account with null card exists\n";
        }
        else
        {
            std::cout << "No Such Account Exists\n";
        }
        std::cout << "-----------------------------\n";

        if (std::optional<float> result = FindBalanceById(data, 72719L); result.has_value())
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