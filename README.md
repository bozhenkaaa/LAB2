# Finite Automaton Word Acceptance Checker(C++)

## Introduction

This program checks whether a given deterministic finite automaton (DFA) can accept any word in the form of `w = w0w1`, where `w0` is the user-input word. The program reads the automaton's description from a file named 'automaton.txt' and prints the evaluation result to the console.

## Input File Format (automaton.txt)

The file 'automaton.txt' must contain the following information regarding the DFA, in the given order:

1. Alphabet size (Number of symbols in the automaton's alphabet)
2. Number of states (i.e., the number of nodes in the DFA)
3. Initial state (Start state)
4. Number of final states
5. The list of final states (one at each line)
6. Transition table consisting of triplets (from_state, symbol, to_state)

Example:

```
3
4
0
1
1
0 0 1
0 1 3
0 2 0
1 0 2
1 1 4
1 2 2
2 0 3
2 1 1
2 2 2
3 0 4
3 1 3
3 2 3
4 0 1
4 1 1
4 2 1
```

## Usage

1. Compile the program:
```
g++ main.cpp -o main
```

2. Make sure 'automaton.txt' contains the proper description of the automaton you want to use.

3. Run the program:
```
./main
```

4. Enter the input string `w0`:
```
Enter w0: ab
```

5. Check the output result:
```
The automaton can accept a word of the form w = w0w1.
```

## Algorithm

The program follows these steps:

1. Reads the automaton from the 'automaton.txt' file.
2. Requests a string `w0` from the user.
3. Checks if the automaton can accept any word of the form w = w0w1 based on the given `w0` and the automaton's description.
4. Prints the result of the check to the console.

## Functions

1. `read_automaton()`: Reads the automaton description from the file.
2. `is_accepted_by_automaton()`: Checks if the DFA can accept the word w0.
3. `main()`: Reads the automaton, gets the user input, checks the acceptance, and prints the result.
