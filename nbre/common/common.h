// Copyright (C) 2018 go-nebulas authors
//
// This file is part of the go-nebulas library.
//
// the go-nebulas library is free software: you can redistribute it and/or
// modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// the go-nebulas library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with the go-nebulas library.  If not, see
// <http://www.gnu.org/licenses/>.
//

#pragma once

#include "common/math/softfloat.hpp"
#include <algorithm>
#include <array>
#include <boost/multiprecision/cpp_int.hpp>
#include <cstdint>
#include <glog/logging.h>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace neb {
typedef std::string hex_hash_t;
typedef uint8_t byte_t;
typedef uint64_t block_height_t;
extern std::string program_name;

typedef std::string module_t;
typedef uint64_t version_t;
typedef std::string address_t;
typedef block_height_t start_block_t;
typedef block_height_t end_block_t;
typedef std::tuple<module_t, version_t, address_t, block_height_t,
                   block_height_t>
    auth_row_t;
typedef std::vector<auth_row_t> auth_table_t;

typedef boost::multiprecision::int128_t int128_t;
typedef boost::multiprecision::uint128_t uint128_t;
typedef int128_t wei_t;

typedef float32 floatxx_t;

namespace tcolor {
const static char *red = "\033[1;31m";
const static char *green = "\033[1;32m";
const static char *yellow = "\033[1;33m";
const static char *blue = "\033[1;34m";
const static char *magenta = "\033[1;35m";
const static char *cyan = "\033[1;36m";
const static char *reset = "\033[0m";
}
}
