#include "headers.h"

 color_type *c=NULL;

 color_type::color_type(int p)
 {
	points = p;
 }

 
 winter::winter(int p)
	 :color_type(p)
 {
	colors = "Красный, синий, фиолетовый.";
	type_name = "Зима";
	advice = "Это холодный тип внешности. Волосы \nобычно темные, черные, с холодным отливом.\n Но могут быть и пепельно-белыми. Кожа обычно\n светло-фарфоровая, белая, но иногда могут встречаться\n смуглые девушки этого типа внешности. В макияже и одежде\n можно использовать яркие цвета, но холодных оттенков. ";
	photo1 = "winter_man.png";
	photo2 = "winter_woman.png";
 }
  
 spring::spring(int p)
	 :color_type( p)
 {
	colors = "Розовый, сиреневый, желтый, зеленый.";
	type_name = "Весна";
	advice = "Это теплый тип внешности. Ваши волосы светлые, \nрусые или каштановые, с теплым золотистым отливом.\n Ваша кожа светлая, бежевая, персиково-розовая.\n Веснушки с золотистым оттенком. В макияже \nи одежде лучше придерживаться теплых оттенков. ";
	photo1 = "spring_man.png";
	photo2 = "spring_woman.png";
 }
  
 summer::summer(int p)
	 :color_type(p)
 {
	colors = "Фиолетовый, желтый, розовый";
	type_name = "Лето";
	advice = "Это холодный тип внешности. Это самый\nраспространенный тип внешности среди славян.\n Ваши волосы либо светло-пепельные, либо русые, \nно с холодным отливом. Ваша кожа прозрачная, светлая, с \nголубовато-сероватым отливом. Веснушки если есть имеют \nсеровато-коричневый оттенок. В макияже и одежде лучше \nпридерживаться холодных нейтральных оттенков. ";
	photo1 = "summer_man.png";
	photo2 = "summer_woman.png";
 }
  
 autumn::autumn(int p)
	 :color_type(p)
 {
colors = "Зеленый, оранжевый, желтый";
	type_name = "Осень";
	advice = "Это теплый тип внешности. Волосы либо рыжие,\n либо каштановые, но с золотистым отливом.\n Ваша кожа либо светлая, цвета слоновой кости, либо\n с небольшим золотистым оттенком. Веснушки имеют золотистый,\n рыжеватый оттенок. В макияже и одежде лучше \nпридерживаться теплых тонов. ";
	photo1 = "autumn_man.png";
	photo2 = "autumn_woman.png";
 }
GtkWidget *rb_wi[9], *rb_sp[9], *rb_su[9], *rb_au[9];

 color_type* get_test_result()
 {
	 
	int wi=0, sp=0, su=0, au=0;// Количество отмеченных вариантов за цветотипы зима, весна...
	
	// Подсчет количества ответов за определенный цветотип
	for(int i=0; i<9; i++)
	{
		if( gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(rb_wi[i])) )
			wi++;
		if( gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(rb_sp[i])) )
			sp++;
		if( gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(rb_su[i])) )
			su++;
		if( gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(rb_au[i])) )
			au++;
	}
	cout<< wi<< " "<<sp<< " "<<su<< " "<<au;
	//Сравнение количества ответов за 4 цветотипа, выбор ц-па с большим количеством ответов 
	char res;
	if( wi>=sp && wi>su && wi>=au )
		res = 'z';
	else
		if( sp>wi && sp>su && sp>au)
			res = 'v';
		else
			if( su>=wi && su>=sp && su>=au )
				res = 'l';
			else
				res = 'o';
	//Выделение памяти для нужного цветотипа
	color_type *c;
	switch(res)
	{
	case 'z':
		c = new winter(wi);
		break;
	case 'v':
		c = new spring(sp);
		break;
	case 'l':
		c = new summer(su);
		break;
	case 'o':
		c = new autumn(au);
		break;
	}
	return c;
 }

 	
	
void show_result()
{
	c = get_test_result();

	GtkWidget* window=NULL, *table, *label, *image;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	string result;
	result = " Скорее всего Ваш цветотип: " + c->get_type_name() + "\n\n" + c->get_advice();
	label = gtk_label_new (g_locale_to_utf8( result.c_str(),-1,NULL,NULL,NULL));

	table = gtk_table_new( 2, 2, FALSE);
	gtk_container_add (GTK_CONTAINER (window), table);

	gtk_table_attach( GTK_TABLE(table), label, 0, 2, 0, 1, GTK_EXPAND,GTK_EXPAND, 5, 5 );
	image = gtk_image_new_from_file(c->get_photo1().c_str());
	gtk_table_attach( GTK_TABLE(table), image, 0, 1, 1, 2, GTK_EXPAND,GTK_EXPAND, 5, 5 );
	gtk_widget_show(image);
	image =  gtk_image_new_from_file(c->get_photo2().c_str());
	gtk_table_attach( GTK_TABLE(table), image, 1, 2, 1, 2, GTK_EXPAND,GTK_EXPAND, 5, 5 );
	gtk_widget_show(image);
	
	gtk_widget_show (label);
	gtk_widget_show (table);
	gtk_widget_show (window);

}
void test()
{
	

	GtkWidget *window, *scrolled_window, *vbox;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), g_locale_to_utf8("Тест",-1,NULL,NULL,NULL));
	
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
    gtk_widget_set_size_request (window, 500, 500);
    
    /* создаём новое окно прокручивания. */
    scrolled_window = gtk_scrolled_window_new (NULL, NULL);
    
    gtk_container_set_border_width (GTK_CONTAINER (scrolled_window), 10);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),
									GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);

	vbox = gtk_vbox_new (FALSE, 0);
	gtk_box_pack_start (GTK_BOX(vbox), scrolled_window, TRUE, TRUE, 0);
	gtk_container_add (GTK_CONTAINER (window), vbox);

/*-------------Radio buttons, text of test--------------*/
	GtkWidget *label, *test_box;
	test_box = gtk_vbox_new (FALSE, 0);
	label = gtk_label_new (g_locale_to_utf8("1. Какое из предложенных утверждений\n вам подходит больше всего?",
												-1,NULL,NULL,NULL));

	gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (scrolled_window), test_box);
	gtk_box_pack_start(GTK_BOX(test_box), label, FALSE, FALSE, 10);
	gtk_widget_show(label);
	
	rb_su[0] = gtk_radio_button_new_with_label (NULL, g_locale_to_utf8(" Кожа имеет голубоватый оттенок\n на сгибе локтя, на внутренней стороне\n запястья и предплечья",
		-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(test_box), rb_su[0], FALSE, FALSE, 0);
	gtk_widget_show (rb_su[0]);
	
	rb_wi[0] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_su[0]), 
                 g_locale_to_utf8("Белки глаз чисто-белого цвета",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_wi[0], FALSE, FALSE, 0);
	gtk_widget_show (rb_wi[0]);

	rb_sp[0] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_wi[0]), 
                 g_locale_to_utf8("Суставы пальцев часто краснеют",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_sp[0], FALSE, FALSE, 0);
	gtk_widget_show (rb_sp[0]);


	rb_au[0] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_sp[0]), 
                 g_locale_to_utf8("В глазах золотистые искорки",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_au[0], FALSE, FALSE, 0);
	gtk_widget_show (rb_au[0]);

	label = gtk_label_new (g_locale_to_utf8("2. Есть ли у вас веснушки?",
												-1,NULL,NULL,NULL));
	
	gtk_box_pack_start(GTK_BOX(test_box), label, FALSE, FALSE, 10);
	gtk_widget_show(label);
	
	rb_au[1] = gtk_radio_button_new_with_label (NULL, 
												g_locale_to_utf8(" есть много золотистых",
		-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(test_box), rb_au[1], FALSE, FALSE, 0);
	gtk_widget_show (rb_au[1]);
	
	rb_wi[1] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_au[1]), 
                 g_locale_to_utf8("нет совсем",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_wi[1], FALSE, FALSE, 0);
	gtk_widget_show (rb_wi[1]);

	rb_su[1] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_wi[1]), 
                 g_locale_to_utf8("есть немного светло-пепельные, либо нет",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_su[1], FALSE, FALSE, 0);
	gtk_widget_show (rb_su[1]);


	rb_sp[1] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_su[1]), 
                 g_locale_to_utf8("да есть тепло золотистые",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_sp[1], FALSE, FALSE, 0);
	gtk_widget_show (rb_sp[1]);

	label = gtk_label_new (g_locale_to_utf8("3. Какого цвета у вас брови и ресницы?",
												-1,NULL,NULL,NULL));
	
	gtk_box_pack_start(GTK_BOX(test_box), label, FALSE, FALSE, 10);
	gtk_widget_show(label);
	
	rb_wi[2] = gtk_radio_button_new_with_label (NULL, 
												g_locale_to_utf8(" черные, темные",
		-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(test_box), rb_wi[2], FALSE, FALSE, 0);
	gtk_widget_show (rb_wi[2]);
	
	rb_su[2] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_wi[2]), 
                 g_locale_to_utf8("не слишком светлые. коричневые, но не черные",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_su[2], FALSE, FALSE, 0);
	gtk_widget_show (rb_su[2]);

	rb_au[2] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_su[2]), 
                 g_locale_to_utf8("темно-коричневые, рыжие, с золотистым отливом",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_au[2], FALSE, FALSE, 0);
	gtk_widget_show (rb_au[2]);


	rb_sp[2] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_au[2]), 
                 g_locale_to_utf8("светлые, светло-коричневые",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_sp[2], FALSE, FALSE, 0);
	gtk_widget_show (rb_sp[2]);


	label = gtk_label_new (g_locale_to_utf8("4. Какая у вас кожа?",
												-1,NULL,NULL,NULL));
	
	gtk_box_pack_start(GTK_BOX(test_box), label, FALSE, FALSE, 10);
	gtk_widget_show(label);
	
	rb_sp[3] = gtk_radio_button_new_with_label (NULL, 
												g_locale_to_utf8("светло-бежевая, цвета слоновой кости. \nТеплый оттенок кожи",
		-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(test_box), rb_sp[3], FALSE, FALSE, 0);
	gtk_widget_show (rb_sp[3]);
	
	rb_au[3] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_sp[3]), 
                 g_locale_to_utf8("цвета слоновой кости, персиковая, \nбежево-желтоватая, светло-золотистая",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_au[3], FALSE, FALSE, 0);
	gtk_widget_show (rb_au[3]);

	rb_su[3] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_au[3]), 
                 g_locale_to_utf8("прозрачная, светло-розовая, \nс голубоватым холодным отливо",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_su[3], FALSE, FALSE, 0);
	gtk_widget_show (rb_su[3]);


	rb_wi[3] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_su[3]), 
                 g_locale_to_utf8("либо светлая фарфорово-белая, либо смуглая",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_wi[3], FALSE, FALSE, 0);
	gtk_widget_show (rb_wi[3]);

	label = gtk_label_new (g_locale_to_utf8("5. Как вы загораете?",
												-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(test_box), label, FALSE, FALSE, 10);
	gtk_widget_show(label);
	
	rb_su[4] = gtk_radio_button_new_with_label (NULL, g_locale_to_utf8("проблем с загаром нет, цвет загара оливково-пепельный.",
		-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(test_box), rb_su[4], FALSE, FALSE, 0);
	gtk_widget_show (rb_su[4]);
	
	rb_wi[4] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_su[4]), 
                 g_locale_to_utf8("загораю быстро, цвет загара - светлый или оливковый",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_wi[4], FALSE, FALSE, 0);
	gtk_widget_show (rb_wi[4]);

	rb_sp[4] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_wi[4]), 
                 g_locale_to_utf8("очень быстро загораю, цвет загара золотистый, морковный.",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_sp[4], FALSE, FALSE, 0);
	gtk_widget_show (rb_sp[4]);


	rb_au[4] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_sp[4]), 
                 g_locale_to_utf8("легко обгораю, оттенок загара светлый или красный",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_au[4], FALSE, FALSE, 0);
	gtk_widget_show (rb_au[4]);

label = gtk_label_new (g_locale_to_utf8("6. Какой у вас цвет волос? \n(учитывается естественный цвет волос)",
												-1,NULL,NULL,NULL));
	
	gtk_box_pack_start(GTK_BOX(test_box), label, FALSE, FALSE, 10);
	gtk_widget_show(label);
	
	rb_wi[5] = gtk_radio_button_new_with_label (NULL, 
												g_locale_to_utf8("черные, темные волосы иногда с серебристым \nили синим отливом",
		-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(test_box), rb_wi[5], FALSE, FALSE, 0);
	gtk_widget_show (rb_wi[5]);
	
	rb_au[5] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_wi[5]), 
                 g_locale_to_utf8("рыжие, золотистые, с медным отливом, \nтемно-русые. Теплых оттенков",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_au[5], FALSE, FALSE, 0);
	gtk_widget_show (rb_au[5]);

	rb_sp[5] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_au[5]), 
                 g_locale_to_utf8("светло-русые, золотистые, рыжие, \nкаштановые. Теплые оттенки",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_sp[5], FALSE, FALSE, 0);
	gtk_widget_show (rb_sp[5]);


	rb_su[5] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_sp[5]), 
                 g_locale_to_utf8("пепельные, светлые волосы, светло-русые, \nтемно-русые. Холодные тона",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_su[5], FALSE, FALSE, 0);
	gtk_widget_show (rb_su[5]);

	label = gtk_label_new (g_locale_to_utf8("7. Какой у вас цвет глаз?",
												-1,NULL,NULL,NULL));
	
	gtk_box_pack_start(GTK_BOX(test_box), label, FALSE, FALSE, 10);
	gtk_widget_show(label);
	
	rb_au[6] = gtk_radio_button_new_with_label (NULL, 
												g_locale_to_utf8(" карие, с небольшой желтизной",
		-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(test_box), rb_au[6], FALSE, FALSE, 0);
	gtk_widget_show (rb_au[6]);
	
	rb_wi[6] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_au[6]), 
                 g_locale_to_utf8("черные, темно-карие, темно-зеленые, \nхолодные, темно-синие",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_wi[6], FALSE, FALSE, 0);
	gtk_widget_show (rb_wi[6]);

	rb_su[6] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_wi[6]), 
                 g_locale_to_utf8("неяркие, серые, желтоватые",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_su[6], FALSE, FALSE, 0);
	gtk_widget_show (rb_su[6]);


	rb_sp[6] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_su[6]), 
                 g_locale_to_utf8("светло-зеленые, янтарные, светло-оливковые, голубые",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_sp[6], FALSE, FALSE, 0);
	gtk_widget_show (rb_sp[6]);

	label = gtk_label_new (g_locale_to_utf8("8. Какой у вас цвет губ?",
												-1,NULL,NULL,NULL));
	
	gtk_box_pack_start(GTK_BOX(test_box), label, FALSE, FALSE, 10);
	gtk_widget_show(label);
	
	rb_sp[7] = gtk_radio_button_new_with_label (NULL, 
												g_locale_to_utf8("  ярко-розовый",
		-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(test_box), rb_sp[7], FALSE, FALSE, 0);
	gtk_widget_show (rb_sp[7]);
	
	rb_wi[7] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_sp[7]), 
                 g_locale_to_utf8("холодный розовый, с оливковым оттенком",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_wi[7], FALSE, FALSE, 0);
	gtk_widget_show (rb_wi[7]);

	rb_au[7] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_wi[7]), 
                 g_locale_to_utf8("от лососевого до ярко-красного",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_au[7], FALSE, FALSE, 0);
	gtk_widget_show (rb_au[7]);


	rb_su[7] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_au[7]), 
                 g_locale_to_utf8("бледно-розовый",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_su[7], FALSE, FALSE, 0);
	gtk_widget_show (rb_su[7]);

	label = gtk_label_new (g_locale_to_utf8("9. Оттенок вашего румянца",
												-1,NULL,NULL,NULL));
	
	gtk_box_pack_start(GTK_BOX(test_box), label, FALSE, FALSE, 10);
	gtk_widget_show(label);
	
	rb_au[8] = gtk_radio_button_new_with_label (NULL, 
												g_locale_to_utf8("ярко-красный или лососевый",
		-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(test_box), rb_au[8], FALSE, FALSE, 0);
	gtk_widget_show (rb_au[8]);
	
	rb_sp[8] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_au[8]), 
                 g_locale_to_utf8("розовато-персиковый",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_sp[8], FALSE, FALSE, 0);
	gtk_widget_show (rb_sp[8]);

	rb_su[8] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_sp[8]), 
                 g_locale_to_utf8("холодный розовый",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_su[8], FALSE, FALSE, 0);
	gtk_widget_show (rb_su[8]);


	rb_wi[8] = gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON (rb_su[8]), 
                 g_locale_to_utf8("холодный с оливковым оттенком, \nлибо нет вообще",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), rb_wi[8], FALSE, FALSE, 0);
	gtk_widget_show (rb_wi[8]);
/*------------------------------------------------------*/

	GtkWidget *fin;
	fin = gtk_button_new_with_label( g_locale_to_utf8("Показать результат",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(test_box), fin, FALSE, FALSE, 0);
	g_signal_connect (G_OBJECT (fin), "clicked",
                     G_CALLBACK (show_result), NULL);
	gtk_widget_show(fin);

	
	gtk_widget_show(test_box);
	gtk_widget_show (scrolled_window);
	gtk_widget_show (vbox);
	gtk_widget_show (window);

}
