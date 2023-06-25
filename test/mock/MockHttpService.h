#ifndef MOCKHTTPSERVICE_H
#define MOCKHTTPSERVICE_H

#include "gmock/gmock.h"

#include "service/IHttpService.h"

class MockHttpService : public IHttpService {
public:
    MOCK_METHOD(std::string, httpGetJson, (std::string serverName), (override));
};

#endif //MOCKHTTPSERVICE_H
