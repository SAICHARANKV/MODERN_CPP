#ifndef RESPONSE_HPP
#define RESPONSE_HPP
#include <string>
#include <ostream>

class Response
{
private:
    std::string _responseString{""};
    long _responseStatusCode{-1};
    double _responseTimeElapsed{0.0f};

public:
    /* Enablers and Disablers */
    Response() = default; // we r taking reference of already declared objects it needs to be default
    ~Response() = default;
    Response(const Response &) = delete;
    Response(Response &&) = delete;
    Response &operator=(const Response &) = delete;
    Response &operator=(const Response &&) = delete;

    Response(std::string responseString, long responseCode, double responseTimeElapsed);

    std::string responseString() const { return _responseString; }

    long responseStatusCode() const { return _responseStatusCode; }

    double responseTimeElapsed() const { return _responseTimeElapsed; }

    friend std::ostream &operator<<(std::ostream &os, const Response &rhs);
    friend class Request;
};

#endif // RESPONSE_HPP
