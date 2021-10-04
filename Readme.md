# Compiler Design Programming Assignment
**Objective** : Develop a generic Table driven Lexical Analyzer (using FSM, i.e., DFA) to determine if the input strings belong to the Language defined by it.

**Implementation** : The DFA is simulated using a ***Graph*** using an *Adjacency List*. The *Node (analogous to States)* at each index of the *Vector (which contains all the Different States)* stores a *Linked List* which will determine all the different nodes that are reachable from that State on processing a particular character.


## Input Format

The input for setting up the Lexical Analyzer is handled using a file **"config.txt"** present in the root directory. The format must be as given below :

* The first line of the file contains an integer, n representing the number of states. The states are numbered from 1 to n
* The second line contains an integer $S_{0}$ representing the starting state, where $1 ≤ S_{0} ≤ n$
* The third line contains an integer, k, representing the number of final states
* The next line contains k integers which represent the final states. Integers are separated by a whitespace
* The next line contains an integer, m representing the number of symbols in the input alphabet. Let them be $c_{1}, c_{2}, \dots,c_{n}$
* The next line contains the list of input symbols, L where each symbol c is separated by whitespace and $\langle c_{1}, c_{2}, \dots,c_{n}\rangle \in \{a \dots z\}$
* The next n lines describe the DFA state transitions. Each line will contain m number of integers, the integer at index (i, p) will tell you what the transition should be if you are in State i, and the next character is p. If the number is -1, it means there is no transition from that State for the given symbol. (Given *$i \in [1..n]$ and $p \in [1..m]$*)
* The next line after the matrix contains an integer representing the number of strings, $N_{s}$
* Next $N_{s}$ lines contain the strings which your Program should determine whether each String belongs to the language of the DFA or not
<br>

***Some Additional Information/Instructions***

1. If the **"config.txt"** file is not in accordance with the above conditions, then the Program will throw an Error.
2. An additional prompt on whether to process the strings or not has to be entered by the user on the terminal. 
```
    
    character input
    print "Process Strings [Y/N] or Press 'X' to Terminate : "
    
    repeatedly
        read input from user
    until (input is not {'Y' or 'y' or 'N' or 'n' or 'X' or 'x'})

    if(c is 'Y' or c is 'y')
        # Then the Input Strings present in the file will be processed 
    else
        # Otherwise, the Program will be terminated

```

## Output Format

If there are no errors in the **"config.txt"** then the Output will be displayed in the terminal as follows :


**![Screenshot of Output Here](https://user-images.githubusercontent.com/70936222/132944812-f5408566-d315-43a3-a516-16a7215848d5.PNG)**

* The first part of the Output contains information about the DFA (for Debug purposes)
```
    <State No_A> : <Is Final/Accepting State>
        Index : <State No_X>   Inward Edge Character : <alphabet_a>
        .
        .
        Index : <State No_Y>   Inward Edge Character : <alphabet_z>

        i.e. Contains all the various States that can be reached from the current State,
        on reading the current character of the String (Inward Edge Character)
```
    
**Note** : It only contains the states to which transition is possible on reading a particular character
If a transition from the current State to another State is not possible for a particular character in the alphabet, it is not displayed.

* Then, based on the User prompt, the Results on processing the String (s) are displayed on subsequent lines.

*Example of How a DFA is stored in the Program*

**![Example representation of how the DFA is stored in the Program](https://user-images.githubusercontent.com/70936222/132949850-99a4b066-0f74-4293-81f6-a6a07cd687ff.PNG)**


## Procedure

* The DFA accepts the input string and progresses to the next State (if possible) on reading each character.
* If it's not possible to make a transition from the current State on reading the current character, then the String will not be accepted, and **false** is returned.
* And if at the end of processing the entire String, if the last State is an Accepting/Final State, then the String will be accepted, and **true** is returned. 

> Note : The DFA does not accept "" or empty strings and are ignored by it. It was not implemented as the solution is different in Windows and Linux systems.
>
> The Problem was encountered because end of line in Linux and Windows are apprehended differently

#### Makefile

```makefile

# Used to compile the ".o files" to the executable "mylex"
mylex: main.o FSM.o
    g++ main.o FSM.o -o mylex

# Compiles "main.cpp" to an object file "main.o"
main.o: main.cpp
    g++ -c main.cpp -o main.o

# Compiles "FSM.cpp" to an object file "FSM.o"
FSM.o: FSM.cpp FSM.h
    g++ -c FSM.cpp -o FSM.o

# To Clear the *.o and executable files in a Linux System
clear_linux:
    rm *.o
    rm mylex

# To Clear the *.o and executable files in a Git-Bash
clear_git:
    rm *.o
    rm *.exe

# To Clear the *.o and executable files in Windows cmd
clear_win:
    del *.o
    del *.exe
```