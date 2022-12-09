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
  {1, 2, RELAY_TRIGGER_LOW, -1, "Sypialnia Łóżko"}, //A0, 12(23) Ośw. Sypialnia nad łóżkiem
  {2, 3, RELAY_TRIGGER_LOW, -1, "Sypialnia TV"}, //A1, 7(22) Ośw. Sypialnia nad TV Spot.5
  {3, 4, RELAY_TRIGGER_LOW, -1, "Garderoba Syp"},  //A2, 13(24) Ośw. Garderoba przy sypialni
  {4, 5, RELAY_TRIGGER_LOW, -1, "Ana Łóżko"},  //A3, 10(21) Ośw. Ana nad łóżkiem
  {5, 6, RELAY_TRIGGER_LOW, -1, "Ana Biurko"},   //A4, 11(20) Ośw. Ana nad biurkiem Spot.3
  {6, 7, RELAY_TRIGGER_LOW, -1, "Mati Biurko"},  //A5, 15(17) Ośw. Mati nad biurkiem 3x
  {7, 8, RELAY_TRIGGER_LOW, -1, "Mati Łóżko"},  //A6, 14(16) Ośw. Mati nad łóżkiem Spot.3
  {8, 9, RELAY_TRIGGER_LOW, -1, "Łazienka Duża"},  //A7, 17(19) Ośw. Łazienka duża
  {9, 10, RELAY_TRIGGER_LOW, -1, "Łazienka Wanna"},  //A8, 16(18) Ośw. Łazienka duża nad wanną 2x
  {10, 11, RELAY_TRIGGER_LOW, -1, "Hal Korytarz"},  //A9, 59(10) Ośw. Hal Korytarz Spot.7
  {11, 12, RELAY_TRIGGER_LOW, -1, "Led Hal"},  //A10, 55-57(LedHal) Ośw. Led Hal 
  {12, 13, RELAY_TRIGGER_LOW, -1, "Salon 1"},  //A11, 62(8) Ośw. Salon nad kanapą 
  {13, 14, RELAY_TRIGGER_LOW, -1, "Salon 2"},  //A12, 63(9) Ośw. Salon nad TV 
  {14, 15, RELAY_TRIGGER_LOW, -1, "Salon Kinkiety"},  //A13, 58(C11) Ośw. Salon kinkiety 4x
  {15, 16, RELAY_TRIGGER_LOW, -1, "Jadalnia Stół"},  //A14, 65(6) Ośw. Jadalnia nad stołem
  {16, 17, RELAY_TRIGGER_LOW, -1, "Jadalnia Hal"}, //A15, 64(3) Ośw. Jadalnia Hal Spot.6
  {17, 18, RELAY_TRIGGER_LOW, -1, "Jadalnia Piano"},  //38, 67(2) Ośw. Jadalnia Pianino Spot.5
  {18, 19, RELAY_TRIGGER_LOW, -1, "Kuchnia"},  //39, 66(4) Ośw. Kuchnia Spot.6
  {19, 20, RELAY_TRIGGER_LOW, -1, "Kuchnia Stolik"},  //40, 69(7) Ośw. Kuchnia nad stolikiem 3x
  {20, 23, RELAY_TRIGGER_LOW, -1, "Spiżarnia"},  //41, 68(5) Ośw. Spiżarnia
  {21, 24, RELAY_TRIGGER_LOW, -1, "Łazienka Mała"},  //42, 8(29) Ośw. Łazienka mała Spot.3
  {22, 25, RELAY_TRIGGER_LOW, -1, "Wiatrołap"}, //43, 60(1) Ośw. Wiatrołap
  {23, 26, RELAY_TRIGGER_LOW, -1, "Garderoba Wiatr"}, //44, 61(12) Ośw. Garderoba przy wiatrołapie
  {24, 27, RELAY_TRIGGER_LOW, -1, "Garaż 1"},  //45, 37(14) Ośw. Garaż Spot.4
  {25, 28, RELAY_TRIGGER_LOW, -1, "Garaż 2"},  //46, 36(13) Ośw. Garaż Spot.3
  {26, 29, RELAY_TRIGGER_LOW, -1, "Kotłownia"}, //47, 38(15) Ośw. Kotłownia Spot.3
  {27, 30, RELAY_TRIGGER_LOW, -1, "Kinkiety Łazienka"}, //48, 9(C-27,28) Kinkiey Łazienka Duża
  {28, 31, RELAY_TRIGGER_LOW, -1, "Poddasze"}, //49, 39(30) Ośw. Poddasze
  {29, 32, RELAY_TRIGGER_LOW, -1, "Ganek Wejście"}, //50, 78(Z8) Ośw. Wejście Dom
  {30, 33, RELAY_TRIGGER_LOW, -1, "Taras Góra"}, //51, 79(Z9) Ośw. Taras Góra
  {31, 34, RELAY_TRIGGER_LOW, -1, "Elewacja Dom"}, //52, Ośw. Elewacji domu
  {32, 35, RELAY_TRIGGER_LOW, -1, "WOLNY"}  //53, Wolny przekaźnik




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
  {A0,  MONO_STABLE, 1,  -1, -1, "BUTTON 1"},
  {A1,  MONO_STABLE, 2,  -1, -1, "BUTTON 2"},
  {A2,  MONO_STABLE, 3,  -1, -1, "BUTTON 3"},
  {A3,  MONO_STABLE, 4,  -1, -1, "BUTTON 4"},
  {A4,  MONO_STABLE, 5,  -1, -1, "BUTTON 5"},
  {A5,  MONO_STABLE, 6,  -1, -1, "BUTTON 6"},
  {A6,  MONO_STABLE, 7,  -1, -1, "BUTTON 7"},
  {A7,  MONO_STABLE, 8,  -1, -1, "BUTTON 8"},
  {A8,  MONO_STABLE, 9,  -1, -1, "BUTTON 9"},
  {A9,  MONO_STABLE, 10,  -1, -1, "BUTTON 10"},
  {A10,  MONO_STABLE, 11,  -1, -1, "BUTTON 11"},
  {A11,  MONO_STABLE, 12,  -1, -1, "BUTTON 12"},
  {A12,  MONO_STABLE, 13,  -1, -1, "BUTTON 13"},
  {A13,  MONO_STABLE, 14,  -1, -1, "BUTTON 14"},
  {A14,  MONO_STABLE, 15,  -1, -1, "BUTTON 15"},
  {A15,  MONO_STABLE, 16,  -1, -1, "BUTTON 16"},
  {38,  MONO_STABLE, 17,  -1, -1, "BUTTON 17"},
  {39,  MONO_STABLE, 18,  -1, -1, "BUTTON 18"},
  {40,  MONO_STABLE, 19,  -1, -1, "BUTTON 19"},
  {41,  MONO_STABLE, 20,  -1, -1, "BUTTON 20"},
  {42,  MONO_STABLE, 21,  -1, -1, "BUTTON 21"},
  {43,  MONO_STABLE, 22,  -1, -1, "BUTTON 22"},
  {44,  MONO_STABLE, 23,  -1, -1, "BUTTON 23"},
  {45,  MONO_STABLE, 24,  -1, -1, "BUTTON 24"},
  {46,  MONO_STABLE, 25,  -1, -1, "BUTTON 25"},
  {47,  MONO_STABLE, 26,  -1, -1, "BUTTON 26"},
  {48,  MONO_STABLE, 27,  -1, -1, "BUTTON 27"},
  {49,  MONO_STABLE, 28,  -1, -1, "BUTTON 28"},
  {50,  MONO_STABLE, 29,  -1, -1, "BUTTON 29"},
  {51,  MONO_STABLE, 30,  -1, -1, "BUTTON 30"},
  {52,  MONO_STABLE, 31,  -1, -1, "BUTTON 31"},
  {53,  MONO_STABLE, 32,  -1, -1, "BUTTON 32"}
    
  //{A3,  BI_STABLE,   4,  -1, -1, "BUTTON 4"},
  //{A4,  BI_STABLE,   5,  -1,  2, "BUTTON 5"},
  //{A5,  REED_SWITCH, 8,  -1, -1, "BUTTON 6"}
};

