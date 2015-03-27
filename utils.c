
/****************************************************************/
/*								*/
/*	CSCE531 - "Pascal" and "C" Compilers			*/
/*								*/
/*	--utils.c--						*/
/*								*/
/*	This file contains utility routines for the CSCE531	*/
/*	Pascal and C compilers.					*/
/*								*/
/*								*/
/*								*/
/****************************************************************/

#include <stdarg.h>
#include <stdlib.h>
#include "defs.h"
#include "symtab.h"
#include "message.h"
/* defined in defs.h */
#include BACKEND_HEADER_FILE

/****************************************************************/
/*
	interface to scanner to get line numbers for error messages
*/

int sc_line()
{
	extern int yylineno;

	return yylineno;
}

/****************************************************************/
/*
	support for symbol table data records
*/

void stdr_free(ST_DR stdr)
{
	free(stdr);
}

ST_DR stdr_alloc()
{
	return (ST_DR) malloc(sizeof(ST_DATA_REC));
}

void stdr_dump(ST_DR stdr)
{
	extern void print_boolean(BOOLEAN);

	if (stdr == NULL)
	{
		msg("<null>");
		return;
	}
	switch(stdr->tag) {
	case ECONST:	msg("	ECONST");
			break;
	case GDECL:	msg("	GDECL");
			break;
	case LDECL:	msg("	LDECL");
			break;
	case PDECL:	msg("	PDECL");
			break;
	case FDECL:	msg("	FDECL");
			break;
	case TYPENAME:	msg("	TYPENAME");
			break;
	default:
		bug("illegal tag in \"stdr_dump\""); 
	}
	switch(stdr->tag) {
	case ECONST:	msgn("		type = ");
			ty_print_type(stdr->u.econst.type);
			msg("");
			msg("		value = %d",stdr->u.econst.val);
			break;
	case GDECL:
	case LDECL:
	case PDECL:
	case FDECL:	msgn("		type = ");
			ty_print_type(stdr->u.decl.type);
			msg("");
			msgn("		storage class = ");
			ty_print_class(stdr->u.decl.sc);
			msg("");
			msgn("		reference parameter = ");
			print_boolean(stdr->u.decl.is_ref);
			msg("");
			if (stdr->tag == LDECL || stdr->tag == PDECL)
			    msg("		offset = %d",
				stdr->u.decl.v.offset);
			else if (stdr->tag == FDECL)
			    msg("		global function name = \"%s\"",
				stdr->u.decl.v.global_func_name);
			msgn("		error = ");
			print_boolean(stdr->u.decl.err);
			msg("");
			break;
	case TYPENAME:	msgn("		type = ");
			ty_print_type(stdr->u.typename.type);
			msg("");
			break;
	}
}


/****************************************************************/
/*
	support for printing "typedef" types
*/

void print_boolean(BOOLEAN b)
{
	if (b)
		msgn("TRUE");

	else
		msgn("FALSE");
}
