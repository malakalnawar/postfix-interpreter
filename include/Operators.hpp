#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include "../include/Stack.hpp"
#include "../include/HashTable.hpp"

/* OPERATORS */

/**
 * These functions perform various mathematical and computational operations using operands 
 * from a stack and interact with a hash table for storing and retrieving variables and results.
 */

void assign(Stack& stack, HashTable& table);
double addition(Stack& stack, HashTable& table);
double subtraction(Stack& stack, HashTable& table);
double multiplication(Stack& stack, HashTable& table);
double division(Stack& stack, HashTable& table);
double exponentiation(Stack& stack, HashTable& table);
double nthRoot(Stack& stack, HashTable& table);
double logarithm(Stack& stack, HashTable& table);
double naturalLogarithm(Stack& stack, HashTable& table);
double sin(Stack& stack, HashTable& table, bool tan);
double cos(Stack& stack, HashTable& table, bool tan);
double tan(Stack& stack, HashTable& table);
double sinh(Stack& stack, HashTable& table, bool tan);
double cosh(Stack& stack, HashTable& table, bool tan);
double tanh(Stack& stack, HashTable& table);
double modulo(Stack& stack, HashTable& table);
double factorial(Stack& stack, HashTable& table);

#endif