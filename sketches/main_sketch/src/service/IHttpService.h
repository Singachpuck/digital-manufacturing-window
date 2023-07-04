#ifndef HTTPSERVICE_H
#define HTTPSERVICE_H

#include <string>

/**
 * Basic interface for http service.
 */
class IHttpService {
public:
    virtual std::string httpGetJson(std::string serverName) = 0;
};


#endif //HTTPSERVICE_H
