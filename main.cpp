#include "FSM.h"
using namespace std;
int main()
{
    ifstream fin;
    fin.open("config.txt", ios::in);
    FSM myFSM;
    if(myFSM.buildFSM(fin))
    {   
        char c;
        cout<<"Process Strings [Y/N] or Press 'X' to Terminate : ";
        do
        {
            cin>>c;
        }while (!(c=='Y'||c=='y'||c=='N'||c=='n'||c=='X'||c=='x'));

        if(c=='Y' || c=='y')
        {
            cout<<"Reading from File... Please Standby\n";
            vector<bool> present=myFSM.readStrings(fin);
            cout<<"\nResults :-\n";
            for(bool i:present)
                cout<<(i?"Yes\n":"No\n");
            cout<<endl;
        }
    }
    fin.close();
}