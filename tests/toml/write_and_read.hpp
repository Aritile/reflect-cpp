#ifndef WRITE_AND_READ_
#define WRITE_AND_READ_

#include <gtest/gtest.h>

#include <iostream>
#include <rfl/toml.hpp>
#include <string>

template <class... Ps>
void write_and_read(const auto& _struct) {
  using T = std::remove_cvref_t<decltype(_struct)>;
  const auto serialized1 = rfl::toml::write<Ps...>(_struct);
  const auto res = rfl::toml::read<T, Ps...>(
      std::string_view(serialized1.c_str(), serialized1.size()));
  EXPECT_TRUE(res && true) << "Test failed on read. Error: "
                           << res.error().what();
  const auto serialized2 = rfl::toml::write<Ps...>(res.value());
  EXPECT_EQ(serialized1, serialized2);
}

#endif
