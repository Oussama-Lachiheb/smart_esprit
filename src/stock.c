  #include "stock.h"
  #include <stdio.h>
#include <stdlib.h>
#include "string.h"
  void ajouter_produit( produit p){
FILE *f=NULL;
f=fopen("stock.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %d %s %s %d\n",p.prod_id,p.nom,p.nature,p.quant,p.type,p.date,p.lieu);
fclose(f);


}




void supprimer_st(char *prod_id){

FILE*f=NULL;
FILE*f1=NULL;
produit p ;
f=fopen("stock.txt","r");
f1=fopen("tmp.txt","w+");

while(fscanf(f,"%s %s %s %d %s %s %d\n",p.prod_id,p.nom,p.nature,&p.quant,p.type,p.date,&p.lieu)!=-1){
if(strcmp(prod_id,p.prod_id)!=0)
    fprintf(f1,"%s %s %s %d %s %s %d\n",p.prod_id,p.nom,p.nature,p.quant,p.type,p.date,p.lieu);
}
fclose(f);
fclose(f1);
remove("stock.txt");
rename("tmp.txt","stock.txt");

}




void modifier_stt(char prod_id[],produit r){
FILE*f=NULL;
FILE*f1=NULL;
produit p ;
f=fopen("stock.txt","r");

f1=fopen("tmp.txt","w+");

if ((f!=NULL)&&(f1!=NULL))
while(fscanf(f,"%s %s %s %d %s %s %d\n",p.prod_id,p.nom,p.nature,&p.quant,p.type,p.date,&p.lieu)!=-1){
if( strcmp(p.prod_id,prod_id)==0    )
{
fprintf(f1,"%s %s %s %d %s %s %d\n",r.prod_id,r.nom,r.nature,r.quant,r.type,r.date,r.lieu);
}
else
{
fprintf(f1,"%s %s %s %d %s %s %d\n",p.prod_id,p.nom,p.nature,p.quant,p.type,p.date,p.lieu);
}

}
fclose(f);
fclose(f1);
remove("stock.txt");
rename("tmp.txt","stock.txt");

}
enum
{
	EPROD,
	ENOM,
	ENAT,
	EQUANT,
	ETYPE,
	EDATE,
	ELIEU,
	COLUMNS2,
};
void afficher_st(GtkWidget *liste)
{
            GtkCellRenderer *renderer;
	    GtkTreeViewColumn *column;
 	    GtkTreeIter iter;
	    GtkListStore *store;
	    produit p;
        char prod_id[30];
	char nom[30];
	char nature[30];
	char quant[30];
	char type[30];
	char date[30];
	char lieu[30];
	
	
	
	    store==NULL;
 	    
	    FILE *f;
	    
	    store=gtk_tree_view_get_model(liste);
	    if(store==NULL)
            {
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer ,"text",EPROD, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Nom",renderer ,"text",ENOM, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Nature",renderer ,"text",ENAT, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Quantite",renderer ,"text",EQUANT, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Type",renderer ,"text",ETYPE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Date d'expiration",renderer ,"text",EDATE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Lieu de stockage",renderer ,"text",ELIEU, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);



}
	    store=gtk_list_store_new (COLUMNS2, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	    f=fopen("stock.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  
			//f=fopen("stock.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s\n",prod_id,nom,nature,quant,type,date,lieu)!=EOF)
			{
				gtk_list_store_append (store, &iter);
				gtk_list_store_set(store,&iter,EPROD,prod_id,ENOM,nom,ENAT,nature,EQUANT,quant,ETYPE,type,EDATE,date,ELIEU,lieu, -1);
			}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }
}

void chercher_st(GtkWidget *liste, char ch[30])
{
            GtkCellRenderer *renderer;
	    GtkTreeViewColumn *column;
 	    GtkTreeIter iter;
	    GtkListStore *store;
	    produit p;
        char prod_id[30];
	char nom[30];
	char nature[30];
	char quant[30];
	char type[30];
	char date[30];
	char lieu[30];
	
	
	
	    store==NULL;
 	    
	    FILE *f;
	    
	    store=gtk_tree_view_get_model(liste);
	    if(store==NULL)
            {
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer ,"text",EPROD, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Nom",renderer ,"text",ENOM, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Nature",renderer ,"text",ENAT, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Quantite",renderer ,"text",EQUANT, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Type",renderer ,"text",ETYPE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Date d'expiration",renderer ,"text",EDATE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Lieu de stockage",renderer ,"text",ELIEU, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


}
	    store=gtk_list_store_new (COLUMNS2, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	    f=fopen("stock.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  
			//f=fopen("stock.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s\n",prod_id,nom,nature,quant,type,date,lieu)!=EOF)
			{if (strcmp(prod_id,ch)==0){
				gtk_list_store_append (store, &iter);
				gtk_list_store_set(store,&iter,EPROD,prod_id,ENOM,nom,ENAT,nature,EQUANT,quant,ETYPE,type,EDATE,date,ELIEU,lieu, -1);
			}}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }
}



void cherche_produit(char prod_id[]){
FILE*f=NULL;
 produit p;
f=fopen("stock.txt","r");
while(fscanf(f,"%s %s %s %d %s %s %d\n",p.prod_id,p.nom,p.nature,&p.quant,p.type,p.date,&p.lieu)!=-1){
if(strcmp(p.prod_id,prod_id)==0)
     printf("%s %s %s %d %s %s %d\n",p.prod_id,p.nom,p.nature,p.quant,p.type,p.date,p.lieu);
}
fclose(f);

}


void utiliser_stt(char prod_id[],int x){
FILE*f=NULL;
FILE*f1=NULL;
produit p ;
f=fopen("stock.txt","r");

f1=fopen("tmp.txt","w+");

if ((f!=NULL)&&(f1!=NULL))
while(fscanf(f,"%s %s %s %d %s %s %d \n",p.prod_id,p.nom,p.nature,&p.quant,p.type,p.date,&p.lieu)!=-1){
if( strcmp(p.prod_id,prod_id)==0)
{
fprintf(f1,"%s %s %s %d %s %s %d \n",p.prod_id,p.nom,p.nature,(p.quant-x),p.type,p.date,p.lieu);
}
else
{
fprintf(f1,"%s %s %s %d %s %s %d \n",p.prod_id,p.nom,p.nature,p.quant,p.type,p.date,p.lieu);
}

}
fclose(f);
fclose(f1);
remove("stock.txt");
rename("tmp.txt","stock.txt");

}




int ret_qp(produit o){
FILE*f=NULL;
int bb;
produit p ;
f=fopen("stock.txt","r");

while(fscanf(f,"%s %s %s %d %s %s %d\n",p.prod_id,p.nom,p.nature,&p.quant,p.type,p.date,&p.lieu)!=-1){
if(strcmp(o.prod_id,p.prod_id)==0){
  bb = p.quant;   
}}

return bb;}


enum
{
	EPROD1,
	ENOM1,
	ENAT1,
	EQUANT1,
	ETYPE1,
	EDATE1,
	ELIEU1,
	ETAT1,
	COLUMNS22,
};
void stoq_ep(GtkWidget *liste,int mn)
{
            GtkCellRenderer *renderer;
	    GtkTreeViewColumn *column;
 	    GtkTreeIter iter;
	    GtkListStore *store;
	    produit p;
            char prod_id[30];
	char nom[30];
	char nature[30];
	char quant[30];
	char type[30];
	char date[30];
	char lieu[30];

	
	
	    store==NULL;
 	    
	    FILE *f;
	    
	    store=gtk_tree_view_get_model(liste);
	    if(store==NULL)
            {
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer ,"text",EPROD1, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Nom",renderer ,"text",ENOM1, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Nature",renderer ,"text",ENAT1, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Quantite",renderer ,"text",EQUANT1, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Type",renderer ,"text",ETYPE1, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Date d'expiration",renderer ,"text",EDATE1, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Lieu de stockage",renderer ,"text",ELIEU1, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Etat",renderer ,"text",ETAT1, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
	    store=gtk_list_store_new (COLUMNS22, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	    f=fopen("stock.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  
			f=fopen("stock.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s\n",prod_id,nom,nature,quant,type,date,lieu)!=EOF)
			{if (atoi(quant)<=mn){
				gtk_list_store_append (store, &iter);
				gtk_list_store_set(store,&iter,EPROD1,prod_id,ENOM1,nom,ENAT1,nature,EQUANT1,quant,ETYPE1,type,EDATE1,date,ELIEU1,lieu,ETAT1,"produit en rupture du stock", -1);
			}
			}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }
}



