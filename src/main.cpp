#include <iostream>
#include <string>
#include "env.h"
#include "lexer.h"
using namespace std;

string parseInput(string input)
{

    Lexer l;
    l.parseRationalVar(input);


    return input;

}

int main(int argc, char **argv)
{

    if (argc > 0) {
        if (argv[1] == "file") {

            cout << "Select *.mi file" << endl;

        } else {

            string input = "";
            string output = "";

            while (input != "exit") {
                cout << "> ";

                getline(cin, input);

                output = parseInput(input);

                cout << output;
                cout << endl;
            }

        }


    }

}
