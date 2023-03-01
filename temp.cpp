long long (vector<int> a, vector<int>b, int n, int k){
    long long ans=0;
    sort(b.begin(),b.end());
    while(k!=0){
        for(int i = 0;i<n-1;i++){
            int temp = b[i + 1] - b[i];
            if(k>=temp){
                b[i]+=temp;
                k-=temp;
            }
            else if(k<temp){
                break;
            }
        }
    }
    return b[0];
}