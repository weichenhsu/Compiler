/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol();
    static void insert_symbol();
    static char* lookup_symbol();
    static void dump_symbol();
    static void store_symbol();
    static char* lookup_assign_symbol();

    int HAS_ERROR = 0;
    int compare = 1, label = 0;
    FILE *fp;
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
}

/* Token without return */
%token VAR
%token INT FLOAT BOOL STRING
%token NEWLINE
%token INC DEC GEQ LEQ EQL NEQ GTR LSS
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token LAND LOR
%token PRINT PRINTLN IF ELSE FOR
%token TRUE FALSE


/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <i_val> BOOL_LIT
%token <s_val> IDENT


/* Nonterminal with return, which need to sepcify type */
%type <s_val> Literal Identifier Factor Expression Term Operand UnaryExpr LogiLAND LogiLOR
%type <s_val> ConversionExpr Comparison TypeName Identifier_assign ForComp Ifcomp ForComp2
%type <i_val> Iftemp Elsetemp Fortemp Forsimp

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : StatementList { dump_symbol();}
;

StatementList
    : StatementList Statement
    | Statement
;

Statement
    : DeclarationStmt NEWLINE { lineno++; }
    | SimpleStmt NEWLINE { lineno++; }
    | Block 
    | IfStmt 
    | ForStmt
    | PrintStmt NEWLINE { lineno++; }
    | NEWLINE { lineno++; }
;

Block
    : '{' StatementList '}' {   if(scope >= scope_com){
                                    scope_com = scope + 1;
                                }
                                dump_symbol(); }
;

Operand
    : Literal { $$ = $1; }
    | Identifier { $$ = $1;}
    | '(' Expression ')' { $$ = $2; }
;

Literal
    : INT_LIT   {   $$ = "int32";
                    fprintf(fp, "ldc %d\n", yylval.i_val); 
                }
    | FLOAT_LIT {   $$ = "float32";
                    fprintf(fp, "ldc %-6f\n", yylval.f_val); 
                }
    | BOOL_LIT  { $$ = "bool"; }
    | '"' STRING_LIT '"'    {   $$ = "string";
                                fprintf(fp, "ldc \"%s\"\n", yylval.s_val); 
                            }
;

ConversionExpr
    : INT '(' Expression ')' { fprintf(fp, "f2i\n"); $$ = "int32"; }
    | FLOAT '(' Expression ')' { fprintf(fp, "i2f\n"); $$ = "float32"; }
;


TypeName
    : INT { $$ = "int32"; }
    | FLOAT { $$ = "float32"; }
    | STRING { $$ = "string"; }
    | BOOL { $$ = "bool"; }
;

ArrayType
    : '[' Expression ']' 
;

DeclarationStmt
    : VAR IDENT TypeName { if(scope != scope_com){
                            scope_com = scope;
                            create_symbol();
                            } 
                            if(strcmp($3, "int32") == 0)
                                fprintf(fp, "ldc 0\n");
                            else if(strcmp($3, "float32") == 0)
                                fprintf(fp, "ldc 0.0\n");
                            else if(strcmp($3, "string") == 0)
                                fprintf(fp, "ldc \"\"\n");

                            insert_symbol($2, 1);
                        }
    | VAR IDENT TypeName '=' Factor {   if(scope != scope_com){
                                            scope_com = scope;
                                            create_symbol();
                                        }
                                        insert_symbol($2, 2); }    
    | VAR IDENT ArrayType TypeName {    if(scope != scope_com){
                                            scope_com = scope;
                                            create_symbol();
                                        }
                                        insert_symbol($2, 3);
                                    }                 
;

SimpleStmt
    : AssignmentStmt
    | IncDecStmt
    | LogiLOR
    | ErrorStmt
;

AssignmentStmt
    : Identifier_assign '=' Expression {   
                                            char *tmp = strtok($1, "_");
                                            char *id = strtok(NULL, "\n");
                                            if($1 != NULL && $3 != NULL)
                                                if(strcmp($1, $3) != 0){
                                                    fprintf(fp, "error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                                    HAS_ERROR = 1;
                                                }  
                                            store_symbol(id);                                 
                                        }
    | Identifier_assign ADD_ASSIGN Expression {    
                                                    char *tmp = strtok($1, "_");
                                                    char *id = strtok(NULL, "\n");
                                                    if($1 != NULL && $3 != NULL)
                                                        if(strcmp($1, $3) != 0){
                                                            fprintf(fp, "error:%d: invalid operation: ADD_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                                            HAS_ERROR = 1;
                                                        }
                                                    lookup_symbol(id);
                                                    if(strcmp($1, "int32") == 0)
                                                        fprintf(fp, "iadd\n");
                                                    else
                                                        fprintf(fp, "fadd\n"); 
                                                    store_symbol(id);
                                                }
    | Identifier_assign SUB_ASSIGN Expression   {    
                                                    char *tmp = strtok($1, "_");
                                                    char *id = strtok(NULL, "\n");
                                                    if($1 != NULL && $3 != NULL)
                                                        if(strcmp($1, $3) != 0){
                                                            fprintf(fp, "error:%d: invalid operation: SUB_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                                            HAS_ERROR = 1;
                                                        }
                                                    lookup_symbol(id);
                                                    if(strcmp($1, "int32") == 0)
                                                        fprintf(fp, "swap\nisub\n");
                                                    else
                                                        fprintf(fp, "swap\nfsub\n");  
                                                    store_symbol(id);
                                                }
    | Identifier_assign MUL_ASSIGN Expression   {    
                                                    char *tmp = strtok($1, "_");
                                                    char *id = strtok(NULL, "\n");
                                                    if($1 != NULL && $3 != NULL)
                                                        if(strcmp($1, $3) != 0){
                                                            fprintf(fp, "error:%d: invalid operation: MUL_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                                            HAS_ERROR = 1;
                                                        }
                                                    lookup_symbol(id);
                                                    if(strcmp($1, "int32") == 0)
                                                        fprintf(fp, "imul\n");
                                                    else
                                                        fprintf(fp, "fmul\n");  
                                                    store_symbol(id); 
                                                }
    | Identifier_assign QUO_ASSIGN Expression {    
                                                    char *tmp = strtok($1, "_");
                                                    char *id = strtok(NULL, "\n");
                                                    if($1 != NULL && $3 != NULL)
                                                        if(strcmp($1, $3) != 0){
                                                            fprintf(fp, "error:%d: invalid operation: QUO_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                                            HAS_ERROR = 1;
                                                        }
                                                    lookup_symbol(id);
                                                    if(strcmp($1, "int32") == 0)
                                                        fprintf(fp, "swap\nidiv\n");
                                                    else
                                                        fprintf(fp, "swap\nfdiv\n");  
                                                    store_symbol(id);
                                                }
    | Identifier_assign REM_ASSIGN Expression {    
                                                    char *tmp = strtok($1, "_");
                                                    char *id = strtok(NULL, "\n");
                                                    if($1 != NULL && $3 != NULL)
                                                        if(strcmp($1, $3) != 0){
                                                            fprintf(fp, "error:%d: invalid operation: REM_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                                            HAS_ERROR = 1;
                                                        }
                                                    lookup_symbol(id);
                                                    fprintf(fp, "swap\nirem\n"); 
                                                    store_symbol(id); 
                                                }
    | Identifier  ArrayType '=' Expression  {   
                                                if($1 != NULL && $4 != NULL)
                                                    if(strcmp($1, $4) != 0){
                                                        fprintf(fp, "error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $4);
                                                        HAS_ERROR = 1;
                                                    }
                                                if(strcmp($1, "int32") == 0)
                                                    fprintf(fp, "iastore\n");
                                                else
                                                    fprintf(fp, "fastore\n");                                    
                                            }
    | Identifier  ArrayType ADD_ASSIGN Expression  {    
                                                        if($1 != NULL && $4 != NULL)
                                                            if(strcmp($1, $4) != 0){
                                                                fprintf(fp, "error:%d: invalid operation: ADD_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $4);
                                                                HAS_ERROR = 1;
                                                            }
                                                        fprintf(fp, "ADD_ASSIGN\n"); 
                                                    }
    | Identifier  ArrayType SUB_ASSIGN Expression  {    
                                                        if($1 != NULL && $4 != NULL)
                                                            if(strcmp($1, $4) != 0){
                                                                fprintf(fp, "error:%d: invalid operation: SUB_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $4);
                                                                HAS_ERROR = 1;
                                                            }
                                                        fprintf(fp, "SUB_ASSIGN\n"); 
                                                    }
    | Identifier  ArrayType MUL_ASSIGN Expression  {    
                                                        if($1 != NULL && $4 != NULL)
                                                            if(strcmp($1, $4) != 0){
                                                                fprintf(fp, "error:%d: invalid operation: MUL_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $4);
                                                                HAS_ERROR = 1;
                                                            }
                                                        fprintf(fp, "MUL_ASSIGN\n"); 
                                                    }
    | Identifier  ArrayType QUO_ASSIGN Expression  {    
                                                        if($1 != NULL && $4 != NULL)
                                                            if(strcmp($1, $4) != 0){
                                                                fprintf(fp, "error:%d: invalid operation: QUO_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $4);
                                                                HAS_ERROR = 1;
                                                            }
                                                        fprintf(fp, "QUO_ASSIGN\n"); 
                                                    }
    | Identifier  ArrayType REM_ASSIGN Expression  {    
                                                        if($1 != NULL && $4 != NULL)
                                                            if(strcmp($1, $4) != 0){
                                                                fprintf(fp, "error:%d: invalid operation: REM_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $4);
                                                                HAS_ERROR = 1;
                                                            }
                                                        fprintf(fp, "REM_ASSIGN\n"); 
                                                    }
;

Identifier
    : IDENT {   
                $$ = lookup_symbol(yylval);
            }
;

Identifier_assign
    : IDENT {   $$ = lookup_assign_symbol(yylval);
                strcat($$, "_");
                strcat($$, $1);
            }
;

IncDecStmt
    : IDENT INC {   char* ptr = strtok($1, "++");
                    char* type = lookup_symbol(ptr);
                    if(strcmp(type, "int32") == 0)
                        fprintf(fp, "ldc 1\niadd\n");
                    else
                        fprintf(fp, "ldc 1.0\nfadd\n");    
                    store_symbol(ptr);    
                }
    | IDENT DEC {   char* ptr = strtok($1, "--");
                    char* type = lookup_symbol(ptr);
                    if(strcmp(type, "int32") == 0)
                        fprintf(fp, "ldc 1\nisub\n");
                    else
                        fprintf(fp, "ldc 1.0\nfsub\n"); 
                    store_symbol(ptr);    
                }
;

ErrorStmt
    : Literal '=' Expression { fprintf(fp, "error:%d: cannot assign to %s\nASSIGN\n", lineno+1, $1); HAS_ERROR = 1; }
    | Literal ADD_ASSIGN Expression { fprintf(fp, "error:%d: cannot assign to %s\nADD_ASSIGN\n", lineno+1, $1); HAS_ERROR = 1; }
    | Literal SUB_ASSIGN Expression { fprintf(fp, "error:%d: cannot assign to %s\nSUB_ASSIGN\n", lineno+1, $1); HAS_ERROR = 1; }
    | Literal MUL_ASSIGN Expression { fprintf(fp, "error:%d: cannot assign to %s\nMUL_ASSIGN\n", lineno+1, $1); HAS_ERROR = 1; }
    | Literal QUO_ASSIGN Expression { fprintf(fp, "error:%d: cannot assign to %s\nQUO_ASSIGN\n", lineno+1, $1); HAS_ERROR = 1; }
    | Literal REM_ASSIGN Expression { fprintf(fp, "error:%d: cannot assign to %s\nREM_ASSIGN\n", lineno+1, $1); HAS_ERROR = 1; }
;

IfStmt
    : Iftemp Ifcomp Block   {    
                                fprintf(fp, "L_if_false%d:\n", $1);
                                if(strcmp($2, "bool") != 0){
                                    fprintf(fp, "error:%d: non-bool (type %s) used as for condition\n", lineno+1, $2);
                                    HAS_ERROR = 1;
                                }
                            }
    | Iftemp Ifcomp Block ElseStmt  {    
                                //fprintf(fp, "L_if_false%d:\n", $1);
                                if(strcmp($2, "bool") != 0){
                                    fprintf(fp, "error:%d: non-bool (type %s) used as for condition\n", lineno+1, $2);
                                    HAS_ERROR = 1;
                                }
                            }
    ;
Ifcomp
    : Comparison { $$ = $1; fprintf(fp, "ifeq L_if_false%d\n", label); label++; }
;


ElseStmt
    : Elsetemp Iftemp Ifcomp Block ElseStmt { fprintf(fp, "L_if_exit%d:\n", $1); }
    | Elsetemp Block  { fprintf(fp, "L_if_exit%d:\n", $1); }
;

Iftemp
    : IF { $$ = label; }
;

Elsetemp
    : ELSE { fprintf(fp, "goto L_if_exit%d\nL_if_false%d:\n", label-1, label-1); $$ = label-1; }
;

ForStmt
    : Fortemp ForComp Block { 
                        if(strcmp($2, "bool") != 0){
                            fprintf(fp, "error:%d: non-bool (type %s) used as for condition\n", lineno+1, $2);
                            HAS_ERROR = 1;
                        }
                        fprintf(fp, "goto L_for_begin%d\nL_for_exit%d:\n", $1, $1);
                    }
    | Fortemp Forsimp ';' ForComp2 ';' Forsimp2 Block { if(strcmp($4, "bool") != 0){
                                                            fprintf(fp, "error:%d: non-bool (type %s) used as for condition\n", lineno+1, $4);
                                                            HAS_ERROR = 1;
                                                        }
                                                        fprintf(fp, "goto L_for_post%d\nL_for_exit%d:\n", $2, $2);
                                                    }
;

Fortemp
    : FOR { fprintf(fp, "L_for_begin%d:\n", label); $$ = label; }
;

ForComp
    : Comparison { fprintf(fp, "ifeq L_for_exit%d\n", label);  $$ = $1; label++; }
;

ForComp2
    : Comparison { fprintf(fp, "goto L_for_pre%d\nL_for_post%d:\n", label, label);  $$ = $1; }
;

Forsimp
    : SimpleStmt { label++; fprintf(fp, "L_for_begin%d:\n", label); $$ = label; }
;

Forsimp2
    : SimpleStmt { fprintf(fp, "goto L_for_begin%d\nL_for_pre%d:\nifeq L_for_exit%d\n", label, label, label); label++; }
;


PrintStmt
    : PRINT '(' LogiLOR ')' {   fprintf(fp, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print" ); 
                                if(strcmp($3, "int32") == 0)
                                    fprintf(fp, "(I)V\n");
                                else if(strcmp($3, "float32") == 0)
                                    fprintf(fp, "(F)V\n");
                                else
                                    fprintf(fp, "(Ljava/lang/String;)V\n");
                            }
    | PRINTLN '(' LogiLOR ')' { fprintf(fp, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println" ); 
                                if(strcmp($3, "int32") == 0)
                                    fprintf(fp, "(I)V\n");
                                else if(strcmp($3, "float32") == 0)
                                    fprintf(fp, "(F)V\n");
                                else
                                    fprintf(fp, "(Ljava/lang/String;)V\n");
                            }
;

LogiLOR
    : LogiLOR LOR LogiLAND { if(strcmp($1, "bool") != 0 || strcmp($3, "bool") != 0){
                                if(strcmp($1, "bool") != 0){
                                    fprintf(fp, "error:%d: invalid operation: (operator LOR not defined on %s)\n", lineno+1, $1);
                                    HAS_ERROR = 1;
                                }
                                else{
                                    fprintf(fp, "error:%d: invalid operation: (operator LOR not defined on %s)\n", lineno+1, $3);
                                    HAS_ERROR = 1;
                                }
                            }
                            $$ = "bool"; 
                            fprintf(fp, "ior\nifne L_cmp_%d\nldc \"false\"\ngoto L_cmp_%d\nL_cmp_%d:\nldc \"true\"\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                            compare += 2; 
                        }
    | LogiLAND { $$ = $1; }
;

LogiLAND
    : LogiLAND LAND Comparison { if(strcmp($1, "bool") != 0 || strcmp($3, "bool") != 0){
                                    if(strcmp($1, "bool") != 0){
                                        fprintf(fp, "error:%d: invalid operation: (operator LAND not defined on %s)\n", lineno+1, $1);
                                        HAS_ERROR = 1;
                                    }
                                    else{
                                        fprintf(fp, "error:%d: invalid operation: (operator LAND not defined on %s)\n", lineno+1, $3);
                                        HAS_ERROR = 1;
                                    }
                                }
                                    $$ = "bool"; fprintf(fp, "iand\n"); 
                                }
    | Comparison { $$ = $1; }
;

Comparison
    : Comparison GTR Expression {   $$ = "bool"; 
                                    if(strcmp($1, "int32") == 0)
                                        fprintf(fp, "isub\n");
                                    else if(strcmp($1, "float32") == 0)
                                        fprintf(fp, "fcmpl\n");
                                    fprintf(fp, "ifgt L_cmp_%d\niconst_0\ngoto L_cmp_%d\nL_cmp_%d:\niconst_1\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                                    compare += 2; 
                                }
    | Comparison LSS Expression {   $$ = "bool"; 
                                    if(strcmp($1, "int32") == 0)
                                        fprintf(fp, "isub\n");
                                    else
                                        fprintf(fp, "fcmpl\n");
                                    fprintf(fp, "iflt L_cmp_%d\niconst_0\ngoto L_cmp_%d\nL_cmp_%d:\niconst_1\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                                    compare += 2; 
                                }
    | Comparison GEQ Expression {   $$ = "bool"; 
                                    if(strcmp($1, "int32") == 0)
                                        fprintf(fp, "isub\n");
                                    else if(strcmp($1, "float32") == 0)
                                        fprintf(fp, "fcmpl\n");
                                    fprintf(fp, "ifge L_cmp_%d\niconst_0\ngoto L_cmp_%d\nL_cmp_%d:\niconst_1\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                                    compare += 2; 
                                }
    | Comparison LEQ Expression {   $$ = "bool"; 
                                    if(strcmp($1, "int32") == 0)
                                        fprintf(fp, "isub\n");
                                    else if(strcmp($1, "float32") == 0)
                                        fprintf(fp, "fcmpl\n");
                                    fprintf(fp, "ifle L_cmp_%d\niconst_0\ngoto L_cmp_%d\nL_cmp_%d:\niconst_1\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                                    compare += 2; 
                                }
    | Comparison EQL Expression {   $$ = "bool"; 
                                    if(strcmp($1, "int32") == 0)
                                        fprintf(fp, "isub\n");
                                    else
                                        fprintf(fp, "fsub\n");
                                    fprintf(fp, "ifeq L_cmp_%d\niconst_0\ngoto L_cmp_%d\nL_cmp_%d:\niconst_1\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                                    compare += 2; 
                                }
    | Comparison NEQ Expression {   $$ = "bool"; 
                                    if(strcmp($1, "int32") == 0)
                                        fprintf(fp, "isub\n");
                                    else
                                        fprintf(fp, "fsub\n");
                                    fprintf(fp, "ifne L_cmp_%d\niconst_0\ngoto L_cmp_%d\nL_cmp_%d:\niconst_1\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                                    compare += 2; 
                                }
    | Expression { $$ = $1; }
;

Expression
    : Expression '+' Term { if(strcmp($1, $3) != 0){
                                fprintf(fp, "error:%d: invalid operation: ADD (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                HAS_ERROR = 1;
                            }
                            else{
                                if(strcmp($1, "int32") == 0)
                                    fprintf(fp, "iadd\n");
                                else
                                    fprintf(fp, "fadd\n");
                            } 
                        }
    | Expression '-' Term { 
                            if(strcmp($1, $3) != 0){
                                fprintf(fp, "error:%d: invalid operation: SUB (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                HAS_ERROR = 1;
                            }
                            else{
                                if(strcmp($1, "int32") == 0)
                                    fprintf(fp, "isub\n");
                                else
                                    fprintf(fp, "fsub\n");
                            } 
                        }
    | Term { $$ = $1; }
;

Term
    : Term '*' Factor { if(strcmp($1, $3) != 0){
                            fprintf(fp, "error:%d: invalid operation: MUL (mismatched types %s and %s)\n", lineno+1, $1, $3);
                            HAS_ERROR = 1;
                        }
                        else{
                            if(strcmp($1, "int32") == 0)
                                fprintf(fp, "imul\n");
                            else
                                    fprintf(fp, "fmul\n");
                        }         
                    }
    | Term '/' Factor { if(strcmp($1, $3) != 0){
                            fprintf(fp, "error:%d: invalid operation: DIV (mismatched types %s and %s)\n", lineno+1, $1, $3);
                            HAS_ERROR = 1;
                        }
                        else{
                            if(strcmp($1, "int32") == 0)
                                fprintf(fp, "idiv\n");
                            else
                                    fprintf(fp, "fdiv\n");
                        }         
                    }
    | Term '%' Factor { if(strcmp($1, "int32") !=0 || strcmp($3, "int32") !=0 ){
                            if(strcmp($1, "int32") !=0){
                                fprintf(fp, "error:%d: invalid operation: (operator REM not defined on %s)\n", lineno+1, $1);
                                HAS_ERROR = 1;
                            }
                            else{
                                fprintf(fp, "error:%d: invalid operation: (operator REM not defined on %s)\n", lineno+1, $3);
                                HAS_ERROR = 1;
                            }
                            fprintf(fp, "REM\n");
                        }
                        else
                            fprintf(fp, "irem\n");
                    }
    | Factor { $$ = $1; }
    | ConversionExpr { $$ = $1; }
;

Factor
    : Operand { $$ = $1; }
    | Identifier '[' Expression ']' {   $$ = $1;
                                        if(strcmp($1, "int32") == 0)
                                            fprintf(fp, "iaload\n");
                                        else
                                            fprintf(fp, "faload\n");
                                    }
    | TRUE { fprintf(fp, "iconst_1\n"); $$ = "bool"; }
    | FALSE { fprintf(fp, "iconst_0\n"); $$ = "bool"; }
    | UnaryExpr { $$ = $1; }
;

UnaryExpr
    : '+' Factor { $$ = $2; }
    | '-' Factor {  if(strcmp($2, "int32") == 0)
                        fprintf(fp, "ineg\n");
                    else
                        fprintf(fp, "fneg\n"); 
                    $$ = $2; 
                }
    | '!' Factor {  fprintf(fp, "iconst_1\nixor\n"); 
                    $$ = $2; 
                }
;


%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    scope = 0;
    scope_com = 0;
    address = 0;
    current = NULL;
    current_head = NULL;
    create_symbol();
    fp = fopen("hw3.j", "w");
    fprintf(fp, ".source hw3.j\n.class public Main\n.super java/lang/Object\n.method public static main([Ljava/lang/String;)V\n.limit stack 100\n.limit locals 100 ;\n");

    yyparse();
    
    fprintf(fp, "return\n.end method\n");
    fclose(fp);
	//printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    if (HAS_ERROR) {
        remove("hw3.j");
    }
    return 0;
}

static void create_symbol() {
    struct table *new = malloc(sizeof(*new));
    new->prev_head = current_head;
    new->prev = current;    
    new->index = 0;
    new->name = NULL;
    new->type = NULL;
    new->scope_level = scope;
    current_head = new; 
    current = new;
    return;
}

static void insert_symbol(char* id, int kind) {
    //printf("insert %s, scope: %d, scope_com: %d\n", id, scope, scope_com);
    //printf("current_head: %s, id %s\n", current_head->name, id);
    char* ptr = strtok(id, " ");
    int insert = 1;
    // some variable is in table, search repeat declaration or not
    if(current_head->name != NULL){
        struct table *tmp = current_head;
        while(tmp != NULL){
            if(strcmp(tmp->name, id) == 0){
                insert = 0;
                fprintf(fp, "error:%d: %s redeclared in this block. previous declaration at line %d\n", lineno+1, id, tmp->lineno);
                HAS_ERROR = 1;
                break;
            }
            else{
                tmp = tmp->next;
            }
        }
    }


    if(insert){
        struct table *new;
        if(current->name == NULL){ // first variable in table
            new = current;
            new->next = NULL;
        }
        else{ // not the first variable in the table
            new = malloc(sizeof(*new));
            current->next = new;
            new->index = current->index +1;
        }
        new->address = address;
        address++;
        new->lineno = lineno+1;    
        new->name = ptr;
        // split input data
        if(kind == 1){
            ptr = strtok(NULL, "\n");
            new->type = ptr;
            new->element_type = "-";
        }
        else if(kind == 2){
            ptr = strtok(NULL, " ");
            new->type = ptr;
            new->element_type = "-";
        }
        else if(kind == 3){
            ptr = strtok(NULL, "\]");
            ptr = strtok(NULL, "\n");   
            new->type = "array";
            new->element_type = ptr;   
        }
        current = new;
        if(strcmp(current->type, "float32") == 0)
            fprintf(fp, "fstore %d\n", current->address);
        else if(strcmp(current->type, "string") == 0 || strcmp(current->element_type, "string") == 0)
            fprintf(fp, "astore %d\n", current->address);
        else if(strcmp(current->type, "array") == 0){
            if(strcmp(current->element_type, "float32") == 0)
                fprintf(fp, "newarray float\n");
            else
                fprintf(fp, "newarray int\n");
            fprintf(fp, "astore %d\n", current->address);
        }
        else
            fprintf(fp, "istore %d\n", current->address);
    }
    return;
}

static char* lookup_symbol(char* id) {
    char* ptr = strtok(id, "\[");
    ptr = strtok(id, " ");
    //printf("id :%s\n", id);
    struct table *search = current_head;
    struct table *search_head = current_head;
    int error = 1;
    char *type;
    while(search != NULL){
        if(strcmp(search->name, id) == 0){
            if(strcmp(search->type, "int32") == 0)
                fprintf(fp, "iload %d\n", search->address);
            else if(strcmp(search->type, "float32") == 0)
                fprintf(fp, "fload %d\n", search->address);
            else if(strcmp(search->type, "string") == 0)
                fprintf(fp, "aload %d\n", search->address);
            else if(strcmp(search->type, "array") == 0){
                fprintf(fp, "aload %d\n", search->address);
            }
            else{
                fprintf(fp, "iload %d\n", search->address);
                fprintf(fp, "ifne L_cmp_%d\nldc \"false\"\ngoto L_cmp_%d\nL_cmp_%d:\n ldc \"true\"\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                compare += 2;
            }
            type = search->type;
            if(strcmp(type, "array") == 0){
                type = search->element_type;
                type = strtok(type, "\n");
                search->element_type = type;
            }
            search = NULL;
            error = 0;
        }
        else{
            search = search->next; 
            if(search == NULL && search_head->prev_head != NULL){
                search_head = search_head->prev_head;
                search = search_head;
            }           
        }
    }
    if(error){
        fprintf(fp, "error:%d: undefined: %s\n", lineno+1, id);
        HAS_ERROR = 1;
    }
    
    if(strlen(type) > 8){
        type = strtok(type, "_");
    }

    return type;
}

static void dump_symbol() {
    /*printf("> Dump symbol table (scope level: %d)\n", scope_com); 

    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");*/
    //printf("current: %d , scope_com %d\n", current_head->scope_level, scope_com);
    if(scope_com == current_head->scope_level){
        struct table *tmp = current_head;
        current = current_head->prev;
        current_head = current_head->prev_head;

        //printf("current: %s, pre: %s\n", tmp->name, current_head->name);
        while(tmp != NULL && tmp->name != NULL){
            /*printf("%-10d%-10s%-10s%-10d%-10d%s\n",
                tmp->index, tmp->name, tmp->type, tmp->address, tmp->lineno, tmp->element_type);*/
            struct table *delete = tmp;
            tmp = tmp->next;
            free(delete);
        }
    }
    scope_com--;
    return;
}


static void store_symbol(char* id){
    struct table *search = current_head;
    struct table *search_head = current_head;
    while(search != NULL){
        if(strcmp(search->name, id) == 0){
            if(strcmp(search->type, "int32") == 0)
                fprintf(fp, "istore %d\n", search->address);
            else if(strcmp(search->type, "float32") == 0)
                fprintf(fp, "fstore %d\n", search->address);
            else if(strcmp(search->type, "array") == 0)
                fprintf(fp, "iastore\n");
            else
                fprintf(fp, "astore %d\n", search->address);
            search = NULL;
        }
        else{
            search = search->next;
            if(search == NULL && search_head->prev_head != NULL){
                search_head = search_head->prev_head;
                search = search_head;
            }  
        }
    }
    return;
}

static char* lookup_assign_symbol(char* id) {
    char* ptr = strtok(id, "\[");
    ptr = strtok(id, " ");
    struct table *search = current_head;
    struct table *search_head = current_head;
    int error = 1;
    char *type;
    while(search != NULL){
        if(strcmp(search->name, id) == 0){
            type = search->type;
            if(strcmp(type, "array") == 0){
                type = search->element_type;
                type = strtok(type, "\n");
                search->element_type = type;
            }
            search = NULL;
            error = 0;
        }
        else{
            search = search->next; 
            if(search == NULL && search_head->prev_head != NULL){
                search_head = search_head->prev_head;
                search = search_head;
            }           
        }
    }
    if(error){
        fprintf(fp, "error:%d: undefined: %s\n", lineno+1, id);
        HAS_ERROR = 1;
    }
    
    if(strlen(type) > 8){
        type = strtok(type, "_");
    }

    return type;
}