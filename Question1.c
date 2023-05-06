#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    TypeTag type;
} Node;

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV
} TypeTag;

typedef struct FibNode {
    TypeTag type;
    int value;
} FibNode;

Node* makeFunc(TypeTag type) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    return node;
}

void calc(Node* node) {
    if (node->type == ADD) {
        FibNode* fibNode = (FibNode*)node;
        printf("add : %d\n", fibNode->value);
    } else if (node->type == MUL) {
        FibNode* fibNode = (FibNode*)node;
        printf("mul : %d\n", fibNode->value);
    } else if (node->type == SUB) {
        FibNode* fibNode = (FibNode*)node;
        printf("sub : %d\n", fibNode->value);
    } else if (node->type == DIV) {
        FibNode* fibNode = (FibNode*)node;
        printf("div : %d\n", fibNode->value);
    }
}

Node* fibonacci(int n) {
    if (n <= 0) {
        return NULL;
    }

    FibNode* fibNode = (FibNode*)malloc(sizeof(FibNode));
    fibNode->type = SUB;

    int fib1 = 0;
    int fib2 = 1;
    int fibN;

    if (n == 1) {
        fibN = fib1;
    } else if (n == 2) {
        fibN = fib2;
    } else {
        for (int i = 3; i <= n; ++i) {
            fibN = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibN;
        }
    }

    fibNode->value = fibN;
    return (Node*)fibNode;
}

int main() {
    Node* add = (*makeFunc(ADD))(10, 6);
    Node* mul = (*makeFunc(MUL))(5, 4);
    Node* sub = (*makeFunc(SUB))(mul, add);
    Node* fibo = (*makeFunc(SUB))(sub, NULL);

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}
