#include <glib.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>
using namespace std;


void test();
void colors_for_you();

class picture
{
private:
	 string color, for_color, not_color;
public:
	picture();
	picture(string, string, string);
	picture set_n_get(string, string, string);
	string get_color();
	string get_for_color();
	string get_not_color();
};
 class color_type
{
private:
	int points;
public:
	color_type(int);
	
	void incr_points(){points++;};
	int get_points(){return points;};	
	void set_points(int p){points = p;};
	virtual string get_type_name()=0;
	
	virtual string get_advice()=0;
	virtual string get_photo1()=0;
	virtual string get_photo2()=0;
	virtual string get_colors()=0;

	virtual ~color_type(){};
};
 class winter:public color_type
 {
 private:
	string type_name;
	string advice;
	string photo1, photo2;
	string colors;
 public:
	winter(int);
	virtual string get_type_name(){return type_name;};
	virtual string get_advice(){return advice;};
	virtual string get_photo1(){return photo1;};
	virtual string get_photo2(){return photo2;};
	virtual string get_colors(){return colors;};

;
 };
 class spring:public color_type
 {
 private:
	string type_name;
	string advice;
	string photo1, photo2;
	string colors;

 public:
	spring(int);
	virtual string get_type_name(){return type_name;};
	virtual string get_advice(){return advice;};
	virtual string get_photo1(){return photo1;};
	virtual string get_photo2(){return photo2;};
	virtual string get_colors(){return colors;};

;

 };
 class summer:public color_type
 {
 private:
	string type_name;
	string advice;
	string photo1, photo2;
	string colors;

 public:
	summer(int);
	virtual string get_type_name(){return type_name;};
	virtual string get_advice(){return advice;};
	virtual string get_photo1(){return photo1;};
	virtual string get_photo2(){return photo2;};
	virtual string get_colors(){return colors;};

;

 };
 class autumn:public color_type
 {
 private:	
	string type_name;
	string advice;
	string photo1, photo2;
	string colors;

 public:
	autumn(int);
	virtual string get_type_name(){return type_name;};
	virtual string get_advice(){return advice;};
	virtual string get_photo1(){return photo1;};
	virtual string get_photo2(){return photo2;};
	virtual string get_colors(){return colors;};

;

 };
 extern color_type *c;
 extern GtkWidget *rb_w, *rb_s1, *rb_s2, *rb_a;
