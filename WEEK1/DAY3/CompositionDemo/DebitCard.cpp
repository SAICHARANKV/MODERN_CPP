#include "DebitCard.h"
#include <memory>

DebitCard::DebitCard(unsigned short cvv, long cardNumber, std::string &&expiryDate, DebitCardType cardType)
    : _cvv(cvv), _cardNumber(cardNumber), _expiryDate(std::move(expiryDate)), _cardType(cardType)
{
}