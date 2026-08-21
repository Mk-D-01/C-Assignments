#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

int adjMatrix[MAX_STUDENTS + 1][MAX_STUDENTS + 1];

void analyzeFriendship(int totalStudents, int r1, int r2) {
    printf("\n--- Friendship Analysis for Roll No %d and Roll No %d ---\n", r1, r2);

    if (adjMatrix[r1][r2]) {
        printf("Roll No %d and Roll No %d ARE friends.\n", r1, r2);
    } else {
        printf("Roll No %d and Roll No %d ARE NOT friends.\n", r1, r2);
    }

    // Mutual Friends (friends with both r1 and r2)
    printf("\nMutual Friends: ");
    int mutualCount = 0;
    for (int i = 1; i <= totalStudents; i++) {
        if (i != r1 && i != r2 && adjMatrix[r1][i] && adjMatrix[r2][i]) {
            printf("%d ", i);
            mutualCount++;
        }
    }
    if (mutualCount == 0) printf("None");
    printf("\n");

    // Students who are NOT friends with both of them
    printf("\nStudents not friends with both Roll No %d and Roll No %d: ", r1, r2);
    int nonFriendCount = 0;
    for (int i = 1; i <= totalStudents; i++) {
        if (i != r1 && i != r2 && !adjMatrix[r1][i] && !adjMatrix[r2][i]) {
            printf("%d ", i);
            nonFriendCount++;
        }
    }
    if (nonFriendCount == 0) printf("None");
    printf("\n");
}

int main() {
    int numStudents;
    printf("Enter number of students (e.g. 10 or 76): ");
    if (scanf("%d", &numStudents) != 1) return 0;

    printf("Enter adjacency matrix (%d x %d):\n", numStudents, numStudents);
    for (int i = 1; i <= numStudents; i++) {
        for (int j = 1; j <= numStudents; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    int r1, r2;
    printf("\nEnter two roll numbers to inspect: ");
    if (scanf("%d %d", &r1, &r2) == 2) {
        if (r1 >= 1 && r1 <= numStudents && r2 >= 1 && r2 <= numStudents) {
            analyzeFriendship(numStudents, r1, r2);
        } else {
            printf("Invalid roll numbers.\n");
        }
    }

    return 0;
}
