#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <string.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fn.h" 


//windows
  GtkWidget *authentification;
  GtkWidget *Admin;
  GtkWidget *Coach;
  GtkWidget *Medecin;
  GtkWidget *Kin__;
  GtkWidget *Dieteticien;
  GtkWidget *Adh__rent;
  GtkWidget *Ajout_Adh__rent;
  GtkWidget *Ajout_coach;
  GtkWidget *Ajout_medcin;
  GtkWidget *Ajout_kin__;
  GtkWidget *Ajout_dieteticien;
  GtkWidget *fiche_med;
  GtkWidget *fiche_suivi;
////////////////////////////////////////////////////////////////
GtkWidget *input1;  //u.login
GtkWidget *input2;  //u.password
GtkWidget *input3;	// entry3
GtkWidget *input4;     	//entry4

GtkWidget *output1;

///////////////////////////////////////////////
//file
FILE*f;  //user
FILE*f1; //admin
FILE*f2; //adherant
FILE*f3 ;//coach
FILE*f4; //medecin
FILE*f5; //kine
FILE*f6; //dieteticien

/////////////////////////////////////////////// 

//struct
user u;
admin a;
adherent ad;
coach c;
medecin m;
kine k;
dieteticien d;

////////////////////////////////////////////////

int v=-1;


void on_button1_clicked (GtkWidget *obj, gpointer user_data) //login
{


authentification=lookup_widget(obj,"authentification");
input1=lookup_widget(obj,"entry1");
input2=lookup_widget(obj,"entry2");
output1=lookup_widget(obj,"label3");




strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(u.password,gtk_entry_get_text(GTK_ENTRY(input2)));

v=verifier(u.login,u.password);



if(v==1)
{
Admin=create_Admin();
gtk_widget_destroy (authentification);
gtk_widget_show (Admin);
}
else if(v==2){
Adh__rent=create_Adh__rent();
gtk_widget_destroy(authentification);
gtk_widget_show(Adh__rent);
}
else if(v==3){
Coach=create_Coach();
gtk_widget_destroy(authentification);
gtk_widget_show(Coach);
}
else if(v==4){
Medecin=create_Medecin();
gtk_widget_destroy(authentification);
gtk_widget_show(Medecin);
}
else if(v==5){
Kin__=create_Kin__();
gtk_widget_destroy(authentification);
gtk_widget_show(Kin__);
}
else if(v==6){
Dieteticien=create_Dieteticien();
gtk_widget_destroy(authentification);
gtk_widget_show(Dieteticien);
}


else { gtk_label_set_text(GTK_LABEL(output1),"verifiez ID ou mot de passe");}

}


void on_logout1_clicked (GtkButton *obj, gpointer user_data)
{
authentification=create_authentification();
gtk_widget_destroy (Admin);
gtk_widget_show (authentification);
v=-1;
}


void on_logout2_clicked (GtkButton *obj, gpointer user_data)
{
authentification=create_authentification();
gtk_widget_destroy(Adh__rent);
gtk_widget_show(authentification);v=-1;
}


void on_logout3_clicked (GtkButton *obj, gpointer user_data)
{
authentification=create_authentification();
gtk_widget_destroy(Coach);
gtk_widget_show(authentification);v=-1;
}


void on_logout4_clicked (GtkButton *obj, gpointer user_data)
{
authentification=create_authentification();
gtk_widget_destroy(Medecin);
gtk_widget_show(authentification);v=-1;
}

void on_logout5_clicked (GtkButton *obj, gpointer user_data)
{
authentification=create_authentification();
gtk_widget_destroy(Kin__);
gtk_widget_show(authentification);v=-1;
}


void on_logout6_clicked (GtkButton *obj, gpointer user_data)
{
authentification=create_authentification();
gtk_widget_destroy(Dieteticien);
gtk_widget_show(authentification);v=-1;
}


void on_Admin_set_focus(GtkWindow *window, GtkWidget *widget,gpointer user_data)
{

GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;


output3=lookup_widget(window,"label36");
output4=lookup_widget(window,"label37");
output5=lookup_widget(window,"label200");
output6=lookup_widget(window,"label201");
output7=lookup_widget(window,"label202");


f1=fopen("admin.txt","r");
while(fscanf(f1,"%s %s %s %s %s\n",a.nom,a.prenom,a.num,a.login,a.password)!=EOF)
{ if(strcmp(u.login,a.login)==0 && strcmp(u.password,a.password)==0)
{
gtk_label_set_text(GTK_LABEL(output3),a.nom);
gtk_label_set_text(GTK_LABEL(output4),a.prenom);
gtk_label_set_text(GTK_LABEL(output5),a.num);
gtk_label_set_text(GTK_LABEL(output6),a.login);
gtk_label_set_text(GTK_LABEL(output7),a.password);
}
}


fclose(f1);
}


void on_Adh__rent_set_focus(GtkWindow *window,GtkWidget *widget,gpointer user_data)
{


GtkWidget *output8;
GtkWidget *output9;
GtkWidget *output10;
GtkWidget *output11;
GtkWidget *output12;
GtkWidget *output13;
GtkWidget *output14;
GtkWidget *output15;
GtkWidget *output16;

output8=lookup_widget(window,"label71");
output9=lookup_widget(window,"label72");             
output10=lookup_widget(window,"label204");
output11=lookup_widget(window,"label77");
output12=lookup_widget(window,"label73");
output13=lookup_widget(window,"label74");
output14=lookup_widget(window,"label78");
output15=lookup_widget(window,"label79");
output16=lookup_widget(window,"label80");


f2=fopen("adherent.txt","r");
while(fscanf(f2,"%s %s %s %s %s %s %s %s %s\n",ad.nom,ad.prenom,ad.num,ad.date_ne,ad.sexe,ad.type_dabo,ad.payemant,ad.login,ad.password)!=EOF)
{ if(strcmp(u.login,ad.login)==0 && strcmp(u.password,ad.password)==0)
	{
gtk_label_set_text(GTK_LABEL(output8),ad.nom);
gtk_label_set_text(GTK_LABEL(output9),ad.prenom);
gtk_label_set_text(GTK_LABEL(output10),ad.num);
gtk_label_set_text(GTK_LABEL(output11),ad.date_ne);
gtk_label_set_text(GTK_LABEL(output12),ad.sexe);
gtk_label_set_text(GTK_LABEL(output13),ad.type_dabo);
gtk_label_set_text(GTK_LABEL(output14),ad.payemant);
gtk_label_set_text(GTK_LABEL(output15),ad.login);
gtk_label_set_text(GTK_LABEL(output16),ad.password);
	}
}
fclose(f2);

}


void on_Coach_set_focus(GtkWindow *window,GtkWidget *widget,gpointer user_data)
{
GtkWidget *output17;
GtkWidget *output18;
GtkWidget *output19;
GtkWidget *output20;
GtkWidget *output21;
GtkWidget *output22;
GtkWidget *output23;

output17=lookup_widget(window,"label44");
output18=lookup_widget(window,"label48");             
output19=lookup_widget(window,"label210");
output20=lookup_widget(window,"label105");
output21=lookup_widget(window,"label101");
output22=lookup_widget(window,"label206");
output23=lookup_widget(window,"label208");

f3=fopen("coach.txt","r");
while(fscanf(f3,"%s %s %s %s %s %s %s\n",c.nom,c.prenom,c.date_ne,c.sexe,c.specialite,c.login,c.password)!=EOF)
{ if(strcmp(u.login,c.login)==0 && strcmp(u.password,c.password)==0)
	{
gtk_label_set_text(GTK_LABEL(output17),c.nom);
gtk_label_set_text(GTK_LABEL(output18),c.prenom);
gtk_label_set_text(GTK_LABEL(output19),c.date_ne);
gtk_label_set_text(GTK_LABEL(output20),c.sexe);
gtk_label_set_text(GTK_LABEL(output21),c.specialite);
gtk_label_set_text(GTK_LABEL(output22),c.login);
gtk_label_set_text(GTK_LABEL(output23),c.password);
	}
}
fclose(f3);

}


void on_Medecin_set_focus(GtkWindow *window,GtkWidget *widget,gpointer user_data)
{

GtkWidget *output24;
GtkWidget *output25;
GtkWidget *output26;
GtkWidget *output27;
GtkWidget *output28;
GtkWidget *output29;


output24=lookup_widget(window,"label18");
output25=lookup_widget(window,"label19");             
output26=lookup_widget(window,"label212");
output27=lookup_widget(window,"label106");
output28=lookup_widget(window,"label213");
output29=lookup_widget(window,"label214");


f4=fopen("medecin.txt","r");
while(fscanf(f4,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.date_ne,m.sexe,m.login,m.password)!=EOF)
{ if(strcmp(u.login,m.login)==0 && strcmp(u.password,m.password)==0)
	{
gtk_label_set_text(GTK_LABEL(output24),m.nom);
gtk_label_set_text(GTK_LABEL(output25),m.prenom);
gtk_label_set_text(GTK_LABEL(output26),m.date_ne);
gtk_label_set_text(GTK_LABEL(output27),m.sexe);
gtk_label_set_text(GTK_LABEL(output28),m.login);
gtk_label_set_text(GTK_LABEL(output29),m.password);
	}
}
fclose(f4);
}


void on_Kin___set_focus(GtkWindow *window,GtkWidget *widget,gpointer user_data)
{
GtkWidget *output30;
GtkWidget *output31;
GtkWidget *output32;
GtkWidget *output33;
GtkWidget *output34;
GtkWidget *output35;


output30=lookup_widget(window,"label95");
output31=lookup_widget(window,"label97");             
output32=lookup_widget(window,"label99");
output33=lookup_widget(window,"label220");
output34=lookup_widget(window,"label222");
output35=lookup_widget(window,"label224");


f5=fopen("kine.txt","r");
while(fscanf(f5,"%s %s %s %s %s %s\n",k.nom,k.prenom,k.date_ne,k.sexe,k.login,k.password)!=EOF)
{ if(strcmp(u.login,k.login)==0 && strcmp(u.password,k.password)==0)
	{
gtk_label_set_text(GTK_LABEL(output30),k.nom);
gtk_label_set_text(GTK_LABEL(output31),k.prenom);
gtk_label_set_text(GTK_LABEL(output32),k.date_ne);
gtk_label_set_text(GTK_LABEL(output33),k.sexe);
gtk_label_set_text(GTK_LABEL(output34),k.login);
gtk_label_set_text(GTK_LABEL(output35),k.password);
	}
}
fclose(f5);
}


void on_Dieteticien_set_focus(GtkWindow *window,GtkWidget *widget,gpointer user_data) 
{
GtkWidget *output36;
GtkWidget *output37;
GtkWidget *output38;
GtkWidget *output39;
GtkWidget *output40;
GtkWidget *output41;


output36=lookup_widget(window,"label102");
output37=lookup_widget(window,"label103");             
output38=lookup_widget(window,"label216");
output39=lookup_widget(window,"label104");
output40=lookup_widget(window,"label217");
output41=lookup_widget(window,"label218");


f6=fopen("dieteticien.txt","r");
while(fscanf(f6,"%s %s %s %s %s %s\n",d.nom,d.prenom,d.date_ne,d.sexe,d.login,d.password)!=EOF)
{ if(strcmp(u.login,d.login)==0 && strcmp(u.password,d.password)==0)
	{
gtk_label_set_text(GTK_LABEL(output36),d.nom);
gtk_label_set_text(GTK_LABEL(output37),d.prenom);
gtk_label_set_text(GTK_LABEL(output38),d.date_ne);
gtk_label_set_text(GTK_LABEL(output39),d.sexe);
gtk_label_set_text(GTK_LABEL(output40),d.login);
gtk_label_set_text(GTK_LABEL(output41),d.password);
	}
}
fclose(f6);


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int w=0;

void on_button37_clicked (GtkWidget *obj, gpointer user_data) //ajout diet
{
if(w==0)
{
Ajout_dieteticien=lookup_widget(obj,"Ajout_dieteticien");
Ajout_dieteticien=create_Ajout_dieteticien();
gtk_widget_show(Ajout_dieteticien);}
w=1;

}

void on_button20_clicked (GtkButton *obj, gpointer user_data) // sauvegarder
{

}

void on_button21_clicked (GtkButton *obj, gpointer user_data) //quitter la fenetre
{
gtk_widget_destroy(Ajout_dieteticien);
w=0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_button43_clicked(GtkWidget *obj, gpointer user_data) //ajout  med
{
if(w==0)
{
Ajout_medcin=lookup_widget(obj,"Ajout_medcin");
Ajout_medcin=create_Ajout_medcin();
gtk_widget_show(Ajout_medcin);

}
w=1;

}


void on_button16_clicked(GtkWidget *obj, gpointer user_data) //sauvegarder
{

}

void on_button17_clicked(GtkWidget *obj, gpointer user_data) //quitter la fenetre
{
gtk_widget_destroy(Ajout_medcin);
w=0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void on_button31_clicked (GtkWidget *obj, gpointer user_data) //ajout adh
{
if(w==0)
{
Ajout_Adh__rent=lookup_widget(obj,"Ajout_Adh__rent");
Ajout_Adh__rent=create_Ajout_Adh__rent();
gtk_widget_show(Ajout_Adh__rent);}
w=1;

}


void on_button12_clicked (GtkWidget *obj, gpointer user_data)  //sauvegarder 
{

}

void on_button11_clicked (GtkWidget *obj, gpointer user_data)  //quitter
{
gtk_widget_destroy(Ajout_Adh__rent);
w=0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void on_button34_clicked (GtkWidget *obj, gpointer user_data) //ajout coach  Ajout_coach
{
if(w==0)
{
Ajout_coach=lookup_widget(obj,"Ajout_coach");
Ajout_coach=create_Ajout_coach();
gtk_widget_show(Ajout_coach);}
w=1;

}


void on_button13_clicked (GtkWidget *obj, gpointer user_data)  //sauvegarder
{

}


void on_button14_clicked (GtkWidget *obj, gpointer user_data)  //quitter
{
gtk_widget_destroy(Ajout_coach);
w=0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void on_button40_clicked (GtkWidget *obj, gpointer user_data)  //ajout kine   Ajout_kin__ 
{
if(w==0)
{
Ajout_kin__=lookup_widget(obj,"Ajout_kin__");
Ajout_kin__=create_Ajout_kin__();
gtk_widget_show(Ajout_kin__);}
w=1;
}

void on_button19_clicked (GtkWidget *obj, gpointer user_data) //sauvegarder
{

}


void on_button18_clicked (GtkWidget *obj, gpointer user_data) //quitter 
{
gtk_widget_destroy(Ajout_kin__);
w=0;

}

