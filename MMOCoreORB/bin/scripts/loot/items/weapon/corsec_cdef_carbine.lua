--Automatically generated by SWGEmu Spawn Tool v0.12 loot editor.

corsec_cdef_carbine = {
	minimumLevel = 0,
	maximumLevel = -1,
	customObjectName = "",
	directObjectTemplate = "object/weapon/ranged/carbine/carbine_cdef_corsec.iff",
	craftingValues = {
		{"mindamage",17,32,0},
		{"maxdamage",35,65,0},
		{"attackspeed",4.6,3.2,1},
		{"woundchance",4,5,0},
		{"roundsused",5,20,0},
		{"hitpoints",750,1500,0},
		{"zerorangemod",0,0,0},
		{"maxrangemod",-80,-80,0},
		{"midrange",35,35,0},
		{"midrangemod",35,65,0},
	},
	customizationStringNames = {},
	customizationValues = {},

	-- randomDotChance: The chance of this weapon object dropping with a random dot on it. Higher number means less chance. Set to 0 to always have a random dot.
	randomDotChance = 800,
	junkDealerTypeNeeded = JUNKWEAPONS + JUNKCORSEC,
	junkMinValue = 20,
	junkMaxValue = 60

}

addLootItemTemplate("corsec_cdef_carbine", corsec_cdef_carbine)
