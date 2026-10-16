#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <time.h>

int main(void) {
	struct timespec inicio, fim;
	long nanossegundos;

	// Codigo cuja duracao queremos medir.
	for (volatile long i = 0; i < 1000L; i++)
	{
		// Captura o instante de inicio.
		clock_gettime(CLOCK_MONOTONIC, &inicio);

		// Código aqui


		// Captura o instante de fim.
		clock_gettime(CLOCK_MONOTONIC, &fim);

		// Calcula a diferenca bruta entre os campos.
		nanossegundos = fim.tv_nsec - inicio.tv_nsec;

		// Se os nanos ficaram negativos, ajusta.
		if (nanossegundos < 0) {
			nanossegundos += 1000000000L;
		}


		printf("(%ld, %09ld)", i, nanossegundos);

	}

	// Imprime no formato S.NANOS, com 9 casas para os nanossegundos.

	return 0;
}
