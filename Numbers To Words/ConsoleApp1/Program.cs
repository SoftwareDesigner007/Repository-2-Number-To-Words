using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;



public class Program
{
    // --- Number to Words ---

    private static readonly string[] ones = {
        "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
        "seventeen", "eighteen", "nineteen"
    };
    private static readonly string[] tens = {
        "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    // Helper for N->W: Converts a number 0-999 to words
    private static string ConvertChunk(long n)
    {
        var s = new StringBuilder();
        if (n >= 100)
        {
            s.Append(ones[n / 100] + " hundred");
            n %= 100;
            if (n > 0) s.Append(" ");
        }
        if (n >= 20)
        {
            s.Append(tens[n / 10]);
            n %= 10;
            if (n > 0) s.Append("-");
        }
        if (n > 0)
        {
            s.Append(ones[n]);
        }
        return s.ToString();
    }

    // Main N->W function
    public static string NumberToWords(long num, int mode)
    {
        if (num == 0) return "zero";

        var result = new StringBuilder();
        if (num < 0)
        {
            result.Append("negative ");
            num = -num;
        }

        var parts = new List<string>();

        if (mode == 1) // International System
        {
            var scales = new[] { "", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion" };
            int scaleIndex = 0;

            while (num > 0)
            {
                if (num % 1000 != 0)
                {
                    string chunk = ConvertChunk(num % 1000);
                    if (scaleIndex > 0)
                    {
                        chunk += " " + scales[scaleIndex];
                    }
                    parts.Add(chunk);
                }
                num /= 1000;
                scaleIndex++;
            }
        }
        else // Indian System
        {
            var scales = new[] { "", "thousand", "lakh", "crore", "arab", "kharab", "neel", "padma" };

            // Handle first chunk (up to 999)
            if (num > 0)
            {
                parts.Add(ConvertChunk(num % 1000));
                num /= 1000;
            }

            // Handle chunks of 100 (lakh, crore, etc.)
            int scaleIndex = 1;
            while (num > 0 && scaleIndex < scales.Length)
            {
                if (num % 100 != 0)
                {
                    parts.Add(ConvertChunk(num % 100) + " " + scales[scaleIndex]);
                }
                num /= 100;
                scaleIndex++;
            }
        }

        parts.Reverse();
        result.Append(string.Join(" ", parts.Where(p => !string.IsNullOrEmpty(p))));
        return result.ToString();
    }

    private static string ProcessNumberToWords()
    {
        Console.Write("Select system:\n1. International (Million, Billion)\n2. Indian (Lakh, Crore)\nChoice: ");
        if (!int.TryParse(Console.ReadLine(), out int mode) || (mode != 1 && mode != 2))
        {
            return "Error: Invalid mode selected.";
        }

        Console.Write("Enter a number (e.g., 152.45 or 45789): ");
        string input = Console.ReadLine() ?? "";

        long integerPart = 0;
        long decimalPart = 0;

        string[] parts = input.Split('.');
        string integerStr = parts[0];
        string decimalStr = (parts.Length > 1) ? parts[1] : "";

        if (decimalStr.Length > 2) decimalStr = decimalStr.Substring(0, 2);
        else if (decimalStr.Length == 1) decimalStr += '0';

        if (!long.TryParse(integerStr, out integerPart))
        {
            return "Error: Invalid number format or number is too large.";
        }
        if (!string.IsNullOrEmpty(decimalStr) && long.TryParse(decimalStr, out long dec))
        {
            decimalPart = dec;
        }

        string rupeeWord = (Math.Abs(integerPart) == 1) ? " rupee" : " rupees";
        string paiseWord = (decimalPart == 1) ? " paisa" : " paise";

        string result = NumberToWords(integerPart, mode) + rupeeWord;

        if (decimalPart > 0)
        {
            result += " and " + NumberToWords(decimalPart, mode) + paiseWord;
        }

        // Capitalize first letter
        if (string.IsNullOrEmpty(result)) return "";
        return char.ToUpper(result[0]) + result.Substring(1);
    }

    // --- Words to Number ---

    private static readonly Dictionary<string, long> wordMap = new Dictionary<string, long>
    {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10},
        {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15},
        {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
        {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50}, {"sixty", 60},
        {"seventy", 70}, {"eighty", 80}, {"ninety", 90},
        {"hundred", 100}, {"thousand", 1000}, {"million", 1000000}, {"billion", 1000000000},
        {"trillion", 1000000000000}, {"quadrillion", 1000000000000000}, {"quintillion", 1000000000000000000},
        {"lakh", 100000}, {"crore", 10000000}, {"arab", 1000000000}, {"kharab", 100000000000}
    };

    public static long WordsToNumber(string text)
    {
        // 1. Preprocess: to lower, remove 'and', 'rupees', etc., and hyphens
        text = text.ToLowerInvariant()
                   .Replace("-", " ")
                   .Replace(" and ", " ");

        // Remove currency words
        text = Regex.Replace(text, @"\b(rupees|rupee|paisa|paise)\b", "");

        bool isNegative = false;
        if (text.Contains("negative"))
        {
            isNegative = true;
            text = text.Replace("negative", "");
        }

        // Tokenize
        var tokens = text.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                         .Where(t => wordMap.ContainsKey(t))
                         .Select(t => t);

        if (!tokens.Any()) return 0;

        long total = 0;
        long currentNumber = 0;

        foreach (var token in tokens)
        {
            long value = wordMap[token];

            if (value == 100) // "hundred"
            {
                currentNumber *= 100;
                if (currentNumber == 0) currentNumber = 100;
            }
            else if (value >= 1000 || value == 100000 || value == 10000000) // Multipliers
            {
                if (currentNumber == 0) currentNumber = 1;
                total += currentNumber * value;
                currentNumber = 0;
            }
            else
            {
                currentNumber += value;
            }
        }
        total += currentNumber;

        return isNegative ? -total : total;
    }

    private static string ProcessWordsToNumber()
    {
        Console.Write("Enter words (e.g., forty-five thousand seven hundred rupees): ");
        string input = Console.ReadLine() ?? "";

        long result = WordsToNumber(input);
        return result.ToString();
    }

    // --- Main Menu ---
    public static void Main(string[] args)
    {
        int choice = 0;
        while (choice != 3)
        {
            Console.WriteLine("\n--- Main Menu ---");
            Console.WriteLine("1. Number to Words");
            Console.WriteLine("2. Words to Number");
            Console.WriteLine("3. Exit");
            Console.Write("Your choice: ");

            if (!int.TryParse(Console.ReadLine(), out choice))
            {
                Console.WriteLine("Invalid input. Please enter a number.");
                continue;
            }

            string output = "";
            try
            {
                switch (choice)
                {
                    case 1:
                        output = ProcessNumberToWords();
                        Console.WriteLine($"\nOutput: {output}");
                        break;
                    case 2:
                        output = ProcessWordsToNumber();
                        Console.WriteLine($"\nOutput: {output}");
                        break;
                    case 3:
                        Console.WriteLine("Exiting...");
                        break;
                    default:
                        Console.WriteLine("Invalid choice. Please select 1, 2, or 3.");
                        break;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"An error occurred: {ex.Message}");
            }
        }
    }
}