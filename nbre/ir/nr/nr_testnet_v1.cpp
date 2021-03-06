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

#include "runtime/nr/impl/nr_impl.h"

std::string entry_point_nr(uint64_t start_block, uint64_t end_block) {

  if (start_block > end_block) {
    return std::string("{\"err\":\"start height must less than end height\"}");
  }
  uint64_t block_nums_of_a_day = 24 * 3600 / 15;
  uint64_t days = 7;
  uint64_t max_nr_block_interval = days * block_nums_of_a_day;
  if (start_block + max_nr_block_interval < end_block) {
    return std::string("{\"err\":\"nr block interval out of range\"}");
  }

  auto to_version_t = [](uint32_t major_version, uint16_t minor_version,
                         uint16_t patch_version) -> neb::rt::nr::version_t {
    return (0ULL + major_version) + ((0ULL + minor_version) << 32) +
           ((0ULL + patch_version) << 48);
  };

  int64_t a = 3000;
  int64_t b = -1;
  int64_t c = 6;
  int64_t d = -9;
  neb::rt::nr::nr_float_t theta = 1;
  neb::rt::nr::nr_float_t mu = 1;
  neb::rt::nr::nr_float_t lambda = 0.1;
  return neb::rt::nr::entry_point_nr_impl(start_block, end_block,
                                          to_version_t(0, 0, 1), a, b, c, d,
                                          theta, mu, lambda);
}

