#include <gtest/gtest.h>

#include "../s21_containers.h"

TEST(S21QueueMemberFunction, DefaultConstructor) {
  s21::Queue<int> que;

  EXPECT_EQ(que.empty(), true);
  EXPECT_EQ(que.size(), (size_t)0);
}

TEST(S21QueueMemberFunction, CopyContructor) {
  s21::Queue<int> que1;
  que1.push(228);
  s21::Queue<int> que2(que1);
  que2.push(2);

  EXPECT_EQ(que1.size(), (size_t)1);
  EXPECT_EQ(que1.front(), 228);
  EXPECT_EQ(que2.size(), (size_t)2);
  EXPECT_EQ(que1.front(), 228);
}

TEST(S21QueueMemberFunction, MoveContructor) {
  s21::Queue<int> que1;
  que1.push(228);
  s21::Queue<int> que2(std::move(que1));

  EXPECT_EQ(que1.size(), (size_t)0);
  EXPECT_EQ(que2.size(), (size_t)1);
  EXPECT_EQ(que2.front(), 228);
}

TEST(S21QueueMemberFunction, MoveOperator) {
  s21::Queue<int> que1;
  que1.push(228);
  s21::Queue<int> que2 = std::move(que1);

  EXPECT_EQ(que1.size(), (size_t)0);
  EXPECT_EQ(que2.size(), (size_t)1);
  EXPECT_EQ(que2.front(), 228);
}

TEST(S21QueueMemberFunction, InitializerListConstructor) {
  s21::Queue<int> que2({1, 2, 3});

  EXPECT_EQ(que2.empty(), false);
  EXPECT_EQ(que2.size(), (size_t)3);
  EXPECT_EQ(que2.front(), 1);
  EXPECT_EQ(que2.back(), 3);
}

TEST(S21QueueElementAccess, FirsElement) {
  s21::Queue<int> que2({1, 2, 3});

  EXPECT_EQ(que2.front(), 1);
}

TEST(S21QueueElementAccess, LastElement) {
  s21::Queue<int> que2({1, 2, 3});

  EXPECT_EQ(que2.back(), 3);
}

TEST(S21QueueCapacity, EmptyQueue) {
  s21::Queue<int> que2({});

  EXPECT_EQ(que2.empty(), true);
}

TEST(S21QueueCapacity, SizeOfQueue) {
  s21::Queue<int> que2({1, 2, 3});

  EXPECT_EQ(que2.size(), (size_t)3);
}

TEST(S21QueueModifiers, PushQueueElement) {
  s21::Queue<int> que1;
  que1.push(228);

  EXPECT_EQ(que1.front(), 228);
}

TEST(S21QueueModifiers, RemoveQueueElement) {
  s21::Queue<int> que2({1, 2, 3});
  que2.pop();

  EXPECT_EQ(que2.front(), 2);
}

TEST(S21QueueModifiers, SwapQueueElement) {
  s21::Queue<int> que1({1, 2, 3});
  s21::Queue<int> que2({4, 5, 6});
  que2.swap(que1);

  EXPECT_EQ(que2.front(), 1);
  EXPECT_EQ(que2.back(), 3);
}

TEST(S21QueueMemberFunction, AssigmentElemetn) {
  s21::Queue<int> stc1({1, 2, 3});
  s21::Queue<int> stc2 = stc1;

  EXPECT_EQ(stc2.back(), 3);
}