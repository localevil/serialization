#include <serialization/cserialization.h>
#include <gtest/include/gtest/gtest.h>
#include <string>

TEST(test001, ChechBuffer)
{
    //Input

    std::string file = "tmp.bin",
            name = "This",
            id = 100
            key = 10;
    //Actual
    bool actual = CSerialization::serialization(file, name, id, key);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ(expected, actual);

}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
