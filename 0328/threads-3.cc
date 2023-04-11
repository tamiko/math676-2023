#include <algorithm>
#include <execution>
#include <ranges>
#include <iostream>

int main()
{
  const auto numbers = std::views::iota(1, 1000);

  std::for_each(std::execution::par_unseq,
                numbers.begin(),
                numbers.end(),
                [](int i) {
                  std::cout << i << " ";
                });
}
