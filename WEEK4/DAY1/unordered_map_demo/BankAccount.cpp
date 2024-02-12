#include "BankAccount.h"
#include <limits>
#include <stdexcept>

BankAccount::BankAccount(std::string accountHolderName, AccountType accounttype, float accountBalance)
    : _accountNumber(++_counter), _accountHolderName(accountHolderName), _accounttype(accounttype), _accountBalance(accountBalance), _accountDebitCard(nullptr)
{
}

BankAccount::BankAccount(std::string accountHolderName, AccountType accounttype, float accountBalance, CardPointer accountDebitCard)
    : BankAccount(accountHolderName, accounttype, accountBalance)
{
    _accountDebitCard = accountDebitCard;
}

// try with custom exception class.
void BankAccount::DepositAmount(long amount)
{
    if (_accountBalance + amount > __LONG_MAX__)
    {
        throw std::runtime_error("Cannot Deposit an amount this large!!"); // this may be incorrect !!please reasearch!!
    }

    _accountBalance += amount;
}

long BankAccount::WithdrawAmount(long amount)
{
    if (amount > _accountBalance)
    {
        throw std::runtime_error("Cannot withdraw an amount larger than account balance!!"); // this may be incorrect !!please reasearch!!
    }
    _accountBalance -= amount;

    return _accountBalance;
}
