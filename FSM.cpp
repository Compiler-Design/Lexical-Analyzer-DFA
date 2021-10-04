#include "FSM.h"

State::State(int index, char edge, State* prev=NULL)
{
    next=NULL;
    if(prev!=NULL)
        prev->next=this;
    this->index=index;
    this->edge=edge;
}
Head::Head(int index)
{
    next=NULL;
    this->index=index;
    isFinal=false;
}

FSM::FSM() : startState(-1)
{

}
void FSM::print(State* S)
{
    if(S==NULL)
        {cout<<endl;return;}
    cout<<"\tIndex : "<<S->index<<"  Inward Edge Character : "<<S->edge<<endl;
    print(S->next); 
}
void FSM::display_FSM()
{
    cout<<"\nStart State : "<<startState<<endl;
    for(vector<Head*>::iterator it=States.begin(); it!=States.end(); it++)
    {
        cout<<(*it)->index<<" "<<((*it)->isFinal ? "Final State" : "Not Final State")<<endl;
        print((*it)->next);
        cout<<endl;
    }
}
bool FSM::checkString(int currentState, string &s, int ci=0)
{
    if(ci==s.length())
        return States[currentState-1]->isFinal;
    char c=s[ci];
    State* temp=States[currentState-1]->next;
    while(temp!=NULL)
    {
        if(temp->edge==c)
            return checkString(temp->index, s, ci+1);
        temp=temp->next;
    }
    return false;
}
bool FSM::isPresent(string s)
{
    return checkString(startState, s);
}
bool FSM::buildFSM(ifstream& fin)
{
    fin.exceptions(ios::eofbit | ios::failbit | ios::badbit);
    try
    {
        int n, k, m;         //No of States, No of Final/Accepting States, No of characters in the Language
        fin>>n;
        States.reserve(n);
        for(int i=0;i<n;i++)
            States.push_back(new Head(i+1));    
            
        fin>>startState;    //Start State
            
        fin>>k;             //Final States
        int final_states;
        for(int i=0;i<k;i++)
        {
            fin>>final_states;
            States[final_states-1]->isFinal=true;
        }     

        fin>>m;             //Alphabet
        char alpha;
        alphabets.reserve(m);
        for(int i=0;i<m;i++)
        {
            fin>>alpha;
            alphabets.push_back(alpha);
        }

        //Transitions
        int state;
        for(int i=0;i<n;i++)
        {
            int j=-1;
            do
            {
                j++;
                fin>>state;
            }while (state==-1);
            
            State* temp=new State(state, alphabets[j]);
            States[i]->next=temp;
            
            j++;
            for(;j<m;j++)
            {
                fin>>state;
                if(state!=-1)
                    temp=new State(state, alphabets[j], temp);
            }
        }
    }
    catch(const exception& e)
    {
        cout<<"Error : Please check your \"config.txt\" file\n";
        cerr<<e.what()<<endl;
        return false;
    }    
    cout<<"\nFSM has been initialized...\n";
        
    //For Debug
    display_FSM();
    return true;
}
vector<bool> FSM::readStrings(ifstream &fin)
{
    vector<bool> Ans;
    try
    {
        int n; string s;
        fin>>n;
        Ans.reserve(n);
        for(int i=0;i<n;i++)
        {
            fin>>s;
            Ans.push_back(isPresent(s));
        }
        return Ans;
    }
    catch(const exception& e)
    {
        cout<<"Error - Process Terminated. Check \"config.txt\" file\n";
    }
    return Ans;
}
