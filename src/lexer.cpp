#include "lexer.h"

Lexer::Lexer()
{


}

void Lexer::parseRationalVar(string lexem)
{
    enum states {START = 1, END = 0, ERROR = -1};
    int state = START;
    int index = 0;

    switch(state)
    {
    case ERROR:
        {
            return;
        } break;
    case 1:
        {
            if (lexem.at(index) == 'R') {
                state++;
                index++;
            } else {
                state = ERROR;
            }
        } break;
    case 2:
        {
            cout << lexem.at(index) << endl;

            while (isdigit(lexem.at(index)) != 0)
            {
                cout << index << endl;
                index++;
            }

            state++;
        } break;
    case 3:
        {
            if (lexem.at(index) == '=') {
                state++;
                index++;
            } else {
                state = ERROR;
            }

        } break;
    }

    cout << "State: " << state << " index: " << index << endl;
}

string Lexer::parseLexem(string input)
{
    if (!input.empty()) {
        if (input.at(0) == 'V') {
            //
        }

        if (input.at(0) == 'M') {
            //
        }

        if (input.at(0) == 'R') {
            parseRationalVar(input);
        }
    }
}

