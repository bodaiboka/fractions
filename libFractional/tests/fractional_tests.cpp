#include <gtest/gtest.h>
#include "fractional_util.h"

TEST(ProduceFractionalResultTest, AdditionTest)
{
    EXPECT_EQ(produce_fractional_result("1/2 + 1/4"), "3/4");
    EXPECT_EQ(produce_fractional_result("1&1/2 + 2&1/2"), "4");
    EXPECT_EQ(produce_fractional_result("2&1/4 + -1&1/2"), "3/4");
}

TEST(ProduceFractionalResultTest, SubtractionTest)
{
    EXPECT_EQ(produce_fractional_result("-1/2 - 1/4"), "-3/4");
    EXPECT_EQ(produce_fractional_result("1/2 - 3/6"), "0");
    EXPECT_EQ(produce_fractional_result("2&1/4 - -3/4"), "3");
}

TEST(ProduceFractionalResultTest, MultiplicationTest)
{
    EXPECT_EQ(produce_fractional_result("-1/2 * 5"), "-2&1/2");
    EXPECT_EQ(produce_fractional_result("1/2 * 3/6"), "1/4");
    EXPECT_EQ(produce_fractional_result("-1 * -1"), "1");
}

TEST(ProduceFractionalResultTest, DivisionTest)
{
    EXPECT_EQ(produce_fractional_result("-1/2 / 1/4"), "-2");
    EXPECT_EQ(produce_fractional_result("1 / 8"), "1/8");
    EXPECT_EQ(produce_fractional_result("2&1/4 / -1/4"), "-9");
}

TEST(ProduceFractionalResultTest, InvalidInputTest)
{
    EXPECT_THROW(produce_fractional_result("1/2"), std::runtime_error);
    EXPECT_THROW(produce_fractional_result("1/2 X 3/6"), std::runtime_error);
    EXPECT_THROW(produce_fractional_result("2&-1/4 - 3/4"), std::runtime_error);
}

TEST(ProduceFractionalResultTest, MultipleSpaceTest)
{
    EXPECT_EQ(produce_fractional_result("-1/2        /  1/4"), "-2");
    EXPECT_EQ(produce_fractional_result("1 /            8"), "1/8");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}