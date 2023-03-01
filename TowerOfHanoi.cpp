//
// Created by Shishir Garg on 19/10/22.
//

#include <iostream>
using namespace std;
void Hanoi(int n, char s, char aux, char dest){
    if(n==0){
        return;
    }
    Hanoi(n-1,  s,  dest,  aux);
    cout<<"move disk "<<n<<" from "<<s<<" to rod "<< dest<<endl;
    Hanoi( n-1, aux,  s,  dest);

}
int main(){
    {
        int N = 3;

        // A, B and C are names of rods
        Hanoi(N, 'A', 'C', 'B');
        return 0;
    }
return 0;
}


