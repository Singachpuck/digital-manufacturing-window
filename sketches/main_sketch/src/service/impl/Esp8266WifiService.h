#ifndef UNIT_TEST_DEFAULTWIFISERVICE_H
#define UNIT_TEST_DEFAULTWIFISERVICE_H

//#include "../WifiService.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <cstdint>

#include "../../../config.h"
#include "../IWifiService.h"

class Esp8266WifiService : public IWifiService {
public:
    /**
     * Tries to connect to WiFi n_retries times.
     * @param n_retries number of retries.
     * @return returns the status of connection after n_retries tries.
     */
    uint8_t connectToWiFi(int n_retries);
};


#endif //UNIT_TEST_DEFAULTWIFISERVICE_H
