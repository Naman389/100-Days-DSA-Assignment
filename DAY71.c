#include <stdio.h>

#define EMPTY -1

int table[100];  
int m;          

int hashFunction(int key) {
    return key % m;
}

void insert(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == EMPTY) {
            table[newIndex] = key;
            return;
        }
    }
    printf("Hash Table Full\n");
}

void search(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[newIndex] == EMPTY) {
            break;  
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    int n;
    scanf("%d", &m);  

    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    scanf("%d", &n);  

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {       
            insert(key);
        } else if (op[0] == 'S') {
            search(key);
        }
    }

    return 0;
}