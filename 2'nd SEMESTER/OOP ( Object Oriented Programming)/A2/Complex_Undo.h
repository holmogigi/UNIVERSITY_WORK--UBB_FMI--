#pragma once
#include "UndoAction.h"

typedef struct {
    int capacity;
    int number_of_elements;
    UndoAction* undo_actions;
}ComplexUndoAction;

ComplexUndoAction createComplexUndoAction(int capacity);
void add_action(ComplexUndoAction* complexUndoAction, UndoAction* undoAction);
void complex_undo_actions(ComplexUndoAction* complexUndoAction);
void complex_redo_actions(ComplexUndoAction* complexUndoAction);
void destroyComplexUndoAction(ComplexUndoAction* complexUndoAction);
