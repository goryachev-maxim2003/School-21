#ifndef S21_BINARY_TREE_H
#define S21_BINARY_TREE_H

namespace s21{
    // template <class T, bool Unique_first> 
    // class btNode;

    // Бинарное дерево
    template <class T, bool Unique_first>
    class BinaryTree{

        class btNode;
        template <bool IsConst>
        class BtIterator;
    public:
        using iterator = BtIterator<false>;
        using const_iterator = BtIterator<true>;

    private:
        btNode* root;
        size_t t_size;

        static int comporator(const T& a, const T& b){
            int ret = 0;
            //constexpr гарантирует, что код внутри блока будет выполнен только при условии, что тип T является std::pair избегая ошибок компиляции
            if constexpr (is_pair<T>::value && Unique_first){
                if (a.first > b.first)
                    ret = -1;
                else if (a.first < b.first)
                    ret = 1;
            }
            else{
                if (a > b)
                    ret = -1;
                else if (a < b)
                    ret = 1;
            }
            return ret;
        }
        
        //Структуры для определения типа pair
        //true_type и false_type - классы со статическим значнеием value = true или false
        //Используется спецификация шаблона под std::pair
        template<class T1>
        struct is_pair : std::false_type {}; 
        template<class T1, class T2>
        struct is_pair<std::pair<T1, T2>> : std::true_type {}; 

        //узел бинарного дерева 
        class btNode
        {
            friend class BinaryTree<T, Unique_first>;
        private:
            T value;
            btNode* left;
            btNode* right;
            btNode* parent;
            // void swap_node_pointer(btNode*& pa, btNode*& pb, btNode*& a, btNode*& b);
        public:
            btNode(const T& Tvalue);
            ~btNode();
            std::pair<btNode*, bool> insert(const T& Tvalue);
            void erase(btNode*& root);
            T& getValue();
            btNode* getLeft();
            btNode* getRight();
            btNode* getParent();
            bool operator==(const btNode& other);
            bool operator!=(const btNode& other);
        };

        template <bool IsConst>
        class BtIterator
        {
            friend class BinaryTree<T, Unique_first>;
        public:
            using reference = std::conditional_t<IsConst, const T&, T&>;
        private:
            btNode* root_; //Для случая если будет --end()
            btNode* current_;
            //Идёт влево до null начиная с переданной ноды, добавля их стек
            void moveLeft(btNode* node){
                while (node->left != nullptr)
                    node = node->left;
                current_ = node;
            }
            void moveRight(btNode* node){
                while (node->right != nullptr)
                    node = node->right;
                current_ = node;
            }

        public:
            BtIterator(btNode* node, btNode* root): root_(root), current_(node){}

            // BtIterator(const BtIterator& other) : nodeStack(other.nodeStack) {}
            // BtIterator(BtIterator&& other) : nodeStack(std::move(other.nodeStack)) {}
            // BtIterator& operator=(const BtIterator& other): nodeStack(other.nodeStack){ return *this;}
            // ~BtIterator() {}
            
            reference operator*() const{
                if (current_ == nullptr) 
                    throw std::out_of_range("Попытка получить значение пустого итератора");
                return current_->value;
            }
            BtIterator& operator++() {
                if (current_ == nullptr)
                    throw std::out_of_range("Выход за границы дерева");
                if (current_->right != nullptr)
                    moveLeft(current_->right);
                else{ //Идём вверх пока приходим справа, и потом ещё раз вверх
                    btNode* parent = current_->parent;
                    while (parent != nullptr && current_ == parent->right) {
                        current_ = parent;
                        parent = parent->parent;
                    }
                    current_ = parent;
                }
                return *this;
            }
            BtIterator& operator--() {
                if (root_ == nullptr) //пустое дерево, когда --end() невозможен
                    throw std::out_of_range("Выход за границы дерева");
                if (current_ == nullptr) //Если --end()
                    moveRight(root_);
                else if (current_->left != nullptr)
                    moveRight(current_->left);
                else{ //После послежнего элемента приходит в nullptr
                    btNode* parent = current_->parent;
                    while (parent != nullptr && current_ == parent->left) {
                        current_ = parent;
                        parent = parent->parent;
                    }
                    current_ = parent;
                }
                if (current_ == nullptr) //--begin()
                    throw std::out_of_range("Выход за границы дерева");
                return *this;
            }
            bool operator==(BtIterator iter) const { return current_ == iter.current_;}
            bool operator!=(BtIterator iter) const { return current_ != iter.current_;}
        };
    public:
        BinaryTree(): root(nullptr), t_size(0){}
        BinaryTree(const T& Tvalue): t_size(1) {root = new btNode(Tvalue);}
        BinaryTree(const BinaryTree& bt): BinaryTree(){
            for (auto &value : bt)
                this->insert(value);
        }
        BinaryTree(BinaryTree&& bt) : BinaryTree(){
            std::swap(t_size, bt.t_size);
            std::swap(this->root, bt.root);
        }
        ~BinaryTree(){
            delete root;
            t_size = 0;
        }
        BinaryTree<T, Unique_first> &operator=(const BinaryTree& bt){
            this->~BinaryTree();
            for (auto &value : bt)
                this->insert(value);
            return *this;
        }
        bool empty(){return t_size == 0;}
        
        std::pair<iterator, bool> insert(const T& Tvalue){ 
            std::pair<btNode*, bool> ret;
            if (t_size == 0) { //Пустое дерево
                root = new btNode(Tvalue);
                ++t_size;
                ret = std::make_pair(root, true);
            }
            else{
                ret = root->insert(Tvalue);
                if (ret.second) //Если вставка произошла увеличиваем размер
                    ++t_size;
            }
            return std::make_pair(iterator(ret.first, root), ret.second);
        }
        void clear(){  
            delete root;
            t_size = 0;
            root = nullptr;
        }


        btNode* getRoot(){
            if (root == nullptr)
                throw std::out_of_range("Дерево пустое");
            return root;
        }
        size_t size(){return t_size;}

        //Методы для работы с итератором
        iterator begin(){
            btNode* node = root;
            if (node!=nullptr)
                while (node->left != nullptr)
                    node = node->left;
            return iterator(node, root);
        }
        iterator end(){
            return iterator(nullptr, root);
        }

        const_iterator begin() const{
            btNode* node = root;
            if (node!=nullptr)
                while (node->left != nullptr)
                    node = node->left;
            return const_iterator(node, root);
        }
        const_iterator end() const{
            return const_iterator(nullptr, root);
        }

        void swap(BinaryTree& bt){
            std::swap(t_size, bt.t_size);
            std::swap(root, bt.root);
        }

        void erase(iterator pos){
            pos.current_->erase(root);
            --t_size;
        }

        // Удаляет из одного дерева, добавляя в другое
        void merge(BinaryTree& bt){
            for (auto iter = bt.begin(), old_iter = iter; iter!=end();){
                old_iter = iter; //old_iter нужен потому что erase не смещает итератор
                ++iter;
                if (this->insert(*old_iter).second) //Если вставка успешная удаляем из дерева
                    bt.erase(old_iter);
            }
        }

        iterator find(const T& value){
            auto finder = root;
            //В binary tree уже есть исключение на выход за границы
            while (finder != nullptr && finder->value != value){
                finder = (value < finder->value ? finder->left : finder->right);
            }
            return iterator(finder, root); //если finder == nullptr - то получиться end()
        }
    };
}
template <class T, bool Unique_first>
s21::BinaryTree<T, Unique_first>::btNode::btNode(const T& Tvalue) : value(Tvalue), left(nullptr), right(nullptr), parent(nullptr){}

//Вставка значения, возвращает true, если вставка осущевтилась (вставка существующего элемента не происходит)
//Вставка не происходит и возвращается false если элементы совпадают
//для std::pair Возвращает false, когда Tvalue.first совподают
template <class T, bool Unique_first>
std::pair<typename s21::BinaryTree<T, Unique_first>::btNode*, bool> s21::BinaryTree<T, Unique_first>::btNode::insert(const T& Tvalue){
    auto ret = std::make_pair(this, true);
    //comporator позволяет грамотно сравнивать std::pair
    if (comporator(Tvalue, value) == 0){ //Tvalue == value
        ret.second = false;
    }
    //Идём в левое потдерево
    else if (comporator(Tvalue, value) == 1){ //Tvalue < value
        //Если пусто, то останавливаемся
        if (left == nullptr){
            left = new btNode(Tvalue);
            left->parent = this;
            ret.first = left;
        }
        else ret = left->insert(Tvalue);
    }
    //Идём в правое потдерево
    else{ //Tvalue > value
        if (right == nullptr){
            right = new btNode(Tvalue);
            right->parent = this;
            ret.first = right;
        }
        else ret = right->insert(Tvalue);
    }
    return ret;
}

template <class T, bool Unique_first>
void s21::BinaryTree<T, Unique_first>::btNode::erase(btNode*& root){
    bool is_root = (parent == nullptr);
    bool from_left = (!is_root && this == parent->left);
    bool from_right = (!is_root && this == parent->right);
    bool has_left = (left!=nullptr);
    bool has_right = (right!=nullptr);
    if (left == nullptr || right == nullptr){ //лист или узел с одним потдеревом
        if (is_root){ // Переопределение корня
            if (has_left) root = left;
            else if (has_right) root = right;
            else root = nullptr;
        }
        else{ //Переопределение ветвей корня
            if (from_left)
                parent->left = (has_left ? left : right); //(для ветки left и right - nullptr, поэтому без разницы)
            else if (from_right)
                parent->right = (has_left ? left : right);
        }
        //Переопределение родителей у детей узла + отчистка ссылок на детей текущего узла для удаления
        if (has_left){
            left->parent = parent;
            left = nullptr;
        }
        if (has_right){
            right->parent = parent;
            right = nullptr;
        }
        //Удаление
        delete this;
    }
    else{ //Узел с двумя потдеревьями
        //Находим наименьший узел справа
        btNode* finder = right;
        while (finder->left != nullptr)
            finder = finder->left;
        //Заменяем значение текущего элемента на значение наименьшего српава, и удаляем наименьший справа узел
        //Заменяем текущий элемент на наименьший справа элемент, и удаляем наименьший справа узел
        value = finder->value; //Не рабоатает для const
        finder->erase(root);
    }
}

template <class T, bool Unique_first>
s21::BinaryTree<T, Unique_first>::btNode::~btNode(){
    //Удаляем всё, так как деструкторы созданных через new объектов не будут вызваться автоматически
    if (left != nullptr)
        delete left; // вызвается деструктор для left и чистится память
    if (right != nullptr)
        delete right; // вызвается деструктор для right и чистится память
}

template <class T, bool Unique_first>
T& s21::BinaryTree<T, Unique_first>::btNode::getValue(){
    return value;
}

template <class T, bool Unique_first>
typename s21::BinaryTree<T, Unique_first>::btNode* s21::BinaryTree<T, Unique_first>::btNode::getLeft(){
    if (left == nullptr)
        throw std::out_of_range("Переход на пустую ветку");
    else
        return left;
}

template <class T, bool Unique_first>
typename s21::BinaryTree<T, Unique_first>::btNode* s21::BinaryTree<T, Unique_first>::btNode::getRight(){
    if (right == nullptr)
        throw std::out_of_range("Переход на пустую ветку");
    else
        return right;
}

template <class T, bool Unique_first>
typename s21::BinaryTree<T, Unique_first>::btNode* s21::BinaryTree<T, Unique_first>::btNode::getParent(){
    if (parent == nullptr)
        throw std::out_of_range("Переход на пустую ветку");
    else
        return parent;
}

#endif