/*
 * Filename: sources/Component/displayable.c
 * Path: sources/Component
 * Created Date: Sunday, February 12th 2023, 6:21:46 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 our_rpg
 */

#include "components.h"
#include "world_logger.h"

int component_displayable_constructor(component_t *component, void *data)
{
    component->type = C_DISPLAYABLE;
    component->data = 0;
    log_info("Displayable component created.");
    return 0;
}
