#include <allegro.h>
#include <time.h>
#include <cstdio>
#define ALTURA 12
#define PISO   31
#pragma comment(lib, "alleg.lib")
#include "Alegro.h"
#include "vidas.h"
#include "exit.h"

int Posx=40*2, Posy=40*8;


char mapa[ALTURA][PISO] =
{
    "                              ",
    "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
    "              R     R R   R R ",
    "                              ",
    "                              ",
    "                              ",
    "                              ",
    "                              ",
    "                              ",
    "              S S   S S     S ",
    "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
};
void di_mapa()
{
    int r, c;
    for (r = 0; r< ALTURA; r++)
    {
        for (c = 0; c< PISO; c++)
        {
            if(mapa[r][c] == 'Y')
            {
                draw_sprite(buffer, Wall, c*40, r*40);
            }
        }
    }
}

void screenl()
{
    blit(buffer, screen, 0,0,0,0,1200,440);
}

void di_cubo()
{
    blit(Cubem,Cube,movement*40,4,0,0,40,40);
    draw_sprite(buffer,Cube,Posx,Posy);
}
bool LoseG ()
{
    if (vida<=0)
    {
        return true;
    }
    else return false;
}
class R
{
    BITMAP *SpikeR;
    BITMAP *Pr;

    int DeR;
    int Rx, Ry;
    public:
    R(int x, int y);
    void di_R () const;
    void movimientoR ();
    void DeadR ();
};
    R::R(int x, int y)
    {
        Rx = x;
        Ry = y;
        DeR = 1;
        Pr = create_bitmap(40, 40);
        SpikeR= load_bitmap("SpiekR.bmp", NULL);
    }
    void R::di_R() const
    {
        blit(SpikeR, Pr,0,0,0,0,40,40);
        draw_sprite(buffer, SpikeR, Rx, Ry);
    }
    void R::DeadR()
    {

                if(Posx == Rx && Posy == Ry)
        {

            play_midi(Roblox, 0);
            clear(Cube);
            clear(buffer);
            over_lifes();
            LoseG()==true;
            di_mapa();
        }
    }
    void R::movimientoR()
    {
            di_R();
        if (DeR == 1)
        {
            Rx -=40;
        }
        if (Rx <=-40) Rx = 1160;
    }

class S
{
BITMAP *Spike;
BITMAP *Ps;

int DeS;
int Sx, Sy;
public:
    S(int x, int y);
    void di_S () const;
    void MovimientoS ();
    void DeadS ();
};
    S::S(int x, int y)
    {
        Sx = x;
        Sy = y;
        DeS = 1;
        Ps= create_bitmap(40,40);
        Spike= load_bitmap("Spiek.bmp", NULL);
    }

    void S::di_S() const
    {
        blit(Spike, Ps,0,0,0,0,40,40);
        draw_sprite(buffer, Spike, Sx, Sy);
    }
    void S::DeadS()
    {
        if(Posx == Sx && Posy == Sy)
        {
            play_midi(Roblox, 0);
            clear(Cube);
            clear(buffer);
            over_lifes();
            LoseG()==true;
            di_mapa();
        }
    }
    void S::MovimientoS()
    {
        di_S();
        if (DeS == 1)
        {
            Sx -=40;
        }
        if (Sx <=-40) Sx = 1160;
            score=score+2;
    }
class Spiek
{
    BITMAP *SpikeA;
    BITMAP *SpiekBm;

    int Smove;
    int SPosx, SPosy;
public:
    Spiek(int x, int y);
    void di_Spike() const;
    void MovSpike();
    void PicoM();
};
Spiek::Spiek(int x, int y)
{
    SPosx = x;
    SPosy = y;
    Smove=1;
    SpikeA= load_bitmap("SpiekA.bmp", NULL);
    SpiekBm= create_bitmap(40,40);
}
void Spiek::di_Spike() const
{
    blit(SpikeA, SpiekBm,0,0,0,0,40,40);
    draw_sprite(buffer, SpikeA, SPosx, SPosy);
}
void Spiek::PicoM()
{
        if(Posx == SPosx && Posy == SPosy)
    {
        play_midi(Roblox,0);
        clear(Cube);
        clear(buffer);
        LoseG () == true;
        over_lifes();
        di_mapa();
    }
}

void Spiek::MovSpike()
{
        di_Spike();
    if(Smove == 1)
    {
        SPosx -=40;
    }
    if (SPosx <=-40)
    {
        SPosx = 1160;
        srand(time(NULL));
        SPosy = ((rand()%6+3)*40);
    }
}

int main(int argc, char* argv[])
{
    bool reinicio;
    reinicio = false;

    while (!reinicio && LoseG()==false)
    {
        Alegro();

    Spiek U(40*27, 40*4);
    Spiek K(40*30, 40*6);
    Spiek L(40*25, 40*8);
    S A(40*14, 40*9);
    S B(40*16, 40*9);
    S C(40*20, 40*9);
    S D(40*22, 40*9);
    S E(40*28, 40*9);
    R F(40*14, 40*2);
    R G(40*19, 40*2);
    R H(40*21, 40*2);
    R I(40*25, 40*2);
    R J(40*27, 40*2);

    dis_vida();
    while(!key[KEY_ESC] && LoseG()==false)
    {
         Moves ();

        if(movement == 4)
        {
            if(mapa[(Posy-40)/40][(Posx)/40] != 'Y')
            Posy -=40;
            else movement=10;
        }
        if(movement == 2)
        {
                if(mapa[(Posy+40)/40][(Posx)/40] !='Y')
                Posy +=40;
                else movement=10;
        }


        clear(buffer);
        di_mapa();
        di_cubo();
        U.MovSpike();
        U.PicoM();
        K.MovSpike();
        K.PicoM();
        L.MovSpike();
        L.PicoM();
        A.MovimientoS();
        A.DeadS();
        B.MovimientoS();
        B.DeadS();
        C.MovimientoS();
        C.DeadS();
        D.MovimientoS();
        D.DeadS();
        E.MovimientoS();
        E.DeadS();
        F.movimientoR();
        F.DeadR();
        G.movimientoR();
        G.DeadR();
        H.movimientoR();
        H.DeadR();
        I.movimientoR();
        I.DeadR();
        J.movimientoR();
        J.DeadR();
        dis_vida();
        screenl();
        rest(140);
    }
}
bool exits;
exits = false;

    while(!exits)
    {
        if (LoseG()==true)
        {
            finish();
            if (key[KEY_ESC] || key[KEY_ENTER])
            {
                exits=true;
                exit(0);
            }
            if (key[KEY_SPACE])
            {
                exits = false;
                reinicio = true;
            }
        }
    }
    destroy_bitmap(buffer);
    return 0;
}
END_OF_MAIN()
