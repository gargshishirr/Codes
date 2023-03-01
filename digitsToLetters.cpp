
#include <iostream>
using namespace std;
void digitsToLetters(int q){
    if(q==0)
        return;
    int z=q%10;
    string arr[10]={"zero", "one", "two", "three", "four", "five" , "six", "seven", "eight", "nine"};
    q=q/10;

    digitsToLetters(q);
    cout<<arr[z]<<" ";
}
int main(){
    int n;
    cin>>n;
    digitsToLetters(n);

    return 0;
}