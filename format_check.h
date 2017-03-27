#ifndef FORMAT_CHECK_H
#define FORMAT_CHECK_H

#include <string>
using namespace std;

int format_check(string passcode);
bool is_digit_2_9(char c);
bool pattern_match(string str, string pattern);

#endif