#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <stdexcept>

#include "include/LinkedList.hpp"
#include "include/Stack.hpp"
#include "include/HashTable.hpp"
#include "include/HelperFunctions.hpp"
#include "include/Operators.hpp"

/**
 * Executes an operation specified by the given symbol on the stack and updates the stack accordingly.
 * Supported operations include basic arithmetic, exponentiation, nth root, logarithms, trigonometric functions,
 * hyperbolic functions, modulo, factorial, and handling of assignment and unknown operators.
 *
 * @param symbol The operation symbol to be performed.
 * @param stack Reference to the stack where user input, operands and results are managed.
 * @param table Reference to the hash table containing variables for operations.
 */

//operate on stack. takes symbol and finds operation to perform.
void operate(const std::string& symbol, Stack& stack, HashTable& table) {
    if (symbol == "+") {
        double result = addition(stack, table);
        stack.push(std::to_string(result));
    } 
    else if (symbol == "-") {
        double result = subtraction(stack, table);
        stack.push(std::to_string(result));
    }
    else if (symbol == "*") {
        double result = multiplication(stack, table);
        stack.push(std::to_string(result));
    }
    else if (symbol == "/") {
        double result = division(stack, table);
        stack.push(std::to_string(result));
    }
    else if (symbol == "^") {
        double result = exponentiation(stack, table);
        stack.push(std::to_string(result));
    }
    else if (symbol == "nrt") {
        double result = nthRoot(stack, table);
        stack.push(std::to_string(result));
    }
    else if (symbol == "lg") {
        double result = logarithm(stack, table);
        stack.push(std::to_string(result));
    }
    else if (symbol == "ln") {
        double result = naturalLogarithm(stack, table);
        stack.push(std::to_string(result));
    }
    else if (symbol == "sin") {
        double result = sin(stack, table, false);
        stack.push(std::to_string(result));
    }
    else if (symbol == "cos") {
        double result = cos(stack, table, false);
        stack.push(std::to_string(result));
    }
    else if (symbol == "tan") {
        double result = tan(stack, table);
        stack.push(std::to_string(result));
    }
    else if (symbol == "sinh") {
        double result = sinh(stack, table, false);
        stack.push(std::to_string(result));
    }
    else if (symbol == "cosh") {
        double result = cosh(stack, table, false);
        stack.push(std::to_string(result));
    }
    else if (symbol == "tanh") {
        double result = tanh(stack, table);
        stack.push(std::to_string(result));
    }
    else if (symbol == "%") {
        double result = modulo(stack, table);
        stack.push(std::to_string(result));
    }
    else if (symbol == "!") {
        double result = factorial(stack, table);
        stack.push(std::to_string(result));
    }
    else if (symbol == "=") {
        throw std::invalid_argument("Cannot assign while performing other operations");
    }
    else {
        throw std::invalid_argument("Unknown operator: " + symbol);
    }
}

/**
 * Processes input string containing operators and operands,
 * updating the stack and performing operations accordingly.
 *
 * @param input The input string containing tokens separated by spaces.
 * @param stack Reference to the stack where user input, operands and results are managed.
 * @param table Reference to the hash table containing variables for operations.
 * @param exit Boolean flag indicating whether the program should exit.
 *             Set to true if the input command is "exit".
 */

//process input string to extract and operate on tokens
void processInput(const std::string& input, Stack& stack, HashTable& table, bool& exit) {
    size_t start = 0;
    size_t end = input.find(' ');

    while (end != std::string::npos) {
        std::string token = input.substr(start, end - start);
        if (isCapitalLetterOrNumber(token)) {
            stack.push(token);
        } else {
            operate(token, stack, table);
        }
        start = end + 1;
        end = input.find(' ', start);
    }

    std::string lastToken = input.substr(start);
    if (isCapitalLetterOrNumber(lastToken)) {
        stack.push(lastToken);
    } 
    else if (lastToken == "exit") {
        exit = true;
        return;
    }
    else if (lastToken == "=") {
        assign(stack, table);
        return;
    }
    else {
        operate(lastToken, stack, table);
    }

    //display result
    std::cout << stack.top();
    if (lastToken == "lg" || lastToken == "ln" || lastToken == "nrt") {
        std::cout << " ( approx. )";
    }
    std::cout << std::endl;

}

/* MAIN */

int main() {

    //flag to kill process
    bool exit = false;

    //user input
    std::string input;

    //stack to store user input broken up into tokens
    Stack tokens;

    // hash table to store user input variables
    HashTable symbolTable;

    while (!exit) {
        // user input
        std::cout << "> ";
        std::getline(std::cin, input);
        // process the input
        processInput(input, tokens, symbolTable, exit);
    }
    
    return 0;
};