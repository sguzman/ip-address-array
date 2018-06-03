#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

constexpr static const unsigned int first{0xff000000};
constexpr static const unsigned char first_shift{24};

constexpr static const unsigned int second{0x00ff0000};
constexpr static const unsigned char second_shift{16};


constexpr static const unsigned int third{0x0000ff00};
constexpr static const unsigned char third_shift{8};


constexpr static const unsigned int fourth{0x000000ff};
constexpr static const unsigned char fourth_shift{0};


[[noreturn]] int main(int argc, char* argv[2]) noexcept {
  if (argc == 1) {
    cout << "usage: ./ip <int>" << endl;
    exit(0);
  }

  const unsigned long num_long{static_cast<unsigned long>(atol(argv[1]))};
  if (num_long > std::numeric_limits<unsigned int>::max()) {
    cerr << "Integer is too large" << endl;
    exit(1);
  }

  const unsigned int num{static_cast<unsigned int>(atoi(argv[1]))};
  cout << ((num & first) >> first_shift) << '.'
       << ((num & second) >> second_shift) << '.'
       << ((num & third) >> third_shift) << '.'
       << ((num & fourth) >> fourth_shift) << endl;
}