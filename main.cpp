#include "headers.h"


gint close_application( GtkWidget *widget,
                        GdkEvent  *event,
                        gpointer   data )
{
  gtk_main_quit ();
  return FALSE;
}
void progr_info()
{
	GtkWidget* window=NULL, *box, *label;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), g_locale_to_utf8("О программе",-1,NULL,NULL,NULL));


	label = gtk_label_new (g_locale_to_utf8("Если вы задавались вопросом какие цвета идут именно вам,\n то эта программа для вас. Для начала нужно узнать\n к какому цветотипу вы относитесь.\n(Цветотип - это совокупность цвета кожи, глаз,волос,\n классифицированная особым способом. \nСуществует четыре цветотипа - осень, весна, зима, лето."
		,-1,NULL,NULL,NULL));
	box =  gtk_vbox_new (FALSE,7);
	gtk_box_pack_start (GTK_BOX (box), label, TRUE, FALSE, 7);
	gtk_container_add (GTK_CONTAINER (window), box);
	
	gtk_widget_show (label);
	gtk_widget_show (box);
	gtk_widget_show (window);
}
//GtkWidget *rb_w, *rb_s1, *rb_s2, *rb_a;
void create_interface(GtkWidget *window)
{
	GtkWidget *vbox, *button;
	vbox = gtk_vbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (window), vbox);
	/* Первый ряд */
	button = gtk_button_new_with_label (g_locale_to_utf8("О программе",-1,NULL,NULL,NULL));
	gtk_box_pack_start (GTK_BOX(vbox), button, TRUE, TRUE, 7);
	g_signal_connect (G_OBJECT (button), "clicked",
                     G_CALLBACK (progr_info), NULL);
	gtk_widget_show (button);
	/* Второй ряд */
	button = gtk_button_new_with_label (g_locale_to_utf8("Узнать цветотип",-1,NULL,NULL,NULL));
	gtk_box_pack_start (GTK_BOX(vbox), button, TRUE, TRUE, 7);
	g_signal_connect (G_OBJECT (button), "clicked",
                     G_CALLBACK (test), NULL);
	gtk_widget_show (button);
	/* Третий ряд - Выбор своего цветотипа*/
	GtkWidget *hbox, *label;
	

	label = gtk_label_new (g_locale_to_utf8("Выберите свой цветотип:",
												-1,NULL,NULL,NULL));
	
	gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 7);
	gtk_widget_show(label);
	
	hbox = gtk_hbox_new(FALSE, 0);
	rb_w = gtk_radio_button_new_with_label (NULL, g_locale_to_utf8("Зима", -1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(hbox), rb_w, FALSE, FALSE, 0);
	gtk_widget_show (rb_w);
	
	rb_s1 = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_w), 
                 g_locale_to_utf8("Весна",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(hbox), rb_s1
		, FALSE, FALSE, 0);
	gtk_widget_show (rb_s1);

	rb_s2 = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_s1), 
                 g_locale_to_utf8("Лето",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(hbox), rb_s2, FALSE, FALSE, 0);
	gtk_widget_show (rb_s2);
	

	rb_a = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_s2), 
                 g_locale_to_utf8("Осень",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(hbox), rb_a, FALSE, FALSE, 0);
	gtk_widget_show (rb_a);

	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
	gtk_widget_show (hbox);
	/*Выбор цветотипа*/

	button = gtk_button_new_with_label (g_locale_to_utf8("Узнать подходящие вам цвета",-1,NULL,NULL,NULL));
	gtk_box_pack_start (GTK_BOX(vbox), button, FALSE, FALSE, 7);
	g_signal_connect (G_OBJECT (button), "clicked",
                     G_CALLBACK (colors_for_you), NULL);
	gtk_widget_show (button);
	/* Четвертый ряд */
	/* Пятый ряд */
	/* Шестой ряд */
	/* Седьмой ряд */


    gtk_widget_show (vbox);
}
int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale (LC_CTYPE,"rus");
	GtkWidget *win = NULL;

	gtk_init (&argc, &argv);

	win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (win), g_locale_to_utf8("Цвета для Вас",-1,NULL,NULL,NULL));

	create_interface(win);
	//colors_for_you();
	/* Определяем обработчик сигналов для delete_event, чтобы выходить из GTK */
    g_signal_connect (G_OBJECT (win), "delete_event",
                     G_CALLBACK (close_application), NULL);
	gtk_container_set_border_width (GTK_CONTAINER (win), 10);

	gtk_widget_show (win);
	gtk_main ();

	return 0;
}
