#include <stdio.h>
#include <math.h>

void Acutem(float);
void Maxima(float, int);
void Minima(float, int);

float ACT = 0.0;
float MAX = -50.0;
float MIN = 60.0;
int HMAX;
int HMIN;

int main(void)
{
    float TEM;
    int I;
    for (I = 1; I <= 24; I++)
    {
        printf("Ingresa la temperatura de la hora %d: ", I);
        scanf("%f", &TEM);
        Acutem(TEM);
        Maxima(TEM, I);
        Minima(TEM, I);
    }
    printf("\nPromedio del dia: %.2f", ACT / 24);
    printf("\nMaxima del dia: %.2f \tHora: %d", MAX, HMAX);
    printf("\nMinima del dia: %.2f \tHora: %d", MIN, HMIN);
    return 0;
}

void Acutem(float TEM)
{
    ACT += TEM;
}

void Maxima(float TEM, int HOR)
{
    if (MAX < TEM)
    {
        MAX = TEM;
        HMAX = HOR;
    }
}

void Minima(float TEM, int HOR)
{
    if (MIN > TEM)
    {
        MIN = TEM;
        HMIN = HOR;
    }
}
