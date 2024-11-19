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
            using value_type = std::pair<key_type,mapped_type>;
            using reference = value_type&;
            using const_reference = const value_type&;
            using iterator = typename BinaryTree<value_type, true>::iterator;
            using const_iterator = typename BinaryTree<value_type, true>::const_iterator;
            using size_type = size_t;
        private:
            BinaryTree<value_type, true> bt_;
        public:
            map();
            map(std::initializer_list<value_type> const &items);
            map(const map &m);
            map(map &&m);
            ~map();
            map& operator=(const map &m);
            T& at(const Key& key);
            T& operator[](const Key& key);
            iterator begin();
            iterator end();
            bool empty();
            size_type size();
            size_type max_size();
            void clear();
            std::pair<iterator, bool> insert(const_reference value);
            std::pair<iterator, bool> insert(const Key& key, const T& obj);
            std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
            void erase(iterator pos);
            void swap(map& other);
            void merge(map& other);
            bool contains(const Key& key);
    };
}

//Конструктор по умолчанию
template <class Key, class T> 
s21::map<Key, T>::map():bt_() {}

//Проверка на пустоту
template <class Key, class T>
bool s21::map<Key, T>::empty(){
    return bt_.size() == 0;   
}

//Размер map
template <class Key, class T>
typename s21::map<Key, T>::size_type s21::map<Key, T>::size(){
    return bt_.size();   
}

//Максимальный размер
template <class Key, class T>
typename s21::map<Key, T>::size_type s21::map<Key, T>::max_size(){
    return std::numeric_limits<size_type>::max()/sizeof(std::pair<Key, T>);
}

//Конструктор на основе инициализатора листа (если попадается существеющий ключ, то элемент просто не добавляется)
template <class Key, class T>
s21::map<Key, T>::map(std::initializer_list<value_type> const &items): bt_(){
    for (auto &item : items)
        bt_.insert(item);
}

// Конструктор копирования
template <class Key, class T>
s21::map<Key,T>::map(const map &m): bt_(m.bt_){}

// Конструктор перемещения
template <class Key, class T>
s21::map<Key,T>::map(map &&m): bt_(std::move(m.bt_)){}

//Деструктор
template <class Key, class T>
s21::map<Key, T>::~map(){}

//=
template <class Key, class T>
s21::map<Key,T>& s21::map<Key, T>::operator=(const map& m){
    bt_ = m.bt_;
    return *this;
}

template <class Key, class T>
std::pair<typename s21::map<Key,T>::iterator, bool> s21::map<Key, T>::insert(typename s21::map<Key,T>::const_reference value){
    return bt_.insert(value);
}


template <class Key, class T>
std::pair<typename s21::map<Key,T>::iterator, bool> s21::map<Key, T>::insert(const Key& key, const T& obj){
    return bt_.insert(std::make_pair(key, obj));
}

template <class Key, class T>
std::pair<typename s21::map<Key,T>::iterator, bool> s21::map<Key, T>::insert_or_assign(const Key& key, const T& obj){
    auto ret = bt_.insert(std::make_pair(key, obj));
    if (ret.second == false)
        (*(ret.first)).second = obj;
    return ret;
}

template <class Key, class T>
void s21::map<Key, T>::merge(typename s21::map<Key,T>& other){
    bt_.merge(other.bt_);
}



//Вернуть элемент по ключу
template <class Key, class T>
T& s21::map<Key,T>::at(const Key& key){
    try{
        auto *finder = bt_.getRoot();
        //В binary tree уже есть исключение на выход за границы
        while (finder->getValue().first != key)
            finder = (key < finder->getValue().first ? finder->getLeft() : finder->getRight());
        return finder->getValue().second;
    }
    catch (const std::exception& err){ //Чтобы изменить текст сообщения дерева под map
        throw std::out_of_range("Не существующий ключ map");
    }
}

template <class Key, class T>
bool s21::map<Key,T>::contains(const Key& key){
    bool ret = true;
    try{
        at(key);
    }
    catch(const std::exception& err){
        ret = false;
    }
    return ret;
}

template <class Key, class T>
T& s21::map<Key,T>::operator[](const Key& key){
    try{
        T& ret = at(key);
        return ret;
    }
    catch(const std::exception& err){ // Если ключ не существует, то создаётся новый экземпляр и возвращается ссылка на значение(value)
        auto pair = bt_.insert(std::make_pair(key, T())); 
        return (*(pair.first)).second;
    }
}

template <class Key, class T>
void s21::map<Key,T>::clear(){
    bt_.clear();
}

template <class Key, class T>
typename s21::map<Key,T>::iterator s21::map<Key,T>::begin(){
    return bt_.begin();
}

template <class Key, class T>
typename s21::map<Key,T>::iterator s21::map<Key,T>::end(){
    return bt_.end();
}

template <class Key, class T> 
void s21::map<Key,T>::swap(map& other){
    bt_.swap(other.bt_);
}

template <class Key, class T> 
void s21::map<Key,T>::erase(iterator pos){
    bt_.erase(pos);
}
#endif