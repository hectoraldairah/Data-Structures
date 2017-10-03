#pragma once
#include <elem.h>

#define SIZE 23

typedef struct parElementos** tablaHash;

tablaHash NuevaTablaHash()
{
    tablaHash nueva_tabla = malloc(sizeof(struct parElementos*) * SIZE);

    for(int i = 0; i < SIZE; i++)
        tablaHash[i] = NULL;
    
    return nueva_tabla;
}

int Hash(key k)
{
    return k % SIZE;
}

}