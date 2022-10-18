#include <fstream>
#include <sstream>
#include "../include/Settings.h"

Settings::Settings(const string &iniFile) {
    ifstream file(iniFile);

    if (file.fail())
        return;

    vector<TestCase> casesT;
    string outputFileT, suffix = ".txt";
    bool readyExit = false;

    while (!readyExit) {
        string line;
        file >> line;
        if(file.peek() != EOF)
        {
            string inputFile = line;
            int repeats, optimalPath;
            file >> repeats >> optimalPath;
            casesT.emplace_back(inputFile, repeats, optimalPath);
        }
        else {
            outputFileT = line;
            readyExit = true;
        }
    }

    if (outputFileT.empty() || casesT.empty())
        return;

    cases = casesT;
    outputFile = outputFileT;
}