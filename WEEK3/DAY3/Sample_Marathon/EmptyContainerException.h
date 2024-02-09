#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <iostream>
#include <string>
#include <cstring>
class EmptyContainerException : public std::exception
{
private:
   char *_msg;

public:
    EmptyContainerException() = delete;
    explicit EmptyContainerException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    EmptyContainerException(const EmptyContainerException &) = default;
    EmptyContainerException(EmptyContainerException &&) = delete;
    EmptyContainerException &operator=(EmptyContainerException &&) = delete;
    EmptyContainerException &operator=(const EmptyContainerException &) = default;
    ~EmptyContainerException() = default;
    virtual const char *what()
    {
        return _msg;
    };
};

#endif // EMPTYCONTAINEREXCEPTION_H
