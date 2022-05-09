#include "Repository.h"
#include "Service.h"
#include "Console.h"

int main()
{
    Console console;
    Service service;
    StackUndoAction undoActions, redoActions;
    UndoService undoService;
    Repository repository;
    repository = createRepository();
    initialise_repo(&repository);
    undoActions = createStackUndoAction();
    redoActions = createStackUndoAction();
    undoService = createUndoService(&undoActions, &redoActions);
    service = createService(&repository, &undoService);
    console = createConsole(&service);
    console_run(&console);
    return 0;
}
