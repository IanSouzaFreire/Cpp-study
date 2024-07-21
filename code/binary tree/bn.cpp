#include "bc.hpp"

int main() {
  binary_tree<int> binTree;
  
  binTree.create_left(10);
  binTree.create_right(10);
  binTree.get_left()->create_right(30);
  binTree.get_right()->create_left(30);
  
  tree_node<int>* lbranch = save_branch(binTree.get_left()); // Save part of tree
  
  binTree.destroy_left();
  binTree.add_left(lbranch); // Restore through the saved part
  
  return 0;
}