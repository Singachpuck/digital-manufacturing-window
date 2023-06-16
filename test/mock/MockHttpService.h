#ifndef MOCKHTTPSERVICE_H
#define MOCKHTTPSERVICE_H

#include "gmock/gmock.h"

#include "service/HttpService.h"

class MockHttpService : public HttpService {
public:
    MOCK_METHOD(std::string, httpGetJson, (std::string serverName), (override));
};


#endif //MOCKHTTPSERVICE_H
