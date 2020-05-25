//
// Created by Kina on 2020/05/25.
//
long long sum(int *a, int n) {
    long long sum=0;
    int i=0;
    for(i=0; i+7<n; i+=8){
        sum += a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7];
    }
    for(;i<n; i++){
        sum+=a[i];
    }
    return sum;
}
