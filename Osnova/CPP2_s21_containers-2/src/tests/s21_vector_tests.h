#include <gtest/gtest.h>

#include <cstdio>
#include <stdexcept>
#include <vector>

#include "../containers/vector/s21_vector.h"

template <typename T>
bool compare_vectors(s21::vector<T> vector, std::vector<T> std_vector) {
  printf("COMPARE STARTS\n");
  printf("COMPARE CAPACITY\nvector | std_vector\n");
  printf("%-7ld|%2ld\n==============\n", vector.capacity(),
         std_vector.capacity());
  if (vector.capacity() != std_vector.capacity()) {
    return false;
  }
  printf("COMPARE SIZE\n");
  printf("%-7ld|%2ld\n==============\n", vector.size(), std_vector.size());
  if (vector.size() != std_vector.size()) {
    return false;
  }
  auto iter = vector.begin();
  auto std_iter = std_vector.begin();
  printf("COMPARE VALUES\n");
  for (auto it = vector.begin(); it != vector.end(); ++it) {
    printf("%-7d|%2d\n", *iter, *std_iter);
    if (*iter != *std_iter) {
      return false;
    }
    iter++;
    std_iter++;
  }
  return true;
}

TEST(Vector_test, Default_Constructor) {
  s21::vector<int> vector1;
  std::vector<int> vector2;
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Size_Constructor) {
  s21::vector<int> vector1(10);
  std::vector<int> vector2(10);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Initializer_List_Constructor) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Copy_Constructor) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  std::vector<int> vector2 = {1, 2, 3, 4};
  s21::vector<int> copied1(vector1);
  std::vector<int> copied2(vector2);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
  ASSERT_TRUE(compare_vectors(copied1, copied2));
}

TEST(Vector_test, Move_Constructor) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  std::vector<int> vector2 = {1, 2, 3, 4};
  s21::vector<int> moved1(std::move(vector1));
  std::vector<int> moved2(std::move(vector2));
  ASSERT_TRUE(compare_vectors(vector1, vector2));
  ASSERT_TRUE(compare_vectors(moved1, moved2));
}

TEST(Vector_test, Move_Assignment) {
  s21::vector<int> vector1({1, 2, 3});
  s21::vector<int> replace1({4, 5, 6, 7});
  std::vector<int> vector2({1, 2, 3});
  std::vector<int> replace2({4, 5, 6, 7});
  vector1 = std::move(replace1);
  vector2 = std::move(replace2);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
  ASSERT_TRUE(compare_vectors(replace1, replace2));
}

TEST(Vector_test, At) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  std::vector<int> vector2 = {1, 2, 3, 4};
  ASSERT_EQ(vector1.at(2), vector2.at(2));
}

TEST(Vector_test, At_Out_Of_Range) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  ASSERT_THROW(vector1.at(5), std::out_of_range);
}

TEST(Vector_test, Braces_Operator) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  std::vector<int> vector2 = {1, 2, 3, 4};
  ASSERT_EQ(vector1[2], vector2[2]);
}

TEST(Vector_test, Braces_Operator_Out_Of_Range) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  ASSERT_THROW(vector1[5], std::out_of_range);
}

TEST(Vector_test, Front) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  std::vector<int> vector2 = {1, 2, 3, 4};
  ASSERT_EQ(vector1.front(), vector2.front());
}

TEST(Vector_test, Back) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  std::vector<int> vector2 = {1, 2, 3, 4};
  ASSERT_EQ(vector1.back(), vector2.back());
}

TEST(Vector_test, Data) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  std::vector<int> vector2 = {1, 2, 3, 4};
  ASSERT_EQ(*vector1.data(), *vector2.data());
}

TEST(Vector_test, Begin) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  std::vector<int> vector2 = {1, 2, 3, 4};
  ASSERT_EQ(*vector1.begin(), *vector2.begin());
}

TEST(Vector_test, End) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  std::vector<int> vector2 = {1, 2, 3, 4};
  auto it1 = vector1.end();
  auto it2 = vector2.end();
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
}

TEST(Vector_test, Const_Begin) {
  const s21::vector<int> vector1 = {1, 2, 3, 4};
  const std::vector<int> vector2 = {1, 2, 3, 4};
  ASSERT_EQ(*vector1.begin(), *vector2.begin());
}

TEST(Vector_test, Const_End) {
  const s21::vector<int> vector1 = {1, 2, 3, 4};
  const std::vector<int> vector2 = {1, 2, 3, 4};
  auto it1 = vector1.end();
  auto it2 = vector2.end();
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
}

TEST(Vector_test, Empty_True) {
  s21::vector<int> vector1(5);
  std::vector<int> vector2(5);
  ASSERT_EQ(vector1.empty(), vector2.empty());
}

TEST(Vector_test, Empty_False) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  std::vector<int> vector2 = {1, 2, 3, 4};
  ASSERT_EQ(vector1.empty(), vector2.empty());
}

TEST(Vector_test, Max_Size) {
  s21::vector<int> vector1(5);
  std::vector<int> vector2(5);
  ASSERT_EQ(vector1.max_size(), vector2.max_size());
}

TEST(Vector_test, Reserve_1) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.reserve(10);
  vector2.reserve(10);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Reserve_2) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.reserve(2);
  vector2.reserve(2);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Reserve_3) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.reserve(5);
  vector2.reserve(5);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Shrink_To_Fit_1) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.reserve(10);
  vector2.reserve(10);
  vector1.shrink_to_fit();
  vector2.shrink_to_fit();
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Shrink_To_Fit_2) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.reserve(5);
  vector2.reserve(5);
  vector1.shrink_to_fit();
  vector2.shrink_to_fit();
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Shrink_To_Fit_3) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.reserve(2);
  vector2.reserve(2);
  vector1.shrink_to_fit();
  vector2.shrink_to_fit();
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Clear_1) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.clear();
  vector2.clear();
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Clear_2) {
  s21::vector<int> vector1;
  std::vector<int> vector2;
  vector1.reserve(10);
  vector2.reserve(10);
  vector1.clear();
  vector2.clear();
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Insert_Begin) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  auto it1 = vector1.insert(vector1.begin(), 10);
  auto it2 = vector2.insert(vector2.begin(), 10);
  ASSERT_EQ(*it1, *it2);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Insert_Middle) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  auto it1 = vector1.insert(vector1.begin() + 2, 10);
  auto it2 = vector2.insert(vector2.begin() + 2, 10);
  ASSERT_EQ(*it1, *it2);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Insert_End) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  auto it1 = vector1.insert(vector1.end(), 10);
  auto it2 = vector2.insert(vector2.end(), 10);
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Insert_Empty) {
  s21::vector<int> vector1;
  std::vector<int> vector2;
  auto it1 = vector1.insert(vector1.end(), 10);
  auto it2 = vector2.insert(vector2.end(), 10);
  ASSERT_EQ(*it1, *it2);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Erase_Begin) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.erase(vector1.begin());
  vector2.erase(vector2.begin());
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Erase_Middle) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.erase(vector1.begin() + 2);
  vector2.erase(vector2.begin() + 2);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Erase_End) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.erase(vector1.end() - 1);
  vector2.erase(vector2.end() - 1);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Erase_Empty) {
  s21::vector<int> vector1;
  ASSERT_THROW(vector1.erase(vector1.begin()), std::invalid_argument);
}

TEST(Vector_test, Push_Back_1) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.push_back(10);
  vector2.push_back(10);
  vector1.push_back(15);
  vector2.push_back(15);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Push_Back_2) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.reserve(10);
  vector2.reserve(10);
  vector1.push_back(15);
  vector2.push_back(15);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Push_Back_Empty) {
  s21::vector<int> vector1;
  std::vector<int> vector2;
  vector1.push_back(10);
  vector2.push_back(10);
  vector1.push_back(15);
  vector2.push_back(15);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Pop_Back) {
  s21::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {1, 2, 3, 4, 5};
  vector1.pop_back();
  vector2.pop_back();
  ASSERT_TRUE(compare_vectors(vector1, vector2));
}

TEST(Vector_test, Pop_Back_Empty) {
  s21::vector<int> vector1;
  ASSERT_THROW(vector1.pop_back(), std::invalid_argument);
}

TEST(Vector_test, Swap) {
  s21::vector<int> vector1 = {1, 2, 3, 4};
  std::vector<int> vector2 = {1, 2, 3, 4};
  s21::vector<int> vector3 = {5, 6, 7};
  std::vector<int> vector4 = {5, 6, 7};
  vector1.swap(vector3);
  vector2.swap(vector4);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
  ASSERT_TRUE(compare_vectors(vector3, vector4));
}

TEST(Vector_test, Swap_Empty) {
  s21::vector<int> vector1;
  std::vector<int> vector2;
  s21::vector<int> vector3;
  std::vector<int> vector4;
  vector1.swap(vector3);
  vector2.swap(vector4);
  ASSERT_TRUE(compare_vectors(vector1, vector2));
  ASSERT_TRUE(compare_vectors(vector3, vector4));
}