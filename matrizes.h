typedef struct abstrata Abstrata;

Abstrata Acria(int l, int c);
float Aacessa(Abstrata m, int i, int j);
void Aatribui(Abstrata m, int i, int j, int valor);
void Aimprime(Abstrata m);
void Alibera(Abstrata m);
int Alinhas(Abstrata m);
int Acolunas(Abstrata m);
Abstrata Asoma(Abstrata m1, Abstrata m2);
Abstrata Asubtr(Abstrata m1, Abstrata m2);
Abstrata Amult(Abstrata a1, Abstrata a2);
Abstrata menos90graus(Abstrata m);
Abstrata mais90graus(Abstrata m);

/////////////////////////////////////////////////////////////////////////////
typedef struct real Real;

Real Rcria(int l, int c);
float Racessa(Real m, int i, int j);
void Ratribui(Real m, int i, int j, int valor);
void Rimprime(Real m);
void Rlibera(Real m);
int Rlinhas(Real m);
int Rcolunas(Real m);
Real Rsoma(Real m1, Real m2);
Real Rsubtr(Real m1, Real m2);
Real Rmult(Real r1, Real r2);
Real menos90graus(Real m);
Real mais90graus(Real m);

/////////////////////////////////////////////////////////////////////////////
typedef struct RGB rgb;
typedef struct cabecalhoPPM cppm;
typedef unsigned char uchar;
typedef struct PPM ppm;

void troca(int *a, int *b);
rgb atribui(uchar r, uchar g, uchar b);
ppm copia(ppm img);
rgb **rgb_malloc(cppm cab);
void libera(ppm img);
ppm leitura(char fname[]);
void grava(char fname[], ppm img);
ppm gira(ppm img, int graus);
ppm decomp(ppm cab, bool r, bool g, bool b);
ppm negativo(ppm img);
ppm BW(ppm img);
ppm BM(ppm img);
void grava_gira(char fname[], ppm img, int graus);
void grava_decomp(char fname[], ppm img, bool r, bool g, bool b);
void grava_negativo(char fname[], ppm img);
void grava_BW(char fname[], ppm img);
void grava_BM(char fname[], ppm img);