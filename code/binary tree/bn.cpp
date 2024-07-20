#include "bc.hpp"

int main() {
  binary_tree<int> binTree;
  binTree.create_left(10);
  binTree.get_left()->create_right(30);
  tree_node<int>* lbranch = save_branch(binTree.get_left());
  binTree.destroy_left();
  binTree.add_left(lbranch);
  return 0;
}