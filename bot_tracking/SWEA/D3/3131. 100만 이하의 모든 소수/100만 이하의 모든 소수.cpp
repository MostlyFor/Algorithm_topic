#include<iostream>
 
using namespace std;
 
bool arr[1000001];
 
int main(void){
    printf("2 ");
    fill_n(arr,1000001,true);
    for(int i=3;i<1000000;i+=2){
        if(i%2==1){
            if(arr[i]==true){
                printf("%d ",i);
                for(int j=i*2;j<=1000000;j+=i){
                    arr[j]=false;
                }
            }
        }
    }
    printf("\n");
}