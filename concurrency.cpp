#include <iostream>
#include <thread>

#include <iostream>
#include <thread>

void threadFunction() {

  std::cout << "Hello concurrent world from threadFunction! Thread id = "
            << std::this_thread::get_id() << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
  std::cout << "Finished work in thread\n"; 
}

int main() {

  // create thread
  std::thread t(threadFunction);

  // do something in main()
  std::cout << "Hello concurrent world from main! Thread id = "
            << std::this_thread::get_id() << std::endl;
  unsigned int nCores = std::thread::hardware_concurrency();
  std::cout << "This machine supports concurrency with " << nCores
            << " cores available" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
  std::cout << "Finished work in main\n";

  // wait for thread to finish
  t.join();

  return 0;
}