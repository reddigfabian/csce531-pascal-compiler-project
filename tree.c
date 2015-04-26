#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "types.h"

int myDebug = 0;

int errorCalled = 0;
int inAssignment = 0;
char* tagtypeStrings[] = {"CHARACTERCONSTANT", "INTCONSTANT", "REALCONSTANT", "VAR_NODE", "NEGNUM", "ASSIGN_NODE",
    "BOOL_NODE", "BINOP_NODE", "FUNC_NODE", "RELOP_NODE", "IF_NODE", "ELSE_NODE", "WHILE_NODE", "STATEMENT_NODE", "ARRAY_NODE", "ACCESS_NODE"};
char* unopTypeStrings[] = {"CHR", "ORD", "SUCC", "PRED", "NEG"};
char* binopTypeStrings[] = {"ADD", "SUB", "REAL_DIV", "INT_DIV", "MOD", "MULT"};
char* relationalTypeStrings[] = {"NE","LE","GE","EQ","LT","GT"};
char* rtsFunOneParStrings[] = {
    "pas_ABS","pas_SQR","pas_SIN","pas_COS","pas_EXP",
    "pas_LN","pas_SQRT","pas_ARCTAN",
    "pas_ARG","pas_TRUNC","pas_ROUND","pas_CARD",
    "pas_ORD","pas_CHR","pas_ODD","pas_EMPTY",
    "pas_POSITION","pas_LASTPOSITION",
    "pas_LENGTH","pas_TRIM","pas_BINDING",
    "pas_DATE","pas_TIME","pas_SUCC","pas_PRED"};


/*
typedef enum {
TYVOID, TYFLOAT, TYDOUBLE, TYLONGDOUBLE, TYSIGNEDLONGINT,
TYSIGNEDSHORTINT, TYSIGNEDINT, TYUNSIGNEDLONGINT,
TYUNSIGNEDSHORTINT, TYUNSIGNEDINT, TYUNSIGNEDCHAR,
TYSIGNEDCHAR, TYSTRUCT, TYUNION, TYENUM, TYARRAY, TYSET,
TYFUNC, TYPTR, TYBITFIELD, TYSUBRANGE, TYERROR
} TYPETAG;
*/


/*
typedef enum{INTCONSTANT, REALCONSTANT, VAR_NODE, NEGNUM, ASSIGN_NODE, BOOL_NODE, BINOP_NODE, FUNC_NODE}tagtype;

typedef enum{ADD, SUB, REAL_DIV, INT_DIV, MOD, MULT}binopType;

typedef struct tn{
  tagtype tag;

  union{

    long intconstant;
    double realconstant;
    struct tn *negNode;
    int boolean;

    struct{
      ST_ID varName;
      int isInstalled;
      ST_DR DR;
      STDR_TAG DRtag;
      TYPE type;
      TYPETAG typetag;
    }var_node;

    struct{
      ST_ID funcName;
      int isInstalled;
      ST_DR DR;
      STDR_TAG DRtag;
      TYPE type;
      TYPETAG typeTag

      //PARAMETERLIST PARAMS - add this

    }func_node; //PLAY THAT FUNC-Y MUSIC...WHIIIIIIIITE BOI

    struct{
      struct tn *varNode;
      struct tn *expression;
    }assign_node;

    struct{
      binopType binTag;
      struct tn *left;
      struct tn *right;
    }binop;


  }u;

}treeNode, *TN;

*/

/*
********************MAKE FUNCTIONS*********************
*/

//PART 3
TN makeIfNode(TN relop,TN expr){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = IF_NODE;
  tempTN->u.if_node.relop = relop;
  tempTN->u.if_node.expression = expr;
  tempTN->u.if_node.falseJump = new_symbol();
  tempTN->u.if_node.exitIf = tempTN->u.if_node.falseJump;
  return tempTN;
}

//passes up IF_NODE
TN makeElseNode(TN ifNode, TN expr){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = ELSE_NODE;
  tempTN->u.else_node.expression = expr;
  ifNode->u.if_node.elseNode = tempTN;
  ifNode->u.if_node.exitIf = new_symbol();
  return ifNode;
}

TN makeWhileNode(TN relop,TN expr){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = WHILE_NODE;
  tempTN->u.while_node.relop = relop;
  tempTN->u.while_node.expression = expr;
  tempTN->u.while_node.beginLoop = new_symbol();
  tempTN->u.while_node.exitLoop = new_symbol();
  return tempTN;
}

TN makeStatementNode(TN root, TN expr){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = STATEMENT_NODE;
  tempTN->u.statement_node.expression = expr;
  tempTN->u.statement_node.nextStatement = NULL;

  if(root != NULL){
    TN lastNode = root;
    if(root->u.statement_node.nextStatement == NULL){
      root->u.statement_node.nextStatement = tempTN; //second time
      return root;
    }
    while(lastNode->u.statement_node.nextStatement != NULL){  //rest times
      lastNode = lastNode->u.statement_node.nextStatement;
    }

    lastNode->u.statement_node.nextStatement = tempTN;
    return root;

  }else{
    return tempTN; //first time
  }

}//END makeStatementNode()


  TN makeAccessNode(TN root, TN expr, int lowInt, TYPE inputType){
    TN tempTN = (TN)malloc(sizeof(treeNode));
    tempTN->tag = ACCESS_NODE;
    tempTN->u.access_node.expression = expr;
    tempTN->u.access_node.nextStatement = NULL;
    tempTN->u.access_node.type = inputType;

    if(root != NULL){
      TN lastNode = root;
      if(root->u.access_node.nextStatement == NULL){
        root->u.access_node.nextStatement = tempTN; //second time
        return root;
      }
      while(lastNode->u.access_node.nextStatement != NULL){  //rest times
        lastNode = lastNode->u.access_node.nextStatement;
      }

      lastNode->u.access_node.nextStatement = tempTN;
      return root;

    }else{
      tempTN->u.access_node.low = lowInt;
      return tempTN; //first time
  }
}//END makeAccessNode



TN makeArrayNode(TN varNode, TN access){
  long low, high;
  INDEX_LIST currList;


  if(varNode->tag == ARRAY_NODE){
    varNode->u.array_node.type = ty_query_array(varNode->u.array_node.type, &currList);
    if(myDebug) if(varNode->u.array_node.type == NULL) msg("found null for tyquery 1");
    varNode->u.array_node.typeTag = ty_query(varNode->u.array_node.type);
    varNode->u.array_node.access_node = makeAccessNode(varNode->u.array_node.access_node, access, varNode->u.array_node.low, varNode->u.array_node.type);
    return varNode; //this is really an array node, deal with it
  }else{
    TN tempTN = (TN)malloc(sizeof(treeNode));
    tempTN->tag = ARRAY_NODE;
    tempTN->u.array_node.isInstalled = varNode->u.var_node.isInstalled;
    int block;
    if(tempTN->u.array_node.isInstalled == 1){
      tempTN->u.array_node.arrayName = varNode->u.var_node.varName;
      tempTN->u.array_node.DR = varNode->u.var_node.DR;
      tempTN->u.array_node.DRtag = varNode->u.var_node.DRtag;
      TYPE tempTYPE = ty_query_array(varNode->u.var_node.type, &currList);
      tempTN->u.array_node.type = tempTYPE;
      if(myDebug) if(tempTN->u.array_node.type == NULL) msg("found null for tyquery 2");
      tempTN->u.array_node.typeTag = ty_query(tempTN->u.array_node.type);
      //if(tempTN->u.array_node.typeTag == TYARRAY) msg("TYARRAY in make");
      TYPE subType = currList->type;
      ty_query_subrange(subType, &low, &high);
      tempTN->u.array_node.access_node = makeAccessNode(NULL, access, low, tempTN->u.array_node.type);
      tempTN->u.array_node.low = low;
      tempTN->u.array_node.high = high;
      tempTN->u.array_node.length = high - low;
    }else{
      bug("Variable node for array node was not installed.");
    }
    return tempTN;

  }
}//END makeArrayNode()



//PART 2
TN makeErrorNode(){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = ERROR_NODE;
  return tempTN;
}

TN makeIntConstNode(long intconstant){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = INTCONSTANT;
  tempTN->u.intconstant = intconstant;
  return tempTN;
}

TN makeRealConstNode(double realconstant){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = REALCONSTANT;
  tempTN->u.realconstant = realconstant;

  return tempTN;
}

TN makeCharConstNode(char charconstant){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = CHARCONSTANT;
  tempTN->u.character = charconstant;
  return tempTN;
}

TN makeNegNumNode(TN numNode){
  tagtype tempTag = numNode->tag;
  if(tempTag == REALCONSTANT){
    double tempReal = numNode->u.realconstant * -1;
    numNode->u.realconstant = tempReal;
    return numNode;
  }
  else if(tempTag == INTCONSTANT){
    long tempInt = numNode->u.intconstant * -1;
    numNode->u.intconstant = tempInt;
    return numNode;
  }

  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = NEGNUM;
  tempTN->u.negNode = numNode;

  return tempTN;
}

TN makeVarNode(ST_ID id){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = VAR_NODE;
  tempTN->u.var_node.varName = id;

  int block;
  ST_DR tempDR = st_lookup(id, &block);
  if(tempDR != NULL){
    tempTN->u.var_node.isInstalled = 1;
    tempTN->u.var_node.DR = tempDR;
    tempTN->u.var_node.DRtag = tempDR->tag;
    if(tempDR->tag == GDECL | tempDR->tag == LDECL | tempDR->tag == PDECL | tempDR->tag == FDECL){
      tempTN->u.var_node.type = tempDR->u.decl.type;
      tempTN->u.var_node.typeTag = ty_query(tempDR->u.decl.type);
    }else if(tempDR->tag == ECONST){
      tempTN->u.var_node.type = tempDR->u.econst.type;
      tempTN->u.var_node.typeTag = ty_query(tempDR->u.econst.type);
    }else if(tempDR->tag == TYPENAME){
      tempTN->u.var_node.type = tempDR->u.typename.type;
      tempTN->u.var_node.typeTag = ty_query(tempDR->u.typename.type);
    }else{
      bug("Bad DR tag in makeVarNode()");
    }

  }else{ //tempDR == NULL
    tempTN->u.var_node.isInstalled = 0;
    //tempTN->u.var_node.DR = NULL;
    //tempTN->u.var_node.DRtag = NULL;
    //tempTN->u.var_node.type = NULL;
    //tempTN->u.var_node.typeTag = NULL;
  }

  return tempTN;
}

TN makeAssignNode(TN var, TN expr){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = ASSIGN_NODE;
  tempTN->u.assign_node.varNode = var;
  tempTN->u.assign_node.expression = expr;
  return tempTN;
}

TN makeBoolNode(int tempBool){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = BOOL_NODE;
  tempTN->u.boolean = tempBool;
  return tempTN;
}


TN makeUnopNode(TN operand, unopType op){
  //{"CHR", "ORD", "SUCC", "PRED", "NEG"};
  tagtype tempTypeTag = operand->tag;
  if(tempTypeTag == INTCONSTANT | tempTypeTag == BOOL_NODE | tempTypeTag == CHARCONSTANT){
    if(myDebug){msg("CONSTANT FOLDING - UNOP");}
    return handleConstantFoldingUNOP(op, operand);
  }

  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = UNOP_NODE;
  tempTN->u.unop.unTag = op;
  tempTN->u.unop.operand = operand;
  return tempTN;
} //END makeUnopNode

TN makeBinopNode(TN leftSide, TN rightSide, binopType binTagType){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = BINOP_NODE;
  tempTN->u.binop.binTag = binTagType;
  tempTN->u.binop.left = leftSide;
  tempTN->u.binop.right = rightSide;

  tagtype LnodeType = leftSide->tag;
  tagtype RnodeType = rightSide->tag;
  TYPETAG Ltag;
  TYPETAG Rtag;

  if((LnodeType == INTCONSTANT | LnodeType == REALCONSTANT) &&
     (RnodeType == INTCONSTANT | RnodeType == REALCONSTANT)){
       if(LnodeType == INTCONSTANT) Ltag = TYSIGNEDLONGINT;
       if(LnodeType == REALCONSTANT) Ltag = TYDOUBLE;
       if(RnodeType == INTCONSTANT) Rtag = TYSIGNEDLONGINT;
       if(RnodeType == REALCONSTANT) Rtag = TYDOUBLE;

       if(myDebug){msg("CONSTANT FOLDING - BINOP");}
       return handleConstantFolding(binTagType, leftSide, rightSide, Ltag, Rtag);
  }//END CONSTANT FOLDING of const ints/doubles

  return tempTN;
}

TN makeRelopNode(TN leftSide, relationalType relTagType, TN rightSide){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = RELOP_NODE;
  tempTN->u.relop.relTag = relTagType;
  tempTN->u.relop.left = leftSide;
  tempTN->u.relop.right = rightSide;
  return tempTN;
}

TN makeFuncNode(ST_ID id, TYPETAG typeTag, TYPE type){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = FUNC_NODE;
  tempTN->u.func_node.funcName = id;
  tempTN->u.func_node.typeTag = typeTag;
  tempTN->u.func_node.type = type;
  return tempTN;
}

/*
********************************BACKEND STUFF****************************
*/

TYPETAG genBackendAssignment(TN startNode, int fromExpr, int genBackend){

  if(genBackend && myDebug && !fromExpr) msg("GENERATING BACKEND");

  switch(startNode->tag){

    case IF_NODE:{
      genBackendAssignment(startNode->u.if_node.relop, 1, genBackend);
      if(genBackend) b_cond_jump(TYSIGNEDCHAR, 0, startNode->u.if_node.falseJump);
      genBackendAssignment(startNode->u.if_node.expression, 1, genBackend);


      if(startNode->u.if_node.elseNode != NULL){
        if(genBackend) b_jump(startNode->u.if_node.exitIf);
        if(genBackend) b_label(startNode->u.if_node.falseJump);
        genBackendAssignment(startNode->u.if_node.elseNode, 1, genBackend);
      }

      if(genBackend) b_label(startNode->u.if_node.exitIf);
      return TYVOID;

    }case ELSE_NODE:{
      genBackendAssignment(startNode->u.else_node.expression,1,genBackend);
      return TYVOID;

    }case WHILE_NODE:{
      if(genBackend) b_label(startNode->u.while_node.beginLoop);
      genBackendAssignment(startNode->u.while_node.relop,1,genBackend);
      if(genBackend)b_cond_jump(TYSIGNEDCHAR,0,startNode->u.while_node.exitLoop);
      genBackendAssignment(startNode->u.while_node.expression,1,genBackend);
      if(genBackend)b_jump(startNode->u.while_node.beginLoop);
      if(genBackend) b_label(startNode->u.while_node.exitLoop);
      return TYVOID;

    }case STATEMENT_NODE:{
      TYPETAG tempTYPETAG = genBackendAssignment(startNode->u.statement_node.expression,1,genBackend);
      //
      if(startNode->u.statement_node.nextStatement != NULL){//check if null next
          genBackendAssignment(startNode->u.statement_node.nextStatement,1,genBackend);
      }else{
        return TYVOID;
      }
      return tempTYPETAG;

    }case FUNC_NODE:{
      TYPETAG tempTYPETAG = startNode->u.func_node.typeTag;
      char *tempName = st_get_id_str(startNode->u.func_node.funcName);
      if(genBackend | inAssignment == 0) b_alloc_arglist(0);  //for exterens and forwards (no args)
      if(genBackend | inAssignment == 0) b_funcall_by_name(tempName, tempTYPETAG);
      return tempTYPETAG;

    }case CHARCONSTANT:{
      char tempChar;
      tempChar = startNode->u.character;
      int tempInt = (int)tempChar;
      if(genBackend) b_push_const_int(tempInt);
      if(genBackend) b_convert(TYSIGNEDLONGINT, TYUNSIGNEDCHAR);
      return TYUNSIGNEDCHAR;

    }case INTCONSTANT:{
      long tempInt;
      tempInt = startNode->u.intconstant;
      if(genBackend) b_push_const_int(tempInt);
      return TYSIGNEDLONGINT;   //not 100% yet

    }case REALCONSTANT:{
      double tempReal = startNode->u.realconstant;
      if(genBackend) b_push_const_double(tempReal);
      return TYDOUBLE;  //not 100% yet

    }case BOOL_NODE:{
      int tempBool = startNode->u.boolean;
      if(genBackend) b_push_const_int(tempBool);
      if(genBackend) b_convert(TYSIGNEDLONGINT, TYSIGNEDCHAR);
      return TYSIGNEDCHAR;

    }case NEGNUM:{
      TN tempNode = startNode->u.negNode;
      tagtype tempTagType = tempNode->tag;
      if(tempTagType == INTCONSTANT){
        long tempInt = -1 * tempNode->u.intconstant;
        if(genBackend) b_push_const_int(tempInt);
        return TYSIGNEDLONGINT;   //not 100% yet

      }else if(tempTagType == REALCONSTANT){
        double tempReal = -1 * tempNode->u.realconstant;
        if(genBackend) b_push_const_double(tempReal);
        return TYDOUBLE;  //not 100% yet

      }else if(tempTagType == VAR_NODE){
        TYPETAG varTypeTag = genBackendAssignment(startNode->u.assign_node.varNode, 1, genBackend);
        if(genBackend) b_negate(varTypeTag);
        return varTypeTag;

      }else{
        bug("unchecked tag in NEGNUM genBackendAssignment()");
        break;
      }

    }case VAR_NODE:{
      errorCalled = 0;
      if(fromExpr){
        if(startNode->u.var_node.isInstalled){
          char *tempIdString = st_get_id_str(startNode->u.var_node.varName);
          if(genBackend) b_push_ext_addr(tempIdString);
          TYPETAG tempTypeTag = getTYPETAG(startNode);
          if(genBackend) b_deref(tempTypeTag);
          if(tempTypeTag == TYFLOAT){
            if(genBackend) b_convert(TYFLOAT, TYDOUBLE);
            return TYDOUBLE;
          }
          return tempTypeTag;
        }else{ //var_node not installed in symbol table
          error("variable in expression has not been initilized");
          break;
        }
      }else{ //var is on the left hand side of an assignment, dont deref
        char *tempIdString = st_get_id_str(startNode->u.var_node.varName);
        if(genBackend) b_push_ext_addr(tempIdString);
        TYPETAG tempTypeTag = getTYPETAG(startNode);
        return tempTypeTag;
      }

    }case ACCESS_NODE:{
      TYPETAG tempTYPETAG = genBackendAssignment(startNode->u.access_node.expression,1,genBackend);

      if(genBackend) b_push_const_int(startNode->u.array_node.low);
      if(genBackend) b_arith_rel_op(B_SUB , TYSIGNEDLONGINT);
      int tempAlignInt = getAlignmentSize(startNode->u.access_node.type);
      if(genBackend) b_ptr_arith_op(B_ADD, TYSIGNEDLONGINT, getSize(startNode->u.access_node.type, tempAlignInt));

      if(startNode->u.access_node.nextStatement != NULL){//check if null next
          genBackendAssignment(startNode->u.access_node.nextStatement,1,genBackend);
      }

      return tempTYPETAG;

    }case ARRAY_NODE:{
      TYPETAG tempTypeTag = startNode->u.array_node.typeTag;


      if(fromExpr){
        char *tempIdString = st_get_id_str(startNode->u.array_node.arrayName);
        if(genBackend) b_push_ext_addr(tempIdString);
        //holder from cut
        TYPETAG tempErrorCheck = genBackendAssignment(startNode->u.array_node.access_node, 1, genBackend);
        if(myDebug){ msgn("tempErrorCheck OF ARRAY_NODE: "); ty_print_typetag(tempErrorCheck); msg("");}
        if(tempErrorCheck != TYSIGNEDLONGINT){
          error("Incompatible index type in array access");
          tempTypeTag = TYERROR;
        }
        if(myDebug){ msgn("TYPETAG OF ARRAY_NODE: "); ty_print_typetag(tempTypeTag); msg("");}
        if(genBackend) b_deref(tempTypeTag);
        if(tempTypeTag == TYFLOAT){
          if(genBackend)b_convert(TYFLOAT, TYDOUBLE);
          return TYDOUBLE;
        }
        return tempTypeTag;

      }else{
        char *tempIdString = st_get_id_str(startNode->u.array_node.arrayName);
        if(genBackend) b_push_ext_addr(tempIdString);
        TYPETAG tempErrorCheck = genBackendAssignment(startNode->u.array_node.access_node, 1, genBackend);
        if(tempErrorCheck != TYSIGNEDLONGINT){ error("Incompatible index type in array access"); tempTypeTag = TYERROR;}
        //if(genBackend) b_push_const_int(startNode->u.array_node.low);
        //if(genBackend) b_arith_rel_op(B_SUB , TYSIGNEDLONGINT);
        //if(genBackend) b_ptr_arith_op(B_ADD, TYSIGNEDLONGINT, getAlignmentSize(startNode->u.array_node.type));
        if(tempTypeTag == TYARRAY) msg("TYARRAY HERE");
        return tempTypeTag;
      }//END left hand side of assignment

    }case UNOP_NODE:{
      return handleUNOP_NODE(startNode,genBackend);

    }case BINOP_NODE:{
      return handleBINOP_NODE(startNode, genBackend);

    }case RELOP_NODE:{
      return handleRELOP_NODE(startNode, genBackend);

    }case ASSIGN_NODE:{
      inAssignment = 1;
      //just get what the return TYPETAGS would be, before generating any backend
      TYPETAG varTypeTag = genBackendAssignment(startNode->u.assign_node.varNode, 0, 0);
      TYPETAG expTypeTag = genBackendAssignment(startNode->u.assign_node.expression, 1, 0);


      if(myDebug){
        msgn("ASSIGNMENT: ");
        ty_print_typetag(varTypeTag);
        msgn(" := ");
        ty_print_typetag(expTypeTag);
        msg(";");
      }

      //check TYPETAG values for the assignment, then error check or gen the backend
      int INVALID = 1;
      if(varTypeTag == expTypeTag) INVALID = 0;
      if(varTypeTag == TYDOUBLE && expTypeTag == TYSIGNEDLONGINT) INVALID = 0;  //needs to do the conversion
      if(varTypeTag == TYFLOAT && expTypeTag == TYSIGNEDLONGINT) INVALID = 0;
      if(varTypeTag == TYFLOAT && expTypeTag == TYDOUBLE) INVALID = 0;
      if(varTypeTag == TYUNSIGNEDCHAR && expTypeTag == TYSIGNEDCHAR) INVALID = 0;
      if(varTypeTag == TYSIGNEDCHAR && expTypeTag == TYUNSIGNEDCHAR) INVALID = 0;

      if(varTypeTag == TYERROR | expTypeTag == TYERROR) INVALID = 1;


      if(INVALID){
       if(expTypeTag != TYERROR && varTypeTag != TYERROR){
         error("Illegal conversion");
       }//if TYERROR, the an error was printed already
      }else{
        genBackendAssignment(startNode->u.assign_node.varNode, 0, 1);

        expTypeTag = genBackendAssignment(startNode->u.assign_node.expression, 1, 1);

        inAssignment = 0;
        if(varTypeTag == TYDOUBLE && expTypeTag == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT,TYDOUBLE);
        if(varTypeTag == TYFLOAT && expTypeTag == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT,TYFLOAT);
        if(varTypeTag == TYFLOAT && expTypeTag == TYDOUBLE) b_convert(TYDOUBLE,TYFLOAT);
        if(varTypeTag == TYUNSIGNEDCHAR && expTypeTag == TYSIGNEDCHAR) b_convert(TYSIGNEDCHAR,TYUNSIGNEDCHAR);
        if(varTypeTag == TYSIGNEDCHAR && expTypeTag == TYUNSIGNEDCHAR) b_convert(TYUNSIGNEDCHAR,TYSIGNEDCHAR);

        b_assign(varTypeTag);
        b_pop();
      }
      return expTypeTag;

    }default:{
      bug("BACKEND ASSIGNMENT -- startNode->tag: %s", tagtypeStrings[startNode->tag]);
      break;
    }}
  }//END genBackendAssignment()


//Just for binops
TN handleConstantFolding(binopType op, TN Lnode, TN Rnode, TYPETAG Ltag, TYPETAG Rtag){
  double leftD;
  double rightD;
  long tempInt;
  double tempReal;

  if(Ltag == Rtag){ //they are the same type
    if(Ltag == TYSIGNEDLONGINT){ //both ints
      long left = Lnode->u.intconstant;
      long right = Rnode->u.intconstant;

      if(op == ADD) tempInt = left + right;
      if(op == SUB) tempInt = left - right;
      if(op == REAL_DIV) tempInt = left / right;
      if(op == INT_DIV) tempInt = left / right;
      if(op == MULT) tempInt = left * right;
      if(op == MOD) tempInt = left % right;
      //if(genBackend) b_push_const_int(tempInt);
      //return TYSIGNEDLONGINT;
      Lnode->u.intconstant = tempInt;
      return Lnode;
    }else{ //both doubles
      leftD = Lnode->u.realconstant;
      rightD = Rnode->u.realconstant;
    }
  }else{ //one of them is a double, other is an INT
      if(Ltag == TYDOUBLE){
        leftD = Lnode->u.realconstant;
        rightD = (double)Rnode->u.intconstant;
      }else{ //Ltag == TYSIGNEDLONGINT
        leftD = (double)Lnode->u.intconstant;
        rightD = Rnode->u.realconstant;
      }
  }



  if(op == ADD) tempReal = leftD + rightD;
  if(op == SUB) tempReal = leftD - rightD;
  if(op == REAL_DIV) tempReal = leftD / rightD;
  if(op == INT_DIV) tempReal = leftD / rightD;
  if(op == MULT) tempReal = leftD * rightD;
  if(op == MOD){
    error("wrong type for mod function");
    return makeErrorNode();
  }

  if(Ltag == TYDOUBLE){
    Lnode->u.realconstant = tempReal;
    return Lnode;
  }else{
    Rnode->u.realconstant = tempReal;
    return Rnode;
  }

}//END handleConstantFolding



TYPETAG handleBINOP_NODE(TN node, int genBackend){
  if(node->tag == BINOP_NODE){
    TYPETAG Ltag = genBackendAssignment(node->u.binop.left, 1, 0); //just get return type
    TYPETAG Rtag;
    if(Ltag != TYERROR){
      Rtag = genBackendAssignment(node->u.binop.right, 1, 0);
    }else{
       if(myDebug){msg("Ltag was tyerror in handleBINOP_NODE");}
       Rtag = TYERROR;
       return TYERROR;
     }
    tagtype LnodeType = node->u.binop.left->tag;
    tagtype RnodeType = node->u.binop.right->tag;
    int inValid = 1;

        if(Ltag == Rtag) inValid = 0;
        //if(Ltag == TYSIGNEDCHAR | Rtag == TYSIGNEDCHAR) inValid = 0;
        //if(Ltag == TYUNSIGNEDCHAR | Rtag == TYUNSIGNEDCHAR) inValid = 0;

        //Left cast up to Right
        if(Ltag == TYSIGNEDLONGINT && Rtag == TYFLOAT)  inValid = 0;
        if(Ltag == TYSIGNEDLONGINT && Rtag == TYDOUBLE)  inValid = 0;
        if(Ltag == TYFLOAT && Rtag == TYDOUBLE)  inValid = 0;

        //Right cast up to Left
        if(Rtag == TYSIGNEDLONGINT && Ltag == TYFLOAT)  inValid = 0;
        if(Rtag == TYSIGNEDLONGINT && Ltag == TYDOUBLE)  inValid = 0;
        if(Rtag == TYFLOAT && Ltag == TYDOUBLE) inValid = 0;

        //WRONG TYPES for MOD
        if(node->u.binop.binTag == MOD){
          if(Ltag == TYDOUBLE | Ltag == TYFLOAT) inValid = 1;
          if(Rtag == TYDOUBLE | Rtag == TYFLOAT) inValid = 1;
        }

        if(inValid == 0){



          Ltag = genBackendAssignment(node->u.relop.left, 1, genBackend);
          //Left cast up to Right
          if(Ltag == TYSIGNEDLONGINT && Rtag == TYFLOAT){
                                                        if(genBackend) b_convert(TYSIGNEDLONGINT, TYFLOAT);
                                                        Ltag = TYFLOAT;}
          if(Ltag == TYSIGNEDLONGINT && Rtag == TYDOUBLE){
                                                        if(genBackend) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
                                                        Ltag = TYDOUBLE;}
          if(Ltag == TYFLOAT && Rtag == TYDOUBLE){
                                                        if(genBackend) b_convert(TYFLOAT, TYDOUBLE);
                                                        Ltag = TYDOUBLE;}
          //if(Ltag == TYSIGNEDCHAR){                              b_convert(TYSIGNEDCHAR, TYSIGNEDLONGINT); Ltag = TYSIGNEDLONGINT;}
          //if(Ltag == TYUNSIGNEDCHAR){                            b_convert(TYUNSIGNEDCHAR, TYSIGNEDLONGINT); Ltag = TYSIGNEDLONGINT;}

          Rtag = genBackendAssignment(node->u.relop.right, 1, genBackend);
          //Right cast up to Left
          if(Rtag == TYSIGNEDLONGINT && Ltag == TYFLOAT){
                                                        if(genBackend) b_convert(TYSIGNEDLONGINT, TYFLOAT);
                                                        Rtag = TYFLOAT;}
          if(Rtag == TYSIGNEDLONGINT && Ltag == TYDOUBLE){
                                                        if(genBackend) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
                                                        Rtag = TYDOUBLE;}
          if(Rtag == TYFLOAT && Ltag == TYDOUBLE){
                                                        if(genBackend) b_convert(TYFLOAT, TYDOUBLE);
                                                        Rtag = TYDOUBLE;}
          //if(Rtag == TYSIGNEDCHAR){                              b_convert(TYSIGNEDCHAR, TYSIGNEDLONGINT);}
          //if(Rtag == TYUNSIGNEDCHAR){                            b_convert(TYUNSIGNEDCHAR, TYSIGNEDLONGINT);}





        if(myDebug){ msgn("handleBINOP_NODE: Ltag: "); ty_print_typetag(Ltag); msg("");}
        if(myDebug){ msgn("handleBINOP_NODE: Rtag: "); ty_print_typetag(Rtag); msg("");}
        switch(node->u.binop.binTag){
          case ADD:{
              if(genBackend) b_arith_rel_op(B_ADD, Ltag);
              return Ltag;
          }case SUB:{
              if(genBackend) b_arith_rel_op(B_SUB, Ltag);
              return Ltag;
          }case INT_DIV:{
              if(genBackend) b_arith_rel_op(B_DIV, Ltag);
              return Ltag;
          }case REAL_DIV:{
              if(genBackend) b_arith_rel_op(B_DIV, Ltag);
              return Ltag;
          }case MOD:{
              if(genBackend) b_arith_rel_op(B_MOD, Ltag);
              return Ltag;
          }case MULT:{
              if(genBackend) b_arith_rel_op(B_MULT, Ltag);
              return Ltag;
          }default:{
            bug("handleBINOP_NODE() bad binopType-- THIS IS AN error");
            break;
          }
        }//end switch on binTag
      }//END for inValid check
      else{
        if(errorCalled == 0) error("Nonnumerical type argument(s) to arithmetic operation");
        errorCalled = 1;
        return TYERROR;
      }
  }//end if BINOP_NODE

  else{ //not a BINOP_NODE, left or right side of a BINOP_NODE
    bug("handleBINOP_NODE() was passed NON-BINOP_NODE");
  }

}//end handleBINOP_NODE


TN handleConstantFoldingUNOP(unopType op, TN node){
  tagtype tempTagType = node->tag;
  int succOrpred = 1;
  switch(op){
    case CHR:{
      if(tempTagType == INTCONSTANT){
        int intValue = node->u.intconstant;
        char newChar = (char)intValue;
        TN tempNode = makeCharConstNode(newChar);
        return tempNode;
      }else{
        error("Illegal type argument to Chr");
      }
    }case ORD:{
      long newOrdinalRep;
      if(tempTagType == INTCONSTANT){
        long tempOrdinal = node->u.intconstant;
        newOrdinalRep = (long)tempOrdinal;
      }else if(tempTagType == CHARCONSTANT){
        char tempOrdinal = node->u.character;
        //msg("ohmightygods %s",tempOrdinal);
        newOrdinalRep = (int)tempOrdinal;
        //msg("ohmightygods 2 %ld",newOrdinalRep);
      }else if(tempTagType == BOOL_NODE){
        int tempOrdinal = node->u.boolean;
        newOrdinalRep = (long)tempOrdinal;
      }
      return makeIntConstNode(newOrdinalRep);
    }case SUCC:{
      succOrpred = 0;
    }case PRED:{
      long newOrdinalRep;
      if(tempTagType == INTCONSTANT){
        long tempOrdinal = node->u.intconstant;
        newOrdinalRep = (long)tempOrdinal;
      }else if(tempTagType == CHARCONSTANT){
        char tempOrdinal = node->u.character;
        newOrdinalRep = (int)tempOrdinal;
      }else if(tempTagType == BOOL_NODE){
        int tempOrdinal = node->u.boolean;
        newOrdinalRep = (long)tempOrdinal;
      }
      //------------------------------
      if(succOrpred == 0){//do SUCC
        newOrdinalRep = newOrdinalRep + 1;
      }else if(succOrpred == 1){//do PRED
        newOrdinalRep = newOrdinalRep - 1;
      }else{
        bug("SOMETHING BORKED IN THE handleConstantFoldingUNOP");
      }
      //-------------------------------
      if(tempTagType == INTCONSTANT){
        node->u.intconstant = newOrdinalRep;
      }else if(tempTagType == CHARCONSTANT){
        char tempChar = (char)newOrdinalRep;
        node->u.character = tempChar;
      }else if(tempTagType == BOOL_NODE){
        int temp = (int)newOrdinalRep;
        node->u.boolean = temp;
      }
      return node;
    }
  }//end switch
}


TYPETAG handleUNOP_NODE(TN node, int genBackend){
    switch(node->u.unop.unTag){
      case CHR:{
        TYPETAG tempTYPETAG = genBackendAssignment(node->u.unop.operand, 1, genBackend);
        if(tempTYPETAG != TYSIGNEDLONGINT){
           error("Wrong type for chr(int)");
           return TYERROR;
         }else{
          if(genBackend) b_convert(TYSIGNEDLONGINT, TYUNSIGNEDCHAR);
          return TYUNSIGNEDCHAR;
        }

      }case ORD:{  //no decimals
        TYPETAG tempTYPETAG = genBackendAssignment(node->u.unop.operand, 1, genBackend);
        if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDLONGINT | tempTYPETAG == TYSIGNEDCHAR){
          if(genBackend) b_convert(tempTYPETAG, TYSIGNEDLONGINT);
          return TYSIGNEDLONGINT;
         }else{
           error("Nonordinal type argument to Ord");
           return TYERROR;
          }

      }case SUCC:{ //no decimals
        TYPETAG tempTYPETAG = genBackendAssignment(node->u.unop.operand, 1, genBackend);
        if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDLONGINT | tempTYPETAG == TYSIGNEDCHAR){
          if(genBackend){
            if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDCHAR) b_convert(tempTYPETAG, TYSIGNEDLONGINT);
            b_push_const_int(1);
            b_arith_rel_op( B_ADD , TYSIGNEDLONGINT);
            if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDCHAR) b_convert (TYSIGNEDLONGINT, tempTYPETAG);
          }
          return tempTYPETAG;
        }else{
          error("Nonordinal type argument to Succ");
          return TYERROR;
        }

      }case PRED:{ //no decimals
        TYPETAG tempTYPETAG = genBackendAssignment(node->u.unop.operand, 1, genBackend);
        if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDLONGINT  | tempTYPETAG == TYSIGNEDCHAR){
          if(genBackend){
            if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDCHAR) b_convert(tempTYPETAG, TYSIGNEDLONGINT);
            b_push_const_int(-1);
            b_arith_rel_op(B_ADD , TYSIGNEDLONGINT);
            if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDCHAR) b_convert(TYSIGNEDLONGINT, tempTYPETAG);
          }
          return tempTYPETAG;
        }else{
          error("Nonordinal type argument to Pred");
          return TYERROR;
        }

      }case NEG:{
        if(myDebug){msg("SHOULD NEVER BE CALLED");}
        TYPETAG tempTYPETAG = genBackendAssignment(node->u.unop.operand, 1, genBackend);
        if(tempTYPETAG == TYVOID) error("Wrong type for -()"); //maybe more type not allowed
        if(genBackend) b_negate(tempTYPETAG);
        return tempTYPETAG;

      }default:{
        bug("unhandled case in handleUNOP_NODE");
      }

    }//END SWITC
}//end handleUNOP_NODE


TYPETAG handleRELOP_NODE(TN startNode, int genBackend){

  TYPETAG lhsTYPETAG = genBackendAssignment(startNode->u.relop.left, 1, 0);
  TYPETAG rhsTYPETAG = genBackendAssignment(startNode->u.relop.right, 1, 0);

  if(myDebug){ msgn("handleRELOP_NODE: lhsTYPETAG: "); ty_print_typetag(lhsTYPETAG);
   msgn("  rhsTYPETAG: ");  ty_print_typetag(rhsTYPETAG); msg("");}

  int inValid = 1;
  if(lhsTYPETAG == rhsTYPETAG) inValid = 0;
  if(lhsTYPETAG == TYSIGNEDCHAR | rhsTYPETAG == TYSIGNEDCHAR) inValid = 0;
  if(lhsTYPETAG == TYUNSIGNEDCHAR | rhsTYPETAG == TYUNSIGNEDCHAR) inValid = 0;

  //Left cast up to Right
  if(lhsTYPETAG == TYSIGNEDLONGINT && rhsTYPETAG == TYFLOAT)  inValid = 0;
  if(lhsTYPETAG == TYSIGNEDLONGINT && rhsTYPETAG == TYDOUBLE)  inValid = 0;
  if(lhsTYPETAG == TYFLOAT && rhsTYPETAG == TYDOUBLE)  inValid = 0;

  //Right cast up to Left
  if(rhsTYPETAG == TYSIGNEDLONGINT && lhsTYPETAG == TYFLOAT)  inValid = 0;
  if(rhsTYPETAG == TYSIGNEDLONGINT && lhsTYPETAG == TYDOUBLE)  inValid = 0;
  if(rhsTYPETAG == TYFLOAT && lhsTYPETAG == TYDOUBLE)  inValid = 0;

  //NOT OK
  if(lhsTYPETAG == TYDOUBLE && rhsTYPETAG == TYSIGNEDCHAR)  inValid = 1;
  if(rhsTYPETAG == TYDOUBLE && lhsTYPETAG == TYSIGNEDCHAR)  inValid = 1;

  if(inValid == 0){

    if(genBackend){

      genBackendAssignment(startNode->u.relop.left, 1, genBackend);
      //Left cast up to Right
      if(lhsTYPETAG == TYSIGNEDLONGINT && rhsTYPETAG == TYFLOAT){  b_convert(TYSIGNEDLONGINT, TYFLOAT); lhsTYPETAG = TYFLOAT;}
      if(lhsTYPETAG == TYSIGNEDLONGINT && rhsTYPETAG == TYDOUBLE){ b_convert(TYSIGNEDLONGINT, TYDOUBLE); lhsTYPETAG = TYDOUBLE;}
      if(lhsTYPETAG == TYFLOAT && rhsTYPETAG == TYDOUBLE){         b_convert(TYFLOAT, TYDOUBLE); lhsTYPETAG = TYDOUBLE;}
      if(lhsTYPETAG == TYSIGNEDCHAR){                              b_convert(TYSIGNEDCHAR, TYSIGNEDLONGINT); lhsTYPETAG = TYSIGNEDLONGINT;}
      if(lhsTYPETAG == TYUNSIGNEDCHAR){                            b_convert(TYUNSIGNEDCHAR, TYSIGNEDLONGINT); lhsTYPETAG = TYSIGNEDLONGINT;}
      if(lhsTYPETAG == rhsTYPETAG && lhsTYPETAG == TYFLOAT){       b_convert(TYUNSIGNEDCHAR, TYSIGNEDLONGINT); lhsTYPETAG = TYDOUBLE;}

      genBackendAssignment(startNode->u.relop.right, 1, genBackend);
      //Right cast up to Left
      if(rhsTYPETAG == TYSIGNEDLONGINT && lhsTYPETAG == TYFLOAT)   b_convert(TYSIGNEDLONGINT, TYFLOAT);
      if(rhsTYPETAG == TYSIGNEDLONGINT && lhsTYPETAG == TYDOUBLE)  b_convert(TYSIGNEDLONGINT, TYDOUBLE);
      if(rhsTYPETAG == TYFLOAT && lhsTYPETAG == TYDOUBLE)          b_convert(TYFLOAT, TYDOUBLE);
      if(rhsTYPETAG == TYSIGNEDCHAR){                              b_convert(TYSIGNEDCHAR, TYSIGNEDLONGINT);}
      if(rhsTYPETAG == TYUNSIGNEDCHAR){                            b_convert(TYUNSIGNEDCHAR, TYSIGNEDLONGINT);}

    }

    if(myDebug){ msgn("%d handleRELOP_NODE: lhsTYPETAG: ",genBackend); ty_print_typetag(lhsTYPETAG); msg("");}
    switch(startNode->u.relop.relTag){
      case NE:{
        if(genBackend) b_arith_rel_op(B_NE,lhsTYPETAG);
        if(genBackend) b_convert(TYSIGNEDLONGINT, TYSIGNEDCHAR);
        return TYSIGNEDCHAR;
      }case LE:{
        if(genBackend) b_arith_rel_op(B_LE,lhsTYPETAG);
        if(genBackend) b_convert(TYSIGNEDLONGINT, TYSIGNEDCHAR);
        return TYSIGNEDCHAR;
      }case GE:{
        if(genBackend) b_arith_rel_op(B_GE,lhsTYPETAG);
        if(genBackend) b_convert(TYSIGNEDLONGINT, TYSIGNEDCHAR);
        return TYSIGNEDCHAR;
      }case EQ:{
        if(genBackend) b_arith_rel_op(B_EQ,lhsTYPETAG);
        if(genBackend) b_convert(TYSIGNEDLONGINT, TYSIGNEDCHAR);
        return TYSIGNEDCHAR;
      }case LT:{
        if(genBackend) b_arith_rel_op(B_LT,lhsTYPETAG);
        if(genBackend) b_convert(TYSIGNEDLONGINT, TYSIGNEDCHAR);
        return TYSIGNEDCHAR;
      }case GT:{
        if(genBackend) b_arith_rel_op(B_GT,lhsTYPETAG);
        if(genBackend) b_convert(TYSIGNEDLONGINT, TYSIGNEDCHAR);
        return TYSIGNEDCHAR;
      }default:{
        bug("Unhandled case in handleRELOP_NODE() with relTag: %d a.k.a. %s", startNode->u.relop.relTag, startNode->u.relop.relTag[relationalTypeStrings]);
      }
    }//END switch
  }//END INVALID
  else{
    error("Incompatible type arguments to comparison operator");
    return TYERROR;
  }
}//END handleRELOP_NODE



  TYPETAG getTYPETAG(TN node){
    if(node->tag == VAR_NODE){
      TYPETAG tempTypeTag = node->u.var_node.typeTag;
      if(tempTypeTag != NULL){
         return tempTypeTag;
      }else{
        if(myDebug) msg("\n ----- getTYPETAG, returned tyerror:");
         return TYERROR;
       }
    }else if(node->tag == ARRAY_NODE){ //end if VAR_NODE
        TYPETAG tempTypeTag = node->u.array_node.typeTag;
        if(tempTypeTag != NULL){
          return tempTypeTag;
        }else{
          if(myDebug) msg("\n ----- getTYPETAG, returned tyerror:");
           return TYERROR;
        }
    }
    if(myDebug) msg("\n ----- VAR_NODE, getTYPETAG, returned tyerror:");
    return TYERROR;
  }//END getTYPETAG()


  /*
  **********DEBUGGING STUFF**************
  */
  void treeNodeToString(TN node, int isTop){
    //INTCONSTANT, REALCONSTANT, NEGNUM
    if(isTop) msgn("TREE NODE    ");
    switch(node->tag){



      //PART 3
      case IF_NODE:
        msg("IF_NODE:{");
        msg("\nBoolean: ");
        treeNodeToString(node->u.if_node.relop, 0);
        msg("\nExpression: ");
        if(node->u.if_node.expression != NULL){ msgn("        "); treeNodeToString(node->u.if_node.expression, 0); msg("}");}

        if(node->u.if_node.elseNode != NULL){ treeNodeToString(node->u.if_node.elseNode, 0);}
        break;

      case ELSE_NODE:
        msg("\nELSE_NODE: {");
        if(node->u.else_node.expression->tag == IF_NODE){ treeNodeToString(node->u.else_node.expression, 0); msg("}");}
        else{ msgn("        "); treeNodeToString(node->u.else_node.expression, 0); msg("}");}
        break;

        case WHILE_NODE:
          msg("WHILE_NODE:{");
          msg("\nBoolean:");
          treeNodeToString(node->u.while_node.relop, 0);
          msg("\nExpression: ");
          if(node->u.while_node.expression != NULL){ msgn("        "); treeNodeToString(node->u.while_node.expression, 0); msg("}");}
          break;

        case STATEMENT_NODE:
          msg("STATEMENT_NODE:");
          msgn("        "); treeNodeToString(node->u.statement_node.expression, 0);
          if(node->u.statement_node.nextStatement != NULL){ msgn("        "); treeNodeToString(node->u.statement_node.nextStatement, 0);}
          msg("");
          break;

        case ACCESS_NODE:
          msg("ACCESS_NODE: low: %d", node->u.access_node.low);
          msgn("        "); treeNodeToString(node->u.access_node.expression, 0);
          if(node->u.access_node.nextStatement != NULL){ msgn("        "); treeNodeToString(node->u.access_node.nextStatement, 0);}
          msg("");
          break;

        case ARRAY_NODE:{
          msgn("ARRAY_NODE: %s of type:", st_get_id_str(node->u.array_node.arrayName));
          ty_print_typetag(node->u.array_node.typeTag);
          msgn("   TYPE: "); msg("low: %d high: %d",node->u.array_node.low, node->u.array_node.high);
          msgn("         with access parameter node: ");
          treeNodeToString(node->u.array_node.access_node, 0);
          break;
        }


      //PART 2
      case CHARCONSTANT:
        if(isTop) msg("CHARCONSTANT node: %c ", node->u.character);
        else msgn("CHARCONSTANT node: %c ", node->u.character);
        break;

      case INTCONSTANT:
        if(isTop) msg("INTCONSTANT node: %ld ", node->u.intconstant);
        else msgn("INTCONSTANT node: %ld ", node->u.intconstant);
        break;

      case REALCONSTANT:
        if(isTop) msg("REALCONSTANT node: %f ",node->u.realconstant);
        else msgn("REALCONSTANT node: %f ",node->u.realconstant);
        break;

      case BOOL_NODE:
        if(isTop) msg("BOOL_NODE node: %d ",node->u.boolean);
        else msgn("BOOL_NODE node: %d ",node->u.boolean);
        break;

      case NEGNUM:
        msgn("NEGNUM node --> ");
        treeNodeToString(node->u.negNode, 0);
        break;

      case VAR_NODE:
        msgn("VAR_NODE node: %s of type: ",st_get_id_str(node->u.var_node.varName));
        ty_print_typetag(getTYPETAG(node));
        msg("");
        break;

      case UNOP_NODE:
        msgn("UNOP_NODE %s ", unopTypeStrings[node->u.unop.unTag]);
        msgn("operand: ");
        treeNodeToString(node->u.unop.operand, 0);
        break;

      case BINOP_NODE:
        msgn("     LEFT: ");
        treeNodeToString(node->u.binop.left, 0);
        msgn("     BINOP_NODE %s ", binopTypeStrings[node->u.binop.binTag]);
        msgn("     RIGHT: ");
        treeNodeToString(node->u.binop.right, 0);
        break;

      case RELOP_NODE:
        msgn("   LEFT: ");
        treeNodeToString(node->u.relop.left, 0);
        msgn("   RELOP_NODE %s ", relationalTypeStrings[node->u.relop.relTag]);
        msgn("   RIGHT: ");
        treeNodeToString(node->u.relop.right, 0);
        break;

      case ASSIGN_NODE:
        msgn("ASSIGN_NODE var --> ");
        treeNodeToString(node->u.assign_node.varNode, 0);
        msgn("             Expression nodes --> ");
        treeNodeToString(node->u.assign_node.expression, 0);
        msg("");
        break;

      case FUNC_NODE:{
          msgn("FUNC_NODE node: %s of type: ",st_get_id_str(node->u.func_node.funcName));
          ty_print_typetag(node->u.func_node.typeTag);
          msg("");
          break;
      }

      case ERROR_NODE:
          msg("ERROR_NODE");
          break;

      default:
        if(isTop) msg("NULL -- THIS IS AN error");
        else msgn("NULL -- THIS IS AN error");
    }
  }



  /*
  ********************OTHER STUFF*************
  */




  LD addToList(ST_ID id, LD oldList){
    LD tempLid = (LD)malloc(sizeof(listOfIds));
    tempLid->data = id;
    tempLid->next = oldList;

    return tempLid;
  }



  INDEX_LIST addToArraySubList(TYPE object, INDEX_LIST root){
    INDEX_LIST tempEntry = (INDEX_LIST)malloc(sizeof(INDEX));
    tempEntry->type = object;
    tempEntry->next = NULL;
    tempEntry->prev = NULL;
    INDEX_LIST lastEntry = root;

    if(lastEntry != NULL){
      while(lastEntry->next != NULL){
        lastEntry = lastEntry->next;
      }
      lastEntry->next = tempEntry;
      tempEntry->prev = lastEntry;
    }


    if(root == NULL){
      return tempEntry;
    }else{
      return root;
    }
  }


  INDEX_LIST addToUnresolvedPtrs(TYPE object, INDEX_LIST root){
    INDEX_LIST tempEntry = (INDEX_LIST)malloc(sizeof(INDEX));
    tempEntry->type = object;
    tempEntry->next = NULL;
    INDEX_LIST lastEntry = root;
    while(lastEntry->next != NULL){
      lastEntry = lastEntry->next;
    }

    lastEntry->next = tempEntry;
    tempEntry->prev = lastEntry;

    return tempEntry;
  }

  int getAlignmentSize(TYPE type){
    INDEX_LIST list;
    long low;
    long high;
    TYPETAG typeTag = ty_query(type);
    switch(typeTag){
      case TYSIGNEDLONGINT:
        return 4;

      case TYSIGNEDSHORTINT:
        return 4;

      case TYSIGNEDINT:
        return 4;

      case TYUNSIGNEDLONGINT:
        return 4;

      case TYUNSIGNEDSHORTINT:
        return 4;

      case TYUNSIGNEDINT:
        return 4;

      case TYUNSIGNEDCHAR:
        return 1;

      case TYSIGNEDCHAR:
        return 1;

      case TYARRAY:
        return getAlignmentSize(ty_query_array(type, &list));

      case TYPTR:
        return 4;

      case TYSUBRANGE:
        return getAlignmentSize(ty_query_subrange(type, &low, &high));

      case TYDOUBLE:
        return 8;

     case TYFLOAT:
        return 4;

     case TYLONGDOUBLE:
        return 8;

    }
  }//END getAlignmentSize()


  int getSize(TYPE type, int baseTypeSize){
    INDEX_LIST currList;
    long low;
    long high;
    TYPETAG typeTag = ty_query(type);
    TYPE tempSubRange;
    switch(typeTag){
      TYPE tempTYPE;
      int indexSize;
      case TYARRAY:
        tempTYPE = ty_query_array(type, &currList);
        indexSize = 0;
        do{
          tempSubRange = currList->type;
          ty_query_subrange(tempSubRange, &low, &high);
          if(indexSize == 0){
            indexSize = high - low + 1;
          }else{
            indexSize = indexSize * (high - low + 1);
          }
          currList = currList->next;
        }while(currList != NULL);

        if(ty_query(tempTYPE) == TYARRAY){
          return indexSize * getSize(tempTYPE, baseTypeSize);
        }
        return indexSize * baseTypeSize;

      case TYSUBRANGE:
        ty_query_subrange(type, &low, &high);
        return 4; //Assumption: In Part 1 of the project we believe we are only dealing with Integer values of subranges and so we return the size value of integers

     default:
        return baseTypeSize;
    }
  }
