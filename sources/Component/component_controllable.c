/*
 * Filename: sources/Component/controllable.c
 * Path: sources/Component
 * Created Date: Friday, March 10th 2023, 11:07:40 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 our_rpg
 */

#include "components.h"
#include "world_logger.h"

int component_controllable_constructor(component_t *component, void *data)
{
    component->type = C_CONTROLLABLE;
    component->data = 0;
    log_info("Controllable component created.");
    return 0;
}
