// For mono-stable buttons it will trigger state: LOW - when button is pressed, HIGH - when button is released
const uint8_t MONO_STABLE_TRIGGER = LOW;

// time interval for RELAY_IMPULSE type relay, ignored when button type is DING_DONG or REED_SWITCH
const unsigned long RELAY_IMPULSE_INTERVAL = 250;

// debounce interval in milliseconds
const unsigned long BUTTON_DEBOUNCE_INTERVAL = 50;

// double-click interval in milliseconds
const unsigned long BUTTON_DOUBLE_CLICK_INTERVAL = 350;

// long-press interval in milliseconds
const unsigned long BUTTON_LONG_PRESS_INTERVAL = 800;

#ifdef USE_EXPANDER
  const uint8_t gExpanderAddresses[] = {0x20};
#endif

const char MULTI_RELAY_DESCRIPTION[] PROGMEM = "ARD2";

// Relays config - ID and PIN MUST BE UNIQUE (can't be repeated)!
// Row params: relay ID - [0-254] sensor ID reported on MySensor Gateway
//             relay pin - pin used for relay, can be expander pin via "E(x, y)" macro
//             relay options - [RELAY_TRIGGER_LOW|RELAY_TRIGGER_HIGH] {RELAY_STARTUP_ON|RELAY_STARTUP_OFF} {RELAY_IMPULSE}
//             relay dependOn - ID of relay that needs to be turned on before this one
//             relay description - reported on MySensor Gateway, can help identify device on initial configuration in Home Automation App, max. 30 chars, can be empty ("")
const RelayConfigDef gRelayConfig[] PROGMEM = {
  {50, 2, RELAY_TRIGGER_HIGH | RELAY_IMPULSE, -1, "Brama Garaż"}, //A0, 43 Brama Garażowa
  {51, 3, RELAY_TRIGGER_HIGH, -1, "Drzwi Garaż"},
  {52, 4, RELAY_TRIGGER_HIGH, -1, "Drzwi Spiżarnia"},
  {53, 5, RELAY_TRIGGER_HIGH, -1, "Drzwi ŁazienkaD"},
  {54, 6, RELAY_TRIGGER_HIGH, -1, "Drzwi ŁazienkaM"},
  {55, 7, RELAY_TRIGGER_HIGH, -1, "Drzwi Garderoba"},
  {56, 8, RELAY_TRIGGER_HIGH, -1, "Drzwi GardWiatrołap"},
  {57, 9, RELAY_TRIGGER_LOW, -1, "Zalanie ŁazienkaD"},
  {58, 10, RELAY_TRIGGER_LOW, -1, "Zalanie ŁazienkaM"},
  {59, 11, RELAY_TRIGGER_LOW, -1, "Zalanie Kotłownia"},
  {60, 12, RELAY_TRIGGER_LOW, -1, "Zalanie Kuchnia"},
  {61, 13, RELAY_TRIGGER_LOW, -1, "Czujka Hal"},
  {62, 14, RELAY_TRIGGER_LOW, -1, "Czujka Jadalnia"},
  {63, 15, RELAY_TRIGGER_LOW, -1, "Czujka Spiżarnia"},
  {64, 16, RELAY_TRIGGER_LOW, -1, "Czujka Garderoba"},
  {65, 17, RELAY_TRIGGER_LOW, -1, "Czujka GardWiatrołap"},
  {66, 18, RELAY_TRIGGER_LOW, -1, "Czujka ŁazienkaM"},
  {67, 19, RELAY_TRIGGER_LOW, -1, "Przekaźnik 1"},
  {68, 20, RELAY_TRIGGER_LOW, -1, "Przekaźnik 2"},
  {69, 23, RELAY_TRIGGER_LOW, -1, "Przekaźnik 3"},
  {70, 24, RELAY_TRIGGER_LOW, -1, "Przekaźnik 4"},
  {71, 25, RELAY_TRIGGER_LOW, -1, "Przekaźnik 5"},
  {72, 26, RELAY_TRIGGER_LOW, -1, "Przekaźnik 6"},
  {73, 27, RELAY_TRIGGER_LOW, -1, "Przekaźnik 7"},
  {74, 28, RELAY_TRIGGER_LOW, -1, "Przekaźnik 8"},
  {75, 29, RELAY_TRIGGER_LOW, -1, "Przekaźnik 9"},
  {76, 30, RELAY_TRIGGER_LOW, -1, "Przekaźnik 10"}
  
};

// Buttons config
// Row params: button pin - pin used for button, can be expander pin (but NOT RECOMMENDED) via "E(x, y)" macro
//             button type - [MONO_STABLE|BI_STABLE|DING_DONG|REED_SWITCH]
//             click action relay ID - MUST be defined in gRelayConfig
//             long-press action relay ID - ignored for BI_STABLE, DING_DONG, REED_SWITCH
//             double-click action relay ID - ignored for DING_DONG, REED_SWITCH
//             button description - debug only, max. 30 chars, can be empty ("")
const ButtonConfigDef gButtonConfig[] PROGMEM = {
  {A0,  MONO_STABLE, 50,  -1, -1, "Brama Garaż"},
  {A1,  REED_SWITCH, 51,  -1, -1, "Drzwi Garaż"},
  {A2,  REED_SWITCH, 52,  -1, -1, "Drzwi Spiżarnia"},
  {A3,  REED_SWITCH, 53,  -1, -1, "Drzwi ŁazienkaD"},
  {A4,  REED_SWITCH, 54,  -1, -1, "Drzwi ŁazienkaM"},
  {A5,  REED_SWITCH, 55,  -1, -1, "Drzwi Garderoba"},
  {A6,  REED_SWITCH, 56,  -1, -1, "Drzwi GardWiatrołap"},
  {A7,  DING_DONG, 57,  -1, -1, "Zalanie ŁazienkaD"},
  {A8,  DING_DONG, 58,  -1, -1, "Zalanie ŁazienkaM"},
  {A9,  DING_DONG, 59,  -1, -1, "Zalanie Kotłownia"},
  {A10,  DING_DONG, 60,  -1, -1, "Zalanie Kuchnia"},
  {A11,  DING_DONG, 61,  -1, -1, "Czujka Hal"},
  {A12,  DING_DONG, 62,  -1, -1, "Czujka Jadalnia"},
  {A13,  DING_DONG, 63,  -1, -1, "Czujka Spiżarnia"},
  {A14,  DING_DONG, 64,  -1, -1, "Czujka Garderoba"},
  {A15,  DING_DONG, 65,  -1, -1, "Czujka GardWiatrołap"},
  {38,  DING_DONG, 66,  -1, -1, "Czujka ŁazienkaM"},
  {39,  MONO_STABLE, 67,  -1, -1, "Przycisk 1"},
  {40,  MONO_STABLE, 68,  -1, -1, "Przycisk 2"},
  {41,  MONO_STABLE, 69,  -1, -1, "Przycisk 3"},
  {42,  MONO_STABLE, 70,  -1, -1, "Przycisk 4"},
  {43,  MONO_STABLE, 71,  -1, -1, "Przycisk 5"},
  {44,  MONO_STABLE, 72,  -1, -1, "Przycisk 6"},
  {45,  MONO_STABLE, 73,  -1, -1, "Przycisk 7"},
  {46,  MONO_STABLE, 74,  -1, -1, "Przycisk 8"},
  {47,  MONO_STABLE, 75,  -1, -1, "Przycisk 9"},
  {48,  MONO_STABLE, 76,  -1, -1, "Przycisk 10"}

};


// WIFI SSID and password
#define MY_WIFI_SSID "<YOUR WIFI NAME>"
#define MY_WIFI_PASSWORD "<YOUR WIFI PASSWORD>"

// Hostname for the WiFi Client. This is the hostname passed to the DHCP server if not static.
#define MY_HOSTNAME "MULTI_RELAY_2"

// Enable MY_IP_ADDRESS here if you want a static ip address (no DHCP)
//#define MY_IP_ADDRESS 192,168,178,87

// If using static ip you can define Gateway and Subnet address as well
//#define MY_IP_GATEWAY_ADDRESS 192,168,178,1
//#define MY_IP_SUBNET_ADDRESS 255,255,255,0

// MAC address can be anything you want but should be unique on your network
//#define MY_MAC_ADDRESS 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED

// Enable MQTT communication (must be commented out for serial and TCP/UDP communication)
//#define MY_GATEWAY_MQTT_CLIENT

#ifdef MY_GATEWAY_MQTT_CLIENT
  // Node's subscribe and publish topic prefix
  #define MY_MQTT_PUBLISH_TOPIC_PREFIX "multi-relay/out"
  #define MY_MQTT_SUBSCRIBE_TOPIC_PREFIX "multi-relay/in"

  // MQTT client id
  #define MY_MQTT_CLIENT_ID "multi-relay-2"

  // Enable these if your MQTT broker requires username/password
  //#define MY_MQTT_USER "<YOUR MQTT USERNAME>"
  //#define MY_MQTT_PASSWORD "<YOUR MQTT PASSWORD>"

  // MQTT broker ip address
  #define MY_CONTROLLER_IP_ADDRESS 192,168,178,17

  // MQTT broker if using URL instead of ip address
  // #define MY_CONTROLLER_URL_ADDRESS "test.mosquitto.org"

  // MQTT broker port (default 1883)
  //#define MY_PORT 1883
#else
  // The Ethernet TCP/UDP port to open on controller or gateway (default 5003).
  //#define MY_PORT 5003
#endif
