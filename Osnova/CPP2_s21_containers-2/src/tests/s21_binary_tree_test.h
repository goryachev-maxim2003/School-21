#ifndef S21_BINARY_TREE_TEST
#define S21_BINARY_TREE_TEST

#include <gtest/gtest.h>
#include "../containers/binary_tree/s21_binary_tree.h"

TEST(s21_btNode_test, test_init_and_insert) {
    // 3 2 5 6 1
    s21::BinaryTree<double, true> t{3};
    EXPECT_EQ(t.size(), 1);
    EXPECT_EQ(t.getRoot()->getValue(), 3);
    EXPECT_THROW({t.getRoot()->getLeft();}, std::out_of_range);
    EXPECT_THROW({t.getRoot()->getRight();}, std::out_of_range);
    t.insert(2);
    EXPECT_EQ(t.size(), 2);
    EXPECT_EQ(t.getRoot()->getLeft()->getValue(), 2);
    EXPECT_THROW({t.getRoot()->getLeft()->getLeft();}, std::out_of_range);
    EXPECT_THROW({t.getRoot()->getLeft()->getRight();}, std::out_of_range);
    t.insert(5);
    EXPECT_EQ(t.size(), 3);
    EXPECT_EQ(t.getRoot()->getRight()->getValue(), 5);
    EXPECT_THROW({t.getRoot()->getRight()->getLeft();}, std::out_of_range);
    EXPECT_THROW({t.getRoot()->getRight()->getRight();}, std::out_of_range);
    t.insert(6);
    EXPECT_EQ(t.size(), 4);
    EXPECT_EQ(t.getRoot()->getRight()->getRight()->getValue(), 6);
    EXPECT_THROW({t.getRoot()->getRight()->getRight()->getLeft();}, std::out_of_range);
    EXPECT_THROW({t.getRoot()->getRight()->getRight()->getRight();}, std::out_of_range);
    t.insert(1);
    EXPECT_EQ(t.size(), 5);
    EXPECT_EQ(t.getRoot()->getLeft()->getLeft()->getValue(), 1);
    EXPECT_THROW({t.getRoot()->getLeft()->getLeft()->getLeft();}, std::out_of_range);
    EXPECT_THROW({t.getRoot()->getLeft()->getLeft()->getRight();}, std::out_of_range);
    

    //parent
    //   3 
    //  2 5 
    // 1   6
    EXPECT_THROW({t.getRoot()->getParent();}, std::out_of_range);
    EXPECT_EQ(t.getRoot()->getLeft()->getParent()->getValue(), 3);
    EXPECT_EQ(t.getRoot()->getRight()->getParent()->getValue(), 3);
    EXPECT_EQ(t.getRoot()->getRight()->getRight()->getParent()->getValue(), 5);  
    EXPECT_EQ(t.getRoot()->getRight()->getRight()->getParent()->getParent()->getValue(), 3);
    EXPECT_EQ(t.getRoot()->getLeft()->getLeft()->getParent()->getValue(), 2);
    EXPECT_EQ(t.getRoot()->getLeft()->getLeft()->getParent()->getParent()->getValue(), 3);

    t.insert(2.5);
    t.insert(4);
    //parent
    //      3 
    //  2       5 
    // 1 2.5  4  6
    //iterator: 3, 2, 1, 2.5 5 4 6
    // 1 2 2.5 3 4 5 6
    
}

TEST(s21_btNode_test, test_init_and_insert2){
    s21::BinaryTree<double, true> t{3.5};
    t.insert(1);
    t.insert(-32);
    t.insert(-1);
    t.insert(5.33);
    EXPECT_EQ(t.getRoot()->getValue(), 3.5);
    EXPECT_EQ(t.getRoot()->getLeft()->getValue(), 1);
    EXPECT_EQ(t.getRoot()->getLeft()->getLeft()->getValue(), -32);
    EXPECT_EQ(t.getRoot()->getLeft()->getLeft()->getRight()->getValue(), -1);
    EXPECT_EQ(t.getRoot()->getRight()->getValue(), 5.33);
    EXPECT_EQ(t.size(), 5);
}

TEST(s21_btNode_test, test_same_value){
    s21::BinaryTree<int, true> t{};
    EXPECT_EQ(t.size(), 0);
    t.insert(1);
    EXPECT_EQ(t.getRoot()->getValue(), 1);
    EXPECT_EQ(t.size(), 1);
    t.insert(2);
    EXPECT_EQ(t.size(), 2);
    EXPECT_EQ(t.getRoot()->getRight()->getValue(), 2);
    t.insert(3);
    EXPECT_EQ(t.size(), 3);
    EXPECT_EQ(t.getRoot()->getRight()->getRight()->getValue(), 3);
    t.insert(3);
    EXPECT_EQ(t.size(), 3);
    EXPECT_THROW({t.getRoot()->getRight()->getRight()->getRight();}, std::out_of_range);
    t.insert(-1);
    EXPECT_EQ(t.size(), 4);
    t.insert(-1);
    EXPECT_EQ(t.size(), 4);
}

TEST(s21_btNode_test, test_init_and_insert_with_pair){
    //При сравнении std::pair, сравнивается сначала первый элемент, а потом второй
    s21::BinaryTree<std::pair<double, std::string>, true> t{std::make_pair(2.23, std::string("hello"))};
    EXPECT_EQ(t.getRoot()->getValue().second, std::string("hello"));
    EXPECT_THROW({t.getRoot()->getLeft();}, std::out_of_range);
    EXPECT_THROW({t.getRoot()->getRight();}, std::out_of_range);
    t.insert(std::make_pair(1.2324, std::string("bye")));
    EXPECT_EQ(t.getRoot()->getLeft()->getValue().second, std::string("bye"));
    t.insert(std::make_pair(-32.5, std::string("ok")));
    EXPECT_EQ(t.getRoot()->getLeft()->getLeft()->getValue().second, std::string("ok"));
    t.insert(std::make_pair(-1, std::string("ok")));
    EXPECT_EQ(t.getRoot()->getLeft()->getLeft()->getRight()->getValue().second, std::string("ok"));
    t.insert(std::make_pair(5.53, std::string("yes")));
    EXPECT_EQ(t.getRoot()->getRight()->getValue().second, std::string("yes"));
    EXPECT_EQ(t.size(), 5);
}

TEST(s21_btNode_test, test_insert_unique){
    s21::BinaryTree<std::pair<double, std::string>, true> t{std::make_pair(2.23, std::string("hello"))};
    EXPECT_EQ(t.size(), 1);
    t.insert(std::make_pair(2.23, std::string("second")));
    EXPECT_EQ(t.size(), 1);
    EXPECT_EQ(t.getRoot()->getValue().first, 2.23);
    EXPECT_EQ(t.getRoot()->getValue().second, std::string("hello"));
    EXPECT_THROW(t.getRoot()->getLeft(), std::out_of_range);
    EXPECT_THROW(t.getRoot()->getRight(), std::out_of_range);
    t.insert(std::make_pair(3.5, std::string("3")));
    EXPECT_EQ(t.size(), 2);
    EXPECT_THROW(t.getRoot()->getLeft(), std::out_of_range);
    EXPECT_EQ(t.getRoot()->getRight()->getValue().first, 3.5);
    EXPECT_EQ(t.getRoot()->getRight()->getValue().second, std::string("3"));
    t.insert(std::make_pair(3.5, std::string("4")));
    EXPECT_EQ(t.size(), 2);
    EXPECT_THROW(t.getRoot()->getLeft(), std::out_of_range);
    EXPECT_EQ(t.getRoot()->getRight()->getValue().first, 3.5);
    EXPECT_EQ(t.getRoot()->getRight()->getValue().second, std::string("3"));
    EXPECT_THROW(t.getRoot()->getRight()->getLeft(), std::out_of_range);
    EXPECT_THROW(t.getRoot()->getRight()->getRight(), std::out_of_range);
    t.insert(std::make_pair(1.5, std::string("5")));
    EXPECT_EQ(t.size(), 3);
    EXPECT_EQ(t.getRoot()->getLeft()->getValue().first, 1.5);
    EXPECT_EQ(t.getRoot()->getLeft()->getValue().second, std::string("5"));
    EXPECT_THROW(t.getRoot()->getLeft()->getLeft(), std::out_of_range);
    EXPECT_THROW(t.getRoot()->getLeft()->getRight(), std::out_of_range);
    t.insert(std::make_pair(1, std::string("6")));
    EXPECT_EQ(t.size(), 4);
    EXPECT_EQ(t.getRoot()->getLeft()->getLeft()->getValue().first, 1);
    EXPECT_EQ(t.getRoot()->getLeft()->getLeft()->getValue().second, std::string("6"));
    t.insert(std::make_pair(78, std::string("7")));
    EXPECT_EQ(t.size(), 5);
    EXPECT_EQ(t.getRoot()->getRight()->getRight()->getValue().first, 78);
    EXPECT_EQ(t.getRoot()->getRight()->getRight()->getValue().second, std::string("7"));


    //parent
    //keys 2.23 3.5 1.5 1 78
    //   2.23
    //  1.5 3.5
    // 1       78
    EXPECT_THROW({t.getRoot()->getParent();}, std::out_of_range);
    EXPECT_EQ(t.getRoot()->getLeft()->getParent()->getValue().first, 2.23);
    EXPECT_EQ(t.getRoot()->getRight()->getParent()->getValue().first, 2.23);
    EXPECT_EQ(t.getRoot()->getRight()->getRight()->getParent()->getValue().first, 3.5);
    EXPECT_EQ(t.getRoot()->getRight()->getRight()->getParent()->getParent()->getValue().first, 2.23);
    EXPECT_EQ(t.getRoot()->getLeft()->getLeft()->getParent()->getValue().first, 1.5);
    EXPECT_EQ(t.getRoot()->getLeft()->getLeft()->getParent()->getParent()->getValue().first, 2.23);
}

TEST(s21_BinaryTree_test, test_init){
    s21::BinaryTree<int, true> b;
    EXPECT_EQ(b.empty(), true);
}

TEST(s21_BinaryTree_test, test_iterator_begin_end){
    s21::BinaryTree<int, true> b;
    auto iter = b.begin();
    EXPECT_EQ(iter == b.end(), true);
    EXPECT_EQ(iter != b.end(), false);
    EXPECT_THROW({++iter;}, std::out_of_range);
    EXPECT_THROW({*iter;}, std::out_of_range);   
    EXPECT_THROW({--iter;}, std::out_of_range);
}

TEST(s21_BinaryTree_test, test_iterator){
    //       4
    //     2   5
    //    1 3    7
    //          6 8
    //         5.5
    
    s21::BinaryTree<double, true> b{4};
    std::pair<s21::BinaryTree<double, true>::iterator, bool> insert2 = b.insert(2);
    std::pair<s21::BinaryTree<double, true>::iterator, bool> insert5 = b.insert(5);
    std::pair<s21::BinaryTree<double, true>::iterator, bool> insert1 = b.insert(1);
    std::pair<s21::BinaryTree<double, true>::iterator, bool> insert3 = b.insert(3);
    
    std::pair<s21::BinaryTree<double, true>::iterator, bool> insert7 = b.insert(7);
    
    std::pair<s21::BinaryTree<double, true>::iterator, bool> insert6 = b.insert(6);
    
    std::pair<s21::BinaryTree<double, true>::iterator, bool> insert8 = b.insert(8);
    
    std::pair<s21::BinaryTree<double, true>::iterator, bool> insert55 = b.insert(5.5);
    
    std::pair<s21::BinaryTree<double, true>::iterator, bool> insert6_second_time = b.insert(6); //не добавится
    
    EXPECT_EQ(*(insert2.first), 2);
    EXPECT_EQ(insert2.second, true);
    EXPECT_EQ(*(insert5.first), 5);
    EXPECT_EQ(insert5.second, true);
    EXPECT_EQ(*(insert1.first), 1);
    EXPECT_EQ(insert1.second, true);
    EXPECT_EQ(*(insert3.first), 3);
    EXPECT_EQ(insert3.second, true);
    EXPECT_EQ(*(insert7.first), 7);
    EXPECT_EQ(insert7.second, true);
    EXPECT_EQ(*(insert6.first), 6);
    EXPECT_EQ(insert6.second, true);
    EXPECT_EQ(*(insert8.first), 8);
    EXPECT_EQ(insert8.second, true);
    EXPECT_EQ(*(insert55.first), 5.5);
    EXPECT_EQ(insert55.second, true);
    EXPECT_EQ(*(insert6_second_time.first), 6);
    EXPECT_EQ(insert6_second_time.second, false);

    EXPECT_EQ(b.getRoot()->getValue(), 4);
    EXPECT_EQ(b.getRoot()->getLeft()->getValue(), 2);
    EXPECT_EQ(b.getRoot()->getLeft()->getLeft()->getValue(), 1);
    EXPECT_EQ(b.getRoot()->getLeft()->getRight()->getValue(), 3);
    EXPECT_EQ(b.getRoot()->getRight()->getValue(), 5);
    EXPECT_EQ(b.getRoot()->getRight()->getRight()->getValue(), 7);
    EXPECT_EQ(b.getRoot()->getRight()->getRight()->getLeft()->getValue(), 6);
    EXPECT_EQ(b.getRoot()->getRight()->getRight()->getLeft()->getLeft()->getValue(), 5.5);
    EXPECT_EQ(b.getRoot()->getRight()->getRight()->getRight()->getValue(), 8);

    EXPECT_EQ(b.size(), 9);

    auto iter = b.begin();
    
    double nums[] {1, 2, 3, 4, 5, 5.5, 6, 7, 8};
    for (int i=0; i<9; i++){
        EXPECT_EQ(*iter, nums[i]);
        ++iter;
    }
    EXPECT_THROW({++iter;}, std::out_of_range);
    int i = 0;
    for (auto &elem : b){
        EXPECT_EQ(elem, nums[i]);
        i++;
    };

    
    // *end()
    EXPECT_THROW({*iter;}, std::out_of_range);
    --iter;
    --i;
    for (; iter!=b.begin(); --iter, --i){
        EXPECT_EQ(*iter, nums[i]);
    }
    EXPECT_EQ(*iter, 1);
    EXPECT_THROW({--iter;}, std::out_of_range);

    // std::cout << (iter) << '\n';
}


TEST(s21_BinaryTree_test, insetr_first_unique_new){
    s21::BinaryTree<std::pair<int, std::string>, true> b{std::make_pair(1, "a")};
    // b.insert(std::make_pair(1, "b"));
    // for (auto v : b){
    //     std::cout << v.first << ' ' << v.second << '\n';
    // }
    EXPECT_EQ(b.size(), 1);
}

TEST(s21_BinaryTree_test, copy_constructor){
    //       4
    //     2   5
    //    1 3    7
    //          6 8
    //         5.5
    
    s21::BinaryTree<double, true> b1{4};
    b1.insert(2);
    b1.insert(5);
    b1.insert(1);
    b1.insert(3);
    b1.insert(7);
    b1.insert(6);
    b1.insert(8);
    b1.insert(5.5);
    b1.insert(6); //Не добавиться
    s21::BinaryTree<double, true> b2{b1};
    auto iter = b1.begin();
    for (auto &value : b2){
        EXPECT_EQ(*iter, value);
        ++iter;
    }
    EXPECT_EQ(b1.size(), b2.size());

    // for (auto &value : b1){
    //     std::cout << value << '\n';
    // }
}

TEST(s21_BinaryTree_test, swap){
    //       4
    //     2   5
    //    1 3    7
    //          6 8
    //         5.5
    s21::BinaryTree<double, true> b1{4};
    b1.insert(2);
    b1.insert(5);
    b1.insert(1);
    b1.insert(3);
    b1.insert(7);
    b1.insert(6);
    b1.insert(8);
    b1.insert(5.5);

    s21::BinaryTree<double, true> b2{4};
    b1.swap(b2);

    double array[]{1,2,3,4,5,5.5,6,7,8};
    int i = 0;
    for (auto &value : b2){
        EXPECT_EQ(array[i], value);
        ++i;
    }

    EXPECT_EQ(b2.size(), 9);
    EXPECT_EQ(b1.size(), 1);
    for (auto &value : b1){
        EXPECT_EQ(value, 4);
    }
}

TEST(s21_BinaryTree_test, move_constructor_and_operator_assign){
    //       4
    //     2   5
    //    1 3    7
    //          6 8
    //         5.5
    s21::BinaryTree<double, true> b1{4};
    b1.insert(2);
    b1.insert(5);
    b1.insert(1);
    b1.insert(3);
    b1.insert(7);
    b1.insert(6);
    b1.insert(8);
    b1.insert(5.5);
    b1.insert(6); //Не добавиться

    s21::BinaryTree<double, true> b2 = std::move(b1);
    EXPECT_EQ(b1.empty(), true);
    EXPECT_EQ(b2.empty(), false);
    
    EXPECT_EQ(b1.size(), 0);
    EXPECT_EQ(b2.size(), 9);
    int i = 0;
    double array[]{1,2,3,4,5,5.5,6,7,8};
    for (auto &value : b2){
        EXPECT_EQ(array[i], value);
        ++i;
    }

    s21::BinaryTree<double, true> b3{5};
    b3.insert(3);
    b3.insert(6);
    b3.insert(10);
    b3.insert(20);
    EXPECT_EQ(b3.getRoot()->getValue(), 5);
    EXPECT_EQ(b3.getRoot()->getLeft()->getValue(), 3);
    EXPECT_EQ(b3.getRoot()->getRight()->getValue(), 6);
    EXPECT_EQ(b3.getRoot()->getRight()->getRight()->getValue(), 10);
    EXPECT_EQ(b3.getRoot()->getRight()->getRight()->getRight()->getValue(), 20);

    b3 = b2; //operator=
    i = 0;
    for (auto &value : b3){
        EXPECT_EQ(array[i], value);
        ++i;
    }
    i = 0;
    for (auto &value : b2){
        EXPECT_EQ(array[i], value);
        ++i;
    }
}

TEST(s21_BinaryTree_test, erase_with_one_subtree){
    //       4
    //     2   5
    //    1 3    7
    //          6 8
    //         5.5

    s21::BinaryTree<double, true> b1{4};
    b1.insert(2);
    b1.insert(5);
    b1.insert(1);
    b1.insert(3);
    b1.insert(7);
    b1.insert(6);
    b1.insert(8);
    b1.insert(5.5);

    auto iter = b1.begin(); //1
    b1.erase(iter); //Удаление листа слева
    iter = b1.begin();
    ++iter; //3
    b1.erase(iter); //Удаление листа справа
    EXPECT_THROW({b1.getRoot()->getLeft()->getRight();}, std::out_of_range);
    EXPECT_THROW({b1.getRoot()->getLeft()->getLeft();}, std::out_of_range);
    EXPECT_EQ(b1.size(), 7); //были удалены 2 листа


    b1.insert(0);
    //       4
    //     2   5
    //   0       7
    //          6 8
    //         5.5
    iter = ++b1.begin();
    b1.erase(iter); //2 - левый узел с левым потдеревом и родителем
    iter = b1.begin();
    EXPECT_EQ(*iter, 0);
    EXPECT_EQ(*(++iter), 4);
    EXPECT_EQ(b1.getRoot()->getLeft()->getValue(), 0);
    EXPECT_EQ(b1.getRoot()->getLeft()->getParent()->getValue(), 4);

    b1.insert(1);
    //       4
    //     0   5
    //      1    7
    //          6 8
    //         5.5
    b1.erase(b1.begin()); //0 - левый узел с правым потдеревом и родителем
    iter = b1.begin();
    EXPECT_EQ(*iter, 1);
    EXPECT_EQ(*(++iter), 4);
    EXPECT_EQ(b1.getRoot()->getLeft()->getValue(), 1);
    EXPECT_EQ(b1.getRoot()->getLeft()->getParent()->getValue(), 4);

    //       4
    //     1   5
    //           7
    //          6 8
    //         5.5
    iter = ++++b1.begin(); //  5 - правый узел с правым потдеревом и родителем
    EXPECT_EQ(*iter, 5);
    b1.erase(iter);
    iter = ++b1.begin();
    EXPECT_EQ(*iter, 4);
    EXPECT_EQ(*(++++++iter), 7);
    EXPECT_EQ(b1.getRoot()->getRight()->getValue(), 7);
    EXPECT_EQ(b1.getRoot()->getRight()->getParent()->getValue(), 4);
    EXPECT_EQ(b1.getRoot()->getRight()->getLeft()->getValue(), 6);
    EXPECT_EQ(b1.getRoot()->getRight()->getRight()->getValue(), 8);

    EXPECT_EQ(*(--b1.end()), 8);
    b1.erase(--b1.end());
    //       4
    //     1    7
    //         6
    //        5.5
    EXPECT_EQ(*(--b1.end()), 7);
    b1.erase(--b1.end()); // 7 - правый узел с левым потдеревом и родителем
    iter = --b1.end();
    EXPECT_EQ(*iter, 6);
    EXPECT_EQ(*--iter, 5.5);
    EXPECT_EQ(*--iter, 4);
    EXPECT_EQ(b1.getRoot()->getRight()->getValue(), 6);
    EXPECT_EQ(b1.getRoot()->getRight()->getParent()->getValue(), 4);
    EXPECT_EQ(b1.getRoot()->getRight()->getLeft()->getValue(), 5.5);

    // Удаление единственного листа
    s21::BinaryTree<double, true> b2{4};
    b2.erase(b2.begin());
    EXPECT_EQ(b2.size(), 0);
    EXPECT_EQ(b2.empty(), true);
    EXPECT_THROW({b2.getRoot();}, std::out_of_range);

    //Удаление корня с одним правым потдеревом
    s21::BinaryTree<double, true> b3{5};
    b3.insert(7);
    b3.insert(6);
    b3.erase(b3.begin()); //5
    // for (auto& i : b3)
    //     EXPECT_EQ(i, 7);
    iter = b3.begin();
    EXPECT_EQ(*iter, 6);
    EXPECT_EQ(*(++iter), 7);
    EXPECT_EQ(b3.size(), 2);
    EXPECT_THROW({b3.getRoot()->getParent();}, std::out_of_range);
    EXPECT_EQ(b3.getRoot()->getValue(), 7);

    //Удаление корня с одним левым потдеревом
    s21::BinaryTree<double, true> b4{5};
    b4.insert(4);
    b4.erase(++b4.begin()); //5
    for (auto& i : b4)
        EXPECT_EQ(i, 4);
    EXPECT_EQ(b4.size(), 1);
    EXPECT_THROW({b3.getRoot()->getParent();}, std::out_of_range);
    
}

TEST(s21_BinaryTree_test, erase_2_subtree){
    //       4
    //     2   5
    //    1 3      7
    //          6    8
    //           6.5

    s21::BinaryTree<double, true> b1{4};
    b1.insert(2);
    b1.insert(5);
    b1.insert(1);
    b1.insert(3);
    b1.insert(7);
    b1.insert(6);
    b1.insert(8);
    b1.insert(6.5);

    auto iter = ----b1.end(); //7 - 
    EXPECT_EQ(*iter, 7);
    b1.erase(iter);
    double a[]{1, 2, 3, 4, 5, 6, 6.5, 8};
    int i = 0;
    for (auto value : b1){
        EXPECT_EQ(value, a[i]);
        ++i;
    }
    i = 7;
    for (auto iter = --b1.end(); iter!=b1.begin(); --iter, --i){
        EXPECT_EQ(*iter, a[i]);
    }

    //       4
    //     2   5
    //    1 3     8
    //          6    
    //           6.5
    iter = ++b1.begin();
    EXPECT_EQ(*iter, 2); //2 - узел c двумя листьями
    b1.erase(iter);
    double a2[]{1, 3, 4, 5, 6, 6.5, 8};
    i = 0;
    for (auto value : b1){
        EXPECT_EQ(value, a2[i]);
        ++i;
    }

    //       4
    //     3   5
    //    1      8
    //          6    
    //           6.5
    iter = ++++b1.begin();
    EXPECT_EQ(*iter, 4); //4 - корень c двумя потдеревьями
    b1.erase(iter);
    double a3[]{1, 3, 5, 6, 6.5, 8};
    i = 0;
    for (auto value : b1){
        EXPECT_EQ(value, a3[i]);
        ++i;
    }
    EXPECT_EQ(b1.getRoot()->getValue(), 5);

    b1.insert(5.5);
    //       5
    //     3     8
    //    1     6 
    //       5.5   6.5    

    b1.erase(++++b1.begin());
    double a4[]{1, 3, 5.5, 6, 6.5, 8};
    i = 0;
    for (auto value : b1){
        EXPECT_EQ(value, a4[i]);
        ++i;
    }
    EXPECT_EQ(b1.getRoot()->getValue(), 5.5);
    EXPECT_EQ(b1.size(), 6);
}

// TEST(s21_BinaryTree_test, erase_with_pair){
//     s21::BinaryTree<std::pair<const int, char>> b1{{1, 'a'}};
//     b1.insert({2, 'b'});
//     b1.insert({3, 'c'});
//     auto iter = b1.begin();
//     b1.erase(iter);
//     EXPECT_EQ((*b1.begin()).first, 2);
//     EXPECT_EQ(b1.size(), 2);
// }

TEST(s21_BinaryTree_test, merge){
    s21::BinaryTree<double, true> b1{4};
    b1.insert(2);
    b1.insert(5);
    s21::BinaryTree<double, true> b2{4}; //Не добавиться при merge
    b2.insert(1);
    b2.insert(3);
    b2.insert(7);
    b2.insert(6);
    b2.insert(8);
    b2.insert(5.5);
    b2.insert(2); //Не добавиться при merge
    b1.merge(b2);


    EXPECT_EQ(b1.size(), 9);
    double array[]{1,2,3,4,5,5.5,6,7,8};
    int i = 0;
    for (auto &value : b1){
        EXPECT_EQ(array[i], value);
        ++i;
    }
}

TEST(s21_BinaryTree_test, find){
    s21::BinaryTree<double, true> b1{4};
    b1.insert(2);
    b1.insert(5);
    b1.insert(1);
    b1.insert(3);
    b1.insert(7);
    b1.insert(6);
    b1.insert(8);
    b1.insert(5.5);
    EXPECT_EQ(*(b1.find(5.5)), 5.5);
    EXPECT_EQ(*(b1.find(4)), 4);
    EXPECT_EQ(*(b1.find(7)), 7);
    EXPECT_EQ(*(b1.find(7)), 7);
    EXPECT_EQ(b1.find(-100) == b1.end(), true);
}

#endif