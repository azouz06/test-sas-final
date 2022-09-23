#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct acheter
{
	int jour;
	int mois;
	int annee;
}Tdate;
typedef struct pharmacie
{
    char nom[100];
	int codebar;
    int quantite;
    float prix;
    float prixTTC;
    Tdate date;
}medicament;
medicament produit[100],max[100];
int i,j,k;
	char r[4];
    int n,N=0;

    ////////////////// //////////////////////  fonction ajouter   ////////////////////////////////////////////////
int ajouter()
{
	  printf("entrer n=");
	  scanf("%d",&n);
	  printf("\n\tentrer les details du produit :\n");
    	for(j=N;j<N+n;j++){
	     fflush(stdin);
	     printf("Entrer le nom de produit %d\n",j+1);
	     gets(produit[j].nom);
		 printf("Entrer le code bar de produit %d\n",j+1);
		 scanf("%d",&produit[j].codebar);
	     printf("Entrer le quantite de produit %d \n",j+1);
	     scanf("%d",&produit[j].quantite);
	     printf("Entrer le prix produit %d \n",j+1);
	     scanf("%f",&produit[j].prix);
	     produit[j].prixTTC=produit[j].prix*1.15;

	      } N+=n;
		  system("cls");
		  printf("\n\t\t\t*** Felicitation vous avez ajouter %d produit ***\n",j);
		   	
                printf("\n Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}  	

}

        /////////////////////////////////        fontion affichier ///////////////////////////////////////:
        
        int ordre;
        medicament str[1000],tmp;
    int affichier()
    
    {
    	
        		printf("affichier les produits selon l'ordre décroissant[1]  ou l'ordre alphabetique[2]:");
        		scanf("%d",&ordre);
        		if(ordre==1){
        			for(i=0;i<N;i++){
        				  for(j=i+1;j<N;j++){
        				  	if(produit[i].prix<produit[j].prix){
        				  		tmp=produit[i];
        				  		produit[i]=produit[j];
        				  		produit[j]=tmp;
							  }
						  }
					}
					for(i=0;i<N;i++){
							printf("\n***** les produit ajouter sont :******\n");
				printf("\t____________________________________________________________________________");
        	    printf("\n\tNOMBRE--->NOM----CODE BAR----QUANTITE----PRIX     ----PRIXTTC   \n");
        	    printf("\t____________________________________________________________________________\n");
				for(i=0;i<N;i++){
        		printf(" \t%d    --->%s    ----%d      ----%d      ----%.2f     ----%.2f      \n",i+1,produit[i].nom,produit[i].codebar,produit[i].quantite,produit[i].prix,produit[i].prixTTC);}
					}
			}
				else {
						for(i=0;i<N;i++){
        				  for(j=i+1;j<N-1;j++){
        				  	if(strcmp(produit[i].nom,produit[j].nom)>0){
        				  		tmp=produit[j];
        				  		produit[i]=produit[j];
        				  		produit[j]=tmp;
							  }
						  }
			         	}
							printf("\n\t***** les produit ajouter sont :******\n");
        	            printf("\n\t NOM \t CODE BAR \t QUANTITE \t PRIX  PRIXTTC \n");

				for(i=0;i<N;i++){
        		printf(" \t%d:\t %s \t %d \t %d \t\t  %.2f \t\t %.2f\n",i+1,produit[i].nom,produit[i].codebar,produit[i].quantite,produit[i].prix,produit[i].prixTTC);}
					}
				for(i=0;i<N;i++){
					if(produit[i].quantite==0)
					{
					printf("\n **** le stock de  produit  %s  est vide ******\n",produit[i].nom);
					printf("Alimenter le stock oui/Non");
					scanf("%s",&r);
					                 if(r[0]=='o'||r[0]=='0'){ system("cls");return stock();}
					                 else{break;}
									 
									 
					}
		      }
				printf("\n Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}
        	

	}

	///////////////////////////////   Fonction Recherche  /////////  //////////////////////////////////////
	
    	int rech,test=0;
	    int code;
    	int nombre;
	    int quan;
	
	int recherche()
	{
		
		printf("recheche sur la produit par  code bar(1) ou quantite(2):\n");
		printf("le choix-->");
		scanf("%d",&rech);
		if(rech==1){
			printf("\n Entrer le code bar de produit :");
			scanf("%d",&code);
		     for(i=0;i<N;i++){
	             	if(code==produit[i].codebar){
                            printf("\n***le produit exist*** \n");
                            test=1;}
	          	}

	          	 if(test!=1) {printf("\n***le produit n'exist pas*** \n");
				  }
      	}
      	else if(rech==2){
      		    printf("Entrer la quantite de produit rechercher:");
      		    scanf("%d",&quan);
      		    for(i=0;i<N;i++){
				  if(produit[i].quantite<0||produit[i].quantite<=quan){nombre+=i;
				  }
				  else break;
				  }
				  printf("\nExist %d produit inferieure a %d\n",nombre,quan);

		  }
		  printf("\n Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}
	}

				/////////////////////// //////  FONCTION SUPRIMER /////////////////////////////////////////////////////////////////
				
            int nb=0;
        int suprimer()
          {
              printf("Entrer le code bar de produit suprimer: ");
              scanf("%d",&code);
              for(i=0;i<N;i++){
                if(code==produit[i].quantite){
                        nb+=i;
                         for(i=nb;i<N;i++){
                                  produit[i]=produit[i+1];
                                    }
                            printf("\n** l'operation de suprimer realiser avec succes **\n");
                            test=1;
                         }
                }
                N--;
                if(test!=1){printf("\n** Le produit n'exist pas **");}
                	printf("\n Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}
			
 }
        
        /////////////////// STOCK DE PRODUIT ET AJOUTER LES PRODUITS QUI INFERIER A 3 ///////////////////////////////////////
        int prod[1000];
        
    int stock()
        {
            printf("\n\t Alimenter le stock de produit de quantite inferieure a 3:\n");
            for(i=0,j=0;i<N;i++){
                if(produit[i].quantite<=3){
                    printf("\nNombre-->NOM \t QUANTITE \t PRIXTTC\n");
                    printf("\n%d--> %s\t %d\t %.2f\n",i+1,produit[i].nom,produit[i].quantite,produit[i].prixTTC);
                    printf("\n\tEntrer le nombre de quantite qui veux ajouter de %s :",produit[i].nom);
                    scanf("%d",&prod[j]);
                    printf("\n\t*** l'operation d'ajoute active ***\n");
                    produit[i].quantite+=prod[j];j++;test=1;

                    }
              }

              if(test==0){printf("\n*** n'exist aucune produit de quantite inferieurr a 3 :***");}
              test--;
             	printf("\n Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}
			
        }
        
        ////////////////////////////      fonction acheter  /////////////////////////////////////////////////////////////
        int quanacheter;
        char produitacheter[30];
        int nom;
        int b=0;
        float sommeprix=0;
        ///medicament  tmp;
        
    acheter()
      {
			int test=0;
			printf("Entrer le nom de produit qui vous acheter ");
        	fflush(stdin);
        	scanf("%s",&produitacheter);
        	for(i=0;i<N;i++){
        		if( strcmp(produitacheter,produit[i].nom)==0) 
				{
					test=1;	b++;
					
				}
				
			}
			
			
		 if(test==1){
			printf("entrer la date d'acheter d'aujourduit :");
			for(i=0;i<1;i++){
				 printf("la date de acheter :\n");
        			     printf(" jour :");
						 scanf("%d",&produit[i].date.jour);
        			     printf(" mois :");
						 scanf("%d",&produit[i].date.mois);
						 printf(" annee :");
						 scanf("%d",&produit[i].date.annee);
        			     (produit[b].quantite)-=quanacheter;
			}
			
        
		   
			printf("Entrer la quantite de produit acheter:");
        			scanf("%d",&quanacheter);
        			printf("\n\t\t** Merci d'acheter --> Le demmande activer avec success **\n");
			for(i=0;i<N;i++){
			
			(produit[i].quantite)-=quanacheter;
		                 sommeprix+=produit[i].prix*(quanacheter);
			}	         
        	}
			else printf("\n***le produit n'exist pas ***");
			
          		printf("\n Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}
		}

      ///////////// //////////////////////////////////// STATISTIQUE DE VENT:////////////////////////////://///////////////
                   
        statistique()
        
        {  
        medicament max[]=produit[0];
		 for(i=0;i<1;i++){
        	printf("\n\t\tDans la date prix de vent dans : %d/%d/%d\n ",produit[i].date.jour,produit[i].date.mois,produit[i].date.annee);
        		}
        	printf("\n\t\t-->>le prix totale de  produit = %.2f DH",sommeprix);
        	printf("\n\t\t-->>le prix moyenne de produit = %.2f DH",sommeprix/b);	
        		for(i=0;i<N;i++){
        				  for(j=i+1;j<N;j++){
        				  	if(produit[i].prix>produit[j].prix){
        				  		max=produit[i].prix;
        				  		
							  }
						  }
					}
			    for(i=0;i<N;i++){printf("le maximal %.2f\n",produit[i].prix);
				}
        		printf("\n Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}
		}
                   
                   
                   
                   
                   
                   
                   
                   
                   

int main()
{
       
       time_t now;
       time(&now);
       printf("\n\n\t\t\t\t\t  %s",ctime(&now));

       int option ,i,j;
       star1:
       printf("\n\t\t================ BIENVENUE AU PHARMACIE ALCHIFAA=================\n");
       printf("\n\t\t================ **CHOISIR VOTRE CHOIX **=================\n");

       printf("\n\t\t1.<-- Ajouter un produit\n");
       printf("\n\t\t2.<-- Affichier tous les produits\n");
       printf("\n\t\t3.<-- Recherche  sur un produit\n");
       printf("\n\t\t4.<-- Supprimer un produit\n");
       printf("\n\t\t5.<-- Stocks des produits\n");
       printf("\n\t\t6.<-- Acheter un produit\n");
       printf("\n\t\t7.<-- Statistique de vent\n");
       printf("\n\t\t8.<-- Quitter le programme\n");

       printf("\n\t\t     ===>> Entrer le choix ::");
       scanf("%d",&option);
       while(option<1 || option>8){
            printf("\n\t\t     ===>> Entrer le choix\n");
            scanf("%d",&option);
           }
       
                      
       switch(option){

       case 1:system("cls");
              ajouter ();

		break;
        case 2: system("cls");
               	affichier();
        break;
        case 3:
        	system("cls");
        	recherche();
        break;
        case 4:
            system("cls");
            suprimer();
        break;
        break;
        case 5:
            system("cls");
            stock();
        break;
        break;
        case 6:
        	system("cls");
        	acheter();
        break;
        case 7:
        	system("cls");
        	statistique();
        break;
        case 8:
        return 0;
        break;
                 	}


    return 0;
}
