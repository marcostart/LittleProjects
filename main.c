#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choix=0 ,nombre1 ,nombre2 ,taBin[50] ,i=0,k ,t=0 ,rest ,*taBin2=NULL;
    restart:
    printf("Ce programme effectue le decalage d'un nombre\n\nEntrer l'operande de gauche et l'operande de droite en les separant par un espace\n");
    scanf("%d %d",&nombre1 ,&nombre2);
    printf("Quelle decalage voulez vous ?\n\n1-Vers la droite\n\n2-Vers la gauche\n");
    scanf("%d",&choix);
    rest=nombre1 % nombre2;
    do
    {
        taBin[i]=nombre1%2 ;
        nombre1=(nombre1-taBin[i])/2 ;
        i++;
    }while (nombre1!=0) ;
    t=i-1;
    rest=nombre2-rest ;
    i+=rest ;
    taBin2=malloc(i*sizeof(int));
    if (taBin2==NULL)
    {
       exit(0);
    }
    for (k=0 ;k<i;k++)
    {
       if (k<rest)
           taBin2[k]=0;
        else
        {
            taBin2[k]=taBin[t];
            t--;
        }
    }
    nombre1=0;
    printf("La representation en binaire du nombre est:");
    for (t=0;t<i;t++)
        printf("%d",taBin2[t]);
    switch(choix)
    {
        case 1:
            for(t=i-1;t>=nombre2 ;t--)
            {
                taBin2[t]=taBin2[t-nombre2];
            }
            for(t=0 ;t<nombre2;t++)
                taBin2[t]=0;
            for (t=0;t<i;t++)
                nombre1=nombre1+taBin2[t]*pow(2,i-1-t);
             printf("\nEt son decalage a droite donne: %d\n",nombre1);
            break;
        case 2:
            for (t=0;t<(i-nombre2);t++)
            {
                taBin2[t]=taBin2[t+nombre2];
                nombre1=nombre1+taBin2[t]*pow(2,(i-1-t));
            }
            for (t=nombre2;t<i;t++)
                taBin2[t]=0;
             printf("\nEt son decalage a gauche donne: %d\n",nombre1);
            break;
        default :
            printf("\nErreure veuiller entrer un choix correct\n");
            goto restart;
            break;
    }
    free(taBin2);
    return 0;
}
