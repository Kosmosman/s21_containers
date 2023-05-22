namespace s21 {

//// Constructs
    template <typename value_type>
    list<value_type>::list() {}

//    template <typename value_type>
//    list<value_type>::list(size_type n) {}
    //// insert & erase

    template <typename value_type>
    typename list<value_type>::iterator list<value_type>::insert(iterator pos,
                                                                 const_iterator value) {
        Node* active = pos.ptr_;
        Node* add = new Node(value);
        setNewValueForList(active, add);


        size_++;
        //// method in zero pool node
        return iterator(add);

    }
    //// доп func
    template <typename value_type>
   void list<value_type>::setNewValueForList(Node* active, Node* add) {
       empty() ? installationInBlankList(add) : installationNotInBlankList(active,add);
    }

    template <typename value_type>
    void list<value_type>::installationInBlankList(Node* add) {
        add->next_ = end_;
        add->prev_ = end_;
        head_ = add;
        tail_ = add;
    }
    template <typename value_type>
    void list<value_type>::installationNotInBlankList(Node* active, Node* add) {
        if (active == head_) {
            head_ = add;
        } else if (active == end_) {
            tail_ = add;
        }
        add->next_ = active;
        add->prev_ = active->prev_;
        active->prev_->next_ = add;
        active->prev_ = add;
    }

//// empty size max_size
    template <typename value_type>
    bool list<value_type>::empty() {
        return size_ == 0;
    }
    template <typename value_type>
    typename list<value_type>::size_type list<value_type>::size() {
        return size_;
    }

    //// iterator /////////////////////////////////////////////////////
template <typename value_type>
typename list<value_type>::reference list<value_type>::iterator::operator*() {
    if (!this->ptr_) {
        throw std::invalid_argument("Value is nullptr");
    }
    return this->ptr_->value_;
}
template <typename value_type>
typename list<value_type>::iterator list<value_type>::iterator::operator++(int) {
    ptr_ = ptr_->next_;
    return *this;
}
template <typename value_type>
typename list<value_type>::iterator list<value_type>::iterator::operator--(int) {
    ptr_ = ptr_->prev_;
    return *this;
}
template <typename value_type>
typename list<value_type>::iterator& list<value_type>::iterator::operator++() {
    ptr_ = ptr_->next_;
    return *this;
}
template <typename value_type>
typename list<value_type>::iterator& list<value_type>::iterator::operator--() {
    ptr_ = ptr_->prev_;
    return *this;
}

template <typename value_type>
bool list<value_type>::iterator::operator==(ListIterator other) {
    return this->ptr_ == other.ptr_;
}

template <typename value_type>
bool list<value_type>::iterator::operator!=(ListIterator other) {
    return this->ptr_ != other.ptr_;
}

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::const_iterator::operator*() const {
    return ListIterator::operator*();
}

//    list<value_type>::reference list<value_type>::iterator::

template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() {
    if (head_) {
        return iterator(head_);
    } else {
        return iterator(end_);
    }
//     return iterator(end_->next_);
//    return !head_ ? iterator(end_) : iterator(head_);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() {
    return iterator(end_);
}
};