#ifndef DECODERS_H
#define DECODERS_H

#include <cmath>
#include <string>
#include <vector>
using namespace std;

string reverse(string ciphertext);

string atbash(string ciphertext);
string atbash_alphanum(string ciphertext);

string ROT(int n, string ciphertext);
string ROT_alphanum(int n, string ciphertext);

string replace_two_letter_digit(string ciphertext);

//morse, grid, keywords check
#endif