#include "../include/Matrix.h"

Matrix::~Matrix() = default;

Matrix::Matrix(int **vertices, int numberOfVertices) : vertices(vertices), numberOfVertices(numberOfVertices) {}
