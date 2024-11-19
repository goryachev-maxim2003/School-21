#ifndef S21_MAP_TEST
#define S21_MAP_TEST

#include <string>
#include <gtest/gtest.h>
#include "../containers/map/s21_map.h"
#include <map>


TEST(s21_map, test_init) {
//   std::pair<int, int> p = std::make_pair(1,2);
//   std::pair<int, int> p2 = std::make_pair(1,1);
//   std::cout << (p == p2) << '\n';
    // std::string s1 {"hello"};
  
    // bool result {s1 == "Hello"}; // false - строки различаются по регистру
    // result = s1 > std::string("helLo"); 
    // std::cout << result;
    
    
    // std::map<int, int> mm{std::make_pair(1,2)};

    s21::map<int, double> m;
    EXPECT_EQ(m.empty(), true);
    EXPECT_EQ(m.size(), 0U);
    s21::map<int, double> m2{std::make_pair(1, 2.23), std::make_pair(2, 4.), std::make_pair(-1, 4.)};
    EXPECT_EQ(m2.size(), 3);
    EXPECT_EQ(m2.empty(), false);
}

TEST(s21_map, test_same_key){
    s21::map<int, double> m2{std::make_pair(1, 2.23), std::make_pair(1, 4.), std::make_pair(1, 45.5), std::make_pair(-1, 4.4)};
    EXPECT_EQ(m2.size(), 2);
}

TEST(s21_map, max_size){
    s21::map<int, double> s21m{std::make_pair(1, 3.5), std::make_pair(1, 2.1), std::make_pair(2, -1.1)};
    s21::map<int, std::string> s21m2{std::make_pair(1, "asdsd")};
    EXPECT_EQ(s21m.max_size(), std::numeric_limits<std::size_t>::max()/sizeof(std::pair<int, double>));
    EXPECT_EQ(s21m2.max_size(), std::numeric_limits<std::size_t>::max()/sizeof(std::pair<int, std::string>));
    EXPECT_EQ(s21m2.empty(), false);
}

TEST(s21_map, at){
    s21::map<double, std::string> m{std::make_pair(1.5, "ok"), std::make_pair(3.5, "yes"), std::make_pair(4.5, "no"), std::make_pair(0, "left"), std::make_pair(-33.42, "too left")};
    EXPECT_EQ(m.at(1.5), "ok");
    EXPECT_EQ(m.at(3.5), "yes");
    EXPECT_EQ(m.at(4.5), "no");
    EXPECT_EQ(m.at(0), "left");
    EXPECT_EQ(m.at(-33.42), "too left");
    EXPECT_THROW({m.at(10000000);}, std::out_of_range);
    EXPECT_EQ(m[1.5], "ok");
    EXPECT_EQ(m[3.5], "yes");
    EXPECT_EQ(m[4.5], "no");
    EXPECT_EQ(m[0], "left");
    EXPECT_EQ(m[-33.42], "too left");
    m[1.5] = "not ok";
    m.at(3.5) = "YES!";
    EXPECT_EQ(m.at(1.5), "not ok");
    EXPECT_EQ(m[3.5], "YES!");
    EXPECT_EQ(m.empty(), false);
    EXPECT_EQ(m.size(), 5);
    
    m[-2] = "Minus2";
    EXPECT_EQ(m.at(-2), "Minus2");
    m.clear();
    EXPECT_EQ(m.empty(), true);
    EXPECT_EQ(m.size(), 0);
}

TEST(s21_map, contains){
    s21::map<double, char> m;
    EXPECT_EQ(m.contains(34.5), false);
    s21::map<double, char> m2{std::make_pair(43.4, 'n')};
    EXPECT_EQ(m2.contains(34.5), false);
    EXPECT_EQ(m2.contains(43.4), true);
}

TEST(s21_map, iterator){
    //       4
    //     2   5
    //    1 3   
    //   0       
    
    s21::map<int, char> m{{4, 'a'}, {2, 'b'}, {5, 'c'}, {1, 'd'}, {3, 'e'}, {0, 'f'}};
    std::pair<int, char> a[]{{0, 'f'}, {1, 'd'}, {2, 'b'}, {3, 'e'}, {4, 'a'}, {5, 'c'}};

    int i = 0;
    for (auto &value : m){
        EXPECT_EQ(value.first, a[i].first);
        EXPECT_EQ(value.second, a[i].second);
        i++;
    }
}

TEST(s21_map, copy_constructor){
    s21::map<int, char> m{{4, 'a'}, {2, 'b'}, {5, 'c'}, {1, 'd'}, {3, 'e'}, {0, 'f'}};
    s21::map<int, char> m2{m};
    EXPECT_EQ(m[4], 'a');
    EXPECT_EQ(m[2], 'b');
    EXPECT_EQ(m[5], 'c');
    EXPECT_EQ(m[1], 'd');
    EXPECT_EQ(m[3], 'e');
    EXPECT_EQ(m[0], 'f');
    
    EXPECT_EQ(m2[4], 'a');
    EXPECT_EQ(m2[2], 'b');
    EXPECT_EQ(m2[5], 'c');
    EXPECT_EQ(m2[1], 'd');
    EXPECT_EQ(m2[3], 'e');
    EXPECT_EQ(m2[0], 'f');

    EXPECT_EQ(m.size(), m2.size());
    EXPECT_EQ(m.empty(), m2.empty());
}

TEST(s21_map, swap){
    s21::map<int, char> m1{{4, 'a'}, {2, 'b'}};
    s21::map<int, char> m2{{3, 'a'}};

    m2.swap(m1);

    for (auto &v : m1){
        EXPECT_EQ(v.first, 3);
        EXPECT_EQ(v.second, 'a');
    }

    auto iter = m2.begin();
    EXPECT_EQ((*iter).first, 2);
    EXPECT_EQ((*iter).second, 'b');
    ++iter;
    EXPECT_EQ((*iter).first, 4);
    EXPECT_EQ((*iter).second, 'a');
    (*iter).second = 'x';
    EXPECT_EQ((*iter).first, 4);
    EXPECT_EQ((*iter).second, 'x');

    EXPECT_EQ(m1.size(), 1);
    EXPECT_EQ(m2.size(), 2);

}

TEST(s21_map, move_constructor_and_operator_assign){
    s21::map<int, char> m{{4, 'a'}, {2, 'b'}, {5, 'c'}, {1, 'd'}, {3, 'e'}, {0, 'f'}};
    s21::map<int, char> m2 = std::move(m);
    EXPECT_EQ(m.empty(), true);
    EXPECT_EQ(m2.empty(), false);
    
    EXPECT_EQ(m.size(), 0);
    EXPECT_EQ(m2.size(), 6);
    int i = 0;
    double keys[]{0, 1, 2, 3, 4, 5};
    double values[]{'f', 'd', 'b', 'e', 'a', 'c'};
    for (auto &value : m2){
        EXPECT_EQ(keys[i], value.first);
        EXPECT_EQ(values[i], value.second);
        ++i;
    }


    //operator=
    s21::map<int, char> m3{{1, 'x'}, {3, 'y'}};
    m3 = m2;
    i = 0;
    for (auto &value : m3){
        EXPECT_EQ(keys[i], value.first);
        EXPECT_EQ(values[i], value.second);
        ++i;
    }
    EXPECT_EQ(m3.size(), 6);
    m3[0] = 'x';
    EXPECT_EQ(m3[0], 'x');
    EXPECT_EQ(m2[0], 'f');
}

TEST(s21_map, insert){
    s21::map<int, char> m{{4, 'a'}, {2, 'b'}};
    auto res = m.insert({5, 'c'});
    EXPECT_EQ(res.second, true);
    EXPECT_EQ((*(res.first)).first, 5);
    EXPECT_EQ((*(res.first)).second, 'c');
    res = m.insert({4, 'd'});
    EXPECT_EQ(res.second, false);
    EXPECT_EQ((*(res.first)).first, 4);
    EXPECT_EQ((*(res.first)).second, 'a');
}

TEST(s21_map, insert_key_obj){
    s21::map<int, char> m{{4, 'a'}, {2, 'b'}};
    auto res = m.insert(5, 'c');
    EXPECT_EQ(res.second, true);
    EXPECT_EQ((*(res.first)).first, 5);
    EXPECT_EQ((*(res.first)).second, 'c');
    res = m.insert(4, 'd');
    EXPECT_EQ(res.second, false);
    EXPECT_EQ((*(res.first)).first, 4);
    EXPECT_EQ((*(res.first)).second, 'a');
}

TEST(s21_map, insert_or_assign){
    s21::map<int, char> m{{4, 'a'}, {2, 'b'}};
    auto res = m.insert_or_assign(5, 'c');
    EXPECT_EQ(res.second, true);
    EXPECT_EQ((*(res.first)).first, 5);
    EXPECT_EQ((*(res.first)).second, 'c');
    res = m.insert_or_assign(4, 'd');
    EXPECT_EQ(res.second, false);
    EXPECT_EQ((*(res.first)).first, 4);
    EXPECT_EQ((*(res.first)).second, 'd');
}

TEST(s21_map, erase){
    s21::map<int, char> m{{4, 'a'}, {6, 'b'}, {5, 'c'}};
    auto iter = m.begin();
    ++iter;
    EXPECT_EQ((*iter).first, 5);
    m.erase(iter);
    EXPECT_EQ(m.size(), 2);
    iter = m.begin();
    EXPECT_EQ((*iter).first, 4);   
    EXPECT_EQ((*iter).second, 'a');   
    ++iter;
    EXPECT_EQ((*iter).first, 6);   
    EXPECT_EQ((*iter).second, 'b');   
}

TEST(s21_map, merge){
    s21::map<int, std::string> ma{{1, "apple"}, {5, "pear"}, {10, "banana"}};
    s21::map<int, std::string> mb{{2, "zorro"}, {4, "batman"}, {5, "X"}, {8, "alpaca"}};
    s21::map<int, std::string> u{};
    u.merge(ma);
    EXPECT_EQ(ma.size(), 0);
    u.merge(mb);
    EXPECT_EQ(mb.size(), 1);
    EXPECT_EQ(mb.at(5), "X");
    EXPECT_EQ(u.size(), 6);

    int a1[] = {1, 2, 4, 5, 8, 10};
    std::string a2[] = {"apple", "zorro", "batman", "pear", "alpaca", "banana"};
    int i = 0;
    for (auto& kv : u){
        EXPECT_EQ(kv.first, a1[i]);
        EXPECT_EQ(kv.second, a2[i]);
        ++i;
    }
}

#endif