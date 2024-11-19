#ifndef S21_SET_TEST
#define S21_SET_TEST

#include <string>
#include <gtest/gtest.h>
#include "../containers/set/s21_set.h"


TEST(s21_set, test_init) {
    s21::set<int> m;
    EXPECT_EQ(m.empty(), true);
    EXPECT_EQ(m.size(), 0U);
    s21::set<int> m2{1, 2, -1};
    EXPECT_EQ(m2.size(), 3);
    EXPECT_EQ(m2.empty(), false);
}

TEST(s21_set, test_with_pair){
    s21::set<std::pair<int, double>> m2{std::make_pair(1, 2.23), std::make_pair(1, 2.23), std::make_pair(1, 4.), std::make_pair(1, 45.5), std::make_pair(-1, 4.4)};
    EXPECT_EQ(m2.size(), 4);
}

TEST(s21_set, max_size){
    s21::set<double> s21m{3.5, 2.1, -1.1};
    s21::set<std::string> s21m2{"asdsd"};
    EXPECT_EQ(s21m.max_size(), std::numeric_limits<std::size_t>::max()/sizeof(double));
    EXPECT_EQ(s21m2.max_size(), std::numeric_limits<std::size_t>::max()/sizeof(std::string));
    EXPECT_EQ(s21m2.empty(), false);
}

TEST(s21_set, contains){
    s21::set<double> m;
    EXPECT_EQ(m.contains(34.5), false);
    s21::set<double> m2{43.4};
    EXPECT_EQ(m2.contains(34.5), false);
    EXPECT_EQ(m2.contains(43.4), true);
}

TEST(s21_set, iterator){
    //       4
    //     2   5
    //    1 3   
    //   0       
    
    s21::set<char> m{'f','d','b','e','a','c'};
    char a[]{'a', 'b', 'c', 'd', 'e', 'f'};

    int i = 0;
    for (auto &value : m){
        EXPECT_EQ(value, a[i]);
        i++;
    }
}

TEST(s21_set, copy_constructor){
    s21::set<char> m{'f','d','b','e','a','c'};
    s21::set<char> m2{m};
    
    char a[] {'a','b','c','d','e','f'};
    int i = 0;
    for (auto v : m){
        EXPECT_EQ(v, a[i]);
        ++i;
    }
    i = 0;
    for (auto v : m2){
        EXPECT_EQ(v, a[i]);
        ++i;
    }

    EXPECT_EQ(m.size(), m2.size());
    EXPECT_EQ(m.empty(), m2.empty());
}

TEST(s21_set, swap){
    s21::set<int> m1{4, 2};
    s21::set<int> m2{3};

    m2.swap(m1);

    for (auto &v : m1)
        EXPECT_EQ(v, 3);

    auto iter = m2.begin();
    EXPECT_EQ((*iter), 2);
    ++iter;
    EXPECT_EQ((*iter), 4);
    EXPECT_EQ(m1.size(), 1);
    EXPECT_EQ(m2.size(), 2);

}

TEST(s21_set, move_constructor_and_operator_assign){
    s21::set<int> m{4, 2, 5, 1, 3, 0};
    s21::set<int> m2 = std::move(m);
    EXPECT_EQ(m.empty(), true);
    EXPECT_EQ(m2.empty(), false);
    
    EXPECT_EQ(m.size(), 0);
    EXPECT_EQ(m2.size(), 6);
    int i = 0;
    double keys[]{0, 1, 2, 3, 4, 5};
    for (auto &value : m2){
        EXPECT_EQ(keys[i], value);
        ++i;
    }


    //operator=
    s21::set<int> m3{1, 3};
    m3 = m2;
    i = 0;
    for (auto &value : m3){
        EXPECT_EQ(keys[i], value);
        ++i;
    }
    EXPECT_EQ(m3.size(), 6);
}

TEST(s21_set, insert){
    s21::set<char> m{'b', 'c'};
    auto res = m.insert('a');
    EXPECT_EQ(res.second, true);
    EXPECT_EQ(*(res.first), 'a');
    res = m.insert('a');
    EXPECT_EQ(res.second, false);
    EXPECT_EQ(*(res.first), 'a');
}

TEST(s21_set, erase){
    s21::set<int> m{4, 6, 5};
    auto iter = m.begin();
    ++iter;
    EXPECT_EQ(*iter, 5);
    m.erase(iter);
    EXPECT_EQ(m.size(), 2);
    iter = m.begin();
    EXPECT_EQ(*iter, 4);   
    ++iter;
    EXPECT_EQ(*iter, 6);   
}

TEST(s21_set, merge){
    s21::set<double> ma{{0}, {3}, {4}};
    s21::set<double> mb{{1}, {2}, {5}, {4}};
    s21::set<double> u{};
    u.merge(ma);
    EXPECT_EQ(ma.size(), 0);
    u.merge(mb);
    EXPECT_EQ(mb.size(), 1);
    EXPECT_EQ(*(u.find(5)), 5);
    EXPECT_EQ(u.size(), 6);

    int a1[] = {0, 1, 2, 3, 4, 5};
    int i = 0;
    for (auto& v : u){
        EXPECT_EQ(v, a1[i]);
        ++i;
    }
}

#endif