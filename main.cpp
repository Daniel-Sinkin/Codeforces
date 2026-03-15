#include <algorithm>
#include <array>
#include <cstdint>
#include <concepts>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <cmath>
#include <unordered_map>
#include <numeric>

using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using i8  = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using usize = std::size_t;

using f32 = float;
using f64 = double;

#define ceildiv(a, b) (((a) + (b) - 1) / (b))
#define rep(i, n) for(int i{0}; i < (n); ++i)
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
#define dbg(x) std::cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

int main() {
  return 0;
}
