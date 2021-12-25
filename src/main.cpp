#include <iostream>
#include <string>
#include "env.h"
#include "lexer.h"
#include "parser.h"
#include <stdlib.h>
#include <exception>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
    Env env;
    Lexer l;
    Parser p;

    TokenList *lst;
    Node *st;

    vector<string> commands;

    if (argc > 0) {
        if (argc == 3) {
            string fileFlag = argv[1];
            string filename = argv[2];

            if (fileFlag == "-f" && !filename.empty()) {
                ifstream file(filename);
                string line;

                if (file.is_open()) {
                    while (getline(file, line)) {
                        commands.push_back(line);
                    }
                } else {
                    cerr << "File '" << filename << "' is not found" << endl;
                }

                file.close();

            }

            if (!commands.empty()) {
                for (auto line : commands) {
                    cout << "mi> " << line << endl;

                    lst = l.parse(line);

                    if (lst) {
                        std::reverse(lst->begin(), lst->end());

                        try
                        {
                            st = p.parse(lst);
                        } catch (string error) {
                            cerr << error;
                        }

                        env.exec(st);
                    }

                    cout << endl;
                }
            }

        } else {
            string input = "";
            string output = "";

            while (input != "exit") {
                cout << "mi> ";

                getline(cin, input);

                lst = l.parse(input);

                if (lst && !lst->empty()) {
                    std::reverse(lst->begin(), lst->end());

                    try
                    {
                        st = p.parse(lst);
                    } catch (string error) {
                        cerr << error;
                    }

                    env.exec(st);
                } else if (input != "exit") {
                    cerr << "Incorrect syntax" << endl;
                }

                cout << endl;
            }

        }
    }

    for (Token *t : *lst) {
        delete t;
    }
}
