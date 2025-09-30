# omp-winter-edition

## Installation

Download *winteredition.inc* with **src** folder and put those files in your **include** folder!

Include in your code and begin using the library:

```c
#include <winteredition>
```

## Usage

### Functions
- Snowflakes
```c
CMD:snowflakes(playerid, const string: params[])
{
    Winter_SetSnowflakeStatus(playerid);
    return 1;
}
```

- Snow objects (LOS SANTOS :c)
```c
CMD:snowobjects(playerid, const string: params[])
{
    Winter_ShowSnowObjects(playerid);
    return 1;
}
```

- Winter cap
```c
CMD:cap(playerid, const string: params[])
{
    Winter_SetSnowCapStatus(playerid);
    return 1;
}
```

- Cold breath
```c
CMD:coldbreath(playerid, const string: params[])
{
    Winter_SetColdBreathStatus(playerid);
    return 1;
}
```
