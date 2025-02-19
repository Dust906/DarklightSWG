/*
 * CreatureTemplate.h
 *
 *  Created on: Oct 9, 2010
 *      Author: dannuic
 */

#ifndef CREATURETEMPLATE_H_
#define CREATURETEMPLATE_H_

#include "engine/engine.h"
#include "server/zone/objects/creature/variables/CreatureAttackMap.h"
#include "server/zone/objects/creature/CreatureFlag.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "server/zone/managers/loot/lootgroup/LootGroupCollection.h"
#include "MobileOutfit.h"

namespace server {
namespace zone {
namespace templates {
namespace mobile {

class CreatureTemplate : public Object {
protected:
	String templateName;
	String customName;

	unsigned int armor;

	float kinetic;
	float energy;
	float electricity;
	float stun;
	float blast;
	float heat;
	float cold;
	float acid;
	float lightSaber;

	float tamingChance;
	unsigned int ferocity;

	String meatType;
	String boneType;
	String hideType;
	String milkType;

	int milk;
	int hideAmount;
	int boneAmount;
	int meatAmount;

	String objectName;
	int randomNameType;
	String socialGroup;
	String faction;

	int level;

	float chanceHit;
	int damageMin;
	int damageMax;
	int range;

	float scale;

	int baseXp;
	int baseHAM;
	int baseHAMmax;

	unsigned int pvpBitmask;
	unsigned int creatureBitmask;
	unsigned int diet;


	Vector<String> templates;

	LootGroupCollection lootgroups;

	Vector<String> weapons;

	CreatureAttackMap* attacks;
	uint32 conversationTemplate;
	uint32 optionsBitmask;

	String patrolPathTemplate;

	//MobileOutfit outfit;
	String outfit;

	String aiTemplate;
	String defaultWeapon;
	String defaultAttack;

	String controlDeviceTemplate;
	String containerComponentTemplate;

	String reactionStf;
	String personalityStf;

public:
	CreatureTemplate();

	virtual ~CreatureTemplate();

	void readObject(LuaObject* templateData);

	inline float getKinetic() {
		if (isSpecialProtection(WeaponObject::KINETIC))
			return kinetic - 100;
		else
			return kinetic;
	}

	inline float getEnergy() {
		if (isSpecialProtection(WeaponObject::ENERGY))
			return energy - 100;
		else
			return energy;
	}

	inline float getElectricity() {
		if (isSpecialProtection(WeaponObject::ELECTRICITY))
			return electricity - 100;
		else
			return electricity;
	}

	inline float getStun() {
		if (isSpecialProtection(WeaponObject::STUN))
			return stun - 100;
		else
			return stun;
	}

	inline float getBlast() {
		if (isSpecialProtection(WeaponObject::BLAST))
			return blast - 100;
		else
			return blast;
	}

	inline float getHeat() {
		if (isSpecialProtection(WeaponObject::HEAT))
			return heat - 100;
		else
			return heat;
	}

	inline float getCold() {
		if (isSpecialProtection(WeaponObject::COLD))
			return cold - 100;
		else
			return cold;
	}

	inline float getAcid() {
		if (isSpecialProtection(WeaponObject::ACID))
			return acid - 100;
		else
			return acid;
	}

	inline float getLightSaber() {
		if (isSpecialProtection(WeaponObject::LIGHTSABER))
			return lightSaber - 100;
		else
			return lightSaber;
	}

	inline bool isStalker() {
		return creatureBitmask & CreatureFlag::STALKER;
	}

	inline bool isBaby() {
		return creatureBitmask & CreatureFlag::BABY;
	}

	inline bool isKiller() {
		return creatureBitmask & CreatureFlag::KILLER;
	}

	inline bool isPack() {
		return creatureBitmask & CreatureFlag::PACK;
	}

	inline bool isHerd() {
		return creatureBitmask & CreatureFlag::HERD;
	}

	inline float getTame() {
		return tamingChance;
	}

	inline String& getMeatType() {
		return meatType;
	}

	inline String& getBoneType() {
		return boneType;
	}

	inline String& getHideType() {
		return hideType;
	}

	inline String& getMilkType() {
		return milkType;
	}

	inline String& getCustomName() {
		return customName;
	}

	inline float getMilk() {
		return milk;
	}

	inline float getHideMax() {
		return hideAmount;
	}

	inline float getBoneMax() {
		return boneAmount;
	}

	inline float getMeatMax() {
		return meatAmount;
	}

	inline unsigned int getFerocity() {
		return ferocity;
	}

	inline unsigned int getArmor() {
		return armor;
	}

	inline String getObjectName() {
		return objectName;
	}

	inline int getRandomNameType() {
		return randomNameType;
	}

	inline String getSocialGroup() {
		return socialGroup;
	}

	inline uint32 getConversationTemplate() {
		return conversationTemplate;
	}

	inline uint32 getOptionsBitmask() {
		return optionsBitmask;
	}

	inline String getFaction() {
		return faction;
	}

	inline int getLevel() {
		return level;
	}

	inline float getChanceHit() {
		return chanceHit;
	}

	inline float getScale() {
		return scale;
	}

	inline int getDamageMin() {
		return damageMin;
	}

	inline int getDamageMax() {
		return damageMax;
	}

	inline int getRange() {
		return range;
	}

	inline int getBaseXp() {
		return baseXp;
	}

	inline int getBaseHAM() {
		return baseHAM;
	}

	inline int getBaseHAMmax() {
		return baseHAMmax;
	}

	inline uint32 getPvpBitmask() {
		return pvpBitmask;
	}

	inline uint32 getCreatureBitmask() {
		return creatureBitmask;
	}

	inline uint32 getDiet() {
		return diet;
	}

	inline Vector<String>& getTemplates() {
		return templates;
	}

	inline LootGroupCollection* getLootGroups() {
		return &lootgroups;
	}

	inline Vector<String>& getWeapons() {
		return weapons;
	}

	inline CreatureAttackMap* getAttacks() {
		return attacks;
	}

	inline String getPatrolPathTemplate() {
		return patrolPathTemplate;
	}

	void setTemplateName(const String& t) {
		templateName = t;
	}

	inline String getTemplateName() {
		return templateName;
	}

	inline bool hasPatrolPathTemplate() {
		return !patrolPathTemplate.isEmpty();
	}

	inline String getOutfit() {
		return outfit;
	}

	inline String getAiTemplate() {
		return aiTemplate;
	}

	inline String getDefaultWeapon(){
		return defaultWeapon;
	}

	inline String getDefaultAttack(){
		return defaultAttack;
	}

	inline String getControlDeviceTemplate() {
		return controlDeviceTemplate;
	}

	inline String getContainerComponentTemplate() {
		return containerComponentTemplate;
	}

	inline String getReactionStf() {
		return reactionStf;
	}

	inline String getPersonalityStf() {
		return personalityStf;
	}

	inline bool isSpecialProtection(int resistType) {
		switch (resistType) {
		case WeaponObject::KINETIC:
			return kinetic > 100;
			break;
		case WeaponObject::ENERGY:
			return energy > 100;
			break;
		case WeaponObject::ELECTRICITY:
			return electricity > 100;
			break;
		case WeaponObject::STUN:
			return stun > 100;
			break;
		case WeaponObject::BLAST:
			return blast > 100;
			break;
		case WeaponObject::HEAT:
			return heat > 100;
			break;
		case WeaponObject::COLD:
			return cold > 100;
			break;
		case WeaponObject::ACID:
			return acid > 100;
			break;
		case WeaponObject::LIGHTSABER:
			return lightSaber > 100;
			break;
		}

		return false;
	}
};

}
}
}
}

using namespace server::zone::templates::mobile;

#endif /* CREATURETEMPLATE_H_ */
