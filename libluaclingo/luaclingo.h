// {{{ GPL License

// This file is part of gringo - a grounder for logic programs.
// Copyright (C) 2013  Roland Kaminski

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// }}}

#ifndef LUACLINGO_LUACLINGO_H
#define LUACLINGO_LUACLINGO_H

#include <clingo/script.h>

#if defined _WIN32 || defined __CYGWIN__
#   define LUACLINGO_WIN
#endif
#ifdef LUACLINGO_NO_VISIBILITY
#   define LUACLINGO_VISIBILITY_DEFAULT
#   define LUACLINGO_VISIBILITY_PRIVATE
#else
#   ifdef LUACLINGO_WIN
#       ifdef LUACLINGO_BUILD_LIBRARY
#           define LUACLINGO_VISIBILITY_DEFAULT __declspec (dllexport)
#       else
#           define LUACLINGO_VISIBILITY_DEFAULT __declspec (dllimport)
#       endif
#       define LUACLINGO_VISIBILITY_PRIVATE
#   else
#       if __GNUC__ >= 4
#           define LUACLINGO_VISIBILITY_DEFAULT  __attribute__ ((visibility ("default")))
#           define LUACLINGO_VISIBILITY_PRIVATE __attribute__ ((visibility ("hidden")))
#       else
#           define LUACLINGO_VISIBILITY_DEFAULT
#           define LUACLINGO_VISIBILITY_PRIVATE
#       endif
#   endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct lua_State;

LUACLINGO_VISIBILITY_DEFAULT int clingo_init_lua_(lua_State *L);
LUACLINGO_VISIBILITY_DEFAULT bool clingo_register_lua_();

#ifdef __cplusplus
}
#endif

#endif // LUACLINGO_LUACLINGO_H

