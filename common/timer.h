/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2002 EQEMu Development Team (http://eqemu.org)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef TIMER_H
#define TIMER_H

#include "types.h"

// Disgrace: for windows compile
#ifdef _WINDOWS
	#include "global_define.h"
	int gettimeofday (timeval *tp, ...);
#endif

class Timer
{
public:
	Timer();
	Timer(uint32 duration);
	~Timer() { }
	bool Check(bool iReset = true);
	bool CheckKeepSynchronized(int tolerance = 200);
	void Enable();
	void Disable();
	void Start(uint32 duration = 0, bool ChangeResetTimer = true);
	uint32 GetRemainingTime();
	void Trigger();
	void Reset();
	void Stop();
	void Pause();
	void Resume();
	bool Paused();

	inline bool Enabled() { return enabled; }
	inline uint32 GetDuration() { return(Duration); }
	void SetDuration(uint32 duration, bool update_current_interval = false);

	static const uint32 SetCurrentTime();
	static const uint32 GetCurrentTime();
	static const uint32 GetTimeSeconds();	// returns a unix timestamp, not used by Timer class

private:
	uint32	TriggerTime;
	uint32	TriggerEra;
	uint32	Duration;
	uint32	pause_time;
	bool	enabled;

	static uint32 current_era;
	static uint32 current_time;
};

#endif
