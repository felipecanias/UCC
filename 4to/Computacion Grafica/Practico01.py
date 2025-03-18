import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk


class MainWindow(Gtk.Window):
    def __init__(self):
        super().__init__(title="Ventana Principal")
        self.set_default_size(400, 300)

        # l = Gtk.Label(label="Hola Grupo")
        button = Gtk.Button(label="Aquí estamos")
        button.connect("clicked", self.on_button_clicked)

        colb = Gtk.ColorButton()
        bff = Gtk.TextBuffer()
        viewer = Gtk.TextView(buffer=bff)
        scroller = Gtk.ScrolledWindow()
        scroller.set_child(viewer)

        grid = Gtk.Grid()
        grid.attach(scroller, 0, 0, 2, 1)
        grid.attach(colb, 0, 1, 1, 1)
        grid.attach(button, 1, 1, 1, 1)

        self.set_child(grid)

    def on_button_clicked(self, button):
        print("Casi nos vamos")

    def run(self):
        app = Gtk.Application(application_id="org.example.myapp")
        app.connect("activate", self.on_activate)
        app.run(None)

    def on_activate(self, app):
        app.add_window(self)
        self.show()


def main():
    window = MainWindow()
    window.run()


if __name__ == "__main__":
    main()
