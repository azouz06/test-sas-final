#include<stdio.h>
///#include<stdlib.h>
///#include<time.h>
///#include<string.h>
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
	  printf("\n\t\t ===> Entrer nombre de produit N=");
	  scanf("%d",&n);
	  printf("\n\n\t *** Entrer les details du produit ***\n");
    	for(j=N;j<N+n;j++){
	     fflush(stdin);
	     printf("\n--> Entrer le nom de produit %d :\n",j+1);
	     gets(produit[j].nom);
		 printf("--> Entrer le code bar de produit %d :\n",j+1);
		 scanf(" %d",&produit[j].codebar);
	     printf("--> Entrer le quantite de produit %d : \n",j+1);
	     scanf(" %d",&produit[j].quantite);
	     printf("--> Entrer le prix produit %d :\n",j+1);
	     scanf(" %f",&produit[j].prix);
	     produit[j].prixTTC=produit[j].prix*1.15;

	      } N+=n;
		  system("cls");
		  printf("\n\t\t\t*** Felicitation vous avez ajouter %d produit ***\n",j);
		   	
                printf("\n--> Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}  	

}

        /////////////////////////////////        fontion affichier ///////////////////////////////////////:
        
        int ordre;
        medicament str[1000],tmp;
    int affichier()
    
    {
    	
        		printf("\n--->>  Affichier les produits selon l'ordre decroissant de prix[1]  ou l'ordre alphabetique[2]:");
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
							printf("\n\t\t*****   les produit ajouter sont a l'odre decoissant de prix :  ******\n");
				
        	    printf("\n\n\tNOMBRE--->NOM \t\t CODEBAR \t\t QUANTITE \t\t PRIX \t\t PRIXTTC   \n\n");
        	    
				for(i=0;i<N;i++){
        		printf("\t%d    --->%s \t  %d \t\t  %d \t\t  %.2f \t\t  %.2f   \n",i+1,produit[i].nom,produit[i].codebar,produit[i].quantite,produit[i].prix,produit[i].prixTTC);}
					}
			}
				else {
						for(i=0;i<N;i++){
        				  for(j=i+1;j<N;j++){
        				  	if(strcmp(produit[i].nom,produit[j].nom)>0){
        				  		tmp=produit[i];
        				  		produit[i]=produit[j];
        				  		produit[j]=tmp;
							  }
						  }
			         	}
							printf("\n\t\t***** les produit ajouter sont a l'ordre alphabetique:  ******\n\n");
        	            printf("\n\t NOMBRE \t\t NOM \t\t CODE BAR \t\t QUANTITE \t\t PRIX \t\tPRIXTTC\n\n");

				for(i=0;i<N;i++){
        		printf("\t%d:\t %s \t\t %d \t\t %d \t\t %.2f \t\t %.2f\n",i+1,produit[i].nom,produit[i].codebar,produit[i].quantite,produit[i].prix,produit[i].prixTTC);}
					}
				for(i=0;i<N;i++){
					if(produit[i].quantite==0)
					{
					printf("\n ****  le stock de  produit  %s  est vide   ******\n",produit[i].nom);
					printf("\n-->>  Alimenter le stock oui/Non");
					scanf("%s",&r);
					if(r[0]=='o'||r[0]=='0'){ system("cls");return stock();}
					else{break;}
									 
									 
					}
		      }
				printf("\n--> Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}
        	

	}

	///////////////////////////////   Fonction Recherche  /////////  //////////////////////////////////////
	
    	int rech,test;
	    int code;
    	int nombre;
	    int quan;
	
	int recherche()
	{
		
		printf("\n--->> Recheche sur la produit par  Code bar[1] ou quantite[2]:\n");
		printf(" Le choix ==>");
		scanf("%d",&rech);
		if(rech==1){test=0;
			printf("\n-->> Entrer le code bar de produit :");
			scanf("%d",&code);
		     for(i=0;i<N;i++){
	             	if(code==produit[i].codebar){
                            printf("\n*** le produit exist *** \n");
                            test=1;}
	          	}

	          	 if(test!=1) {printf("\n***  le produit n'exist pas  *** \n");
				  }
				  
      	}
      	else if(rech==2){  test=0;
      		    printf("\n--->>  Entrer la quantite de produit rechercher:");
      		    scanf("%d",&quan);
      		    
      		     for(i=0;i<N;i++){
	             	if(quan==produit[i].quantite){
                            printf("\n***  le produit exist  *** \n");
                             test=1;}
	          	}

	          	 if(test!=1) {printf("\n*** Le produit n'exist pas *** \n");
				  }
      		    
      		    for(i=0;i<N;i++){
				  if(produit[i].quantite<0||produit[i].quantite<=quan){nombre+=i;
				  }
				  else break;
				  }

		  }
		  printf("\n--> Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}
	}

				/////////////////////// //////  FONCTION SUPRIMER /////////////////////////////////////////////////////////////////
				
            int nb=0;
        int suprimer()
          {
              printf("--->> Entrer le code bar de produit suprimer: ");
              scanf("%d",&code);
              for(i=0;i<N;i++){
                if(code==produit[i].quantite){
                        nb+=i;
                         for(i=nb;i<N;i++){
                                  produit[i]=produit[i+1];
                                    }
                            printf("\n\t*** l'operation de suprimer realiser avec success ***\n");
                            test=1;
                         }
                }
                N--;
                if(test!=1){printf("\n\t*** Le produit n'exist pas ***");}
                	printf("\n--> Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}
			
 }
        
        /////////////////// STOCK DE PRODUIT ET AJOUTER LES PRODUITS QUI INFERIER A 3 ///////////////////////////////////////
        int prod;
        
    int stock()
        {
            printf("\n\t--->> Alimenter le stock de produit de quantite inferieure a 3:\n");
            for(i=0,j=0;i<N;i++){
                if(produit[i].quantite<=3){
                    printf("\nNombre-->NOM \t QUANTITE \t PRIXTTC\n");
                    printf("\n%d--> %s\t %d\t %.2f\n",i+1,produit[i].nom,produit[i].quantite,produit[i].prixTTC);
                    printf("\n\t--->> Entrer le nombre de quantite qui veux ajouter de %s :",produit[i].nom);
                    scanf("%d",&prod);
                    printf("\n\t*** l'operation d'ajoute active ***\n");
                    produit[i].quantite+=prod;j++;test=1;

                    }
              }

              if(test==0){printf("\n*** n'exist aucune produit de quantite inferieurr a 3 :***");}
              test--;
             	printf("\n--> Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}
			
        }
        
        ////////////////////////////      fonction acheter  /////////////////////////////////////////////////////////////
        int quanacheter;
        char produitacheter[30];
        int nom,k=0;
        int b=1,a;
        float c[1000];
        float sommeprix=0;
        int pp=0;
    int acheter()
      {
			int test=0;
			printf("\n\t--->> Entrer le nom de produit qui vous acheter ::");
        	fflush(stdin);
        	scanf("%s",&produitacheter);
        	printf("**********%d**%d*****",k,b);
        	for(i=0;i<N;i++){
        		if( strcmp(produitacheter,produit[i].nom)==0) 
				{
					test=1;a=i;c[k]=produit[i].prix;
					
				}
			}
			
		 if(test==1){
			printf("\n\t--->> Entrer la date d'acheter d'aujourduit :");
			for(i=0;i<1;i++){
        			     printf("\n\t--> jour :");
						 scanf("%d",&produit[i].date.jour);
        			     printf("\t--> mois :");
						 scanf("%d",&produit[i].date.mois);
						 printf("\t--> annee :");
						 scanf("%d",&produit[i].date.annee);
						}	
						 
        			
		
			printf("\n\t--->> Entrer la quantite de produit acheter:");
        			scanf("%d",&quanacheter);
        		
			 	
    		       if(quanacheter>produit[a].quantite){
				   	pp=1;}
				if(pp==1){printf("\n ***** Cette quantite n'exist pas dans le stock *****.\n");
				    printf("\n --> Aller a menu  oui/non :");
		            scanf("%s",&r);
				    if(r[0]=='o'||r[0]=='0'||r[0]=='O'||r[0]=='o'){system("cls");
				    return main();};
			     	}
        			
				else printf("\n\t\t****  Merci d'acheter --> Le demmande activer avec success ****\n");
						(produit[a].quantite)-=quanacheter;
					sommeprix+=produit[a].prix*(quanacheter);
					
					k++;
					b++;
					
							           
        	}
			else printf("\n\t\t*** le produit n'exist pas ***");
			
          		printf("\n --> Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}
		}

      ///////////// //////////////////////////////////// STATISTIQUE DE VENT:////////////////////////////://///////////////
       
		float min,ma;

        int statistique()
{       	ma=produit[a].prix;	
         
		 for(i=0;i<1;i++){
        	printf("\n\t\t>>>>*****  Dans la date prix de vent dans : %d/%d/%d   *****<<<<\n ",produit[i].date.jour,produit[i].date.mois,produit[i].date.annee);
        		}
        	printf("\n\t\t--->> Le total des prix des produits vendus en journee est %.2f DH",sommeprix);
        	printf("\n\t\t--->> Le moyenne  des prix des produits vendus en journee est %.2f DH",sommeprix/b);	
        	
			for(i=0;i<b;i++)
			{printf("\nc[%d]=%.2f\n",i,c[i]);
								
							}
				/*
					for(i=0;i<b-1;i++){
						for(j=i+1;j<b;j++){
							if(ma<c[j]) {  ma=c[j];}
							
						
							
				
					 for(i=0;i<b-1;i++){
						for(j=i+1;j<b-1;j++){
							if(min>c[j]) {  min=c[j];}
							}}
							*/
			    printf("\n\t\t--->> Le Maximal des prix des produits vendus en journee est: %.2f DH",ma);
			    printf("\n\t\t--->> Le Minimal des prix des produits vendus en journee est %.2f DH\n",min);
		
        		printf("\n --> Aller a menu  oui/non :");
		        scanf("%s",&r);
		        if(r[0]=='o'||r[0]=='O'||r[0]=='O'||r[0]=='o'){system("cls");
				return main();}
		}
        ////////////////////////////////////////////////
    
                                   

int main()
{
       system("color 3F");
       time_t now;
       time(&now);
       printf("\n\t\t\t\t  %s",ctime(&now));
       int option ,i,j;
       printf("\n\t                --------------------------------------------                   ");
       printf("\n\t================ BIENVENUE AU PLANS DE GESTION DE PHARMACIE =================");
       printf("\n\t                --------------------------------------------                   ");

       printf("\n\t        ================ **CHOISIR VOTRE CHOIX **========================\n\n");
       printf("                      =====================================================");
       printf("\n\t\t      *                                                   *");
       printf("\n\t\t     **        1.<-- Ajouter un produit                   **\n");
       printf("\n\t\t    ***        2.<-- Affichier tous les produits          ***\n");
       printf("\n\t\t   ****        3.<-- Recherche  sur un produit            ****\n");
       printf("\n\t\t  *****        4.<-- Supprimer un produit                 *****\n");
       printf("\n\t\t  *****        5.<-- Stocks des produits                  *****\n");
       printf("\n\t\t   ****        6.<-- Acheter un produit                   ****\n");
       printf("\n\t\t    ***        7.<-- Statistique de vent                  ***\n");
       printf("\n\t\t     **        8.<-- Quitter le programme                 **");
       printf("\n\t\t      *                                                   *\n");
	   printf("                       ===================================================");
       printf("\n\t\t     ===>> Entrer le choix ::");
       scanf("%d",&option);
       while(option<1 || option>8){
            printf("\n\t\t     ===>> Entrer le choix ::");
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
        case 5:
            system("cls");
            stock();
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
        	system("cls");
        	printf("\n\n\n\n\n\t\t\t\t\t*******  MERCI POUR VISITE !!!! *******\n\n\n\n\n");
        	system("pause");
        break;
   	}
    return 0;
}
