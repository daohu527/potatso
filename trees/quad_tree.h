#pragma once


#include "common/vector.h"

namespace potatso {
namespace trees {

using potatso::common::Vector2D;


struct TreeNode {
  TreeNode *left;
  TreeNode *right;
  Vector2D val;
};



class QuadTree {

};

}  // namespace trees
}  // namespace potatso