#ifndef EXIT_H_INCLUDED
#define EXIT_H_INCLUDED
#include <allegro.h>

    int score = 0;
    char c1 [10];
void finish ()
{
                blit(losee,buffer,0,0,60,0,1200,440);
            textout(buffer,font,"Your score is:",220,350,pallete_color[14]);
            textout_ex(buffer, font, itoa(score,c1,10), 240, 380,  0xfff000, -1);
            textout(buffer,font,"Presione ESC o ENTER para salir",220,490,pallete_color[14]);
            blit(buffer,screen,0,0,0,0,1200,440);
            midi_pause();
}

#endif // EXIT_H_INCLUDED
