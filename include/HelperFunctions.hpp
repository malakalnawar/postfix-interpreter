#ifndef HELPERFUNCTIONS_HPP
#define HELPERFUNCTIONS_HPP

#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>

#include "../include/HashTable.hpp"

/* HELPER FUNCTIONS */

/**
 * These functions provide utility operations for handling string tokens and numeric conversions.
 */

bool isCapitalLetter(const std::string& tkn);
bool isNumber(const std::string& tkn);
bool isCapitalLetterOrNumber(const std::string& tkn);
double stringToDouble(const std::string& tkn);
double getNum(const std::string& tkn, HashTable& table);

#endif