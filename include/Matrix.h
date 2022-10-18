#ifndef PEA_1_MATRIX_H
#define PEA_1_MATRIX_H

class Matrix {

public:
    Matrix(int** vertices, int numberOfVertices);

    ~Matrix();

    int** vertices;
    int numberOfVertices;
};


#endif //PEA_1_MATRIX_H