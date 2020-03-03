#include <iostream>
#include <gtkmm.h>
#include <gtkmm.h>
using namespace std;
using namespace Gtk;

class FrmMain : public Gtk::Window{
protected:
        Glib::RefPtr<Gtk::Builder> builder;
        Gtk::Button *btnOk;
        Gtk::Button *btnCancel;
        Gtk::Label *lblNotice;
public:
	FrmMain(BaseObjectType* bot, const Glib::RefPtr<Gtk::Builder>& refg): Gtk::Window(bot), builder(refg){
	        builder->get_widget("btnOk", btnOk);
	        builder->get_widget("btnCancel", btnCancel);
	        builder->get_widget("lblNotice",lblNotice);
	        btnOk->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_ok_button_clicked));
	        btnCancel->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_cancel_button_clicked));
	}
protected:
        void on_ok_button_clicked(){ lblNotice->set_text("OK clicked"); }
        void on_cancel_button_clicked(){ lblNotice->set_text("Cancel clicked"); }
};

int main(int argc, char **argv) {
        cout << "Started" << endl;
        Main kit(argc,argv);
        Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("gui.glade");
        FrmMain *frm = 0;
        builder->get_widget_derived("frmMain", frm);
        kit.run(*frm);
        cout << "End" << endl;
        return 0;
}
