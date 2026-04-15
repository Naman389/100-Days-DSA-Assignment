#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char candidates[MAX][LEN];
    int count[MAX] = {0};
    int unique = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < unique; j++) {
            if (strcmp(votes[i], candidates[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(candidates[unique], votes[i]);
            count[unique] = 1;
            unique++;
        }
    }

    int maxVotes = 0;
    char winner[LEN];

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, candidates[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(candidates[i], winner) < 0) {
                strcpy(winner, candidates[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}