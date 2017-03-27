#ifndef DECODERS_H
#define DECODERS_H

#include <string>
using namespace std;

string atbash_alphanum(string ciphertext);
string ROT(int n, string ciphertext);
string ROT_alphanum(int n, string ciphertext);
string replace_two_letter_digit(string ciphertext);

#endif