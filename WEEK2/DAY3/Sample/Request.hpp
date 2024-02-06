#ifndef REQUEST_HPP
#define REQUEST_HPP
#include <string>
#include <curl/curl.h>
#include <memory>
#include <ostream>
#include "Response.hpp"
// this class cannot be used as "Parent" for Inheritance
class Request final
{
private:
    std::string _apiEndPointUrl;
    std::shared_ptr<CURL> _curlSession;

public:
    /* Enablers and Disablers */
    Request() = delete;
    ~Request() = default;
    Request(const Request &) = delete;
    Request(Request &&) = delete;
    Request &operator=(const Request &) = delete;
    Request &operator=(const Request &&) = delete;

    /*
        Setter used as client might reuse one request object for
        subsequent api calls!!!
    */
    std::string apiEndPointUrl() const { return _apiEndPointUrl; }
    void setApiEndPointUrl(const std::string &apiEndPointUrl) { _apiEndPointUrl = apiEndPointUrl; }

    explicit Request(std::string url);
    /*
        this will help in displaying the request object for debugging and logging purposes
    */
    std::shared_ptr<Response> ExecuteApiCall();
    friend std::ostream &operator<<(std::ostream &os, const Request &rhs);
};

#endif // REQUEST_HPP
