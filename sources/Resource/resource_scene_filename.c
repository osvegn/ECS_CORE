/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Resource/resource_scene_filename.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Resource
 * Created Date: Tuesday, March 21st 2023, 9:45:13 am
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "resources.h"

int resource_scene_filename_constructor(resource_t *resource, void *data)
{
    char *tmp = strdup(data);

    for (int i = 0; tmp[i]; i++)
        if (tmp[i] == '\\' || tmp[i] == '\"')
            strcpy(&tmp[i], &tmp[i + 1]);
    resource->type = R_SCENE_FILENAME;
    // resource->data = strdup(data);
    resource->data = strdup(tmp);
    resource->destructor = &resource_scene_filename_destructor;
    printf("data: %s\n", resource->data);
    free(tmp);
    return 0;
}

int resource_scene_filename_destructor(resource_t *resource)
{
    if (resource->data)
        free(resource->data);
    return 0;
}

int resource_scene_filename_set(resource_t *resource, char *filename)
{
    free(resource->data);
    resource->data = strdup(filename);
    return 0;
}

int resource_scene_filename_get(resource_t *resource)
{
    return resource->data;
}
