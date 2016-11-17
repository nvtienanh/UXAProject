///
/// @file    Student.h
/// @author  Nguyen Van Tien Anh
///

#ifndef PROJECT_C_STUDENT_H
#define PROJECT_C_STUDENT_H

#include<string>

/// @brief    Here you put a short description of the namespace
/// Extended documentation for this namespace
/// @author  	nvtienanh
namespace ProjectTemplate {
namespace ProjC {

/// @brief   Here you put a short description of the class
/// Extended documentation for this class.
/// @author 	nvtienanh
class Student{
private:
        std::string name;
public:
    /// @brief   Default constructor
    /// @author  nvtienanh
    /// @brief	A default constructor
    Student(std::string name):name(name){}

    /// @brief   Display name of student
    /// @author  Tien Anh
    virtual void display();
};

} // namespace Hello
} // namespace ProjectTemplate

#endif // PROJECT_C_STUDENT_H
