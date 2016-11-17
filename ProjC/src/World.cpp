///
/// @file    World.cpp
/// @author  nvtienanh
///

#include "ProjC/World.h"

#include <iostream>

namespace ProjectTemplate {
namespace ProjC {

void World::greet()
{
  std::cout << "ProjC world!!" << std::endl;
}

int World::returnsN(int n)
{

  /// \todo This is how you can markup a todo in your code that will show up in the documentation of your project.
  /// \bug This is how you annotate a bug in your code.
  return n;
}

} // namespace ProjC
} // namespace ProjectTemplate
