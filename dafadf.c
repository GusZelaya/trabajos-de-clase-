/*
 ============================================================================
 Name        : ventanadetexto.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in GTK+
 ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *selector;
GtkWidget *boton1;
GtkWidget *texto;

GtkWidget *builder;
void fileSelectCB()
{
	selector=
	gtk_file_chooser_get_filename (
	  GtkFileChooser* chooser
	)
	g_print("hola");
}

void ba()
{
	g_print("hola");
}
 int main (int argc, char *argv[])
 {
    gtk_init(&argc,&argv);

    builder=gtk_builder_new_from_file ("gtkshowarc.ui");

    window = GTK_WINDOW(gtk_builder_get_object(builder,"window"));
    gtk_window_set_title (GTK_WINDOW(window), "abrir archivos");

    g_signal_connect (window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    selector=gtk_builder_get_object (builder,"botonarch");

    boton1=gtk_builder_get_object (builder,"botonabr");

    g_signal_connect (selector, "file-set",G_CALLBACK(fileSelectCB),NULL);
    g_signal_connect (boton1, "clicked",G_CALLBACK(ba),NULL);

    texto=gtk_builder_get_object (builder,"wintext");

    gtk_widget_show_all (GTK_WIDGET(window));

    gtk_main();



    return 0;
 }
