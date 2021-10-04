#ifndef FSM_H
#define FSM_H

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

struct State
{
    int index;
    char edge;
    State* next;
    State(int index, char edge, State* prev);
};
struct Head
{
    int index;
    bool isFinal;
    State* next;
    Head(int index);
};
class FSM
{
    private:
    vector<Head*> States;
    vector<char> alphabets;
    int startState;
    
    //For Debug
    void print(State* S);
    void display_FSM();
    //For checking if a string s belongs to the language
    bool checkString(int currentState, string &s, int ci);
    
    public:
    FSM();
    bool isPresent(string s);
    bool buildFSM(ifstream& fin);
    vector<bool> readStrings(ifstream &fin);
};

#endif