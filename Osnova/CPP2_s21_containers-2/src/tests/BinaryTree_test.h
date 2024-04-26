#ifndef S21_BINARY_TREE_TEST
#define S21_BINARY_TREE_TEST

#include <gtest/gtest.h>
#include "../containers/binary_tree/s21_binary_tree.h"

TEST(s21_BinaryTree_test, test_init_and_insert) {
    s21::BinaryTree<int> t{3};
    EXPECT_EQ(t.getValue(), 3);
    EXPECT_THROW({t.getLeft();}, std::out_of_range);
    EXPECT_THROW({t.getRight();}, std::out_of_range);
    t.insert(2);
    EXPECT_EQ(t.getLeft()->getValue(), 2);
    EXPECT_THROW({t.getLeft()->getLeft();}, std::out_of_range);
    EXPECT_THROW({t.getLeft()->getRight();}, std::out_of_range);
    t.insert(5);
    EXPECT_EQ(t.getRight()->getValue(), 5);
    EXPECT_THROW({t.getRight()->getLeft();}, std::out_of_range);
    EXPECT_THROW({t.getRight()->getRight();}, std::out_of_range);
    t.insert(6);
    EXPECT_EQ(t.getRight()->getRight()->getValue(), 6);
    EXPECT_THROW({t.getRight()->getRight()->getLeft();}, std::out_of_range);
    EXPECT_THROW({t.getRight()->getRight()->getRight();}, std::out_of_range);
    t.insert(1);
    EXPECT_EQ(t.getLeft()->getLeft()->getValue(), 1);
    EXPECT_THROW({t.getLeft()->getLeft()->getLeft();}, std::out_of_range);
    EXPECT_THROW({t.getLeft()->getLeft()->getRight();}, std::out_of_range);
}

TEST(s21_BinaryTree_test, test_init_and_insert2){
    s21::BinaryTree<double> t{3.5};
    t.insert(1);
    t.insert(-32);
    t.insert(-1);
    t.insert(5.33);
    EXPECT_EQ(t.getValue(), 3.5);
    EXPECT_EQ(t.getLeft()->getValue(), 1);
    EXPECT_EQ(t.getLeft()->getLeft()->getValue(), -32);
    EXPECT_EQ(t.getLeft()->getLeft()->getRight()->getValue(), -1);
    EXPECT_EQ(t.getRight()->getValue(), 5.33);
}

TEST(s21_BinaryTree_test, test_init_and_insert_with_pair){
    //При сравнении std::pair, сравнивается сначала первый элемент, а ппотом второй
    s21::BinaryTree<std::pair<double, std::string>> t{std::make_pair(2.23, std::string("hello"))};
    EXPECT_EQ(t.getValue().second, std::string("hello"));
    EXPECT_THROW({t.getLeft();}, std::out_of_range);
    EXPECT_THROW({t.getRight();}, std::out_of_range);
    t.insert(std::make_pair(1.2324, std::string("bye")));
    EXPECT_EQ(t.getLeft()->getValue().second, std::string("bye"));
    t.insert(std::make_pair(-32.5, std::string("ok")));
    EXPECT_EQ(t.getLeft()->getLeft()->getValue().second, std::string("ok"));
    t.insert(std::make_pair(-1, std::string("ok")));
    EXPECT_EQ(t.getLeft()->getLeft()->getRight()->getValue().second, std::string("ok"));
    t.insert(std::make_pair(5.53, std::string("yes")));
    EXPECT_EQ(t.getRight()->getValue().second, std::string("yes"));
}
#endif