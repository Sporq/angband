#ifndef INCLUDED_DEFINES_H
#define INCLUDED_DEFINES_H

/*
 * Copyright (c) 1997 Ben Harrison, James E. Wilson, Robert A. Koeneke
 *
 * This software may be copied and distributed for educational, research,
 * and not for profit purposes provided that this copyright and statement
 * are included in all such copies.  Other copyrights may also apply.
 */


/*
 * Do not edit this file unless you know *exactly* what you are doing.
 *
 * Some of the values in this file were chosen to preserve game balance,
 * while others are hard-coded based on the format of old save-files, the
 * definition of arrays in various places, mathematical properties, fast
 * computation, storage limits, or the format of external text files.
 *
 * Changing some of these values will induce crashes or memory errors or
 * savefile mis-reads.  Most of the comments in this file are meant as
 * reminders, not complete descriptions, and even a complete knowledge
 * of the source may not be sufficient to fully understand the effects
 * of changing certain definitions.
 *
 * Lastly, note that the code does not always use the symbolic constants
 * below, and sometimes uses various hard-coded values that may not even
 * be defined in this file, but which may be related to definitions here.
 * This is of course bad programming practice, but nobody is perfect...
 *
 * You have been warned.
 */


/*
 * Number of grids in each block (vertically)
 * Probably hard-coded to 11, see "generate.c"
 */
#define BLOCK_HGT	11

/*
 * Number of grids in each block (horizontally)
 * Probably hard-coded to 11, see "generate.c"
 */
#define BLOCK_WID	11

/**
 * Number of grids in each panel (vertically)
 */
#define PANEL_HGT	((int)(BLOCK_HGT / tile_height))

/**
 * Number of grids in each panel (horizontally)
 */
#define PANEL_WID 	((int)(BLOCK_WID / tile_width))


/**
 * Number of text rows in each map screen, regardless of tile size
 */
#define SCREEN_ROWS	(Term->hgt - ROW_MAP - 1) 

/**
 * Number of grids in each screen (vertically)
 */
#define SCREEN_HGT    ((int) (SCREEN_ROWS / tile_height))

/**
 * Number of grids in each screen (horizontally)
 */
#define SCREEN_WID	((int)((Term->wid - COL_MAP - 1) / tile_width))

#define ROW_MAP			1
#define COL_MAP			13


/*
 * Number of grids in each dungeon (vertically)
 * Must be a multiple of SCREEN_HGT
 * Must be less or equal to 256
 */
#define DUNGEON_HGT		66

/*
 * Number of grids in each dungeon (horizontally)
 * Must be a multiple of SCREEN_WID
 * Must be less or equal to 256
 */
#define DUNGEON_WID		198

#define TOWN_WID 66
#define TOWN_HGT 22


/*
 * Maximum amount of Angband windows.
 */
#define ANGBAND_TERM_MAX 8



/* The fixed amount of energy a player should have at the start of a new level */
#define INITIAL_DUNGEON_ENERGY 100

/*
 * Maximum number of player "sex" types (see "table.c", etc)
 */
#define MAX_SEXES            3


/*
 * Number of tval/min-sval/max-sval slots per ego_item
 */
#define EGO_TVALS_MAX 3


/*
 * Hack -- Maximum number of quests
 */
#define MAX_Q_IDX	4


/*
 * Maximum dungeon level.  The player can never reach this level
 * in the dungeon, and this value is used for various calculations
 * involving object and monster creation.  It must be at least 100.
 * Setting it below 128 may prevent the creation of some objects.
 */
#define MAX_DEPTH	128


/*
 * Maximum size of the "view" array (see "cave.c")
 * Note that the "view radius" will NEVER exceed 20, and even if the "view"
 * was octagonal, we would never require more than 1520 entries in the array.
 */
#define VIEW_MAX 1536

/*
 * Maximum size of the "temp" array (see "cave.c")
 * Note that we must be as large as "VIEW_MAX" for proper functioning
 * of the "update_view()" function, and we must also be as large as the
 * largest illuminatable room, but no room is larger than 800 grids.  We
 * must also be large enough to allow "good enough" use as a circular queue,
 * to calculate monster flow, but note that the flow code is "paranoid".
 */
#define TEMP_MAX 1536

/* History message types */
#define HISTORY_PLAYER_BIRTH     0x0001	/* Player was born */
#define HISTORY_ARTIFACT_UNKNOWN 0x0002	/* Player found but not IDd an artifact */
#define HISTORY_ARTIFACT_KNOWN   0x0004	/* Player has IDed an artifact */
#define HISTORY_ARTIFACT_LOST    0x0008	/* Player had an artifact and lost it */
#define HISTORY_PLAYER_DEATH     0x0010	/* Player has been slain */
#define HISTORY_SLAY_UNIQUE      0x0020	/* Player has slain a unique monster */
#define HISTORY_USER_INPUT       0x0040	/* User-added note */
#define HISTORY_SAVEFILE_IMPORT  0x0080	/* Added when an older version savefile is imported */
#define HISTORY_GAIN_LEVEL       0x0100	/* Player gained a level */
#define HISTORY_GENERIC          0x0200	/* Anything else not covered here (unused) */


/*
 * Misc constants
 */
#define TOWN_DAWN		10000	/* Number of turns from dawn to dawn */
#define TOWN_DUSK         5000    /* Number of turns from dawn to dusk */
#define BREAK_GLYPH		550	/* Rune of protection resistance */
#define BTH_PLUS_ADJ    	3 	/* Adjust BTH per plus-to-hit */
#define MON_MULT_ADJ		8 	/* High value slows multiplication */
#define MON_DRAIN_LIFE		2	/* Percent of player exp drained per hit */


/*
 * There is a 1/50 (2%) chance of inflating the requested monster level
 * during the creation of a monsters (see "get_mon_num()" in "monster.c").
 * Lower values yield harder monsters more often.
 */
#define NASTY_MON    25        /* 1/chance of inflated monster level */
#define MON_OOD_MAX  10        /* maximum out-of-depth amount */

/*
 * Refueling constants
 */
#define FUEL_TORCH                5000  /* Maximum amount of fuel in a torch */
#define FUEL_LAMP                15000  /* Maximum amount of fuel in a lantern */
#define DEFAULT_TORCH       FUEL_TORCH  /* Default amount of fuel in a torch */
#define DEFAULT_LAMP   (FUEL_LAMP / 2)  /* Default amount of fuel in a lantern */


/*
 * More maximum values
 */
#define MAX_SIGHT	20	/* Maximum view distance */
#define MAX_RANGE	20	/* Maximum range (spells, etc) */



/*
 * There is a 1/160 chance per round of creating a new monster
 */
#define MAX_M_ALLOC_CHANCE	160

/*
 * Normal levels get at least 14 monsters
 */
#define MIN_M_ALLOC_LEVEL	14

/*
 * The town starts out with 4 residents during the day
 */
#define MIN_M_ALLOC_TD		4

/*
 * The town starts out with 8 residents during the night
 */
#define MIN_M_ALLOC_TN		8


/*
 * A monster can only "multiply" (reproduce) if there are fewer than 100
 * monsters on the level capable of such spontaneous reproduction.  This
 * is a hack which prevents the "mon_list[]" array from exploding due to
 * reproducing monsters.  Messy, but necessary.
 */
#define MAX_REPRO	100


/*
 * Player constants
 */
#define PY_MAX_EXP	99999999L	/* Maximum exp */
#define PY_MAX_GOLD	999999999L	/* Maximum gold */
#define PY_MAX_LEVEL	50		/* Maximum level */

/*
 * Player "food" crucial values
 */
#define PY_FOOD_UPPER   20000   /* Upper limit on food counter */
#define PY_FOOD_MAX	15000	/* Food value (Bloated) */
#define PY_FOOD_FULL	10000	/* Food value (Normal) */
#define PY_FOOD_ALERT	2000	/* Food value (Hungry) */
#define PY_FOOD_WEAK	1000	/* Food value (Weak) */
#define PY_FOOD_FAINT	500	/* Food value (Fainting) */
#define PY_FOOD_STARVE	100	/* Food value (Starving) */

/*
 * Player regeneration constants
 */
#define PY_REGEN_NORMAL		197	/* Regen factor*2^16 when full */
#define PY_REGEN_WEAK		98	/* Regen factor*2^16 when weak */
#define PY_REGEN_FAINT		33	/* Regen factor*2^16 when fainting */
#define PY_REGEN_HPBASE		1442	/* Min amount hp regen*2^16 */
#define PY_REGEN_MNBASE		524	/* Min amount mana regen*2^16 */


/*
 * Maximum number of players spells
 */
#define PY_MAX_SPELLS 64

/*
 * Flags for player_type.spell_flags[]
 */
#define PY_SPELL_LEARNED    0x01 /* Spell has been learned */
#define PY_SPELL_WORKED     0x02 /* Spell has been successfully tried */
#define PY_SPELL_FORGOTTEN  0x04 /* Spell has been forgotten */


/*
 * Maximum number of "normal" pack slots, and the index of the "overflow"
 * slot, which can hold an item, but only temporarily, since it causes the
 * pack to "overflow", dropping the "last" item onto the ground.  Since this
 * value is used as an actual slot, it must be less than "INVEN_WIELD" (below).
 * Note that "INVEN_PACK" is probably hard-coded by its use in savefiles, and
 * by the fact that the screen can only show 23 items plus a one-line prompt.
 */
#define INVEN_PACK        23

/*
 * Like the previous but takes into account the (variably full quiver).
 */
#define INVEN_MAX_PACK  (INVEN_PACK - p_ptr->quiver_slots)

/*
 * Indexes used for various "equipment" slots (hard-coded by savefiles, etc).
 */
#define INVEN_WIELD	24
#define INVEN_BOW       25
#define INVEN_LEFT      26
#define INVEN_RIGHT     27
#define INVEN_NECK      28
#define INVEN_LIGHT     29
#define INVEN_BODY      30
#define INVEN_OUTER     31
#define INVEN_ARM       32
#define INVEN_HEAD      33
#define INVEN_HANDS     34
#define INVEN_FEET      35

/*
 * Total number of inventory slots (hard-coded).
 */
#define INVEN_TOTAL	36


/*
 *Quiver
 */
#define QUIVER_START 	37
#define QUIVER_SIZE  	10
#define QUIVER_END   	47

#define ALL_INVEN_TOTAL 47


/*
 * A "stack" of items is limited to less than 100 items (hard-coded).
 */
#define MAX_STACK_SIZE 100


/*
 * An item's pval (for charges, amount of gold, etc) is limited to s16b
 */
#define MAX_PVAL  32767


/*
 * Maximum number of objects allowed in a single dungeon grid.
 *
 * The main-screen has a minimum size of 24 rows, so we can always
 * display 23 objects + 1 header line.
 */
#define MAX_FLOOR_STACK			23


/*** Constants for accessing the player struct ***/

/*
 * Timed effects
 */
enum
{
	TMD_FAST = 0, TMD_SLOW, TMD_BLIND, TMD_PARALYZED, TMD_CONFUSED,
	TMD_AFRAID, TMD_IMAGE, TMD_POISONED, TMD_CUT, TMD_STUN, TMD_PROTEVIL,
	TMD_INVULN, TMD_HERO, TMD_SHERO, TMD_SHIELD, TMD_BLESSED, TMD_SINVIS,
	TMD_SINFRA, TMD_OPP_ACID, TMD_OPP_ELEC, TMD_OPP_FIRE, TMD_OPP_COLD,
	TMD_OPP_POIS, TMD_OPP_CONF, TMD_AMNESIA, TMD_TELEPATHY, TMD_STONESKIN,
	TMD_TERROR, TMD_SPRINT,

	TMD_MAX
};

/*
 * Skill indexes
 */
enum
{
	SKILL_DISARM,			/* Skill: Disarming */
	SKILL_DEVICE,			/* Skill: Magic Devices */
	SKILL_SAVE,			/* Skill: Saving throw */
	SKILL_STEALTH,			/* Skill: Stealth factor */
	SKILL_SEARCH,			/* Skill: Searching ability */
	SKILL_SEARCH_FREQUENCY,		/* Skill: Searching frequency */
	SKILL_TO_HIT_MELEE,		/* Skill: To hit (normal) */
	SKILL_TO_HIT_BOW,		/* Skill: To hit (shooting) */
	SKILL_TO_HIT_THROW,		/* Skill: To hit (throwing) */
	SKILL_DIGGING,			/* Skill: Digging */

	SKILL_MAX
};


/*
 * Indexes of the various "stats" (hard-coded by savefiles, etc).
 */
enum
{
	A_STR = 0,
	A_INT,
	A_WIS,
	A_DEX,
	A_CON,
	A_CHR,

	A_MAX
};

/*
 * The range of possible indexes into tables based upon stats.
 * Currently things range from 3 to 18/220 = 40.
 */
#define STAT_RANGE 38


/*
 * Player sex constants (hard-coded by save-files, arrays, etc)
 */
#define SEX_FEMALE		0
#define SEX_MALE		1


/* 
 * Special values for the number of turns to rest, these need to be
 * negative numbers, as postive numbers are taken to be a turncount,
 * and zero means "not resting". 
 */
enum 
{
	REST_COMPLETE = -2,
	REST_ALL_POINTS = -1,
	REST_SOME_POINTS = -3
};



/*** General index values ***/

/*
 * Spell types used by project(), and related functions.
 */
enum
{
	#define GF(x) GF_##x,
	#include "list-gf-types.h"
	#undef GF
	GF_MAX
};


/*
 * Keymap modes.
 */
enum
{
	KEYMAP_MODE_ORIG = 0,
	KEYMAP_MODE_ROGUE,

	KEYMAP_MODES		/* Total */
};


/**
 * Bolt motion (used in prefs.c, spells1.c)
 */
enum
{
	BOLT_NO_MOTION,
	BOLT_0,
	BOLT_45,
	BOLT_90,
	BOLT_135,
	BOLT_MAX
};


/*** Feature Indexes (see "lib/edit/terrain.txt") ***/

enum
{
	FEAT_LIGHTING_BRIGHT = 0,
	FEAT_LIGHTING_LIT,
	FEAT_LIGHTING_DARK,
	FEAT_LIGHTING_MAX
};

/* Nothing */
#define FEAT_NONE		0x00

/* Various */
#define FEAT_FLOOR		0x01
#define FEAT_INVIS		0x02
#define FEAT_GLYPH		0x03
#define FEAT_OPEN		0x04
#define FEAT_BROKEN		0x05
#define FEAT_LESS		0x06
#define FEAT_MORE		0x07

/* Shops */
#define FEAT_SHOP_HEAD		0x08
#define FEAT_SHOP_TAIL		0x0F

/* Traps */
#define FEAT_TRAP_HEAD		0x10
#define FEAT_TRAP_TAIL		0x1F

/* Doors */
#define FEAT_DOOR_HEAD		0x20
#define FEAT_DOOR_TAIL		0x2F

/* Extra */
#define FEAT_SECRET		0x30
#define FEAT_RUBBLE		0x31

/* Seams */
#define FEAT_MAGMA		0x32
#define FEAT_QUARTZ		0x33
#define FEAT_MAGMA_H		0x34
#define FEAT_QUARTZ_H		0x35
#define FEAT_MAGMA_K		0x36
#define FEAT_QUARTZ_K		0x37

/* Walls */
#define FEAT_WALL_EXTRA		0x38
#define FEAT_WALL_INNER		0x39
#define FEAT_WALL_OUTER		0x3A
#define FEAT_WALL_SOLID		0x3B
#define FEAT_PERM_EXTRA		0x3C
#define FEAT_PERM_INNER		0x3D
#define FEAT_PERM_OUTER		0x3E
#define FEAT_PERM_SOLID		0x3F



/*** Object origin kinds ***/

enum
{
	ORIGIN_NONE = 0,
	ORIGIN_MIXED,
	ORIGIN_BIRTH,
	ORIGIN_STORE,
	ORIGIN_FLOOR,
	ORIGIN_DROP,
	ORIGIN_DROP_UNKNOWN,
	ORIGIN_ACQUIRE,
	ORIGIN_CHEAT,
	ORIGIN_CHEST
};



/*** Important artifact indexes (see "lib/edit/artifact.txt") ***/

#define ART_POWER			13
#define ART_MORGOTH			34
#define ART_GROND			111
#define ART_PALANTIR			7

/*
 * Hack -- first "normal" artifact in the artifact list.  All of
 * the artifacts with indexes from 1 to 15 are "special" (lights,
 * rings, amulets), and the ones from 16 to 127 are "normal".
 */
#define ART_MIN_NORMAL		16


/*** Function flags ***/


/*
 * Bit flags for the "project()" function
 *
 *   NONE: No flags
 *   JUMP: Jump directly to the target location (this is a hack)
 *   BEAM: Work as a beam weapon (affect every grid passed through)
 *   THRU: Continue "through" the target (used for "bolts"/"beams")
 *   STOP: Stop as soon as we hit a monster (used for "bolts")
 *   GRID: Affect each grid in the "blast area" in some way
 *   ITEM: Affect each object in the "blast area" in some way
 *   KILL: Affect each monster in the "blast area" in some way
 *   HIDE: Hack -- disable "visual" feedback from projection
 *   AWARE: Effects are already obvious to the player
 */
#define PROJECT_NONE  0x000
#define PROJECT_JUMP  0x001
#define PROJECT_BEAM  0x002
#define PROJECT_THRU  0x004
#define PROJECT_STOP  0x008
#define PROJECT_GRID  0x010
#define PROJECT_ITEM  0x020
#define PROJECT_KILL  0x040
#define PROJECT_HIDE  0x080
#define PROJECT_AWARE 0x100


/*
 * Bit flags for the "enchant()" function
 */
#define ENCH_TOHIT   0x01
#define ENCH_TODAM   0x02
#define ENCH_TOAC    0x04


/*
 * Bit flags for the "target_set" function
 *
 *	KILL: Target monsters
 *	LOOK: Describe grid fully
 *	XTRA: Currently unused flag (NOT USED)
 *	GRID: Select from all grids (NOT USED)
 * QUIET: Prevent targeting messages.
 */
#define TARGET_KILL   0x01
#define TARGET_LOOK   0x02
#define TARGET_XTRA   0x04
#define TARGET_GRID   0x08
#define TARGET_QUIET  0x10


/*
 * Bit flags for the "monster_desc" function
 */
#define MDESC_OBJE		0x01	/* Objective (or Reflexive) */
#define MDESC_POSS		0x02	/* Possessive (or Reflexive) */
#define MDESC_IND1		0x04	/* Indefinites for hidden monsters */
#define MDESC_IND2		0x08	/* Indefinites for visible monsters */
#define MDESC_PRO1		0x10	/* Pronominalize hidden monsters */
#define MDESC_PRO2		0x20	/* Pronominalize visible monsters */
#define MDESC_HIDE		0x40	/* Assume the monster is hidden */
#define MDESC_SHOW		0x80	/* Assume the monster is visible */


/*
 * Bit flags for the "get_item" function
 */
#define USE_EQUIP     0x01	/* Allow equip items */
#define USE_INVEN     0x02	/* Allow inven items */
#define USE_FLOOR     0x04	/* Allow floor items */
#define CAN_SQUELCH   0x08	/* Allow selection of all squelched items */
#define IS_HARMLESS   0x10	/* Ignore generic warning inscriptions */
#define SHOW_PRICES   0x20	/* Show item prices in item lists */
#define SHOW_FAIL     0x40 	/* Show device failure in item lists */
#define QUIVER_TAGS   0x80	/* 0-9 are quiver slots when selecting */


/*** Player flags ***/


/*
 * Bit flags for the "p_ptr->notice" variable
 */
#define PN_COMBINE      0x00000001L    /* Combine the pack */
#define PN_REORDER      0x00000002L    /* Reorder the pack */
#define PN_AUTOINSCRIBE 0x00000004L    /* Autoinscribe items */
#define PN_PICKUP       0x00000008L    /* Pick stuff up */
#define PN_SQUELCH      0x00000010L    /* Squelch stuff */
#define PN_SORT_QUIVER  0x00000020L    /* Sort the quiver */
/* xxx (many) */


/*
 * Bit flags for the "p_ptr->update" variable
 */
#define PU_BONUS		0x00000001L	/* Calculate bonuses */
#define PU_TORCH		0x00000002L	/* Calculate torch radius */
/* xxx (many) */
#define PU_HP			0x00000010L	/* Calculate chp and mhp */
#define PU_MANA			0x00000020L	/* Calculate csp and msp */
#define PU_SPELLS		0x00000040L	/* Calculate spells */
/* xxx (many) */
#define PU_FORGET_VIEW		0x00010000L	/* Forget field of view */
#define PU_UPDATE_VIEW		0x00020000L	/* Update field of view */
/* xxx (many) */
#define PU_FORGET_FLOW		0x00100000L	/* Forget flow data */
#define PU_UPDATE_FLOW		0x00200000L	/* Update flow data */
/* xxx (many) */
#define PU_MONSTERS		0x10000000L	/* Update monsters */
#define PU_DISTANCE		0x20000000L	/* Update distances */
/* xxx */
#define PU_PANEL		0x80000000L	/* Update panel */


/*
 * Bit flags for the "p_ptr->redraw" variable
 */
#define PR_MISC			0x00000001L	/* Display Race/Class */
#define PR_TITLE		0x00000002L	/* Display Title */
#define PR_LEV			0x00000004L	/* Display Level */
#define PR_EXP			0x00000008L	/* Display Experience */
#define PR_STATS		0x00000010L	/* Display Stats */
#define PR_ARMOR		0x00000020L	/* Display Armor */
#define PR_HP			0x00000040L	/* Display Hitpoints */
#define PR_MANA			0x00000080L	/* Display Mana */
#define PR_GOLD			0x00000100L	/* Display Gold */

#define PR_HEALTH		0x00000800L	/* Display Health Bar */
#define PR_SPEED		0x00001000L	/* Display Extra (Speed) */
#define PR_STUDY		0x00002000L	/* Display Extra (Study) */
#define PR_DEPTH		0x00004000L	/* Display Depth */
#define PR_STATUS		0x00008000L
#define PR_DTRAP		0x00010000L 	/* Trap detection indicator */
#define PR_STATE		0x00020000L	/* Display Extra (State) */
#define PR_MAP			0x00040000L	/* Redraw whole map */

#define PR_INVEN		0x00080000L 	/* Display inven/equip */
#define PR_EQUIP		0x00100000L 	/* Display equip/inven */
#define PR_MESSAGE		0x00200000L 	/* Display messages */
#define PR_MONSTER		0x00400000L 	/* Display monster recall */
#define PR_OBJECT		0x00800000L 	/* Display object recall */
#define PR_MONLIST		0x01000000L 	/* Display monster list */
#define PR_BUTTONS              0x02000000L     /* Display mouse buttons */
#define PR_ITEMLIST             0x04000000L 	/* Display item list */

/* Display Basic Info */
#define PR_BASIC \
	(PR_MISC | PR_TITLE | PR_STATS | PR_LEV |\
	 PR_EXP | PR_GOLD | PR_ARMOR | PR_HP |\
	 PR_MANA | PR_DEPTH | PR_HEALTH | PR_SPEED)

/* Display Extra Info */
#define PR_EXTRA \
	(PR_STATUS | PR_STATE | PR_STUDY)


/*
 * Bit flags for the "p_ptr->window" variable.
 */
#define PW_INVEN            0x00000001L /* Display inven/equip */
#define PW_EQUIP            0x00000002L /* Display equip/inven */
#define PW_PLAYER_0         0x00000004L /* Display player (basic) */
#define PW_PLAYER_1         0x00000008L /* Display player (extra) */
#define PW_PLAYER_2         0x00000010L /* Display player (compact) */
#define PW_MAP              0x00000020L /* Display dungeon map */
#define PW_MESSAGE          0x00000040L /* Display messages */
#define PW_OVERHEAD         0x00000080L /* Display overhead view */
#define PW_MONSTER          0x00000100L /* Display monster recall */
#define PW_OBJECT           0x00000200L /* Display object recall */
#define PW_MONLIST          0x00000400L /* Display monster list */
#define PW_STATUS           0x00000800L /* Display status */
#define PW_ITEMLIST         0x00001000L /* Display item list */
/* xxx */
#define PW_BORG_1           0x00004000L /* Display borg messages */
#define PW_BORG_2           0x00008000L /* Display borg status */


#define PW_MAX_FLAGS		16


/*** Cave flags ***/


/*
 * Special cave grid flags
 */
#define CAVE_MARK		0x01 	/* memorized feature */
#define CAVE_GLOW		0x02 	/* self-illuminating */
#define CAVE_ICKY		0x04 	/* part of a vault */
#define CAVE_ROOM		0x08 	/* part of a room */
#define CAVE_SEEN		0x10 	/* seen flag */
#define CAVE_VIEW		0x20 	/* view flag */
#define CAVE_TEMP		0x40 	/* temp flag */
#define CAVE_WALL		0x80 	/* wall flag */

#define CAVE2_DTRAP		0x01	/* trap detected grid */


/*** Object flags ***/


/*
 * Chest trap flags (see "tables.c")
 */
#define CHEST_LOSE_STR	0x01
#define CHEST_LOSE_CON	0x02
#define CHEST_POISON	0x04
#define CHEST_PARALYZE	0x08
#define CHEST_EXPLODE	0x10
#define CHEST_SUMMON	0x20


/*
 * Special object flags
 */
#define IDENT_SENSE     0x0001	/* Has been "sensed" */
#define IDENT_WORN      0x0002	/* Has been tried on */
#define IDENT_EMPTY     0x0004	/* Is known to be empty */
#define IDENT_KNOWN     0x0008	/* Fully known */
#define IDENT_STORE     0x0010	/* Item is in the inventory of a store */
#define IDENT_ATTACK	0x0020	/* Know combat dice/ac/bonuses */
#define IDENT_DEFENCE	0x0040	/* Know AC/etc bonuses */
#define IDENT_EFFECT	0x0080	/* Know item activation/effect */
/* xxx */
#define IDENT_INDESTRUCT 0x0200	/* Tried to destroy it and failed */
#define IDENT_NAME	0x0400	/* Know the name of ego or artifact if there is one */
#define IDENT_FIRED	0x0800  /* Has been used as a missile */
#define IDENT_NOTART	0x1000  /* Item is known not to be an artifact */
#define IDENT_FAKE	0x2000  /* Item is a fake, for displaying knowledge */
/* ... */


/*
 * Object flags
 */
enum
{
	#define OF(a,b) OF_##a,
	#include "list-object-flags.h"
	#undef OF
	OF_MAX
};

#define OF_SIZE                FLAG_SIZE(OF_MAX)
#define OF_BYTES	       32  /* savefile bytes, i.e. 256 flags */

#define of_has(f, flag)        flag_has_dbg(f, OF_SIZE, flag, #f, #flag)
#define of_next(f, flag)       flag_next(f, OF_SIZE, flag)
#define of_is_empty(f)         flag_is_empty(f, OF_SIZE)
#define of_is_full(f)          flag_is_full(f, OF_SIZE)
#define of_is_inter(f1, f2)    flag_is_inter(f1, f2, OF_SIZE)
#define of_is_subset(f1, f2)   flag_is_subset(f1, f2, OF_SIZE)
#define of_is_equal(f1, f2)    flag_is_equal(f1, f2, OF_SIZE)
#define of_on(f, flag)         flag_on_dbg(f, OF_SIZE, flag, #f, #flag)
#define of_off(f, flag)        flag_off(f, OF_SIZE, flag)
#define of_wipe(f)             flag_wipe(f, OF_SIZE)
#define of_setall(f)           flag_setall(f, OF_SIZE)
#define of_negate(f)           flag_negate(f, OF_SIZE)
#define of_copy(f1, f2)        flag_copy(f1, f2, OF_SIZE)
#define of_union(f1, f2)       flag_union(f1, f2, OF_SIZE)
#define of_comp_union(f1, f2)  flag_comp_union(f1, f2, OF_SIZE)
#define of_inter(f1, f2)       flag_inter(f1, f2, OF_SIZE)
#define of_diff(f1, f2)        flag_diff(f1, f2, OF_SIZE)

/* Flag set for "pval-dependant" flags. */
#define OF_PVAL_MASK \
	OF_STR, OF_INT, OF_WIS, OF_DEX, OF_CON, OF_CHR, \
	OF_STEALTH, OF_SEARCH, OF_INFRA, OF_TUNNEL, \
	OF_SPEED, OF_BLOWS, OF_SHOTS, OF_MIGHT

/* Flag set for high resists */
#define OF_HIGH_RESIST_MASK \
	OF_RES_POIS, OF_RES_LIGHT, OF_RES_DARK, \
	OF_RES_SOUND, OF_RES_SHARD, \
	OF_RES_NEXUS, OF_RES_NETHR, OF_RES_CHAOS, OF_RES_DISEN

/* Flag set for curses. */
#define OF_CURSE_MASK \
	OF_LIGHT_CURSE, OF_HEAVY_CURSE, OF_PERMA_CURSE

/* Flag set for flags that are obvious to the player on wield. */
#define OF_OBVIOUS_MASK \
	OF_STR, OF_INT, OF_WIS, OF_DEX, OF_CON, OF_CHR, \
	OF_STEALTH, OF_SEARCH, OF_INFRA, OF_TUNNEL, \
	OF_SPEED, OF_BLOWS, OF_SHOTS, OF_MIGHT, \
	OF_BRAND_POIS, OF_BRAND_ELEC, OF_BRAND_FIRE, OF_BRAND_COLD, OF_BRAND_ACID, \
	OF_LIGHT, OF_SEE_INVIS, OF_TELEPATHY, OF_NO_FUEL, \
	OF_BLESSED, OF_AFRAID, OF_CURSE_MASK

/* Flag set for flags that are noticed after some time has passed. */
#define OF_NOTICE_TIMED_MASK \
	OF_STEALTH, OF_SLOW_DIGEST, OF_REGEN, OF_AGGRAVATE, \
	OF_IMPAIR_HP, OF_IMPAIR_MANA

/* Flag set for "ignore element" flags. */
#define OF_IGNORE_MASK \
	OF_IGNORE_ACID, OF_IGNORE_ELEC, OF_IGNORE_FIRE, OF_IGNORE_COLD

/* Flag set for "can be damaged by" flags */
#define OF_HATE_MASK \
	OF_HATES_ACID, OF_HATES_FIRE, OF_HATES_COLD, OF_HATES_ELEC

/* Flag set for "show stuff before ID" flags */
#define OF_SHOW_MASK \
	OF_SHOW_MODS, OF_SHOW_DICE, OF_SHOW_MULTIPLIER

/* Flag set for flags on an object that do not affect the player */
#define OF_OBJ_ONLY_MASK \
	OF_INSTA_ART, OF_EASY_KNOW, OF_HIDE_TYPE, OF_SHOW_MASK, OF_IGNORE_MASK, \
	OF_HATE_MASK

/* Flag sets for slays and brands. */
#define OF_SLAY_MASK \
	OF_SLAY_ANIMAL, OF_SLAY_EVIL, \
	OF_SLAY_ORC, OF_SLAY_TROLL, OF_SLAY_GIANT, \
	OF_SLAY_UNDEAD, OF_SLAY_DEMON, OF_SLAY_DRAGON

#define OF_BRAND_MASK \
	OF_BRAND_ACID, OF_BRAND_ELEC, OF_BRAND_FIRE, OF_BRAND_COLD, OF_BRAND_POIS

#define OF_KILL_MASK \
	OF_KILL_UNDEAD, OF_KILL_DEMON, OF_KILL_DRAGON

#define OF_ALL_SLAY_MASK \
	OF_SLAY_MASK, OF_BRAND_MASK, OF_KILL_MASK


/*
 * Hack -- special "xtra" object flag info (type)
 */
#define OBJECT_XTRA_TYPE_NONE     0
#define OBJECT_XTRA_TYPE_SUSTAIN  1
#define OBJECT_XTRA_TYPE_RESIST   2
#define OBJECT_XTRA_TYPE_POWER    3


/*
 * Player race and class flags
 */

enum
{
	#define PF(a,b) PF_##a,
	#include "list-player-flags.h"
	#undef PF
	PF_MAX
};

#define PF_SIZE                FLAG_SIZE(PF_MAX)

#define pf_has(f, flag)        flag_has_dbg(f, PF_SIZE, flag, #f, #flag)
#define pf_next(f, flag)       flag_next(f, PF_SIZE, flag)
#define pf_is_empty(f)         flag_is_empty(f, PF_SIZE)
#define pf_is_full(f)          flag_is_full(f, PF_SIZE)
#define pf_is_inter(f1, f2)    flag_is_inter(f1, f2, PF_SIZE)
#define pf_is_subset(f1, f2)   flag_is_subset(f1, f2, PF_SIZE)
#define pf_is_equal(f1, f2)    flag_is_equal(f1, f2, PF_SIZE)
#define pf_on(f, flag)         flag_on_dbg(f, PF_SIZE, flag, #f, #flag)
#define pf_off(f, flag)        flag_off(f, PF_SIZE, flag)
#define pf_wipe(f)             flag_wipe(f, PF_SIZE)
#define pf_setall(f)           flag_setall(f, PF_SIZE)
#define pf_negate(f)           flag_negate(f, PF_SIZE)
#define pf_copy(f1, f2)        flag_copy(f1, f2, PF_SIZE)
#define pf_union(f1, f2)       flag_union(f1, f2, PF_SIZE)
#define pf_comp_union(f1, f2)  flag_comp_union(f1, f2, PF_SIZE)
#define pf_inter(f1, f2)       flag_inter(f1, f2, PF_SIZE)
#define pf_diff(f1, f2)        flag_diff(f1, f2, PF_SIZE)

#define player_has(flag)       (pf_has(rp_ptr->pflags, (flag)) || pf_has(cp_ptr->pflags, (flag)))


/*** Terrain flags ***/

enum
{
	FF_PWALK        = 0x00000001,
	FF_PPASS        = 0x00000002,
	FF_MWALK        = 0x00000004,
	FF_MPASS        = 0x00000008,
	FF_LOOK         = 0x00000010,
	FF_DIG          = 0x00000020,
	FF_DOOR         = 0x00000040,
	FF_EXIT_UP      = 0x00000080,
	FF_EXIT_DOWN    = 0x00000100,
	FF_PERM         = 0x00000200,
	FF_TRAP         = 0x00000400,
	FF_SHOP         = 0x00000800,
	FF_HIDDEN       = 0x00001000,
	FF_BORING       = 0x00002000
};


/*** Macro Definitions ***/

/*
 * Hack -- The main "screen"
 */
#define term_screen	(angband_term[0])


/*
 * Determine if the attr and char should consider the item's flavor
 *
 * Identified scrolls should use their own tile.
 */
#define use_flavor_glyph(kind) \
	((kind)->flavor && \
	 !((kind)->tval == TV_SCROLL && (kind)->aware))

/*
 * Return the "attr" for a given item kind.
 * Use "flavor" if available.
 * Default to user definitions.
 */
#define object_kind_attr(kind) \
	(use_flavor_glyph((kind)) ? \
	 ((kind)->flavor->x_attr) : \
	 ((kind)->x_attr))

/*
 * Return the "char" for a given item kind.
 * Use "flavor" if available.
 * Default to user definitions.
 */
#define object_kind_char(kind) \
	(use_flavor_glyph(kind) ? \
	 ((kind)->flavor->x_char) : \
	 ((kind)->x_char))

/*
 * Return the "attr" for a given item.
 * Use "flavor" if available.
 * Default to user definitions.
 */
#define object_attr(T) \
	(object_kind_attr((T)->kind))

/*
 * Return the "char" for a given item.
 * Use "flavor" if available.
 * Default to user definitions.
 */
#define object_char(T) \
	(object_kind_char((T)->kind))

/*
 * Artifacts use the "name1" field
 */
#define artifact_p(T) \
	((T)->name1 ? TRUE : FALSE)

/*
 * Ego-Items use the "name2" field
 */
#define ego_item_p(T) \
	((T)->name2 ? TRUE : FALSE)

/*
 * Cursed items.
 */
#define cursed_p(T) \
	(flags_test((T)->flags, OF_SIZE, OF_CURSE_MASK, FLAG_END))

 /*
 * Rings and Amulets
 */
#define object_is_jewelry(T) \
	(((T)->tval == TV_RING) || ((T)->tval == TV_AMULET))


/*
 * Convert a "location" (Y,X) into a "grid" (G)
 */
#define GRID(Y,X) \
	(256 * (Y) + (X))

/*
 * Convert a "grid" (G) into a "location" (Y)
 */
#define GRID_Y(G) \
	((int)((G) / 256U))

/*
 * Convert a "grid" (G) into a "location" (X)
 */
#define GRID_X(G) \
	((int)((G) % 256U))


/*
 * Convert a "key event" into a "location" (Y)
 */
#define KEY_GRID_Y(K) \
  ((int) (((K.mousey - ROW_MAP) / tile_height) + Term->offset_y))

/*
 * Convert a "key event" into a "location" (X)
 */
#define KEY_GRID_X(K) \
	((int) (((K.mousex - COL_MAP) / tile_width) + Term->offset_x))


/*
 * Determines if a map location is "meaningful"
 */
#define in_bounds(Y,X) \
	(((unsigned)(Y) < (unsigned)(DUNGEON_HGT)) && \
	 ((unsigned)(X) < (unsigned)(DUNGEON_WID)))

/*
 * Determines if a map location is fully inside the outer walls
 * This is more than twice as expensive as "in_bounds()", but
 * often we need to exclude the outer walls from calculations.
 */
#define in_bounds_fully(Y,X) \
	(((Y) > 0) && ((Y) < DUNGEON_HGT-1) && \
	 ((X) > 0) && ((X) < DUNGEON_WID-1))


/*
 * Determines if a map location is currently "on screen"
 * Note that "panel_contains(Y,X)" always implies "in_bounds(Y,X)".
 * Pre-storing this into a cave->info flag would be nice.  XXX XXX
 */
#define panel_contains(Y,X) \
	(((unsigned)((Y) - Term->offset_y) < (unsigned)(SCREEN_HGT)) && \
	 ((unsigned)((X) - Term->offset_x) < (unsigned)(SCREEN_WID)))



/*
 * Determine if a "legal" grid is a "floor" grid
 *
 * Line 1 -- forbid doors, rubble, seams, walls
 *
 * Note the use of the new "CAVE_WALL" flag.
 */
#define cave_floor_bold(Y,X) \
	(!(cave->info[Y][X] & (CAVE_WALL)))

/*
 * Determine if a "legal" grid is a "clean" floor grid
 *
 * Line 1 -- forbid non-floors
 * Line 2 -- forbid normal objects
 */
#define cave_clean_bold(Y,X) \
	((cave->feat[Y][X] == FEAT_FLOOR) && \
	 (cave->o_idx[Y][X] == 0))

/*
 * Determine if a "legal" grid is an "empty" floor grid
 *
 * Line 1 -- forbid doors, rubble, seams, walls
 * Line 2 -- forbid player/monsters
 */
#define cave_empty_bold(Y,X) \
	(cave_floor_bold(Y,X) && \
	 (cave->m_idx[Y][X] == 0))

/*
 * Determine if a "legal" grid is an "naked" floor grid
 *
 * Line 1 -- forbid non-floors
 * Line 2 -- forbid normal objects
 * Line 3 -- forbid player/monsters
 */
#define cave_naked_bold(Y,X) \
	((cave->feat[Y][X] == FEAT_FLOOR) && \
	 (cave->o_idx[Y][X] == 0) && \
	 (cave->m_idx[Y][X] == 0))


/*
 * Determine if a "legal" grid is "permanent"
 *
 * Line 1 -- perma-walls
 * Line 2-3 -- stairs
 * Line 4-5 -- shop doors
 */
#define cave_perma_bold(Y,X) \
	((cave->feat[Y][X] >= FEAT_PERM_EXTRA) || \
	 ((cave->feat[Y][X] == FEAT_LESS) || \
	  (cave->feat[Y][X] == FEAT_MORE)) || \
	 ((cave->feat[Y][X] >= FEAT_SHOP_HEAD) && \
	  (cave->feat[Y][X] <= FEAT_SHOP_TAIL)))


/*
 * Determine if a "legal" grid is within "los" of the player
 *
 * Note the use of comparison to zero to force a "boolean" result
 */
#define player_has_los_bold(Y,X) \
	((cave->info[Y][X] & (CAVE_VIEW)) != 0)


/*
 * Determine if a "legal" grid can be "seen" by the player
 *
 * Note the use of comparison to zero to force a "boolean" result
 */
#define player_can_see_bold(Y,X) \
	((cave->info[Y][X] & (CAVE_SEEN)) != 0)


/*
 * Say whether it's daytime or not
 */
#define is_daytime() \
	(((turn % (10L * TOWN_DAWN)) < ((10L * TOWN_DAWN) / 2)) ? FALSE : TRUE)




/*
 * Maximum number of macro trigger names
 */
#define MAX_MACRO_TRIGGER 200
#define MAX_MACRO_MOD 12


/*** Hack ***/


/*
 * Available graphic modes
 */
#define GRAPHICS_NONE           0
#define GRAPHICS_ORIGINAL       1
#define GRAPHICS_ADAM_BOLT      2
#define GRAPHICS_DAVID_GERVAIS  3
#define GRAPHICS_PSEUDO         4
#define GRAPHICS_NOMAD          5


/* player_type.noscore flags */
#define NOSCORE_WIZARD		0x0002
#define NOSCORE_DEBUG		0x0008
#define NOSCORE_BORG		0x0010

#define SCAN_INSTANT ((u32b) -1)
#define SCAN_OFF 0
#define SCAN_MACRO 45

#define MAX_ITEMLIST 256

/* Whether to learn egos and flavors with less than complete information */
#define EASY_LEARN 1

/* MSVC doesn't have va_copy (which is C99) or an alternative, so we'll just
 * copy the SRC pointer. In other cases we'll use va_copy() as we should. */
#ifdef _MSC_VER
#define VA_COPY(DST, SRC) (DST) = (SRC)
#else
#define VA_COPY(DST, SRC) va_copy(DST, SRC)
#endif

/**
 * Maximum number of pvals on objects
 *
 * Note: all pvals other than DEFAULT_PVAL are assumed to be associated with
 * flags, and any non-flag uses of pval (e.g. chest quality, gold quantity)
 * are assumed to use DEFAULT_PVAL.
 */
#define MAX_PVALS 3
#define DEFAULT_PVAL 0

#endif /* !INCLUDED_DEFINES_H */
