/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar 			= 0;                      /* -b  option; if 0, dsteam appears at bottom     */
static int fuzzy 			= 1;
static int caseinsensitive 	= 1;
static char separator 		= ';';

/* Window margin */
static unsigned int marginx 		= 800; 						/* Add a margin to the sides of dsteam. Disabled if 0 */
static unsigned int marginy 		= 200; 						/* Add margin to the top/bottom of dsteam */

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"Cantarell:size=15"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     				fg         bg       */
	[SchemeNorm] 		= { "#D4D4D4", "#222222" },
	[SchemeSel] 		= { "#000000", "#81C2FF" },
	[SchemeSelBelow] 	= { "#69AFF1", "#69AFF1" },
	[SchemeOut] 		= { "#000000", "#00ffff" },
	[Border] 			= { "#90A6BC", "#90A6BC" },
};
/* -l option; if nonzero, dsteam uses vertical list with given number of lines */
static unsigned int lines 	= 30;
static int limitlines 		= 1;  /* Prevent unnecessary lines, if there isn't enough items to fill those lines.
									 Might cause a memory error in some cases if disabled. */

/* -h option; minimum height of a menu line */
static unsigned int lineheight = 24;
static unsigned int min_lineheight = 8;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static const unsigned int border_width = 5;
