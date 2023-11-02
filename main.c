#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Entrez le chemin du fichier à afficher\n");
		return 1;
	}
	
	FILE* fichier = NULL;
	char c = 0;
	
	
	fichier = fopen(argv[1], "r+");
	
	if (fichier != NULL)
	{
		while(c != EOF)
		{
			c = fgetc(fichier);
			if (c != -1)
			printf("%c", c);
		}
		fclose(fichier);
		
	}
	else
	{
		printf("Impossible d'ouvrir le fichier %s\n", argv[1]);
		return 1;
	}
	
	
	return 0;
}
