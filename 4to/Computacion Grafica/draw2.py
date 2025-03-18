import gi

gi.require_version("Gtk", "4.0")
gi.require_version("GooCanvas", "3.0")
from gi.repository import Gtk, GooCanvas

PIXEL_SIZE = 12
X_SIZE = 50
Y_SIZE = 50


class MainWindow(Gtk.Window):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.connect("destroy", Gtk.main_quit)
        self.set_default_size(400, 300)

        canvas = GooCanvas.Canvas()
        cvroot = canvas.get_root_item()

        for y in range(Y_SIZE):
            for x in range(X_SIZE):
                r = GooCanvas.CanvasRect(
                    parent=cvroot,
                    x=x * PIXEL_SIZE,
                    y=y * PIXEL_SIZE,
                    width=PIXEL_SIZE,
                    height=PIXEL_SIZE,
                    line_width=1,
                    stroke_color="blue",
                    fill_color="yellow",
                )

        self.add(canvas)
        self.show_all()

    def button_clicked(self, btn):
        print(self.bff)

    def run(self):
        Gtk.main()


def main(args):
    mainwdw = MainWindow()
    mainwdw.run()

    return 0


if __name__ == "__main__":
    import sys

    sys.exit(main(sys.argv))
