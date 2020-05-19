// http://hpca23.cse.tamu.edu/taco/utsa-www/ut/utsa/cs1723/lecture4.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include <locale.h>
#include <conio.h>
#include <time.h>

using namespace std;

typedef struct _student {
	int		  id;
	char		name[100];
	float		gpa;
} student;


// nó
typedef struct _node {
	student		k;
	struct _node	*next; // ponteiro para o próximo elemento
} node, *list;


void insert_list (list *L, student k) {
	node	*p;
	p = (node *) malloc (sizeof (node));
	p->k = k;
	p->next = *L;

	*L = p;
}


student *search_list (list L, int id) {
	node	*p;

	for (p=L; p && p->k.id != id; p=p->next);

	if (p)
		return &p->k;
	else
		return NULL;
}

/* make an empty list */

void create_list (list *L) {
	*L = NULL;
}

void imprimeMenu( ){
int opcao;

    printf("\n\tMENU\n");

     printf("informe a opcao desejada\n");
    printf("\n1 - consultar nota do Aluno digite 1");
    printf("\n2 - opcao 2");
    printf("\n3 - opcao 3");
    printf("\n4 - sair 4\n\n");

    scanf("%d", &opcao);

// system("pause");
			system("@cls||clear");
			//  escolhaOpcao();
}

 buscarEstudante(){
  //  int escolhaOpcao;

	list		C;	/* a class of students */
	student		s, *p;
	int		id;
	FILE		*arquivo;



	arquivo = fopen ("./List.txt", "r");
	if (!arquivo) {
		perror ("List");
		exit (1);
	}

	create_list (&C);

	for (;;) {
		fscanf (arquivo, "%d %s %f\n", &s.id, s.name, &s.gpa);
		if (feof (arquivo))
      break;
		insert_list (&C, s);
	}
	fclose (arquivo);

	for (;;) {
		printf ("informe ID do estudante ou zero(0) para voltar ao MENU\n");
		scanf ("%d", &id);

		if (id == 0){
            system("@cls||clear");
            fclose (arquivo);
            imprimeMenu( );

          } //else if(id == -1)
     //  break;

		p = search_list (C, id);


		if (!p)
			printf ("ID #%d not found!\n", id);
		else
			printf ("%d\t%s\t%0.2f\n", p->id, p->name, p->gpa);
	}
	exit (0);
}
void escolhaOpcao(){
    int opcao;

     switch(opcao){
        case 1:
            buscarEstudante();
     //   FILE *arquivo = fopen (caminho, "r"); //rt leitura
          //"./List.txt"
          break;
        case 2:
      //  arquivo = fopen (caminho, "wt"); //wt gravação
            printf("caso 2 em desenvolvimento!!!\n");
     //   scanf (arquivo, "%d %s %f\n", &s.id, s.name, &s.gpa);
        break;
        case 3:
            printf("caso 3 em desenvolvimento!!!\n");
       // arquivo = fopen (caminho, "r"); // a append
        break;
        default:
            printf("opcao invalida tente novamente\n");
            imprimeMenu( );

     }


}


int main () {

      printf("============================LISTA DUPLAMENTE ENCADEADA==========================\n\n");

imprimeMenu( );
escolhaOpcao();

return 0;
}
