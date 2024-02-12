#include "Functionalities.h"
#include "AccountType.h"

void CreateObjects(AccountContainer &accounts, MapContainer &data)
{
    accounts.emplace_back(std::make_shared<BankAccount>(
        "Sai",
        AccountType::SAVINGS,
        78000.0f,
        std::make_shared<DebitCard>(
            111,
            3838930L,
            "09/27",
            DebitCardType::VISA)));

    accounts.emplace_back(std::make_shared<BankAccount>(
        "Surya",
        AccountType::SAVINGS,
        292000.0f,
        std::make_shared<DebitCard>(
            134,
            84842030L,
            "3/28",
            DebitCardType::MASTERCARD)));

    accounts.emplace_back(std::make_shared<BankAccount>(
        "Dolly",
        AccountType::CURRENT,
        289900.0f,
        std::make_shared<DebitCard>(
            142,
            73844303L,
            "04/24",
            DebitCardType::VISA)));

    // L value to r value by std::move
    data.emplace(
        std::make_pair<unsigned long, AccountPointer>(accounts[0]->accountNumber(), std::move(accounts[0])));
    data.emplace(
        std::make_pair<unsigned long, AccountPointer>(accounts[1]->accountNumber(), std::move(accounts[1])));
    data.emplace(
        std::make_pair<unsigned long, AccountPointer>(accounts[2]->accountNumber(), std::move(accounts[2])));
}

float FindTotalBankBalance(const MapContainer &data)
{
    if (data.empty())
        std::runtime_error("Data Not Available");

    float ans = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float total, std::pair<unsigned long, AccountPointer> &&p)
        {
            return total + p.second->accountBalance();
        });

    return ans;
}

unsigned int CountAbove50000BalanceAmount(const MapContainer &data)
{
    if (data.empty())
        std::runtime_error("Data Not Available");

    std::size_t ans = std::count_if(
        data.begin(),
        data.end(),
        [](std::pair<unsigned long, AccountPointer> &&p)
        {
            return p.second->accountBalance() > 50000.0f;
        });
    return ans;
}

bool IsAnyAccountWithNoCard(const MapContainer &data)
{
    if (data.empty())
        std::runtime_error("Data Not Available");

    bool ans = std::any_of(
        data.begin(),
        data.end(),
        [](std::pair<unsigned long, AccountPointer> &&p)
        {
            return p.second->accountDebitCard() == nullptr;
        });
    return ans;
}

std::optional<float> FindBalanceById(const MapContainer &data, unsigned long accNumber)
{
    if (data.empty())
    {
        std::runtime_error("Data Not Available");
    }

    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](std::pair<unsigned long, AccountPointer> &&p)
        {
            return p.second->accountNumber() == accNumber;
        });

    if (itr == data.end())
    {
        return std::nullopt;
    }
    
    return (*itr).second->accountBalance();
}
/*
unordered map  : map<key,value>
    create a key , create an object ----> move them in a pair , pair moves into hashtable
        l to r value by move

    step 1: create the object.preserve its lifetime in some sort of data container(not hashtable)
        special case : if key is not available by default step 1 can be followed.


*/