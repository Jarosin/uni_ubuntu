//
// Created by jarozin on 25.04.22.
//

#include "cube.h"
Cube *create_cube(Point (&vertexes)[N])
{
    if (vertexes == nullptr)
        return nullptr;
    Cube *new_cube = new Cube;
    for (int i = 0; i < N; i++)
    {
        copy(new_cube->vertexes[i], vertexes[i]);
    }
    return new_cube;
}
void free_cube(Cube &cube)
{
    delete &cube;
}