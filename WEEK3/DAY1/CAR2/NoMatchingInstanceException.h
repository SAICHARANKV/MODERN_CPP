#ifndef NOMATCHINGINSTANCEEXCEPTION_H
#define NOMATCHINGINSTANCEEXCEPTION_H

#include <string>
#include <cstring>
class NoMatchingInstanceException : public std::exception
{
private:
    char *_msg;

public:
    NoMatchingInstanceException() = delete;
    explicit NoMatchingInstanceException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    NoMatchingInstanceException(const NoMatchingInstanceException &) = default;
    NoMatchingInstanceException &operator=(const NoMatchingInstanceException &) = default;
    NoMatchingInstanceException(NoMatchingInstanceException &&) = default;
    NoMatchingInstanceException &operator=(NoMatchingInstanceException &&) = delete;
    ~NoMatchingInstanceException() = default;

    virtual const char *what() { return _msg; }
};

#endif // NOMATCHINGINSTANCEEXCEPTION_H
