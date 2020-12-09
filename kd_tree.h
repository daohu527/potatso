#pragma once

#include "common.h"

namespace trees {

template<typename T>
struct TreeNode {
  TreeNode *left;
  TreeNode *right;
  T val;
};

template<typename T>
class KdTree {
 public:
  void BuildTree(const std::vector<TreeNode<T>>& nodes);

  void Add(TreeNode<T>* node);

  void Del(TreeNode<T>* node);

  bool FindClosestNodes(TreeNode<T>* node, double distance, 
                        std::vector<TreeNode<T>>& nodes);

 private:
  TreeNode<T> *root_;
};


} // namespace trees
