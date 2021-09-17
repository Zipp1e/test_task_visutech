#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "tests.h"

std::string to_lowercase(const std::string &str) {
  std::string res;
  for (auto &c: str) {
    res += std::tolower(c);
  }
  return res;
}

bool cmp(const std::string &wa, const std::string &wb) {
  return to_lowercase(wa) <
      to_lowercase(wb);
}

std::string sort_words(const std::string &str) {
  std::vector<std::string> words;
  std::istringstream iss(str);
  std::string item;
  while (std::getline(iss, item, ' ')) {
    words.push_back(item);
  }

  std::sort(words.begin(), words.end(), cmp);
  std::string resulting_line;
  for (auto ii = words.begin(); ii != words.end(); ++ii) {
    resulting_line += (*ii);
    if (ii + 1 != words.end()) {
      resulting_line += " ";
    }
  }
  return resulting_line;
}

void run_tests() {
  to_lowercase_tests::empty_str_test();
  to_lowercase_tests::do_nothing_test();
  to_lowercase_tests::test1();
  to_lowercase_tests::test2();
  to_lowercase_tests::all_caps_test();
  std::cout << "to_lowercase tests passed!\n";

  sort_words_tests::do_nothing_test();
  sort_words_tests::test1();
  sort_words_tests::test2();
  sort_words_tests::test3();
  sort_words_tests::test4();
  std::cout << "sort_words tests passed!\n";

  std::cout << "All tests passed!\n";
}

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cout << "Passed " << ((argc > 3) ? "more " : "less ") << "than 2 arguments";
    return 0;
  }

  std::ifstream fin;
  fin.open(argv[1]);
  std::string line;
  std::vector<std::string> lines;
  while (std::getline(fin, line)) {
    lines.push_back(line);
  }
  fin.close();

  for (auto &str : lines) {
    str = sort_words(str);
  }

  std::ofstream fout;
  fout.open(argv[2]);

  for (auto &str : lines) {
    fout << str << '\n';
  }
  fout.close();

  return 0;
}
