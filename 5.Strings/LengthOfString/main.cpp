#include <iostream>

using namespace std;

int main()
{
    cout << "Length of String: " << endl;
    char *s="Welcome";
    int i;
    for(i=0;s[i]!='\0';i++){}
    cout<<"Length of String is "<<i<<endl;
    return 0;
}
