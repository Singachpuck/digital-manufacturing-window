#ifndef HTTPSERVICE_H
#define HTTPSERVICE_H

#include <string>

class HttpService {
public:
    virtual std::string httpGetJson(std::string serverName) = 0;
};


#endif //HTTPSERVICE_H
