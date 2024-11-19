#ifndef S21_set_H
#define S21_set_H

#include "../binary_tree/s21_binary_tree.h"

#include <iostream>
#include <initializer_list>
#include <utility>
#include <string>
namespace s21{
    template <class Key>
    class set
    {   
        public:
            using key_type = Key;
            using value_type = Key;
            using reference = Key&;
            using const_reference = const Key&;
            using iterator = typename BinaryTree<value_type, false>::iterator;
            using const_iterator = typename BinaryTree<value_type, false>::const_iterator;
            using size_type = size_t;
        private:
            BinaryTree<value_type, false> bt_;
        public:
            set();
            set(std::initializer_list<value_type> const &items);
            set(const set &s);
            set(set &&s);
            ~set();
            set& operator=(const set &s);
            iterator begin();
            iterator end();
            bool empty();
            size_type size();
            size_type max_size();
            void clear();
            std::pair<iterator, bool> insert(const_reference value);
            void erase(iterator pos);
            void swap(set& other);
            void merge(set& other);
            bool contains(const Key& key);
            iterator find(const Key& key);
    };
}

//Конструктор по умолчанию
template <class Key> 
s21::set<Key>::set():bt_() {}

//Проверка на пустоту
template <class Key>
bool s21::set<Key>::empty(){
    return bt_.size() == 0;   
}

//Размер set
template <class Key>
typename s21::set<Key>::size_type s21::set<Key>::size(){
    return bt_.size();   
}

//Максимальный размер
template <class Key>
typename s21::set<Key>::size_type s21::set<Key>::max_size(){
    return std::numeric_limits<size_type>::max()/sizeof(value_type);
}

//Конструктор на основе инициализатора листа (если попадается существеющий ключ, то элемент просто не добавляется)
template <class Key>
s21::set<Key>::set(std::initializer_list<value_type> const &items): bt_(){
    for (auto &item : items)
        bt_.insert(item);
}

// Конструктор копирования
template <class Key>
s21::set<Key>::set(const set &m): bt_(m.bt_){}

// Конструктор перемещения
template <class Key>
s21::set<Key>::set(set &&m): bt_(std::move(m.bt_)){}

//Деструктор
template <class Key>
s21::set<Key>::~set(){}

//=
template <class Key>
s21::set<Key>& s21::set<Key>::operator=(const set& m){
    bt_ = m.bt_;
    return *this;
}

template <class Key>
std::pair<typename s21::set<Key>::iterator, bool> s21::set<Key>::insert(typename s21::set<Key>::const_reference value){
    return bt_.insert(value);
}

template <class Key>
void s21::set<Key>::merge(typename s21::set<Key>& other){
    bt_.merge(other.bt_);
}

template <class Key>
void s21::set<Key>::clear(){
    bt_.clear();
}

template <class Key>
typename s21::set<Key>::iterator s21::set<Key>::begin(){
    return bt_.begin();
}

template <class Key>
typename s21::set<Key>::iterator s21::set<Key>::end(){
    return bt_.end();
}

template <class Key> 
void s21::set<Key>::swap(set& other){
    bt_.swap(other.bt_);
}

template <class Key> 
void s21::set<Key>::erase(iterator pos){
    bt_.erase(pos);
}

template <class Key>
bool s21::set<Key>::contains(const Key& key){
    bool ret = true;
    try{
        auto *finder = bt_.getRoot();
        //В binary tree уже есть исключение на выход за границы
        while (finder->getValue() != key)
            finder = (key < finder->getValue() ? finder->getLeft() : finder->getRight());
        ret = true;
    }
    catch (const std::exception& err){ //Чтобы изменить текст сообщения дерева под map
        ret = false;
    }
    return ret;
}

template <class Key>
typename s21::set<Key>::iterator s21::set<Key>::find(const Key& key){
    return bt_.find(key);
}


#endif