/*
Name- Yuvraj Singh
Roll no.- 59
Section- ML2
Course-B.tech CSE with specialization in AI and ML
Branch-B.tech CSE'''
*/
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_STUDENTS 76

typedef struct Node {
    int roll;
    struct Node *next;
} Node;

int main() {
    int n;
    printf("Enter number of students in class (default 76): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        n = DEFAULT_STUDENTS;
    }

    // Adjacency Matrix space calculation
    // Matrix of size n x n integers
    size_t matrix_size = (size_t)n * n * sizeof(int);

    // Adjacency List space calculation
    // Array of n pointers + nodes for total edges E.
    // Average sparse friendship density assumption ~ 10 friends per student
    int avg_friends = 10;
    int total_edges = n * avg_friends;
    size_t list_size = (size_t)n * sizeof(Node*) + (size_t)total_edges * sizeof(Node);

    printf("\n--- Memory Representation Analysis for %d Students ---\n", n);
    printf("1. Adjacency Matrix Representation Size: %zu bytes\n", matrix_size);
    printf("2. Adjacency List Representation Size  : %zu bytes\n", list_size);

    if (list_size < matrix_size) {
        printf("\nResult: Adjacency List representation is better and takes %zu bytes LESS space.\n", matrix_size - list_size);
    } else {
        printf("\nResult: Adjacency Matrix representation is better and takes %zu bytes LESS space.\n", list_size - matrix_size);
    }

    return 0;
}
