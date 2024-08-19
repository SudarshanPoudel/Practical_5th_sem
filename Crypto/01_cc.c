#include<stdio.h>
#include<string.h>

int alphaToNum(char c){
    if(c >= 'A' &&  c <= 'Z') return c-'A';
    else if(c >= 'a' && c <= 'z') return c-'a';
}
char numToChar(int n){
    return n+'A';
}

void caesarCipher(char text[], char result[], int isEncrypt){
    int i, num, j = 0;
    for(i=0; i < strlen(text); i++){
        num = alphaToNum(text[i]);
        if(isEncrypt == 1) 
            num = (num+3)%26;
        else 
            num = (num-3+26)%26;
        result[j++] = numToChar(num);
    }
    result[j] = '\0';
}

int main(){
    char pt[100], ct[100];
    printf("Encryption\n");
    printf("Enter plain text : ");
    scanf("%s", pt);
    caesarCipher(pt, ct, 1);
    printf("Cipher text is : %s\n\n", ct);
    printf("Decryption\n");
    printf("Enter Cipher text : ");
    scanf("%s", ct);
    caesarCipher(ct, pt, 0);
    printf("Plain text is : %s\n\n", pt);
    return 0;
}