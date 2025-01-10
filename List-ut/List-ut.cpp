#include "List.h"
#include <gtest/gtest.h>

TEST(ListTests, IsEmptyShouldReturnTrueWhenListIsEmpty)
{
    List<int> list;

    EXPECT_EQ(list.isEmpty(), true);
}

TEST(ListTests, ShouldReturn5And20WhenFirstAndLastIsCalled)
{
    List<int> list;
    list.push_back(5);
    list.push_back(20);

    EXPECT_EQ(list.first(), 5);
    EXPECT_EQ(list.last(), 20);
}

TEST(ListTests, ShouldReturn6WhenEraseIsCalledOn5)
{
    List<int> list;
    list.push_back(5);
    list.push_back(6);
    list.push_back(20);

    list.erase(list.begin());

    List<int> expectedResult;
    expectedResult.push_back(6);
    expectedResult.push_back(20);

    EXPECT_TRUE(list == expectedResult);
}

TEST(ListTests, ShouldReturnEmptyListWhenEraseIsCalledOn5)
{
    List<int> list;
    list.push_back(5);

    list.erase(list.begin());

    List<int> expectedResult;
    expectedResult.clear();

    EXPECT_TRUE(list == expectedResult);
}

TEST(ListTests, ShouldReturn5WhenEraseIsCalledOn6)
{
    List<int> list;
    list.push_back(5);
    list.push_back(6);
    list.push_back(20);

    list.eraseIndex(1);

    List<int> expectedResult;
    expectedResult.push_back(5);
    expectedResult.push_back(20);

    EXPECT_TRUE(list == expectedResult);
}

TEST(ListTests, ShouldReturn5WhenEraseIsCalledOn20)
{
    List<int> list;
    list.push_back(5);
    list.push_back(6);
    list.push_back(20);

    auto it = list.begin();
    it++;
    it++;
    list.erase(it);

    List<int> expectedResult;
    expectedResult.push_back(5);
    expectedResult.push_back(6);

    EXPECT_TRUE(list == expectedResult);
}

TEST(ListTests, ShouldReturnFalseIfTwoComparedListsHaveDifferentValues)
{
    List<int> list;
    list.push_back(5);
    list.push_back(21);

    List<int> comparedList;
    comparedList.push_back(5);
    comparedList.push_back(20);

    EXPECT_FALSE(list == comparedList);
}

TEST(ListTests, ShouldReturnFalseIfTwoComparedListsHaveDifferentSizes)
{
    List<int> list;
    list.push_back(5);
    list.push_back(20);
    list.push_back(15);

    List<int> comparedList;
    comparedList.push_back(5);
    comparedList.push_back(20);

    EXPECT_FALSE(list == comparedList);
}
