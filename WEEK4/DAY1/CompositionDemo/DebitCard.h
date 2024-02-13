#ifndef DEBITCARD_H
#define DEBITCARD_H

#include <iostream>
#include <string>
#include "DebitCardType.h"

class DebitCard
{
private:
    unsigned short _cvv;
    long _cardNumber;
    DebitCardType _cardType;
    const std::string _expiryDate; // std::string &&_expiryDate

public:
    DebitCard() = delete;
    DebitCard(const DebitCard &) = delete;
    DebitCard &operator=(const DebitCard &) = delete;
    DebitCard(DebitCard &&) = delete; // Move constructor
    DebitCard &operator=(DebitCard &&) = delete;
    ~DebitCard() = default; //{ std::cout << "Card details have deleted : " << _cardNumber << "\n"; };
    DebitCard(unsigned short cvv, long cardNumber, std::string expiryDate, DebitCardType cardType);

    unsigned short cvv() const { return _cvv; }

    long cardNumber() const { return _cardNumber; }

    DebitCardType cardType() const { return _cardType; }

    std::string expiryDate() const { return _expiryDate; }


    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
};

#endif // DEBITCARD_H
