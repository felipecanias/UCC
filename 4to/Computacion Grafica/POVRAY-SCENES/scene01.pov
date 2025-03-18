// --------------------------------------------
// Escena POV-Ray simple y agradable
// --------------------------------------------

// Cámara: Ubicada ligeramente arriba y mirando hacia el centro de la escena
camera {
    location <0, 2, -3>
    look_at <0, 0, 0>
}

// Luz principal: una luz blanca, suave, arriba y a la izquierda
light_source {
    <-2, 4, -2>
    color rgb <1,1,1>
    area_light <1,0,0>, <0,0,1>, 5, 5 // Luz área para sombras suaves
    adaptive 1
    jitter
}

// Cielo con un degradado azul-clarito
sky_sphere {
    pigment {
        gradient y
        color_map {
            [0.0 color rgb <0.4,0.6,1>]   // Azul más intenso
            [1.0 color rgb <0.8,0.9,1>]   // Azul muy claro casi blanco
        }
    }
}

// Suelo con patrón ajedrezado
plane {
    y, 0
    texture {
        pigment {
            checker
            color rgb <1,1,1>      // Blanco
            color rgb <0.2,0.2,0.2> // Gris oscuro
            scale 0.5
        }
        finish {
            reflection 0.1  // Un poco de reflejo para que la esfera se refleje
            diffuse 0.8
            specular 0.3
            roughness 0.005
        }
    }
}

// Esfera reflectante y especular
sphere {
    <0,0.5,0>, 0.5
    texture {
        pigment { color rgb <1,1,1> }
        finish {
            reflection 0.5   // Media reflexión, para ver el piso y el cielo reflejados
            specular 0.8     // Brillo fuerte
            roughness 0.001
        }
    }
}

