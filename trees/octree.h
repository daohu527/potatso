#pragma once


#include "common/vector.h"

namespace potatso {
namespace trees {

using potatso::common::Vector3D;


struct TreeNode {
  TreeNode *left;
  TreeNode *right;
  Vector3D val;
};


class OcTree {

};

}  // namespace trees
}  // namespace potatso