#include "Args.h"

#include "Util.h"

#include <assert.h>

static bool Check(const char* const arg, const char* const hyphen, const char* const full)
{
    return Util_StringEqual(arg, full)
        || Util_StringEqual(arg, hyphen);
}

Args Args_Parse(const int32_t argc, const char* argv[])
{
    static Args zero;
    Args args = zero;
    args.path = "/home/gl/.steam/steam/steamapps/common/Age2HD/Directory/data/";
    args.color = COLOR_BLU;
    args.host = "localhost";
    args.port = 1234;
    args.port_ping = args.port + 1;
    args.xres = 800;
    args.yres = 600;
    args.users = 1;
    args.civ = CIV_NORTH_EUROPE;
    for(int32_t i = 0; i < argc; i++)
    {
        const char* const arg = argv[i];
        const char* const next = argv[i + 1];
        if(Check(arg, "-c", "--color" )) args.color = (Color) atoi(next);
        if(Check(arg, "-p", "--path"  )) args.path = next;
        if(Check(arg, "-s", "--server")) args.is_server = true;
        if(Check(arg, "-x", "--xres"  )) args.xres = atoi(next);
        if(Check(arg, "-y", "--yres"  )) args.yres = atoi(next);
        if(Check(arg, "-u", "--users" )) args.users = atoi(next);
        if(Check(arg, "-q", "--quiet" )) args.quiet = true;
        if(Check(arg, "-v", "--civ"   )) args.civ = (Civ) atoi(next);
        if(Check(arg, "-d", "--demo"  )) args.demo = true;
    }
    assert(args.path);
    return args;
}
