# Repository-2-Number-To-Words
NumWord-Pro: Ultimate Number ↔ Words Converter. Multi-language utility in C/C++/C# supporting Indian (Lakh/Crore) and International (Million/Billion) systems. Features precise decimal, currency, and large number handling.

Markdown

# 🔢 NumWord-Pro [C++]
[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](.)
[![Standard](https://img.shields.io/badge/Standard-C%2B%2B17-blueviolet.svg)](.)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-orange)](.)

**A professional, terminal-friendly C++ utility for seamless two-way conversion between numbers and their word representations. This tool features robust support for both Indian (Lakh, Crore) and International (Million, Billion) numbering systems.**

This repository contains the **modern C++ implementation** of NumWord-Pro, built for performance and accuracy.



---

## ✨ Core Features

* **🔄 Bidirectional Conversion:**
    * **Number → Words:** Convert `152.45` to "One hundred fifty-two rupees and forty-five paise".
    * **Words → Number:** Parse "Forty-five thousand seven hundred rupees" into `45700`.

* **🌐 Dual Numbering System:**
    * **Indian System:** Correctly handles scales like `Thousand`, `Lakh`, and `Crore`.
    * **International System:** Correctly handles scales like `Thousand`, `Million`, and `Billion`.

* **💰 Smart Currency & Decimal Handling:**
    * Automatically appends "rupees" and "paise".
    * Handles singular/plural forms ("1 rupee" vs "2 rupees").
    * Processes decimal values for precise financial conversions.

* **🧠 Modern C++ Design:**
    * Leverages **C++17** features for clean, modular code.
    * Utilizes `std::map` for an efficient and high-speed word parsing engine.
    * Employs `std::string` and `std::vector` for robust string and data manipulation.

* **🚀 Robust & Efficient:**
    * Handles 64-bit signed integers (up to ~9.2 Quintillion).
    * Includes comprehensive error handling for invalid or malformed inputs.

---

## 🛠️ Tech Stack

* **Language:** C++17
* **Core Libraries:** Standard Template Library (STL)
* **Compiler Support:** GCC (g++), Clang, MSVC (cl.exe)

---

## 🚀 Getting Started

Clone the repository to your local machine:
```bash
git clone [https://github.com/YourUsername/NumWord-Pro-CPP.git](https://github.com/YourUsername/NumWord-Pro-CPP.git)
cd NumWord-Pro-CPP
Compile and Run
On Linux / macOS
Bash

g++ -std=c++17 -o converter converter.cpp
./converter
On Windows (with MSVC)
Bash

cl.exe /std:c++17 /EHsc converter.cpp
./converter.exe
💡 How to Use
Once running, the program presents a simple menu:

--- Main Menu ---
1. Number to Words
2. Words to Number
3. Exit
Your choice:
Select a mode (1 or 2).

Follow the on-screen prompts to enter your number or words.

Get your converted output instantly.

🤝 Contributing
Contributions, issues, and feature requests are welcome!

Fork the Project

Create your Feature Branch (git checkout -b feature/NewFeature)

Commit your Changes (git commit -m 'Add some NewFeature')

Push to the Branch (git push origin feature/NewFeature)

Open a Pull Request

📄 License
This project is distributed under the MIT License. See LICENSE for more information.


---

### 2. C# रिपॉजिटरी के लिए (README.md)

```markdown
# 🔢 NumWord-Pro [C#]
[![Language](https://img.shields.io/badge/Language-C%23-purple.svg)](.)
[![Framework](https://img.shields.io/badge/Framework-.NET%20Core-blueviolet.svg)](.)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-orange)](.)

**A professional, terminal-friendly C# utility for seamless two-way conversion between numbers and their word representations. This tool features robust support for both Indian (Lakh, Crore) and International (Million, Billion) numbering systems.**

This repository contains the **modern C# implementation** of NumWord-Pro, built on the **.NET Core** platform for cross-platform reliability.



---

## ✨ Core Features

* **🔄 Bidirectional Conversion:**
    * **Number → Words:** Convert `152.45` to "One hundred fifty-two rupees and forty-five paise".
    * **Words → Number:** Parse "Forty-five thousand seven hundred rupees" into `45700`.

* **🌐 Dual Numbering System:**
    * **Indian System:** Correctly handles scales like `Thousand`, `Lakh`, and `Crore`.
    * **International System:** Correctly handles scales like `Thousand`, `Million`, and `Billion`.

* **💰 Smart Currency & Decimal Handling:**
    * Automatically appends "rupees" and "paise".
    * Handles singular/plural forms ("1 rupee" vs "2 rupees").
    * Processes decimal values for precise financial conversions.

* **🧠 Modern C# Design:**
    * Clean, object-oriented code built for the .NET runtime.
    * Utilizes `Dictionary<string, long>` for an efficient word parsing engine.
    * Employs modern C# features for robust string and error handling.

* **🚀 Cross-Platform & Efficient:**
    * Runs anywhere .NET Core is supported (Windows, Linux, macOS).
    * Handles 64-bit signed integers (`long`) up to ~9.2 Quintillion.

---

## 🛠️ Tech Stack

* **Language:** C#
* **Framework:** .NET Core (compatible with .NET 5/6/7/8+)
* **Core Libraries:** System.Collections.Generic, System.Linq

---

## 🚀 Getting Started

Ensure you have the **.NET SDK** (version 5.0 or higher) installed.

Clone the repository to your local machine:
```bash
git clone [https://github.com/YourUsername/NumWord-Pro-CS.git](https://github.com/YourUsername/NumWord-Pro-CS.git)
cd NumWord-Pro-CS
Run the Application
The simplest way to run the project is using the dotnet CLI:

Bash

dotnet run
This will automatically compile and execute the program.

💡 How to Use
Once running, the program presents a simple menu:

--- Main Menu ---
1. Number to Words
2. Words to Number
3. Exit
Your choice:
Select a mode (1 or 2).

Follow the on-screen prompts to enter your number or words.

Get your converted output instantly.

🤝 Contributing
Contributions, issues, and feature requests are welcome!

Fork the Project

Create your Feature Branch (git checkout -b feature/NewFeature)

Commit your Changes (git commit -m 'Add some NewFeature')

Push to the Branch (git push origin feature/NewFeature)

Open a Pull Request

📄 License
This project is distributed under the MIT License. See LICENSE for more information.


---

### 3. C रिपॉजिटरी के लिए (README.md)

```markdown
# 🔢 NumWord-Pro [C]
[![Language](https://img.shields.io/badge/Language-C-blue.svg)](.)
[![Standard](https://img.shields.io/badge/Standard-C99-lightgrey.svg)](.)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-orange)](.)

**A lightweight, portable, and professional C utility for number-to-word conversion. This terminal-friendly tool is written in pure C (C99) and supports both Indian (Lakh, Crore) and International (Million, Billion) numbering systems.**

This repository contains the **C implementation** of NumWord-Pro, focusing on performance, portability, and minimal dependencies.



---

## ✨ Core Features

* **➡️ Number → Words Conversion:**
    * Accurately converts `152.45` to "One hundred fifty-two rupees and forty-five paise".

* **⬅️ Words → Number Conversion:**
    * Includes a parser to convert text like "Forty-five thousand" into `45000`. (Note: The C implementation is a foundational parser).

* **🌐 Dual Numbering System:**
    * **Indian System:** Correctly handles scales like `Thousand`, `Lakh`, and `Crore`.
    * **International System:** Correctly handles scales like `Thousand`, `Million`, and `Billion`.

* **💰 Smart Currency & Decimal Handling:**
    * Automatically appends "rupees" and "paise".
    * Handles singular/plural forms ("1 rupee" vs "2 rupees").

* **🚀 Lightweight & Portable:**
    * Written in standard **C99**.
    * No external libraries or dependencies are required.
    * Compiles cleanly with GCC, Clang, and MSVC.

* **💪 Robust:**
    * Handles 64-bit signed integers (`long long`) up to ~9.2 Quintillion.
    * Safe string handling to prevent buffer overflows.

---

## 🛠️ Tech Stack

* **Language:** C (C99)
* **Core Libraries:** C Standard Library (`stdio.h`, `string.h`, `stdlib.h`, `ctype.h`)

---

## 🚀 Getting Started

Clone the repository to your local machine:
```bash
git clone [https://github.com/YourUsername/NumWord-Pro-C.git](https://github.com/YourUsername/NumWord-Pro-C.git)
cd NumWord-Pro-C
Compile and Run
On Linux / macOS (using GCC)
Bash

gcc -std=c99 -o converter converter.c
./converter
On Windows (with MSVC)
Bash

cl.exe converter.c
./converter.exe
💡 How to Use
Once running, the program presents a simple menu:

--- Main Menu ---
1. Number to Words
2. Words to Number
3. Exit
Your choice:
Select a mode (1 or 2).

Follow the on-screen prompts to enter your number or words.

Get your converted output instantly.

🤝 Contributing
Contributions, issues, and feature requests are welcome!

Fork the Project

Create your Feature Branch (git checkout -b feature/NewFeature)

Commit your Changes (git commit -m 'Add some NewFeature')

Push to the Branch (git push origin feature/NewFeature)

Open a Pull Request

📄 License
This project is distributed under the MIT License. See LICENSE for more information.