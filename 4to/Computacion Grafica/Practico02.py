
from gi.repository import Gtk, GooCanvas


class MainWindow(Gtk.Window):
    def __init__(self):
        super().__init__(title="Ventana Principal")
        self.set_default_size(400, 300)

        canvas = GooCanvas.Canvas()
        cvroot= canvas.get_root_item()

        r = GooCanvas.CanvasRect(parent=cvroot, x=0, y=0, width=100, height=100, line_widht =4, stroke_color="Purple", fill_color = 'Yellow')

        self.set_child(canvas)

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
