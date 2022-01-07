#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctype.h>

using namespace std;

string split(string line, int max) {
    int i = 0;
    int k = 0;
    string out = "";

    while (i < (int)line.size()) {
        string token = "";
        if (isalpha(line[i])) {
            do {
                token += line[i++];
            } while(isalpha(line[i]));
        } else {
            token += line[i++];
        }
        if (k == 0 || k + (int)token.size() <= max) out += token;
        else {
            k = 0;
            out += "\n";
            out += token;
        }
        k += token.size();
    }
    return out;
}

int main()
{
    ifstream fin;
    ofstream fon;
    string c;
    int max=10;
    fin.open("/Users/maksims.gudima/CLionProjects/untitled4/first.txt");
    fon.open("/Users/maksims.gudima/CLionProjects/untitled4/second.txt");
    getline(fin, c);
    while (fin)
    {
        fon << split(c,max)<< endl;
        getline(fin, c);
    };
    fin.close();
    fon << endl;
    fon.close();
    return 0;
}
