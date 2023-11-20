#pragma once
#include "LexAnalyse.h"
#include <string>
#include <map>
#include <list>

using namespace std;

#define MAXT 100

// Identifier node
struct IdentifierNode
{
    string content;   // Content
    string describe;  // Description
    int type;         // Lexical code
    string iden_type; // Identifier type
    int line;         // Line number

    IdentifierNode() {}
    IdentifierNode(string c, string d, int t, string i, int l) : content(c), describe(d), type(t), iden_type(i), line(l) {}
};

// Identifier table
map<string, IdentifierNode> iden_map;

// Intermediate point
struct mid_type
{
    NormalNode *node; // If it is an identifier or constant, it points to the node
    int T_num;        // If it is an intermediate variable, it represents the intermediate variable number
    int isT;          // 1: Intermediate variable; 0: Token node (identifier/constant/operator); -1: error; 2: Empty

} error, null;

bool T[MAXT]; // Intermediate variable occupation

// Quadruple intermediate code node
struct CodeNode
{
    int line;
    string opt;
    string arg1, arg2;
    string result;
    CodeNode(int l, string o, string a1, string a2, string r) : line(l), opt(o), arg1(a1), arg2(a2), result(r) {}
};

// Quadruple intermediate code linked list
list<CodeNode> code;

string mid2string(mid_type m);     // Extract content from mid_type structure for gen() to generate quadruple intermediate code
void createNewIden(NormalNode *p); // Create a new identifier node
void printIdentLink();             // Output the identifier table
void outputIdenLink();             // Export the identifier table

/* The following are recursive subprograms for various non-terminals */
void program(NormalNode *&p);                              //<Program>
void main_fun(NormalNode *&p);                             //<main function>
void return_type(NormalNode *&p);                          //<Return type>
void var_type(NormalNode *&p);                             //<Variable type>
void struct_statement(NormalNode *&p);                     //<Compound statement>
void statements_list(NormalNode *&p);                      //<Statement sequence>
void statement(NormalNode *&p);                            //<Statement>
void statements_recursive(NormalNode *&p);                 //<Statement recursive>
void define_statement(NormalNode *&p);                     //<Definition statement>
mid_type assign_default(NormalNode *&p);                   //<Assign default value>
void assign_statement(NormalNode *&p);                     //<Assignment statement>
void condition_statement(NormalNode *&p);                  //<Conditional statement>
mid_type bool_expression(NormalNode *&p);                  //<Boolean expression>
mid_type expression(NormalNode *&p);                       //<Expression>
mid_type items_recursive(NormalNode *&p, mid_type front);  //<Item recursive>
mid_type item(NormalNode *&p);                             //<Item>
mid_type factor_recursive(NormalNode *&p, mid_type front); //<Factor recursive>
mid_type factor(NormalNode *&p);                           //<Factor>
mid_type relation_operator(NormalNode *&p);                //<Relational operator>
string _identifier(NormalNode *&p);                        //<Identifier>
void unsigned_const(NormalNode *&p);                       //<Unsigned constant>

mid_type newTemp();                                                 // Get a new intermediate variable Ti
void emit(mid_type m);                                              // Recycle intermediate variable Ti
CodeNode &gen(string opt, string arg1, string arg2, string result); // Generate quadruple intermediate code
void printCode();                                                   // Output quadruple intermediate code
void outputCode();                                                  // Export quadruple intermediate code
