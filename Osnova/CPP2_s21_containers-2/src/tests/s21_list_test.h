#include <gtest/gtest.h>

#include <cstdio>
#include <list>
#include <stdexcept>

#include "../s21_containers.h"

template <typename T>
bool compare_lists(s21::list<T> list, std::list<T> std_list) {
  printf("COMPARE STARTS\n");
  printf("COMPARE SIZE\nlist | std_list\n");
  printf("%-5ld|%2ld\n==============\n", list.size(), std_list.size());
  if (list.size() != std_list.size()) {
    return false;
  }
  auto iter = list.begin();
  auto std_iter = std_list.begin();
  printf("COMPARE VALUES\n");
  for (typename s21::list<int>::iterator it = list.begin(); it != list.end();
       ++it) {
    printf("%-5d|%2d\n", *iter, *std_iter);
    if (*iter != *std_iter) {
      return false;
    }
    iter++;
    std_iter++;
  }
  return true;
}

TEST(List_test, Default_Constructor) {
  s21::list<int> list1;
  std::list<int> list2;
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Size_Constructor) {
  s21::list<int> list1(500);
  std::list<int> list2(500);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Initializer_List_Constructor) {
  s21::list<int> list1 = {1, 2, 3, 4, 5};
  std::list<int> list2 = {1, 2, 3, 4, 5};
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Copy_Constructor) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  s21::list<int> copied1(list1);
  std::list<int> copied2(list2);
  ASSERT_TRUE(compare_lists(list1, list2));
  ASSERT_TRUE(compare_lists(copied1, copied2));
}

TEST(List_test, Move_Constructor) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  s21::list<int> moved1(std::move(list1));
  std::list<int> moved2(std::move(list2));
  ASSERT_TRUE(compare_lists(list1, list2));
  ASSERT_TRUE(compare_lists(moved1, moved2));
}

TEST(List_test, Move_Assignment) {
  s21::list<int> list1({1, 2, 3});
  s21::list<int> replace1({4, 5, 6, 7});
  std::list<int> list2({1, 2, 3});
  std::list<int> replace2({4, 5, 6, 7});
  list1 = std::move(replace1);
  list2 = std::move(replace2);
  ASSERT_TRUE(compare_lists(list1, list2));
  ASSERT_TRUE(compare_lists(replace1, replace2));
}

TEST(List_test, Iter_Prefix_Inc) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  auto iter1 = list1.begin();
  auto iter2 = list2.begin();
  iter1++;
  iter2++;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(List_test, Iter_Postfix_Inc) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  auto iter1 = list1.begin();
  auto iter2 = list2.begin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(List_test, Iter_Prefix_Decr) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  auto iter1 = list1.end();
  auto iter2 = list2.end();
  iter1--;
  iter2--;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(List_test, Iter_Postfix_Decr) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  auto iter1 = list1.end();
  auto iter2 = list2.end();
  --iter1;
  --iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(List_test, Front) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  ASSERT_EQ(list1.front(), list2.front());
}

TEST(List_test, Back) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  ASSERT_EQ(list1.back(), list2.back());
}

TEST(List_test, Begin) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  ASSERT_EQ(*list1.begin(), *list2.begin());
}

TEST(List_test, End) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  auto it1 = list1.end();
  auto it2 = list2.end();
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
}

TEST(List_test, Const_Begin) {
  const s21::list<int> list1 = {1, 2, 3, 4};
  const std::list<int> list2 = {1, 2, 3, 4};
  ASSERT_EQ(*list1.begin(), *list2.begin());
}

TEST(List_test, Const_End) {
  const s21::list<int> list1 = {1, 2, 3, 4};
  const std::list<int> list2 = {1, 2, 3, 4};
  auto it1 = list1.end();
  auto it2 = list2.end();
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
}

TEST(List_test, Empty_False) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  ASSERT_EQ(list1.empty(), list2.empty());
}

TEST(List_test, Empty_True) {
  s21::list<int> list1(5);
  std::list<int> list2(5);
  ASSERT_EQ(list1.empty(), list2.empty());
}

TEST(List_test, Max_Size) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  ASSERT_EQ(list1.max_size(), list2.max_size());
}

TEST(List_test, Clear) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  list1.clear();
  list2.clear();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Clear_Empty) {
  s21::list<int> list1;
  std::list<int> list2;
  list1.clear();
  list2.clear();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Insert_Empty) {
  s21::list<int> list1;
  std::list<int> list2;
  auto it = list1.insert(list1.begin(), 0);
  auto it2 = list2.insert(list2.begin(), 0);
  ASSERT_EQ(*it, *it2);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Insert_Head) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  auto it = list1.insert(list1.begin(), 0);
  auto it2 = list2.insert(list2.begin(), 0);
  ASSERT_EQ(*it, *it2);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Insert_Tail) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  auto it = list1.insert(list1.end(), 0);
  auto it2 = list2.insert(list2.end(), 0);
  ASSERT_EQ(*it, *it2);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Insert_Middle) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  auto iter1 = list1.begin();
  auto iter2 = list2.begin();
  iter1++;
  iter2++;
  auto it = list1.insert(iter1, 0);
  auto it2 = list2.insert(iter2, 0);
  ASSERT_EQ(*it, *it2);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Erase_Empty) {
  s21::list<int> list1;
  ASSERT_THROW(list1.erase(list1.begin()), std::invalid_argument);
}

TEST(List_test, Erase_Head) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  list1.erase(list1.begin());
  list2.erase(list2.begin());
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Erase_Middle) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  auto iter1 = list1.begin();
  auto iter2 = list2.begin();
  iter1++;
  iter2++;
  iter1++;
  iter2++;
  list1.erase(iter1);
  list2.erase(iter2);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Erase_Tail) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  auto iter1 = list1.end();
  auto iter2 = list2.end();
  iter1--;
  iter2--;
  list1.erase(iter1);
  list2.erase(iter2);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Erase_End) {
  s21::list<int> list1 = {1, 2, 3, 4};
  ASSERT_THROW(list1.erase(list1.end()), std::invalid_argument);
}

TEST(List_test, Push_Back) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  list1.push_back(5);
  list2.push_back(5);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Push_Back_Empty) {
  s21::list<int> list1;
  std::list<int> list2;
  list1.push_back(5);
  list2.push_back(5);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Pop_Back_1_Element) {
  s21::list<int> list1 = {1};
  std::list<int> list2 = {1};
  list1.pop_back();
  list2.pop_back();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Pop_Back_Many) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  list1.pop_back();
  list2.pop_back();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Pop_Back_Empty) {
  s21::list<int> list1;
  ASSERT_THROW(list1.pop_back(), std::invalid_argument);
}

TEST(List_test, Push_Front) {
  s21::list<int> list1 = {1};
  std::list<int> list2 = {1};
  list1.push_front(5);
  list2.push_front(5);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Push_Front_Many) {
  s21::list<int> list1 = {1, 2};
  std::list<int> list2 = {1, 2};
  list1.push_front(5);
  list2.push_front(5);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Push_Front_Empty) {
  s21::list<int> list1;
  std::list<int> list2;
  list1.push_front(5);
  list2.push_front(5);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Pop_Front_1_Element) {
  s21::list<int> list1 = {1};
  std::list<int> list2 = {1};
  list1.pop_front();
  list2.pop_front();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Pop_Front_Many) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  list1.pop_front();
  list2.pop_front();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Pop_Front_Empty) {
  s21::list<int> list1;
  ASSERT_THROW(list1.pop_front(), std::invalid_argument);
}

TEST(List_test, Swap_Empty) {
  s21::list<int> list1;
  std::list<int> list2;
  s21::list<int> list3;
  std::list<int> list4;
  list1.swap(list3);
  list2.swap(list4);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Swap) {
  s21::list<int> list1 = {1, 2, 3, 4};
  std::list<int> list2 = {1, 2, 3, 4};
  s21::list<int> list3 = {5, 6, 7};
  std::list<int> list4 = {5, 6, 7};
  list1.swap(list3);
  list2.swap(list4);
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Merge_1) {
  s21::list<int> list1 = {1, 3, 5};
  s21::list<int> list3 = {2, 4, 6};
  list1.merge(list3);
  std::list<int> list2 = {1, 3, 5};
  std::list<int> list4 = {2, 4, 6};
  list2.merge(list4);
  ASSERT_TRUE(compare_lists(list1, list2));
  ASSERT_TRUE(compare_lists(list3, list4));
}

TEST(List_test, Merge_2) {
  s21::list<int> list1 = {10, 20, 30};
  s21::list<int> list3 = {1, 2, 4, 40, 80};
  list1.merge(list3);
  std::list<int> list2 = {10, 20, 30};
  std::list<int> list4 = {1, 2, 4, 40, 80};
  list2.merge(list4);
  ASSERT_TRUE(compare_lists(list1, list2));
  ASSERT_TRUE(compare_lists(list3, list4));
}

TEST(List_test, Merge_3) {
  s21::list<int> list1 = {10, 10, 10};
  s21::list<int> list3 = {10, 10, 10};
  list1.merge(list3);
  std::list<int> list2 = {10, 10, 10};
  std::list<int> list4 = {10, 10, 10};
  list2.merge(list4);
  ASSERT_TRUE(compare_lists(list1, list2));
  ASSERT_TRUE(compare_lists(list3, list4));
}

TEST(List_test, Merge_Empty_1) {
  s21::list<int> list1;
  s21::list<int> list3 = {2, 4, 6};
  list1.merge(list3);
  std::list<int> list2;
  std::list<int> list4 = {2, 4, 6};
  list2.merge(list4);
  ASSERT_TRUE(compare_lists(list1, list2));
  ASSERT_TRUE(compare_lists(list3, list4));
}

TEST(List_test, Merge_Empty_2) {
  s21::list<int> list1 = {1, 3, 5};
  s21::list<int> list3;
  list1.merge(list3);
  std::list<int> list2 = {1, 3, 5};
  std::list<int> list4;
  list2.merge(list4);
  ASSERT_TRUE(compare_lists(list1, list2));
  ASSERT_TRUE(compare_lists(list3, list4));
}

TEST(List_test, Splice_Head) {
  s21::list<int> list1 = {1, 3, 5, 6, 7};
  s21::list<int> list3 = {10, 10, 10};
  list1.splice(list1.begin(), list3);
  std::list<int> list2 = {1, 3, 5, 6, 7};
  std::list<int> list4 = {10, 10, 10};
  list2.splice(list2.begin(), list4);
  ASSERT_TRUE(compare_lists(list1, list2));
  ASSERT_TRUE(compare_lists(list3, list4));
}

TEST(List_test, Splice_Tail) {
  s21::list<int> list1 = {1, 3, 5, 6, 7};
  s21::list<int> list3 = {10, 10, 10};
  list3.splice(list3.end(), list1);
  std::list<int> list2 = {1, 3, 5, 6, 7};
  std::list<int> list4 = {10, 10, 10};
  list4.splice(list4.end(), list2);
  ASSERT_TRUE(compare_lists(list1, list2));
  ASSERT_TRUE(compare_lists(list3, list4));
}

TEST(List_test, Splice_Empty_1) {
  s21::list<int> list1;
  s21::list<int> list3 = {10, 10, 10};
  list1.splice(list1.begin(), list3);
  std::list<int> list2;
  std::list<int> list4 = {10, 10, 10};
  list2.splice(list2.begin(), list4);
  ASSERT_TRUE(compare_lists(list1, list2));
  ASSERT_TRUE(compare_lists(list3, list4));
}

TEST(List_test, Splice_Empty_2) {
  s21::list<int> list1 = {1, 3, 5, 6, 7};
  s21::list<int> list3;
  list1.splice(list1.begin(), list3);
  std::list<int> list2 = {1, 3, 5, 6, 7};
  std::list<int> list4;
  list2.splice(list2.begin(), list4);
  ASSERT_TRUE(compare_lists(list1, list2));
  ASSERT_TRUE(compare_lists(list3, list4));
}

TEST(List_test, Splice_Same) {
  s21::list<int> list1 = {1, 3, 5, 6, 7};
  ASSERT_THROW(list1.splice(list1.begin(), list1), std::invalid_argument);
}

TEST(List_test, Reverse_1) {
  s21::list<int> list1 = {1, 3, 5, 6, 7};
  std::list<int> list2 = {1, 3, 5, 6, 7};
  list1.reverse();
  list2.reverse();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Reverse_2) {
  s21::list<int> list1 = {5, 3, 5};
  std::list<int> list2 = {5, 3, 5};
  list1.reverse();
  list2.reverse();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Reverse_Empty) {
  s21::list<int> list1;
  std::list<int> list2;
  list1.reverse();
  list2.reverse();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Unique_1) {
  s21::list<int> list1 = {5, 3, 5, 3, 3};
  std::list<int> list2 = {5, 3, 5, 3, 3};
  list1.unique();
  list2.unique();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Unique_2) {
  s21::list<int> list1 = {5, 3, 5, 3};
  std::list<int> list2 = {5, 3, 5, 3};
  list1.unique();
  list2.unique();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Unique_3) {
  s21::list<int> list1 = {5, 5, 5, 3, 3, 3, 3};
  std::list<int> list2 = {5, 5, 5, 3, 3, 3, 3};
  list1.unique();
  list2.unique();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Unique_4) {
  s21::list<int> list1 = {5, 5, 5, 5};
  std::list<int> list2 = {5, 5, 5, 5};
  list1.unique();
  list2.unique();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Unique_5) {
  s21::list<int> list1 = {5};
  std::list<int> list2 = {5};
  list1.unique();
  list2.unique();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Unique_Empty) {
  s21::list<int> list1;
  std::list<int> list2;
  list1.unique();
  list2.unique();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Sort_1) {
  s21::list<int> list1 = {3, 2, 1};
  std::list<int> list2 = {3, 2, 1};
  list1.sort();
  list2.sort();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Sort_2) {
  s21::list<int> list1 = {55, 1, 4, 4, 0, 3, 12, 4};
  std::list<int> list2 = {55, 1, 4, 4, 0, 3, 12, 4};
  list1.sort();
  list2.sort();
  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(List_test, Sort_Empty) {
  s21::list<int> list1;
  std::list<int> list2;
  list1.sort();
  list2.sort();
  ASSERT_TRUE(compare_lists(list1, list2));
}