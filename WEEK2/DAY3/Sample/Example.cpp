#include <curl/curl.h>
#include <iostream>
#include <string>

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string *data)
{
    data->append((char *)ptr, size * nmemb); // no of memory bits =nmemb
    return size * nmemb;
}

int main(int argc, char **argv)
{
    // Step 1:  Intialize Session Object
    auto curl = curl_easy_init();

    // step 2: If Session Objecct is NOT NULL !!!
    if (curl)
    {
        // Options for URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://min-api.cryptocompare.com/data/price?fsym=BTC&tsyms=USD,JPY,EUR,INR");
        // curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        // curl_easy_setopt(curl, CURLOPT_USERPWD, "user:pass");
        // curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.42.0");
        // curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        // curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

        // string where returning data will be stored!!
        std::string response_string;

        // While  making a reques t, if any extra item needs to be pass
        //  Pass it here!!!
        std::string header_string;

        // Write Function is used here
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);

        // option to pass pointer to the response variable
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

        // option to pass pointer to the response variable
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

        char *url;          // use this url to fetch data!!!
        long response_code; // use this varaible store api response code
        double elapsed;     // time taken to completed the request

        /*
            NOW USE THESE COMMANDS TO MAP ABOVE VARIABLES
        */
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
        curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

        // Finally execute the api call
        curl_easy_perform(curl);

        // Freeup memory
        curl_easy_cleanup(curl);
        std::cout << response_string << std::endl;
        // Indicating exiting of program.
        curl = NULL;
    }
}