// Copyright (C) 2018 go-nebulas authors
//
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
#include "common/common.h"
#include <boost/endian/conversion.hpp>

namespace neb {
namespace util {

namespace internal {
std::string convert_byte_to_hex(const byte_t *buf, size_t len);
std::string convert_byte_to_base58(const byte_t *buf, size_t len);

bool convert_hex_to_bytes(const std::string &s, byte_t *buf, size_t &len);
bool convert_base58_to_bytes(const std::string &s, byte_t *buf, size_t &len);
} // end namespace internal

template <size_t ByteLength = 32> class fix_bytes {
public:
  fix_bytes() : m_value{0} {};
  fix_bytes(std::initializer_list<byte_t> l) : m_value(l) {}
  fix_bytes(const fix_bytes<ByteLength> &v) : m_value(v.m_value) {}
  fix_bytes(fix_bytes &&v) : m_value(std::move(v.m_value)) {}
  fix_bytes(const byte_t *buf, size_t buf_len) {
    if (buf_len >= ByteLength) {
      memcpy(m_value, buf, ByteLength);
    } else {
      LOG(ERROR) << "buf len is: " << buf_len << ", less than " << ByteLength;
    }
  }

  fix_bytes<ByteLength> &operator=(const fix_bytes<ByteLength> &v) {
    if (&v == this)
      return *this;
    m_value = v.m_value;
    return *this;
  }

  fix_bytes<ByteLength> &operator=(fix_bytes<ByteLength> &&v) {
    m_value = std::move(v.m_value);
    return *this;
  }

  bool operator==(const fix_bytes<ByteLength> &v) const {
    return m_value == v.m_value;
  }

  bool operator!=(const fix_bytes<ByteLength> &v) const {
    return m_value != v.m_value;
  }

  std::string to_base58() const {
    return internal::convert_byte_to_base58(value(), size());
  }

  std::string to_hex() const {
    return internal::convert_byte_to_hex(value(), size());
  }

  inline size_t size() const { return ByteLength; }
  inline const byte_t *value() const { return m_value; }
  inline byte_t *value() { return m_value; }

  static fix_bytes<ByteLength> from_base58(const std::string &t) {
    fix_bytes<ByteLength> ret;
    size_t s = ret.size();
    bool succ = internal::convert_base58_to_bytes(t, ret.value(), s);
    if (!succ)
      throw std::invalid_argument("invalid base58 string for from_base58");
    return ret;
  }

  static fix_bytes<ByteLength> from_hex(const std::string &t) {
    fix_bytes<ByteLength> ret;
    size_t s = ret.size();
    bool succ = internal::convert_base58_to_bytes(t, ret.value(), s);
    if (!succ)
      throw std::invalid_argument("invalid hex string for from_hex");
    return ret;
  }

protected:
  std::array<byte_t, ByteLength> m_value;
}; // end class fix_bytes

template <typename T> struct is_fix_bytes { const static bool value = false; };
template <size_t N> struct is_fix_bytes<fix_bytes<N>> {
  const static bool value = true;
};

class bytes {
public:
  bytes();
  bytes(size_t len);

  bytes(const bytes &v);
  bytes(bytes &&v);
  bytes(std::initializer_list<byte_t> l);
  bytes(const byte_t *v, size_t len);

  bytes &operator=(const bytes &v);
  bytes &operator=(bytes &&v);

  bool operator==(const bytes &v);
  bool operator!=(const bytes &v);

  std::string to_base58() const;
  std::string to_hex() const;

  static bytes from_base58(const std::string &t);
  static bytes from_hex(const std::string &t);

  inline size_t size() const { return sizeof(m_value.get()); }
  inline const byte_t *value() const { return m_value.get(); }
  inline byte_t *value() { return m_value.get(); }

private:
  std::unique_ptr<byte_t[]> m_value;
}; // end class bytes

template <typename T>
auto byte_to_number(byte_t *bytes, size_t len) ->
    typename std::enable_if<std::is_arithmetic<T>::value, T>::type {
  if (len < sizeof(T))
    return T();

  T *val = (T *)bytes;
  T ret = boost::endian::big_to_native(*val);
  return ret;
}

template <typename T>
auto number_to_byte(T val, byte_t *bytes, size_t len) ->
    typename std::enable_if<std::is_arithmetic<T>::value, void>::type {
  if (len < sizeof(T))
    return;

  T v = boost::endian::native_to_big(val);
  T *p = (T *)bytes;
  *p = v;
  return;
}

template <typename T, typename BytesType>
auto byte_to_number(const BytesType &v) ->
    typename std::enable_if<std::is_arithmetic<T>::value, T>::type {
  if (v.size() < sizeof(T))
    return T();

  T *val = (T *)v.value();
  T ret = boost::endian::big_to_native(*val);
  return ret;
}

template <typename BytesType, typename T>
auto number_to_byte(T val) ->
    typename std::enable_if<std::is_arithmetic<T>::value &&
                                std::is_same<BytesType, bytes>::value,
                            BytesType>::type {
  T v = boost::endian::native_to_big(val);
  BytesType b((byte_t *)&v, sizeof(v));
  return b;
}

template <typename BytesType, typename T>
auto number_to_byte(T val) ->
    typename std::enable_if<std::is_arithmetic<T>::value &&
                                is_fix_bytes<BytesType>::value,
                            BytesType>::type {
  T v = boost::endian::native_to_big(val);
  BytesType b;
  T *rval = (T *)b.value();
  *rval = v;
  return b;
}
}
}
