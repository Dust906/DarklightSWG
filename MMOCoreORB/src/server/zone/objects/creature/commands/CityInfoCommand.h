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

#ifndef CITYINFOCOMMAND_H_
#define CITYINFOCOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"

class CityInfoCommand : public QueueCommand {
public:
	CityInfoCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) {
		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		if (!creature->isPlayerCreature())
			return GENERALERROR;

		PlayerObject* ghost = creature->getPlayerObject();

		if(ghost == NULL || !ghost->isPrivileged()) {
			return GENERALERROR;
		}

		byte rank = 0;
		StringTokenizer args(arguments.toString());
		String planet;

		if(args.hasMoreTokens()) {
			args.getStringToken(planet);
		} else {
			sendSyntax(creature);
			return INVALIDSYNTAX;
		}

		if (args.hasMoreTokens()) {
			rank = args.getIntToken();
			if(rank < 1 || rank > 5) {
				creature->sendSystemMessage("Rank, if specified, must be between 1 and 5.");
				return INVALIDPARAMETERS;
			}

		}

		if(creature->getZoneServer() == NULL)
			return GENERALERROR;

		CityManager* cityManager = creature->getZoneServer()->getCityManager();

		if(cityManager == NULL)
			return GENERALERROR;

		cityManager->sendCityReport(creature, planet, rank);
		return SUCCESS;
	}

	static void sendSyntax(CreatureObject* creature) {
		String syntax = "/cityinfo [planetname] <rank>";
		creature->sendSystemMessage(syntax);
	}
};

#endif //CITYINFOCOMMAND_H_
