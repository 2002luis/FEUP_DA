// Adapted from the Algorithm Design and Analysis Course (MIEIC), coordinated by Prof. Rosaldo Rossetti

#ifndef DA_TP_CLASSES_CLOSESTPOINTPAIR_H
#define DA_TP_CLASSES_CLOSESTPOINTPAIR_H

#include <ostream>
#include <vector>

struct Point {
    double x;
    double y;

    Point(double x, double y);
    Point(int x, int y);
    double distance(Point &p) const;
    double distSquare(Point &p) const; // distance squared
    bool operator==(const Point &p) const;
};
std::ostream& operator<<(std::ostream& os, Point &p);

// Auxiliary class to store a solution.
struct Result {
    double dmin; // distance between selected points
    Point p1, p2; // selected points
    Result(double dmin2, Point p1, Point p2);
    Result();
};

// Pointer to function that computes nearest points
typedef Result (*NP_FUNC)(std::vector<Point> &vp);

//// For the tests
#define REL_PATH "../running_examples/closest_point_pair/" // relative path to the tests

// Auxiliary function to read points from file to vector.
void readPoints(std::string in, std::vector<Point> &vp);

// Auxiliary functions to generate random sets of points.
void shuffle(std::vector<Point> &vp, int left, int right);

void shuffleY(std::vector<Point> &vp, int left, int right);

// Generates a vector of n distinct points with minimum distance 1.
void generateRandom(int n, std::vector<Point> &vp);

// Similar, but with constant X.
void generateRandomConstX(int n, std::vector<Point> &vp);

/**
 * Runs the given algorithm (func) for an input file (in)
 * and checks the expected result (res).
 * Prints result and performance information.
 */
int testNPFile(std::string in, double dmin, NP_FUNC func, std::string alg);

int testNPRand(int size, std::string name, double dmin, NP_FUNC func, std::string alg);

int testNPRandConstX(int size, std::string name, double dmin, NP_FUNC func, std::string alg);

/**
 * Runs the given algorithm for the existent data files.
 */
void testNearestPoints(NP_FUNC func, std::string alg);

#endif //DA_TP_CLASSES_CLOSESTPOINTPAIR_H
