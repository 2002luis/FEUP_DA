// By: Gonçalo Leão

#ifndef DA_TP4_CLASSES_EXERCISES_H
#define DA_TP4_CLASSES_EXERCISES_H

#include <vector>
#include <string>

// Ex 1
int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j);

// Ex 2
std::vector<int> mysteryFunc(const std::vector<int> &A);

// Ex 3
std::string hanoiDC(unsigned int n, char src, char dest);

// Ex 4
std::vector<std::vector<double>> strassen(const std::vector<std::vector<double>> &X, const std::vector<std::vector<double>> &Y);

// Ex 5
double bisection(double x1, double x2, double err, double(*f)(double));

// Ex 6
#include "../running_examples/closest_point_pair/ClosestPointPair.h"

void setNumThreads(int num);

// Divide-and-conquer with a single thread
Result nearestPointsDC(std::vector<Point> &vp);
// Divide-and-conquer with multiple threads (number of threads is set using setNumThreads).
Result nearestPointsDC_MT(std::vector<Point> &vp);

#endif //DA_TP4_CLASSES_EXERCISES_H
