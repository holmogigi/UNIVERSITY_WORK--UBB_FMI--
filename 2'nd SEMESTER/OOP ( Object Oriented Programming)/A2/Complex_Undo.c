#include "Complex_Undo.h"
#include <stdlib.h>

/*
  Function that creates the complex undo/redo, used for add/remove
*/
ComplexUndoAction createComplexUndoAction(int capacity)
{
    ComplexUndoAction complexUndoAction;
    complexUndoAction.capacity = capacity;
    complexUndoAction.number_of_elements = 0;
    complexUndoAction.undo_actions = (UndoAction*)malloc((capacity + 1) * sizeof(UndoAction));
    return complexUndoAction;
}

/*
  Function that takes care of the add undo
*/
void add_action(ComplexUndoAction* complexUndoAction, UndoAction* undoAction)
{
    *(complexUndoAction->undo_actions + complexUndoAction->number_of_elements) = *undoAction;
    complexUndoAction->number_of_elements ++;
}

/*
  Function that takes care of the remove undo
*/
void complex_undo_actions(ComplexUndoAction* complexUndoAction)
{
    int index;
    for (index = complexUndoAction->number_of_elements - 1; index >= 0; index--)
    {
        executeUndo(complexUndoAction->undo_actions + index);
    }
}

/*
  Function that takes care of the add/remove redo
*/
void complex_redo_actions(ComplexUndoAction* complexUndoAction)
{
    int index;
    for (index = complexUndoAction->number_of_elements - 1; index >= 0; index--)
    {
        executeRedo(complexUndoAction->undo_actions + index);
    }
}

/*
  Function that frees all the memory allocated by the complex undo/redo
*/
void destroyComplexUndoAction(ComplexUndoAction* complexUndoAction)
{
    free(complexUndoAction->undo_actions);
}
