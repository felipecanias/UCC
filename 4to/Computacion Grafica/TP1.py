import gi
gi.require_version('Gtk', '3.0')
gi.require_version('GooCanvas', '2.0')
from gi.repository import GLib, Gtk, GooCanvas, Gdk
from datetime import datetime
import pytz

CTR_X = 225
CTR_Y = 50

# Zonas horarias
TIMEZONES = {
    "Argentina": "America/Argentina/Buenos_Aires",
    "Nueva York": "America/New_York",
    "Londres": "Europe/London",
    "Tokio": "Asia/Tokyo",
    "Sídney": "Australia/Sydney",
    "Moscú": "Europe/Moscow",
    "Dubái": "Asia/Dubai",
    "París": "Europe/Paris",
    "Hong Kong": "Asia/Hong_Kong",
    "Singapur": "Asia/Singapore",
    "Los Ángeles": "America/Los_Angeles"
}

# Temas
THEMES = {
    "Claro": {
        "background": "White",
        "text": "Black",
        "panel_bg": "LightGray",
        "flip_bg": "DarkGray"
    },
    "Oscuro": {
        "background": "Gray",
        "text": "White",
        "panel_bg": "DarkSlateGray",
        "flip_bg": "Black"
    },
    "Pastel 1": {
        "background": "#FFEBEE",  # Rosa claro
        "text": "#B71C1C",
        "panel_bg": "#FFCDD2",
        "flip_bg": "#EF9A9A"
    },
    "Pastel 2": {
        "background": "#E3F2FD",  # Azul claro
        "text": "#0D47A1",
        "panel_bg": "#90CAF9",
        "flip_bg": "#64B5F6"
    },
    "Pastel 3": {
        "background": "#E8F5E9",  # Verde claro
        "text": "#1B5E20",
        "panel_bg": "#A5D6A7",
        "flip_bg": "#81C784"
    }
}

class MainWindow(Gtk.Window):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.flip_is_down = {
            "hour": False,
            "minute": False,
            "second": False
        }
        self.connect("destroy", lambda x: Gtk.main_quit())
        self.set_default_size(1200, 400)  # Aumentamos el tamaño para acomodar dos relojes

        # Contenedor principal
        main_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
        self.add(main_box)

        # Contenedor para controles
        control_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=10)
        main_box.pack_start(control_box, False, False, 5)

        # ComboBox para seleccionar la segunda zona horaria
        self.timezone_combo = Gtk.ComboBoxText()
        for tz in TIMEZONES.keys():
            if tz != "Argentina":  # Ya incluimos Argentina por defecto
                self.timezone_combo.append_text(tz)
        self.timezone_combo.set_active(0)  # Seleccionamos la primera opción por defecto
        self.timezone_combo.connect("changed", self.on_timezone_changed)
        control_box.pack_start(Gtk.Label(label="Selecciona Zona Horaria:"), False, False, 5)
        control_box.pack_start(self.timezone_combo, False, False, 5)

        # ComboBox para seleccionar el tema
        self.theme_combo = Gtk.ComboBoxText()
        for theme in THEMES.keys():
            self.theme_combo.append_text(theme)
        self.theme_combo.set_active(0)  # Seleccionamos el primer tema por defecto
        self.theme_combo.connect("changed", self.on_theme_changed)
        control_box.pack_start(Gtk.Label(label="Selecciona Tema:"), False, False, 5)
        control_box.pack_start(self.theme_combo, False, False, 5)

        # Contenedor para los relojes
        clocks_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=50)
        main_box.pack_start(clocks_box, True, True, 10)

        # Reloj de Argentina
        self.argentina_clock = self.create_clock_panel(clocks_box, "Argentina", TIMEZONES["Argentina"])

        # Reloj de la zona horaria seleccionada
        self.selected_timezone = TIMEZONES["Nueva York"]  # Por defecto
        self.other_clock = self.create_clock_panel(clocks_box, "Nueva York", self.selected_timezone)

        # Aplicar tema inicial
        self.apply_theme("Claro")

        # Actualizar la visualización al iniciar
        self.update_time_display()
        GLib.timeout_add(100, self.on_timer)  # Cada segundo

        self.show_all()

    def create_clock_panel(self, parent, label, timezone):
        """Crea un panel de reloj para una zona horaria específica."""
        box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
        parent.pack_start(box, True, True, 10)

        # Etiqueta de la zona horaria
        tz_label = Gtk.Label(label=label)
        box.pack_start(tz_label, False, False, 5)

        # Canvas para el reloj
        canvas = GooCanvas.Canvas()
        canvas.set_bounds(0,0,525,250)
        cvroot = canvas.get_root_item()

        # Crear paneles para horas, minutos y segundos
        hour_panel_top, hour_panel_bottom, hour_flip = self.create_flip_panel(cvroot, CTR_X - 150, CTR_Y, "00")
        minute_panel_top, minute_panel_bottom, minute_flip = self.create_flip_panel(cvroot, CTR_X, CTR_Y, "00")
        second_panel_top, second_panel_bottom, second_flip = self.create_flip_panel(cvroot, CTR_X + 150, CTR_Y, "00")

        # Almacenar referencias para actualizar
        clock = {
            "label": tz_label,
            "timezone": timezone,
            "current_time": datetime.now(pytz.timezone(timezone)),
            "hour_panel_top": hour_panel_top,
            "hour_panel_bottom": hour_panel_bottom,
            "hour_flip": hour_flip,
            "minute_panel_top": minute_panel_top,
            "minute_panel_bottom": minute_panel_bottom,
            "minute_flip": minute_flip,
            "second_panel_top": second_panel_top,
            "second_panel_bottom": second_panel_bottom,
            "second_flip": second_flip
        }

        box.pack_start(canvas, True, True, 5)

        return clock

    def create_flip_panel(self, parent, x, y, text):
        """Crea un panel de flip con mitades superior e inferior."""
        # Panel de fondo
        panel_bg = GooCanvas.CanvasRect(
            parent=parent,
            x=x, y=y,
            width=100, height=150,
            line_width=2,
            radius_x=10, radius_y=10,
            stroke_color="Black",
            fill_color=THEMES["Claro"]["panel_bg"]
        )

        # Texto inicial para la parte superior del flip
        text_top = GooCanvas.CanvasText(
            parent=parent,
            x=x + 50, y=y + 45,  # Ajuste para la parte superior
            font="Sans Bold 60",
            text=text,
            fill_color=THEMES["Claro"]["text"],
            anchor=0
        )

        # Texto para la parte inferior
        text_bottom = GooCanvas.CanvasText(
            parent=parent,
            x=x + 50, y=y + 115,  # Ajuste para la parte inferior
            font="Sans Bold 60",
            text=text,
            fill_color=THEMES["Claro"]["text"],
            anchor=0
        )

        # Flip panel para animación (parte que se mueve)
        flip_panel = GooCanvas.CanvasRect(
            parent=parent,
            x=x, y=y + 75,
            width=100, height=75,
            line_width=2,
            radius_x=10, radius_y=10,
            stroke_color="Black",
            fill_color=THEMES["Claro"]["flip_bg"]
        )

        return (text_top, text_bottom, flip_panel)

    def on_timezone_changed(self, combo):
        """Actualiza la segunda zona horaria seleccionada."""
        tz_name = combo.get_active_text()
        if tz_name:
            self.selected_timezone = TIMEZONES[tz_name]
            self.other_clock["timezone"] = self.selected_timezone
            self.other_clock["label"].set_text(tz_name)
            self.update_time_display()

    def on_theme_changed(self, combo):
        """Aplica el tema seleccionado."""
        theme_name = combo.get_active_text()
        if theme_name:
            self.apply_theme(theme_name)

    def apply_theme(self, theme_name):
        """Aplica un tema a todos los elementos del reloj."""
        theme = THEMES.get(theme_name, THEMES["Claro"])

        # Crear un proveedor de CSS
        css_provider = Gtk.CssProvider()
        css = f"""
        window {{
            background-color: {theme["background"]};
        }}
        label {{
            color: {theme["text"]};
        }}
        """
        css_provider.load_from_data(css.encode())

        # Obtener la pantalla predeterminada
        screen = Gdk.Screen.get_default()
        Gtk.StyleContext.add_provider_for_screen(
            screen,
            css_provider,
            Gtk.STYLE_PROVIDER_PRIORITY_APPLICATION
        )

        # Actualizar colores de los paneles y flip panels
        for clock in [self.argentina_clock, self.other_clock]:
            # Actualizar paneles
            for panel in ["hour_panel_top", "hour_panel_bottom",
                          "minute_panel_top", "minute_panel_bottom",
                          "second_panel_top", "second_panel_bottom"]:
                clock[panel].set_property("fill_color", theme["panel_bg"])
                clock[panel].set_property("fill_color", theme["panel_bg"])
                # Actualizar texto
                clock[panel].set_property("fill_color", theme["text"])

            # Actualizar flip panels
            for flip in ["hour_flip", "minute_flip", "second_flip"]:
                clock[flip].set_property("fill_color", theme["flip_bg"])

    def update_time_display(self):
        """Actualiza los números de los paneles solo si hay un cambio."""
        for clock in [self.argentina_clock, self.other_clock]:
            now = datetime.now(pytz.timezone(clock["timezone"]))
            hour_str = f"{now.hour:02d}"
            minute_str = f"{now.minute:02d}"
            second_str = f"{now.second:02d}"

            # Verificar si ha habido cambios en la hora, minutos o segundos
            if hour_str != clock["hour_panel_top"].props.text:
                self.animate_flip(clock, "hour", hour_str)

            if minute_str != clock["minute_panel_top"].props.text:
                self.animate_flip(clock, "minute", minute_str)

            if second_str != clock["second_panel_top"].props.text:
                self.animate_flip(clock, "second", second_str)

    def animate_flip(self, clock, unit, new_text):
        """Simula el efecto de flip cambiando el texto con animación en dos pasos."""
        panel_top = f"{unit}_panel_top"
        panel_bottom = f"{unit}_panel_bottom"
        flip_panel = f"{unit}_flip"

        # Parte inferior comienza la animación de flip (cambiando con la "pestaña")
        if self.flip_is_down[unit]:
            GLib.timeout_add(0, lambda: self.flip_up(clock, unit, panel_top, flip_panel, new_text))
        else:
            GLib.timeout_add(0, lambda: self.flip_down(clock, unit, panel_bottom, flip_panel, new_text))
        clock[panel_top].set_property("text", new_text)
        clock[panel_bottom].set_property("text", new_text)  # Cambiamos el texto inferior

    def flip_down(self, clock, unit, panel_bottom, flip_panel, new_text):
        """Simula el movimiento del flip hacia abajo y actualiza el texto inferior."""
        self.flip_is_down[unit] = True
        clock[flip_panel].set_property("y", clock[flip_panel].props.y - 75)

    def flip_up(self, clock, unit, panel_top, flip_panel, new_text):
        """Vuelve a mover el flip panel hacia arriba."""
        self.flip_is_down[unit] = False
        clock[flip_panel].set_property("y", clock[flip_panel].props.y + 75)
        clock[f"{unit}_panel_top"].set_property("text", new_text)

    def change_text(self, clock, panel_top, new_text):
        """Cambia el texto de la parte superior."""
        clock[panel_top].set_property("text", new_text)

    def on_timer(self):
        """Actualiza la hora cada segundo."""
        self.update_time_display()
        return True

    def run(self):
        Gtk.main()

def main(args):
    mainwdw = MainWindow()
    mainwdw.run()
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
