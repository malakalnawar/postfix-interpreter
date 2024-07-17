#include "../include/HelperFunctions.hpp"
#include "../include/HashTable.hpp"

/* HELPER FUNCTIONS */

/*
IS-LETTER(tkn)
1   if tkn is chararcter
2       return TRUE
3   else
4       return FALSE
*/

//check if input is a capital letter
bool isCapitalLetter(const std::string& tkn) {
    return tkn.size() == 1 && std::isupper(tkn[0]); //check length and capitalization
}

/*
IS-NUMBER(tkn)
1   if tkn is integer or float
2       return TRUE
3   else
4       return FALSE
*/

//check if input is a number (integer or float)
bool isNumber(const std::string& tkn) {
    std::istringstream iss(tkn);
    double d; //to parse a number
    char c; //for non-numeric characters
    return iss >> d && !(iss >> c);
}

/*
IS-LETTER-OR-NUMBER(tkn)
1   return IS-LETTER(tkn) or IS-NUMBER(tkn)
*/

//check if input is a letter or number
bool isCapitalLetterOrNumber(const std::string& tkn) {
    return isCapitalLetter(tkn) || isNumber(tkn);
}

//convert a valid number string to double
double stringToDouble(const std::string& tkn) {
    if (isNumber(tkn)) {
        return std::stod(tkn);
    } else {
        throw std::invalid_argument("Invalid number format: " + tkn);
    }
}

/*
GET-NUM(tkn, table)
1  if IS-NUMBER(tkn)
2     return tkn
3  else if IS-LETTER(tkn) //search hash table
4     return table.SEARCH(tkn)
5  else
6     error "Invalid token"
*/

//get number from hash table or convert from string to number
double getNum(const std::string& tkn, HashTable& table) {
    if (isNumber(tkn)) {
        return stringToDouble(tkn); //convert to number
    } else if (isCapitalLetter(tkn)) { //search hash table and return value
        char c = tkn[0];
        return table.search(c) -> value;
    } else {
        throw std::invalid_argument("Invalid token: " + tkn);
    }
}