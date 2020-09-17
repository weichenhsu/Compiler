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
%type <s_val> ConversionExpr Comparison IdentifierStmt

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
    : '{' StatementList '}' {  if(scope == scope_com){
                                scope_com++;
                            }
                                dump_symbol(); }
;

Operand
    : Literal { $$ = $1; }
    | Identifier { $$ = $1; }
    | '(' Expression ')' { $$ = $2; }
;

Literal
    : INT_LIT   {   $$ = "int32";
                    printf("INT_LIT %d\n", yylval.i_val); 
                }
    | FLOAT_LIT {   $$ = "float32";
                    printf("FLOAT_LIT %-6f\n", yylval.f_val); 
                }
    | BOOL_LIT
    | '"' STRING_LIT '"'    {   $$ = "string";
                                printf("STRING_LIT %s\n", yylval.s_val); 
                            }
;

ConversionExpr
    : INT '(' Factor ')' { printf("F to I\n"); $$ = "int32"; }
    | FLOAT '(' Factor ')' { printf("I to F\n"); $$ = "float32"; }
;

TypeName
    : INT
    | FLOAT
    | STRING
    | BOOL
;

ArrayType
    : '[' Literal ']' 
;

DeclarationStmt
    : VAR IDENT TypeName { if(scope != scope_com){
                            scope_com = scope;
                            create_symbol();
                        }
                        insert_symbol($2, 1); }
    | VAR IDENT TypeName '=' Factor { if(scope != scope_com){
                                        scope_com = scope;
                                        create_symbol();
                                        }
                                        insert_symbol($2, 2); }    
    | VAR IDENT ArrayType TypeName { if(scope != scope_com){
                                        scope_com = scope;
                                        create_symbol();
                                        }
                                        insert_symbol($2, 3);
                                    }                 
;

Identifier
    : IDENT { $$ = lookup_symbol(yylval); }
;

SimpleStmt
    : AssignmentStmt
    | IncDecStmt
    | LogiLOR
    | ErrorStmt
;

AssignmentStmt
    : IdentifierStmt '=' Expression { if($1 != NULL && $3 != NULL)
                                            if(strcmp($1, $3) != 0)
                                                printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                        printf("ASSIGN\n"); 
                                    }
    | IdentifierStmt ADD_ASSIGN Expression { if($1 != NULL && $3 != NULL)
                                                    if(strcmp($1, $3) != 0)
                                                        printf("error:%d: invalid operation: ADD_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                                printf("ADD_ASSIGN\n"); 
                                            }
    | IdentifierStmt SUB_ASSIGN Expression { if($1 != NULL && $3 != NULL)
                                                    if(strcmp($1, $3) != 0)
                                                        printf("error:%d: invalid operation: SUB_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                                printf("SUB_ASSIGN\n"); 
                                            }
    | IdentifierStmt MUL_ASSIGN Expression { if($1 != NULL && $3 != NULL)
                                                    if(strcmp($1, $3) != 0)
                                                        printf("error:%d: invalid operation: MUL_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                                printf("MUL_ASSIGN\n"); 
                                            }
    | IdentifierStmt QUO_ASSIGN Expression { if($1 != NULL && $3 != NULL)
                                                    if(strcmp($1, $3) != 0)
                                                        printf("error:%d: invalid operation: QUO_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                                printf("QUO_ASSIGN\n"); 
                                            }
    | IdentifierStmt REM_ASSIGN Expression { if($1 != NULL && $3 != NULL)
                                                    if(strcmp($1, $3) != 0)
                                                        printf("error:%d: invalid operation: REM_ASSIGN (mismatched types %s and %s)\n", lineno+1, $1, $3);
                                                printf("REM_ASSIGN\n"); 
                                            }
;

IdentifierStmt
    : Identifier { $$ = $1; }
    | Identifier ArrayType { $$ = $1; }
;

IncDecStmt
    : Factor INC { printf("INC\n"); }
    | Factor DEC { printf("DEC\n"); }
;

ErrorStmt
    : Literal '=' Expression { printf("error:%d: cannot assign to %s\nASSIGN\n", lineno+1, $1); }
    | Literal ADD_ASSIGN Expression { printf("error:%d: cannot assign to %s\nADD_ASSIGN\n", lineno+1, $1); }
    | Literal SUB_ASSIGN Expression { printf("error:%d: cannot assign to %s\nSUB_ASSIGN\n", lineno+1, $1); }
    | Literal MUL_ASSIGN Expression { printf("error:%d: cannot assign to %s\nMUL_ASSIGN\n", lineno+1, $1); }
    | Literal QUO_ASSIGN Expression { printf("error:%d: cannot assign to %s\nQUO_ASSIGN\n", lineno+1, $1); }
    | Literal REM_ASSIGN Expression { printf("error:%d: cannot assign to %s\nREM_ASSIGN\n", lineno+1, $1); }
;

IfStmt
    : IF Comparison { if(strcmp($2, "bool") != 0){
                            printf("error:%d: non-bool (type %s) used as for condition\n", lineno+1, $2);
                        }
                    }
    | ELSE IfStmt
    | ELSE Block 
;

ForStmt
    : FOR Comparison { if(strcmp($2, "bool") != 0){
                            printf("error:%d: non-bool (type %s) used as for condition\n", lineno+1, $2);
                        }
                    }
    | FOR SimpleStmt ';' Comparison ';' SimpleStmt { if(strcmp($4, "bool") != 0){
                                                            printf("error:%d: non-bool (type %s) used as for condition\n", lineno+1, $4);
                                                        }
                                                    }
;

PrintStmt
    : PRINT '(' LogiLOR ')' { printf("PRINT %s\n", $3); }
    | PRINTLN '(' LogiLOR ')' { printf("PRINTLN %s\n", $3); }
;

LogiLOR
    : LogiLOR LOR LogiLAND { if(strcmp($1, "bool") != 0 || strcmp($3, "bool") != 0){
                                if(strcmp($1, "bool") != 0)
                                    printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", lineno+1, $1);
                                else   
                                    printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", lineno+1, $3);
                            }
                            $$ = "bool"; printf("LOR\n"); }
    | LogiLAND { $$ = $1; }
;

LogiLAND
    : LogiLAND LAND Comparison { if(strcmp($1, "bool") != 0 || strcmp($3, "bool") != 0){
                                    if(strcmp($1, "bool") != 0)
                                        printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", lineno+1, $1);
                                    else   
                                        printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", lineno+1, $3);
                                }
                                    $$ = "bool"; printf("LAND\n"); }
    | Comparison { $$ = $1; }
;

Comparison
    : Comparison GTR Expression { $$ = "bool"; printf("GTR\n"); }
    | Comparison LSS Expression { $$ = "bool"; printf("LSS\n"); }
    | Comparison GEQ Expression { $$ = "bool"; printf("GEQ\n"); }
    | Comparison LEQ Expression { $$ = "bool"; printf("LEQ\n"); }
    | Comparison EQL Expression { $$ = "bool"; printf("EQL\n"); }
    | Comparison NEQ Expression { $$ = "bool"; printf("NEQ\n"); }
    | Expression { $$ = $1; }
;

Expression
    : Expression '+' Term { if(strcmp($1, $3) != 0)
                                printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", lineno+1, $1, $3);
                            printf("ADD\n"); 
                        }
    | Expression '-' Term { if(strcmp($1, $3) != 0)
                                printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", lineno+1, $1, $3);
                            printf("SUB\n"); 
                        }
    | Term { $$ = $1; }
;

Term
    : Term '*' Factor { printf("MUL\n"); }
    | Term '/' Factor { printf("QUO\n"); }
    | Term '%' Factor { if(strcmp($1, "int32") !=0 || strcmp($3, "int32") !=0 ){
                            if(strcmp($1, "int32") !=0)
                                printf("error:%d: invalid operation: (operator REM not defined on %s)\n", lineno+1, $1);
                            else
                                printf("error:%d: invalid operation: (operator REM not defined on %s)\n", lineno+1, $3);
                        }
                        printf("REM\n"); }
    | ConversionExpr { $$ = $1; }
    | Factor { $$ = $1; }
;

Factor
    : Operand { $$ = $1; }
    | Identifier '[' Expression ']' { $$ = $1; }
    | TRUE { printf("TRUE\n"); $$ = "bool"; }
    | FALSE { printf("FALSE\n"); $$ = "bool"; }
    | UnaryExpr { $$ = $1; }
;

UnaryExpr
    : '+' Factor { printf("POS\n"); $$ = $2; }
    | '-' Factor { printf("NEG\n"); $$ = $2; }
    | '!' Factor { printf("NOT\n"); $$ = $2; }
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

    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
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
    char* ptr = strtok(id, " ");
    int insert = 1;
    if(current_head->name != NULL){
        struct table *tmp = current_head;
        while(tmp != NULL){
            if(strcmp(tmp->name, id) == 0){
                insert = 0;
                printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", lineno+1, id, tmp->lineno);
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
        printf("> Insert {%s} into symbol table (scope level: %d)\n", current->name, scope);
    }
    return;
}

static char* lookup_symbol(char* id) {
    struct table *search = current_head;
    int error = 1;
    char *type;
    while(search != NULL){
        if(strcmp(search->name, id) == 0){
            printf("IDENT (name=%s, address=%d)\n", search->name, search->address);
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
        }
    }
    if(error){
        printf("error:%d: undefined: %s\n", lineno+1, id);
    }
    return type;
}

static void dump_symbol() {
    printf("> Dump symbol table (scope level: %d)\n", scope_com); 

    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
    if(scope_com == current_head->scope_level){
        struct table *tmp = current_head;
        current = current_head->prev;
        current_head = current_head->prev_head;
    
        while(tmp != NULL && tmp->name != NULL){
            printf("%-10d%-10s%-10s%-10d%-10d%s\n",
                tmp->index, tmp->name, tmp->type, tmp->address, tmp->lineno, tmp->element_type);
            struct table *delete = tmp;
            tmp = tmp->next;
            free(delete);
        }
    }
    scope_com--;
    return;
}
