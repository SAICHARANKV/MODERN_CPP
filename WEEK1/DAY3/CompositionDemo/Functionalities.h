#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include "BankAccount.h"

using AccountPointer = std::shared_ptr<BankAccount>;
using Container = std::vector<AccountPointer>;

void CreateObjects(Container &data); // Empty

void PrintDetails(Container &data);

#endif // FUNCTIONALITIES_H
