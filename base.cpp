#include <gtk/gtk.h>

static gboolean delete_event(GtkWidget *widget,
                             GdkEvent *event,
                             gpointer data) {
  return TRUE;
}

static void destroy(GtkWidget *widget, gpointer data) {
  gtk_main_quit();
}

int main(int argc, char *argv[]) {
  GtkWidget *window;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);
  g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
  gtk_widget_show(window);

  gtk_main();

  return 0;
}
