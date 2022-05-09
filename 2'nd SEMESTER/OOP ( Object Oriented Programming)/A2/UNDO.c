#include "UNDO.h"

/*
  Function that creates the undo service
*/
UndoService createUndoService(StackUndoAction* undoActions, StackUndoAction* redoActions)
{
    UndoService undoService;
    undoService.undo_actions = undoActions;
    undoService.redo_actions = redoActions;
    return undoService;
}

/*
  Functon that does the undo operation
*/
int undo_action(UndoService* undoService)
{
    ComplexUndoAction last_action;
    last_action = pop_stack(undoService->undo_actions);
    if (last_action.capacity == 0)
        return 1;
    push_stack(undoService->redo_actions, &last_action);
    complex_undo_actions(&last_action);
    return 0;
}

/*
  Function that does the redo operation
*/
int redo_action(UndoService* undoService)
{
    ComplexUndoAction last_action_undone;
    last_action_undone = pop_stack(undoService->redo_actions);
    if (last_action_undone.capacity == 0)
    {
        destroyComplexUndoAction(&last_action_undone);
        return 1;
    }
    push_stack(undoService->undo_actions, &last_action_undone);
    complex_redo_actions(&last_action_undone);
    return 0;
}

/*
  Function that frees the memory allocated for the undo/redo functionality
*/
void destroy_all_undo_actions(UndoService* undoService)
{
    clear(undoService->undo_actions);
    clear(undoService->redo_actions);
}

