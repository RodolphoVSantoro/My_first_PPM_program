#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrizes.h"

struct abstrata{
	int linhas;
	int colunas;
	float *p;
};

Abstrata Acria(int l, int c)
{
	Abstrata m;
	m.p = NULL;
	m.linhas = 0;
	m.colunas = 0;
	if (l == 0 || c == 0)
	{
		printf("linhas ou colunas zeradas\n");
	}
	int x, y;
	m.p = (float*)malloc(sizeof(float)*l*c);
	if (m.p == NULL)
	{
		printf("Sem memória suficiente\n");
		return m;
	}
	m.linhas = l;
	m.colunas = c;
	for (x = 0; x < m.linhas; x++)
	{
		for (y = 0; y < m.colunas; y++)
		{
			m.p[x + y*m.linhas] = 0;
		}
	}
	return m;
}

float Aacessa(Abstrata m, int i, int j)
{
	return m.p[i + j*m.linhas];
}

void Aatribui(Abstrata m, int i, int j, int valor)
{
	m.p[i + j*m.linhas] = valor;
}

void Aimprime(Abstrata m)
{
	int x, y;
	for (x = 0; x < m.linhas; x++)
	{
		for (y = 0; y < m.colunas; y++)
		{
			printf(" %.0f ",m.p[x+y*m.linhas]);
		}
		printf("\n");
	}
}

void Alibera(Abstrata m)
{
	free(m.p);
	m.linhas = 0;
	m.colunas = 0;
}

int Alinhas(Abstrata m)
{
	return m.linhas;
}

int Acolunas(Abstrata m)
{
	return m.colunas;
}

Abstrata Asoma(Abstrata m1, Abstrata m2)
{
	Abstrata mr;
	int x, y;
	mr.p = NULL;
	mr.linhas = 0;
	mr.colunas = 0;
	if (m1.colunas != m2.colunas || m1.linhas != m2.linhas)
	{
		printf("As duas matrizes tem ordem diferente");
		return mr;
	}
	mr = Acria(m1.linhas, m1.colunas);
	for (x = 0; x < m1.linhas; x++)
		for (y = 0; y < m1.colunas; y++)
			Aatribui(mr, x, y, (Aacessa(m1, x, y) + Aacessa(m2, x, y)));
	return mr;
}

Abstrata Asubtr(Abstrata m1, Abstrata m2)
{
	Abstrata mr;
	int x, y;
	mr.p = NULL;
	mr.linhas = 0;
	mr.colunas = 0;
	if (m1.colunas != m2.colunas || m1.linhas != m2.linhas)
	{
		printf("As duas matrizes tem ordem diferente");
		return mr;
	}
	mr = Acria(m1.linhas, m1.colunas);
	for (x = 0; x < m1.linhas; x++)
		for (y = 0; y < m1.colunas; y++)
			Aatribui(mr, x, y, (Aacessa(m1, x, y) - Aacessa(m2, x, y)));
	return mr;
}

Abstrata Amult(Abstrata a1, Abstrata a2)
{
	Abstrata mr;
	int x, y, a, k, ac;
	mr.p = NULL;
	mr.linhas = 0;
	mr.colunas = 0;
	if (a1.colunas != a2.linhas)
	{
		printf("Nao e possivel multiplicar essas matrizes\n");
		return mr;
	}
	mr = Acria(a1.linhas, a2.colunas);
	for (x = 0; x < a1.linhas; x++)
	{
		for (y = 0; y < a2.colunas; y++)
		{
			ac = 0;
			for (a = 0; a < a1.colunas; a++)
			{
				ac += Aacessa(a1, x, a) * Aacessa(a2, a, y);
			}
			Aatribui(mr, x, y, ac);
		}
	}
	return mr;
}

Abstrata menos90graus(Abstrata m)
{
	int x, y, a, b;
	Abstrata m2 = Acria(Acolunas(m), Alinhas(m));
	a = Alinhas(m2) - 1;
	for (x = 0; x < Alinhas(m2); x++)
	{
		b = 0;
		for (y = 0; y < Acolunas(m2); y++)
		{
			Aatribui(m2, x, y, Aacessa(m, b, a));
			b++;
		}
		a--;
	}
	return m2;
}

Abstrata mais90graus(Abstrata m)
{
	int x, y, a, b;
	Abstrata m2 = Acria(Acolunas(m), Alinhas(m));
	a = 0;
	for (x = 0; x < Alinhas(m2); x++)
	{
		b = Acolunas(m2) - 1;
		for (y = 0; y < Acolunas(m2); y++)
		{
			Aatribui(m2, x, y, Aacessa(m, b, a));
			b--;
		}
		a++;
	}
	return m2;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

struct real{
	int linhas;
	int colunas;
	float **p;
};

Real Rcria(int l, int c)
{
	Real m;
	m.p = NULL;
	m.linhas = 0;
	m.colunas = 0;
	if (l == 0 || c == 0)
	{
		printf("linhas ou colunas zeradas\n");
		return m;
	}
	int x, y;
	m.p = (float**)malloc(sizeof(float*)*l);
	if (m.p == NULL)
	{
		printf("Sem memória suficiente\n");
		return m;
	}
	for (x = 0; x < l; x++)
	{
		m.p[x] = (float*)malloc(sizeof(float)*c);
		if (m.p[x] == NULL)
		{
			printf("Sem memória suficiente\n");
			return m;
		}
	}
	m.linhas = l;
	m.colunas = c;
	for (x = 0; x < l; x++)
	{
		for (y = 0; y < c; y++)
		{
			m.p[x][y] = 0;
		}
	}
	return m;
}

float Racessa(Real m, int i, int j)
{
	return m.p[i][j];
}

void Ratribui(Real m, int i, int j, int valor)
{
	m.p[i][j] = valor;
}

void Rimprime(Real m)
{
	int x, y;
	for (x = 0; x < m.linhas; x++)
	{
		for (y = 0; y < m.colunas; y++)
		{
			printf(" %.0f ", m.p[x][y]);
		}
		printf("\n");
	}
}

void Rlibera(Real m)
{
	int x;
	for (x = 0; x < m.linhas; x++)
	{
		free(m.p[x]);
	}
	free(m.p);
	m.linhas = 0;
	m.colunas = 0;
}

int Rlinhas(Real m)
{
	return m.linhas;
}

int Rcolunas(Real m)
{
	return m.colunas;
}

Real Rsoma(Real m1, Real m2)
{
	Real mr;
	int x, y;
	mr.p = NULL;
	mr.linhas = 0;
	mr.colunas = 0;
	if (m1.colunas != m2.colunas || m1.linhas != m2.linhas)
	{
		printf("As duas matrizes tem ordem diferente\n");
		return mr;
	}
	mr = Rcria(m1.linhas, m1.colunas);
	for (x = 0; x < m1.linhas; x++)
		for (y = 0; y < m1.colunas; y++)
			mr.p[x][y] = m1.p[x][y] + m2.p[x][y];
	return mr;
}

Real Rsubtr(Real m1, Real m2)
{
	Real mr;
	int x, y;
	mr.p = NULL;
	mr.linhas = 0;
	mr.colunas = 0;
	if (m1.colunas != m2.colunas || m1.linhas != m2.linhas)
	{
		printf("As duas matrizes tem ordem diferente\n");
		return mr;
	}
	mr = Rcria(m1.linhas, m1.colunas);
	for (x = 0; x < m1.linhas; x++)
		for (y = 0; y < m1.colunas; y++)
			mr.p[x][y] = m1.p[x][y] - m2.p[x][y];
	return mr;
}

Real Rmult(Real r1, Real r2)
{
	Real mr;
	int x, y, a, k, ac;
	mr.p = NULL;
	mr.linhas = 0;
	mr.colunas = 0;
	if (r1.colunas != r2.linhas)
	{
		printf("Nao e possivel multiplicar essas matrizes\n");
		return mr;
	}
	mr = Rcria(r1.linhas, r2.colunas);
	for (x = 0; x < r1.linhas; x++)
	{
		for (y = 0; y < r2.colunas; y++)
		{
			ac = 0;
			for (a = 0; a < r1.colunas; a++)
			{
				ac += r1.p[x][a] * r2.p[a][y];
			}
			mr.p[x][y] = ac;
		}
	}
	return mr;
}

Real menos90graus(Real m)
{
	int x, y, a, b;
	Real m2 = Rcria(Rcolunas(m), Rlinhas(m));
	a = Rlinhas(m2) - 1;
	for (x = 0; x < Rlinhas(m2); x++)
	{
		b = 0;
		for (y = 0; y < Rcolunas(m2); y++)
		{
			Ratribui(m2, x, y, Racessa(m, b, a));
			b++;
		}
		a--;
	}
	return m2;
}

Real mais90graus(Real m)
{
	int x, y, a, b;
	Real m2 = Rcria(Rcolunas(m), Rlinhas(m));
	a = 0;
	for (x = 0; x < Rlinhas(m2); x++)
	{
		b = Rcolunas(m2) - 1;
		for (y = 0; y < Rcolunas(m2); y++)
		{
			Ratribui(m2, x, y, Racessa(m, b, a));
			b--;
		}
		a++;
	}
	return m2;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

struct RGB{
	uchar r;
	uchar g;
	uchar b;
};

struct cabecalhoPPM{
	int largura;
	int altura;
	int max;
	char key[3];
};

struct PPM
{
	cppm cab;
	rgb **cor;
};

void troca(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

rgb atribui(uchar r, uchar g, uchar b)
{
	rgb pixel;
	pixel.r = r;
	pixel.g = g;
	pixel.b = b;
	return pixel;
}

ppm copia(ppm img)
{
	int i, j;
	ppm r;
	r.cab.altura = img.cab.altura;
	r.cab.largura = img.cab.largura;
	r.cab.max = img.cab.max;
	strcpy(r.cab.key, img.cab.key);
	r.cor = rgb_malloc(r.cab);
	for (i = 0; i < r.cab.altura; i++)
		for (j = 0; j < r.cab.largura; j++)
			r.cor[i][j] = img.cor[i][j];
	return r;
}

rgb **rgb_malloc(cppm cab)
{
	rgb **cor;
	int i, j;
	cor = (rgb**)malloc(cab.altura*sizeof(rgb*));
	if (cor == NULL)
	{
		printf("Sem memoria\n");
		system("PAUSE");
		exit(1);
	}
	for (i = 0; i<cab.altura; i++)
	{
		cor[i] = (rgb*)malloc(cab.largura*sizeof(rgb));
		if (cor == NULL)
		{
			printf("Sem memoria\n");
			system("PAUSE");
			exit(1);
		}
	}
	return cor;
}

void libera(ppm img)
{
	int i;
	for (i = 0; i<img.cab.altura; i++)
	{
		free(img.cor[i]);
		img.cor[i] = NULL;
	}
	free(img.cor);
	img.cor = NULL;
}

ppm leitura(char fname[])
{
	ppm img;
	int r, g, b, i, j;
	FILE *arq = fopen(fname, "r");
	if (arq == NULL)
	{
		printf("Falha ao abrir o arquivo %s\n", fname);
		system("PAUSE");
		exit(1);
	}
	fscanf(arq, "%s", img.cab.key);
	fscanf(arq, "%d %d", &img.cab.largura, &img.cab.altura);
	fscanf(arq, "%d", &img.cab.max);
	if (strcmp(img.cab.key, "P3") != 0)
	{
		printf("O arquivo nao e um ppm");
		system("PAUSE");
		fclose(arq);
		arq = NULL;
		exit(1);
	}
	img.cor = rgb_malloc(img.cab);
	for (i = 0; i<img.cab.altura; i++)
	{
		for (j = 0; j<img.cab.largura; j++)
		{
			fscanf(arq, "%d", &r);
			fscanf(arq, "%d", &g);
			fscanf(arq, "%d", &b);
			img.cor[i][j].r = r;
			img.cor[i][j].g = g;
			img.cor[i][j].b = b;
		}
	}
	fclose(arq);
	arq = NULL;
	return img;
}

void grava(char fname[], ppm img)
{
	FILE *arq = fopen(fname, "w");
	int i, j;
	if (arq == NULL)
	{
		printf("Falha ao abrir o arquivo %s\n", fname);
		system("PAUSE");
		exit(1);
	}
	fprintf(arq, "P3\n%d %d %d\n", img.cab.largura, img.cab.altura, img.cab.max);
	for (i = 0; i<img.cab.altura; i++)
		for (j = 0; j<img.cab.largura; j++)
			fprintf(arq, "  %d %d %d \n ", img.cor[i][j].r, img.cor[i][j].g, img.cor[i][j].b);
	fclose(arq);
	arq = NULL;
}

ppm gira(ppm img, int graus)
{
	int n,i,j,a,b,vezes;
	ppm tmp, res = copia(img);
	tmp.cor = NULL;
	tmp.cab = res.cab;
	if (graus == 0)
		return res;
	vezes = graus/90;
	vezes = vezes % 4;
	for(n=0;n<vezes;n++)
	{
		if(tmp.cor != NULL)
			libera(tmp);
		troca(&tmp.cab.altura, &tmp.cab.largura);
		tmp.cor = rgb_malloc(tmp.cab);
		b = 0;
		for(i=0;i<tmp.cab.altura;i++)
		{
			a = tmp.cab.largura - 1;
			for(j=0;j<tmp.cab.largura;j++)
			{
				tmp.cor[i][j] = res.cor[a][b];
				a--;
			}
			b++;
		}
		res = copia(tmp);
	}
	if(tmp.cor!=NULL)
		libera(tmp);
	return res;
}

ppm decomp(ppm img, bool r, bool g, bool b)
{
	int i,j;
	ppm imgdec;
	imgdec.cab = img.cab;
	imgdec.cor = rgb_zalloc(imgdec.cab);
	for(i=0;i<imgdec.cab.altura;i++)
	{
		for(j=0;j<imgdec.cab.largura;j++)
		{
			if(r==true)
				imgdec.cor[i][j].r = img.cor[i][j].r;
			if(g==true)
				imgdec.cor[i][j].g = img.cor[i][j].g;
			if(b==true)
				imgdec.cor[i][j].b = img.cor[i][j].b;
		}
	}
	return imgdec;
}

ppm negativo(ppm img)
{
	int i, j;
	ppm r = copia(img);
	for (i = 0; i < r.cab.altura; i++)
	{
		for (j = 0; j < r.cab.largura; j++)
		{
			r.cor[i][j].r = 255 - img.cor[i][j].r;
			r.cor[i][j].g = 255 - img.cor[i][j].g;
			r.cor[i][j].b = 255 - img.cor[i][j].b;
		}
	}
	return r;
}

ppm BW(ppm img)
{
	int i, j;
	float val = 0.0;
	ppm r = copia(img);
	for (i = 0; i < r.cab.altura; i++)
	{
		for (j = 0; j < r.cab.largura; j++)
		{
			val = (img.cor[i][j].r + img.cor[i][j].g + img.cor[i][j].b) / 3;
			r.cor[i][j].r = aprox(val);
			r.cor[i][j].g = aprox(val);
			r.cor[i][j].b = aprox(val);
		}
	}
	return r;
}

ppm BM(ppm img)
{
	int i, j;
	float val;
	ppm r = copia(img);
	for (i = 0; i < r.cab.altura; i++)
	{
		for (j = 0; j < r.cab.largura; j++)
		{
			val = aprox((img.cor[i][j].r + img.cor[i][j].g + img.cor[i][j].b) / 3) < 128 ? 0 : 255;
			r.cor[i][j].r = val;
			r.cor[i][j].g = val;
			r.cor[i][j].b = val;
		}
	}
	return r;
}

ppm espelhar(ppm img, char fname[])
{
	ppm r = copia(img);
	int i, j;
	for (i = 0; i<r.cab.altura; i++)
		for (j = 0; j < r.cab.largura; j++)
			r.cor[i][j] = img.cor[i][img.cab.largura - j - 1];
	return r;
}

void grava_gira(char fname[], ppm img, int graus)
{
	ppm gir = gira(img, graus);
	grava(fname, gir);
	libera(gir);
}

void grava_decomp(char fname[], ppm img, bool r, bool g, bool b)
{
	ppm dec = decomp(img, r, g, b);
	grava(fname,dec);
	libera(dec);
}

void grava_negativo(char fname[], ppm img)
{
	ppm neg = negativo(img);
	grava(fname, neg);
	libera(neg);
}

void grava_BW(char fname[], ppm img)
{
	ppm pb = BW(img);
	grava(fname, pb);
	libera(pb);
}

void grava_BM(char fname[], ppm img)
{
	ppm bm = BM(img);
	grava(fname, bm);
	libera(bm);
}
