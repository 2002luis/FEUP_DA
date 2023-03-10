// By: Gonçalo Leão

#include "exercises.h"

#include <algorithm>

bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}

bool Activity::operator<(const Activity &a2) const {
    return this->finish<a2.finish;
}

// Time: O(N*log(N)), Space: O(N), where N is the number of activities
std::vector<Activity> activitySelectionGR(std::vector<Activity> A) {
    std::vector<Activity> selected;
    std::sort(A.begin(),A.end());
    selected.push_back(A[0]);
    for(unsigned long int i = 1; i < A.size(); i++){
        if(A[i].start>=selected.back().finish) selected.push_back(A[i]);
    }
    return selected;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(TP3_Ex2, activityScheduling) {
    std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
    std::vector<Activity> V = activitySelectionGR(A);
    EXPECT_EQ(V.size(), 3 );
    EXPECT_THAT(V,  ::testing::UnorderedElementsAre(Activity(5, 15), Activity(30, 35), Activity(40, 50)));
}