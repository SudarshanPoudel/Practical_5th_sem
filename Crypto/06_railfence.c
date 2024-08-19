#include <stdio.h>
#include <string.h>

void railFence(char text[], char result[], int isEncrypt) {
    int len = strlen(text), i, j, k;
    if(isEncrypt == 1){
        for(i = 0, j = 0; i<len; i++)
            if(i%2 == 0) result[j++] = text[i];
        for(i = 0; i<len; i++)
            if(i%2 == 1) result[j++] = text[i];
    }
    else{
        if(len%2 == 0) k = len/2;
        else k = len/2 + 1;
        for(i = 0, j = 0; i < k; i++){
            result[j] = text[i];
            j = j+2;
        } 
        for(i = k, j = 1; i < k; i++){
            result[j] = text[i];
            j = j+2;
        } 
    }
    result[len] = '\0';
}

int main() {
    char pt[100], ct[100];
    
    printf("Encryption\n");
    printf("Enter plain text : ");
    scanf("%s", pt);
    railFence(pt, ct, 1);
    printf("Cipher text is : %s\n\n", ct);

    printf("Decryption\n");
    printf("Enter cipher text : ");
    scanf("%s", ct);
    railFence(ct, pt, 0);
    printf("Plain text is : %s\n\n", pt);

    return 0;
}
