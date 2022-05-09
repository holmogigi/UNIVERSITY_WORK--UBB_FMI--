#pragma once

#include "Service.h"

typedef struct
{
    Service service;
}Console;

Console createConsole(Service* service);
void print_menu();
void console_add(Console* console);
void console_remove(Console* console);
void console_replace(Console* console);
void console_print_all(Console* console);
void console_run(Console* console);
void console_print_countries_on_continent_with_greater_population(Console* console);
void console_undo(Console* console);
void console_redo(Console* console);
