/*
 * picklie.c: the main source file of Picklie.
 * See LICENSE for copyright and licensing details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main(int argc, char** argv)
{
    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--version"))
        {
            printf("Picklie v%s\nCopyright (c) 2025 Ivan Movchan\nhttps://github.com/ivan-movchan/picklie\n", VERSION);
            return 0;
        };
    };
    
    return 0;
}