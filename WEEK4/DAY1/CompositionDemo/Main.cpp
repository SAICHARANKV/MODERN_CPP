#include"Functionalities.h"

int main()
{
    std::vector<std::shared_ptr<BankAccount>> data;
    CreateObjects(data);

    try
    {
        std::cout<<"FindTotalBankBalance(data)="<<FindTotalBankBalance(data)<<"\n";
        
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout<<"--------------------------"<<"\n";
    try
    {
        std::cout<<"CountAbove50000BalanceAccounts="<<CountAbove50000BalanceAmount(data)<<"\n";
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout<<"--------------------------"<<"\n";
    try
    {
        std::cout<<"IsAnyAccountWithNoCard="<<IsAnyAccountWithNoCard(data)<<"\n";
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        if(FindMaxBalanceCvvNumber(data).has_value())
        {
            std::cout<<"FindMaxbalanceCvvNumber="<<FindMaxBalanceCvvNumber(data).value()<<"\n";
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        if(FindMinBalanceExpiry(data).has_value())
        {
            std::cout<<"FindMinBalanceExpiry="<<FindMinBalanceExpiry(data).value()<<"\n";
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        for(CardPointer& cp:  ReturnDebitCardPointers(data))
        {
            std::cout<<cp<<"\n";
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        if(ReturnNonNullDebitCardPointers(data).has_value())
        {
            for(CardPointer cp:ReturnNonNullDebitCardPointers(data).value())
            {
                std::cout<<cp<<"\n";
            }
        }
        
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        if(ReturnNonNullDebitCardPointers(data).has_value())
        {
            for(AccountPointer ap:FindMatchingAccounts(data).value())
            {
                std::cout<<ap<<"\n";
            }
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    


    return 0;
}