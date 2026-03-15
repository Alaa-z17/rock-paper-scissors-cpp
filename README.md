# ✊✋✌️ Rock Paper Scissors — C++

A console-based Rock Paper Scissors game built in **C++** demonstrating
core concepts of **Functional & Procedural Programming**.

---

## 🎯 Learning Objectives

- Structuring a program using functions (Procedural Programming)
- Separating logic, data, and display layers
- Using `enum` and `struct` as data models
- Passing data between functions cleanly
- Random number generation with `rand()` and `srand()`

---

## 🕹️ How to Play

1. Run the program
2. Choose how many rounds (1 to 10)
3. Enter your choice:
   - `1` = Stone
   - `2` = Paper
   - `3` = Scissors
4. The computer picks randomly
5. Best of N rounds wins!

> 🟢 Screen turns **green** if you win  
> 🔴 Screen turns **red** if you lose  
> 🟡 Screen turns **yellow** on a draw

---

## 🏗️ Project Architecture

```
main()
 └── StartGame()
      └── PlayGame()
           ├── ReadPlayer1Choice()
           ├── GetComputerChoice()
           ├── WhoWonTheRound()
           └── PrintRoundResults()
                └── SetWinnerScreenColor()
```

---

## 💡 Key Concepts

| Concept                  | Where in Code                                   |
| ------------------------ | ----------------------------------------------- |
| Enums as named constants | `enGameChoice`, `enWinner`                      |
| Structs as data models   | `stRoundInfo`, `stGameResults`                  |
| Pure logic functions     | `WhoWonTheRound()`, `RandomNumber()`            |
| Display functions        | `PrintRoundResults()`, `ShowFinalGameResults()` |
| Game loop                | `StartGame()`, `PlayGame()`                     |

---

## 🔧 Build & Run

**Windows (MinGW / g++)**

```bash
g++ rock-paper-scissors-cpp.cpp -o rps.exe
./rps.exe
```

**Or open in Visual Studio**

```
double click: rock-paper-scissors-cpp.slnx
Ctrl + F5
```

---

## 📁 File Structure

```
rock-paper-scissors-cpp/
├── .gitignore
├── README.md
├── LICENSE
├── rock-paper-scissors-cpp.slnx
└── rock-paper-scissors-cpp/
    ├── rock-paper-scissors-cpp.cpp
    ├── rock-paper-scissors-cpp.vcxproj
    └── rock-paper-scissors-cpp.vcxproj.filters
```

---

## 👤 Author

Built as a learning exercise in C++ Procedural Programming.

---

## 📄 License

MIT License
