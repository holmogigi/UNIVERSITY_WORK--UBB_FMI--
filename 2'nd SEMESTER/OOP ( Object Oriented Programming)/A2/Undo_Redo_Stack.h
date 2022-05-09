#pragma once
#include "Complex_Undo.h"

typedef struct{
    ComplexUndoAction* complexUndoActions;
    int length;
}StackUndoAction;

StackUndoAction createStackUndoAction();
void push_stack(StackUndoAction* pointer_s, ComplexUndoAction* pointer);
ComplexUndoAction pop_stack(StackUndoAction* pointer);
void clear(StackUndoAction* pointer);

