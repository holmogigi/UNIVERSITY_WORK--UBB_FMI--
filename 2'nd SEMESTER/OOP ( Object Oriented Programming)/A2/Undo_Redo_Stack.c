#include "Undo_Redo_Stack.h"
#include <stdlib.h>

/*
  Function that craetes the "stack" for the undo/redo functionality
*/
StackUndoAction createStackUndoAction()
{
    StackUndoAction stackUndoAction;
    stackUndoAction.length = 0;
    stackUndoAction.complexUndoActions = (ComplexUndoAction*)malloc(100* sizeof(ComplexUndoAction));
    return stackUndoAction;
}

/*
  Function that pushes the vector to the stack
*/
void push_stack(StackUndoAction* pointer_s, ComplexUndoAction* pointer)
{
    *(pointer_s->complexUndoActions + pointer_s->length) = *pointer;
    pointer_s->length ++;
}

/*
  Function that pops the vector from the stack
*/
ComplexUndoAction pop_stack(StackUndoAction* pointer_s)
{
    if (pointer_s->length == 0){
        return createComplexUndoAction(0);
    }
    pointer_s->length --;
    return *(pointer_s->complexUndoActions + pointer_s->length);
}

/*
  Function that freees all the memory allocated before for the stack
*/
void clear(StackUndoAction* pointer)
{
    for (int index = pointer->length - 1; index >= 0; index--)
        destroyComplexUndoAction(pointer->complexUndoActions + index);
    free(pointer->complexUndoActions);
}
