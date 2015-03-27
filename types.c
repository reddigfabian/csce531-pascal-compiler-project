/*								*/
/*								*/
/*	CSCE 531 - "Pascal" compiler				*/
/*								*/
/*								*/
/*		Module Implementing "Pascal" Types		*/
/*								*/
/*	--types.c--						*/
/*								*/
/*	This module contains the routines that manipulate 	*/
/*	the type structure for the CSCE 531 "Pascal" compiler.	*/
/* 	Types are implemented by structure sharing, except that	*/
/*	separately declared array and record types are		*/
/*	considered distinct types.				*/
/*								*/
/*								*/
/*								*/
/****************************************************************/

#include <stdlib.h>
#include "defs.h"
#include "types.h"
#include "symtab.h"
#include "message.h"

/* actual definition of TYPE */

typedef struct type_rec
{
    TYPETAG tag;
    union
    {
	struct
	{
	    INDEX_LIST indices;
	    struct type_rec *object;
	} array;
	struct
	{
	    struct type_rec *object;
	} set;
	struct
	{
	    PARAM_LIST params;
	    BOOLEAN check_args;
	    struct type_rec *object;
	} function;
	struct
	{
	    struct type_rec *object;
	    ST_ID id;
	} pointer;
	struct
	{
	    MEMBER_LIST members;
	} record;
	struct
	{
	    unsigned int num_values;
	} enumeration;
	struct
	{
	    struct type_rec *base_type;
	    long low, high;
	} subrange;
    } u;	
} TYPE_REC;

static void print_type();
static BOOLEAN test_equality();

/* Declaration Of All Basic Type Records */

static TYPE_REC basic_error;	/* Added 11/13/91 -SF */
static TYPE_REC basic_void;
static TYPE_REC basic_float;
static TYPE_REC basic_double;
static TYPE_REC basic_long_double;
static TYPE_REC basic_signed_long_int;
static TYPE_REC basic_signed_short_int;
static TYPE_REC basic_signed_int;
static TYPE_REC basic_unsigned_long_int;
static TYPE_REC basic_unsigned_short_int;
static TYPE_REC basic_unsigned_int;
static TYPE_REC basic_unsigned_char;
static TYPE_REC basic_signed_char;


/****************************************************************/
/*								*/
/*								*/
/*		Type Routines For Building Types		*/
/*			(Exported Routines)			*/
/*								*/
/****************************************************************/

/***************************************************************/
void ty_types_init(void)
{
    basic_error.tag = TYERROR;	/* Added 11/13/91 -SF */
    basic_void.tag = TYVOID;
    basic_float.tag = TYFLOAT;
    basic_double.tag = TYDOUBLE;
    basic_long_double.tag = TYLONGDOUBLE;
    basic_signed_long_int.tag = TYSIGNEDLONGINT;
    basic_signed_short_int.tag = TYSIGNEDSHORTINT;
    basic_signed_int.tag = TYSIGNEDINT;
    basic_unsigned_long_int.tag = TYUNSIGNEDLONGINT;
    basic_unsigned_short_int.tag = TYUNSIGNEDSHORTINT;
    basic_unsigned_int.tag = TYUNSIGNEDINT;
    basic_unsigned_char.tag = TYUNSIGNEDCHAR;
    basic_signed_char.tag = TYSIGNEDCHAR;
}

/***************************************************************/
TYPETAG ty_query(TYPE_REC *type)
{
    if (type == NULL)
	fatal ("NULL type in ty_query (%d %s).", __LINE__, __FILE__);

    return type->tag;
}

/**************************************************************/
BOOLEAN ty_test_equality(TYPE_REC * type1, TYPE_REC * type2)
    /*
      Check for compatible types.  This is a wrapper for test_equality(),
      which avoids recursing infinitely on cyclic type structures by
      limiting its pointer depth to 2.
    */
{
    return test_equality(type1, type2, 2);
}

/***************************************************************/
TYPE ty_strip_modifier(TYPE_REC * type)
{
    switch (type->tag)
    {
    case TYARRAY :
	return type->u.array.object;
	break;

    case TYFUNC :
	return type->u.function.object;
	break;

    case TYPTR :
	return type->u.pointer.object;
	break;

    case TYSET :
	return type->u.set.object;

    case TYSUBRANGE :
	return type->u.subrange.base_type;

    default:
	return (NULL);
    }
}

/***************************************************************/
TYPE ty_build_basic(TYPETAG tag)
{
    switch (tag)
    {
    case TYFLOAT :
	return &basic_float;

    case TYDOUBLE :
	return &basic_double;

    case TYLONGDOUBLE :
	return &basic_long_double;

    case TYUNSIGNEDINT :
	return &basic_unsigned_int;

    case TYUNSIGNEDCHAR :
	return &basic_unsigned_char;

    case TYUNSIGNEDSHORTINT :
	return &basic_unsigned_short_int;

    case TYUNSIGNEDLONGINT :
	return &basic_unsigned_long_int;

    case TYSIGNEDCHAR :
	return &basic_signed_char;

    case TYSIGNEDINT :
	return &basic_signed_int;

    case TYSIGNEDLONGINT:
	return &basic_signed_long_int;

    case TYSIGNEDSHORTINT:
	return &basic_signed_short_int;

    case TYVOID :
	return &basic_void;

    case TYERROR :		/* Added 11/13/91 -SF */
	return &basic_error;

    default: 
	bug("illegal tag in \"ty_build_basic\" \n");
    }
}


/*****************************************************************/
TYPE ty_build_ptr(TYPE object)
{
    TYPE_REC *ret_type;

    if (object == NULL)
	fatal("NULL object passed to \"ty_build_ptr\"");

    ret_type = (TYPE_REC *)malloc(sizeof(TYPE_REC));
    ret_type->tag = TYPTR;
    ret_type->u.pointer.object = object;
    ret_type->u.pointer.id = NULL;

    return(ret_type);
}

/*****************************************************************/
TYPE ty_build_unresolved_ptr(ST_ID id)
{
    TYPE_REC *ret_type;

    if (id == NULL)
	fatal("NULL id passed to \"ty_build_unresolved_ptr\"");

    ret_type = (TYPE_REC *)malloc(sizeof(TYPE_REC));
    ret_type->tag = TYPTR;
    ret_type->u.pointer.object = NULL;
    ret_type->u.pointer.id = id;

    return(ret_type);
}

/****************************************************************/
TYPE ty_build_array(TYPE_REC * object, INDEX_LIST indices)
{
    TYPE_REC *ret_type;

    ret_type = (TYPE_REC *)malloc(sizeof(TYPE_REC));
    ret_type->tag = TYARRAY;
    ret_type->u.array.indices = indices;
    ret_type->u.array.object = object;
    return(ret_type);
}

/****************************************************************/
TYPE ty_build_set(TYPE_REC * object)
{
    TYPE_REC *ret_type;

    ret_type = (TYPE_REC *)malloc(sizeof(TYPE_REC));
    ret_type->tag = TYSET;
    ret_type->u.set.object = object;
    return(ret_type);
}

/****************************************************************/
TYPE ty_build_struct(MEMBER_LIST members)
{
    TYPE_REC *ret_type;

    ret_type = (TYPE_REC *)malloc(sizeof(TYPE_REC));
    ret_type->tag = TYSTRUCT;
    ret_type->u.record.members = members;
    return(ret_type);
}

/****************************************************************/
TYPE ty_build_union(MEMBER_LIST members)
{
    TYPE_REC *ret_type;

    ret_type = (TYPE_REC *)malloc(sizeof(TYPE_REC));
    ret_type->tag = TYUNION;
    ret_type->u.record.members = members;
    return(ret_type);
}

/****************************************************************/
TYPE ty_build_enum(unsigned int num_values)
{
    TYPE_REC *ret_type;

    ret_type = (TYPE_REC *)malloc(sizeof(TYPE_REC));
    ret_type->tag = TYENUM;
    ret_type->u.enumeration.num_values = num_values;
    return(ret_type);
}

/****************************************************************/
TYPE ty_build_func(TYPE_REC * object, PARAM_LIST params, BOOLEAN check_args)
{
    TYPE_REC *ret_type;

    ret_type = (TYPE_REC *)malloc(sizeof(TYPE_REC));
    ret_type->tag = TYFUNC;
    ret_type->u.function.params = params;
    ret_type->u.function.check_args = check_args;
    ret_type->u.function.object = object;
    return(ret_type);
}

/****************************************************************/
TYPE ty_build_subrange(TYPE_REC * object, long low, long high)
{
    TYPE_REC *ret_type;

    ret_type = (TYPE_REC *)malloc(sizeof(TYPE_REC));
    ret_type->tag = TYSUBRANGE;
    ret_type->u.subrange.base_type = object;
    ret_type->u.subrange.low = low;
    ret_type->u.subrange.high = high;
    return(ret_type);
}

/****************************************************************/
TYPE ty_query_func(TYPE_REC * type, PARAM_LIST * params, BOOLEAN * check_args)
{
    if (type->tag != TYFUNC)
	bug("not passed a function in \"ty_query_func\"");
    *params = type->u.function.params;
    *check_args = type->u.function.check_args;
    return type->u.function.object;
}


/****************************************************************/
MEMBER_LIST ty_retrieve_members(TYPE_REC * type)
{
    switch (type->tag)
    {
    case TYSTRUCT:
    case TYUNION:
	return type->u.record.members;
    default:
	bug("illegal type in \"ty_retrieve_members\"");
    }
}

/****************************************************************/
TYPE ty_query_array(TYPE_REC * type, INDEX_LIST * indices)
{
    if (type->tag != TYARRAY)
	bug("illegal type in \"ty_query_array\"");
    *indices = type->u.array.indices;
    return type->u.array.object;
}

/****************************************************************/
TYPE ty_query_set(TYPE type)
{
    if (type->tag != TYSET)
	bug("illegal type in \"ty_query_set\"");
    return type->u.set.object;
}

/****************************************************************/
TYPE ty_query_ptr(TYPE_REC * type, ST_ID * id)
{
    if (type->tag != TYPTR)
	bug("illegal type in \"ty_query_ptr\"");

    *id = type->u.pointer.id;

    return type->u.pointer.object;
}

/****************************************************************/
TYPE ty_query_subrange(TYPE_REC * type, long * low, long * high)
{
    if (type->tag != TYSUBRANGE)
	bug("illegal type in \"ty_query_subrange\"");
    *low = type->u.subrange.low;
    *high = type->u.subrange.high;
    return type->u.subrange.base_type;
}

/****************************************************************/
unsigned int ty_query_enum(TYPE_REC * type)
{
    if (type->tag != TYENUM)
	bug("Illegal type in \"ty_query_enum\"");
    return type->u.enumeration.num_values;
}

/****************************************************************/
BOOLEAN ty_resolve_ptr(TYPE_REC * ptr_type, TYPE_REC * object_type)
{
    ST_ID id;

    if (ptr_type == NULL || object_type == NULL)
    {
	msg("null argument(s) to \"ty_resolve_ptr\"");
	return FALSE;
    }

    if (ty_query(ptr_type) != TYPTR)
    {
	msg("Nonpointer type in \"ty_resolve_ptr\"");
	return FALSE;
    }

    if (ty_query_ptr(ptr_type,&id) != NULL)
    {
	msg("Object type already resolved in \"ty_resolve_ptr\"");
	return FALSE;
    }

    /* Modify the object type of the pointer */
    ptr_type->u.pointer.object = object_type;
    ptr_type->u.pointer.id = NULL;

    return TRUE;
}

/****************************************************************/
TYPE ty_assign_members(TYPE_REC * type, MEMBER_LIST members)
{
    switch (type->tag)
    {
    case TYSTRUCT:
    case TYUNION:
	type->u.record.members = members;
	break;
    default:
	bug("illegal tag in \"ty_assign_members\" ");
	break;
    }
    return(type);
}

/*****************************************************************/
/*
  designed to delete a TYPE: does nothing
*/
void ty_delete(TYPE_REC * type)
{
    /* not implemented */
}


/********************************************************************/
/*
	TYPE printing routines

	All these routines use "msg/msgn" from message.c for printing.
*/
/********************************************************************/
void ty_print_type(TYPE_REC * typein)
    /*
      The problem here is that types could be cyclic (recursive)
      through pointers, and unlike C, cycles in Pascal types need not
      involve records.  So we check for cycles not going through records or
      procedure/function parameter lists or array index lists (cycles in
      array index types would be illegal anyway) by running two pointers
      through the type at different speeds.  The slow pointer moves at half
      speed by our toggling cycle_check each time we call print_type directly.
      Simultaneously, we will use the recurse flag to only go through
      one level of records/procedures/functions.
    */
{
    print_type(typein,TRUE,typein,FALSE);
}

/********************************************************************/
void ty_print_typetag(TYPETAG tag)
{

    switch (tag)
    {
    case TYARRAY:
	msgn("array");
	break;

    case TYSET:
	msgn("set");
	break;

    case TYBITFIELD:
	msgn("bitfield");
	break;

    case TYPTR:
	msgn("pointer");
	break;

    case TYSTRUCT:
	msgn("structure");
	break;

    case TYUNION:
	msgn("union");
	break;

    case TYENUM:
	msgn("enumeration");
	break;

    case TYFUNC:
	msgn("procedure/function");
	break;

    case TYSUBRANGE:
	msgn("subrange");
	break;

    case TYFLOAT:
	msgn("float");
	break;

    case TYDOUBLE:
	msgn("double");
	break;

    case TYLONGDOUBLE:
	msgn("long double");
	break;

    case TYUNSIGNEDINT:
	msgn("unsigned int");
	break;

    case TYUNSIGNEDCHAR:
	msgn("unsigned char");
	break;

    case TYUNSIGNEDSHORTINT:
	msgn("unsigned short int");
	break;

    case TYUNSIGNEDLONGINT:
	msgn("unsigned long int");
	break;

    case TYSIGNEDCHAR:
	msgn("signed char");
	break;

    case TYSIGNEDINT:
	msgn("signed int");
	break;

    case TYSIGNEDLONGINT:
	msgn("signed long int");
	break;

    case TYSIGNEDSHORTINT:
	msgn("signed short int");
	break;

    case TYVOID:
	msgn("void");
	break;

    case TYERROR:
	msgn("error");
	break;

    default:
	bug("illegal tag in \"ty_print_typetag\"");
    }

}

/****************************************************************/
void ty_print_class(STORAGE_CLASS tag)
{

    switch (tag)
    {
    case EXTERN_SC:
	msgn("extern");
	break;
    case STATIC_SC:
	msgn("static");
	break;
    case REGISTER_SC:
	msgn("register");
	break;
    case AUTO_SC:
	msgn("auto");
	break;
    case TYPEDEF_SC:
	msgn("typedef");
	break;
    case NO_SC:
	msgn("<no storage class>");
	break;
    default:
	bug("illegal storage class in \"ty_print_class\"");
	     
    }
}

/****************************************************************/
void ty_print_paramlist(PARAM_LIST params)
{

    if (params == NULL)
    {
	msgn(" <no params>");
	return;
    }

    msgn(" (");
    while (params != NULL)
    {
	msg("");
	/* id might be NULL, but st_get_id_str handles NULL */
	msgn("\t\t\t%sparam: id %s; type ",
	     params->is_ref ? "var   " : "value ",
	     st_get_id_str(params->id));
	/* type might be NULL, but ty_print_type handles NULL */
	/* don't recurse */
	print_type((TYPE) params->type, FALSE, (TYPE) params->type, FALSE);
	params = params->next;
    }
    msg("");
    msgn("\t\t)");
}

/****************************************************************/
void ty_print_memlist(MEMBER_LIST members)
{

    if (members == NULL)
    {
	msg("");
	msg("\tmember list is <null>");
	return;
    }

    while (members != NULL)
    {
	msg("");
	msgn("\t\t\tmember: id %s; type ", st_get_id_str(members->id));
	/* don't recurse */
	print_type(members->type, FALSE, members->type, FALSE);
	members = members->next;
    }
    msg("");
}

/****************************************************************/
void ty_print_indexlist(INDEX_LIST indices)
{

    if (indices == NULL)
    {
	msgn("<no indices>");
	return;
    }

    while (indices != NULL)
    {
	msg("");
	msgn("\t\t\tindex: type ");
	/* don't recurse */
	print_type(indices->type, FALSE, indices->type, FALSE);
	indices = indices->next;
    }
    msg("");
}

/****************************************************************/
/*								*/
/*								*/
/*		All Following Routines will			*/
/*		be hidden from user of the module.		*/
/*								*/
/*								*/
/****************************************************************/



/********************************************************************/
void print_type(TYPE_REC * typein, BOOLEAN recurse_flag,
		TYPE_REC * slow, BOOLEAN cycle_check)
/* See the comments for ty_print_type */
{
    unsigned int length;
    PARAM_LIST params;
    INDEX_LIST indices;
    long low, high;
    TYPE_REC *object;
    TYPETAG tag;
    ST_ID id;
    BOOLEAN check_args;

    if (typein == NULL)
    {
	msgn("<null>");
	return;
    }

    if (cycle_check)
    {
	if (typein == slow)	/* cycle detected */
	{
	    msgn("...");
	    return;
	}
	slow = ty_strip_modifier(slow);
    }

    tag = typein->tag;

    switch (tag)
    {
    case TYARRAY:
	object = ty_query_array(typein,&indices);
	msgn("array [");
	ty_print_indexlist(indices);
	msgn("\t\t] of ");
	print_type(object,recurse_flag,slow,!cycle_check);
	break;

    case TYSET:
	object = ty_query_set(typein);
	msgn("set of ");
	print_type(object,recurse_flag,slow,!cycle_check);
	break;

    case TYPTR:
	object = ty_query_ptr(typein,&id);
        if (object == NULL)
            msgn("unresolved pointer to \"%s\"", st_get_id_str(id));
        else
        {  
            msgn("pointer to ");
            print_type(object,recurse_flag,slow,!cycle_check);
        }
	break;

    case TYSTRUCT:
	msg("struct ");
	if (recurse_flag)
	    ty_print_memlist(typein->u.record.members);
	break;

    case TYUNION:
	msg("union ");
	if (recurse_flag)
	    ty_print_memlist(typein->u.record.members);
	break;

    case TYENUM:
	msgn("enumeration ");
	break;

    case TYFUNC:
	object = ty_query_func(typein,&params,&check_args);
	if (ty_query(object) == TYVOID)
	{
	    msgn("procedure");
	    msgn(" <check args = %s>", check_args ? "YES" : "NO");
	    ty_print_paramlist(params);
	}
	else
	{
	    msgn("function");
	    msgn(" <check args = %s>", check_args ? "YES" : "NO");
	    ty_print_paramlist(params);
	    msgn(" returning ");
	    print_type(object,recurse_flag,slow,!cycle_check);
	}
	break;

    case TYSUBRANGE:
	object = ty_query_subrange(typein,&low,&high);
	msgn("subrange %ld .. %ld of ",low,high);
	ty_print_type(object);
	break;

    case TYFLOAT:
	msgn("float");
	break;

    case TYDOUBLE:
	msgn("double");
	break;

    case TYLONGDOUBLE:
	msgn("long double");
	break;

    case TYUNSIGNEDINT:
	msgn("unsigned int");
	break;

    case TYUNSIGNEDCHAR:
	msgn("unsigned char");
	break;

    case TYUNSIGNEDSHORTINT:
	msgn("unsigned short int");
	break;

    case TYUNSIGNEDLONGINT:
	msgn("unsigned long int");
	break;

    case TYSIGNEDCHAR:
	msgn("signed char");
	break;

    case TYSIGNEDINT:
	msgn("signed int");
	break;

    case TYSIGNEDLONGINT:
	msgn("signed long int");
	break;

    case TYSIGNEDSHORTINT:
	msgn("signed short int");
	break;

    case TYVOID:
	msgn("void");
	break;

    case TYERROR:
	msgn("error");
	break;

    default:
	bug("illegal typetag (%d) in \"ty_print_type\"", tag);
    }

}


/**************************************************************/
static BOOLEAN test_equality(TYPE_REC * type1, TYPE_REC * type2, int ptr_cnt)
    /*
      Type equivalence in Pascal is not defined very well, and varies
      with the dialect.  It is always some combination of structural
      and name equivalence.  We strike a compromise here by checking
      structural equivalence on type structures with the following
      exceptions:

      1. occurrences of arrays, records, and enumerated types are
         considered their own unique types (we don't recurse through
	 them but use pointer equality instead).

      2. we only recurse through at most two levels of TYPTR nodes,
         resorting to pointer equality for any deeper level.  This
	 avoids endlessly chasing a cycle in the type structure
	 (which must go through at least one TYPTR node).
	 (Doing full structural equivalence would require
	 maintaining an auxillary data structure.)  Also, we don't
	 recurse through pointer types at all when processing
	 procedure/function parameter types.

      We maintain the number of available TYPTR nodes to recurse through
      in the parameter ptr_cnt.  Initially, this value is set to 2
      in ty_test_equality.
    */
{
    long l1, l2, h1, h2;
    TYPETAG tag1, tag2;
    TYPE_REC *obj1, *obj2;
    PARAM_LIST pl1, pl2;
    BOOLEAN ca1, ca2;

    if (type1 == NULL || type2 == NULL)
    {
	bug("Null argument(s) to \"ty_test_equality\"");
	return FALSE;
    }

#if 0
    /* Subranges over the same base type are compatible with the base
       type and with each other, so just substitute the base type
       for the subrange type. */
    if (ty_query(type1) == TYSUBRANGE)
	type1 = ty_strip_modifier(type1);
    if (ty_query(type2) == TYSUBRANGE)
	type2 = ty_strip_modifier(type2);
#endif

    tag1 = ty_query(type1);
    tag2 = ty_query(type2);

    if (tag1 == TYERROR || tag2 == TYERROR)
	fatal("TYERROR encountered in \"ty_test_equality\"");

    if (tag1 == TYBITFIELD || tag2 == TYBITFIELD)
	fatal("Bit fields are not supported in Standard Pascal.");

    /* If not the same type tag */
    if (tag1 != tag2)
	return FALSE;

    /* Type tags are equal at this point. */
    obj1 = ty_strip_modifier(type1);
    obj2 = ty_strip_modifier(type2);
    switch (tag1)
    {
    case TYPTR:
            /* Check resolved versus unresolved */
        if (obj1 == NULL && obj2 == NULL)
            return type1->u.pointer.id == type2->u.pointer.id;
        if (obj1 == NULL || obj2 == NULL)
            return FALSE;
	if (ptr_cnt > 0)	/* Recurse through the pointer type */
	    return test_equality(obj1, obj2, ptr_cnt - 1);
	/* Otherwise, fall through! */
    case TYARRAY:
    case TYSTRUCT:
    case TYUNION:
    case TYENUM:
	/* Treat these as unique types */
	return type1 == type2;

    case TYSUBRANGE:
#if 0
	return obj1 == obj2;
#else
	(void) ty_query_subrange(type1,&l1,&h1);
	(void) ty_query_subrange(type2,&l2,&h2);
	return obj1 == obj2 && l1 == l2 && h1 == h2;
#endif

    case TYSET:
	return test_equality(obj1, obj2, ptr_cnt);

    case TYFUNC:
	/* First, check return types. */
	if (!test_equality(obj1,obj2,ptr_cnt))
	    return FALSE;
	/* Now check the parameter lists in order.  (Don't recurse
	   through pointers in parameter types, i.e., set ptr_cnt = 0) */
	(void) ty_query_func(type1,&pl1,&ca1);
	(void) ty_query_func(type2,&pl2,&ca2);
	if (!ca1 || !ca2)	/* If args not checked */
	    return TRUE;
	/* Check params */
	while (pl1 != NULL && pl2 != NULL)
	{
	    if (pl1->is_ref != pl2->is_ref ||
		pl1->sc != pl2->sc ||
		!test_equality(pl1->type,pl2->type,0))
		return FALSE;
	    pl1 = pl1->next;
	    pl2 = pl2->next;
	}
	/* Return TRUE iff both parameter list pointers are NULL. */
	return pl1 == pl2;
	
	/* The rest of the tags are for basic types, and these tags
	   determine their types completely. */
    default:
	return TRUE;
    }

    bug("How did I get here?");
}
	    
