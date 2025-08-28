/*
 * picklie.c: the main source file of Picklie.
 * See LICENSE for copyright and licensing details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define KEY_SPACE 0x20
#define KEY_ESCAPE 0x1B

int main(int argc, char** argv)
{
    POINT CursorPoint;
    char Command = '\0';
    
    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--version"))
        {
            printf("Picklie v%s\nCopyright (c) 2025 Ivan Movchan\nhttps://github.com/ivan-movchan/picklie\n", VERSION);
            return 0;
        };
    };
    
    while (Command != KEY_ESCAPE)
    {
        Command = getch();
        
        if (Command == KEY_SPACE)
        {
            if (GetCursorPos(&CursorPoint) != 0)
            {
                printf("%dx, %dy\n", CursorPoint.x, CursorPoint.y);
            }
            else
            {
                printf("Failed to get cursor position (0x%08X).\n", GetLastError());
            };
        };
    };
    
    return 0;
}