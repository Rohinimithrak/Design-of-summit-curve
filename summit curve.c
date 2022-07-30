#include<stdio.h>
#include<math.h>
double squrt(double n){
    return sqrt(n);
}
double square(double x){
    return x*x;
}
int roundup(int l,int x){
    while(l%x!=0)
    l++;
    return l;
}
float maximum(float y[],int l){
    float max=y[0];
    for(int i=1;i<l;i++){
        if(y[i]>max)
        max=y[i];
    }
    return max;
}
int main(){
    float ssd,a,b,c,n,H,h,m,o,RL,max,dist;
    int L,len;
    printf("enter stopping site distance in m:");
    scanf("%f",&ssd);
    printf("enter gradient one:");
    scanf("%f",&a);
    printf("enter gradient two:");
    scanf("%f",&b);
    printf("enter chord length:");
    scanf("%f",&c);
    printf("enter height of driver (enter 1.2 if not given):");
    scanf("%f",&H);
    printf("enter height of object (enter 0.15 if not given):");
    scanf("%f",&h);
    printf("Enter RL of reference:");
    scanf("%f",&RL);
    n=(a-b)/100;
    L=(n*ssd*ssd)/(square(squrt(2*H)+(squrt(2*h))));
    if(L>=ssd){
        L=L;
    }
    else{
        L=(2*ssd)-(square(squrt(2*H)+(squrt(2*h)))/n);
    }
    L=roundup(L,c);
    len=(L/c)+1;
    int arr[len];
    int x[len];
    float y[len];
    float rl[len];
    int temp=0;
    for(int i=0;i<=len;i++)
    {
        arr[i]=i+1;
        x[i]=temp;
        temp=temp+c;
        y[i]=(x[i]*x[i])/((2*L)/n);
        y[i]=((a/100)*x[i])-y[i];
    }
    max=maximum(y,len);
    max=max+RL;
    dist=(a*L)/(a-b);
    printf("maximum value of RL is %f, at a diatance of %f",max,dist);
    return 0;
}
