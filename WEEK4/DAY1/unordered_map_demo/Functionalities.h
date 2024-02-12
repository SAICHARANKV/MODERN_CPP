#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <unordered_map>
#include <optional>
#include <algorithm>
#include <numeric>
#include <memory>
#include <vector>
#include "BankAccount.h"

using AccountPointer = std::shared_ptr<BankAccount>;
using MapContainer = std::unordered_map<unsigned long, AccountPointer>;
using AccountContainer = std::vector<AccountPointer>;

void CreateObjects(AccountContainer &accounts, MapContainer &data);

float FindTotalBankBalance(const MapContainer &data);
unsigned int CountAbove50000BalanceAmount(const MapContainer &data);
bool IsAnyAccountWithNoCard(const MapContainer &data);

/*
Find the account balance of the account
whose account number is provided as a parameter
*/
std::optional<float> FindBalanceById(const MapContainer&data,unsigned long accNumber);

#endif // FUNCTIONALITIES_H
