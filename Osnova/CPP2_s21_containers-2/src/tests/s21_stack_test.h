#include <gtest/gtest.h>

#include "../s21_containers.h"

TEST(S21StackMemberFunction, DefaultConstructor) {
  s21::Stack<int> stc;

  EXPECT_EQ(stc.empty(), true);
  EXPECT_EQ(stc.size(), (size_t)0);
}

TEST(S21StackMemberFunction, CopyContructor) {
  s21::Stack<int> stc1;
  stc1.push(228);
  s21::Stack<int> stc2(stc1);
  stc2.push(2);

  EXPECT_EQ(stc1.size(), (size_t)1);
  EXPECT_EQ(stc1.top(), 228);
  EXPECT_EQ(stc2.size(), (size_t)2);
  EXPECT_EQ(stc1.top(), 228);
}

TEST(S21StackMemberFunction, MoveContructor) {
  s21::Stack<int> stc1;
  stc1.push(228);
  s21::Stack<int> stc2(std::move(stc1));

  EXPECT_EQ(stc1.size(), (size_t)0);
  EXPECT_EQ(stc2.size(), (size_t)1);
  EXPECT_EQ(stc2.top(), 228);
}

TEST(S21StackMemberFunction, MoveOperator) {
  s21::Stack<int> stc1;
  stc1.push(228);
  s21::Stack<int> stc2 = std::move(stc1);

  EXPECT_EQ(stc1.size(), (size_t)0);
  EXPECT_EQ(stc2.size(), (size_t)1);
  EXPECT_EQ(stc2.top(), 228);
}

TEST(S21StackMemberFunction, InitializerListConstructor) {
  s21::Stack<int> stc2({1, 2, 3});

  EXPECT_EQ(stc2.empty(), false);
  EXPECT_EQ(stc2.size(), (size_t)3);
  EXPECT_EQ(stc2.top(), 3);
}

TEST(S21StackElementAccess, StackTopElement) {
  s21::Stack<int> stc1;
  stc1.push(228);

  EXPECT_EQ(stc1.top(), 228);
}

TEST(S21StackCapacity, EmptyStack) {
  s21::Stack<int> stc2({});

  EXPECT_EQ(stc2.empty(), true);
}

TEST(S21StckCapacity, SizeOfStack) {
  s21::Stack<int> stc2({1, 2, 3});

  EXPECT_EQ(stc2.size(), (size_t)3);
}

TEST(S21StackModifiers, PushStackElement) {
  s21::Stack<int> stc1;
  stc1.push(228);

  EXPECT_EQ(stc1.top(), 228);
}

TEST(S21StackModifiers, RemoveStackElement) {
  s21::Stack<int> stc2({1, 2, 3});
  stc2.pop();

  EXPECT_EQ(stc2.top(), 2);
}

TEST(S21StackModifiers, SwapStackElement) {
  s21::Stack<int> stc1({1, 2, 3});
  s21::Stack<int> stc2({4, 5, 6});
  stc2.swap(stc1);

  EXPECT_EQ(stc2.top(), 3);
}

TEST(S21StackMemberFunction, AssigmentElemetn) {
  s21::Stack<int> stc1({1, 2, 3});
  s21::Stack<int> stc2 = stc1;

  EXPECT_EQ(stc2.top(), 3);
}