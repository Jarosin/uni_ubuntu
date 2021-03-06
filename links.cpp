//
// Created by jarozin on 25.04.22.
//
#include "error_handling.h"
#include "links.h"

int links_alloc(links_data &connections, int len)
{
    connections.n = len;

    connections.arr = new link[len];
    if (!connections.arr)
        return EMPTY_PTR_ERR;

    return NONE;
}

links_data *alloc_link_data(int len)
{
    int err = NONE;
    links_data *new_links_data = new links_data;
    if (new_links_data != nullptr)
    {
        err = links_alloc(*new_links_data, len);
        if (err)
        {
            links_free(*new_links_data);
            delete new_links_data;
            new_links_data = nullptr;
        }
    }
    return new_links_data;
}

void links_free(links_data &connections)
{
    if (connections.arr)
        delete[] connections.arr;
}

void free_links_data(links_data &src)
{
    links_free(src);
}


int read_link(link* joints, FILE* f)
{
    if (fscanf(f, "%d%d", &joints->p1, &joints->p2) != 2)
        return FILE_FORMAT_ERR;

    return NONE;
}


int read_n_links(link* joints, int n, FILE *f)
{
    int err = 0;
    for (int i = 0; i < n && !err; i++)
    {
        if (read_link(&joints[i], f))
            err = FILE_FORMAT_ERR;
    }

    return err;
}
