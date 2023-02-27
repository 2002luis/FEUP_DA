#include "exercises.h"

#include <cmath>

Result nearestPointsBF(std::vector<Point> &vp) {
    Result res;

    for(unsigned long int i = 0; i < vp.size(); i++){
        for(unsigned long int j = i+1; j < vp.size(); j++){
            if(res.dmin > vp[i].distance(vp[j])) res = {vp[i].distance(vp[j]),vp[i],vp[j]};
        }
    }
    return res;
}

/// TESTS ///
#include "gtest/gtest.h"

TEST(TP2_Ex5, testNPBF) {
    testNearestPoints(nearestPointsBF, "Brute force");
}