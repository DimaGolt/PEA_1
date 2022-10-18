#include <utility>

#include "../include/Path.h"

Path::Path(int shortestPath, vector<int> path) : shortestPath(shortestPath), path(std::move(path)) {}

Path::Path() = default;

Path::~Path() = default;

void Path::copyData(Path pathFrom) {
    shortestPath = pathFrom.shortestPath;
    path = pathFrom.path;
}