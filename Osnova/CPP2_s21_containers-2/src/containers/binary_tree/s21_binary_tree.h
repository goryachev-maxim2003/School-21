#ifndef S21_BINARY_TREE_H
#define S21_BINARY_TREE_H

namespace s21{
    template <class T>
    class BinaryTree
    {
    private:
        T value;
        BinaryTree* left;
        BinaryTree* right;
    public:
        // using iterator = 
        // using const_iterator = 
        BinaryTree(const T& Tvalue);
        ~BinaryTree();
        void insert(const T& Tvalue);
        T& getValue();
        BinaryTree* getLeft();
        BinaryTree* getRight();
    };
}
template <class T>
s21::BinaryTree<T>::BinaryTree(const T& Tvalue) : value(Tvalue), left(nullptr), right(nullptr){}

template <class T>
void s21::BinaryTree<T>::insert(const T& Tvalue){
    //Идём в левое потдерево
    if (Tvalue < value){
        //Если пусто, то останавливаемся
        if (left == nullptr) left = new BinaryTree<T>(Tvalue);
        else left->insert(Tvalue);
    }
    //Идём в правое потдерево
    else{ //Tvalue >= value
        if (right == nullptr) right = new BinaryTree<T>(Tvalue);
        else right->insert(Tvalue);
    }

}

template <class T>
s21::BinaryTree<T>::~BinaryTree(){
    //Удаляем всё, так как деструкторы созданных через new объектов не будут вызваться автоматически
    if (left != nullptr) {
        delete left; // вызвается деструктор для left и чистится память
    }
    if (right != nullptr) {
        delete right; // вызвается деструктор для right и чистится память
    }

}

template <class T>
T& s21::BinaryTree<T>::getValue(){
    return value;
}

template <class T>
s21::BinaryTree<T>* s21::BinaryTree<T>::getLeft(){
    if (left == nullptr)
        throw std::out_of_range("Переход на пустую ветку");
    else
        return left;
}

template <class T>
s21::BinaryTree<T>* s21::BinaryTree<T>::getRight(){
    if (right == nullptr)
        throw std::out_of_range("Переход на пустую ветку");
    else
        return right;
}

#endif