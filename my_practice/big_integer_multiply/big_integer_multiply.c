#include <stdio.h>
#include <string.h>

char str1[1005], str2[1005];
int A[1005], B[1005] = {0}, C[2010] = {0};

int main() {
    if (scanf("%s %s", str1, str2) !=2){
        printf("输入数字数量不正确");
        return 0;
    }

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 0; i<len1; i++){
        A[i] = str1[len1 -1 -i] -'0';
    }
    for (int i = 0; i<len2; i++){
        B[i] = str2[len2 -1 -i] -'0';
    }

    for (int i = 0; i<len1; i++){
        for (int j = 0; j<len2; j++){
            C[i+j] += A[i] *B[j];
        }
    }

    int lenC = len1 +len2;
    for (int i = 0; i<lenC; i++){
        if (C[i] >= 10){
            C[i+1] += C[i]/10;
            C[i] %= 10;
        }
    }

    int k = lenC -1;
    while (k>0  &&  C[k] == 0){
        k--;
    }

    for (int i = k; i >= 0; i--){
        printf("%d",C[i]);
    }
    printf("\n");
    
    return 0;
}