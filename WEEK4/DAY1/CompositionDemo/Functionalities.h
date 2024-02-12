#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include "BankAccount.h"
#include <optional>
using AccountPointer = std::shared_ptr<BankAccount>;
using Container = std::vector<AccountPointer>;
using CardContainer = std::vector<std::shared_ptr<DebitCard>>;

void CreateObjects(Container &data);

/* Return the total bank balance from all accounts */
float FindTotalBankBalance(const Container &data);

/* Return Count of all account whose balance amount is above 50000 */
unsigned int CountAbove50000BalanceAmount(const Container &data);

/* Find if any account exists with no debit card instance (null ptr for card pointer) */
bool IsAnyAccountWithNoCard(const Container &data);

/*
    return the cvv number of the debit card attached with the account with max balance
    of multiple such max account exist, return the first match found
*/
std::optional<unsigned short> FindMaxBalanceCvvNumber(const Container &data);

/*
    return the expiry date of the debit card attached with the acc with mix bal
    of the multiple such min accounts exist, return the first match found
*/

std::optional<std::string> FindMinBalanceExpiry(const Container &data);

/*
    return all shared pointers to debitcard instances from all accounts
*/

CardContainer ReturnDebitCardPointers(const Container &data);

/*
    return non null debitcard pointers in a container from all accounts
*/

std::optional<CardContainer> ReturnNonNullDebitCardPointers(const Container &data); // optional bcoz

/*
    return a container of shared pointer to account objects if
    a) Account has a balance of over 30000
    b) account debit card is not null
*/
std::optional<Container> FindMatchingAccounts(const Container &data);

#endif // FUNCTIONALITIES_H
