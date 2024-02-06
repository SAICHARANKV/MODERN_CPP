#include "Response.hpp"
#
std::ostream &operator<<(std::ostream &os, const Response &rhs)
{
    os << "_responseString: " << rhs._responseString
       << " _responseStatusCode: " << rhs._responseStatusCode
       << " _responseTimeElapsed: " << rhs._responseTimeElapsed;
    return os;
}
Response::Response(std::string responseString, long responseCode, double responseTimeElapsed)
    : _responseString(responseString),
      _responseStatusCode(responseCode),
      _responseTimeElapsed(responseTimeElapsed)
{
}
