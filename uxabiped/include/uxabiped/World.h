///
/// @file    World.h
/// @author  nvtienanh
///

#ifndef PROJECT_UXA_BIPED_WORLD_H
#define PROJECT_UXA_BIPED_WORLD_H

/// @brief    A class demo
/// File World.h includes some fucntion for demo UXA Biped demo class
/// @author  	nvtienanh
namespace UXA {
namespace biped{

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

} // namespace biped
} // namespace UXA

#endif // PROJECT_UXA_BIPED_WORLD_H
