#include "DebitCard.h"
//#include <memory>

DebitCard::DebitCard(unsigned short cvv, long cardNumber, std::string expiryDate, DebitCardType cardType)
    : _cvv(cvv), _cardNumber(cardNumber), _expiryDate(expiryDate), _cardType(cardType)
{
}
std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
    os << "_cvv: " << rhs._cvv<<"\n"
       << " _cardNumber: " << rhs._cardNumber<<"\n"
       << " _cardType: " <<static_cast<int>(rhs._cardType) <<"\n"
       << " _expiryDate: " << rhs._expiryDate;
    return os;
}
