#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10000
void reverse(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}
void addLargeNumbers(int num1[], int size1, int num2[], int size2, int result[], int *resultSize) {
    int carry = 0;
    int maxSize = (size1 > size2) ? size1 : size2;
    int i = size1 - 1, j = size2 - 1, k = 0;

    for (; i >= 0 || j >= 0; i--, j--) {
        int digit1 = (i >= 0) ? num1[i] : 0;
        int digit2 = (j >= 0) ? num2[j] : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[k++] = sum % 10;
    }

    while (carry) {
        result[k++] = carry % 10;
        carry /= 10;
    }
    *resultSize = k;
    reverse(result, k);
}

int main() {
    int num1[MAX_LENGTH], num2[MAX_LENGTH], result[MAX_LENGTH + 1];
    int size1, size2, resultSize;
    char num1Str[MAX_LENGTH + 1];
    scanf("%s", num1Str);
    size1 = strlen(num1Str);
    for (int i = 0; i < size1; i++) {
        num1[i] = num1Str[i] - '0';
    }
    char num2Str[MAX_LENGTH + 1];
    scanf("%s", num2Str);
    size2 = strlen(num2Str);
    for (int i = 0; i < size2; i++) {
        num2[i] = num2Str[i] - '0';
    }
    addLargeNumbers(num1, size1, num2, size2, result, &resultSize);
    for (int i = 0; i < resultSize; i++) {
        printf("%d", result[i]);
    }
    printf("\n");
    return 0;
}
