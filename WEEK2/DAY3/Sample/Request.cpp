#include <iostream>
#include "Request.hpp"
                                  std::ostream &
                                  operator<<(std::ostream &os, const Request &rhs)
{
    os << "_apiEndPointUrl: " << rhs._apiEndPointUrl;
    return os;
}

Request::Request(std::string url)
    : _apiEndPointUrl(url), _curlSession(curl_easy_init(), curl_easy_cleanup)
{

    /*
    decide logic for writing data,
    saving this as a lambda function
    */
    auto fn = [](void *ptr, size_t size, size_t nmemb, std::string *data)
    {
        data->append((char *)ptr, size * nmemb);
        return size * nmemb;
    };
    // how will i save returning in my program's memory
    // pass pointer to a function that contains this logic
    // writefunction is used here
    curl_easy_setopt(
        _curlSession.get(),
        CURLOPT_WRITEFUNCTION,
        +fn);

    // url part is here
    curl_easy_setopt(_curlSession.get(), CURLOPT_URL, _apiEndPointUrl.c_str());
}

std::shared_ptr<Response> Request::ExecuteApiCall()
{
    std::shared_ptr<Response> resPtr = std::make_shared<Response>();

    // option to pass pointer to the response variable
    curl_easy_setopt(_curlSession.get(), CURLOPT_WRITEDATA, &resPtr->_responseString);
    curl_easy_perform(_curlSession.get());

    // now use these commands to map above other parameters
    curl_easy_getinfo(_curlSession.get(), CURLINFO_RESPONSE_CODE, &resPtr->_responseStatusCode);
    curl_easy_getinfo(_curlSession.get(), CURLINFO_TOTAL_TIME, &resPtr->_responseTimeElapsed);

    return resPtr;
}


