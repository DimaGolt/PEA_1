#ifndef PEA_1_PATH_H
#define PEA_1_PATH_H
#include <vector>

using namespace std;

class Path {

public:
    Path(int shortestPath, vector<int> path);
    ~Path();

    int shortestPath;
    vector<int> path;
};


#endif //PEA_1_PATH_H