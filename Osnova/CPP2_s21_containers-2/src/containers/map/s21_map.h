#ifndef S21_MAP_H
#define S21_MAP_H

#include "../binary_tree/s21_binary_tree.h"

#include <iostream>
#include <initializer_list>
#include <utility>
#include <string>
namespace s21{
    template <class Key, class T>
    class map
    {   
        public:
            using key_type = Key;
            using mapped_type = T;
            using value_type = std::pair<const key_type,mapped_type>;
            using reference = value_type&;
            using const_reference = const value_type&;
            // using iterator = 
            // using const_iterator = 
            using size_type = size_t;
        private:
            size_t m_size;
            size_t m_capacity;
            BinaryTree<value_type> *bt;
        public:
            map();
            map(std::initializer_list<value_type> const &items);
            // map(const map &m);
            // map(map &&m)
            ~map();
            // operator=(map &&m);
            T& at(const Key& key);
            // T& operator[](const Key& key);
            // iterator begin();
            // iterator end();
            bool empty();
            size_type size();
            size_type max_size();
            // void clear();
            // std::pair<iterator, bool> insert(const value_type& value);
            // std::pair<iterator, bool> insert(const Key& key, const T& obj)
            // std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
            // void erase(iterator pos);
            // void swap(map& other);
            // void merge(map& other);
            // bool contains(const Key& key)
    };
}

template <class Key, class T> 
s21::map<Key, T>::map(): m_size(0U), m_capacity(0U), bt(nullptr) {}

template <class Key, class T>
bool s21::map<Key, T>::empty(){
    return (bt == nullptr ? true : false);   
}

template <class Key, class T>
typename s21::map<Key, T>::size_type s21::map<Key, T>::size(){
    return m_size;   
}

template <class Key, class T>
typename s21::map<Key, T>::size_type s21::map<Key, T>::max_size(){
    return m_capacity;   
}

template <class Key, class T>
s21::map<Key, T>::map(std::initializer_list<value_type> const &items){
    auto iter = items.begin();
    bt = new s21::BinaryTree(*iter);
    ++iter;
    for (; iter != items.end(); ++iter)
        bt->insert(*iter);
}

template <class Key, class T>
s21::map<Key, T>::~map(){
    delete bt;
}

template <class Key, class T>
T& s21::map<Key,T>::at(const Key& key){
    BinaryTree<value_type> *finder = bt;
    while ((*finder).value.first != key){
        //В binary tree уже есть исключение на выход за границы
        //Левое потдерево
        if (key < finder->getValue().first){
            finder = bt->getLeft();
        }
        //Правое потдерево ( >= )
        else{
            finder = bt->getRight();
        }
    }
}

#endif