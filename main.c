#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#ifndef BUF_SIZE
#	define BUF_SIZE 2064
#endif

extern _Noreturn void
help();

int
main(int argc, char **args)
{
	// this will work for -h & --help in almost all positions except for files named ./--help | ./-h
	if (argc != 3)
		help();
	else
	{
		FILE *f[2];
		
		f[0] = fopen(args[1], "r");
		f[1] = fopen(args[2], "r");
		
		if (f[0] == NULL || f[1] == NULL)
			help();
		else
		{
			// iters, never decl something in a loop.
			register int i,s=0;
			
			// found or not boolean
			bool found = false;
			
			// 0 1 file bufs
			// 2   line buf
			char buf[3][BUF_SIZE];
			
			for (i = 0; i <= 1; ++i)
			{
				while (fgets(buf[2], BUF_SIZE, f[i]) != NULL)
				{
					strcat(buf[i], buf[2]);
				};
			}
			
			int len = strlen(buf[0]);
			
			// iter search algo
			for (i = 0; i < BUF_SIZE; ++i)
				if (s == len)
					found = true;
				else if (buf[0][s] == buf[1][i])
					s++;
				else
					s = 0;
			
			// dubug info
#			ifndef NDEBUG
				printf("len:%d\n", len);
				printf("b0:\n%s\nb1:\n%s\nb2:\n%s\n", buf[0], buf[1], buf[2]);
#			endif
			
			// closes all open files
			for(i = 0; i <= 1; ++i)
			{
				// assertion to ensure file isn't NULL
				assert(f[i] != NULL);
				fclose(f[i]);
			}
			
				puts(found ? "SUCCESS" : "FAILURE");
			
			return EXIT_SUCCESS;
		}
	}
}

_Noreturn void
help()
{
	printf("[USAGE] [TEXT.txt, ART.askii, ETC. TO FIND] [FILE TO FIND IT IN]\nNOTE: The Files MUST exist.\nNo options.\n\n");
	exit(EXIT_FAILURE);
}
