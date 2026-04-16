#include <stdio.h>

#define MAX 1000

int main() {
    int arr[MAX], n;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0, maxLen = 0;

    int map[20001];
    
    for(int i = 0; i < 20001; i++) {
        map[i] = -2;
    }

    map[10000] = -1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int key = prefixSum + 10000; 

        if(map[key] != -2) {
            int length = i - map[key];
            if(length > maxLen) {
                maxLen = length;
            }
        } else {
            map[key] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}