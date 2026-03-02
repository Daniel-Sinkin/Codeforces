#include <iostream>
int main() {
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
int w;
std::cin >> w;
std::cout << ((w & 3) ? "YES" : "NO") << '\n';
}
