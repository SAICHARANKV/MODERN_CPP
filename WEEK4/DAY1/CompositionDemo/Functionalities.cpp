#include "Functionalities.h"
#include <algorithm>
#include <numeric>
#include <string>

void CreateObjects(Container &data) {
  std::string _expiry = "12/27";

  data.push_back(
      std::make_shared<BankAccount>("Saicharan",          // name
                                    AccountType::SAVINGS, // accounttype
                                    99832.0f));           // Balance
                                                          // DebitCard
  // std::make_shared<DebitCard>(111,                // cvv
  //                             11234452311L,       // cardNumber
  //                             _expiry,            // expiryDate
  //                             DebitCardType::VISA // cardType
  //                             )));

  data.push_back(std::make_shared<BankAccount>(
      "Kushal",             // name
      AccountType::CURRENT, // accounttype
      12992.0f,             // Balance
      // DebitCard
      std::make_shared<DebitCard>(124,                 // cvv
                                  18229383492L,        // cardNumber
                                  _expiry,             // expiryDate
                                  DebitCardType::RUPAY // cardType
                                  )));
}

/*
    init/answer upto current point
    0                           10  20  30
                10                   |   |
                |                    |   |
                            30           |
                            |            |
                                    60

*/

// Binary op : Any operation using 2 operands
float FindTotalBankBalance(const Container &data) {
  if (data.empty())
    throw std::runtime_error("Data is Empty!!!\n");

  float ans = std::accumulate(data.begin(), // start point
                              data.end(),   // End point
                              0.0f,         // Initalzing Value
                              [](float total, const AccountPointer &ptr) {
                                return (total + ptr->accountBalance());
                              }); // Operation need to be in lambda

  return ans;
}

unsigned int CountAbove50000BalanceAmount(const Container &data) {
  if (data.empty())
    throw std::runtime_error("Data is Empty!!!\n");

  size_t ans =
      std::count_if(data.begin(), data.end(), [](const AccountPointer &ptr) {
        return ptr->accountBalance() > 50000;
      });
  return ans;
}

// all_of , none_of ,any_of
bool IsAnyAccountWithNoCard(const Container &data) {
  if (data.empty()) {
    throw std::runtime_error("Data is Empty!!!\n");
  }
  bool ans =
      std::any_of(data.begin(), data.end(), [](const AccountPointer &ptr) {
        return ptr->accountDebitCard() == nullptr;
      });
  return ans;
}

std::optional<unsigned short> FindMaxBalanceCvvNumber(const Container &data) {
  if (data.empty())
    throw std::runtime_error("Data is Empty!!!\n");

  auto ans = std::max_element(
      data.begin(), data.end(),
      [](const AccountPointer &ptr1, const AccountPointer &ptr2) {
        return ptr1->accountBalance() > ptr2->accountBalance();
      });
  if ((*ans)->accountDebitCard() == nullptr)
    return std::nullopt;
  return (*ans)->accountDebitCard()->cvv();
}

std::optional<std::string> FindMinBalanceExpiry(const Container &data) {
  if (data.empty())
    throw std::runtime_error("Data is Empty!!!\n");

  auto ans = std::min_element(
      data.begin(), data.end(),
      [](const AccountPointer &ptr1, const AccountPointer &ptr2) {
        return (ptr1->accountBalance() < ptr2->accountBalance());
      });
  if ((*ans)->accountDebitCard() == nullptr)
    return std::nullopt;
  return ((*ans)->accountDebitCard()->expiryDate());
}

CardContainer ReturnDebitCardPointers(const Container &data) {
  if (data.empty())
    throw std::runtime_error("Data is Empty!!!\n");
  Container temp(data.size());
  CardContainer result;

  std::copy(data.begin(), data.end(), temp.begin());

  std::for_each(temp.begin(), temp.end(), [&](const AccountPointer &ptr) {
    result.push_back(ptr->accountDebitCard());
  });

  return result;
}

/*
    Step 1: for all accounts where condition matches,
    copy the whole account into a temp container.

    Step 2: From the temp container,extract the debitcard attribute and place
    in the result container.
*/
std::optional<CardContainer>
ReturnNonNullDebitCardPointers(const Container &data) {
  if (data.empty()) {
    throw std::runtime_error("Container is empty\n");
  }
  Container temp(
      data.size()); // To avoid segmentation fault you need to intialize
  CardContainer result;
  // Don't put random size
  std::copy_if(data.begin(), data.end(), temp.begin(),
               [](const AccountPointer &ptr) {
                 if (ptr->accountDebitCard() != nullptr)
                   return true;
                 return false;
               });

  std::for_each(temp.begin(), temp.end(), [&](const AccountPointer &ptr) {
    result.push_back(ptr->accountDebitCard());
  });
  if (result.empty()) {
    return std::nullopt;
  }
  return result;

  /*
      //alternative
      std::for_each(
          data.begin(),
          data.end(),
          [&](const AccountPointer& ptr)
          {
              if(ptr->accountDebitCard()!=nullptr)
              {
                  result.push_back(ptr->accountDebitCard());
              }
          }
      );
      this code violates the 17 rules
      twice the func call for doing the same thing in ptr->accountDebitCard()
      if we use temp, this is not a functional style
  */
}

std::optional<Container> FindMatchingAccounts(const Container &data) {
  if (data.empty())
    std::runtime_error("Data is Empty!!!\n");
  Container result(data.size());

  auto itr = std::copy_if(data.begin(), data.end(), result.begin(),
                          [](const AccountPointer &ptr) {
                            return (ptr->accountBalance() > 30000 &&
                                    ptr->accountDebitCard() != nullptr);
                          });
  std::size_t newSize =
      std::distance(result.begin(), itr); // used to subtract two same objects
  result.resize(newSize);
  if (result.empty())
    return std::nullopt;
  return result;
}

/*
If default constructor is deleted or segmentation fault means that data
intitalization of memory is not happening as in line 129 data.size() solves
error

If there is direct copy it is fine.If it has to return a container based on a
condition data resizing is must

If you want to copy whole object normal copy process can be done. If Condition
Based copy process need to be changed.
*/