#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    long long K;

    // Leitura de N e K
    if (scanf("%d %lld", &N, &K) != 2) return 0;

    // Alocação dinâmica para armazenar os comprimentos em centímetros
    long long *lengths = (long long *)malloc(N * sizeof(long long));
    if (lengths == NULL) {
        return 1;
    }

    long long max_len = 0;
    for (int i = 0; i < N; i++) {
        int m, c;
        scanf("%d.%d", &m, &c);
        // Converte metros para centímetros sem usar ponto flutuante
        lengths[i] = (long long)m * 100 + c;
        if (lengths[i] > max_len) {
            max_len = lengths[i];
        }
    }

    // Busca binária pelo maior comprimento possível
    long long low = 1;
    long long high = max_len;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long count = 0;
        
        // Conta quantos cabos de tamanho 'mid' podem ser cortados
        for (int i = 0; i < N; i++) {
            count += lengths[i] / mid;
        }

        if (count >= K) {
            ans = mid;       // É possível, guardamos a resposta e tentamos um valor maior
            low = mid + 1;
        } else {
            high = mid - 1;  // Cabos muito longos, precisamos diminuir o tamanho
        }
    }

    // Imprime o resultado em metros com exatamente duas casas decimais
    printf("%lld.%02lld\n", ans / 100, ans % 100);

    // Liberação da memória alocada dinamicamente
    free(lengths);

    return 0;
}
