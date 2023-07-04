#ifndef WIFISERVICE_H
#define WIFISERVICE_H

#include <cstdint>

/**
 * Basic interface for wifi service.
 */
class IWifiService {
public:
    virtual uint8_t connectToWiFi(int n_retries) = 0;
};


#endif //WIFISERVICE_H
