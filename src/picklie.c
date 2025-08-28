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
    HDC ScreenDC;
    POINT CursorPoint;
    COLORREF Color;
    int CursorX, CursorY, ColorR, ColorG, ColorB;
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
                CursorX = CursorPoint.x;
                CursorY = CursorPoint.y;
                
                ScreenDC = GetDC(0);
                
                if (ScreenDC == NULL)
                {
                    printf("Failed to get display device context handler (0x%08X).\n", GetLastError());
                };
                
                Color = GetPixel(ScreenDC, CursorX, CursorY);
                
                ColorR = GetRValue(Color);
                ColorG = GetGValue(Color);
                ColorB = GetBValue(Color);
                
                printf("%dx, %dy: #%02X%02X%02X (%d, %d, %d)\n", CursorX, CursorY, ColorR, ColorG, ColorB, ColorR, ColorG, ColorB);
            }
            else
            {
                printf("Failed to get cursor position (0x%08X).\n", GetLastError());
            };
        };
    };
    
    return 0;
}