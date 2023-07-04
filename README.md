# Interactive Window project

### Launch guide
To launch this project on your device you will have to:
1. Clone the following repository: https://github.com/Singachpuck/digital-manufacturing-window.git
2. Go to the Blynk dashboard (https://blynk.io/) and create web template that contains 2 switches linked with 2 datastreams (V0, V1).
    1. V0 - controls the listening mode state.
    2. V1 - controls the window state (open/close).
3. Create config.h file in the sketches/main_sketch folder that contains the following information:
    ```c++
    #ifndef CONFIG_H
    #define CONFIG_H
    
    #define BLYNK_TEMPLATE_ID "Id_of_Blynk_template"
    #define BLYNK_TEMPLATE_NAME "Template_name"
    #define BLYNK_AUTH_TOKEN "Blynk_auth_token"
    
    #define WIFI_SSID "ssid"
    #define WIFI_PWD "*****"
    
    #define WEATHER_API_ENDPOINT "http://api.weatherapi.com/v1"
    #define WEATHER_API_KEY "*****" // can be found in personal account on https://www.weatherapi.com/
    #define DEVICE_LOCATION "Rennes" // location for weather
    
    #endif // CONFIG_H
    ```
4. Launch Arduino IDE and open the main_sketch (verify if the code compiles).
5. Build a DC motor controller with 2 relays as shown in the guide: https://www.instructables.com/DC-Motor-Controller-With-Two-Relay/#step2
6. Connect the output wires to D0 and D1 pins of the ESP8266 board.
7. Upload the program to ESP8266 using Arduino IDE.
8. Control your model with Blynk web dashboard.