#ifndef INSUFFICIENTBALANCEEXCEPTION_H
#define INSUFFICIENTBALANCEEXCEPTION_H

#include <iostream>
#include <cstring>

class InSufficientBalanceException : public std::exception
{
private:
    char *_msg;

public:
    InSufficientBalanceException() = delete;
    InSufficientBalanceException(const InSufficientBalanceException &) = delete;
    InSufficientBalanceException &operator=(const InSufficientBalanceException &) = delete;
    InSufficientBalanceException(InSufficientBalanceException &&) = delete;
    InSufficientBalanceException &operator=(InSufficientBalanceException &&) = delete;

    InSufficientBalanceException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    virtual const char *what()
    {
        return _msg;
    }
    ~InSufficientBalanceException()
    {
        delete _msg;
    }
};

#endif // INSUFFICIENTBALANCEEXCEPTION_H
