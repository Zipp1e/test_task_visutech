
#ifndef VISUTECH_TESTS_H
#define VISUTECH_TESTS_H

std::string to_lowercase(const std::string&);

class to_lowercase_tests {
 public:
  static void do_nothing_test() {
    std::string str = "all characters are lowercase";
    std::string excepted_res = "all characters are lowercase";

    std::string res = to_lowercase(str);

    assert(excepted_res == res);
  }

  static void test1() {
    std::string str = "NOt all characters are lowercase";
    std::string excepted_res = "not all characters are lowercase";

    std::string res = to_lowercase(str);

    assert(excepted_res == res);
  }

  static void test2() {
    std::string str = "ChArAcTeRs 'n' ApoStRoPHeS";
    std::string excepted_res = "characters 'n' apostrophes";

    std::string res = to_lowercase(str);

    assert(excepted_res == res);
  }

  static void empty_str_test() {
    std::string str = "";
    std::string excepted_res = "";

    std::string res = to_lowercase(str);

    assert(excepted_res == res);
  }

  static void all_caps_test() {
    std::string str = "ALL CHARACTERS ARE CAPS";
    std::string excepted_res = "all characters are caps";

    std::string res = to_lowercase(str);

    assert(excepted_res == res);
  }
};

std::string sort_words(const std::string&);

class sort_words_tests {
 public:
  static void do_nothing_test() {
    std::string str = "aaa bbb ccc ddd";
    std::string excepted_res = "aaa bbb ccc ddd";

    std::string res = sort_words(str);

    assert(excepted_res == res);
  }

  static void test1() {
    std::string str = "NOt all characters Are LOwercase";
    std::string excepted_res = "all Are characters LOwercase NOt";

    std::string res = sort_words(str);

    assert(excepted_res == res);
  }

  static void test2() {
    std::string str = "all chars are lowercase";
    std::string excepted_res = "all are chars lowercase";

    std::string res = sort_words(str);

    assert(excepted_res == res);
  }

  static void test3() {
    std::string str = "SOmebody once Told me the world Is GONNA rOLL";
    std::string excepted_res = "GONNA Is me once rOLL SOmebody the Told world";

    std::string res = sort_words(str);

    assert(excepted_res == res);
  }

  static void test4() {
    std::string str = "Lorem ipsum dolor sit amet";
    std::string excepted_res = "amet dolor ipsum Lorem sit";

    std::string res = sort_words(str);

    assert(excepted_res == res);
  }
};


#endif //VISUTECH_TESTS_H
