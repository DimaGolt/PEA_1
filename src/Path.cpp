#include <utility>

#include "../include/Path.h"

Path::Path(int shortestPath, vector<int> path) : shortestPath(shortestPath), path(std::move(path)) {}

Path::~Path() = default;
