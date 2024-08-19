#include<stdio.h>
#include<string.h>

int alphaToNum(char c){
    if(c >= 'A' &&  c <= 'Z') return c-'A';
    else if(c >= 'a' && c <= 'z') return c-'a';
}
char numToChar(int n){
    return n+'A';
}

void vigenereCipher(char text[], char key[], int isEncrypt){
    int i, num, keyNum;
    for(i=0; i < strlen(text); i++){
        num = alphaToNum(text[i]);
        keyNum = alphaToNum(key[i%strlen(key)]);
        if(isEncrypt == 1) 
            num = (num+keyNum)%26;
        else 
            num = (num-keyNum+26)%26;
        printf("%c", numToChar(num));
    }
    printf("\n\n");
}

int main(){
    char pt[100], ct[100], key[100];
    printf("Encryption\n");
    printf("Enter plain text : ");
    scanf("%s", pt);
    printf("Enter Key : ");
    scanf("%s", key);
    printf("Cipher text is : ");
    vigenereCipher(pt, key, 1);
    printf("Decryption\n");
    printf("Enter Cipher text : ");
    scanf("%s", ct);
    printf("Enter Key : ");
    scanf("%s", key);
    printf("Plain text is : ");
    vigenereCipher(ct, key, 0);
    return 0;
}