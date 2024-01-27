// pawn-easing-functions by alexchwoj

#if defined _pawn_easing_functions_included
	#endinput
#endif
#define _pawn_easing_functions_included

#include <a_samp>
#include <float>
#include <YSF>

#define MAX_ANIMATORS 1024
#define ANIMATORS_UPDATE_RATE 16
#define PI 3.14159265

#define EASE_IN_SINE __addressof(easeInSine)
#define EASE_OUT_SINE __addressof(easeOutSine)
#define EASE_IN_OUT_SINE __addressof(easeInOutSine)
#define EASE_IN_QUAD __addressof(easeInQuad)
#define EASE_OUT_QUAD __addressof(easeOutQuad)
#define EASE_IN_OUT_QUAD __addressof(easeInOutQuad)
#define EASE_IN_CUBIC __addressof(easeInCubic)
#define EASE_OUT_CUBIC __addressof(easeOutCubic)
#define EASE_IN_OUT_CUBIC __addressof(easeInOutCubic)
#define EASE_IN_QUART __addressof(easeInQuart)
#define EASE_OUT_QUART __addressof(easeOutQuart)
#define EASE_IN_OUT_QUART __addressof(easeInOutQuart)
#define EASE_IN_QUINT __addressof(easeInQuint)
#define EASE_OUT_QUINT __addressof(easeOutQuint)
#define EASE_IN_OUT_QUINT __addressof(easeInOutQuint)
#define EASE_IN_EXPO __addressof(easeInExpo)
#define EASE_OUT_EXPO __addressof(easeOutExpo)
#define EASE_IN_OUT_EXPO __addressof(easeInOutExpo)
#define EASE_IN_CIRC __addressof(easeInCirc)
#define EASE_OUT_CIRC __addressof(easeOutCirc)
#define EASE_IN_OUT_CIRC __addressof(easeInOutCirc)
#define EASE_IN_BACK __addressof(easeInBack)
#define EASE_OUT_BACK __addressof(easeOutBack)
#define EASE_IN_OUT_BACK __addressof(easeInOutBack)
#define EASE_IN_ELASTIC __addressof(easeInElastic)
#define EASE_OUT_ELASTIC __addressof(easeOutElastic)
#define EASE_IN_OUT_ELASTIC __addressof(easeInOutElastic)
#define EASE_IN_BOUNCE __addressof(easeInBounce)
#define EASE_OUT_BOUNCE __addressof(easeOutBounce)
#define EASE_IN_OUT_BOUNCE __addressof(easeInOutBounce)

enum _:eAnimatorData
{
	bool:e_bValid,
	Float:e_fStartX,
	Float:e_fStartY,
	Float:e_fTargetX,
	Float:e_fTargetY,
	PlayerText:e_tdTextdraw,
	e_iPlayerid,
	Float:e_fDuration,
	e_iTick,
	e_iEase
}

new g_rgeAnimators[MAX_ANIMATORS + 1][eAnimatorData];

// Easing functions
stock Float:easeInSine(Float:t)
{
	return floatsin( 1.5707963 * t );
}

stock Float:easeOutSine(Float:t)
{
	return 1.0 + floatsin( 1.5707963 * (--t) );
}

stock Float:easeInOutSine(Float:t)
{
	return 0.5 * (1.0 + floatsin( 3.1415926 * (t - 0.5) ) );
}

stock Float:easeInQuad(Float:t)
{
    return t * t;
}

stock Float:easeOutQuad(Float:t)
{ 
    return t * (2.0 - t);
}

stock Float:easeInOutQuad(Float:t)
{
    return t < 0.5 ? 2.0 * t * t : t * (4.0 - 2.0 * t) - 1.0;
}

stock Float:easeInCubic(Float:t)
{
    return t * t * t;
}

stock Float:easeOutCubic(Float:t)
{
    return 1.0 + (--t) * t * t;
}

stock Float:easeInOutCubic(Float:t)
{
    return t < 0.5 ? 4.0 * t * t * t : 1.0 + (--t) * (2.0 * (--t)) * (2.0 * t);
}

stock Float:easeInQuart(Float:t)
{
    t *= t;
    return t * t;
}

stock Float:easeOutQuart(Float:t)
{
    t = (--t) * t;
    return 1.0 - t * t;
}

stock Float:easeInOutQuart(Float:t)
{
    if ( t < 0.5 )
    {
        t *= t;
        return 8.0 * t * t;
    }
    else
    {
        t = (--t) * t;
        return 1.0 - 8.0 * t * t;
    }
}

stock Float:easeInQuint(Float:t)
{
    new Float:t2 = t * t;
    return t * t2 * t2;
}

stock Float:easeOutQuint(Float:t)
{
    new Float:t2 = (--t) * t;
    return 1.0 + t * t2 * t2;
}

stock Float:easeInOutQuint(Float:t)
{
    new Float:t2;
    if ( t < 0.5 )
    {
        t2 = t * t;
        return 16.0 * t * t2 * t2;
    }
    else
    {
        t2 = (--t) * t;
        return 1.0 + 16.0 * t * t2 * t2;
    }
}

stock Float:easeInExpo(Float:t)
{
    return (floatpower( 2.0, 8.0 * t ) - 1.0) / 255.0;
}

stock Float:easeOutExpo(Float:t)
{
    return 1.0 - floatpower( 2.0, -8.0 * t );
}

stock Float:easeInOutExpo(Float:t)
{
    if ( t < 0.5 )
    {
        return (floatpower( 2.0, 16.0 * t ) - 1.0) / 510.0;
    }
    else
    {
        return 1.0 - 0.5 * floatpower( 2.0, -16.0 * (t - 0.5) );
    }
}

stock Float:easeInCirc(Float:t)
{
    return 1.0 - sqrt( 1.0 - t );
}

stock Float:easeOutCirc(Float:t)
{
    return sqrt( t );
}

stock Float:easeInOutCirc(Float:t)
{
    if ( t < 0.5 )
    {
        return (1.0 - sqrt( 1.0 - 2.0 * t )) * 0.5;
    }
    else
    {
        return (1.0 + sqrt( 2.0 * t - 1 )) * 0.5;
    }
}

stock Float:easeInBack(Float:t)
{
    return t * t * (2.70158 * t - 1.70158);
}

stock Float:easeOutBack(Float:t)
{
    return 1.0 + (--t) * t * (2.70158 * t + 1.70158);
}

stock Float:easeInOutBack(Float:t)
{
    if ( t < 0.5 )
    {
        return t * t * (7.0 * t - 2.5) * 2.0;
    }
    else {
        return 1.0 + (--t) * t * 2.0 * (7 * t + 2.5);
    }
}

stock Float:easeInElastic(Float:t)
{
    new Float:t2 = t * t;
    return t2 * t2 * floatsin( t * PI * 4.5 );
}

stock Float:easeOutElastic(Float:t)
{
    new Float:t2 = (t - 1.0) * (t - 1.0);
    return 1.0 - t2 * t2 * floatcos( t * PI * 4.5 );
}

stock Float:easeInOutElastic(Float:t)
{
    new Float:t2;
    if ( t < 0.45 )
    {
        t2 = t * t;
        return 8.0 * t2 * t2 * floatsin( t * PI * 9.0 );
    }
    else if ( t < 0.55 )
    {
        return 0.5 + 0.75 * floatsin( t * PI * 4.0 );
    }
    else
    {
        t2 = (t - 1.0) * (t - 1.0);
        return 1.0 - 8.0 * t2 * t2 * floatsin( t * PI * 9.0 );
    }
}

stock Float:easeInBounce(Float:t)
{
    return floatpower( 2.0, 6.0 * (t - 1.0) ) * floatabs( floatsin( t * PI * 3.5 ) );
}

stock Float:easeOutBounce(Float:t)
{
    return 1.0 - floatpower( 2.0, -6.0 * t ) * floatabs( floatcos( t * PI * 3.5 ) );
}

stock Float:easeInOutBounce(Float:t)
{
    if ( t < 0.5 )
    {
        return 8.0 * floatpower( 2.0, 8.0 * (t - 1.0) ) * floatabs( floatsin( t * PI * 7.0 ) );
    }
    else
    {
        return 1.0 - 8.0 * floatpower( 2.0, -8.0 * t ) * floatabs( floatsin( t * PI * 7.0 ) );
    }
}

static Float:lerp(Float:start_value, Float:end_value, Float:pct)
{
    return (start_value + (end_value - start_value) * pct);
}

static Animator_GetFreeSlot()
{
	for (new i; i < MAX_ANIMATORS; ++i)
	{
		if (!g_rgeAnimators[i][e_bValid])
		    return i;
	}
    return -1;
}

forward Animator_Process();
public Animator_Process()
{
	for (new i; i < MAX_ANIMATORS; ++i)
	{
		if (g_rgeAnimators[i][e_bValid])
		{
			new elapsed_time = GetTickCount() - g_rgeAnimators[i][e_iTick];
			new Float:t = elapsed_time / g_rgeAnimators[i][e_fDuration];

			new
				ease_addr = g_rgeAnimators[i][e_iEase],
				Float:ease, Float:x, Float:y
			;

			__emit
            {
                push.s t
                push.c 4
                lctrl 6
                add.c 0x24
                lctrl 8
                push.pri
                load.s.pri ease_addr
                sctrl 6
                stor.s.pri ease
            }

			x = lerp(g_rgeAnimators[i][e_fStartX], g_rgeAnimators[i][e_fTargetX], ease);
			y = lerp(g_rgeAnimators[i][e_fStartY], g_rgeAnimators[i][e_fTargetY], ease);

			PlayerTextDrawSetPos(g_rgeAnimators[i][e_iPlayerid], g_rgeAnimators[i][e_tdTextdraw], x, y);
			PlayerTextDrawShow(g_rgeAnimators[i][e_iPlayerid], g_rgeAnimators[i][e_tdTextdraw]);

			if (t >= 1.0)
			{
				g_rgeAnimators[i] = g_rgeAnimators[MAX_ANIMATORS];
				continue;
			}
		}
	}
	return 1;
}

stock Animator_Insert(playerid, PlayerText:textdraw, Float:start_x, Float:start_y, Float:x, Float:y, duration = 1000, ease)
{
	new animator = Animator_GetFreeSlot();
	if (animator == -1)
		return -1;

	g_rgeAnimators[animator][e_fStartX] = start_x;
	g_rgeAnimators[animator][e_fStartY] = start_y;

	g_rgeAnimators[animator][e_tdTextdraw] = textdraw;
	g_rgeAnimators[animator][e_iPlayerid] = playerid;
	g_rgeAnimators[animator][e_fDuration] = duration;
	g_rgeAnimators[animator][e_iEase] = ease;

	g_rgeAnimators[animator][e_fTargetX] = x;
	g_rgeAnimators[animator][e_fTargetY] = y;

	g_rgeAnimators[animator][e_iTick] = GetTickCount();
	g_rgeAnimators[animator][e_bValid] = true;
	return animator;
}

stock PlayerText_MoveTo(playerid, PlayerText:textdraw, Float:x, Float:y, duration = 1000, ease)
{
	new Float:start_x, Float:start_y;
	PlayerTextDrawGetPos(playerid, textdraw, start_x, start_y);
	return Animator_Insert(playerid, textdraw, start_x, start_y, x, y, duration, ease);
}

stock PlayerText_MoveToX(playerid, PlayerText:textdraw, Float:x, duration = 1000, ease)
{
	new Float:start_x, Float:start_y;
	PlayerTextDrawGetPos(playerid, textdraw, start_x, start_y);
	return Animator_Insert(playerid, textdraw, start_x, start_y, x, start_y, duration, ease);
}

stock PlayerText_MoveToY(playerid, PlayerText:textdraw, Float:y, duration = 1000, ease)
{
	new Float:start_x, Float:start_y;
	PlayerTextDrawGetPos(playerid, textdraw, start_x, start_y);
	return Animator_Insert(playerid, textdraw, start_x, start_y, start_x, y, duration, ease);
}

stock PlayerText_StopMove(animator)
{
	if (animator < MAX_ANIMATORS)
	{
		g_rgeAnimators[animator] = g_rgeAnimators[MAX_ANIMATORS];
		return 1;
	}
	return 0;
}

public OnGameModeInit()
{
	SetTimer("Animator_Process", ANIMATORS_UPDATE_RATE, true);

	#if defined easing_OnGameModeInit
		return easing_OnGameModeInit();
	#else
		return 1;
	#endif
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit easing_OnGameModeInit
#if defined easing_OnGameModeInit
	forward easing_OnGameModeInit();
#endif