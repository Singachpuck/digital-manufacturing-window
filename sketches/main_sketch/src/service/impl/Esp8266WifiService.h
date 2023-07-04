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
    uint8_t connectToWiFi(int n_retries);
};


#endif //UNIT_TEST_DEFAULTWIFISERVICE_H
