#ifndef CPP_CONTAINERS_S21_AVL_TREE_H_
#define CPP_CONTAINERS_S21_AVL_TREE_H_

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <list>
#include <queue>
namespace s21 {

template <typename K, typename V>
struct Node {
  Node() : key(0), value(0), height(0){};
  Node(K o_key, V o_value, int o_height)
      : key{o_key}, value{o_value}, height{o_height} {};

  Node<K, V>* NextNode();
  Node<K, V>* PreviousNode();

  K key;
  V value;
  int height;
  Node *parent = nullptr, *left = nullptr, *right = nullptr;
};

template <typename K, typename V>
class AvlTree {
 public:
  AvlTree() noexcept;
  explicit AvlTree(std::initializer_list<K> const& init);
  explicit AvlTree(const AvlTree& other);
  AvlTree(AvlTree&& other) noexcept;
  ~AvlTree() { Clear(); };

  Node<K, V>* Insert(const K& key, const V& value);
  void Erase(Node<K, V>*);
  Node<K, V>* Find(const K& key);
  size_t GetSize() const { return size_; };
  bool Empty() const { return !head_; };
  void Clear();

  AvlTree& operator=(const AvlTree& other) { CopyTree(head_, other.head_); };
  AvlTree& operator=(AvlTree&& other) { SwapTree(other); };

  Node<K, V>* Begin();
  Node<K, V>* End() { return head_->parent; };

  void PrintTree();

 private:
  size_t size_;
  Node<K, V>* head_;

  void DeleteNodes(Node<K, V>* node);
  Node<K, V>* InnerInsert(Node<K, V>* node, const K& key, const V& value);
  void Balance(Node<K, V>* node, int diff);
  void SwapNode(Node<K, V>* one, Node<K, V>* two);
  AvlTree& SwapTree(AvlTree<K, V>&& other_tree);
  void LeftRotate(Node<K, V>* node);
  void RightRotate(Node<K, V>* node);
  void UpdateHeight(Node<K, V>* node);
  Node<K, V>* FindExtremum(Node<K, V>* node, int balance);
  int GetHeight(const Node<K, V>* node) const;
  int GetBalance(const Node<K, V>* node) const;
  void CopyNode(Node<K, V>* node, const Node<K, V>* other_node);
  AvlTree& CopyTree(Node<K, V>* node, const Node<K, V>* other_node);
  void CreateEnd();
};
};  // namespace s21

#include "s21_avl_tree.tpp"

#endif  // CPP_CONTAINERS_S21_AVL_TREE_H_