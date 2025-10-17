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

static _WE_AllSettingsStatus[MAX_PLAYERS];

public OnPlayerConnect(playerid)
{
    _WE_AllSettingsStatus[playerid] = 0;

	if (Winter_GetColdBreathStatus(playerid))
		Winter_SetColdBreathStatus(playerid);
        
    if (Winter_GetSnowCapStatus(playerid))
        Winter_SetSnowCapStatus(playerid);
        
    if (Winter_GetSnowflakeStatus(playerid))
        Winter_SetSnowflakeStatus(playerid);
    
    #if defined __WE_OnPlayerConnect
        return __WE_OnPlayerConnect(playerid);
    #else
        return 1;
    #endif
}

stock Winter_GetAllStatus(const playerid) return _WE_AllSettingsStatus[playerid];
stock Winter_SetStatusAll(const playerid)
{
    new const bool: status = !Winter_GetAllStatus(playerid);
    if (!status)
    {
        if (Winter_GetColdBreathStatus(playerid))
            Winter_SetColdBreathStatus(playerid);
        
        if (Winter_GetSnowCapStatus(playerid))
            Winter_SetSnowCapStatus(playerid);
        
        if (Winter_GetSnowflakeStatus(playerid))
            Winter_SetSnowflakeStatus(playerid);
        
        if (Winter_GetSnowObjStatus(playerid))
            Winter_ShowSnowObjects(playerid);

        _WE_AllSettingsStatus[playerid] = 0;
        return 1;
    }

    if (!Winter_GetColdBreathStatus(playerid))
        Winter_SetColdBreathStatus(playerid);
    
    if (!Winter_GetSnowCapStatus(playerid))
        Winter_SetSnowCapStatus(playerid);
    
    if (!Winter_GetSnowflakeStatus(playerid))
        Winter_SetSnowflakeStatus(playerid);
    
    if (!Winter_GetSnowObjStatus(playerid))
        Winter_ShowSnowObjects(playerid);

    _WE_AllSettingsStatus[playerid] = 1;
    return 1;
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