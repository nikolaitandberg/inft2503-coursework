#include "task2.h"
#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::Box box;
  Gtk::Entry entryFirst;
  Gtk::Entry entryLast;
  Gtk::Button button;
  Gtk::Label label;

  Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
    set_title("Øving 4");

    entryFirst.set_placeholder_text("Fornavn");
    entryLast.set_placeholder_text("Etternavn");
    button.set_label("Slå sammen");
    button.set_sensitive(false);

    box.set_spacing(5);

    box.pack_start(entryFirst);
    box.pack_start(entryLast);
    box.pack_start(button);
    box.pack_start(label);

    add(box);
    show_all();

    auto update_button_state = [this]() {
      bool enable = !entryFirst.get_text().empty() && !entryLast.get_text().empty();
      button.set_sensitive(enable);
    };

    entryFirst.signal_changed().connect(update_button_state);
    entryLast.signal_changed().connect(update_button_state);

    button.signal_clicked().connect([this]() {
      label.set_text(entryFirst.get_text() + " " + entryLast.get_text());
    });
  }
};

int task2() {
  auto app = Gtk::Application::create("org.gtkmm.assignment");
  Window window;
  return app->run(window);
}
