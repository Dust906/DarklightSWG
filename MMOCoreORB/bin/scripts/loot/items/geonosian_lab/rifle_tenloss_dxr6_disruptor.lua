--Automatically generated by SWGEmu Spawn Tool v0.12 loot editor.
 
rifle_tenloss_dxr6_disruptor = {
	minimumLevel = 0,
	maximumLevel = -1,
	customObjectName = "",
	directObjectTemplate = "object/weapon/ranged/rifle/rifle_tenloss_dxr6_disruptor_loot.iff",
	craftingValues = {
		{"mindamage",40,150,0},
		{"maxdamage",80,320,0},
		{"attackspeed",9.4,6.7,1},
		{"woundchance",4.8,12.3,0},
		{"hitpoints",750,750,0},
		{"roundsused",30,65,0},
		{"zerorangemod",-80,-40,0},
		{"maxrangemod",10,30,0},
		{"midrange",54,54,0},
		{"midrangemod",45,70,0},
	},
	customizationStringNames = {},
	customizationValues = {},

	-- randomDotChance: The chance of this weapon object dropping with a random dot on it. Higher number means less chance. Set to 0 to always have a random dot.
	randomDotChance = 1000,
	junkDealerTypeNeeded = JUNKWEAPONS,
	junkMinValue = 20,
	junkMaxValue = 60

}

addLootItemTemplate("rifle_tenloss_dxr6_disruptor", rifle_tenloss_dxr6_disruptor)
