/**
 * DO NOT MODIFY THIS FILE
 *
 * This repository was automatically generated and is NOT to be modified directly.
 * Any repository modifications are meant to be made to the repository extending the base.
 * Any modifications to base repositories are to be made by the generator only
 *
 * @generator ./utils/scripts/generators/repository-generator.pl
 * @docs https://eqemu.gitbook.io/server/in-development/developer-area/repositories
 */

#ifndef EQEMU_BASE_SPELLS_NEW_REPOSITORY_H
#define EQEMU_BASE_SPELLS_NEW_REPOSITORY_H

#include "../../database.h"
#include "../../strings.h"
#include <ctime>


class BaseSpellsNewRepository {
public:
	struct SpellsNew {
		int32_t     id;
		std::string name;
		std::string player_1;
		std::string teleport_zone;
		std::string you_cast;
		std::string other_casts;
		std::string cast_on_you;
		std::string cast_on_other;
		std::string spell_fades;
		int32_t     range;
		int32_t     aoerange;
		float       pushback;
		float       pushup;
		int32_t     cast_time;
		int32_t     recovery_time;
		int32_t     recast_time;
		int32_t     buffdurationformula;
		int32_t     buffduration;
		int32_t     AEDuration;
		int32_t     mana;
		int32_t     effect_base_value1;
		int32_t     effect_base_value2;
		int32_t     effect_base_value3;
		int32_t     effect_base_value4;
		int32_t     effect_base_value5;
		int32_t     effect_base_value6;
		int32_t     effect_base_value7;
		int32_t     effect_base_value8;
		int32_t     effect_base_value9;
		int32_t     effect_base_value10;
		int32_t     effect_base_value11;
		int32_t     effect_base_value12;
		int32_t     effect_limit_value1;
		int32_t     effect_limit_value2;
		int32_t     effect_limit_value3;
		int32_t     effect_limit_value4;
		int32_t     effect_limit_value5;
		int32_t     effect_limit_value6;
		int32_t     effect_limit_value7;
		int32_t     effect_limit_value8;
		int32_t     effect_limit_value9;
		int32_t     effect_limit_value10;
		int32_t     effect_limit_value11;
		int32_t     effect_limit_value12;
		int32_t     max1;
		int32_t     max2;
		int32_t     max3;
		int32_t     max4;
		int32_t     max5;
		int32_t     max6;
		int32_t     max7;
		int32_t     max8;
		int32_t     max9;
		int32_t     max10;
		int32_t     max11;
		int32_t     max12;
		int32_t     icon;
		int32_t     memicon;
		int32_t     components1;
		int32_t     components2;
		int32_t     components3;
		int32_t     components4;
		int32_t     component_counts1;
		int32_t     component_counts2;
		int32_t     component_counts3;
		int32_t     component_counts4;
		int32_t     NoexpendReagent1;
		int32_t     NoexpendReagent2;
		int32_t     NoexpendReagent3;
		int32_t     NoexpendReagent4;
		int32_t     formula1;
		int32_t     formula2;
		int32_t     formula3;
		int32_t     formula4;
		int32_t     formula5;
		int32_t     formula6;
		int32_t     formula7;
		int32_t     formula8;
		int32_t     formula9;
		int32_t     formula10;
		int32_t     formula11;
		int32_t     formula12;
		int32_t     LightType;
		int32_t     goodEffect;
		int32_t     Activated;
		int32_t     resisttype;
		int32_t     effectid1;
		int32_t     effectid2;
		int32_t     effectid3;
		int32_t     effectid4;
		int32_t     effectid5;
		int32_t     effectid6;
		int32_t     effectid7;
		int32_t     effectid8;
		int32_t     effectid9;
		int32_t     effectid10;
		int32_t     effectid11;
		int32_t     effectid12;
		int32_t     targettype;
		int32_t     basediff;
		int32_t     skill;
		int32_t     zonetype;
		int32_t     EnvironmentType;
		int32_t     TimeOfDay;
		int32_t     classes1;
		int32_t     classes2;
		int32_t     classes3;
		int32_t     classes4;
		int32_t     classes5;
		int32_t     classes6;
		int32_t     classes7;
		int32_t     classes8;
		int32_t     classes9;
		int32_t     classes10;
		int32_t     classes11;
		int32_t     classes12;
		int32_t     classes13;
		int32_t     classes14;
		int32_t     classes15;
		int32_t     CastingAnim;
		int32_t     TargetAnim;
		int32_t     TravelType;
		int32_t     SpellAffectIndex;
		int32_t     disallow_sit;
		int32_t     deities0;
		int32_t     deities1;
		int32_t     deities2;
		int32_t     deities3;
		int32_t     deities4;
		int32_t     deities5;
		int32_t     deities6;
		int32_t     deities7;
		int32_t     deities8;
		int32_t     deities9;
		int32_t     deities10;
		int32_t     deities11;
		int32_t     deities12;
		int32_t     deities13;
		int32_t     deities14;
		int32_t     deities15;
		int32_t     deities16;
		int32_t     npc_no_cast;
		int32_t     ai_pt_bonus;
		int32_t     new_icon;
		int32_t     spellanim;
		int32_t     uninterruptable;
		int32_t     ResistDiff;
		int32_t     dot_stacking_exempt;
		int32_t     deleteable;
		int32_t     RecourseLink;
		int32_t     no_partial_resist;
		int32_t     small_targets_only;
		int32_t     use_persistent_particles;
		int32_t     short_buff_box;
		int32_t     descnum;
		int32_t     typedescnum;
		int32_t     effectdescnum;
		int32_t     effectdescnum2;
		int32_t     npc_no_los;
		int32_t     reflectable;
		int32_t     resist_per_level;
		int32_t     resist_cap;
		int32_t     EndurCost;
		int32_t     EndurTimerIndex;
		int32_t     IsDiscipline;
		int32_t     HateAdded;
		int32_t     EndurUpkeep;
		int32_t     pvpresistbase;
		int32_t     pvpresistcalc;
		int32_t     pvpresistcap;
		int32_t     spell_category;
		int32_t     pvp_duration;
		int32_t     pvp_duration_cap;
		int32_t     cast_not_standing;
		int32_t     can_mgb;
		int32_t     nodispell;
		int32_t     npc_category;
		int32_t     npc_usefulness;
		int32_t     wear_off_message;
		int32_t     suspendable;
		int32_t     spellgroup;
		int32_t     allow_spellscribe;
		int32_t     allowrest;
		int32_t     custom_icon;
		int32_t     not_player_spell;
		int8_t      disabled;
	};

	static std::string PrimaryKey()
	{
		return std::string("id");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"id",
			"name",
			"player_1",
			"teleport_zone",
			"you_cast",
			"other_casts",
			"cast_on_you",
			"cast_on_other",
			"spell_fades",
			"range",
			"aoerange",
			"pushback",
			"pushup",
			"cast_time",
			"recovery_time",
			"recast_time",
			"buffdurationformula",
			"buffduration",
			"AEDuration",
			"mana",
			"effect_base_value1",
			"effect_base_value2",
			"effect_base_value3",
			"effect_base_value4",
			"effect_base_value5",
			"effect_base_value6",
			"effect_base_value7",
			"effect_base_value8",
			"effect_base_value9",
			"effect_base_value10",
			"effect_base_value11",
			"effect_base_value12",
			"effect_limit_value1",
			"effect_limit_value2",
			"effect_limit_value3",
			"effect_limit_value4",
			"effect_limit_value5",
			"effect_limit_value6",
			"effect_limit_value7",
			"effect_limit_value8",
			"effect_limit_value9",
			"effect_limit_value10",
			"effect_limit_value11",
			"effect_limit_value12",
			"max1",
			"max2",
			"max3",
			"max4",
			"max5",
			"max6",
			"max7",
			"max8",
			"max9",
			"max10",
			"max11",
			"max12",
			"icon",
			"memicon",
			"components1",
			"components2",
			"components3",
			"components4",
			"component_counts1",
			"component_counts2",
			"component_counts3",
			"component_counts4",
			"NoexpendReagent1",
			"NoexpendReagent2",
			"NoexpendReagent3",
			"NoexpendReagent4",
			"formula1",
			"formula2",
			"formula3",
			"formula4",
			"formula5",
			"formula6",
			"formula7",
			"formula8",
			"formula9",
			"formula10",
			"formula11",
			"formula12",
			"LightType",
			"goodEffect",
			"Activated",
			"resisttype",
			"effectid1",
			"effectid2",
			"effectid3",
			"effectid4",
			"effectid5",
			"effectid6",
			"effectid7",
			"effectid8",
			"effectid9",
			"effectid10",
			"effectid11",
			"effectid12",
			"targettype",
			"basediff",
			"skill",
			"zonetype",
			"EnvironmentType",
			"TimeOfDay",
			"classes1",
			"classes2",
			"classes3",
			"classes4",
			"classes5",
			"classes6",
			"classes7",
			"classes8",
			"classes9",
			"classes10",
			"classes11",
			"classes12",
			"classes13",
			"classes14",
			"classes15",
			"CastingAnim",
			"TargetAnim",
			"TravelType",
			"SpellAffectIndex",
			"disallow_sit",
			"deities0",
			"deities1",
			"deities2",
			"deities3",
			"deities4",
			"deities5",
			"deities6",
			"deities7",
			"deities8",
			"deities9",
			"deities10",
			"deities11",
			"deities12",
			"deities13",
			"deities14",
			"deities15",
			"deities16",
			"npc_no_cast",
			"ai_pt_bonus",
			"new_icon",
			"spellanim",
			"uninterruptable",
			"ResistDiff",
			"dot_stacking_exempt",
			"deleteable",
			"RecourseLink",
			"no_partial_resist",
			"small_targets_only",
			"use_persistent_particles",
			"short_buff_box",
			"descnum",
			"typedescnum",
			"effectdescnum",
			"effectdescnum2",
			"npc_no_los",
			"reflectable",
			"resist_per_level",
			"resist_cap",
			"EndurCost",
			"EndurTimerIndex",
			"IsDiscipline",
			"HateAdded",
			"EndurUpkeep",
			"pvpresistbase",
			"pvpresistcalc",
			"pvpresistcap",
			"spell_category",
			"pvp_duration",
			"pvp_duration_cap",
			"cast_not_standing",
			"can_mgb",
			"nodispell",
			"npc_category",
			"npc_usefulness",
			"wear_off_message",
			"suspendable",
			"spellgroup",
			"allow_spellscribe",
			"allowrest",
			"custom_icon",
			"not_player_spell",
			"disabled",
		};
	}

	static std::vector<std::string> SelectColumns()
	{
		return {
			"id",
			"name",
			"player_1",
			"teleport_zone",
			"you_cast",
			"other_casts",
			"cast_on_you",
			"cast_on_other",
			"spell_fades",
			"range",
			"aoerange",
			"pushback",
			"pushup",
			"cast_time",
			"recovery_time",
			"recast_time",
			"buffdurationformula",
			"buffduration",
			"AEDuration",
			"mana",
			"effect_base_value1",
			"effect_base_value2",
			"effect_base_value3",
			"effect_base_value4",
			"effect_base_value5",
			"effect_base_value6",
			"effect_base_value7",
			"effect_base_value8",
			"effect_base_value9",
			"effect_base_value10",
			"effect_base_value11",
			"effect_base_value12",
			"effect_limit_value1",
			"effect_limit_value2",
			"effect_limit_value3",
			"effect_limit_value4",
			"effect_limit_value5",
			"effect_limit_value6",
			"effect_limit_value7",
			"effect_limit_value8",
			"effect_limit_value9",
			"effect_limit_value10",
			"effect_limit_value11",
			"effect_limit_value12",
			"max1",
			"max2",
			"max3",
			"max4",
			"max5",
			"max6",
			"max7",
			"max8",
			"max9",
			"max10",
			"max11",
			"max12",
			"icon",
			"memicon",
			"components1",
			"components2",
			"components3",
			"components4",
			"component_counts1",
			"component_counts2",
			"component_counts3",
			"component_counts4",
			"NoexpendReagent1",
			"NoexpendReagent2",
			"NoexpendReagent3",
			"NoexpendReagent4",
			"formula1",
			"formula2",
			"formula3",
			"formula4",
			"formula5",
			"formula6",
			"formula7",
			"formula8",
			"formula9",
			"formula10",
			"formula11",
			"formula12",
			"LightType",
			"goodEffect",
			"Activated",
			"resisttype",
			"effectid1",
			"effectid2",
			"effectid3",
			"effectid4",
			"effectid5",
			"effectid6",
			"effectid7",
			"effectid8",
			"effectid9",
			"effectid10",
			"effectid11",
			"effectid12",
			"targettype",
			"basediff",
			"skill",
			"zonetype",
			"EnvironmentType",
			"TimeOfDay",
			"classes1",
			"classes2",
			"classes3",
			"classes4",
			"classes5",
			"classes6",
			"classes7",
			"classes8",
			"classes9",
			"classes10",
			"classes11",
			"classes12",
			"classes13",
			"classes14",
			"classes15",
			"CastingAnim",
			"TargetAnim",
			"TravelType",
			"SpellAffectIndex",
			"disallow_sit",
			"deities0",
			"deities1",
			"deities2",
			"deities3",
			"deities4",
			"deities5",
			"deities6",
			"deities7",
			"deities8",
			"deities9",
			"deities10",
			"deities11",
			"deities12",
			"deities13",
			"deities14",
			"deities15",
			"deities16",
			"npc_no_cast",
			"ai_pt_bonus",
			"new_icon",
			"spellanim",
			"uninterruptable",
			"ResistDiff",
			"dot_stacking_exempt",
			"deleteable",
			"RecourseLink",
			"no_partial_resist",
			"small_targets_only",
			"use_persistent_particles",
			"short_buff_box",
			"descnum",
			"typedescnum",
			"effectdescnum",
			"effectdescnum2",
			"npc_no_los",
			"reflectable",
			"resist_per_level",
			"resist_cap",
			"EndurCost",
			"EndurTimerIndex",
			"IsDiscipline",
			"HateAdded",
			"EndurUpkeep",
			"pvpresistbase",
			"pvpresistcalc",
			"pvpresistcap",
			"spell_category",
			"pvp_duration",
			"pvp_duration_cap",
			"cast_not_standing",
			"can_mgb",
			"nodispell",
			"npc_category",
			"npc_usefulness",
			"wear_off_message",
			"suspendable",
			"spellgroup",
			"allow_spellscribe",
			"allowrest",
			"custom_icon",
			"not_player_spell",
			"disabled",
		};
	}

	static std::string ColumnsRaw()
	{
		return std::string(Strings::Implode(", ", Columns()));
	}

	static std::string SelectColumnsRaw()
	{
		return std::string(Strings::Implode(", ", SelectColumns()));
	}

	static std::string TableName()
	{
		return std::string("spells_new");
	}

	static std::string BaseSelect()
	{
		return fmt::format(
			"SELECT {} FROM {}",
			SelectColumnsRaw(),
			TableName()
		);
	}

	static std::string BaseInsert()
	{
		return fmt::format(
			"INSERT INTO {} ({}) ",
			TableName(),
			ColumnsRaw()
		);
	}

	static SpellsNew NewEntity()
	{
		SpellsNew e{};

		e.id                       = 0;
		e.name                     = "";
		e.player_1                 = "BLUE_TRAIL";
		e.teleport_zone            = "";
		e.you_cast                 = "";
		e.other_casts              = "";
		e.cast_on_you              = "";
		e.cast_on_other            = "";
		e.spell_fades              = "";
		e.range                    = 100;
		e.aoerange                 = 0;
		e.pushback                 = 0.00;
		e.pushup                   = 0.00;
		e.cast_time                = 0;
		e.recovery_time            = 0;
		e.recast_time              = 0;
		e.buffdurationformula      = 7;
		e.buffduration             = 65;
		e.AEDuration               = 0;
		e.mana                     = 0;
		e.effect_base_value1       = 100;
		e.effect_base_value2       = 0;
		e.effect_base_value3       = 0;
		e.effect_base_value4       = 0;
		e.effect_base_value5       = 0;
		e.effect_base_value6       = 0;
		e.effect_base_value7       = 0;
		e.effect_base_value8       = 0;
		e.effect_base_value9       = 0;
		e.effect_base_value10      = 0;
		e.effect_base_value11      = 0;
		e.effect_base_value12      = 0;
		e.effect_limit_value1      = 0;
		e.effect_limit_value2      = 0;
		e.effect_limit_value3      = 0;
		e.effect_limit_value4      = 0;
		e.effect_limit_value5      = 0;
		e.effect_limit_value6      = 0;
		e.effect_limit_value7      = 0;
		e.effect_limit_value8      = 0;
		e.effect_limit_value9      = 0;
		e.effect_limit_value10     = 0;
		e.effect_limit_value11     = 0;
		e.effect_limit_value12     = 0;
		e.max1                     = 0;
		e.max2                     = 0;
		e.max3                     = 0;
		e.max4                     = 0;
		e.max5                     = 0;
		e.max6                     = 0;
		e.max7                     = 0;
		e.max8                     = 0;
		e.max9                     = 0;
		e.max10                    = 0;
		e.max11                    = 0;
		e.max12                    = 0;
		e.icon                     = 0;
		e.memicon                  = 0;
		e.components1              = -1;
		e.components2              = -1;
		e.components3              = -1;
		e.components4              = -1;
		e.component_counts1        = 1;
		e.component_counts2        = 1;
		e.component_counts3        = 1;
		e.component_counts4        = 1;
		e.NoexpendReagent1         = -1;
		e.NoexpendReagent2         = -1;
		e.NoexpendReagent3         = -1;
		e.NoexpendReagent4         = -1;
		e.formula1                 = 100;
		e.formula2                 = 100;
		e.formula3                 = 100;
		e.formula4                 = 100;
		e.formula5                 = 100;
		e.formula6                 = 100;
		e.formula7                 = 100;
		e.formula8                 = 100;
		e.formula9                 = 100;
		e.formula10                = 100;
		e.formula11                = 100;
		e.formula12                = 100;
		e.LightType                = 0;
		e.goodEffect               = 0;
		e.Activated                = 0;
		e.resisttype               = 0;
		e.effectid1                = 254;
		e.effectid2                = 254;
		e.effectid3                = 254;
		e.effectid4                = 254;
		e.effectid5                = 254;
		e.effectid6                = 254;
		e.effectid7                = 254;
		e.effectid8                = 254;
		e.effectid9                = 254;
		e.effectid10               = 254;
		e.effectid11               = 254;
		e.effectid12               = 254;
		e.targettype               = 2;
		e.basediff                 = 0;
		e.skill                    = 98;
		e.zonetype                 = -1;
		e.EnvironmentType          = 0;
		e.TimeOfDay                = 0;
		e.classes1                 = 255;
		e.classes2                 = 255;
		e.classes3                 = 255;
		e.classes4                 = 255;
		e.classes5                 = 255;
		e.classes6                 = 255;
		e.classes7                 = 255;
		e.classes8                 = 255;
		e.classes9                 = 255;
		e.classes10                = 255;
		e.classes11                = 255;
		e.classes12                = 255;
		e.classes13                = 255;
		e.classes14                = 255;
		e.classes15                = 255;
		e.CastingAnim              = 44;
		e.TargetAnim               = 13;
		e.TravelType               = 0;
		e.SpellAffectIndex         = -1;
		e.disallow_sit             = 0;
		e.deities0                 = 0;
		e.deities1                 = 0;
		e.deities2                 = 0;
		e.deities3                 = 0;
		e.deities4                 = 0;
		e.deities5                 = 0;
		e.deities6                 = 0;
		e.deities7                 = 0;
		e.deities8                 = 0;
		e.deities9                 = 0;
		e.deities10                = 0;
		e.deities11                = 0;
		e.deities12                = 0;
		e.deities13                = 0;
		e.deities14                = 0;
		e.deities15                = 0;
		e.deities16                = 0;
		e.npc_no_cast              = 0;
		e.ai_pt_bonus              = 0;
		e.new_icon                 = 161;
		e.spellanim                = 0;
		e.uninterruptable          = 0;
		e.ResistDiff               = -150;
		e.dot_stacking_exempt      = 0;
		e.deleteable               = 0;
		e.RecourseLink             = 0;
		e.no_partial_resist        = 0;
		e.small_targets_only       = 0;
		e.use_persistent_particles = 0;
		e.short_buff_box           = -1;
		e.descnum                  = 0;
		e.typedescnum              = 0;
		e.effectdescnum            = 0;
		e.effectdescnum2           = 0;
		e.npc_no_los               = 0;
		e.reflectable              = 0;
		e.resist_per_level         = 0;
		e.resist_cap               = 0;
		e.EndurCost                = 0;
		e.EndurTimerIndex          = 0;
		e.IsDiscipline             = 0;
		e.HateAdded                = 0;
		e.EndurUpkeep              = 0;
		e.pvpresistbase            = -150;
		e.pvpresistcalc            = 100;
		e.pvpresistcap             = -150;
		e.spell_category           = -99;
		e.pvp_duration             = 0;
		e.pvp_duration_cap         = 0;
		e.cast_not_standing        = 0;
		e.can_mgb                  = 0;
		e.nodispell                = -1;
		e.npc_category             = 0;
		e.npc_usefulness           = 0;
		e.wear_off_message         = 0;
		e.suspendable              = 0;
		e.spellgroup               = 0;
		e.allow_spellscribe        = 0;
		e.allowrest                = 0;
		e.custom_icon              = 0;
		e.not_player_spell         = 0;
		e.disabled                 = 0;

		return e;
	}

	static SpellsNew GetSpellsNew(
		const std::vector<SpellsNew> &spells_news,
		int spells_new_id
	)
	{
		for (auto &spells_new : spells_news) {
			if (spells_new.id == spells_new_id) {
				return spells_new;
			}
		}

		return NewEntity();
	}

	static SpellsNew FindOne(
		Database& db,
		int spells_new_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {} = {} LIMIT 1",
				BaseSelect(),
				PrimaryKey(),
				spells_new_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			SpellsNew e{};

			e.id                       = static_cast<int32_t>(atoi(row[0]));
			e.name                     = row[1] ? row[1] : "";
			e.player_1                 = row[2] ? row[2] : "";
			e.teleport_zone            = row[3] ? row[3] : "";
			e.you_cast                 = row[4] ? row[4] : "";
			e.other_casts              = row[5] ? row[5] : "";
			e.cast_on_you              = row[6] ? row[6] : "";
			e.cast_on_other            = row[7] ? row[7] : "";
			e.spell_fades              = row[8] ? row[8] : "";
			e.range                    = static_cast<int32_t>(atoi(row[9]));
			e.aoerange                 = static_cast<int32_t>(atoi(row[10]));
			e.pushback                 = strtof(row[11], nullptr);
			e.pushup                   = strtof(row[12], nullptr);
			e.cast_time                = static_cast<int32_t>(atoi(row[13]));
			e.recovery_time            = static_cast<int32_t>(atoi(row[14]));
			e.recast_time              = static_cast<int32_t>(atoi(row[15]));
			e.buffdurationformula      = static_cast<int32_t>(atoi(row[16]));
			e.buffduration             = static_cast<int32_t>(atoi(row[17]));
			e.AEDuration               = static_cast<int32_t>(atoi(row[18]));
			e.mana                     = static_cast<int32_t>(atoi(row[19]));
			e.effect_base_value1       = static_cast<int32_t>(atoi(row[20]));
			e.effect_base_value2       = static_cast<int32_t>(atoi(row[21]));
			e.effect_base_value3       = static_cast<int32_t>(atoi(row[22]));
			e.effect_base_value4       = static_cast<int32_t>(atoi(row[23]));
			e.effect_base_value5       = static_cast<int32_t>(atoi(row[24]));
			e.effect_base_value6       = static_cast<int32_t>(atoi(row[25]));
			e.effect_base_value7       = static_cast<int32_t>(atoi(row[26]));
			e.effect_base_value8       = static_cast<int32_t>(atoi(row[27]));
			e.effect_base_value9       = static_cast<int32_t>(atoi(row[28]));
			e.effect_base_value10      = static_cast<int32_t>(atoi(row[29]));
			e.effect_base_value11      = static_cast<int32_t>(atoi(row[30]));
			e.effect_base_value12      = static_cast<int32_t>(atoi(row[31]));
			e.effect_limit_value1      = static_cast<int32_t>(atoi(row[32]));
			e.effect_limit_value2      = static_cast<int32_t>(atoi(row[33]));
			e.effect_limit_value3      = static_cast<int32_t>(atoi(row[34]));
			e.effect_limit_value4      = static_cast<int32_t>(atoi(row[35]));
			e.effect_limit_value5      = static_cast<int32_t>(atoi(row[36]));
			e.effect_limit_value6      = static_cast<int32_t>(atoi(row[37]));
			e.effect_limit_value7      = static_cast<int32_t>(atoi(row[38]));
			e.effect_limit_value8      = static_cast<int32_t>(atoi(row[39]));
			e.effect_limit_value9      = static_cast<int32_t>(atoi(row[40]));
			e.effect_limit_value10     = static_cast<int32_t>(atoi(row[41]));
			e.effect_limit_value11     = static_cast<int32_t>(atoi(row[42]));
			e.effect_limit_value12     = static_cast<int32_t>(atoi(row[43]));
			e.max1                     = static_cast<int32_t>(atoi(row[44]));
			e.max2                     = static_cast<int32_t>(atoi(row[45]));
			e.max3                     = static_cast<int32_t>(atoi(row[46]));
			e.max4                     = static_cast<int32_t>(atoi(row[47]));
			e.max5                     = static_cast<int32_t>(atoi(row[48]));
			e.max6                     = static_cast<int32_t>(atoi(row[49]));
			e.max7                     = static_cast<int32_t>(atoi(row[50]));
			e.max8                     = static_cast<int32_t>(atoi(row[51]));
			e.max9                     = static_cast<int32_t>(atoi(row[52]));
			e.max10                    = static_cast<int32_t>(atoi(row[53]));
			e.max11                    = static_cast<int32_t>(atoi(row[54]));
			e.max12                    = static_cast<int32_t>(atoi(row[55]));
			e.icon                     = static_cast<int32_t>(atoi(row[56]));
			e.memicon                  = static_cast<int32_t>(atoi(row[57]));
			e.components1              = static_cast<int32_t>(atoi(row[58]));
			e.components2              = static_cast<int32_t>(atoi(row[59]));
			e.components3              = static_cast<int32_t>(atoi(row[60]));
			e.components4              = static_cast<int32_t>(atoi(row[61]));
			e.component_counts1        = static_cast<int32_t>(atoi(row[62]));
			e.component_counts2        = static_cast<int32_t>(atoi(row[63]));
			e.component_counts3        = static_cast<int32_t>(atoi(row[64]));
			e.component_counts4        = static_cast<int32_t>(atoi(row[65]));
			e.NoexpendReagent1         = static_cast<int32_t>(atoi(row[66]));
			e.NoexpendReagent2         = static_cast<int32_t>(atoi(row[67]));
			e.NoexpendReagent3         = static_cast<int32_t>(atoi(row[68]));
			e.NoexpendReagent4         = static_cast<int32_t>(atoi(row[69]));
			e.formula1                 = static_cast<int32_t>(atoi(row[70]));
			e.formula2                 = static_cast<int32_t>(atoi(row[71]));
			e.formula3                 = static_cast<int32_t>(atoi(row[72]));
			e.formula4                 = static_cast<int32_t>(atoi(row[73]));
			e.formula5                 = static_cast<int32_t>(atoi(row[74]));
			e.formula6                 = static_cast<int32_t>(atoi(row[75]));
			e.formula7                 = static_cast<int32_t>(atoi(row[76]));
			e.formula8                 = static_cast<int32_t>(atoi(row[77]));
			e.formula9                 = static_cast<int32_t>(atoi(row[78]));
			e.formula10                = static_cast<int32_t>(atoi(row[79]));
			e.formula11                = static_cast<int32_t>(atoi(row[80]));
			e.formula12                = static_cast<int32_t>(atoi(row[81]));
			e.LightType                = static_cast<int32_t>(atoi(row[82]));
			e.goodEffect               = static_cast<int32_t>(atoi(row[83]));
			e.Activated                = static_cast<int32_t>(atoi(row[84]));
			e.resisttype               = static_cast<int32_t>(atoi(row[85]));
			e.effectid1                = static_cast<int32_t>(atoi(row[86]));
			e.effectid2                = static_cast<int32_t>(atoi(row[87]));
			e.effectid3                = static_cast<int32_t>(atoi(row[88]));
			e.effectid4                = static_cast<int32_t>(atoi(row[89]));
			e.effectid5                = static_cast<int32_t>(atoi(row[90]));
			e.effectid6                = static_cast<int32_t>(atoi(row[91]));
			e.effectid7                = static_cast<int32_t>(atoi(row[92]));
			e.effectid8                = static_cast<int32_t>(atoi(row[93]));
			e.effectid9                = static_cast<int32_t>(atoi(row[94]));
			e.effectid10               = static_cast<int32_t>(atoi(row[95]));
			e.effectid11               = static_cast<int32_t>(atoi(row[96]));
			e.effectid12               = static_cast<int32_t>(atoi(row[97]));
			e.targettype               = static_cast<int32_t>(atoi(row[98]));
			e.basediff                 = static_cast<int32_t>(atoi(row[99]));
			e.skill                    = static_cast<int32_t>(atoi(row[100]));
			e.zonetype                 = static_cast<int32_t>(atoi(row[101]));
			e.EnvironmentType          = static_cast<int32_t>(atoi(row[102]));
			e.TimeOfDay                = static_cast<int32_t>(atoi(row[103]));
			e.classes1                 = static_cast<int32_t>(atoi(row[104]));
			e.classes2                 = static_cast<int32_t>(atoi(row[105]));
			e.classes3                 = static_cast<int32_t>(atoi(row[106]));
			e.classes4                 = static_cast<int32_t>(atoi(row[107]));
			e.classes5                 = static_cast<int32_t>(atoi(row[108]));
			e.classes6                 = static_cast<int32_t>(atoi(row[109]));
			e.classes7                 = static_cast<int32_t>(atoi(row[110]));
			e.classes8                 = static_cast<int32_t>(atoi(row[111]));
			e.classes9                 = static_cast<int32_t>(atoi(row[112]));
			e.classes10                = static_cast<int32_t>(atoi(row[113]));
			e.classes11                = static_cast<int32_t>(atoi(row[114]));
			e.classes12                = static_cast<int32_t>(atoi(row[115]));
			e.classes13                = static_cast<int32_t>(atoi(row[116]));
			e.classes14                = static_cast<int32_t>(atoi(row[117]));
			e.classes15                = static_cast<int32_t>(atoi(row[118]));
			e.CastingAnim              = static_cast<int32_t>(atoi(row[119]));
			e.TargetAnim               = static_cast<int32_t>(atoi(row[120]));
			e.TravelType               = static_cast<int32_t>(atoi(row[121]));
			e.SpellAffectIndex         = static_cast<int32_t>(atoi(row[122]));
			e.disallow_sit             = static_cast<int32_t>(atoi(row[123]));
			e.deities0                 = static_cast<int32_t>(atoi(row[124]));
			e.deities1                 = static_cast<int32_t>(atoi(row[125]));
			e.deities2                 = static_cast<int32_t>(atoi(row[126]));
			e.deities3                 = static_cast<int32_t>(atoi(row[127]));
			e.deities4                 = static_cast<int32_t>(atoi(row[128]));
			e.deities5                 = static_cast<int32_t>(atoi(row[129]));
			e.deities6                 = static_cast<int32_t>(atoi(row[130]));
			e.deities7                 = static_cast<int32_t>(atoi(row[131]));
			e.deities8                 = static_cast<int32_t>(atoi(row[132]));
			e.deities9                 = static_cast<int32_t>(atoi(row[133]));
			e.deities10                = static_cast<int32_t>(atoi(row[134]));
			e.deities11                = static_cast<int32_t>(atoi(row[135]));
			e.deities12                = static_cast<int32_t>(atoi(row[136]));
			e.deities13                = static_cast<int32_t>(atoi(row[137]));
			e.deities14                = static_cast<int32_t>(atoi(row[138]));
			e.deities15                = static_cast<int32_t>(atoi(row[139]));
			e.deities16                = static_cast<int32_t>(atoi(row[140]));
			e.npc_no_cast              = static_cast<int32_t>(atoi(row[141]));
			e.ai_pt_bonus              = static_cast<int32_t>(atoi(row[142]));
			e.new_icon                 = static_cast<int32_t>(atoi(row[143]));
			e.spellanim                = static_cast<int32_t>(atoi(row[144]));
			e.uninterruptable          = static_cast<int32_t>(atoi(row[145]));
			e.ResistDiff               = static_cast<int32_t>(atoi(row[146]));
			e.dot_stacking_exempt      = static_cast<int32_t>(atoi(row[147]));
			e.deleteable               = static_cast<int32_t>(atoi(row[148]));
			e.RecourseLink             = static_cast<int32_t>(atoi(row[149]));
			e.no_partial_resist        = static_cast<int32_t>(atoi(row[150]));
			e.small_targets_only       = static_cast<int32_t>(atoi(row[151]));
			e.use_persistent_particles = static_cast<int32_t>(atoi(row[152]));
			e.short_buff_box           = static_cast<int32_t>(atoi(row[153]));
			e.descnum                  = static_cast<int32_t>(atoi(row[154]));
			e.typedescnum              = static_cast<int32_t>(atoi(row[155]));
			e.effectdescnum            = static_cast<int32_t>(atoi(row[156]));
			e.effectdescnum2           = static_cast<int32_t>(atoi(row[157]));
			e.npc_no_los               = static_cast<int32_t>(atoi(row[158]));
			e.reflectable              = static_cast<int32_t>(atoi(row[159]));
			e.resist_per_level         = static_cast<int32_t>(atoi(row[160]));
			e.resist_cap               = static_cast<int32_t>(atoi(row[161]));
			e.EndurCost                = static_cast<int32_t>(atoi(row[162]));
			e.EndurTimerIndex          = static_cast<int32_t>(atoi(row[163]));
			e.IsDiscipline             = static_cast<int32_t>(atoi(row[164]));
			e.HateAdded                = static_cast<int32_t>(atoi(row[165]));
			e.EndurUpkeep              = static_cast<int32_t>(atoi(row[166]));
			e.pvpresistbase            = static_cast<int32_t>(atoi(row[167]));
			e.pvpresistcalc            = static_cast<int32_t>(atoi(row[168]));
			e.pvpresistcap             = static_cast<int32_t>(atoi(row[169]));
			e.spell_category           = static_cast<int32_t>(atoi(row[170]));
			e.pvp_duration             = static_cast<int32_t>(atoi(row[171]));
			e.pvp_duration_cap         = static_cast<int32_t>(atoi(row[172]));
			e.cast_not_standing        = static_cast<int32_t>(atoi(row[173]));
			e.can_mgb                  = static_cast<int32_t>(atoi(row[174]));
			e.nodispell                = static_cast<int32_t>(atoi(row[175]));
			e.npc_category             = static_cast<int32_t>(atoi(row[176]));
			e.npc_usefulness           = static_cast<int32_t>(atoi(row[177]));
			e.wear_off_message         = static_cast<int32_t>(atoi(row[178]));
			e.suspendable              = static_cast<int32_t>(atoi(row[179]));
			e.spellgroup               = static_cast<int32_t>(atoi(row[180]));
			e.allow_spellscribe        = static_cast<int32_t>(atoi(row[181]));
			e.allowrest                = static_cast<int32_t>(atoi(row[182]));
			e.custom_icon              = static_cast<int32_t>(atoi(row[183]));
			e.not_player_spell         = static_cast<int32_t>(atoi(row[184]));
			e.disabled                 = static_cast<int8_t>(atoi(row[185]));

			return e;
		}

		return NewEntity();
	}

	static int DeleteOne(
		Database& db,
		int spells_new_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				spells_new_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		Database& db,
		const SpellsNew &e
	)
	{
		std::vector<std::string> v;

		auto columns = Columns();

		v.push_back(columns[0] + " = " + std::to_string(e.id));
		v.push_back(columns[1] + " = '" + Strings::Escape(e.name) + "'");
		v.push_back(columns[2] + " = '" + Strings::Escape(e.player_1) + "'");
		v.push_back(columns[3] + " = '" + Strings::Escape(e.teleport_zone) + "'");
		v.push_back(columns[4] + " = '" + Strings::Escape(e.you_cast) + "'");
		v.push_back(columns[5] + " = '" + Strings::Escape(e.other_casts) + "'");
		v.push_back(columns[6] + " = '" + Strings::Escape(e.cast_on_you) + "'");
		v.push_back(columns[7] + " = '" + Strings::Escape(e.cast_on_other) + "'");
		v.push_back(columns[8] + " = '" + Strings::Escape(e.spell_fades) + "'");
		v.push_back(columns[9] + " = " + std::to_string(e.range));
		v.push_back(columns[10] + " = " + std::to_string(e.aoerange));
		v.push_back(columns[11] + " = " + std::to_string(e.pushback));
		v.push_back(columns[12] + " = " + std::to_string(e.pushup));
		v.push_back(columns[13] + " = " + std::to_string(e.cast_time));
		v.push_back(columns[14] + " = " + std::to_string(e.recovery_time));
		v.push_back(columns[15] + " = " + std::to_string(e.recast_time));
		v.push_back(columns[16] + " = " + std::to_string(e.buffdurationformula));
		v.push_back(columns[17] + " = " + std::to_string(e.buffduration));
		v.push_back(columns[18] + " = " + std::to_string(e.AEDuration));
		v.push_back(columns[19] + " = " + std::to_string(e.mana));
		v.push_back(columns[20] + " = " + std::to_string(e.effect_base_value1));
		v.push_back(columns[21] + " = " + std::to_string(e.effect_base_value2));
		v.push_back(columns[22] + " = " + std::to_string(e.effect_base_value3));
		v.push_back(columns[23] + " = " + std::to_string(e.effect_base_value4));
		v.push_back(columns[24] + " = " + std::to_string(e.effect_base_value5));
		v.push_back(columns[25] + " = " + std::to_string(e.effect_base_value6));
		v.push_back(columns[26] + " = " + std::to_string(e.effect_base_value7));
		v.push_back(columns[27] + " = " + std::to_string(e.effect_base_value8));
		v.push_back(columns[28] + " = " + std::to_string(e.effect_base_value9));
		v.push_back(columns[29] + " = " + std::to_string(e.effect_base_value10));
		v.push_back(columns[30] + " = " + std::to_string(e.effect_base_value11));
		v.push_back(columns[31] + " = " + std::to_string(e.effect_base_value12));
		v.push_back(columns[32] + " = " + std::to_string(e.effect_limit_value1));
		v.push_back(columns[33] + " = " + std::to_string(e.effect_limit_value2));
		v.push_back(columns[34] + " = " + std::to_string(e.effect_limit_value3));
		v.push_back(columns[35] + " = " + std::to_string(e.effect_limit_value4));
		v.push_back(columns[36] + " = " + std::to_string(e.effect_limit_value5));
		v.push_back(columns[37] + " = " + std::to_string(e.effect_limit_value6));
		v.push_back(columns[38] + " = " + std::to_string(e.effect_limit_value7));
		v.push_back(columns[39] + " = " + std::to_string(e.effect_limit_value8));
		v.push_back(columns[40] + " = " + std::to_string(e.effect_limit_value9));
		v.push_back(columns[41] + " = " + std::to_string(e.effect_limit_value10));
		v.push_back(columns[42] + " = " + std::to_string(e.effect_limit_value11));
		v.push_back(columns[43] + " = " + std::to_string(e.effect_limit_value12));
		v.push_back(columns[44] + " = " + std::to_string(e.max1));
		v.push_back(columns[45] + " = " + std::to_string(e.max2));
		v.push_back(columns[46] + " = " + std::to_string(e.max3));
		v.push_back(columns[47] + " = " + std::to_string(e.max4));
		v.push_back(columns[48] + " = " + std::to_string(e.max5));
		v.push_back(columns[49] + " = " + std::to_string(e.max6));
		v.push_back(columns[50] + " = " + std::to_string(e.max7));
		v.push_back(columns[51] + " = " + std::to_string(e.max8));
		v.push_back(columns[52] + " = " + std::to_string(e.max9));
		v.push_back(columns[53] + " = " + std::to_string(e.max10));
		v.push_back(columns[54] + " = " + std::to_string(e.max11));
		v.push_back(columns[55] + " = " + std::to_string(e.max12));
		v.push_back(columns[56] + " = " + std::to_string(e.icon));
		v.push_back(columns[57] + " = " + std::to_string(e.memicon));
		v.push_back(columns[58] + " = " + std::to_string(e.components1));
		v.push_back(columns[59] + " = " + std::to_string(e.components2));
		v.push_back(columns[60] + " = " + std::to_string(e.components3));
		v.push_back(columns[61] + " = " + std::to_string(e.components4));
		v.push_back(columns[62] + " = " + std::to_string(e.component_counts1));
		v.push_back(columns[63] + " = " + std::to_string(e.component_counts2));
		v.push_back(columns[64] + " = " + std::to_string(e.component_counts3));
		v.push_back(columns[65] + " = " + std::to_string(e.component_counts4));
		v.push_back(columns[66] + " = " + std::to_string(e.NoexpendReagent1));
		v.push_back(columns[67] + " = " + std::to_string(e.NoexpendReagent2));
		v.push_back(columns[68] + " = " + std::to_string(e.NoexpendReagent3));
		v.push_back(columns[69] + " = " + std::to_string(e.NoexpendReagent4));
		v.push_back(columns[70] + " = " + std::to_string(e.formula1));
		v.push_back(columns[71] + " = " + std::to_string(e.formula2));
		v.push_back(columns[72] + " = " + std::to_string(e.formula3));
		v.push_back(columns[73] + " = " + std::to_string(e.formula4));
		v.push_back(columns[74] + " = " + std::to_string(e.formula5));
		v.push_back(columns[75] + " = " + std::to_string(e.formula6));
		v.push_back(columns[76] + " = " + std::to_string(e.formula7));
		v.push_back(columns[77] + " = " + std::to_string(e.formula8));
		v.push_back(columns[78] + " = " + std::to_string(e.formula9));
		v.push_back(columns[79] + " = " + std::to_string(e.formula10));
		v.push_back(columns[80] + " = " + std::to_string(e.formula11));
		v.push_back(columns[81] + " = " + std::to_string(e.formula12));
		v.push_back(columns[82] + " = " + std::to_string(e.LightType));
		v.push_back(columns[83] + " = " + std::to_string(e.goodEffect));
		v.push_back(columns[84] + " = " + std::to_string(e.Activated));
		v.push_back(columns[85] + " = " + std::to_string(e.resisttype));
		v.push_back(columns[86] + " = " + std::to_string(e.effectid1));
		v.push_back(columns[87] + " = " + std::to_string(e.effectid2));
		v.push_back(columns[88] + " = " + std::to_string(e.effectid3));
		v.push_back(columns[89] + " = " + std::to_string(e.effectid4));
		v.push_back(columns[90] + " = " + std::to_string(e.effectid5));
		v.push_back(columns[91] + " = " + std::to_string(e.effectid6));
		v.push_back(columns[92] + " = " + std::to_string(e.effectid7));
		v.push_back(columns[93] + " = " + std::to_string(e.effectid8));
		v.push_back(columns[94] + " = " + std::to_string(e.effectid9));
		v.push_back(columns[95] + " = " + std::to_string(e.effectid10));
		v.push_back(columns[96] + " = " + std::to_string(e.effectid11));
		v.push_back(columns[97] + " = " + std::to_string(e.effectid12));
		v.push_back(columns[98] + " = " + std::to_string(e.targettype));
		v.push_back(columns[99] + " = " + std::to_string(e.basediff));
		v.push_back(columns[100] + " = " + std::to_string(e.skill));
		v.push_back(columns[101] + " = " + std::to_string(e.zonetype));
		v.push_back(columns[102] + " = " + std::to_string(e.EnvironmentType));
		v.push_back(columns[103] + " = " + std::to_string(e.TimeOfDay));
		v.push_back(columns[104] + " = " + std::to_string(e.classes1));
		v.push_back(columns[105] + " = " + std::to_string(e.classes2));
		v.push_back(columns[106] + " = " + std::to_string(e.classes3));
		v.push_back(columns[107] + " = " + std::to_string(e.classes4));
		v.push_back(columns[108] + " = " + std::to_string(e.classes5));
		v.push_back(columns[109] + " = " + std::to_string(e.classes6));
		v.push_back(columns[110] + " = " + std::to_string(e.classes7));
		v.push_back(columns[111] + " = " + std::to_string(e.classes8));
		v.push_back(columns[112] + " = " + std::to_string(e.classes9));
		v.push_back(columns[113] + " = " + std::to_string(e.classes10));
		v.push_back(columns[114] + " = " + std::to_string(e.classes11));
		v.push_back(columns[115] + " = " + std::to_string(e.classes12));
		v.push_back(columns[116] + " = " + std::to_string(e.classes13));
		v.push_back(columns[117] + " = " + std::to_string(e.classes14));
		v.push_back(columns[118] + " = " + std::to_string(e.classes15));
		v.push_back(columns[119] + " = " + std::to_string(e.CastingAnim));
		v.push_back(columns[120] + " = " + std::to_string(e.TargetAnim));
		v.push_back(columns[121] + " = " + std::to_string(e.TravelType));
		v.push_back(columns[122] + " = " + std::to_string(e.SpellAffectIndex));
		v.push_back(columns[123] + " = " + std::to_string(e.disallow_sit));
		v.push_back(columns[124] + " = " + std::to_string(e.deities0));
		v.push_back(columns[125] + " = " + std::to_string(e.deities1));
		v.push_back(columns[126] + " = " + std::to_string(e.deities2));
		v.push_back(columns[127] + " = " + std::to_string(e.deities3));
		v.push_back(columns[128] + " = " + std::to_string(e.deities4));
		v.push_back(columns[129] + " = " + std::to_string(e.deities5));
		v.push_back(columns[130] + " = " + std::to_string(e.deities6));
		v.push_back(columns[131] + " = " + std::to_string(e.deities7));
		v.push_back(columns[132] + " = " + std::to_string(e.deities8));
		v.push_back(columns[133] + " = " + std::to_string(e.deities9));
		v.push_back(columns[134] + " = " + std::to_string(e.deities10));
		v.push_back(columns[135] + " = " + std::to_string(e.deities11));
		v.push_back(columns[136] + " = " + std::to_string(e.deities12));
		v.push_back(columns[137] + " = " + std::to_string(e.deities13));
		v.push_back(columns[138] + " = " + std::to_string(e.deities14));
		v.push_back(columns[139] + " = " + std::to_string(e.deities15));
		v.push_back(columns[140] + " = " + std::to_string(e.deities16));
		v.push_back(columns[141] + " = " + std::to_string(e.npc_no_cast));
		v.push_back(columns[142] + " = " + std::to_string(e.ai_pt_bonus));
		v.push_back(columns[143] + " = " + std::to_string(e.new_icon));
		v.push_back(columns[144] + " = " + std::to_string(e.spellanim));
		v.push_back(columns[145] + " = " + std::to_string(e.uninterruptable));
		v.push_back(columns[146] + " = " + std::to_string(e.ResistDiff));
		v.push_back(columns[147] + " = " + std::to_string(e.dot_stacking_exempt));
		v.push_back(columns[148] + " = " + std::to_string(e.deleteable));
		v.push_back(columns[149] + " = " + std::to_string(e.RecourseLink));
		v.push_back(columns[150] + " = " + std::to_string(e.no_partial_resist));
		v.push_back(columns[151] + " = " + std::to_string(e.small_targets_only));
		v.push_back(columns[152] + " = " + std::to_string(e.use_persistent_particles));
		v.push_back(columns[153] + " = " + std::to_string(e.short_buff_box));
		v.push_back(columns[154] + " = " + std::to_string(e.descnum));
		v.push_back(columns[155] + " = " + std::to_string(e.typedescnum));
		v.push_back(columns[156] + " = " + std::to_string(e.effectdescnum));
		v.push_back(columns[157] + " = " + std::to_string(e.effectdescnum2));
		v.push_back(columns[158] + " = " + std::to_string(e.npc_no_los));
		v.push_back(columns[159] + " = " + std::to_string(e.reflectable));
		v.push_back(columns[160] + " = " + std::to_string(e.resist_per_level));
		v.push_back(columns[161] + " = " + std::to_string(e.resist_cap));
		v.push_back(columns[162] + " = " + std::to_string(e.EndurCost));
		v.push_back(columns[163] + " = " + std::to_string(e.EndurTimerIndex));
		v.push_back(columns[164] + " = " + std::to_string(e.IsDiscipline));
		v.push_back(columns[165] + " = " + std::to_string(e.HateAdded));
		v.push_back(columns[166] + " = " + std::to_string(e.EndurUpkeep));
		v.push_back(columns[167] + " = " + std::to_string(e.pvpresistbase));
		v.push_back(columns[168] + " = " + std::to_string(e.pvpresistcalc));
		v.push_back(columns[169] + " = " + std::to_string(e.pvpresistcap));
		v.push_back(columns[170] + " = " + std::to_string(e.spell_category));
		v.push_back(columns[171] + " = " + std::to_string(e.pvp_duration));
		v.push_back(columns[172] + " = " + std::to_string(e.pvp_duration_cap));
		v.push_back(columns[173] + " = " + std::to_string(e.cast_not_standing));
		v.push_back(columns[174] + " = " + std::to_string(e.can_mgb));
		v.push_back(columns[175] + " = " + std::to_string(e.nodispell));
		v.push_back(columns[176] + " = " + std::to_string(e.npc_category));
		v.push_back(columns[177] + " = " + std::to_string(e.npc_usefulness));
		v.push_back(columns[178] + " = " + std::to_string(e.wear_off_message));
		v.push_back(columns[179] + " = " + std::to_string(e.suspendable));
		v.push_back(columns[180] + " = " + std::to_string(e.spellgroup));
		v.push_back(columns[181] + " = " + std::to_string(e.allow_spellscribe));
		v.push_back(columns[182] + " = " + std::to_string(e.allowrest));
		v.push_back(columns[183] + " = " + std::to_string(e.custom_icon));
		v.push_back(columns[184] + " = " + std::to_string(e.not_player_spell));
		v.push_back(columns[185] + " = " + std::to_string(e.disabled));

		auto results = db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				Strings::Implode(", ", v),
				PrimaryKey(),
				e.id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static SpellsNew InsertOne(
		Database& db,
		SpellsNew e
	)
	{
		std::vector<std::string> v;

		v.push_back(std::to_string(e.id));
		v.push_back("'" + Strings::Escape(e.name) + "'");
		v.push_back("'" + Strings::Escape(e.player_1) + "'");
		v.push_back("'" + Strings::Escape(e.teleport_zone) + "'");
		v.push_back("'" + Strings::Escape(e.you_cast) + "'");
		v.push_back("'" + Strings::Escape(e.other_casts) + "'");
		v.push_back("'" + Strings::Escape(e.cast_on_you) + "'");
		v.push_back("'" + Strings::Escape(e.cast_on_other) + "'");
		v.push_back("'" + Strings::Escape(e.spell_fades) + "'");
		v.push_back(std::to_string(e.range));
		v.push_back(std::to_string(e.aoerange));
		v.push_back(std::to_string(e.pushback));
		v.push_back(std::to_string(e.pushup));
		v.push_back(std::to_string(e.cast_time));
		v.push_back(std::to_string(e.recovery_time));
		v.push_back(std::to_string(e.recast_time));
		v.push_back(std::to_string(e.buffdurationformula));
		v.push_back(std::to_string(e.buffduration));
		v.push_back(std::to_string(e.AEDuration));
		v.push_back(std::to_string(e.mana));
		v.push_back(std::to_string(e.effect_base_value1));
		v.push_back(std::to_string(e.effect_base_value2));
		v.push_back(std::to_string(e.effect_base_value3));
		v.push_back(std::to_string(e.effect_base_value4));
		v.push_back(std::to_string(e.effect_base_value5));
		v.push_back(std::to_string(e.effect_base_value6));
		v.push_back(std::to_string(e.effect_base_value7));
		v.push_back(std::to_string(e.effect_base_value8));
		v.push_back(std::to_string(e.effect_base_value9));
		v.push_back(std::to_string(e.effect_base_value10));
		v.push_back(std::to_string(e.effect_base_value11));
		v.push_back(std::to_string(e.effect_base_value12));
		v.push_back(std::to_string(e.effect_limit_value1));
		v.push_back(std::to_string(e.effect_limit_value2));
		v.push_back(std::to_string(e.effect_limit_value3));
		v.push_back(std::to_string(e.effect_limit_value4));
		v.push_back(std::to_string(e.effect_limit_value5));
		v.push_back(std::to_string(e.effect_limit_value6));
		v.push_back(std::to_string(e.effect_limit_value7));
		v.push_back(std::to_string(e.effect_limit_value8));
		v.push_back(std::to_string(e.effect_limit_value9));
		v.push_back(std::to_string(e.effect_limit_value10));
		v.push_back(std::to_string(e.effect_limit_value11));
		v.push_back(std::to_string(e.effect_limit_value12));
		v.push_back(std::to_string(e.max1));
		v.push_back(std::to_string(e.max2));
		v.push_back(std::to_string(e.max3));
		v.push_back(std::to_string(e.max4));
		v.push_back(std::to_string(e.max5));
		v.push_back(std::to_string(e.max6));
		v.push_back(std::to_string(e.max7));
		v.push_back(std::to_string(e.max8));
		v.push_back(std::to_string(e.max9));
		v.push_back(std::to_string(e.max10));
		v.push_back(std::to_string(e.max11));
		v.push_back(std::to_string(e.max12));
		v.push_back(std::to_string(e.icon));
		v.push_back(std::to_string(e.memicon));
		v.push_back(std::to_string(e.components1));
		v.push_back(std::to_string(e.components2));
		v.push_back(std::to_string(e.components3));
		v.push_back(std::to_string(e.components4));
		v.push_back(std::to_string(e.component_counts1));
		v.push_back(std::to_string(e.component_counts2));
		v.push_back(std::to_string(e.component_counts3));
		v.push_back(std::to_string(e.component_counts4));
		v.push_back(std::to_string(e.NoexpendReagent1));
		v.push_back(std::to_string(e.NoexpendReagent2));
		v.push_back(std::to_string(e.NoexpendReagent3));
		v.push_back(std::to_string(e.NoexpendReagent4));
		v.push_back(std::to_string(e.formula1));
		v.push_back(std::to_string(e.formula2));
		v.push_back(std::to_string(e.formula3));
		v.push_back(std::to_string(e.formula4));
		v.push_back(std::to_string(e.formula5));
		v.push_back(std::to_string(e.formula6));
		v.push_back(std::to_string(e.formula7));
		v.push_back(std::to_string(e.formula8));
		v.push_back(std::to_string(e.formula9));
		v.push_back(std::to_string(e.formula10));
		v.push_back(std::to_string(e.formula11));
		v.push_back(std::to_string(e.formula12));
		v.push_back(std::to_string(e.LightType));
		v.push_back(std::to_string(e.goodEffect));
		v.push_back(std::to_string(e.Activated));
		v.push_back(std::to_string(e.resisttype));
		v.push_back(std::to_string(e.effectid1));
		v.push_back(std::to_string(e.effectid2));
		v.push_back(std::to_string(e.effectid3));
		v.push_back(std::to_string(e.effectid4));
		v.push_back(std::to_string(e.effectid5));
		v.push_back(std::to_string(e.effectid6));
		v.push_back(std::to_string(e.effectid7));
		v.push_back(std::to_string(e.effectid8));
		v.push_back(std::to_string(e.effectid9));
		v.push_back(std::to_string(e.effectid10));
		v.push_back(std::to_string(e.effectid11));
		v.push_back(std::to_string(e.effectid12));
		v.push_back(std::to_string(e.targettype));
		v.push_back(std::to_string(e.basediff));
		v.push_back(std::to_string(e.skill));
		v.push_back(std::to_string(e.zonetype));
		v.push_back(std::to_string(e.EnvironmentType));
		v.push_back(std::to_string(e.TimeOfDay));
		v.push_back(std::to_string(e.classes1));
		v.push_back(std::to_string(e.classes2));
		v.push_back(std::to_string(e.classes3));
		v.push_back(std::to_string(e.classes4));
		v.push_back(std::to_string(e.classes5));
		v.push_back(std::to_string(e.classes6));
		v.push_back(std::to_string(e.classes7));
		v.push_back(std::to_string(e.classes8));
		v.push_back(std::to_string(e.classes9));
		v.push_back(std::to_string(e.classes10));
		v.push_back(std::to_string(e.classes11));
		v.push_back(std::to_string(e.classes12));
		v.push_back(std::to_string(e.classes13));
		v.push_back(std::to_string(e.classes14));
		v.push_back(std::to_string(e.classes15));
		v.push_back(std::to_string(e.CastingAnim));
		v.push_back(std::to_string(e.TargetAnim));
		v.push_back(std::to_string(e.TravelType));
		v.push_back(std::to_string(e.SpellAffectIndex));
		v.push_back(std::to_string(e.disallow_sit));
		v.push_back(std::to_string(e.deities0));
		v.push_back(std::to_string(e.deities1));
		v.push_back(std::to_string(e.deities2));
		v.push_back(std::to_string(e.deities3));
		v.push_back(std::to_string(e.deities4));
		v.push_back(std::to_string(e.deities5));
		v.push_back(std::to_string(e.deities6));
		v.push_back(std::to_string(e.deities7));
		v.push_back(std::to_string(e.deities8));
		v.push_back(std::to_string(e.deities9));
		v.push_back(std::to_string(e.deities10));
		v.push_back(std::to_string(e.deities11));
		v.push_back(std::to_string(e.deities12));
		v.push_back(std::to_string(e.deities13));
		v.push_back(std::to_string(e.deities14));
		v.push_back(std::to_string(e.deities15));
		v.push_back(std::to_string(e.deities16));
		v.push_back(std::to_string(e.npc_no_cast));
		v.push_back(std::to_string(e.ai_pt_bonus));
		v.push_back(std::to_string(e.new_icon));
		v.push_back(std::to_string(e.spellanim));
		v.push_back(std::to_string(e.uninterruptable));
		v.push_back(std::to_string(e.ResistDiff));
		v.push_back(std::to_string(e.dot_stacking_exempt));
		v.push_back(std::to_string(e.deleteable));
		v.push_back(std::to_string(e.RecourseLink));
		v.push_back(std::to_string(e.no_partial_resist));
		v.push_back(std::to_string(e.small_targets_only));
		v.push_back(std::to_string(e.use_persistent_particles));
		v.push_back(std::to_string(e.short_buff_box));
		v.push_back(std::to_string(e.descnum));
		v.push_back(std::to_string(e.typedescnum));
		v.push_back(std::to_string(e.effectdescnum));
		v.push_back(std::to_string(e.effectdescnum2));
		v.push_back(std::to_string(e.npc_no_los));
		v.push_back(std::to_string(e.reflectable));
		v.push_back(std::to_string(e.resist_per_level));
		v.push_back(std::to_string(e.resist_cap));
		v.push_back(std::to_string(e.EndurCost));
		v.push_back(std::to_string(e.EndurTimerIndex));
		v.push_back(std::to_string(e.IsDiscipline));
		v.push_back(std::to_string(e.HateAdded));
		v.push_back(std::to_string(e.EndurUpkeep));
		v.push_back(std::to_string(e.pvpresistbase));
		v.push_back(std::to_string(e.pvpresistcalc));
		v.push_back(std::to_string(e.pvpresistcap));
		v.push_back(std::to_string(e.spell_category));
		v.push_back(std::to_string(e.pvp_duration));
		v.push_back(std::to_string(e.pvp_duration_cap));
		v.push_back(std::to_string(e.cast_not_standing));
		v.push_back(std::to_string(e.can_mgb));
		v.push_back(std::to_string(e.nodispell));
		v.push_back(std::to_string(e.npc_category));
		v.push_back(std::to_string(e.npc_usefulness));
		v.push_back(std::to_string(e.wear_off_message));
		v.push_back(std::to_string(e.suspendable));
		v.push_back(std::to_string(e.spellgroup));
		v.push_back(std::to_string(e.allow_spellscribe));
		v.push_back(std::to_string(e.allowrest));
		v.push_back(std::to_string(e.custom_icon));
		v.push_back(std::to_string(e.not_player_spell));
		v.push_back(std::to_string(e.disabled));

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				Strings::Implode(",", v)
			)
		);

		if (results.Success()) {
			e.id = results.LastInsertedID();
			return e;
		}

		e = NewEntity();

		return e;
	}

	static int InsertMany(
		Database& db,
		const std::vector<SpellsNew> &entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &e: entries) {
			std::vector<std::string> v;

			v.push_back(std::to_string(e.id));
			v.push_back("'" + Strings::Escape(e.name) + "'");
			v.push_back("'" + Strings::Escape(e.player_1) + "'");
			v.push_back("'" + Strings::Escape(e.teleport_zone) + "'");
			v.push_back("'" + Strings::Escape(e.you_cast) + "'");
			v.push_back("'" + Strings::Escape(e.other_casts) + "'");
			v.push_back("'" + Strings::Escape(e.cast_on_you) + "'");
			v.push_back("'" + Strings::Escape(e.cast_on_other) + "'");
			v.push_back("'" + Strings::Escape(e.spell_fades) + "'");
			v.push_back(std::to_string(e.range));
			v.push_back(std::to_string(e.aoerange));
			v.push_back(std::to_string(e.pushback));
			v.push_back(std::to_string(e.pushup));
			v.push_back(std::to_string(e.cast_time));
			v.push_back(std::to_string(e.recovery_time));
			v.push_back(std::to_string(e.recast_time));
			v.push_back(std::to_string(e.buffdurationformula));
			v.push_back(std::to_string(e.buffduration));
			v.push_back(std::to_string(e.AEDuration));
			v.push_back(std::to_string(e.mana));
			v.push_back(std::to_string(e.effect_base_value1));
			v.push_back(std::to_string(e.effect_base_value2));
			v.push_back(std::to_string(e.effect_base_value3));
			v.push_back(std::to_string(e.effect_base_value4));
			v.push_back(std::to_string(e.effect_base_value5));
			v.push_back(std::to_string(e.effect_base_value6));
			v.push_back(std::to_string(e.effect_base_value7));
			v.push_back(std::to_string(e.effect_base_value8));
			v.push_back(std::to_string(e.effect_base_value9));
			v.push_back(std::to_string(e.effect_base_value10));
			v.push_back(std::to_string(e.effect_base_value11));
			v.push_back(std::to_string(e.effect_base_value12));
			v.push_back(std::to_string(e.effect_limit_value1));
			v.push_back(std::to_string(e.effect_limit_value2));
			v.push_back(std::to_string(e.effect_limit_value3));
			v.push_back(std::to_string(e.effect_limit_value4));
			v.push_back(std::to_string(e.effect_limit_value5));
			v.push_back(std::to_string(e.effect_limit_value6));
			v.push_back(std::to_string(e.effect_limit_value7));
			v.push_back(std::to_string(e.effect_limit_value8));
			v.push_back(std::to_string(e.effect_limit_value9));
			v.push_back(std::to_string(e.effect_limit_value10));
			v.push_back(std::to_string(e.effect_limit_value11));
			v.push_back(std::to_string(e.effect_limit_value12));
			v.push_back(std::to_string(e.max1));
			v.push_back(std::to_string(e.max2));
			v.push_back(std::to_string(e.max3));
			v.push_back(std::to_string(e.max4));
			v.push_back(std::to_string(e.max5));
			v.push_back(std::to_string(e.max6));
			v.push_back(std::to_string(e.max7));
			v.push_back(std::to_string(e.max8));
			v.push_back(std::to_string(e.max9));
			v.push_back(std::to_string(e.max10));
			v.push_back(std::to_string(e.max11));
			v.push_back(std::to_string(e.max12));
			v.push_back(std::to_string(e.icon));
			v.push_back(std::to_string(e.memicon));
			v.push_back(std::to_string(e.components1));
			v.push_back(std::to_string(e.components2));
			v.push_back(std::to_string(e.components3));
			v.push_back(std::to_string(e.components4));
			v.push_back(std::to_string(e.component_counts1));
			v.push_back(std::to_string(e.component_counts2));
			v.push_back(std::to_string(e.component_counts3));
			v.push_back(std::to_string(e.component_counts4));
			v.push_back(std::to_string(e.NoexpendReagent1));
			v.push_back(std::to_string(e.NoexpendReagent2));
			v.push_back(std::to_string(e.NoexpendReagent3));
			v.push_back(std::to_string(e.NoexpendReagent4));
			v.push_back(std::to_string(e.formula1));
			v.push_back(std::to_string(e.formula2));
			v.push_back(std::to_string(e.formula3));
			v.push_back(std::to_string(e.formula4));
			v.push_back(std::to_string(e.formula5));
			v.push_back(std::to_string(e.formula6));
			v.push_back(std::to_string(e.formula7));
			v.push_back(std::to_string(e.formula8));
			v.push_back(std::to_string(e.formula9));
			v.push_back(std::to_string(e.formula10));
			v.push_back(std::to_string(e.formula11));
			v.push_back(std::to_string(e.formula12));
			v.push_back(std::to_string(e.LightType));
			v.push_back(std::to_string(e.goodEffect));
			v.push_back(std::to_string(e.Activated));
			v.push_back(std::to_string(e.resisttype));
			v.push_back(std::to_string(e.effectid1));
			v.push_back(std::to_string(e.effectid2));
			v.push_back(std::to_string(e.effectid3));
			v.push_back(std::to_string(e.effectid4));
			v.push_back(std::to_string(e.effectid5));
			v.push_back(std::to_string(e.effectid6));
			v.push_back(std::to_string(e.effectid7));
			v.push_back(std::to_string(e.effectid8));
			v.push_back(std::to_string(e.effectid9));
			v.push_back(std::to_string(e.effectid10));
			v.push_back(std::to_string(e.effectid11));
			v.push_back(std::to_string(e.effectid12));
			v.push_back(std::to_string(e.targettype));
			v.push_back(std::to_string(e.basediff));
			v.push_back(std::to_string(e.skill));
			v.push_back(std::to_string(e.zonetype));
			v.push_back(std::to_string(e.EnvironmentType));
			v.push_back(std::to_string(e.TimeOfDay));
			v.push_back(std::to_string(e.classes1));
			v.push_back(std::to_string(e.classes2));
			v.push_back(std::to_string(e.classes3));
			v.push_back(std::to_string(e.classes4));
			v.push_back(std::to_string(e.classes5));
			v.push_back(std::to_string(e.classes6));
			v.push_back(std::to_string(e.classes7));
			v.push_back(std::to_string(e.classes8));
			v.push_back(std::to_string(e.classes9));
			v.push_back(std::to_string(e.classes10));
			v.push_back(std::to_string(e.classes11));
			v.push_back(std::to_string(e.classes12));
			v.push_back(std::to_string(e.classes13));
			v.push_back(std::to_string(e.classes14));
			v.push_back(std::to_string(e.classes15));
			v.push_back(std::to_string(e.CastingAnim));
			v.push_back(std::to_string(e.TargetAnim));
			v.push_back(std::to_string(e.TravelType));
			v.push_back(std::to_string(e.SpellAffectIndex));
			v.push_back(std::to_string(e.disallow_sit));
			v.push_back(std::to_string(e.deities0));
			v.push_back(std::to_string(e.deities1));
			v.push_back(std::to_string(e.deities2));
			v.push_back(std::to_string(e.deities3));
			v.push_back(std::to_string(e.deities4));
			v.push_back(std::to_string(e.deities5));
			v.push_back(std::to_string(e.deities6));
			v.push_back(std::to_string(e.deities7));
			v.push_back(std::to_string(e.deities8));
			v.push_back(std::to_string(e.deities9));
			v.push_back(std::to_string(e.deities10));
			v.push_back(std::to_string(e.deities11));
			v.push_back(std::to_string(e.deities12));
			v.push_back(std::to_string(e.deities13));
			v.push_back(std::to_string(e.deities14));
			v.push_back(std::to_string(e.deities15));
			v.push_back(std::to_string(e.deities16));
			v.push_back(std::to_string(e.npc_no_cast));
			v.push_back(std::to_string(e.ai_pt_bonus));
			v.push_back(std::to_string(e.new_icon));
			v.push_back(std::to_string(e.spellanim));
			v.push_back(std::to_string(e.uninterruptable));
			v.push_back(std::to_string(e.ResistDiff));
			v.push_back(std::to_string(e.dot_stacking_exempt));
			v.push_back(std::to_string(e.deleteable));
			v.push_back(std::to_string(e.RecourseLink));
			v.push_back(std::to_string(e.no_partial_resist));
			v.push_back(std::to_string(e.small_targets_only));
			v.push_back(std::to_string(e.use_persistent_particles));
			v.push_back(std::to_string(e.short_buff_box));
			v.push_back(std::to_string(e.descnum));
			v.push_back(std::to_string(e.typedescnum));
			v.push_back(std::to_string(e.effectdescnum));
			v.push_back(std::to_string(e.effectdescnum2));
			v.push_back(std::to_string(e.npc_no_los));
			v.push_back(std::to_string(e.reflectable));
			v.push_back(std::to_string(e.resist_per_level));
			v.push_back(std::to_string(e.resist_cap));
			v.push_back(std::to_string(e.EndurCost));
			v.push_back(std::to_string(e.EndurTimerIndex));
			v.push_back(std::to_string(e.IsDiscipline));
			v.push_back(std::to_string(e.HateAdded));
			v.push_back(std::to_string(e.EndurUpkeep));
			v.push_back(std::to_string(e.pvpresistbase));
			v.push_back(std::to_string(e.pvpresistcalc));
			v.push_back(std::to_string(e.pvpresistcap));
			v.push_back(std::to_string(e.spell_category));
			v.push_back(std::to_string(e.pvp_duration));
			v.push_back(std::to_string(e.pvp_duration_cap));
			v.push_back(std::to_string(e.cast_not_standing));
			v.push_back(std::to_string(e.can_mgb));
			v.push_back(std::to_string(e.nodispell));
			v.push_back(std::to_string(e.npc_category));
			v.push_back(std::to_string(e.npc_usefulness));
			v.push_back(std::to_string(e.wear_off_message));
			v.push_back(std::to_string(e.suspendable));
			v.push_back(std::to_string(e.spellgroup));
			v.push_back(std::to_string(e.allow_spellscribe));
			v.push_back(std::to_string(e.allowrest));
			v.push_back(std::to_string(e.custom_icon));
			v.push_back(std::to_string(e.not_player_spell));
			v.push_back(std::to_string(e.disabled));

			insert_chunks.push_back("(" + Strings::Implode(",", v) + ")");
		}

		std::vector<std::string> v;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES {}",
				BaseInsert(),
				Strings::Implode(",", insert_chunks)
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static std::vector<SpellsNew> All(Database& db)
	{
		std::vector<SpellsNew> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			SpellsNew e{};

			e.id                       = static_cast<int32_t>(atoi(row[0]));
			e.name                     = row[1] ? row[1] : "";
			e.player_1                 = row[2] ? row[2] : "";
			e.teleport_zone            = row[3] ? row[3] : "";
			e.you_cast                 = row[4] ? row[4] : "";
			e.other_casts              = row[5] ? row[5] : "";
			e.cast_on_you              = row[6] ? row[6] : "";
			e.cast_on_other            = row[7] ? row[7] : "";
			e.spell_fades              = row[8] ? row[8] : "";
			e.range                    = static_cast<int32_t>(atoi(row[9]));
			e.aoerange                 = static_cast<int32_t>(atoi(row[10]));
			e.pushback                 = strtof(row[11], nullptr);
			e.pushup                   = strtof(row[12], nullptr);
			e.cast_time                = static_cast<int32_t>(atoi(row[13]));
			e.recovery_time            = static_cast<int32_t>(atoi(row[14]));
			e.recast_time              = static_cast<int32_t>(atoi(row[15]));
			e.buffdurationformula      = static_cast<int32_t>(atoi(row[16]));
			e.buffduration             = static_cast<int32_t>(atoi(row[17]));
			e.AEDuration               = static_cast<int32_t>(atoi(row[18]));
			e.mana                     = static_cast<int32_t>(atoi(row[19]));
			e.effect_base_value1       = static_cast<int32_t>(atoi(row[20]));
			e.effect_base_value2       = static_cast<int32_t>(atoi(row[21]));
			e.effect_base_value3       = static_cast<int32_t>(atoi(row[22]));
			e.effect_base_value4       = static_cast<int32_t>(atoi(row[23]));
			e.effect_base_value5       = static_cast<int32_t>(atoi(row[24]));
			e.effect_base_value6       = static_cast<int32_t>(atoi(row[25]));
			e.effect_base_value7       = static_cast<int32_t>(atoi(row[26]));
			e.effect_base_value8       = static_cast<int32_t>(atoi(row[27]));
			e.effect_base_value9       = static_cast<int32_t>(atoi(row[28]));
			e.effect_base_value10      = static_cast<int32_t>(atoi(row[29]));
			e.effect_base_value11      = static_cast<int32_t>(atoi(row[30]));
			e.effect_base_value12      = static_cast<int32_t>(atoi(row[31]));
			e.effect_limit_value1      = static_cast<int32_t>(atoi(row[32]));
			e.effect_limit_value2      = static_cast<int32_t>(atoi(row[33]));
			e.effect_limit_value3      = static_cast<int32_t>(atoi(row[34]));
			e.effect_limit_value4      = static_cast<int32_t>(atoi(row[35]));
			e.effect_limit_value5      = static_cast<int32_t>(atoi(row[36]));
			e.effect_limit_value6      = static_cast<int32_t>(atoi(row[37]));
			e.effect_limit_value7      = static_cast<int32_t>(atoi(row[38]));
			e.effect_limit_value8      = static_cast<int32_t>(atoi(row[39]));
			e.effect_limit_value9      = static_cast<int32_t>(atoi(row[40]));
			e.effect_limit_value10     = static_cast<int32_t>(atoi(row[41]));
			e.effect_limit_value11     = static_cast<int32_t>(atoi(row[42]));
			e.effect_limit_value12     = static_cast<int32_t>(atoi(row[43]));
			e.max1                     = static_cast<int32_t>(atoi(row[44]));
			e.max2                     = static_cast<int32_t>(atoi(row[45]));
			e.max3                     = static_cast<int32_t>(atoi(row[46]));
			e.max4                     = static_cast<int32_t>(atoi(row[47]));
			e.max5                     = static_cast<int32_t>(atoi(row[48]));
			e.max6                     = static_cast<int32_t>(atoi(row[49]));
			e.max7                     = static_cast<int32_t>(atoi(row[50]));
			e.max8                     = static_cast<int32_t>(atoi(row[51]));
			e.max9                     = static_cast<int32_t>(atoi(row[52]));
			e.max10                    = static_cast<int32_t>(atoi(row[53]));
			e.max11                    = static_cast<int32_t>(atoi(row[54]));
			e.max12                    = static_cast<int32_t>(atoi(row[55]));
			e.icon                     = static_cast<int32_t>(atoi(row[56]));
			e.memicon                  = static_cast<int32_t>(atoi(row[57]));
			e.components1              = static_cast<int32_t>(atoi(row[58]));
			e.components2              = static_cast<int32_t>(atoi(row[59]));
			e.components3              = static_cast<int32_t>(atoi(row[60]));
			e.components4              = static_cast<int32_t>(atoi(row[61]));
			e.component_counts1        = static_cast<int32_t>(atoi(row[62]));
			e.component_counts2        = static_cast<int32_t>(atoi(row[63]));
			e.component_counts3        = static_cast<int32_t>(atoi(row[64]));
			e.component_counts4        = static_cast<int32_t>(atoi(row[65]));
			e.NoexpendReagent1         = static_cast<int32_t>(atoi(row[66]));
			e.NoexpendReagent2         = static_cast<int32_t>(atoi(row[67]));
			e.NoexpendReagent3         = static_cast<int32_t>(atoi(row[68]));
			e.NoexpendReagent4         = static_cast<int32_t>(atoi(row[69]));
			e.formula1                 = static_cast<int32_t>(atoi(row[70]));
			e.formula2                 = static_cast<int32_t>(atoi(row[71]));
			e.formula3                 = static_cast<int32_t>(atoi(row[72]));
			e.formula4                 = static_cast<int32_t>(atoi(row[73]));
			e.formula5                 = static_cast<int32_t>(atoi(row[74]));
			e.formula6                 = static_cast<int32_t>(atoi(row[75]));
			e.formula7                 = static_cast<int32_t>(atoi(row[76]));
			e.formula8                 = static_cast<int32_t>(atoi(row[77]));
			e.formula9                 = static_cast<int32_t>(atoi(row[78]));
			e.formula10                = static_cast<int32_t>(atoi(row[79]));
			e.formula11                = static_cast<int32_t>(atoi(row[80]));
			e.formula12                = static_cast<int32_t>(atoi(row[81]));
			e.LightType                = static_cast<int32_t>(atoi(row[82]));
			e.goodEffect               = static_cast<int32_t>(atoi(row[83]));
			e.Activated                = static_cast<int32_t>(atoi(row[84]));
			e.resisttype               = static_cast<int32_t>(atoi(row[85]));
			e.effectid1                = static_cast<int32_t>(atoi(row[86]));
			e.effectid2                = static_cast<int32_t>(atoi(row[87]));
			e.effectid3                = static_cast<int32_t>(atoi(row[88]));
			e.effectid4                = static_cast<int32_t>(atoi(row[89]));
			e.effectid5                = static_cast<int32_t>(atoi(row[90]));
			e.effectid6                = static_cast<int32_t>(atoi(row[91]));
			e.effectid7                = static_cast<int32_t>(atoi(row[92]));
			e.effectid8                = static_cast<int32_t>(atoi(row[93]));
			e.effectid9                = static_cast<int32_t>(atoi(row[94]));
			e.effectid10               = static_cast<int32_t>(atoi(row[95]));
			e.effectid11               = static_cast<int32_t>(atoi(row[96]));
			e.effectid12               = static_cast<int32_t>(atoi(row[97]));
			e.targettype               = static_cast<int32_t>(atoi(row[98]));
			e.basediff                 = static_cast<int32_t>(atoi(row[99]));
			e.skill                    = static_cast<int32_t>(atoi(row[100]));
			e.zonetype                 = static_cast<int32_t>(atoi(row[101]));
			e.EnvironmentType          = static_cast<int32_t>(atoi(row[102]));
			e.TimeOfDay                = static_cast<int32_t>(atoi(row[103]));
			e.classes1                 = static_cast<int32_t>(atoi(row[104]));
			e.classes2                 = static_cast<int32_t>(atoi(row[105]));
			e.classes3                 = static_cast<int32_t>(atoi(row[106]));
			e.classes4                 = static_cast<int32_t>(atoi(row[107]));
			e.classes5                 = static_cast<int32_t>(atoi(row[108]));
			e.classes6                 = static_cast<int32_t>(atoi(row[109]));
			e.classes7                 = static_cast<int32_t>(atoi(row[110]));
			e.classes8                 = static_cast<int32_t>(atoi(row[111]));
			e.classes9                 = static_cast<int32_t>(atoi(row[112]));
			e.classes10                = static_cast<int32_t>(atoi(row[113]));
			e.classes11                = static_cast<int32_t>(atoi(row[114]));
			e.classes12                = static_cast<int32_t>(atoi(row[115]));
			e.classes13                = static_cast<int32_t>(atoi(row[116]));
			e.classes14                = static_cast<int32_t>(atoi(row[117]));
			e.classes15                = static_cast<int32_t>(atoi(row[118]));
			e.CastingAnim              = static_cast<int32_t>(atoi(row[119]));
			e.TargetAnim               = static_cast<int32_t>(atoi(row[120]));
			e.TravelType               = static_cast<int32_t>(atoi(row[121]));
			e.SpellAffectIndex         = static_cast<int32_t>(atoi(row[122]));
			e.disallow_sit             = static_cast<int32_t>(atoi(row[123]));
			e.deities0                 = static_cast<int32_t>(atoi(row[124]));
			e.deities1                 = static_cast<int32_t>(atoi(row[125]));
			e.deities2                 = static_cast<int32_t>(atoi(row[126]));
			e.deities3                 = static_cast<int32_t>(atoi(row[127]));
			e.deities4                 = static_cast<int32_t>(atoi(row[128]));
			e.deities5                 = static_cast<int32_t>(atoi(row[129]));
			e.deities6                 = static_cast<int32_t>(atoi(row[130]));
			e.deities7                 = static_cast<int32_t>(atoi(row[131]));
			e.deities8                 = static_cast<int32_t>(atoi(row[132]));
			e.deities9                 = static_cast<int32_t>(atoi(row[133]));
			e.deities10                = static_cast<int32_t>(atoi(row[134]));
			e.deities11                = static_cast<int32_t>(atoi(row[135]));
			e.deities12                = static_cast<int32_t>(atoi(row[136]));
			e.deities13                = static_cast<int32_t>(atoi(row[137]));
			e.deities14                = static_cast<int32_t>(atoi(row[138]));
			e.deities15                = static_cast<int32_t>(atoi(row[139]));
			e.deities16                = static_cast<int32_t>(atoi(row[140]));
			e.npc_no_cast              = static_cast<int32_t>(atoi(row[141]));
			e.ai_pt_bonus              = static_cast<int32_t>(atoi(row[142]));
			e.new_icon                 = static_cast<int32_t>(atoi(row[143]));
			e.spellanim                = static_cast<int32_t>(atoi(row[144]));
			e.uninterruptable          = static_cast<int32_t>(atoi(row[145]));
			e.ResistDiff               = static_cast<int32_t>(atoi(row[146]));
			e.dot_stacking_exempt      = static_cast<int32_t>(atoi(row[147]));
			e.deleteable               = static_cast<int32_t>(atoi(row[148]));
			e.RecourseLink             = static_cast<int32_t>(atoi(row[149]));
			e.no_partial_resist        = static_cast<int32_t>(atoi(row[150]));
			e.small_targets_only       = static_cast<int32_t>(atoi(row[151]));
			e.use_persistent_particles = static_cast<int32_t>(atoi(row[152]));
			e.short_buff_box           = static_cast<int32_t>(atoi(row[153]));
			e.descnum                  = static_cast<int32_t>(atoi(row[154]));
			e.typedescnum              = static_cast<int32_t>(atoi(row[155]));
			e.effectdescnum            = static_cast<int32_t>(atoi(row[156]));
			e.effectdescnum2           = static_cast<int32_t>(atoi(row[157]));
			e.npc_no_los               = static_cast<int32_t>(atoi(row[158]));
			e.reflectable              = static_cast<int32_t>(atoi(row[159]));
			e.resist_per_level         = static_cast<int32_t>(atoi(row[160]));
			e.resist_cap               = static_cast<int32_t>(atoi(row[161]));
			e.EndurCost                = static_cast<int32_t>(atoi(row[162]));
			e.EndurTimerIndex          = static_cast<int32_t>(atoi(row[163]));
			e.IsDiscipline             = static_cast<int32_t>(atoi(row[164]));
			e.HateAdded                = static_cast<int32_t>(atoi(row[165]));
			e.EndurUpkeep              = static_cast<int32_t>(atoi(row[166]));
			e.pvpresistbase            = static_cast<int32_t>(atoi(row[167]));
			e.pvpresistcalc            = static_cast<int32_t>(atoi(row[168]));
			e.pvpresistcap             = static_cast<int32_t>(atoi(row[169]));
			e.spell_category           = static_cast<int32_t>(atoi(row[170]));
			e.pvp_duration             = static_cast<int32_t>(atoi(row[171]));
			e.pvp_duration_cap         = static_cast<int32_t>(atoi(row[172]));
			e.cast_not_standing        = static_cast<int32_t>(atoi(row[173]));
			e.can_mgb                  = static_cast<int32_t>(atoi(row[174]));
			e.nodispell                = static_cast<int32_t>(atoi(row[175]));
			e.npc_category             = static_cast<int32_t>(atoi(row[176]));
			e.npc_usefulness           = static_cast<int32_t>(atoi(row[177]));
			e.wear_off_message         = static_cast<int32_t>(atoi(row[178]));
			e.suspendable              = static_cast<int32_t>(atoi(row[179]));
			e.spellgroup               = static_cast<int32_t>(atoi(row[180]));
			e.allow_spellscribe        = static_cast<int32_t>(atoi(row[181]));
			e.allowrest                = static_cast<int32_t>(atoi(row[182]));
			e.custom_icon              = static_cast<int32_t>(atoi(row[183]));
			e.not_player_spell         = static_cast<int32_t>(atoi(row[184]));
			e.disabled                 = static_cast<int8_t>(atoi(row[185]));

			all_entries.push_back(e);
		}

		return all_entries;
	}

	static std::vector<SpellsNew> GetWhere(Database& db, const std::string &where_filter)
	{
		std::vector<SpellsNew> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {}",
				BaseSelect(),
				where_filter
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			SpellsNew e{};

			e.id                       = static_cast<int32_t>(atoi(row[0]));
			e.name                     = row[1] ? row[1] : "";
			e.player_1                 = row[2] ? row[2] : "";
			e.teleport_zone            = row[3] ? row[3] : "";
			e.you_cast                 = row[4] ? row[4] : "";
			e.other_casts              = row[5] ? row[5] : "";
			e.cast_on_you              = row[6] ? row[6] : "";
			e.cast_on_other            = row[7] ? row[7] : "";
			e.spell_fades              = row[8] ? row[8] : "";
			e.range                    = static_cast<int32_t>(atoi(row[9]));
			e.aoerange                 = static_cast<int32_t>(atoi(row[10]));
			e.pushback                 = strtof(row[11], nullptr);
			e.pushup                   = strtof(row[12], nullptr);
			e.cast_time                = static_cast<int32_t>(atoi(row[13]));
			e.recovery_time            = static_cast<int32_t>(atoi(row[14]));
			e.recast_time              = static_cast<int32_t>(atoi(row[15]));
			e.buffdurationformula      = static_cast<int32_t>(atoi(row[16]));
			e.buffduration             = static_cast<int32_t>(atoi(row[17]));
			e.AEDuration               = static_cast<int32_t>(atoi(row[18]));
			e.mana                     = static_cast<int32_t>(atoi(row[19]));
			e.effect_base_value1       = static_cast<int32_t>(atoi(row[20]));
			e.effect_base_value2       = static_cast<int32_t>(atoi(row[21]));
			e.effect_base_value3       = static_cast<int32_t>(atoi(row[22]));
			e.effect_base_value4       = static_cast<int32_t>(atoi(row[23]));
			e.effect_base_value5       = static_cast<int32_t>(atoi(row[24]));
			e.effect_base_value6       = static_cast<int32_t>(atoi(row[25]));
			e.effect_base_value7       = static_cast<int32_t>(atoi(row[26]));
			e.effect_base_value8       = static_cast<int32_t>(atoi(row[27]));
			e.effect_base_value9       = static_cast<int32_t>(atoi(row[28]));
			e.effect_base_value10      = static_cast<int32_t>(atoi(row[29]));
			e.effect_base_value11      = static_cast<int32_t>(atoi(row[30]));
			e.effect_base_value12      = static_cast<int32_t>(atoi(row[31]));
			e.effect_limit_value1      = static_cast<int32_t>(atoi(row[32]));
			e.effect_limit_value2      = static_cast<int32_t>(atoi(row[33]));
			e.effect_limit_value3      = static_cast<int32_t>(atoi(row[34]));
			e.effect_limit_value4      = static_cast<int32_t>(atoi(row[35]));
			e.effect_limit_value5      = static_cast<int32_t>(atoi(row[36]));
			e.effect_limit_value6      = static_cast<int32_t>(atoi(row[37]));
			e.effect_limit_value7      = static_cast<int32_t>(atoi(row[38]));
			e.effect_limit_value8      = static_cast<int32_t>(atoi(row[39]));
			e.effect_limit_value9      = static_cast<int32_t>(atoi(row[40]));
			e.effect_limit_value10     = static_cast<int32_t>(atoi(row[41]));
			e.effect_limit_value11     = static_cast<int32_t>(atoi(row[42]));
			e.effect_limit_value12     = static_cast<int32_t>(atoi(row[43]));
			e.max1                     = static_cast<int32_t>(atoi(row[44]));
			e.max2                     = static_cast<int32_t>(atoi(row[45]));
			e.max3                     = static_cast<int32_t>(atoi(row[46]));
			e.max4                     = static_cast<int32_t>(atoi(row[47]));
			e.max5                     = static_cast<int32_t>(atoi(row[48]));
			e.max6                     = static_cast<int32_t>(atoi(row[49]));
			e.max7                     = static_cast<int32_t>(atoi(row[50]));
			e.max8                     = static_cast<int32_t>(atoi(row[51]));
			e.max9                     = static_cast<int32_t>(atoi(row[52]));
			e.max10                    = static_cast<int32_t>(atoi(row[53]));
			e.max11                    = static_cast<int32_t>(atoi(row[54]));
			e.max12                    = static_cast<int32_t>(atoi(row[55]));
			e.icon                     = static_cast<int32_t>(atoi(row[56]));
			e.memicon                  = static_cast<int32_t>(atoi(row[57]));
			e.components1              = static_cast<int32_t>(atoi(row[58]));
			e.components2              = static_cast<int32_t>(atoi(row[59]));
			e.components3              = static_cast<int32_t>(atoi(row[60]));
			e.components4              = static_cast<int32_t>(atoi(row[61]));
			e.component_counts1        = static_cast<int32_t>(atoi(row[62]));
			e.component_counts2        = static_cast<int32_t>(atoi(row[63]));
			e.component_counts3        = static_cast<int32_t>(atoi(row[64]));
			e.component_counts4        = static_cast<int32_t>(atoi(row[65]));
			e.NoexpendReagent1         = static_cast<int32_t>(atoi(row[66]));
			e.NoexpendReagent2         = static_cast<int32_t>(atoi(row[67]));
			e.NoexpendReagent3         = static_cast<int32_t>(atoi(row[68]));
			e.NoexpendReagent4         = static_cast<int32_t>(atoi(row[69]));
			e.formula1                 = static_cast<int32_t>(atoi(row[70]));
			e.formula2                 = static_cast<int32_t>(atoi(row[71]));
			e.formula3                 = static_cast<int32_t>(atoi(row[72]));
			e.formula4                 = static_cast<int32_t>(atoi(row[73]));
			e.formula5                 = static_cast<int32_t>(atoi(row[74]));
			e.formula6                 = static_cast<int32_t>(atoi(row[75]));
			e.formula7                 = static_cast<int32_t>(atoi(row[76]));
			e.formula8                 = static_cast<int32_t>(atoi(row[77]));
			e.formula9                 = static_cast<int32_t>(atoi(row[78]));
			e.formula10                = static_cast<int32_t>(atoi(row[79]));
			e.formula11                = static_cast<int32_t>(atoi(row[80]));
			e.formula12                = static_cast<int32_t>(atoi(row[81]));
			e.LightType                = static_cast<int32_t>(atoi(row[82]));
			e.goodEffect               = static_cast<int32_t>(atoi(row[83]));
			e.Activated                = static_cast<int32_t>(atoi(row[84]));
			e.resisttype               = static_cast<int32_t>(atoi(row[85]));
			e.effectid1                = static_cast<int32_t>(atoi(row[86]));
			e.effectid2                = static_cast<int32_t>(atoi(row[87]));
			e.effectid3                = static_cast<int32_t>(atoi(row[88]));
			e.effectid4                = static_cast<int32_t>(atoi(row[89]));
			e.effectid5                = static_cast<int32_t>(atoi(row[90]));
			e.effectid6                = static_cast<int32_t>(atoi(row[91]));
			e.effectid7                = static_cast<int32_t>(atoi(row[92]));
			e.effectid8                = static_cast<int32_t>(atoi(row[93]));
			e.effectid9                = static_cast<int32_t>(atoi(row[94]));
			e.effectid10               = static_cast<int32_t>(atoi(row[95]));
			e.effectid11               = static_cast<int32_t>(atoi(row[96]));
			e.effectid12               = static_cast<int32_t>(atoi(row[97]));
			e.targettype               = static_cast<int32_t>(atoi(row[98]));
			e.basediff                 = static_cast<int32_t>(atoi(row[99]));
			e.skill                    = static_cast<int32_t>(atoi(row[100]));
			e.zonetype                 = static_cast<int32_t>(atoi(row[101]));
			e.EnvironmentType          = static_cast<int32_t>(atoi(row[102]));
			e.TimeOfDay                = static_cast<int32_t>(atoi(row[103]));
			e.classes1                 = static_cast<int32_t>(atoi(row[104]));
			e.classes2                 = static_cast<int32_t>(atoi(row[105]));
			e.classes3                 = static_cast<int32_t>(atoi(row[106]));
			e.classes4                 = static_cast<int32_t>(atoi(row[107]));
			e.classes5                 = static_cast<int32_t>(atoi(row[108]));
			e.classes6                 = static_cast<int32_t>(atoi(row[109]));
			e.classes7                 = static_cast<int32_t>(atoi(row[110]));
			e.classes8                 = static_cast<int32_t>(atoi(row[111]));
			e.classes9                 = static_cast<int32_t>(atoi(row[112]));
			e.classes10                = static_cast<int32_t>(atoi(row[113]));
			e.classes11                = static_cast<int32_t>(atoi(row[114]));
			e.classes12                = static_cast<int32_t>(atoi(row[115]));
			e.classes13                = static_cast<int32_t>(atoi(row[116]));
			e.classes14                = static_cast<int32_t>(atoi(row[117]));
			e.classes15                = static_cast<int32_t>(atoi(row[118]));
			e.CastingAnim              = static_cast<int32_t>(atoi(row[119]));
			e.TargetAnim               = static_cast<int32_t>(atoi(row[120]));
			e.TravelType               = static_cast<int32_t>(atoi(row[121]));
			e.SpellAffectIndex         = static_cast<int32_t>(atoi(row[122]));
			e.disallow_sit             = static_cast<int32_t>(atoi(row[123]));
			e.deities0                 = static_cast<int32_t>(atoi(row[124]));
			e.deities1                 = static_cast<int32_t>(atoi(row[125]));
			e.deities2                 = static_cast<int32_t>(atoi(row[126]));
			e.deities3                 = static_cast<int32_t>(atoi(row[127]));
			e.deities4                 = static_cast<int32_t>(atoi(row[128]));
			e.deities5                 = static_cast<int32_t>(atoi(row[129]));
			e.deities6                 = static_cast<int32_t>(atoi(row[130]));
			e.deities7                 = static_cast<int32_t>(atoi(row[131]));
			e.deities8                 = static_cast<int32_t>(atoi(row[132]));
			e.deities9                 = static_cast<int32_t>(atoi(row[133]));
			e.deities10                = static_cast<int32_t>(atoi(row[134]));
			e.deities11                = static_cast<int32_t>(atoi(row[135]));
			e.deities12                = static_cast<int32_t>(atoi(row[136]));
			e.deities13                = static_cast<int32_t>(atoi(row[137]));
			e.deities14                = static_cast<int32_t>(atoi(row[138]));
			e.deities15                = static_cast<int32_t>(atoi(row[139]));
			e.deities16                = static_cast<int32_t>(atoi(row[140]));
			e.npc_no_cast              = static_cast<int32_t>(atoi(row[141]));
			e.ai_pt_bonus              = static_cast<int32_t>(atoi(row[142]));
			e.new_icon                 = static_cast<int32_t>(atoi(row[143]));
			e.spellanim                = static_cast<int32_t>(atoi(row[144]));
			e.uninterruptable          = static_cast<int32_t>(atoi(row[145]));
			e.ResistDiff               = static_cast<int32_t>(atoi(row[146]));
			e.dot_stacking_exempt      = static_cast<int32_t>(atoi(row[147]));
			e.deleteable               = static_cast<int32_t>(atoi(row[148]));
			e.RecourseLink             = static_cast<int32_t>(atoi(row[149]));
			e.no_partial_resist        = static_cast<int32_t>(atoi(row[150]));
			e.small_targets_only       = static_cast<int32_t>(atoi(row[151]));
			e.use_persistent_particles = static_cast<int32_t>(atoi(row[152]));
			e.short_buff_box           = static_cast<int32_t>(atoi(row[153]));
			e.descnum                  = static_cast<int32_t>(atoi(row[154]));
			e.typedescnum              = static_cast<int32_t>(atoi(row[155]));
			e.effectdescnum            = static_cast<int32_t>(atoi(row[156]));
			e.effectdescnum2           = static_cast<int32_t>(atoi(row[157]));
			e.npc_no_los               = static_cast<int32_t>(atoi(row[158]));
			e.reflectable              = static_cast<int32_t>(atoi(row[159]));
			e.resist_per_level         = static_cast<int32_t>(atoi(row[160]));
			e.resist_cap               = static_cast<int32_t>(atoi(row[161]));
			e.EndurCost                = static_cast<int32_t>(atoi(row[162]));
			e.EndurTimerIndex          = static_cast<int32_t>(atoi(row[163]));
			e.IsDiscipline             = static_cast<int32_t>(atoi(row[164]));
			e.HateAdded                = static_cast<int32_t>(atoi(row[165]));
			e.EndurUpkeep              = static_cast<int32_t>(atoi(row[166]));
			e.pvpresistbase            = static_cast<int32_t>(atoi(row[167]));
			e.pvpresistcalc            = static_cast<int32_t>(atoi(row[168]));
			e.pvpresistcap             = static_cast<int32_t>(atoi(row[169]));
			e.spell_category           = static_cast<int32_t>(atoi(row[170]));
			e.pvp_duration             = static_cast<int32_t>(atoi(row[171]));
			e.pvp_duration_cap         = static_cast<int32_t>(atoi(row[172]));
			e.cast_not_standing        = static_cast<int32_t>(atoi(row[173]));
			e.can_mgb                  = static_cast<int32_t>(atoi(row[174]));
			e.nodispell                = static_cast<int32_t>(atoi(row[175]));
			e.npc_category             = static_cast<int32_t>(atoi(row[176]));
			e.npc_usefulness           = static_cast<int32_t>(atoi(row[177]));
			e.wear_off_message         = static_cast<int32_t>(atoi(row[178]));
			e.suspendable              = static_cast<int32_t>(atoi(row[179]));
			e.spellgroup               = static_cast<int32_t>(atoi(row[180]));
			e.allow_spellscribe        = static_cast<int32_t>(atoi(row[181]));
			e.allowrest                = static_cast<int32_t>(atoi(row[182]));
			e.custom_icon              = static_cast<int32_t>(atoi(row[183]));
			e.not_player_spell         = static_cast<int32_t>(atoi(row[184]));
			e.disabled                 = static_cast<int8_t>(atoi(row[185]));

			all_entries.push_back(e);
		}

		return all_entries;
	}

	static int DeleteWhere(Database& db, const std::string &where_filter)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {}",
				TableName(),
				where_filter
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int Truncate(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"TRUNCATE TABLE {}",
				TableName()
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int64 GetMaxId(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"SELECT COALESCE(MAX({}), 0) FROM {}",
				PrimaryKey(),
				TableName()
			)
		);

		return (results.Success() && results.begin()[0] ? strtoll(results.begin()[0], nullptr, 10) : 0);
	}

	static int64 Count(Database& db, const std::string &where_filter = "")
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"SELECT COUNT(*) FROM {} {}",
				TableName(),
				(where_filter.empty() ? "" : "WHERE " + where_filter)
			)
		);

		return (results.Success() && results.begin()[0] ? strtoll(results.begin()[0], nullptr, 10) : 0);
	}

};

#endif //EQEMU_BASE_SPELLS_NEW_REPOSITORY_H
