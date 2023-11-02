#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ce programme est similaire à la commande "cat". Il peut prendre "-c" et/ou "-l" en option
// "-c" compte le nombre de caractères
// "-l" compte le nombre de lignes

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Entrez le chemin du fichier à afficher\n");
		return 1;
	}
	
	FILE* fichier = NULL;
	char c = 0;
	int i = 0, l = 0, k;
	
	fichier = fopen(argv[1], "r+");
	
	if (fichier != NULL)
	{
		while(c != EOF)		//On va lire chaque caractère jusqu'à la fin du fichier
		{
			c = fgetc(fichier);
			i++;			//compteur de caractères
			
			if (c == 10)	//compteur de ligne, \n = 10 den ASCII
			l++;
			
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
	
	printf("--------------------------------\n");
	for(k=0;k<argc;k++)       //Parcourir tous les arguments du programme
	{
		
		if (strcmp(argv[k], "-c") == 0)			//Si l'argument est "-c" , afficher le nombre de caractères
		printf("Le fichier contient %d caractères\n", i-l-1);	// on enlève le nombre de caractères "\n" donc le nombre de lignes
	
		if (strcmp(argv[k], "-l") == 0)			//Si l'argument est "-l", afficher le nombre de lignes
		printf("Le fichier contient %d lignes\n", l);
	}
	
	return 0;
}
