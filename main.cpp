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

auto sieve(u64 t) -> std::vector<bool> {
  std::vector<bool> primes(t + 1, true);
  primes[0] = false;
  primes[1] = false;
  for(usize i{2}; i < t; ++i) {
    if(!primes[i]) continue;
    auto j = i * i;
    while(j <= t) {
      primes[j] = false;
      j += i;
    }
  }
  return primes;
}

auto _square(u64 x) -> __uint128_t {
  return static_cast<__uint128_t>(x) * x;
}

auto usqrt(u64 x) -> u64 {
  auto s = static_cast<u64>(std::sqrt(static_cast<f64>(x)));
  if(_square(s) > x) --s;
  if(_square(s + 1) <= x) ++s;
  return s;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; std::cin >> n;
  std::vector<u64> xs;
  xs.reserve(n);
  u64 max_{0};
  while(n-- > 0) {
    u64 t; std::cin >> t;
    xs.push_back(t);
    max_ = std::max(max_, t);
  }
  const auto primes = sieve(usqrt(max_));
  for(const auto x : xs) {
    const auto x_sqrt = usqrt(x);
    const auto s2 = _square(x_sqrt);
    if(s2 != x || !primes[x_sqrt]) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
}
