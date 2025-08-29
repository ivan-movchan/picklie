/*
 * picklie.c: the main source file of Picklie.
 * See LICENSE for copyright and licensing details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define LAST_ERROR GetLastError()

#define TITLE_FORMAT "Picklie v%s"

#define EXIT_KEY 0x1B

int main(int argc, char** argv)
{
    HDC screen_dc;
    POINT cursor;
    COLORREF color;
    int r, g, b;
    char command = '\0';
    
    char title[32];
    sprintf(title, TITLE_FORMAT, VERSION);
    
    if (SetConsoleTitle(title) == 0)
    {
        printf("Failed to set console window title (0x%08X).\n", LAST_ERROR);
    };
    
    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--version"))
        {
            printf("%s\nCopyright (c) 2025 Ivan Movchan\nhttps://github.com/ivan-movchan/picklie\n", title);
            return 0;
        };
    };
    
    while (command != EXIT_KEY)
    {
        command = getch();
        
        if (command != EXIT_KEY)
        {
            if (GetCursorPos(&cursor) != 0)
            {
                screen_dc = GetDC(0);
                
                if (screen_dc == NULL)
                {
                    printf("Failed to get display device context handler (0x%08X).\n", LAST_ERROR);
                };
                
                color = GetPixel(screen_dc, cursor.x, cursor.y);
                
                r = GetRValue(color);
                g = GetGValue(color);
                b = GetBValue(color);
                
                printf("%dx, %dy: #%02X%02X%02X (%d, %d, %d)\n", cursor.x, cursor.y, r, g, b, r, g, b);
            }
            else
            {
                printf("Failed to get cursor position (0x%08X).\n", LAST_ERROR);
            };
        };
    };
    
    return 0;
}