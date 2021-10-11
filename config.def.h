/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar 			= 1;                      /* -b  option; if 0, dsteam appears at bottom     */
static int fuzzy 			= 1;
static int caseinsensitive 	= 1;
static char separator 		= ';';

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"monospace:size=15"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     			fg         bg       */
	[SchemeNorm] = { "#D4D4D4", "#222222" },
	[SchemeSel] = { "#000000", "#81C2FF" },
	[SchemeOut] = { "#000000", "#00ffff" },
};
/* -l option; if nonzero, dsteam uses vertical list with given number of lines */
static unsigned int lines 	= 30;
static int limitlines 		= 1;  /* Prevent unnecessary lines, if there isn't enough items to fill those lines.
									 Might cause a memory error in some cases if disabled. */

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
