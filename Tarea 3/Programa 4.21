# include <stdio.h>
/* Funciones y par�metros. */
int z, y;                         /* Variables globales. */
int F1(float);
void F2(float, int *);             /* Prototipos de funciones. */
void main(void)
{
int w;
float x;
z = 5;
y = 7;
w = 2;
x = (float)y / z;
printf(�\nPrograma Principal: %d %d %.2f %d�, z, y, x, w);
F2 (x, &w);
printf(�\nPrograma Principal: %d %d %.2f %d�, z, y, x, w);
}
int F1(float x)
{
int k;
if (x!= 0)
{
k = z - y;
x++;
}
else
k = z + y;
printf(�\nF1: %d %d %.2f %d�, z, y, x, k);
return(k);
}
void F2(float t, int *r)
{
