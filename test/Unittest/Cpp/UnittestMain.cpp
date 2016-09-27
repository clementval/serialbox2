//===-- Unittest/Cpp/UnittestMain.cpp -----------------------------------------------*- C++ -*-===//
//
//                                    S E R I A L B O X
//
// This file is distributed under terms of BSD license.
// See LICENSE.txt for more information
//
//===------------------------------------------------------------------------------------------===//
//
/// \file
/// This file sets-up GTest and parses command-line arguments.
///
//===------------------------------------------------------------------------------------------===//

#include "serialbox/Core/Logging.h"
#include "Utility/UnittestEnvironment.h"
#include <boost/filesystem.hpp>
#include <gtest/gtest.h>

using namespace serialbox;

int main(int argc, char *argv[]) {

  // Initialize gtest
  testing::InitGoogleTest(&argc, argv);

  // Initialize glog
  Logging::init(argv[0], true);
  Logging::setLogToStderr(true);
  Logging::setMinLogLevel(serialbox::Logging::Warning);
  Logging::setColorLogToStdErr(true);
  Logging::setStdErrThreshold(Logging::Error);

  // Register test environment
  testing::AddGlobalTestEnvironment(&unittest::UnittestEnvironment::getInstance());

  return RUN_ALL_TESTS();
}
