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

const char MULTI_RELAY_DESCRIPTION[] PROGMEM = "Multi Relay";

// Relays config - ID and PIN MUST BE UNIQUE (can't be repeated)!
// Row params: relay ID - [0-254] sensor ID reported on MySensor Gateway
//             relay pin - pin used for relay, can be expander pin via "E(x, y)" macro
//             relay options - [RELAY_TRIGGER_LOW|RELAY_TRIGGER_HIGH] {RELAY_STARTUP_ON|RELAY_STARTUP_OFF} {RELAY_IMPULSE}
//             relay dependOn - ID of relay that needs to be turned on before this one
//             relay description - reported on MySensor Gateway, can help identify device on initial configuration in Home Automation App, max. 30 chars, can be empty ("")
const RelayConfigDef gRelayConfig[] PROGMEM = {
  {33, 2, RELAY_TRIGGER_LOW, -1, "RELAY 33"},
  {34, 3, RELAY_TRIGGER_LOW, -1, "RELAY 34"},
  {35, 4, RELAY_TRIGGER_LOW, -1, "RELAY 35"},
  {36, 5, RELAY_TRIGGER_LOW, -1, "RELAY 36"},
  {37, 6, RELAY_TRIGGER_LOW, -1, "RELAY 37"},
  {38, 7, RELAY_TRIGGER_LOW, -1, "RELAY 38"},
  {39, 8, RELAY_TRIGGER_LOW, -1, "RELAY 39"},
  {40, 9, RELAY_TRIGGER_LOW, -1, "RELAY 40"},
  {41, 10, RELAY_TRIGGER_LOW, -1, "RELAY 41"},
  {42, 11, RELAY_TRIGGER_LOW, -1, "RELAY 42"},
  {43, 12, RELAY_TRIGGER_LOW, -1, "RELAY 43"},
  {44, 13, RELAY_TRIGGER_LOW, -1, "RELAY 44"},
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
  {A0,  MONO_STABLE, 33,  -1, -1, "BUTTON 33"},
  {A1,  MONO_STABLE, 34,  -1, -1, "BUTTON 34"},
  {A2,  MONO_STABLE, 35,  -1, -1, "BUTTON 35"},
  {A3,  MONO_STABLE, 36,  -1, -1, "BUTTON 36"},
  {A4,  MONO_STABLE, 37,  -1, -1, "BUTTON 37"},
  {A5,  MONO_STABLE, 38,  -1, -1, "BUTTON 38"},
  {A6,  MONO_STABLE, 39,  -1, -1, "BUTTON 39"},
  {A7,  MONO_STABLE, 40,  -1, -1, "BUTTON 40"},
  {A8,  MONO_STABLE, 41,  -1, -1, "BUTTON 41"},
  {A9,  MONO_STABLE, 42,  -1, -1, "BUTTON 42"},
  {A10,  MONO_STABLE, 43,  -1, -1, "BUTTON 43"},
  {A11,  MONO_STABLE, 44,  -1, -1, "BUTTON 44"},
  {A12,  MONO_STABLE, 45,  -1, -1, "BUTTON 45"},
  {A13,  MONO_STABLE, 46,  -1, -1, "BUTTON 46"},
  {A14,  MONO_STABLE, 47,  -1, -1, "BUTTON 47"},
  {A15,  MONO_STABLE, 48,  -1, -1, "BUTTON 48"}
  //{38,  MONO_STABLE, 48,  -1, -1, "BUTTON 49"},
  //{39,  MONO_STABLE, 18,  -1, -1, "BUTTON 50"},
  //{40,  MONO_STABLE, 19,  -1, -1, "BUTTON 51"},
  //{41,  MONO_STABLE, 20,  -1, -1, "BUTTON 20"},
  //{42,  MONO_STABLE, 21,  -1, -1, "BUTTON 21"},
  //{43,  MONO_STABLE, 22,  -1, -1, "BUTTON 22"},
  //{44,  MONO_STABLE, 23,  -1, -1, "BUTTON 23"},
  //{45,  MONO_STABLE, 24,  -1, -1, "BUTTON 24"},
  //{46,  MONO_STABLE, 25,  -1, -1, "BUTTON 25"},
  //{47,  MONO_STABLE, 26,  -1, -1, "BUTTON 26"},
  //{48,  MONO_STABLE, 27,  -1, -1, "BUTTON 27"},
  //{49,  MONO_STABLE, 28,  -1, -1, "BUTTON 28"},
  //{50,  MONO_STABLE, 29,  -1, -1, "BUTTON 29"},
  //{51,  MONO_STABLE, 30,  -1, -1, "BUTTON 30"},
  //{52,  MONO_STABLE, 31,  -1, -1, "BUTTON 31"},
  //{53,  MONO_STABLE, 32,  -1, -1, "BUTTON 32"}
    
  //{A3,  BI_STABLE,   4,  -1, -1, "BUTTON 4"},
  //{A4,  BI_STABLE,   5,  -1,  2, "BUTTON 5"},
  //{A5,  REED_SWITCH, 8,  -1, -1, "BUTTON 6"}
};

