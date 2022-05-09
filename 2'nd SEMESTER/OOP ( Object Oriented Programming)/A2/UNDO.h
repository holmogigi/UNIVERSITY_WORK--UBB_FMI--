#pragma once

#include "Undo_Redo_Stack.h"

typedef struct
{
    StackUndoAction* undo_actions;
    StackUndoAction* redo_actions;
}UndoService;

UndoService createUndoService(StackUndoAction* undoActions, StackUndoAction* redoActions);
int undo_action(UndoService* undoService);
int redo_action(UndoService* undoService);
void destroy_all_undo_actions(UndoService* undoService);
