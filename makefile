# For Windows System
# mylex.exe: main.o FSM.o
# 	g++ main.o FSM.o -o mylex

# For Linux System
mylex: main.o FSM.o
	g++ main.o FSM.o -o mylex

main.o: main.cpp
	g++ -c main.cpp -o main.o

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