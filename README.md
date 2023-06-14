# CreditCardValidator
# 1 Overview

## 1.1 Why Credit Card validation is useful

Credit-card validation is crucial in e-commerce as it helps prevent fraud and ensures that transactions are processed accurately. By validating credit card numbers, e-commerce websites can verify the authenticity of the card and prevent unauthorised purchases. This not only protects the merchants from chargebacks but also enhances the trust of customers in the website. Hence, having a robust credit-card validation system is essential for the success of any e-commerce business.

## 1.2 Potential Stakeholders

Some potential stakeholders for a program like this are as follows:

- E-commerce websites that process payments
- Credit card companies that issue credit cards
- Customers who use credit cards for online transactions
- Regulatory bodies that oversee e-commerce transactions and financial institutions.

## 1.3 Projected Outcomes

Some basic goals that a credit card validation program may need to have are:

- To ensure that the credit card number is in the correct format
- To check the validity of the credit card number by verifying its checksum
- To determine the type of credit card (e.g., Visa, Mastercard, American Express, etc.)

---

# 2 Functionality

## 2.1 Validity of credit cards

One way to check the validity of a credit card number is by using Luhn's algorithm. The algorithm is named after its creator, Hans Peter Luhn, who developed it in the 1950s.

The algorithm works by taking the credit card number and performing a series of mathematical operations on it. The result is a single digit number that is used to validate the credit card number.

To apply Luhn's algorithm, the following steps can be followed:

1. Starting with the second to last digit and moving backwards, double every other digit.
2. If the result of doubling a digit is greater than 9, then add the digits of the result together (e.g. 7 x 2 = 14, 1 + 4 = 5).
3. Add up all the digits in the credit card number.
4. If the sum of the digits is divisible by 10, then the credit card number is valid.

For example, let's say we want to check the validity of the credit card number 4111 1111 1111 1111. Applying Luhn's algorithm, we get:

```
4   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1
8   1   2   1   2   1   2   1   2   1   2   1   2   1   2   1
--  --  --  --  --  --  --  --  --  --  --  --  --  --  --  --
32  1   2   1   2   1   2   1   2   1   2   1   2   1   2   1

```

Adding up all the digits, we get 32 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 = 56. Since 56 is divisible by 10, the credit card number is valid.

A credit card validation program can implement Luhn's algorithm to check the validity of credit card numbers.

## 2.2 Implementation in C++

To implement Luhn's algorithm in C++, you can use a function that takes a string representing the credit card number as input and returns a boolean value indicating whether the credit card number is valid or not. Here is an example implementation:

```cpp
#include <iostream>
#include <string>

// Returns true if the given credit card number is valid
bool isValidCreditCard(const std::string& creditCardNumber) {
    int sum = 0;
    bool alternate = false;
    for (int i = creditCardNumber.length() - 1; i >= 0; --i) {
        int digit = creditCardNumber[i] - '0';
        if (alternate) {
            digit *= 2;
            if (digit > 9) {
                digit = (digit / 10) + (digit % 10);
            }
        }
        sum += digit;
        alternate = !alternate;
    }
    return (sum % 10 == 0);
}

int main() {
    std::string creditCardNumber = "4111111111111111";
    if (isValidCreditCard(creditCardNumber)) {
        std::cout << "Credit card number is valid\\n";
    } else {
        std::cout << "Credit card number is invalid\\n";
    }
    return 0;
}

```

In the `isValidCreditCard` function, we start by initializing `sum` to 0 and `alternate` to false. We then iterate over the credit card number from right to left, doubling every second digit and adding up all the digits. The `alternate` variable is used to keep track of whether we should double the current digit or not.

Finally, we check if the sum is divisible by 10. If it is, we return true (indicating that the credit card number is valid), otherwise we return false.

In the `main` function, we test the `isValidCreditCard` function with a sample credit card number. The output of the program will be "Credit card number is valid".

## 2.3 String Manipulation

When dealing with credit card validation, string manipulation may be necessary to extract certain information from the credit card number. For example, the issuer identification number (IIN) can be used to determine the type of credit card (e.g. Visa, Mastercard, American Express, etc.). The IIN is the first six digits of the credit card number, and can be extracted using string manipulation techniques such as substring or character array manipulation.

Additionally, some credit card numbers may have spaces or dashes that need to be removed before the number can be validated. String manipulation techniques such as replace or erase can be used to remove these characters.

It's important to be careful when performing string manipulation on credit card numbers, as even a small mistake can result in an invalid number. It's also important to ensure that any sensitive information in the credit card number is handled securely to prevent unauthorized access or disclosure.

---

# 3 Coding the Solution

## 3.1 Coding the initial algorithm

My initial algorithm consisted of code that I have written above. I used the test case:

```cpp
#include <iostream>
#include <string>

using namespace std;

bool isValidCC(const string& creditCardNumber) {
    int sum = 0;
    bool alternate = false;
    for (int i = creditCardNumber.length() - 1; i >= 0; i--) {
        int digit = creditCardNumber[i] - '0';
        if (alternate) {
            digit *= 2;
            if (digit > 9) {
                digit = (digit / 10) + (digit % 10);
            }
        }
        sum += digit;
        alternate = !alternate;
    }
    return (sum % 10 == 0);
}

int main() {
    string creditCardNumber = "4111111111111111";
    if (isValidCC(creditCardNumber)) {
        cout << "T";
    } else {
        cout << "F";
    }
    return 0;
}
```

## 3.2 Compilation

To compile a C++ program using g++, you can use the following command in the terminal:

```
g++ program.cpp -o program

```

This will compile the program and create an executable file called `program`. You can then run the program by typing `./program` in the terminal.

In the command above, `program.cpp` is the name of the C++ file you want to compile. The `-o` flag specifies the name of the output file (in this case, `program`). If you don't specify an output file name, the default output file name will be `a.out`.

You can also add additional flags to the `g++` command, such as `-Wall` to enable all warnings, or `-std=c++11` to use the C++11 standard.

It's important to ensure that your C++ program is free of errors and warnings before compiling it. You can use a text editor or an integrated development environment (IDE) to write and debug your code.

I compiled my test code using this, and it gave me the output `T`, which I know now that my algorithm works because I used the test case of `4111-1111-1111-1111`.

## 3.3 Taking inputs; String manipulation

To take inputs in C++, you can use the `cin` function, which reads input from the standard input stream. Here is an example of how to use `cin` to read a string input:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a credit card number: ";
    std::cin >> input;
    std::cout << "You entered: " << input << std::endl;
    return 0;
}

```

In the code above, we declare a string variable called `input` and use `cin` to read a string input from the user. We then output the input back to the user to confirm that it was read correctly.

When taking input for credit card numbers, it's important to check that the input is a valid string representation of a credit card number. This can be done using regular expressions or by checking that the input only contains digits and any necessary separators (such as spaces or hyphens).

To strip off any unneeded characters from a credit card number string, you can use string manipulation functions such as `replace` or `erase`. For example, to remove all spaces and hyphens from a credit card number string, you can do the following:

```cpp
#include <iostream>
#include <string>

int main() {
    // Read input from user
    std::string input;
    std::cout << "Enter a credit card number: ";
    std::cin >> input;

    // Remove spaces and hyphens
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    input.erase(std::remove(input.begin(), input.end(), '-'), input.end());

    // Output modified input
    std::cout << "You entered: " << input << std::endl;
    return 0;
}

```

In the code above, we first read a credit card number input from the user. We then use the `erase` function along with the `remove` algorithm to remove all spaces and hyphens from the input string. The `remove` algorithm takes a range of iterators and a value to remove, and returns an iterator to the new end of the range. The `erase` function then erases the characters between the new end iterator and the old end iterator.

After modifying the input string, we output it back to the user to confirm that the modifications were made correctly.

It's important to be careful when modifying credit card number strings, as any mistakes can result in an invalid number. It's also important to ensure that any sensitive information in the credit card number is handled securely to prevent unauthorized access or disclosure.

Implementing this into my program (and tidying up; adding proper messages instead of T and F):

```cpp
#include <iostream>
#include <string>

using namespace std;

bool isValidCC(const string& creditCardNumber) {
    // Luhn's algorithm - see docs
    int sum = 0;
    bool alternate = false;
    for (int i = creditCardNumber.length() - 1; i >= 0; i--) {
        int digit = creditCardNumber[i] - '0';
        if (alternate) {
            digit *= 2;
            if (digit > 9) {
                digit = (digit / 10) + (digit % 10);
            }
        }
        sum += digit;
        alternate = !alternate;
    }
    return (sum % 10 == 0);
}

int main() {
    string creditCardNumber;

    while(true) {
        cout << "Enter a CC Number: ";
        cin >> creditCardNumber;
    
        // Removing all ' ' and '-' from the string
        creditCardNumber.erase(remove(creditCardNumber.begin(), creditCardNumber.end(), ' '), creditCardNumber.end());
        creditCardNumber.erase(remove(creditCardNumber.begin(), creditCardNumber.end(), '-'), creditCardNumber.end());

    
        if (isValidCC(creditCardNumber)) {
            cout << "Credit Card is Verified.";
            cout << endl << endl;
            break;
        } else {
            cout << "Credit card is not Verified";
            cout << endl << endl;
        }
    }
  
    return 0;

}
```

## 3.4 Testing

Testing is an essential part of software development, and it is especially important when developing a credit card validation program. A robust testing plan can help ensure that the program works as intended and catches any potential errors or bugs that could lead to invalid credit card transactions or security breaches.

When testing a credit card validation program, it's important to cover a range of test cases to ensure that the program works correctly in all scenarios. Here are some example test cases that could be used for a credit card validation program:

| Test Case | Input | Expected Output |
| --- | --- | --- |
| Valid Visa card | 4111 1111 1111 1111 | Valid |
| Valid Mastercard | 5555 5555 5555 4444 | Valid |
| Valid American Express | 3782 822463 10005 | Valid |
| Valid Discover | 6011 1111 1111 1117 | Valid |
| Invalid credit card number | 1234 5678 9012 3456 | Invalid |
| Invalid checksum | 4111 1111 1111 1112 | Invalid |

These test cases cover a range of scenarios that a credit card validation program may encounter in the real world, such as valid and invalid credit card numbers, different credit card types, and various error conditions.

It's important to note that these test cases are just examples, and a comprehensive testing plan should cover as many scenarios as possible to ensure the program's reliability and accuracy.

In conclusion, testing a credit card validation program is crucial to ensure that it works correctly and provides accurate results. By covering a range of test cases and using a rigorous testing plan, developers can ensure that their credit card validation program is reliable, secure, and effective.
