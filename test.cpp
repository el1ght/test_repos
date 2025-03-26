#include "pch.h"
#include "stringProcessor.h"
#include "sort.h"

TEST(QuickSortTest, SortsArrayInAscendingOrder)
{
    // Test input array
    char* arr[] = { "banana", "apple", "cherry", "date", "elderberry" };
    size_t length = sizeof(arr) / sizeof(arr[0]);

    // Sort the array
    quick_sort(arr, length);

    // Check if the array is sorted in ascending order
    for (size_t i = 1; i < length; i++)
    {
        ASSERT_TRUE(strcmp(arr[i - 1], arr[i]) <= 0);
    }
}



TEST(QuickSortTest, SingleElementArray) {
    // Test sorting an array with a single element.
    char* arr[] = { "hello" };
    quick_sort(arr, 1);
    ASSERT_STREQ(arr[0], "hello");
}

TEST(QuickSortTest, SortedArray) {
    // Test sorting an array that is already sorted.
    char* arr[] = { "alpha", "beta", "gamma" };
    quick_sort(arr, 3);
    ASSERT_STREQ(arr[0], "alpha");
    ASSERT_STREQ(arr[1], "beta");
    ASSERT_STREQ(arr[2], "gamma");
}

TEST(QuickSortTest, ReverseSortedArray) {
    // Test sorting an array that is reverse sorted.
    char* arr[] = { "gamma", "beta", "alpha" };
    quick_sort(arr, 3);
    ASSERT_STREQ(arr[0], "alpha");
    ASSERT_STREQ(arr[1], "beta");
    ASSERT_STREQ(arr[2], "gamma");
}

TEST(QuickSortTest, RandomArray) {
    // Test sorting an array with random elements.
    char* arr[] = { "hello", "world", "foo", "bar", "baz", "qux", "quux", "corge" };
    quick_sort(arr, 8);
    ASSERT_STREQ(arr[0], "bar");
    ASSERT_STREQ(arr[1], "baz");
    ASSERT_STREQ(arr[2], "corge");
    ASSERT_STREQ(arr[3], "foo");
    ASSERT_STREQ(arr[4], "hello");
    ASSERT_STREQ(arr[5], "quux");
    ASSERT_STREQ(arr[6], "qux");
    ASSERT_STREQ(arr[7], "world");
}


TEST(StringProcessorTest, ValidString_ReturnsTrue)
{
    char str[] = "Valid string: apple, banana; cherry";
    bool isValid = is_string_valid(str);
    EXPECT_TRUE(isValid);
}

TEST(StringProcessorTest, InvalidString_ReturnsFalse)
{
    char str[] = "Invalid string: apple,; banana; cherry";
    bool isValid = is_string_valid(str);
    EXPECT_FALSE(isValid);
}
// Test swap function
TEST(SwapTest, SwapsValuesCorrectly)
{
    char* a = "apple";
    char* b = "banana";

    swap(&a, &b);

    EXPECT_STREQ(a, "banana");
    EXPECT_STREQ(b, "apple");
}

