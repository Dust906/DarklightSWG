/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#ifndef POLEARMLEGHIT3COMMAND_H_
#define POLEARMLEGHIT3COMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/managers/combat/CombatManager.h"
#include "CombatQueueCommand.h"


class PolearmLegHit3Command : public CombatQueueCommand {
public:

	PolearmLegHit3Command(const String& name, ZoneProcessServer* server)
		: CombatQueueCommand(name, server) {
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		ManagedReference<WeaponObject*> weapon = creature->getWeapon();

		if (!weapon->isPolearmWeaponObject()) {
			return INVALIDWEAPON;
		}

		Reference<SceneObject*> object = server->getZoneServer()->getObject(target);
		ManagedReference<CreatureObject*> creatureTarget = cast<CreatureObject*>( object.get());
	
		if (creatureTarget == NULL)
			return GENERALERROR;

		if (creature->getDistanceTo(object) > 8.f){
			creature->sendSystemMessage("You are out of range.");
			return GENERALERROR;
		}
	
		uint32 buffcrc = BuffCRC::FORCE_RANK_SUFFERING;
		uint32 buffcrc2 = BuffCRC::FORCE_RANK_SERENITY;

		if(creature->hasBuff(buffcrc2)) {
			creature->sendSystemMessage("You cannot snare at this time.");
			return GENERALERROR;
		}

		int duration = 8;
		int duration2 = 38;

		ManagedReference<Buff*> buff2 = new Buff(creature, buffcrc2, duration2, BuffType::JEDI);
		ManagedReference<Buff*> buff = new Buff(creatureTarget, buffcrc, duration, BuffType::JEDI);

		if (object->isCreatureObject() && creatureTarget->isAttackableBy(creature) && !creatureTarget->hasBuff(buffcrc)) {
			buff->setSpeedMultiplierMod(0.5);
			creatureTarget->addBuff(buff);
			creature->addBuff(buff2);
			creatureTarget->playEffect("clienteffect/pikeman_snare.cef", "");
		}

		return doCombatAction(creature, target);
	}

};

#endif //POLEARMLEGHIT3COMMAND_H_
