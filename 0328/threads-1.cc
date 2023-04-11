#include <iostream>
#include <thread>

const auto do_something_1 = [] () {
  for (unsigned int i = 0; i < 1000; ++i)
    std::cout << "A" << std::flush;
};

const auto do_something_2 = [] () {
  for (unsigned int i = 0; i < 1000; ++i)
    std::cout << "B" << std::flush;
};

int main() {
  std::thread thread_1(do_something_1);
  std::thread thread_2(do_something_2);

  thread_1.join();
  thread_2.join();
}
