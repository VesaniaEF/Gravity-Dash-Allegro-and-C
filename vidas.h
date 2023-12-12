#ifndef VIDAS_H_INCLUDED
#define VIDAS_H_INCLUDED
#define PISO 31
#include <allegro.h>
int vida=1;


void over_lifes()
{
    vida--;

}
void dis_vida ()
{
        textout_ex(buffer, font, "Score", 40*2, 40*2, 0xFFFFFF,0x000000);

    for(int i=0; i < vida; i++)
    {
        draw_sprite(buffer,heart,i*40, 40*0);
    }
}
#endif // VIDAS_H_INCLUDED
