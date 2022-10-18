#include "../include/Parser.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Matrix * Parser::LoadFile(string &filename) {
    fstream File;
    File.open(filename, ios::in);
    if (!File.good()) {\
        cout << "\nNie mozna wczytac pliku!\n";
        return nullptr;
    }

    int numberOfVertices = 0;

    File >> numberOfVertices;
    int **vertices = new int *[numberOfVertices];
    int line = 0;

    for (int i = 0; i < numberOfVertices; i++)
        vertices[i] = new int[numberOfVertices];

    while (!File.eof()) {
        for (int i = 0; i < numberOfVertices; i++) {
            for (int j = 0; j < numberOfVertices; j++) {
                File >> vertices[i][j];
            }

            line++;
        }
    }
    File.close();

    if (line != numberOfVertices && line != numberOfVertices * 2) { // zabezpieczenie pir
        cout << "-> Zla ilosc danych <-\n";
        for (int i = 0; i < numberOfVertices; i++)
            delete vertices[i];
        delete[] vertices;
        vertices = nullptr;
        numberOfVertices = 0;
        return nullptr;
    }
    cout << "\nWczytano plik!\n";

    return new Matrix(vertices, numberOfVertices);
}