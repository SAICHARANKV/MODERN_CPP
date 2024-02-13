#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <memory>
#include <ostream>
#include "AccountType.h"
#include "DebitCard.h"

using CardPointer = std::shared_ptr<DebitCard>;

class BankAccount
{
private:
    static int _counter;
    const unsigned long _accountNumber;
    std::string _accountHolderName;
    AccountType _accounttype;
    float _accountBalance;
    CardPointer _accountDebitCard;

public:
    /*
          std
  Special enablers and disablers
    */
    BankAccount() = delete;
    BankAccount(const BankAccount &) = delete;
    BankAccount &operator=(const BankAccount &) = delete;
    BankAccount(BankAccount &&) = delete; // Move constructor
    BankAccount &operator=(BankAccount &&) = delete;
    ~BankAccount() = default;

    /*
        User defined parameterized constructor
    */
    BankAccount(std::string accountHolderName, AccountType accounttype, float accountBalance);
    BankAccount(std::string accountHolderName, AccountType accounttype, float accountBalance, CardPointer accountDebitCard);

    /*
        Member function for account behaviour
    */
    void DepositAmount(long amount);
    long WithdrawAmount(long amount);

    /*
    getters and setters for member access
    */
    unsigned long accountNumber() const { return _accountNumber; }
    std::string accountHolderName() const { return _accountHolderName; }
    AccountType accounttype() const { return _accounttype; }
    void setAccountHolderName(const std::string &accountHolderName) { _accountHolderName = accountHolderName; }
    void setAccounttype(const AccountType &accounttype) { _accounttype = accounttype; }

    // Getter for Debitcard access from DebitCard.h
    // std::shared_ptr<DebitCard> accountDebitCard() const { return _accountDebitCard; }
    CardPointer accountDebitCard() const { return _accountDebitCard; }

    float accountBalance() const { return _accountBalance; }

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &rhs);

    // bool operator!=(const BankAccount &e);
};
inline int BankAccount::_counter = 900000; // static

#endif // BANKACCOUNT_H
