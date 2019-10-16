#include <iostream>
using namespace std;

int primes[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int answer[20] = {0};

bool primo(int a){
    for(int i=0; i<13 ;i++){
        if (primes[i] == a)
            return true;
    }
    return false;
}
void alg_compare(int inicio_fin, int n, bool *pares){
    if (inicio_fin == n) {
        if (!primo(answer[n - 1] + 1))
            return;
        printf("1");
        for (int i = 1; i < n; i++)
            printf(" %d", answer[i]);
        printf("\n");
        return;
    }
    for (int i = 2; i <= n; ++i) {
        if (pares[i])
            continue;
        if (primo(i + answer[inicio_fin - 1])) {
            pares[i] = true;
            answer[inicio_fin] = i;
            alg_compare(inicio_fin + 1, n, pares);
            pares[i] = false;
        }
    }
}
int main(){
    int num, casenum = 0;
    answer[0] = 1;
    while (scanf("%d", &num) != EOF) {
        if (casenum == 0) {
            printf("Case %d:\n", casenum + 1);
            bool pares[20] = {false};
            alg_compare(1, num, pares);
            casenum++;
        }else {
            casenum++;
            printf("\nCase %d:\n", casenum);
            bool pares[20] = {false};
            alg_compare(1, num, pares);
        }
    }
}