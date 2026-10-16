#include <stdio.h>
#include <stdlib.h>

/* Converte "123.45" para centímetros (123*100 + 45), sem usar float/double */
static long long parse_cm(const char *s) {
    long long inteiro = 0, frac = 0;
    int digitos = 0, depois_ponto = 0;

    for (; *s; s++) {
        if (*s == '.' || *s == ',') {
            depois_ponto = 1;
        } else if (*s >= '0' && *s <= '9') {
            if (!depois_ponto) {
                inteiro = inteiro * 10 + (*s - '0');
            } else if (digitos < 2) {
                frac = frac * 10 + (*s - '0');
                digitos++;
            }
        }
    }
    while (digitos < 2) { frac *= 10; digitos++; }
    return inteiro * 100 + frac;
}

/* Verifica se é possível obter pelo menos K cabos de comprimento x (cm) */
static int possivel(const long long *L, int n, long long k, long long x) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += L[i] / x;
        if (total >= k) return 1;
    }
    return 0;
}

int main(void) {
    int n;
    long long k;

    if (scanf("%d %lld", &n, &k) != 2) return 0;

    long long *L = (long long *)malloc(n * sizeof(long long));
    if (L == NULL) return 1;

    long long maior = 0;
    char buf[64];
    for (int i = 0; i < n; i++) {
        scanf("%63s", buf);
        L[i] = parse_cm(buf);
        if (L[i] > maior) maior = L[i];
    }

    long long lo = 1, hi = maior, resp = 0;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (possivel(L, n, k, mid)) {
            resp = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%lld.%02lld\n", resp / 100, resp % 100);

    free(L);
    return 0;
}
