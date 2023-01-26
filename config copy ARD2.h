// for development purposes copy "config.h.sample" into "config.h" file or use link:
// - Windows 10 (PowerShell) as admin: Start-Process -FilePath "$env:comspec" -ArgumentList "/k", "mklink", "config.h","config.h.sample" -Verb RunAs
// For production you can customize "config.h" or use link to "config.h.local":
// - Start-Process -FilePath "$env:comspec" -ArgumentList "/k", "mklink", "config.h","config.h.local" -Verb RunAs
// Alternative version:
// Start-Process -Verb RunAs -FilePath "powershell" -ArgumentList "-NoExit","-command","New-Item -Path '$(Get-Location)\include\config.h' -ItemType SymbolicLink -Value '$(Get-Location)\include\config.h.sample'"


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

const char MULTI_RELAY_DESCRIPTION[] PROGMEM = "Przekazniki";

// Relays config - ID and PIN MUST BE UNIQUE (can't be repeated)!
// Row params: relay ID - [0-254] sensor ID reported on MySensor Gateway
//             relay pin - pin used for relay, can be expander pin via "E(x, y)" macro
//             relay options - [RELAY_TRIGGER_LOW|RELAY_TRIGGER_HIGH] {RELAY_STARTUP_ON|RELAY_STARTUP_OFF} {RELAY_IMPULSE}
//             relay dependOn - ID of relay that needs to be turned on before this one
//             relay description - reported on MySensor Gateway, can help identify device on initial configuration in Home Automation App, max. 30 chars, can be empty ("")
const RelayConfigDef gRelayConfig[] PROGMEM = {
  {33, 2, RELAY_TRIGGER_HIGH | RELAY_IMPULSE, -1, "Brama Garaż"}, //A0, 43 Brama Garażowa
  {34, 3, RELAY_TRIGGER_HIGH, -1, "Drzwi Garaż"},
  {35, 4, RELAY_TRIGGER_HIGH, -1, "Drzwi Spiżarnia"},
  {36, 5, RELAY_TRIGGER_HIGH, -1, "Drzwi ŁazienkaD"},
  {37, 6, RELAY_TRIGGER_HIGH, -1, "Drzwi ŁazienkaM"},
  {38, 7, RELAY_TRIGGER_HIGH, -1, "Drzwi Garderoba"},
  {39, 8, RELAY_TRIGGER_LOW, -1, "Zalanie ŁazienkaD"},
  {40, 9, RELAY_TRIGGER_LOW, -1, "Zalanie ŁazienkaM"},
  {41, 10, RELAY_TRIGGER_LOW, -1, "Zalanie Kotłownia"},
  {42, 11, RELAY_TRIGGER_LOW, -1, "Zalanie Kuchnia"},
  {43, 12, RELAY_TRIGGER_LOW, -1, "Czujka Hal"},
  {44, 13, RELAY_TRIGGER_LOW, -1, "Czujka Jadalnia"},
  {45, 14, RELAY_TRIGGER_LOW, -1, "RELAY 45"},
  {46, 15, RELAY_TRIGGER_LOW, -1, "RELAY 46"},
  {47, 16, RELAY_TRIGGER_LOW, -1, "RELAY 47"},
  {48, 17, RELAY_TRIGGER_LOW, -1, "RELAY 48"}
  

  //{6, 7, RELAY_TRIGGER_LOW | RELAY_STARTUP_OFF, -1, "RELAY 6"},
  //{7, 8, RELAY_TRIGGER_LOW | RELAY_STARTUP_ON, -1, "RELAY 7"},
  //{8, 9, RELAY_TRIGGER_LOW, -1, "RELAY 8"}
};

// Buttons config
// Row params: button pin - pin used for button, can be expander pin (but NOT RECOMMENDED) via "E(x, y)" macro
//             button type - [MONO_STABLE|BI_STABLE|DING_DONG|REED_SWITCH]
//             click action relay ID - MUST be defined in gRelayConfig
//             long-press action relay ID - ignored for BI_STABLE, DING_DONG, REED_SWITCH
//             double-click action relay ID - ignored for DING_DONG, REED_SWITCH
//             button description - debug only, max. 30 chars, can be empty ("")
const ButtonConfigDef gButtonConfig[] PROGMEM = {
  {A0,  MONO_STABLE, 33,  -1, -1, "Brama Garaż"},
  {A1,  REED_SWITCH, 34,  -1, -1, "Drzwi Garaż"},
  {A2,  REED_SWITCH, 35,  -1, -1, "Drzwi Spiżarnia"},
  {A3,  REED_SWITCH, 36,  -1, -1, "Drzwi ŁazienkaD"},
  {A4,  REED_SWITCH, 37,  -1, -1, "Drzwi ŁazienkaM"},
  {A5,  REED_SWITCH, 38,  -1, -1, "Drzwi Garderoba"},
  {A6,  DING_DONG, 39,  -1, -1, "Zalanie ŁazienkaD"},
  {A7,  DING_DONG, 40,  -1, -1, "Zalanie ŁazienkaM"},
  {A8,  DING_DONG, 41,  -1, -1, "Zalanie Kotłownia"},
  {A9,  DING_DONG, 42,  -1, -1, "Zalanie Kuchnia"},
  {A10,  DING_DONG, 43,  -1, -1, "Czujka Hal"},
  {A11,  DING_DONG, 44,  -1, -1, "Czujka Jadalnia"},
  {A12,  MONO_STABLE, 45,  -1, -1, "BUTTON 45"},
  {A13,  MONO_STABLE, 46,  -1, -1, "BUTTON 46"},
  {A14,  MONO_STABLE, 47,  -1, -1, "BUTTON 47"},
  {A15,  MONO_STABLE, 48,  -1, -1, "BUTTON 48"}

};

