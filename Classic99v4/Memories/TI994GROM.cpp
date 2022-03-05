// Classic99 v4xx - Copyright 2021 by Mike Brent (HarmlessLion.com)
// See License.txt, but the answer is "just ask me first". ;)

// This class emulates the GROMs attached to a TI-99/4 home computer

#include "ROMS.h"

#include "TI994GROM.h"
extern const uint8_t TI994GROMData[8192*3];

// not much needed for construction, except pointing to the data
TI994GROM::TI994GROM(Classic99System *core) 
    : Classic99GROM(core, TI994GROMData, 8192*3, 0)
{
    const uint8_t* ROM;
    uint ROMSIZE;

    switch (core->getRom())
    {
        case 1:
            ROM = CARWARSG;
            ROMSIZE = sizeof(CARWARSG);
        break;

        case 2:
            ROM = PARSECG;
            ROMSIZE = sizeof(PARSECG);
        break;

        case 3:
            ROM = TIEXTG;
            ROMSIZE = sizeof(TIEXTG);
        break;

        case 4:
            ROM = TunDoomG;
            ROMSIZE = sizeof(TunDoomG);
        break;

        case 5:
            ROM = TOMBCITG;
            ROMSIZE = sizeof(TOMBCITG);
        break;

        case 6:
            ROM = MunchMnG;
            ROMSIZE = sizeof(MunchMnG);
        break;

        case 7:
        default:
            ROM = DEMOG;
            ROMSIZE = sizeof(DEMOG);
            break;
    }

    LoadAdditionalData(ROM, ROMSIZE, 0x6000);
}

TI994GROM::~TI994GROM() {
}
