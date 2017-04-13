#ifndef DECODERS_H
#define DECODERS_H

#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

string reverse(string ciphertext);

string atbash(string ciphertext);
string atbash_alphanum(string ciphertext);
string atbash_hex(string ciphertext);

string ROT(int n, string ciphertext);
string ROT_alphanum(int n, string ciphertext);

string replace_two_letter_digit(string ciphertext);

string skip(int n, string ciphertext);

string base64(string ciphertext);

string swap_morse_bits(string ciphertext);

vector<int> factors(string ciphertext);

//morse, grid, keywords check
#endif