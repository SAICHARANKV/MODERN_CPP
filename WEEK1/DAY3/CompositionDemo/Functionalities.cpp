#include "Functionalities.h"
#include "DebitCard.h"
#include <string>

void CreateObjects(Container &data)
{
    std::string _expiry= "12/27";

    data.push_back(std::make_shared<BankAccount>(
        "Saicharan",          // name
        AccountType::SAVINGS, // accounttype
        998392.0f,            // Balance
        // DebitCard
        std::make_shared<DebitCard>(111,                // cvv
                                    11234452311L,       // cardNumber
                                    _expiry,            // expiryDate
                                    DebitCardType::VISA // cardType
                                    )));

    data.push_back(std::make_shared<BankAccount>(
        "Kushal",             // name
        AccountType::CURRENT, // accounttype
        129992.0f,            // Balance
        // DebitCard
        std::make_shared<DebitCard>(124,                 // cvv
                                    18229383492L,        // cardNumber
                                    _expiry,             // expiryDate
                                    DebitCardType::RUPAY // cardType
                                    )));
}

void PrintDetails(Container &data)
{
    if (data.empty())
        std::cout << "No details available..."
                  << "\n";
    std::cout << "---------------------" << std::endl;
    // const used as no details will be changed
    // auto for using AccountPointer = std::shared_ptr<BankAccount>;
    for (const auto &account : data)
    {
        std::cout << "Account Holder: " << account->accountHolderName() << std::endl;
        std::cout << "Account Type: ";
        if (account->accounttype() ==AccountType::SAVINGS)
            std::cout << "SAVINGS" << std::endl;
        else if (account->accounttype() == AccountType::CURRENT)
            std::cout << "CURRENT" << std::endl;
        else if (account->accounttype() == AccountType::PENSION)
            std::cout << "PENSION" << std::endl;

        std::cout << "Balance: " << account->accountBalance() << std::endl;

        auto debitCard = account->accountDebitCard();
        if (debitCard)
        {
            std::cout << "Debit Card Details:" << std::endl;
            std::cout << "CVV: " << debitCard->cvv() << std::endl;
            std::cout << "Card Number: " << debitCard->cardNumber() << std::endl;
            std::cout << "Expiry Date: " << debitCard->expiryDate() << std::endl;
            std::cout << "Card Type: ";
            if (debitCard->cardType() == DebitCardType::VISA)
                std::cout << "VISA" << std::endl;
            else if (debitCard->cardType() == DebitCardType::MASTERCARD)
                std::cout << "MASTERCARD" << std::endl;
            else if (debitCard->cardType() == DebitCardType::RUPAY)
                std::cout << "RUPAY" << std::endl;
        }

        std::cout << "---------------------" << std::endl;
    }
}
