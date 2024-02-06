#include <iostream>
#include "Request.hpp"
int main()
{
    std::string _url = "https://min-api.cryptocompare.com/data/price?fsym=BTC&tsyms=USD,JPY,EUR,INR";

    std::shared_ptr<Request> requestPtr = std::make_shared<Request>(_url);

    std::shared_ptr<Response> responsePtr = requestPtr->ExecuteApiCall();

    std::cout << "API RETURNS: "
              << responsePtr->responseString()
              <<"\n";

    std::cout << "API CALL STATUS CODE : "
              << responsePtr->responseStatusCode()
              <<"\n";

    std::cout << "API CALL TIME TAKEN: "
              << responsePtr->responseTimeElapsed()
              <<"\n";
    return 0;
}