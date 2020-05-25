// http://hpca23.cse.tamu.edu/taco/utsa-www/ut/utsa/cs1723/lecture4.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

buscarEstudante(int opcao){

		list		C;	/* a class of students */
	student		s, *p;
	int		id;
	FILE		*arquivo;


if(opcao == 1){
 arquivo = fopen ("./List.txt", "r");
 create_list (&C);

	while (!feof(arquivo)) {
		fscanf (arquivo, "%d %s %f\n", &s.id, s.name, &s.gpa);

			insert_list (&C, s);
	}

}else if(opcao == 2){
    arquivo = fopen ("./List.txt", "wt");
    create_list (&C);
    printf("Opcao 2 foi selecionada ADICIONAR DADOS NO ARQUIVO\n");
    printf("\n\nATENCAO: aprimorar o sistema de manipulacao de arquivo no case 2\n");
    printf("SAIBA QUE OS DADOS DE SEUA AQUIVO ORIGINAL SERA APAGADO\n");
    printf("pois esta sobrescrevendo o arquivo original\n");

    system("pause");
//	while (!feof(arquivo)) {

            printf("informe a ID do Aluno\n");
            scanf("%d",&s.id);
            fprintf(arquivo,"%d ",&s.id);

            printf("informe o nome do Aluno\n");
            scanf("%s", s.name);
            fprintf(arquivo,"%s ",s.name);

            printf("Informe a GPA do Aluno\n");
            scanf("%.20f ",&s.gpa);

            fprintf(arquivo, "%f", &s.gpa);

		//fscanf (arquivo, "%d %s %f\n", &s.id, s.name, &s.gpa);

			insert_list (&C, s);
//	}
}else if(opcao == 3){
    arquivo = fopen ("./List.txt", "r");
    create_list (&C);

	while (!feof(arquivo)) {
		fscanf (arquivo, "%d %s %f\n", &s.id, s.name, &s.gpa);

			insert_list (&C, s);
	}

}else if (!arquivo) {
		perror ("List");
		printf("O arquivo não existe!");
		system("pause");
		exit (1);
	}


	fclose (arquivo);

	do{

		printf ("Informe a ID do estudante:");
		printf("\n");
		printf ("Voltar ao MENU digite 0(zero)");
		printf("\n");
		scanf ("%d", &id);

		p = search_list (C, id);

		if (!p)
			printf ("ID #%d nao encontarda!\n", id);
			else
			// system( "clear||cls");
			printf ("%d\t%s\t%0.2f\n", p->id, p->name, p->gpa);
	}while (id !=0);

}

void cadastrarEstudante() {
	printf("caso 2\n");

	system("pause");
}

int main () {

	printf("============================LISTA DUPLAMENTE ENCADEADA==========================\n\n");

	int opcao;
do{

    printf("\n\tMENU\n");

     printf("informe a opcao desejada\n");
    printf("\n1 - Consultar estudante digite 1");
    printf("\n2 - Cadastrar estudante digite 2");
    printf("\n3 - Listar estudantes digite 3");
    printf("\n4 - sair 4\n\n");

    scanf("%d", &opcao);
   system( "clear||cls");

    switch(opcao){
        case 1:
           buscarEstudante(opcao);
        break;

        case 2:
            buscarEstudante(opcao);
       // cadastrarEstudante();
         system("pause");
        break;
        case 3:
            printf("caso 3 em desenvolvimento!!!\n");
            system("pause");
        break;
        case 4:
            printf("SAINDO...\n");
            system("pause");
        break;
        default:
            printf("opcao invalida\n");

         system("pause");

     }
     	system("@cls||clear");

}while(opcao != 4);

}
