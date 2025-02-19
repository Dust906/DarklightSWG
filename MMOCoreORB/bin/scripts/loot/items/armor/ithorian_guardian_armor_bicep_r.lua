ithorian_guardian_armor_bicep_r = {
	minimumLevel = 0,
	maximumLevel = -1,
	customObjectName = "",
	directObjectTemplate = "object/tangible/wearables/armor/ithorian_guardian/ith_armor_s02_bicep_r.iff",
	craftingValues = {
		{"armor_rating",1,1,0},
		{"kineticeffectiveness",10,40,10},
		{"armor_effectiveness",4,29,10},
		{"armor_integrity",15000, 25000,0},

	},
	skillMods = {

	},
	customizationStringNames = {"/private/index_color_0", "/private/index_color_1"},
	customizationValues = {
			{0, 1},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
	},

	junkDealerTypeNeeded = JUNKARMOUR,
	junkMinValue = 35,
	junkMaxValue = 70
}

addLootItemTemplate("ithorian_guardian_armor_bicep_r", ithorian_guardian_armor_bicep_r)
