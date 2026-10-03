#include <stdio.h>
#include <string.h>
#include <ctype.h>

char line[2011];
char str1[1005], str2[1005] = {0};
int A[1005], B[1005] , C[2010] = {0};

int main() {
    if (scanf("%1004s %1004s", str1, str2) !=2){
        printf("输入数字数量不正确");
        return 0;
    }
    //检查输入数字小于2的情况
    // 限制了读取的字符数量，防止越界

    
    int c;
    int bad = 0;
    while ((c = getchar()) != '\n' && c != EOF){
        if (!isspace(c)){
            bad = 1;
        }
    }
    // 检查缓存区是否有可见字符，顺便清理缓存区
    if (bad){
        printf("输入的数字过长或格式不正确\n");
        return 0;
    }


    for (int i =0; str1[i] != '\0'; i++){
        if (str1[i]<'0' || str1[i]>'9'){
            printf("非法输入\n");
            return 0;
        }
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i]<'0' || str2[i]>'9'){
            printf("非法输入\n");
            return 0;
        }
    }
    //检查输入是否为数字

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
