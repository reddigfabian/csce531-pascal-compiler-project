%{
/*
 * lex/flex input for "Pascal" lexical scanner
 *
 */

#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "types.h"
#include "symtab.h"
#include "message.h"
/* defined in defs.h */
#include BACKEND_HEADER_FILE
#include "y.tab.h"

#undef yywrap

void comment(int);
void count();
char * convert_id(const char *), * convert_str_const(const char *);


YYSTYPE yylval;

%}

D	[0-9]
L	[a-zA-Z_]
E	[Ee][+-]?{D}+
ID	{L}({L}|{D})*
IC	{D}+
RC	{D}+"."{D}+({E})?
SC	"'"([^'\r\n\f\v\b]|"''")*"'"
WS	[ \t\f\v\r\b\n]+

%option case-insensitive

%%

{WS}	{ count(); }
"{"	{ comment(1); }
"(*"	{ comment(2); }
abs		{ count(); return p_ABS; }
and		{ count(); return LEX_AND; }
arctan		{ count(); return p_ARCTAN; }
array		{ count(); return LEX_ARRAY; }
begin		{ count(); return LEX_BEGIN; }
break		{ count(); return BREAK; }
case		{ count(); return LEX_CASE; }
chr		{ count(); return p_CHR; }
const		{ count(); return LEX_CONST; }
continue	{ count(); return CONTINUE; }
cos		{ count(); return p_COS; }
dispose		{ count(); return p_DISPOSE; }
div		{ count(); return LEX_DIV; }
do		{ count(); return LEX_DO; }
downto		{ count(); return LEX_DOWNTO; }
else		{ count(); return LEX_ELSE; }
end		{ count(); return LEX_END; }
eof		{ count(); return p_EOF; }
eoln		{ count(); return p_EOLN; }
exp		{ count(); return p_EXP; }
external	{ count(); return LEX_EXTERNAL; }
false		{ count(); return p_FALSE; }
file		{ count(); return LEX_FILE; }
for		{ count(); return LEX_FOR; }
forward		{ count(); return LEX_FORWARD; }
function	{ count(); return LEX_FUNCTION; }
get		{ count(); return p_GET; }
goto		{ count(); return LEX_GOTO; }
if		{ count(); return LEX_IF; }
in		{ count(); return LEX_IN; }
input		{ count(); return p_INPUT; }
is		{ count(); return LEX_IS; }
label		{ count(); return LEX_LABEL; }
ln		{ count(); return p_LN; }
maxint		{ count(); return p_MAXINT; }
mod		{ count(); return LEX_MOD; }
new		{ count(); return p_NEW; }
nil		{ count(); return LEX_NIL; }
not		{ count(); return LEX_NOT; }
odd		{ count(); return p_ODD; }
of		{ count(); return LEX_OF; }
or		{ count(); return LEX_OR; }
ord		{ count(); return p_ORD; }
output		{ count(); return p_OUTPUT; }
pack		{ count(); return p_PACK; }
packed		{ count(); return LEX_PACKED; }
page		{ count(); return p_PAGE; }
pred		{ count(); return p_PRED; }
procedure	{ count(); return LEX_PROCEDURE; }
program		{ count(); return LEX_PROGRAM; }
put		{ count(); return p_PUT; }
read		{ count(); return p_READ; }
readln		{ count(); return p_READLN; }
record		{ count(); return LEX_RECORD; }
repeat		{ count(); return LEX_REPEAT; }
reset		{ count(); return p_RESET; }
rewrite		{ count(); return p_REWRITE; }
round		{ count(); return p_ROUND; }
set		{ count(); return LEX_SET; }
sin		{ count(); return p_SIN; }
sqr		{ count(); return p_SQR; }
sqrt		{ count(); return p_SQRT; }
succ		{ count(); return p_SUCC; }
then		{ count(); return LEX_THEN; }
to		{ count(); return LEX_TO; }
true		{ count(); return p_TRUE; }
trunc		{ count(); return p_TRUNC; }
type		{ count(); return LEX_TYPE; }
unpack		{ count(); return p_UNPACK; }
until		{ count(); return LEX_UNTIL; }
uses		{ count(); return LEX_USES; }
var		{ count(); return LEX_VAR; }
while		{ count(); return LEX_WHILE; }
with		{ count(); return LEX_WITH; }
write		{ count(); return p_WRITE; }
writeln		{ count(); return p_WRITELN; }
xor		{ count(); return LEX_XOR; }
{ID}	{
	    count();
	    yylval.y_string = convert_id(yytext);
	    return LEX_ID;
	}
{IC}	{
	    count();
	    yylval.y_int = strtol(yytext,0,10);
	    return LEX_INTCONST;
	}
{RC}	{
	    count();
	    yylval.y_real = strtod(yytext,0);
	    return LEX_REALCONST;
	}
{SC}	{
	    count();
	    yylval.y_string= convert_str_const(yytext);
	    return LEX_STRCONST;
	}
"(."	{ count(); return '['; }
".)"	{ count(); return ']'; }
".."	{ count(); return LEX_RANGE; }
"..."	{ count(); return LEX_ELLIPSIS; }
":="	{ count(); return LEX_ASSIGN; }
"<="	{ count(); return LEX_LE; }
">="	{ count(); return LEX_GE; }
"<>"	{ count(); return LEX_NE; }
"><"	{ count(); return LEX_SYMDIFF; }
"=>"	{ count(); return LEX_RENAME; }
"**"	{ count(); return LEX_POWER; }
"+>"	{ count(); return LEX_CEIL_PLUS; }
"->"	{ count(); return LEX_CEIL_MINUS; }
"*>"	{ count(); return LEX_CEIL_MULT; }
"/>"	{ count(); return LEX_CEIL_DIV; }
"+<"	{ count(); return LEX_FLOOR_PLUS; }
"-<"	{ count(); return LEX_FLOOR_MINUS; }
"*<"	{ count(); return LEX_FLOOR_MULT; }
"/<"	{ count(); return LEX_FLOOR_DIV; }
.	{ count(); return yytext[0]; }

%%


int yywrap()
{
    return 1;
}

static int column = 0;

void comment(int comment_type)
{
    char c, c1;
    int is_star = 0;

    column += comment_type==1 ? 1 : 2;  /* for '{' (type 1) or '(*' (type 2) */

    while (1)
    {
	c = input();

	if (c == 0)
	    error("open comment at EOF");

	if (c == '\n')
	{
	    column = 0;
	    b_lineno_comment(++yylineno);
	}
	else if (c == '\t')
	    column += 8 - (column % 8);
	else
	    column++;

	if (comment_type == 1 && c == '}')
	    return;

	if (comment_type == 2 && is_star && c == ')')
	    return;

	if (comment_type == 2)
	    is_star = (c == '*');
    }
}

void count()
{
    int i;

    for (i = 0; yytext[i] != '\0'; i++)
    {
	if (yytext[i] == '\n')
	{
	    b_lineno_comment(++yylineno);
	    column = 0;
	}
	else if (yytext[i] == '\t')
	    column += 8 - (column % 8);
	else
	    column++;
    }
}


int digit(char c)
{
    if (isdigit(c))
	return c - '0';
    if (isxdigit(c))
	return toupper(c) - 'A' + 10;
    bug("Non-hex digit found: %c", c);
}


/* Determines if the given character can legally follow a backslash
   in a Pascal string constant.  Used in convert_str_const(), below.
*/
BOOLEAN is_escchar(char c)
{
    switch (c)
    {
    case '\\': case 'a' : case 'b' : case 'f' : case 'n' :
    case 'r' : case 't' : case 'v' : case 'x' :
    case '0': case '1': case '2': case '3':
    case '4': case '5': case '6': case '7':
	return TRUE;
    default:
	return FALSE;
    }

    bug("is_escchar: failed to return inside switch");
}


/* Make the initial letter upper case and the rest lower case.
   This serves two purposes:
     1.  Differently cased versions of the same identifier will map
         to the same string (needed by the symbol table)
     2.  Initial caps won't conflict with any names of external library
         routines
*/
char * convert_id(const char * s)
{
    char *str = st_save_string(s);
    char *start = str;
    if (!*str)
	bug("Empty identifier");
    *str = toupper(*str);
    for (str++; *str; str++)
	*str = tolower(*str);
    return start;
}

char * convert_str_const(const char * str)
{
    /* We convert the string to C/assembler source for the sake of gcc.
       This requires converting '' into ' and " into \" */
    int len = 0;
    BOOLEAN is_escaped = FALSE, is_quote = FALSE;
    const char *p;
    char *buf, *q;

    /* First, find the length of the converted string, and detect errors */
    if (*str++ != '\'')
	bug("Malformed string constant: no initial single quote");

    for (p = str; *p != '\0'; p++,len++)
    {
	if (*p == '\\' && !is_escaped)
	    is_escaped = TRUE;
	else if (is_escaped)
	{
	    if (is_escchar(*p))
		is_escaped = FALSE;
	    else
	    {
		error("Illegal escape sequence in string constant");
		len = 0;
		break;
	    }
	}
	else if (*p == '"')
	    len++;
	else if (*p == '\'')
	{
	    if (is_quote)
		len--;
	    is_quote = !is_quote;
	}
    }

    /* The final single quote should turn is_quote on. */
    if (!is_quote)
	bug("convert_str_const: malformed string");

    /* Account for the final single quote */
    len--;

    /* Allocate new memory for the converted string, sans quotes. */

    q = buf = (char *)malloc(sizeof(char) * (len + 1));

    if (!buf)
	fatal("convert_str_const: out of memory");

    /* str is pointing to the first char after the initial quote. */
    /* Loop invariant: q points to the next free space in buf. */
    while (0 < len)
	if (*str == '\'') {
	    if (*(str+1) == '\'') {
		*q++ = '\'';
		str += 2;
		len--;
	    }
	    else
		break;
	}
	else if (*str == '"') {
	    *q++ = '\\';
	    *q++ = '"';
	    str++;
	    len -= 2;
	}
	else
	{
	    *q++ = *str++;
	    len--;
	}

    if (len != 0)
	bug("convert_str_const: string length calculated incorrectly");

    *q = '\0';

    return buf;
}
