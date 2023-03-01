// By: Gonçalo Leão

#include "exercises.h"

#include <algorithm>

double minimumAverageCompletionTime(std::vector<unsigned int> tasks, std::vector<unsigned int> &orderedTasks) {
    orderedTasks = tasks;
    sort(orderedTasks.begin(),orderedTasks.end());
    double out = 0, cur = 0;
    for(unsigned long int i = 0; i < orderedTasks.size(); i++){
        out+=cur;
        out+=orderedTasks[i];
        cur+=orderedTasks[i];
    }
    return out/orderedTasks.size();
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(TP3_Ex3, taskOrdering) {
    std::vector<unsigned int> tasks = {15, 8, 3, 10};
    std::vector<unsigned int> orderedTasks;
    double averageTime = minimumAverageCompletionTime(tasks, orderedTasks);
    EXPECT_EQ(orderedTasks.size(), 4 );
    EXPECT_NEAR(averageTime, 17.75, 0.00001);
    EXPECT_THAT(orderedTasks,  ::testing::ElementsAre(3,8,10,15));
}