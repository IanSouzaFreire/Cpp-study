#pragma once

template <class T>
struct tree_node {
  T value;
  tree_node<T>* parent;
  tree_node<T>* left;
  tree_node<T>* right;

  // Constructor
  tree_node(T val) : value(val), parent(nullptr), left(nullptr), right(nullptr) {}
};

template <class T>
class binary_tree {
public:
  // Constructor
  binary_tree() : parent(nullptr), left(nullptr), right(nullptr) {}

  // Destructor
  ~binary_tree() { delete left; delete right; }

  void create_left(T value) {
    left = new binary_tree<T>();
    left->parent = this;
    left->value = value;
  }

  void create_right(T value) {
    right = new binary_tree<T>();
    right->parent = this;
    right->value = value;
  }

  binary_tree<T>* get_left() { return left; }

  binary_tree<T>* get_right() { return right; }

  binary_tree<T>* get_parent() { return parent; }

  binary_tree<T>* get_root() {
    binary_tree<T>* current = this;
    while (current->parent != nullptr) { current = current->parent; }
    return current;
  }

  T get_value() { return value; }

  void set_value(T new_value) { value = new_value; }

  void destroy_left() {
    if (left != nullptr) {
      delete left;
      left = nullptr;
    }
  }

  void destroy_right() {
    if (right != nullptr) {
      delete right;
      right = nullptr;
    }
  }

  // Add a node and it's children to the tree to the left
  void add_left(tree_node<T>* node) {
    if (node != nullptr) {
      left = new binary_tree<T>();
      left->parent = this;
      left->value = node->value;
      if (node->left != nullptr) {
        left->create_left(node->left->value);
        left->get_left()->parent = left;
      }
      if (node->right != nullptr) {
        left->create_right(node->right->value);
        left->get_right()->parent = left;
      }
    }
  }

  // Add a node and it's children to the tree to the right
  void add_right(tree_node<T>* node) {
    if (node != nullptr) {
      right = new binary_tree<T>();
      right->parent = this;
      right->value = node->value;
      if (node->left != nullptr) {
        right->create_left(node->left->value);
        right->get_left()->parent = right;
      }
      if (node->right != nullptr) {
        right->create_right(node->right->value);
        right->get_right()->parent = right;
      }
    }
  }

private:
  T value;
  binary_tree<T>* parent;
  binary_tree<T>* left;
  binary_tree<T>* right;
};

template <class T>
tree_node<T>* save_branch(binary_tree<T>* node) {
  if (node == nullptr) { return nullptr; }

  tree_node<T>* new_node = new tree_node<T>(node->get_value());

  new_node->left = save_branch(node->get_left());
  if (new_node->left!= nullptr) { new_node->left->parent = new_node; }

  new_node->right = save_branch(node->get_right());
  if (new_node->right!= nullptr) { new_node->right->parent = new_node; }

  return new_node;
}