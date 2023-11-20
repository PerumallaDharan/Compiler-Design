#include "LexAnalyse.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <string>
#include <ctype.h>

using namespace std;

// Initialize the reserved word dictionary
void initKeyMap()
{
    keyMap.clear();
    keyMap["main"] = MAIN;
    keyMap["int"] = INT;
    keyMap["float"] = FLOAT;
    keyMap["char"] = CHAR;
    keyMap["return"] = RETURN;
    keyMap["if"] = IF;
    keyMap["else"] = ELSE;
    keyMap["for"] = FOR;
    keyMap["while"] = WHILE;
    keyMap["string"] = STRING;
}

// Initialize the operator dictionary
void initOperMap()
{
    operMap.clear();
    operMap["+"] = ADD;
    operMap["-"] = SUB;
    operMap["*"] = MUL;
    operMap["/"] = DIV;
    operMap["%"] = DIVMOD;
    operMap[">"] = GRT_THAN;
    operMap[">="] = GRT_EQUAL;
    operMap["<"] = LESS_THAN;
    operMap["<="] = LESS_EQUAL;
    operMap["!="] = NOT_EQUAL;
    operMap["=="] = EQUAL;
    operMap["="] = ASSIGN;
}

// Initialize the delimiter dictionary
void initLimitMap()
{
    limitMap["{"] = LEFT_BOUNDER;
    limitMap["}"] = RIGHT_BOUNDER;
    limitMap["("] = LEFT_BRACKET;
    limitMap[")"] = RIGHT_BRACKET;
    limitMap[";"] = SEMICOLON;
}

// Initialize the nodes
void initNode()
{
    normalHead = new NormalNode();
    normalHead->content = "";
    normalHead->describe = "";
    normalHead->type = -1;
    normalHead->iden_type = "";
    normalHead->line = -1;
    normalHead->next = NULL;

    errorHead = new ErrorNode();
    errorHead->content = "";
    errorHead->describe = "";
    errorHead->line = -1;
    errorHead->next = NULL;

    cout << "Initialization of word nodes and error nodes completed" << endl;
}

// Insert a node
void createNewNode(string content, string describe, int type, int line)
{
    NormalNode *p = normalHead;
    NormalNode *temp = new NormalNode();

    while (p->next)
    {
        p = p->next;
    }

    temp->content = content;
    temp->describe = describe;
    temp->type = type;
    temp->iden_type = "";
    temp->line = line;
    temp->next = NULL;

    p->next = temp;
}

// Insert an error node
void createNewError(string content, string describe, int type, int line)
{
    ErrorNode *p = errorHead;
    ErrorNode *temp = new ErrorNode();

    temp->content = content;
    temp->describe = describe;
    temp->type = type;
    temp->line = line;
    temp->next = NULL;
    while (p->next)
    {
        p = p->next;
    }
    p->next = temp;
}

// Print node information
void printNodeLink()
{
    cout << "*****************************Analysis Table******************************" << endl
         << endl;
    cout << setw(15) << "Content"
         << setw(15) << "Description"
         << "\t"
         << setw(3) << "Type Code"
         << "\t"
         //<< setw(8) << "Identifier Type"
         //<< "\t"
         << "Line Number" << endl;
    NormalNode *p = normalHead;
    p = p->next;
    while (p)
    {
        cout << setw(15) << p->content
             << setw(15) << p->describe << "\t"
             << setw(3) << p->type << "\t"
             << setw(8) << p->iden_type << "\t"
             << p->line << endl;

        p = p->next;
    }
    cout << endl;
}

// Export node information
void outputNodeLink()
{
    ofstream fout("words.txt");
    if (!fout)
    {
        cout << "Failed to open words.txt!" << endl;
        return;
    }
    fout << "*****************************Analysis Table******************************" << endl
         << endl;
    fout << "Content"
         << "\t"
         << setw(10) << "Description"
         << "\t"
         << setw(3) << "Type Code"
         << "\t"
         << setw(8) << "Identifier Type"
         << "\t"
         << "Line Number" << endl;
    NormalNode *p = normalHead;
    p = p->next;
    while (p)
    {
        fout << p->content << "\t"
             << setw(10) << p->describe << "\t"
             << setw(3) << p->type << "\t"
             << setw(8) << p->iden_type << "\t\t"
             << p->line << endl;

        p = p->next;
    }
    fout << endl;

    cout << "Update of words.txt completed!" << endl;
    fout.close();
}

// Print error node information
void printErrorLink()
{
    cout << "*****************************Error Table******************************" << endl
         << endl;
    cout << setw(15) << "Content" << setw(15) << "Description"
         << "\t"
         << "Type"
         << "\t"
         << "Line Number" << endl;
    ErrorNode *p = errorHead;
    p = p->next;
    while (p)
    {
        cout << setw(15) << p->content << setw(15) << p->describe << "\t" << p->type << "\t" << p->line << endl;
        p = p->next;
    }
    cout << endl
         << endl;
}

// Word scanning
void scanner()
{
    string filename;
    string word;
    int i;
    int line = 1; // Line number

    fstream fin("test.txt", ios::in);
    if (!fin)
    {
        cout << "Failed to open the file!" << endl;
        return;
    }
    else
    {
        cout << "File opened successfully!" << endl;
    }

    char ch;
    char x;
    fin.get(ch);
    while (!fin.eof() && ch != '$')
    {
        // i = 0;
        // cout<<word<<endl;
        word.clear();
        if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'))
            word += x;
        // x='\0';
        // Starts with a letter, processing keywords or identifiers
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            while ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            {

                word += tolower(ch);
                fin.get(ch);
            }

            // If it is a reserved word

            map<string, int>::iterator it = keyMap.find(word);
            if (it != keyMap.end())
            {
                createNewNode(word, KEY_DESC, it->second, line);
            }
            // If it is an identifier
            else
            {
                // int addr_tmp = createNewIden(word, IDENTIFIER_DESC, IDENTIFIER, -1, line);
                createNewNode(word, IDENTIFIER_DESC, IDENTIFIER, line);
            }
        }
        // Starts with a number
        else if (ch >= '0' && ch <= '9')
        {
            while (ch >= '0' && ch <= '9')
            {
                word += ch;
                fin.get(ch);
            }
            createNewNode(word, CONSTANT_DESC, CONST, line);
            // fin.seekg(-1, ios::cur);
        }
        else if (ch == '+')
        {
            createNewNode("+", OPE_DESC, ADD, line);
            fin.get(ch);
        }
        else if (ch == '-')
        {
            createNewNode("-", OPE_DESC, SUB, line);
            fin.get(ch);
        }
        else if (ch == '*')
        {
            createNewNode("*", OPE_DESC, MUL, line);
            fin.get(ch);
        }
        else if (ch == '/')
        {
            createNewNode("/", OPE_DESC, DIV, line);
            fin.get(ch);
        }
        else if (ch == '%')
        {
            createNewNode("%", OPE_DESC, DIVMOD, line);
            fin.get(ch);
        }
        else if (ch == '<')
        {
            fin.get(ch);
            if (ch == '=')
            {
                createNewNode("<=", OPE_DESC, LESS_EQUAL, line);
            }
            else
            {
                //  x=ch;
                createNewNode("<", OPE_DESC, LESS_THAN, line);
                // fin.seekg(-1, ios::cur);
            }
        }
        else if (ch == '>')
        {
            fin.get(ch);
            if (ch == '=')
            {
                createNewNode(">=", OPE_DESC, GRT_EQUAL, line);
            }
            else
            {
                //  x=ch;
                createNewNode(">", OPE_DESC, GRT_THAN, line);
                // fin.seekg(-1, ios::cur);
            }
        }
        else if (ch == '!')
        {
            fin.get(ch);

            if (ch == '=')
            {
                createNewNode("!=", OPE_DESC, NOT_EQUAL, line);
            }
            else
            {
                //  x=ch;
                createNewError("!", EXCLAMATION_ERROR, EXCLAMATION_ERROR_NUM, line);
                // fin.seekg(-1, ios::cur);
            }
        }
        else if (ch == '=')
        {
            fin.get(ch);

            if (ch == '=')
            {
                createNewNode("==", OPE_DESC, EQUAL, line);
            }
            else
            {
                // x=ch;
                createNewNode("=", OPE_DESC, ASSIGN, line);
                // fin.seekg(-1, ios::cur);
            }
        }
        else if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n')
        {
            if (ch == '\n')
            {
                line++;
            }
            fin.get(ch);
        }
        else if (ch == '(')
        {
            createNewNode("(", CLE_OPE_DESC, LEFT_BRACKET, line);
            fin.get(ch);
        }
        else if (ch == ')')
        {
            createNewNode(")", CLE_OPE_DESC, RIGHT_BRACKET, line);
            fin.get(ch);
        }
        else if (ch == '{')
        {
            createNewNode("{", CLE_OPE_DESC, LEFT_BOUNDER, line);
            fin.get(ch);
        }
        else if (ch == '}')
        {
            createNewNode("}", CLE_OPE_DESC, RIGHT_BOUNDER, line);
            fin.get(ch);
        }
        else if (ch == ';')
        {
            createNewNode(";", CLE_OPE_DESC, SEMICOLON, line);
            fin.get(ch);
        }
        else if (ch == '$')
        {
            createNewNode(";", CLE_OPE_DESC, DOLLAR, line);
            fin.get(ch);
        }
        else
        {
            word += ch;
            createNewError(word, SYMBOL_ERROR, SYMBOL_ERROR_NUM, line);
            fin.get(ch);
        }
    }
    if (ch == '$')
    {
        word.clear();
        word += ch;
        createNewNode(word, CLE_OPE_DESC, DOLLAR, line);
    }

    fin.close();
}

// Recycle node chain and error chain
void clear()
{
    while (normalHead)
    {
        NormalNode *next = normalHead->next;
        delete normalHead;
        normalHead = next;
    }
    while (errorHead)
    {
        ErrorNode *next = errorHead->next;
        delete errorHead;
        errorHead = next;
    }
}
