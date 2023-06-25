#ifndef WIFISERVICE_H
#define WIFISERVICE_H

#include <cstdint>

class IWifiService {
public:
    virtual uint8_t connectToWiFi(int n_retries) = 0;
};


#endif //WIFISERVICE_H
