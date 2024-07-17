#include "../include/HelperFunctions.hpp"
#include "../include/Operators.hpp"

/* OPERATORS */

/*
ASSIGN(stack, table)
1   tkn1 ← stack.TOP()
2   stack.POP()
3   tkn2 ← stack.TOP()
4   stack.POP()
5  
6   if IS-LETTER(tkn1) and IS-NUMBER(tkn2)
7       key ← tkn1
8       value ← tkn2
9   else if IS-LETTER(tkn2) and IS-NUMBER(tkn1)
10      key ← tkn2
11      value ← tkn1
12  else
13      error "Invalid tokens for assignment"
14 
15  table.INSERT(key, value)
*/

void assign(Stack& stack, HashTable& table) {
    std::string tkn1 = stack.top();
    stack.pop();
    std::string tkn2 = stack.top();
    stack.pop();

    char key;
    double value;

    //check which token is the key and which is the value
    if (isCapitalLetter(tkn1) && isNumber(tkn2)) {
        key = tkn1[0];
        value = stringToDouble(tkn2);
    } else if (isCapitalLetter(tkn2) && isNumber(tkn1)) {
        key = tkn2[0];
        value = stringToDouble(tkn1);
    } else {
        throw std::invalid_argument("Invalid tokens for assignment. One must be a capital letter and the other a number.");
    }

    //insert the key-value pair into the hash table
    table.insert(key, value);
}

/*
ADDITION(stack, table)
1  tkn1 ← stack.TOP()
2  stack.POP()
3  tkn2 ← stack.TOP()
4  stack.POP()
5  a ← GET-NUM(tkn1, table)
6  b ← GET-NUM(tkn2, table)
7  return b + a
*/

double addition(Stack& stack, HashTable& table) {
    std::string tkn1 = stack.top();
    stack.pop();
    std::string tkn2 = stack.top();
    stack.pop();

    double a = getNum(tkn1, table);
    double b = getNum(tkn2, table);

    return b + a;
}

/*
SUBTRACTION(stack, table)
1  tkn1 ← stack.TOP()
2  stack.POP()
3  tkn2 ← stack.TOP()
4  stack.POP()
5  a ← GET-NUM(tkn1, table)
6  b ← GET-NUM(tkn2, table)
5  return b - a
*/

double subtraction(Stack& stack, HashTable& table) {
    std::string tkn1 = stack.top();
    stack.pop();
    std::string tkn2 = stack.top();
    stack.pop();

    double a = getNum(tkn1, table);
    double b = getNum(tkn2, table);

    return b - a;
}

/*
MULTIPLICATION(stack, table)
1  tkn1 ← stack.TOP()
2  stack.POP()
3  tkn2 ← stack.TOP()
4  stack.POP()
5  a ← GET-NUM(tkn1, table)
6  b ← GET-NUM(tkn2, table)
5  return b * a
*/

double multiplication(Stack& stack, HashTable& table) {
    std::string tkn1 = stack.top();
    stack.pop();
    std::string tkn2 = stack.top();
    stack.pop();

    double a = getNum(tkn1, table);
    double b = getNum(tkn2, table);

    return b * a;
}

/*
DIVISION(stack, table)
1  tkn1 ← stack.TOP()
2  stack.POP()
3  tkn2 ← stack.TOP()
4  stack.POP()
5  a ← GET-NUM(tkn1, table)
6  b ← GET-NUM(tkn2, table)
7  if a == 0 then
8      error "undefined"
9  return b / a
*/

double division(Stack& stack, HashTable& table) {
    std::string tkn1 = stack.top();
    stack.pop();
    std::string tkn2 = stack.top();
    stack.pop();

    double a = getNum(tkn1, table);
    double b = getNum(tkn2, table);

    if (a == 0) {
        throw std::invalid_argument("Division by zero: undefined");
    }

    return b / a;
}

/*
EXPONENTIATION(stack, table)
1  tkn1 ← stack.TOP()
2  stack.POP()
3  tkn2 ← stack.TOP()
4  stack.POP()
5  
6  base ← GET-NUM(tkn1, table)
7  exponent ← GET-NUM(tkn2, table)
8  
9  result ← 1.0
10 for i ← 1 to base
11     do result ← result * exponent
12 
13 return result
*/

double exponentiation(Stack& stack, HashTable& table) {
    std::string tkn1 = stack.top();
    stack.pop();
    std::string tkn2 = stack.top();
    stack.pop();

    double a = getNum(tkn1, table); //base
    double b = getNum(tkn2, table); //exponent

    double result = 1.0;
    for (int i = 0; i < a; ++i) {
        result *= b;
    }

    return result;
}

/*
NTH-ROOT(stack, table)
1  tkn1 ← stack.TOP()
2  stack.POP()
3  tkn2 ← stack.TOP()
4  stack.POP()
5  
6  base ← GET-NUM(tkn2, table)
7  exponent ← GET-NUM(tkn1, table)
8  
9  if exponent <= 0
10     error "Exponent must be a positive integer"
11  
12  if base < 0 and exponent % 2 == 0
13     error "No even root of a negative number"
14  
15  x ← 1.0
16  
17  maxIterations ← 200
18  for i ← 1 to maxIterations
19      do prevX ← x
20         x ← (1.0 / exponent) * ((exponent - 1) * x + base / x^(exponent - 1)
21         if |x - prevX| < 10^(-9)
22             break
23  
24  return x
*/

double nthRoot(Stack& stack, HashTable& table) {
    std::string tkn1 = stack.top();
    stack.pop();
    std::string tkn2 = stack.top();
    stack.pop();

    double a = getNum(tkn2, table); //base
    int b = static_cast<int>(getNum(tkn1, table)); //exponent

    //check if b is positive
    if (b <= 0) {
        throw std::invalid_argument("Exponent must be a positive integer for nth root operation");
    }

    //check if a is negative when b is even
    if (a < 0 && b % 2 == 0) {
        throw std::invalid_argument("Cannot compute even root of a negative number");
    }

    //initial guess for nth root
    double x = 1.0; //initial guess

    //babylonian method
    const int maxIterations = 200; //safety (increase for accuracy if needed)
    for (int i = 0; i < maxIterations; ++i) {
        double prevX = x;
        //nth root iteration formula
        x = (1.0 / b) * ((b - 1) * x + a / std::pow(x, b - 1)); 
        if (std::abs(x - prevX) < 1e-9) { //check for convergence
            break;
        }
    }

    return x;
}

/*
LOGARITHM(stack, table)
1   tkn1 ← stack.TOP()
2   stack.POP()
3   tkn2 ← stack.TOP()
4   stack.POP()
5  
6   x ← GET-NUM(tkn2, table)
7   base ← GET-NUM(tkn1, table)
8  
9   if x <= 0 or base <= 0 or base == 1
10      error "Invalid input"
11  
12  //calculate ln(x)
13  ln_x ← 0.0
14  term ← (x - 1) / (x + 1)
15  term2 ← term * term
16  y ← term
17  maxIterations ← 200
18  
19  for i ← 1 to maxIterations by 2
20      do ln_x ← ln_x + y / i
21          y ← y * term2
22  ln_x ← ln_x 2
23  
24  //calculate ln(base)
25  ln_base ← 0.0
26  term ← (base - 1) / (base + 1)
27  term2 ← term * term
28  y ← term
29  
30  for i ← 1 to maxIterations by 2
31      do ln_base ← ln_base + (y / i)
32         y ← y * term2
33  ln_base ← ln_base * 2
34  
35  return ln_x / ln_base
*/

double logarithm(Stack& stack, HashTable& table) {
    std::string tkn1 = stack.top();
    stack.pop();
    std::string tkn2 = stack.top();
    stack.pop();

    double x = getNum(tkn2, table);
    double base = getNum(tkn1, table);

    if (x <= 0 || base <= 0 || base == 1) {
        throw std::invalid_argument("Invalid input for logarithm operation");
    }

    //calculate ln(x) (taylor series)
    double ln_x = 0.0;
    double term = (x - 1) / (x + 1);
    double term2 = term * term;
    double y = term;
    const int maxIterations = 200; //safety (increase for accuracy if needed)

    for (int i = 1; i <= maxIterations; i += 2) {
        ln_x += y / i;
        y *= term2;
    }
    ln_x *= 2;

    //calculate ln(b) (taylor series)
    double ln_base = 0.0;
    term = (base - 1) / (base + 1);
    term2 = term * term;
    y = term;

    for (int i = 1; i <= maxIterations; i += 2) {
        ln_base += y / i;
        y *= term2;
    }
    ln_base *= 2;

    //change of base formula: log_b(x) = ln(x) / ln(b)
    return ln_x / ln_base;
}

/*
NATURAL-LOGARITHM(stack, table)
1   tkn ← stack.TOP()
2   stack.POP()
3  
4   x ← GET-NUM(tkn, table)
5  
6   if x <= 0
7       error "Invalid input"
8  
9   //calculate ln(x)
10  ln_x ← 0.0
11  term ← (x - 1) / (x + 1)
12  term2 ← term * term
13  y ← term
14  maxIterations ← 200
15  
16  for i ← 1 to maxIterations by 2
17      do ln_x ← ln_x + (y / i)
18          y ← y * term2
19  ln_x ← ln_x * 2
20  
21  return ln_x
*/

double naturalLogarithm(Stack& stack, HashTable& table) {
    std::string tkn = stack.top();
    stack.pop();

    double x = getNum(tkn, table);

    if (x <= 0) {
        throw std::invalid_argument("Invalid input for natural logarithm operation");
    }

    //calculate ln(x) (taylor series)
    double ln_x = 0.0;
    double term = (x - 1) / (x + 1);
    double term2 = term * term;
    double y = term;
    const int maxIterations = 200; //safety (increase for accuracy if needed)

    for (int i = 1; i <= maxIterations; i += 2) {
        ln_x += y / i;
        y *= term2;
    }
    ln_x *= 2;

    return ln_x;
}

/*
SIN(stack, table)
1   tkn ← stack.TOP()
2   stack.POP()
3  
4   x ← GET-NUM(tkn, table)
5  
6   //convert degrees to radians
7   x ← x * PI / 180.0
8  
9   result ← 0.0
10  term ← x
11  x2 ← x * x
12  maxIterations ← 20
13  
14  for i ← 1 to maxIterations
15      do if i % 2 != 0
16          result ← result + term
17      else 
18          result ← result - term
18      term ← term * (x2 / (2 * i * (2 * i + 1)))
19  
20  return result
*/

double sin(Stack& stack, HashTable& table, bool tan) {
    std::string tkn = stack.top();
    if (!tan) {
        stack.pop();
    }
    double x = getNum(tkn, table);

    //converting degrees to radians if necessary (assume x is in degrees)
    x = x * M_PI / 180.0;

    double result = 0.0;
    double term = x;
    double x2 = x * x;
    const int maxIterations = 20; //safety (increase for accuracy if needed)

    for (int i = 1; i <= maxIterations; ++i) {
        if (i % 2 != 0) { //for odd terms
            result += term;
        } else { //for even terms
            result -= term;
        }
        term *= x2 / (2 * i * (2 * i + 1));
    }

    return result;
}

/*
COS(stack, table)
1   tkn ← stack.TOP()
2   stack.POP()
3  
4   x ← GET-NUM(tkn, table)
5  
6   //convert degrees to radians
7   x ← x * PI / 180.0
8  
9   result ← 1.0
10  term ← 1.0
11  x2 ← x * x
12  maxIterations ← 20
13  
14  for i ← 1 to maxIterations
15      do if i % 2 != 0
16          result ← result - term
17      else 
18          result ← result + term
19      term ← term * (x2 / (2 * i * (2 * i - 1)))
20  
21  return result
*/

double cos(Stack& stack, HashTable& table, bool tan) {
    std::string tkn = stack.top();
    if (!tan) {
        stack.pop();
    }
    double x = getNum(tkn, table);

    //converting degrees to radians if necessary (assume x is in degrees)
    x = x * M_PI / 180.0;

    double result = 1.0;
    double term = 1.0;
    double x2 = x * x;
    const int maxIterations = 20; //safety (increase for accuracy if needed)

    for (int i = 1; i <= maxIterations; ++i) {
        term *= x2 / (2 * i * (2 * i - 1));
        if (i % 2 != 0) { //for odd terms
            result -= term;
        } else { //for even terms
            result += term;
        }
    }

    return result;
}

/*
TAN(stack, table)
1  sine ← SIN(stack, table)
2  cosine ← COS(stack, table)
3  
4  if cosine == 0
5     error "Cosine is zero"
6  
7  return sine / cosine
*/

double tan(Stack& stack, HashTable& table) {
    double sine = sin(stack, table, true);
    double cosine = cos(stack, table, true);

    stack.pop();

    if (cosine == 0) {
        throw std::invalid_argument("Cosine is zero");
    }

    return sine / cosine;
}

/*
SINH(stack, table)
1  tkn ← stack.TOP()
2  stack.POP()
3  
4  x ← GET-NUM(tkn, table)
5  
6  result ← 0.0
7  term ← x
8  x2 ← x * x
9  maxIterations ← 20
10  
11 for i ← 1 to maxIterations
12     do result ← result + term
13        term ← term * (x2 / ((2 * i) * (2 * i + 1)))
14  
15 return result
*/

double sinh(Stack& stack, HashTable& table, bool tanh) {
    std::string tkn = stack.top();
    if (!tanh) {
        stack.pop();
    }
    double x = getNum(tkn, table);

    double result = 0.0;
    double term = x;
    double x2 = x * x;
    const int maxIterations = 20; //safety (increase for accuracy if needed)

    for (int i = 1; i <= maxIterations; ++i) {
        result += term;
        term *= x2 / ((2 * i) * (2 * i + 1));
    }

    return result;
}

/*
COSH(stack, table)
1  tkn ← stack.TOP()
2  stack.POP()
3  
4  x ← GET-NUM(tkn, table)
5  
6  result ← 1.0
7  term ← 1.0
8  x2 ← x * x
9  maxIterations ← 20
10  
11 for i ← 1 to maxIterations
12     do term ← term * (x2 / ((2 * i) * (2 * i - 1)))
13        result ← result + term
14  
15 return result
*/

double cosh(Stack& stack, HashTable& table, bool tanh) {
    std::string tkn = stack.top();
    if (!tanh) {
        stack.pop();
    }
    double x = getNum(tkn, table);

    double result = 1.0;
    double term = 1.0;
    double x2 = x * x;
    const int maxIterations = 20; //safety (increase for accuracy if needed)

    for (int i = 1; i <= maxIterations; ++i) {
        term *= x2 / ((2 * i) * (2 * i - 1));
        result += term;
    }

    return result;
}

/*
TANH(stack, table)
1  h_sine ← SINH(stack, table)
2  h_cosine ← COSH(stack, table)
3  
4  if h_cosine == 0
5     then error "Cosh is zero"
6  
7  return h_sine / h_cosine
*/

double tanh(Stack& stack, HashTable& table) {
    double hyperbolic_sine = sinh(stack, table, true);
    double hyperbolic_cosine = cosh(stack, table, true);

    stack.pop();

    if (hyperbolic_cosine == 0) {
        throw std::invalid_argument("Cosh is zero");
    }

    return hyperbolic_sine / hyperbolic_cosine;
}

/*
MODULO(stack, table)
1  tkn1 ← stack.TOP()
2  stack.POP()
3  tkn2 ← stack.TOP()
4  stack.POP()
5  
6  a ← GET-NUM(tkn2, table)
7  b ← GET-NUM(tkn1, table)
8  
9  if b == 0
10     error "Division by zero"
11  
12  return a - (a / b) * b
*/

double modulo(Stack& stack, HashTable& table) {
    std::string tkn1 = stack.top();
    stack.pop();
    std::string tkn2 = stack.top();
    stack.pop();

    int a = static_cast<int>(getNum(tkn2, table));
    int b = static_cast<int>(getNum(tkn1, table));

    if (b == 0) {
        throw std::invalid_argument("Division by zero in modulo operation");
    }

    return a - (a / b) * b;
}

/*
FACTORIAL(stack, table)
1  tkn ← stack.TOP()
2  stack.POP()
3  
4  x ← GET-NUM(tkn, table)
5  
6  if x < 0
7     error "Factorial is only defined for non-negative integers"
8  
9  result ← 1
10 for i ← 1 to x
11     do result ← result * i
12  
13 return result
*/

double factorial(Stack& stack, HashTable& table) {
    std::string tkn = stack.top();
    stack.pop();

    int x = static_cast<int>(getNum(tkn, table));

    if (x < 0) {
        throw std::invalid_argument("Factorial is only defined for non-negative integers");
    }

    int result = 1;
    for (int i = 1; i <= x; ++i) {
        result *= i;
    }

    return result;
}

