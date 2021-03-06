/*
*
*   This program is free software; you can redistribute it and/or modify it
*   under the terms of the GNU General Public License as published by the
*   Free Software Foundation; either version 2 of the License, or (at
*   your option) any later version.
*
*   This program is distributed in the hope that it will be useful, but
*   WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*   General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software Foundation,
*   Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*   In addition, as a special exception, the author gives permission to
*   link the code of this program with the Half-Life Game Engine ("HL
*   Engine") and Modified Game Libraries ("MODs") developed by Valve,
*   L.L.C ("Valve").  You must obey the GNU General Public License in all
*   respects for all of the code used other than the HL Engine and MODs
*   from Valve.  If you modify this file, you may extend this exception
*   to your version of the file, but you are not obligated to do so.  If
*   you do not wish to do so, delete this exception statement from your
*   version.
*
*/

#ifndef TUTOR_BASE_STATES_H
#define TUTOR_BASE_STATES_H
#ifdef _WIN32
#pragma once
#endif

class CBaseTutorState
{
public:
	CBaseTutorState(void);

	virtual ~CBaseTutorState(void);
	virtual int CheckForStateTransition(GameEventType event, CBaseEntity *entity, CBaseEntity *other) = 0;
	virtual char *GetStateString(void) = 0;

public:
	int GetType(void);

protected:
	int m_type;

};/* size: 8, cachelines: 1, members: 2 */

class CBaseTutorStateSystem
{
public:
	CBaseTutorStateSystem(void);

	virtual ~CBaseTutorStateSystem(void);
	virtual bool UpdateState(GameEventType event, CBaseEntity *entity, CBaseEntity *other) = 0;
	virtual char *GetCurrentStateString(void) = 0;
	virtual CBaseTutorState *ConstructNewState(int stateType) = 0;

public:
	int GetCurrentStateType(void);

protected:
	CBaseTutorState *m_currentState;

};/* size: 8, cachelines: 1, members: 2 */

#endif // TUTOR_BASE_STATES_H
