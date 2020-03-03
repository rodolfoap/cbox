/* gcc -Wall -g -o tutorial main.c `pkg-config --cflags --libs gtk+-2.0` -export-dynamic */
#include<iostream>
#include<gtk/gtk.h>

/*void on_window_destroy(GtkObject *object, gpointer user_data){ gtk_main_quit (); }
int main(){
	std::cerr<<"Hello, World!"<<std::endl;
	GtkBuilder	*builder;
	GtkWidget	*window;
	gtk_init(&argc, &argv);
	builder=gtk_builder_new();
	gtk_builder_add_from_file(builder, "tutorial.xml", NULL);
	window=GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(G_OBJECT(builder));
	gtk_widget_show(window);
	gtk_main();
	return 0;
}
*/

static void
activate(GtkApplication *app,
    gpointer user_data) {
    GtkWidget *window;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hello GNOME");
    gtk_widget_show_all(window);
}

int
main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example",
        G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate",
        G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return (status);
}
