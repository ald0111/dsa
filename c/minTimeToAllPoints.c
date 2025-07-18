#include<stdio.h>

int findDistance(int x1, int y1, int x2, int y2) {
    int a = x2-x1;
    int b = y2-y1;
    if(a<0) a*=-1;
    if(b<0) b*=-1;
    if (a>b)
    {
        return a;
    } else {
        return b;
    }
    return 0;
}


int findMinDistance(int n) {
    if(n<=1) return 0;
    int tot=0;
    int x1,x2,y1,y2;
    scanf("%d %d",&x1,&y1);
    for(int i=2; i<=n; i++) {
        scanf("%d %d",&x2,&y2);
        int t = findDistance(x1,y1,x2,y2);
        // printf("%d \t",t);
        tot += t;
        x1=x2;
        y1=y2;
    }
    return tot;
}

int main() {
    int n;
    scanf("%d",&n);
    int t = findMinDistance(n);
    printf("%d",t);
    return 0;
}