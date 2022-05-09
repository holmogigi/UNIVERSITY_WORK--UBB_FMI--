#include "UndoAction.h"

/*
  Function that creates the undo function
*/
UndoAction createUndoAction(Repository* repository,int (*function)(Repository*, Country*), Country *object, int (*inverse_function)(Repository*, Country*), Country *inverse_object)
{
    UndoAction undoAction;
    undoAction.repository = repository;
    undoAction.function = function;
    undoAction.object = *object;
    undoAction.inverse_function = inverse_function;
    undoAction.inverse_object = *inverse_object;
    return undoAction;
}

/*
  Function that executes the undo
*/
int executeUndo(UndoAction* pointer)
{
    return pointer->inverse_function(pointer->repository, &pointer->inverse_object);
}

/*
  Function that executes the redo
*/
int executeRedo(UndoAction* pointer)
{
    return pointer->function(pointer->repository, &pointer->object);
}

