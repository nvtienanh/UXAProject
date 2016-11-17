///
/// @file    Student.cpp
/// @author  nvtienanh
///

#include "ProjC/Student.h"

#include <iostream>

namespace ProjectTemplate {
namespace ProjC {

void Student::display(){
    std::cout << "A student with name " << this->name << std::endl;
}

} // namespace ProjC
} // namespace ProjectTemplate
