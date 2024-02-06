#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <string>
#include <cstring>
class IdNotFoundException : public std::exception
{
private:
    char *_msg;

public:
    IdNotFoundException() = delete;
    explicit IdNotFoundException(const char *msg)
    {
        _msg = new char[strlen(msg)+1]; // (char*) malloc(strlen(msg)+1);
        strcpy(_msg,msg);
    }
    IdNotFoundException(const IdNotFoundException &) = default;
    IdNotFoundException &operator=(const IdNotFoundException &) = default;
    IdNotFoundException(IdNotFoundException &&) = default;
    IdNotFoundException &operator=(IdNotFoundException &&) = delete;
    ~IdNotFoundException() = default;

    virtual const char *what() { return _msg; }
};

#endif // IDNOTFOUNDEXCEPTION_H
