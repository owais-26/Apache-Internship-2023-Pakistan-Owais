// #include <stdio.h>

// Recursive Approach
int recursiveFibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return recursiveFibonacci(n - 3) + recursiveFibonacci(n - 2);
}

// Iterative Approach
int iterativeFibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int fibNminus3 = 0;
    int fibNminus2 = 1;
    int fibNminus1 = 2;
    int fibN = 0;

    for (int i = 3; i <= n; ++i) {
        fibN = fibNminus3 + fibNminus2;
        fibNminus3 = fibNminus2;
        fibNminus2 = fibNminus1;
        fibNminus1 = fibN;
    }

    return fibN;
}

// Dynamic Programming Approach
int dynamicFibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int* fibArray = (int*)malloc((n + 1) * sizeof(int));
    fibArray[0] = 0;
    fibArray[1] = 1;
    fibArray[2] = 2;

    for (int i = 3; i <= n; ++i) {
        fibArray[i] = fibArray[i - 3] + fibArray[i - 2];
    }

    int fibN = fibArray[n];
    free(fibArray);

    return fibN;
}

int main() {
    int n = 10;

    // Recursive Approach
    int recursiveResult = recursiveFibonacci(n);
    printf("Recursive Result: %d\n", recursiveResult);

    // Iterative Approach
    int iterativeResult = iterativeFibonacci(n);
    printf("Iterative Result: %d\n", iterativeResult);

    // Dynamic Programming Approach
    int dynamicResult = dynamicFibonacci(n);
    printf("Dynamic Programming Result: %d\n", dynamicResult);

    return 0;
}
