#include <gtest/gtest.h>

extern "C" {
    #include "test.h"
}

TEST(OutlierTest, Test1) { 
    int input_data[4] = {1,2,6500,4};
    int output_data[4];
    ASSERT_EQ(1, calculate(input_data, output_data, 4, 10));
    ASSERT_EQ(3, output_data[2]);
}

TEST(OutlierTest, PositiveOutliers) {
    int input_data[5] = {1,3,783,9,200};
    int output_data[5];
    ASSERT_EQ(2, calculate(input_data, output_data, 5, 10));
    ASSERT_EQ(5, output_data[2]);
    ASSERT_EQ(13, output_data[4]);
}

TEST(OutlierTest, NegativeOutliers) {
    int input_data[5] = {1,5,-30,10,-200};
    int output_data[5];
    ASSERT_EQ(2, calculate(input_data, output_data, 5, 10));
    ASSERT_EQ(9, output_data[2]);
    ASSERT_EQ(11, output_data[4]);
}

TEST(OutlierTest, GarbageInput) {
    int input_data[5] = {1,-500,-30,-100,-200};
    int output_data[5];
    ASSERT_EQ(-1, calculate(input_data, output_data, 5, 10));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
