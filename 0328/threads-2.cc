#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::mutex cout_mutex; // "mutual exclusion"

void do_something(const std::string &person) {
  for (unsigned int i = 0; i < 200; ++i) {
    std::lock_guard<std::mutex> cout_guard(cout_mutex);
    std::cout << person << std::flush;
    std::cout << " says " << std::flush;
    std::cout << "hello!" << std::endl;
  }
}

int main()
{
  std::thread t1([](){ do_something("Alice"); });
  std::thread t2([](){ do_something("Bob"); });

  t1.join();
  t2.join();
}
