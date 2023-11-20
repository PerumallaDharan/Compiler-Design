#pragma once
#include <string>
#include <map>

using namespace std;

// Reserved Words
#define MAIN 0   // main
#define INT 1    // int
#define FLOAT 2  // float
#define RETURN 3 // return
#define CHAR 4   // char
#define STRING 5 // string
#define IF 6     // if
#define ELSE 7   // else
#define FOR 8    // for
#define WHILE 9  // while
#define KEY_DESC "Reserved Word"
// Identifier
#define IDENTIFIER 10
#define IDENTIFIER_DESC "Identifier"

// Operators
#define ADD 11        // +
#define SUB 12        // -
#define MUL 13        // *
#define DIV 14        // /
#define DIVMOD 14     // %
#define EQUAL 15      // ==
#define LESS_THAN 16  // <
#define LESS_EQUAL 17 // <=
#define GRT_THAN 18   // >
#define GRT_EQUAL 19  // >=
#define NOT_EQUAL 20  // !=
#define ASSIGN 21     // =
#define OPE_DESC "Operator"

// Delimiters
#define LEFT_BRACKET 22  // (
#define RIGHT_BRACKET 23 // )
#define LEFT_BOUNDER 24  // {
#define RIGHT_BOUNDER 25 // }
#define SEMICOLON 26     // ;
#define DOLLAR 27        // $
#define CLE_OPE_DESC "Delimiter"

// Constants
#define CONST 28 // Unsigned integer constants
#define CONSTANT_DESC "Constant"

// Error Types
#define INT_ERROR "Not an integer constant"
#define INT_ERROR_NUM 1
#define EXCLAMATION_ERROR "Invalid '!' symbol"
#define EXCLAMATION_ERROR_NUM 2
#define SYMBOL_ERROR "Special symbol"
#define SYMBOL_ERROR_NUM 3
#define LEFT_BRACKET_ERROR "Unmatched '('"
#define LEFT_BRACKET_ERROR_NUM 4
#define RIGHT_BRACKET_ERROR "Unmatched ')'"
#define RIGHT_BRACKET_ERROR_NUM 5
#define LEFT_BOUNDER_ERROR "Unmatched '{'"
#define LEFT_BOUNDER_ERROR_NUM 6
#define RIGHT_BOUNDER_ERROR "Unmatched '}'"
#define RIGHT_BOUNDER_ERROR_NUM 7
#define END_ERROR "Does not end with $"
#define END_ERROR_NUM 8

#define _NULL "null"

map<string, int> keyMap;
map<string, int> operMap;
map<string, int> limitMap;

// Reserved Word | Identifier | Operator | Constant
struct NormalNode
{
    string content;   // Content
    string describe;  // Describe whether it is a reserved word or identifier
    int type;         // Type code
    string iden_type; // Identifier type
    int line;         // Line number
    NormalNode *next; // Next node
} *normalHead;        // Head node

// Error Node
struct ErrorNode
{
    string content;  // Error content
    string describe; // Error description
    int type;
    int line;        // Line number
    ErrorNode *next; // Next node
} *errorHead;        // Head node

void initKeyMap();                                                                 // Initialize the reserved word dictionary
void initOperMap();                                                                // Initialize the operator dictionary
void initLimitMap();                                                               // Initialize the delimiter dictionary
void initNode();                                                                   // Initialize nodes
void createNewNode(string content, string describe, int type, int addr, int line); // Insert a node
void createNewError(string content, string describe, int type, int line);          // Insert an error node
void scanner();                                                                    // Word scanning
void printNodeLink();                                                              // Print node information
void outputNodeLink();                                                             // Export node information
void printErrorLink();                                                             // Print error node information
void clear();                                                                      // Recycle node chain and error chain
