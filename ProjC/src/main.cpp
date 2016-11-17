///
/// @file    main.cpp
/// @author  nvtienanh
///

#include "ProjC/World.h"
#include "ProjC/Student.h"
#include "ProjC/Version.h"
#include <boost/program_options.hpp>
#include <iostream>

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
  // Arguments parsing
  po::variables_map vm;
  po::options_description desc("Allowed options");
  desc.add_options()("help,h", "Produce help message.")("version,v", "Show program name/version banner and exit.")(
    "rev", "Print the SVN revision number");
  po::store(parse_command_line(argc, argv, desc), vm);
  po::notify(vm);
  // help
  if (vm.count("help")) {
    std::cout << desc << std::endl;
    return EXIT_SUCCESS;
  }
  // version
  if (vm.count("version")) {
    std::cout << "HelloRunner version " << ProjectTemplate::ProjC::Version::getString() << std::endl;
    return EXIT_SUCCESS;
  }
  // rev
  if (vm.count("rev")) {
    std::cout << "SVN revision : " << ProjectTemplate::ProjC::Version::getRevision() << std::endl;
    return EXIT_SUCCESS;
  }

  // Actual "work"
  ProjectTemplate::ProjC::World hello;
  hello.greet();

  ProjectTemplate::ProjC::Student s("Tien");
  s.display();

  return EXIT_SUCCESS;
}
