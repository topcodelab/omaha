// Copyright 2003-2009 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ========================================================================

// TODO(omaha): refactor to eliminate this file.

#ifndef OMAHA_COMMON_COMMONTYPES_H_
#define OMAHA_COMMON_COMMONTYPES_H_

#include "base/basictypes.h"

namespace omaha {

// ---------------------- Defines -------------------------------
// Define some variable types, so that we can change them under the hood
// easier if need be.
typedef unsigned char      uchar;

typedef uint32 flags32;
typedef uint16 time16;
typedef uint64 time64;

#define kInt32Max 2147483647
#define kUint32Max 4294967295U
#define kUint64Max 18446744073709551615U
#define kTime64Max kUint64Max


template <typename T>
inline T ABS(T val) {
  return val < (T)0 ? -val : val;
}

// Isolate some VisualC++-isms to macros for easy redefinition
#define SELECTANY __declspec(selectany)
#define DLLIMPORT __declspec(dllimport)
#define DLLEXPORT __declspec(dllexport)

// Put this around string literals that don't need to be localized
// to indicate this fact.  Note that you don't need to do this for string
// literals used in functions where they obviously don't need to be localized,
// such as REPORT(), XXX_LOG(), CHK(), ASSERT(), VERIFY(), TRACE(), dbgprint(),
// OutputDebugString(), GetProcAddress(), GetModuleHandle(), etc.
//
// For large blocks of non-localizable string literals, you can use a comment
// line including "SKIP_LOC_BEGIN" to start a non-localizable section of
// your file, and "SKIP_LOC_END" to end the section.
//
// Don't worry about NOTRANSL or the SKIP_LOC blocks in unit tests, experimental
// code, etc. as they are ignored when checking for localizable string literals.
#define NOTRANSL(x) x

}  // namespace omaha

#endif  // OMAHA_COMMON_COMMONTYPES_H_
