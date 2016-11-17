///
/// @file    World.h
/// @author  nvtienanh
///

#ifndef PROJECT_TEMPLATE_C_HELLO_WORLD_H
#define PROJECT_TEMPLATE_C_HELLO_WORLD_H

/// @brief    Here you put a short description of the namespace
/// Extended documentation for this namespace
/// @author  	nvtienanh
namespace ProjectTemplate {
namespace ProjC {

/// @brief   Here you put a short description of the class
/// Extended documentation for this class.
/// @author 	nvtienanh
class World {
public:

  /// @brief   Greets the caller
  /// @author 	nvtienanh
  /// @brief	Simple hello world
  void greet();

  /// @brief   Returns the value passed to it
  /// Longer description that is useless here.
  /// @author 	nvtienanh
  /// @param n (In) input number.
  /// @return Returns the input number given.
  int returnsN(int n);
};

} // namespace Hello
} // namespace ProjectTemplate

#endif // PROJECT_TEMPLATE_C_HELLO_WORLD_H
