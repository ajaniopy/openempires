#include "Interfac.h"

#include "Config.h"

const char* Interfac_GetString(const Interfac interfac)
{
#if CONFIG_DISABLE_STRINGS == 1
    switch(interfac)
    {
#define FILE_X(name, file, upgrade, prio, walkable, type, max_speed, health, attack, width, single_frame, multi_state, expire, inanimate, dimensions, action, detail, midding) case name: return #name;
        FILE_X_INTERFAC
#undef FILE_X
    }
#else
    (void) interfac;
#endif
    return "N/A";
}

uint8_t Interfac_GetHeight(const Interfac interfac)
{
    switch(interfac)
    {
#define FILE_X(name, file, upgrade, prio, walkable, type, max_speed, health, attack, width, single_frame, multi_state, expire, inanimate, dimensions, action, detail, midding) case name: return prio;
        FILE_X_INTERFAC
#undef FILE_X
    }
    return 0;
}
