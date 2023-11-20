#include "LexAnalyse.cpp"
#include "SynAnalyse.cpp"
#include <cstring>

int main()
{
    // Lexical Analysis Section
    initKeyMap();
    initOperMap();
    initLimitMap();
    initNode();

    cout << "Lexical Analysis Results: " << endl;
    scanner();

    printNodeLink();
    outputNodeLink();
    printErrorLink(); // error table not working , fix if possible

    clear();
    return 0;
}
