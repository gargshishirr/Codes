#include <iostream>
using namespace std;

int main() {
    int a;
    cin>>a;
    int y;
    int s=0;

    while (a--)
    {
        int x;
        cin>>x;
        while (x>0)
        {
            y=x%10;
            x=x/10;
            s=s+y;
            cout<<s<<endl;
        }

    }
    return 0;
}
