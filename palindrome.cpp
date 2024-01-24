/*
 * palindrome.cpp
 *
 * This file contains `palindrome` program to identify palindromes.
 *
 * The palindrome test is handled by isPalindrome, while all
 * interaction is handled in main.
 */

#include <iostream>
#include <string>
#include <cctype>

/**
 * \brief        "Normalizes" the given string to remove non-letters
 *               and convert the remaining letters to lowercase.s
 * \param text   The string to normalize.
 * \returns      The string after normalization.
 * \warning      Doesn't yet work; currently returns a copy of the given string.
 * \warning      It's almost always bad practice to include comments that just
 *               restate what the code does, but we've included them here
 *               because C++ isn't familiar to you yet.
 */
std::string normalize(std::string text) {
    std::string result;   // Initially empty

    // Loop over every character characters c in result
    for (char c : text) {
        if (isalpha(c)) {
        result.push_back(tolower(c));  //conversts it to lower case and adds to result
    }
}
    return result;
}

/**
 * \brief        Checks if a string is the same backwards & forwards
 * \param text   The string to check
 * \returns      Whether text is a palindrome.
 * \warning      Currently checks all characters in a case-sensitive way.
 * \warning      Do not change the code in this function!
 */
bool isPalindrome(std::string text) {
    // We only care about letters, and not about upper/lower case
    std::string norm = normalize(text);

    int left  = 0;                      // Indexes of the leftmost and
    int right = norm.length() - 1;      // rightmost unchecked character.

    // Check for a palindrome by moving left and right boundaries
    // closer until they finally meet or pass each other.
    // Bail early (return false) if we find a mismatch.
    while (left < right) {
        if (norm[left] != norm[right])
            return false;

        ++left;
        --right;
    }

    // All the character pairs matched. It's a palindrome!
    return true;
}


/**
 * \brief        Gets a potential palindrome as input; checks if it is one.
 * \returns      0, the C++ convention to signal "no error occurred"
 * \warning      Do not change the code in this function!
 */
int main() {
    // Print the prompt
    std::cout << "Enter possible palindrome: ";

    // As for a line of user input
    std::string line;
    std::getline(std::cin, line);

    // Report whether it's a palindrome.
    if (isPalindrome(line)) {
        std::cout << "Yay, that's a palindrome!\n";
    } else {
        std::cout << "No, that's not a palindrome\n";
    }

    // No error to report!
    return 0;
}
