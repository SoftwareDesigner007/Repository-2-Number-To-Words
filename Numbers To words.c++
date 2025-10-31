/*
 * Comprehensive Number <-> Words Converter (C++)
 * Handles 64-bit integers and decimals.
 * Supports Indian and International numbering systems.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cctype>

// --- Number to Words ---

// Arrays for N->W conversion
const std::vector<std::string> ones = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen"};
const std::vector<std::string> tens = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

// Helper for N->W: Converts a number 0-999 to words
std::string convertChunk(long long n)
{
    std::string s = "";
    if (n >= 100)
    {
        s += ones[n / 100] + " hundred";
        n %= 100;
        if (n > 0)
            s += " ";
    }
    if (n >= 20)
    {
        s += tens[n / 10];
        n %= 10;
        if (n > 0)
            s += "-";
    }
    if (n > 0)
    {
        s += ones[n];
    }
    return s;
}

// Main N->W function
std::string numberToWords(long long num, int mode)
{
    if (num == 0)
        return "zero";

    std::string result = "";
    if (num < 0)
    {
        result = "negative ";
        num = -num;
    }

    if (mode == 1)
    { // International System
        const std::vector<std::string> scales = {"", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion"};
        std::vector<std::string> parts;
        int scaleIndex = 0;

        while (num > 0)
        {
            if (num % 1000 != 0)
            {
                std::string chunk = convertChunk(num % 1000);
                if (scaleIndex > 0)
                {
                    chunk += " " + scales[scaleIndex];
                }
                parts.push_back(chunk);
            }
            num /= 1000;
            scaleIndex++;
        }
        std::reverse(parts.begin(), parts.end());
        for (size_t i = 0; i < parts.size(); ++i)
        {
            result += parts[i];
            if (i < parts.size() - 1)
                result += " ";
        }
    }
    else
    { // Indian System
        const std::vector<std::string> scales = {"", "thousand", "lakh", "crore", "arab", "kharab", "neel", "padma"};
        std::vector<std::string> parts;

        // Handle first chunk (up to 999)
        if (num > 0)
        {
            parts.push_back(convertChunk(num % 1000));
            num /= 1000;
        }

        // Handle chunks of 100 (lakh, crore, etc.)
        int scaleIndex = 1;
        while (num > 0 && scaleIndex < scales.size())
        {
            if (num % 100 != 0)
            {
                parts.push_back(convertChunk(num % 100) + " " + scales[scaleIndex]);
            }
            num /= 100;
            scaleIndex++;
        }
        std::reverse(parts.begin(), parts.end());
        for (size_t i = 0; i < parts.size(); ++i)
        {
            if (!parts[i].empty())
            {
                result += parts[i];
                if (i < parts.size() - 1 && !parts[i + 1].empty())
                    result += " ";
            }
        }
    }
    return result;
}

std::string processNumberToWords()
{
    std::cout << "Select system:\n1. International (Million, Billion)\n2. Indian (Lakh, Crore)\nChoice: ";
    int mode;
    std::cin >> mode;

    std::cout << "Enter a number (e.g., 152.45 or 45789): ";
    std::string input;
    std::cin >> input;

    long long integerPart = 0;
    long long decimalPart = 0;
    std::string integerStr, decimalStr;

    size_t decimalPoint = input.find('.');
    if (decimalPoint != std::string::npos)
    {
        integerStr = input.substr(0, decimalPoint);
        decimalStr = input.substr(decimalPoint + 1);
        // Truncate/pad paise to 2 digits
        if (decimalStr.length() > 2)
        {
            decimalStr = decimalStr.substr(0, 2);
        }
        else if (decimalStr.length() == 1)
        {
            decimalStr += '0';
        }
        else if (decimalStr.empty())
        {
            decimalStr = "00";
        }
        try
        {
            decimalPart = std::stoll(decimalStr);
        }
        catch (...)
        { /* ignore */
        }
    }
    else
    {
        integerStr = input;
    }

    try
    {
        integerPart = std::stoll(integerStr);
    }
    catch (const std::out_of_range &)
    {
        return "Error: Number is too large for 64-bit integer.";
    }
    catch (const std::invalid_argument &)
    {
        return "Error: Invalid number format.";
    }

    // Handle singular "rupee"
    std::string rupeeWord = (integerPart == 1 || integerPart == -1) ? " rupee" : " rupees";
    std::string paiseWord = (decimalPart == 1) ? " paisa" : " paise";

    std::string result = numberToWords(integerPart, mode) + rupeeWord;

    if (decimalPart > 0)
    {
        result += " and " + numberToWords(decimalPart, mode) + paiseWord;
    }

    // Capitalize first letter
    if (!result.empty())
    {
        result[0] = std::toupper(result[0]);
    }
    return result;
}

// --- Words to Number ---

// Map for W->N parsing
std::map<std::string, long long> wordMap = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90}, {"hundred", 100}, {"thousand", 1000}, {"million", 1000000}, {"billion", 1000000000}, {"trillion", 1000000000000}, {"quadrillion", 1000000000000000}, {"quintillion", 1000000000000000000}, {"lakh", 100000}, {"crore", 10000000}, {"arab", 1000000000}, {"kharab", 100000000000}};

long long wordsToNumber(std::string text)
{
    // 1. Preprocess: to lower, remove 'and', 'rupees', 'paise', hyphens
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    std::string resultStr = "";
    for (char c : text)
    {
        if (c == '-')
        {
            resultStr += ' ';
        }
        else if (std::isalpha(c) || c == ' ')
        {
            resultStr += c;
        }
    }

    // Remove useless words
    std::istringstream iss(resultStr);
    std::string word;
    std::vector<std::string> tokens;
    while (iss >> word)
    {
        if (word != "and" && word != "rupees" && word != "rupee" && word != "paise" && word != "paisa" && word != "negative")
        {
            tokens.push_back(word);
        }
    }

    if (tokens.empty())
        return 0;

    long long total = 0;
    long long currentNumber = 0;

    for (const std::string &token : tokens)
    {
        if (wordMap.find(token) == wordMap.end())
        {
            std::cout << "(Ignoring unknown word: " << token << ") ";
            continue;
        }

        long long value = wordMap[token];

        if (value == 100)
        { // e.g., "two hundred"
            currentNumber *= 100;
            // Handle case "hundred" (implies 100)
            if (currentNumber == 0)
                currentNumber = 100;
        }
        else if (value >= 1000 || value == 100000 || value == 10000000)
        { // Multipliers
            // Handle case "thousand" (implies 1000)
            if (currentNumber == 0)
                currentNumber = 1;

            total += currentNumber * value;
            currentNumber = 0;
        }
        else
        {
            currentNumber += value;
        }
    }
    total += currentNumber; // Add any remaining part

    // Handle "negative"
    if (resultStr.find("negative") != std::string::npos)
    {
        total = -total;
    }

    return total;
}

std::string processWordsToNumber()
{
    std::cout << "Enter words (e.g., forty-five thousand seven hundred rupees): ";
    std::string input;
    std::cin.ignore(); // Clear newline from previous input
    std::getline(std::cin, input);

    long long result = wordsToNumber(input);
    return std::to_string(result);
}

// --- Main Menu ---
void main_menu()
{
    int choice = 0;
    while (choice != 3)
    {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Number to Words\n";
        std::cout << "2. Words to Number\n";
        std::cout << "3. Exit\n";
        std::cout << "Your choice: ";

        if (!(std::cin >> choice))
        {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n'); // Discard bad input
            continue;
        }

        std::string output;
        switch (choice)
        {
        case 1:
            output = processNumberToWords();
            std::cout << "\nOutput: " << output << "\n";
            break;
        case 2:
            output = processWordsToNumber();
            std::cout << "\nOutput: " << output << "\n";
            break;
        case 3:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please select 1, 2, or 3.\n";
        }
    }
}

int main()
{
    main_menu();
    return 0;
}