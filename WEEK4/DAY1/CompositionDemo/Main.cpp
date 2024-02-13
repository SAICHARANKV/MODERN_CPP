#include "Functionalities.h"

int main()
{
    std::vector<std::shared_ptr<BankAccount>> data;
    CreateObjects(data);

    try
    {
        float ans = 0.0f;
        ans = FindTotalBankBalance(data);
        std::cout << "FindTotalBankBalance(data)=" << ans << "\n";
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "--------------------------"
              << "\n";
    try
    {
        std::cout << "CountAbove50000BalanceAccounts=" << CountAbove50000BalanceAmount(data) << "\n";
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "--------------------------"
              << "\n";
    try
    {
        std::cout << "IsAnyAccountWithNoCard: "
                  << "\n";

        auto answer = IsAnyAccountWithNoCard(data);
        if (answer)
        {
            std::cout << "We have One Account with No card"<<"\n";
        }
        else
        {
            std::cout << "We don't have any accounts without cards"<<"\n";
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "--------------------------"
              << "\n";

    try
    {
        auto res =FindMaxBalanceCvvNumber(data) ;
        if (res.has_value())
        {
            std::cout << "FindMaxbalanceCvvNumber=" << res.value() << "\n";
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }
    
    std::cout << "--------------------------"
              << "\n";
    try
    {
        auto result = FindMinBalanceExpiry(data);
        if (result.has_value())
        {
            std::cout << "FindMinBalanceExpiry=" << result.value() << "\n";
        }
    }

    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "--------------------------"
              << "\n";
    try
    {
        for (CardPointer &cp : ReturnDebitCardPointers(data))
        {
            std::cout << *cp << "\n";
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "--------------------------"
              << "\n";
    try
    {
        auto result1 = ReturnNonNullDebitCardPointers(data);
        if (result1.has_value())
        {
            for (CardPointer cp : result1.value())
            {
                std::cout << *cp << "\n";
            }
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "--------------------------"
              << "\n";
    try
    {
        auto rr = FindMatchingAccounts(data);
        if (rr.has_value())
        {
            for (AccountPointer ap : rr.value())
            {
                std::cout << *ap << "\n";
            }
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}