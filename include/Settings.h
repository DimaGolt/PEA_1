#ifndef PEA_1_SETTINGS_H
#define PEA_1_SETTINGS_H
#include <utility>
#include <vector>
#include <string>

using namespace std;


struct TestCase {
    string filename;
    int repeats;
    int optimalPath;

    TestCase(string filename, int repeats, int optimalPath) : filename(std::move(filename)), repeats(repeats), optimalPath(optimalPath) {};
};

class Settings {
public:
    explicit Settings(const string& iniFile);

    vector<TestCase> cases;
    string outputFile;
};


#endif //PEA_1_SETTINGS_H
