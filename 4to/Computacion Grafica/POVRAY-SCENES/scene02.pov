// -----------------------------------------
// Escena POV-Ray: Bandera de Argentina Detallada
// -----------------------------------------
//
// Ejecutar: povray +Iscene12.pov +W1200 +H800 +A +AM2
//
// Este ejemplo usa algunas características más elaboradas:
// - Bandera con proporciones oficiales (3:2).
// - Sol de Mayo con múltiples rayos mediante un #for loop.
// - Iluminación más cuidada.
// -----------------------------------------


// -----------------------------------------
// Configuración global
// -----------------------------------------
#version 3.7; // Asegurar versión

global_settings {
    assumed_gamma 1.0
    max_trace_level 10
}

// -----------------------------------------
// Definición de colores aproximados
// Celeste oficial aproximado: #6BC3FF (0.4196,0.7647,1.0)
#declare Celeste = color rgb <0.4196,0.7647,1.0>;
#declare Blanco  = color rgb <1.0,1.0,1.0>;
#declare Dorado  = color rgb <1.0,0.85,0.0>; // Oro aproximado

// Parámetros de la bandera
#declare Flag_Width  = 3.0;
#declare Flag_Height = 2.0;

// -----------------------------------------
// Cámara y entorno
// -----------------------------------------
camera {
    location <0,0,-6>
    look_at <0,0,0>
    right x*image_width/image_height
    angle 30
}

// Luces y ambiente
light_source {
    <0,10,-10> rgb <1,1,1>*0.8
    fade_distance 20
    fade_power 2
}

light_source {
    <5, -5, -5> rgb <1,1,1>*0.3
    fade_distance 20
    fade_power 2
}

// Luz tenue de relleno
light_source {
    <-5, 5, -2> rgb <1,1,1>*0.2
    fade_distance 20
    fade_power 2
}

// Fondo suave
background {
    color rgb <1,1,1>
}

// Un plano para el "piso" de la escena
plane {
    y, -1
    texture {
        pigment { color rgb <0.9,0.9,0.9> }
        finish { diffuse 0.7 ambient 0.2 reflection 0.05 }
    }
}


// -----------------------------------------
// Creación de la bandera
// La bandera de Argentina: 3 franjas horizontales (celeste-blanco-celeste)
#declare Bandera_Pigment = pigment {
    gradient y
    color_map {
        [0.0    Celeste]
        [1/3.0  Celeste]
        [1/3.0  Blanco]
        [2/3.0  Blanco]
        [2/3.0  Celeste]
        [1.0    Celeste]
    }
    scale Flag_Height
    translate -Flag_Height/2*y
}

#declare Bandera = object {
    box {
        <-Flag_Width/2, -Flag_Height/2, 0>,
        < Flag_Width/2,  Flag_Height/2, 0.01>
    }
    texture {
        pigment { Bandera_Pigment }
        finish {
            diffuse 0.9
            ambient 0.1
            specular 0.1
            roughness 0.01
        }
    }
}

// -----------------------------------------
// Sol de Mayo Detallado (Simplificado)
#declare Sol_Radio = 0.3;
#declare Sol = disc {
    <0,0,10>, <0,0,1>, Sol_Radio
    texture {
        pigment { color Dorado }
        finish {
            diffuse 0.8
            ambient 0.2
            specular 0.3
            roughness 0.02
        }
    }
}

// Rayos del sol
#declare Numero_Rayos = 32;
#declare Angulo_Paso = 360/Numero_Rayos;

#declare Rayo_Largo = 0.2; // altura del rayo largo
#declare Rayo_Ancho = 0.05;
#declare Rayo_Corto = 0.13; // altura del rayo corto

#macro Rayo(Tipo)
    // Tipo 0: Largo
    // Tipo 1: Corto
    #if (Tipo=0)
        cone {
            <0,0,0.021>, Rayo_Ancho*0.5,
            <0,0,Rayo_Largo+0.02>, 0
            texture {
                pigment { color Dorado }
                finish {
                    diffuse 0.8
                    ambient 0.2
                    specular 0.3
                    roughness 0.02
                }
            }
        }
    #else
        cone {
            <0,0,0.021>, Rayo_Ancho*0.3,
            <0,0,Rayo_Corto+0.02>, 0
            texture {
                pigment { color Dorado }
                finish {
                    diffuse 0.8
                    ambient 0.2
                    specular 0.3
                    roughness 0.02
                }
            }
        }
    #end
#end

#declare SolConRayos = union {
    object { Sol }
    #for(i,0, Numero_Rayos-1)
        #declare Angulo = i*Angulo_Paso;
        // Alternar tipo de rayo usando mod en vez de %
        #declare TipoRayo = mod(i,2);
        object {
            Rayo(TipoRayo)
            rotate <90,0,0>  // Rotar para apuntar radialmente
            rotate <0,0,Angulo>
            translate <0,Sol_Radio,0>
        }
    #end
}

union {
    object { Bandera }
    object { SolConRayos }
    translate <0,0,0>
}

