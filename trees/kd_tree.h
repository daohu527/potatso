#pragma once

#include <vector>

#include "common/vector.h"

namespace potatso {
namespace trees {

using potatso::common::Vector2D;


struct TreeNode {
  TreeNode *left;
  TreeNode *right;
  Vector2D val;
};


class KdTree {
 public:
  void BuildTree(const std::vector<Vector2D> &nodes);

  void Add(TreeNode *node);

  void Delete(TreeNode *node);

  bool FindNearestNode(TreeNode *node, double distance, TreeNode *nearest_node);

 private:
  TreeNode *root_;
};

} // namespace trees
} // namespace potatso
