#include<gtkmm.h>

class MainWindow: public Gtk::Window {
	Gtk::Box *main_gtk_box;
        Gtk::Entry *entry1, *entry2;
        Gtk::Button *button1, *button2;
	Glib::RefPtr<Gtk::Builder> builder;
public:
	MainWindow(): builder{Gtk::Builder::create_from_file("app.ui")} {
		builder->get_widget<Gtk::Box>("main_gtk_box", main_gtk_box);
	        builder->get_widget("entry1", entry1);
	        builder->get_widget("entry2", entry2);
	        builder->get_widget("button1", button1);
	        builder->get_widget("button2", button2);
	        button1->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::button1_clicked));
	        button2->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::button2_clicked));
		add(*main_gtk_box);
		show_all();
	}
private:
	// Still not reversing
        void button1_clicked(){ entry2->set_text( entry1->get_text() ); }
        void button2_clicked(){ MainWindow::hide(); }
};

int main(int argc, char *argv[]) {
	auto app=Gtk::Application::create(argc, argv);
	MainWindow hw;
	return app->run(hw);
}
