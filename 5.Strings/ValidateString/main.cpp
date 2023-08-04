#include <iostream>

using namespace std;

int validate(string name)
{
    for(int i=0;name[i]!='\0';i++)
    {
        if(!(name[i]>=65 && name[i]<=90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    cout << "Validating a String:" << endl;
    string n="Anil321";
    string n1="Swaraj?123";
    if(validate(n)==1)
    {
        cout<<n<<" is valid String"<<endl;
    }
    else
    {
        cout<<n<<" is Invalid String"<<endl;
    }

    if(validate(n1)==1)
    {
        cout<<n1<<" is valid String"<<endl;
    }
    else
    {
        cout<<n1<<" is Invalid String"<<endl;
    }
    return 0;
}
