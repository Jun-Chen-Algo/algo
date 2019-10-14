/*
*COMAPNY:HuaWei
*写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）
*输入一个十六进制的数值字符串。
*输出该数值的十进制字符串。
*Author:chenjun
*Date:2018/7/20 
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

char *Hex2Dec(char *inputHex)
{
    static char decString[128] = {0};
    float n = 0;
    int len = strlen(inputHex)-1;
    int n2 = 0;
     
    while(*inputHex != '\0'){
        if(*inputHex<='9'&&*inputHex>='0'){
            n = n+(*inputHex-'0')*pow(16, len);
        }
         if(*inputHex<='f'&&*inputHex>='a'){
            n = n+(*inputHex-'a'+10)*pow(16, len);
        }
         if(*inputHex<='F'&&*inputHex>='A'){
            n = n+(*inputHex-'A'+10)*pow(16, len);
        }
        len--;
        *(inputHex++);
    }
    n2 = (int)n;
    sprintf(decString, "%d", n2);
    return decString;
}
int main()
{
    char inputHex[32] = {0};
    char inputHex2[32] = {0};
     
    while (EOF != scanf("%s",inputHex)){
         
        if(inputHex[0] == '0'&&(inputHex[1] == 'x'|| inputHex[1] == 'X')){
            memcpy(inputHex2, inputHex+2, strlen(inputHex)-2);
        }else{
            memcpy(inputHex2, inputHex, strlen(inputHex));
        }
        printf("%s\n", Hex2Dec(inputHex2));
        memset(inputHex,0,sizeof(inputHex));
        memset(inputHex2,0,sizeof(inputHex2));
    }
}

