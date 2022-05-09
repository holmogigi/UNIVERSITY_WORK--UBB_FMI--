#pragma once
#include "Repository.h"

typedef struct
{
    Repository* repository;
    int (*function)(Repository*, Country*);
    Country object;
    int (*inverse_function)(Repository*, Country*);
    Country inverse_object;
}UndoAction;

UndoAction createUndoAction(Repository* repository, int (*function)(Repository*, Country*), Country *object, int (*inverse_function)(Repository*, Country*), Country *inverse_object);
int executeUndo(UndoAction* pointer);
int executeRedo(UndoAction* pointer);
