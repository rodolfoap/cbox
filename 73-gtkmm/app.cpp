#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

class HelloWorldWindow: public Gtk::Window {
public:
	HelloWorldWindow(): hello_world("Hello World") {
		set_title("Hello World");
		add(hello_world);
		hello_world.signal_clicked().connect([] () { std::cout << "Hello world" << std::endl; });
		show_all_children();
	}

protected:
	Gtk::Button hello_world;
};

int main(int argc, char *argv[]) {
	Gtk::Main kit(argc, argv);
	HelloWorldWindow example;
	Gtk::Main::run(example);
	return 0;
}

