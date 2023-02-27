// Adapted from the Algorithm Design and Analysis Course (MIEIC), coordinated by Prof. Rosaldo Rossetti

#include "ClosestPointPair.h"

#include <limits>

#include <iostream>
#include <fstream>
#include <sys/timeb.h>
#include <random>
#include <cstdlib>
#include "gtest/gtest.h"

const double MAX_DOUBLE = std::numeric_limits<double>::max();

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

double Point::distance(Point &p) const {
    return sqrt((x-p.x) * (x-p.x)  + (y-p.y) * (y-p.y));
}

double Point::distSquare(Point &p) const {
    return (x-p.x) * (x-p.x)  + (y-p.y) * (y-p.y);
}

bool Point::operator==(const Point &p) const {
    return (x == p.x && y == p.y);
}

std::ostream& operator<<(std::ostream& os, Point &p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

Result::Result(double dmin, Point p1, Point p2): dmin(dmin), p1(p1), p2(p2) {
}

Result::Result(): Result(MAX_DOUBLE, Point(0,0), Point(0,0)) {
}

//// For tests

void readPoints(std::string in, std::vector<Point> &vp) {
    std::ifstream is(REL_PATH + in);
    vp.clear();
    if (!is) {
        std::cerr << "Failed to read file " << in << "." << std::endl;
        return;
    }
    while (!is.eof()) {
        double x, y;
        is >> x >> y;
        Point p(x,y);
        vp.push_back(p);
    }
}

void shuffle(std::vector<Point> &vp, int left, int right) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, right - left +1);
    for (int i = left; i < right; i++){
        int k = i + dis(gen) % (right - i + 1);
        Point tmp = vp[i];
        vp[i] = vp[k];
        vp[k] = tmp;
    }
}

void shuffleY(std::vector<Point> &vp, int left, int right) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, right - left +1);
    for (int i = left; i < right; i++){
        int k = i + dis(gen) % (right - i + 1);
        double tmp = vp[i].y;
        vp[i].y = vp[k].y;
        vp[k].y = tmp;
    }
}

void generateRandom(int n, std::vector<Point> &vp) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, n-1);

    vp.clear();
    // reference value for reference points (r, r), (r, r+1)
    int r = dis(gen);
    vp.push_back(Point(r,r));
    vp.push_back(Point(r,r+1));
    for (int i = 2; i < n; i++)
        if (i < r)
            vp.push_back(Point(i, i));
        else
            vp.push_back(Point(i+1, i+2));
    shuffleY(vp, 2, n-1);
    shuffle(vp, 0, n-1);
}

void generateRandomConstX(int n, std::vector<Point> &vp) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, n-1);

    vp.clear();
    // reference value for min dist
    int r = dis(gen);
    int y = 0;
    for (int i = 0; i < n; i++) {
        vp.push_back(Point(0, y));
        if (i == r)
            y++;
        else
            y += 1 + dis(gen) % 100;
    }
    shuffleY(vp, 0, n-1);
}

/**
 * Auxiliary functions to obtain current time and time elapsed
 * in milliseconds.
 * Something like GetTickCount but portable.
 * It rolls over every ~ 12.1 days (0x100000/24/60/60)
 * Use GetMilliSpan to correct for rollover
 */
int GetMilliCount() {
    timeb tb;
    ftime( &tb );
    int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
    return nCount;
}

int GetMilliSpan(int nTimeStart) {
    int nSpan = GetMilliCount() - nTimeStart;
    if (nSpan < 0)
        nSpan += 0x100000 * 1000;
    return nSpan;
}

int testNP(std::string name, std::vector<Point> &points, double dmin, NP_FUNC func, std::string alg) {
    int nTimeStart = GetMilliCount();
    Result res = (func)(points);
    int nTimeElapsed = GetMilliSpan(nTimeStart);
    std::cout << alg << "; " << name << "; " << nTimeElapsed << "; ";
    std::cout.precision(17);
    std::cout << res.dmin << "; " << res.p1 << "; " << res.p2 << std::endl;
    EXPECT_NEAR(dmin, res.dmin, 0.01);
    return nTimeElapsed;
}

/**
 * Runs the given algorithm (func) for an input file (in)
 * and checks the expected result (res).
 * Prints result and performance information.
 */
int testNPFile(std::string in, double dmin, NP_FUNC func, std::string alg) {
    std::vector<Point> pontos;
    readPoints(in, pontos);
    return testNP(in, pontos, dmin, func, alg);
}

int testNPRand(int size, std::string name, double dmin, NP_FUNC func, std::string alg) {
    std::vector<Point> pontos;
    generateRandom(size, pontos);
    return testNP(name, pontos, dmin, func, alg);
}

int testNPRandConstX(int size, std::string name, double dmin, NP_FUNC func, std::string alg) {
    std::vector<Point> pontos;
    generateRandomConstX(size, pontos);
    return testNP(name, pontos, dmin, func, alg);
}

/**
 * Runs the given algorithm for the existent data files.
 */

void testNearestPoints(NP_FUNC func, std::string alg) {
    std::cout << "algorithm; data set; time elapsed (ms); distance; point1; point2" << std::endl;
    int maxTime = 10000;
    if ( testNPFile("Pontos8", 11841.3, func, alg) > maxTime)
        return;
    if ( testNPFile("Pontos64", 556.066, func, alg) > maxTime)
        return;
    if (testNPFile("Pontos1k", 100.603, func, alg) > maxTime)
        return;
    /*
    // Uncomment to use more tests
    if (testNPFile("Pontos16k", 13.0384, func, alg) > maxTime)
        return;
    if (testNPFile("Pontos32k", 1.0, func, alg) > maxTime)
        return;
    if (testNPFile("Pontos64k", 1.0, func, alg) > maxTime)
        return;
    if (testNPFile("Pontos128k", 0.0, func, alg) > maxTime)
        return;
    if (testNPRand(0x40000, "Pontos256k", 1.0, func, alg) > maxTime)
        return;
    if (testNPRand(0x80000, "Pontos512k",  1.0, func, alg) > maxTime)
        return;
    if ( testNPRand(0x100000, "Pontos1M",  1.0, func, alg) > maxTime)
        return;
    if ( testNPRand(0x200000, "Pontos2M",  1.0, func, alg) > maxTime)
        return;
    */
}