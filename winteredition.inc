#if defined _winteredition_included
    #endinput
#endif

#define _winteredition_included
#pragma library winteredition

#if !defined _streamer_included
    #error Please include <streamer>.
#endif

#include "./src/we/we_snowobjects.inc"
#include "./src/we/we_snowfalling.inc"
#include "./src/we/we_snowcap.inc"
#include "./src/we/we_coldbreath.inc"

public OnPlayerConnect(playerid)
{
    snowFallingStatus[playerid] = false;
    snowCapStatus[playerid] = false;
    coldBreathStatus[playerid] = false;
    
    #if defined __WE_OnPlayerConnect
        return __WE_OnPlayerConnect(playerid);
    #else
        return 1;
    #endif
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect __WE_OnPlayerConnect
#if defined __WE_OnPlayerConnect
    forward __WE_OnPlayerConnect(playerid);
#endif