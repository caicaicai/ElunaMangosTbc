/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 * Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef SPELLMETHODS_H
#define SPELLMETHODS_H

class LuaSpell
{
    public:
        // :GetUnitType()
        static int GetUnitType(lua_State* L, Spell* spell)
        {
            if (!spell)
                return 0;

            lua_pushstring(L, "Spell");
            return 1;
        }

        // GetCaster()
        static int GetCaster(lua_State* L, Spell* spell)
        {
            if (!spell)
                return 0;

            sEluna.PushUnit(L, spell->GetCaster());
            return 1;
        }

        // GetCastTime()
        static int GetCastTime(lua_State* L, Spell* spell)
        {
            if (!spell)
                return 0;

            sEluna.PushInteger(L, spell->GetCastTime());
            return 1;
        }

        // GetId()
        static int GetId(lua_State* L, Spell* spell)
        {
            if (!spell)
                return 0;

            sEluna.PushUnsigned(L, spell->m_spellInfo->Id);
            return 1;
        }

        // GetPowerCost()
        static int GetPowerCost(lua_State* L, Spell* spell)
        {
            if (!spell)
                return 0;

            sEluna.PushInteger(L, spell->GetPowerCost());
            return 1;
        }

        // GetDuration()
        static int GetDuration(lua_State* L, Spell* spell) // TODO: Implementation
        {
            if (!spell)
                return 0;

            // sEluna.PushInteger(L, spell->m_spellInfo->GetDuration());
            // return 1;
            return 0; // Temp to not cause conflicts
        }

        // Cast(skipCheck)
        static int Cast(lua_State* L, Spell* spell)
        {
            if (!spell)
                return 0;

            bool skipCheck = lua_toboolean(L, 1);
            spell->cast(skipCheck);
            return 0;
        }

        // IsAutoRepeat()
        static int IsAutoRepeat(lua_State* L, Spell* spell)
        {
            if (!spell)
                sEluna.PushBoolean(L, false);
            else
            {
                bool repeat = spell->IsAutoRepeat();
                sEluna.PushBoolean(L, repeat);
            }
            return 1;
        }

        // SetAutoRepeat(boolean)
        static int SetAutoRepeat(lua_State* L, Spell* spell)
        {
            if (!spell)
                return 0;

            bool repeat = luaL_checkbool(L, 1);
            spell->SetAutoRepeat(repeat);
            return 0;
        }

        // Cancel()
        static int cancel(lua_State* L, Spell* spell)
        {
            if (!spell)
                return 0;

            spell->cancel();
            return 0;
        }

        // Finish()
        static int Finish(lua_State* L, Spell* spell)
        {
            if (!spell)
                return 0;

            spell->finish();
            return 0;
        }

        // GetTargetDest()
        static int GetTargetDest(lua_State* L, Spell* spell) // TODO: Implementation
        {
            /*if (!spell)
                return 0;

            if (!spell->m_targets.HasDst())
                return 0;
            float x, y, z, o;
            spell->m_targets.GetDstPos()->GetPosition(x,y,z,o);
            sEluna.PushFloat(L, x);
            sEluna.PushFloat(L, y);
            sEluna.PushFloat(L, z);
            sEluna.PushFloat(L, o);
            sEluna.PushUnsigned(L, spell->m_targets.GetDstPos()->GetMapId());
            return 5;*/
            return 0; // Temporary to prevent conflicts
        }
};
#endif