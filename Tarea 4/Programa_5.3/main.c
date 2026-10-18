#include <stdio.h>

void main(void)
{
    int X = 3, Y = 7, Z[5] = {2, 4, 6, 8, 10};
    int *IX;

    printf("\nX = %d \t Y = %d \t Z[0]=%d Z[1]=%d Z[2]=%d Z[3]=%d Z[4]=%d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = &X;  /* IX guarda la DIRECCION de X */
    Y = *IX;  /* Y toma lo que hay en esa direccion (3) */
    *IX = 1;  /* Cambia lo que hay en esa direccion, X ahora vale 1 */
    printf("\n\n1) X=%d Y=%d Z[0]=%d Z[1]=%d Z[2]=%d Z[3]=%d Z[4]=%d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = &Z[2]; /* Ahora IX apunta a Z[2] que vale 6 */
    Y = *IX;    /* Y vale 6 */
    *IX = 15;   /* Z[2] ahora vale 15 */
    printf("\n2) X=%d Y=%d Z[0]=%d Z[1]=%d Z[2]=%d Z[3]=%d Z[4]=%d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    X = *IX + 5;  /* X = 15 + 5 = 20 */
    *IX = *IX - 5; /* Z[2] = 15 - 5 = 10 */
    printf("\n3) X=%d Y=%d Z[0]=%d Z[1]=%d Z[2]=%d Z[3]=%d Z[4]=%d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    ++*IX;   /* Z[2] = 11 */
    *IX += 1; /* Z[2] = 12 */
    printf("\n4) X=%d Y=%d Z[0]=%d Z[1]=%d Z[2]=%d Z[3]=%d Z[4]=%d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    X = *(IX + 1); /* X toma Z[3] que es 8, pero IX sigue en Z[2] */
    Y = *IX;       /* Y = 12 */
    printf("\n5) X=%d Y=%d Z[0]=%d Z[1]=%d Z[2]=%d Z[3]=%d Z[4]=%d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = IX + 1; /* IX ahora si se mueve a Z[3] */
    Y = *IX;     /* Y = 8 */
    printf("\n6) X=%d Y=%d Z[0]=%d Z[1]=%d Z[2]=%d Z[3]=%d Z[4]=%d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);
}
