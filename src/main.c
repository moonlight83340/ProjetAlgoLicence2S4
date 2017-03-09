#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "railwayNetwork.h"
#include "util.h"
#include "trace.h"
#include "dijkstra.h"
#include "generate.h"

void infos(){
	printf("Ce fichier a ete compile le %s a %s\n", __DATE__, __TIME__);
}

void usage(){
	printf("ToDo");
}

int main (int argc , char * argv[]){
	char filename[] = "test.txt";
	int test=1;
	printf("afficher les valeurs lue ? (OUI:1/NON:0)\n");
	scanf("%d",&test);
	RailwayNetwork RRInstance;
	railwayNetwork(filename,&RRInstance);
	if (test==1)
	{
		show_RR(&RRInstance);
		show_lignesInVille(&RRInstance);
		show_voisins(&RRInstance);
	}
	Trajet trajet;
	set_trajet(&trajet);
	int result[RRInstance.nbvilles+1];
	dijkstra(&RRInstance,&trajet,result);

	for (int i = 0; i <= RRInstance.nbvilles; ++i)
	{
		printf("%d\n",result[i]);
	}
	
	return 0;
}
