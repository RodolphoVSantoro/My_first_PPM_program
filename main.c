#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"

int main()
{
	int x, y;

	printf("Com matriz de ponteiro para ponteiro:\n");
	Real mr = Rcria(3, 3);
	for (x = 0; x < Rlinhas(mr); x++)
		for (y = 0; y < Rcolunas(mr); y++)
				Ratribui(mr, x, y, x*Rcolunas(mr) + y + 1);
	Rimprime(mr);
	Real mr2 = mais90graus(mr);
	printf("\n");
	Rimprime(mr2);
	Rlibera(mr);
	Rlibera(mr2);
	
	//////////////////////////////////////////////////////////////////////////////////

	printf("\nCom matriz de ponteiro simples:\n");
	Abstrata ma = Acria(3, 3);
	for (x = 0; x < Alinhas(ma); x++)
		for (y = 0; y < Acolunas(ma); y++)
				Ratribui(m, x, y, x*Acolunas(ma) + y + 1);
	Rimprime(ma);
	Real ma2 = mais90graus(ma);
	printf("\n");
	Rimprime(ma2);
	Rlibera(ma);
	Rlibera(ma2);

	//////////////////////////////////////////////////////////////////////////////////
	
	printf("Lendo imagem.ppm\n");
	ppm img = leitura("imagem.ppm");
	printf("Salvando imagem rotacionada em 90 graus\n");
	grava_gira("90 graus.ppm", img, 90);
	printf("Salvando imagem rotacionada em 180 graus\n");
	grava_gira("180 graus.ppm", img, 180);
	printf("Salvando imagem rotacionada em 270 graus\n");
	grava_gira("270 graus.ppm", img, 270);
	printf("Finalizando\n");
	libera(img);
	return 0;
}