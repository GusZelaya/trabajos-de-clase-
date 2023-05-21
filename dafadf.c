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

#define direccion "/home/lp1-2023/eclipse_workspace/Lab7/Debug/MostrarArchivo"
int bandera;
gchar * filename;

//widgets de utilidad
GtkBuilder * builder;

//widgets de Ventana
GtkWidget * Ventana;
GtkWidget * BotonArchivo;
GtkWidget * BotonConfirmar;
GtkWidget * Texto;

//funcion para copiar el contenido de un archivo dentro de una cadena
char* copy_file_to_string(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo: %s\n", filename);
        return NULL;
    }

    // Obtener el tamaño del archivo
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Crear una cadena del tamaño adecuado
    char* str = (char*)malloc((file_size + 1) * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "No se pudo asignar memoria para la cadena\n");
        fclose(file);
        return NULL;
    }

    // Leer los caracteres del archivo y copiarlos en la cadena
    size_t read_size = fread(str, sizeof(char), file_size, file);
    if (read_size != file_size) {
        fprintf(stderr, "No se pudo leer completamente el archivo\n");
        fclose(file);
        free(str);
        return NULL;
    }

    // Agregar el terminador de cadena al final
    str[file_size] = '\0';

    fclose(file);
    return str;
}

void guardar(GtkFileChooserButton *button, gpointer user_data)
{
    GtkFileChooser *file_chooser = GTK_FILE_CHOOSER(button);
    // Obtener la dirección del archivo seleccionado
    filename = gtk_file_chooser_get_filename(file_chooser);
    //vuelve a la pantalla anterior
    g_print("archivo: %s \n",filename);
}
//funcion para confirmar que quiere abrir el archivo seleccionado
void mostrar(GtkWidget event_box, GdkEventButton *event, gpointer data)
{
	bandera=1;
	   int c,cont;
	    FILE *a;
	    if ((a=fopen(filename,"r"))==NULL)
	    {
	    	printf("error\n");
	    }else{
	    	for (cont=0;(c=fgetc(a))!=EOF;cont++){}
	    	cont-=1;
	    	printf("tamaño del archivo: %d \n",cont);
	    	char* str = copy_file_to_string(filename);
	    	    if (str != NULL) {
	    	        printf("Contenido del archivo:\n%s\n", str);

	    	        GtkTextBuffer* buffer = gtk_text_view_get_buffer(Texto);
	    	        GtkTextIter end_iter;
					gtk_text_buffer_get_end_iter(buffer, &end_iter);
					gtk_text_buffer_insert(buffer, &end_iter, str, -1);
	    	        free(str);
	    	    }
	    	    //
	    }
}

int main (int argc, char *argv[])
 {
	guint ret;
	GError *error = NULL;

	gtk_init (&argc, &argv);

	builder = gtk_builder_new();
	ret = gtk_builder_add_from_file(builder, direccion, &error);
	if (ret == 0)
		{
			g_print("Error en la función gtk_builder_add_from_file:\n%s", error->message);
			return 1;
		}

	//asignación de ventanas
	Ventana = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana"));

	//objetos dentro de ventana Ventena
	BotonArchivo  	= GTK_WIDGET(gtk_builder_get_object(builder, "BotonArchivo"));
	BotonConfirmar  = GTK_WIDGET(gtk_builder_get_object (builder,"BotonConfirmar"));
	Texto			= GTK_WIDGET(gtk_builder_get_object(builder,"Texto"));

	gtk_text_view_set_editable(GTK_TEXT_VIEW(Texto), FALSE);

	//señales
	g_signal_connect (BotonArchivo, "file-set",G_CALLBACK(guardar),NULL);
	g_signal_connect (BotonConfirmar, "button-press-event",G_CALLBACK(mostrar),NULL);



	gtk_widget_show_all (Ventana);

	gtk_main();

    return 0;
 }
