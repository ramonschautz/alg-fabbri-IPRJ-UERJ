// rfabbri 2025-09-25
#include "gtest/gtest.h"
#include "../sort_char.h"
#include <string.h>
#include <algorithm>

TEST(SortCharTest, HandlesEmptyArray) {
  char arr[] = "";
  sort_char(arr, 0);
  ASSERT_EQ(arr[0], '\0');
}

TEST(SortCharTest, HandlesSingleElementArray) {
  char arr[] = "a";
  sort_char(arr, 1);
  ASSERT_EQ(arr[0], 'a');
}

TEST(SortCharTest, SortsSimpleString) {
  char arr[] = "badcfe";
  int n = strlen(arr);
  sort_char(arr, n);
  ASSERT_STREQ(arr, "abcdef");
}

TEST(SortCharTest, SortsWithDuplicates) {
  char arr[] = "hello world";
  int n = strlen(arr);
  char expected[] = " dehllloorw"; // space first
  sort_char(arr, n);
  ASSERT_STREQ(arr, expected);
}

TEST(SortCharTest, SortsAllSameCharacters) {
  char arr[] = "aaaaa";
  int n = strlen(arr);
  sort_char(arr, n);
  ASSERT_STREQ(arr, "aaaaa");
}

TEST(SortCharTest, HandlesAlreadySorted) {
  char arr[] = "12345";
  int n = strlen(arr);
  sort_char(arr, n);
  ASSERT_STREQ(arr, "12345");
}

TEST(SortCharTest, HandlesReverseSorted) {
  char arr[] = "54321";
  int n = strlen(arr);
  sort_char(arr, n);
  ASSERT_STREQ(arr, "12345");
}

// O main não é necessário aqui, pois o CMake cuidará de vincular com o gtest_main
// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
