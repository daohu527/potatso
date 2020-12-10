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
  void BuildTree(const std::vector<Vector2D> &vecs);

  void Add(TreeNode *node);

  void Delete(TreeNode *node);

  bool FindNearestNode(const Vector2D &vec, TreeNode &nearest_node);

  bool FindNodeByDistance(const Vector2D &vec, double distance, 
                          std::vector<TreeNode> &nodes);

 private:
  TreeNode *root_;
};

} // namespace trees
} // namespace potatso
