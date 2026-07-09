#include <iostream>
#include <string>
using namespace std;

int main() {
    string input = "cout << 20 + a * 60.5;";

    string keywords[] = {"cout", "cin", "int", "float", "char"};
    string word = "";

    for (int i = 0; i < input.length(); i++) {

        if ((input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= '0' && input[i] <= '9') ||
            input[i] == '.') {

            word += input[i];
        }
        else {

            if (word != "") {
                bool keyword = false;

                for (int j = 0; j < 5; j++) {
                    if (word == keywords[j]) {
                        cout << word << " -> Keyword" << endl;
                        keyword = true;
                        break;
                    }
                }

                if (!keyword) {
                    bool number = true;

                    for (int j = 0; j < word.length(); j++) {
                        if (!((word[j] >= '0' && word[j] <= '9') || word[j] == '.')) {
                            number = false;
                            break;
                        }
                    }

                    if (number)
                        cout << word << " -> Number" << endl;
                    else
                        cout << word << " -> Identifier" << endl;
                }

                word = "";
            }

            if (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
                input[i] == '/' || input[i] == '=' || input[i] == '<' ||
                input[i] == '>') {
                cout << input[i] << " -> Operator" << endl;
            }
            else if (input[i] == ';' || input[i] == ',' ||
                     input[i] == '(' || input[i] == ')' ||
                     input[i] == '{' || input[i] == '}') {
                cout << input[i] << " -> Punctuation" << endl;
            }
        }
    }

    return 0;
}
