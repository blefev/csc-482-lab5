// Lab 5 CXX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <array>
#define ARRAY_SIZE 93
#define matrixVec vector<vector<uint64_t> >

#pragma once;

using namespace std;

uint64_t FibLoop(size_t);
uint64_t FibRecur(uint64_t);
uint64_t FibRecurDP(size_t);
uint64_t FibRecurDPWorker(size_t, vector<uint64_t> &xs);
uint64_t FibMatrix(uint64_t);
matrixVec MatrixPower(matrixVec, int);
matrixVec MatrixMultiplication(matrixVec A, matrixVec B);
void printMatrix(matrixVec v);