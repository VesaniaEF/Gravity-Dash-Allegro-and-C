#ifndef ALEGRO_H_INCLUDED
#define ALEGRO_H_INCLUDED
#define ALTURA 12
#define PISO   31

BITMAP *buffer;
BITMAP *Wall;
BITMAP *Cubem;
BITMAP *Cube;
BITMAP *heart;
BITMAP *losee;
MIDI *Fondo;
MIDI *Roblox;
FILE *Punt;

int movement=0;


void Alegro()
{
    allegro_init();
    install_keyboard();

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1200,440,0,0 );
     if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
        {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
        }
        set_volume(200, 200);

    Fondo = load_midi("Cycles.mid");
    Roblox = load_midi("Roblox.mid");

    buffer = create_bitmap(1200,440);
    Wall= load_bitmap("Wall.bmp", NULL);
    Cubem= load_bitmap("Cube.bmp", NULL);
    Cube= create_bitmap(40,40);
    heart = load_bitmap("Heart.bmp", NULL);
    losee = load_bitmap("MenuD.bmp", NULL);

    play_midi(Fondo,1);
    }
    void Moves ()
    {
                if(key[KEY_UP]) movement=4;
            else if(key[KEY_DOWN]) movement=2;
    }

#endif // ALEGRO_H_INCLUDED
