#include <bits/stdc++.h>
#include "include/Parser.h"
#include "include/Stopwatch.h"
#include "include/Path.h"
#include "include/Settings.h"

using namespace std;

Path travellingSalesmanProblem(int **graph, int vertexNumber) {
    vector<int> vertex;
    vector<int> path;
    int s = 0;
    path.push_back(s);
    for (int i = 0; i < vertexNumber; i++)
        if (i != s)
            vertex.push_back(i);

    int min_path = INT_MAX;
    do {

        int current_pathweight = 0;

        int k = s;
        for (int i: vertex) {
            current_pathweight += graph[k][i];
            k = i;
        }
        current_pathweight += graph[k][s];
        if (current_pathweight < min_path) {
            min_path = current_pathweight;
            path = vertex;
        }


    } while (
            next_permutation(vertex.begin(), vertex.end()));

    path.insert(path.begin(), s);
    Path pathy = Path(min_path, path);

    return pathy;
}

int main() {
    Settings settings = Settings("settings.ini");
    Parser parser;
    Stopwatch stopwatch;
    ofstream outputFile;
    outputFile.open(settings.outputFile);
    outputFile
            << "nazwa pliku wej ; ilość powtórzeń ; wartość optymalna ; wartość otrzymana ; ścieżka otrzymana; średni czas (ms) \n";

    for (TestCase testCase: settings.cases) {
        Matrix *matrix = parser.LoadFile(testCase.filename);
        long long allTime = 0;
        Path path;
        bool firstTime = true;
        for (int i = 0; i < testCase.repeats; i++) {
            stopwatch.start();
            Path salesman = travellingSalesmanProblem(matrix->vertices, matrix->numberOfVertices);
            stopwatch.stop();
            allTime += stopwatch.getTime();
            if (firstTime) {
                path.copyData(salesman);
                firstTime = false;
            }
        }
        outputFile << testCase.filename << " ;";
        outputFile << testCase.repeats << " ;";
        outputFile << testCase.optimalPath << " ;";
        outputFile << path.shortestPath << " ;";
        for (int i: path.path) {
            outputFile << i << " ";
        }
        outputFile << "0 ;";
        outputFile << allTime / testCase.repeats << " \n";
    }
    outputFile.close();
    return 0;
}