#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
unsigned int i = 0;
unsigned int arr[255];
void comp(vector<char> c)
{
    bool broken = false;
    unsigned int e= 255;
    for(unsigned int j = 0; j<c.size(); j++)
    {
        if(broken)
            break;
        char x = c.at(j);
        if(x=='+')
        {
            arr[i]++;
            arr[i]%=255;
        }
        else if(x=='-')
        {
            arr[i]--;
            arr[i]%=255;
        }
        else if(x=='>')
        {
            i++;
            i%=255;
        }
        else if(x=='<')
        {
            i--;
            i%=255;
        }
        else if(x=='.')
            cout << (char)arr[i];
        else if(x==',')
        {
            char a;
            cout << endl << "Input: " << endl;
            cin >> a;
            arr[i] = (int) a;
        }
        else if(x=='[')
        {
            vector<char> a;
            a.clear();
            unsigned int track = 1;
            for(unsigned int b = 1; b<c.size(); b++)
            {
                if(c.at(j+b)==']')
                {
                    track--;
                    if(track==0)
                        e = j+b;
                    else
                        a.push_back(c.at(j+b));
                }
                else if(c.at(j+b)=='[')
                {
                    track++;
                    a.push_back(c.at(j+b));
                }
                else
                    a.push_back(c.at(j+b));
                if(track==0)
                    break;
                else if(b == c.size()-1)
                    broken = true;
            }
            while(arr[i]!=0)
            {
                if(a.size()>0)
                    comp(a);
            }
            j = e;
        }
        else if(x==']')
           cout << "Pretty sure this shouldn't have been evaluated outside of where [ is so um yeah  awkward";
    }
    return;
}
int main()
{
    bool play = true;
    while(play)
    {
        system("cls");
        vector<char> c;
        c.clear();
        for(unsigned int m = 0; m<255; m++)
            arr[m] = 0;
        char a;
        cout << "BrainFuck: " << endl;
        cin >> a;
        while(a!='_')
        {
            c.push_back(a);
            cin >> a;
        }
        comp(c);
        system("pause>nul");
    }
    return 0;
}
