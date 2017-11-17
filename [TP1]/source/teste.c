#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <math.h>

const float FPS = 100; //FRAMES PER SECOND
const int SCREEN_W = 1200; //SCREEN WIDTH
const int SCREEN_H = 800; //SCREEN HEIGTH
const int OBJECT_SIZE = 30; //OBJECT SIZE

//NUMERO INTEIRO EM UM INTERVALO
float randomFloat (int min, int max) {
	return (rand() % (max + 1 - min)) + min;
}

//NUMERO INTEIRO EM UM INTERVALO
float randomInt (int min, int max) {
	return (rand() % (max + 1 - min)) + min;
}


float dist(float x1, float x2, float y1, float y2) {
	return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

typedef struct Bola {
	float x;
	float y;
	float raio;
	float dx;
	float dy;
	ALLEGRO_COLOR cor;
	int alive;
} Bola;

void criaBola (Bola *b, float x, float y, float raio, float dx, float dy, ALLEGRO_COLOR cor) {
	b->x = x;
	b->y = y;
	b->raio = raio;
	b->dx = dx;
	b->dy = dy;
	b->cor = cor;
	b->alive = 1;
}

void desenhaBolas(Bola *b, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (b[i].alive)
			al_draw_filled_circle(b[i].x, b[i].y, b[i].raio, b[i].cor);
	}
}

void verificaColisao(Bola *b, int n) {
	int i;
	for (i = 1; i < n; i++) {
		if (b[i].alive) {
			if (b[0].raio > b[i].raio) {
				//CHECK IF THE POINT B[I] IS ON OR INSIDE THE CIRCLE B[0]
				//FORMULA: (x - xo)^2 + (y - yo)^2 <= r^2
				if ((pow((b[i].x - b[0].x),2) + pow((b[i].y - b[0].y),2)) <= pow(b[0].raio,2)) {
					b[i].alive = 0;
					b[0].raio += b[i].raio/2;
				}
			}
		}
	}
}

int main(int argc, char **argv) {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;	
	int playing = 1;

	if(!al_init()) {
      	fprintf(stderr, "failed to initialize allegro!\n");
      	return -1;
   	}
   
    if(!al_init_primitives_addon()) {
		fprintf(stderr, "failed to initialize primitives!\n");
        return -1;
    }	

   	display = al_create_display(SCREEN_W, SCREEN_H);
   	if(!display) {
      	fprintf(stderr, "failed to create display!\n");
      	return -1;
   	}

   	timer = al_create_timer(1.0 / FPS);
   	if(!timer) {
      	fprintf(stderr, "failed to create timer!\n");
      	return -1;
   	}

	event_queue = al_create_event_queue();
   	if(!event_queue) {
      	fprintf(stderr, "failed to create event_queue!\n");
      	return -1;
   	}

   	if(!al_install_mouse())
		fprintf(stderr, "failed to initialize mouse!\n");

	//registra na fila de eventos que eu quero identificar quando a tela foi alterada
   	al_register_event_source(event_queue, al_get_display_event_source(display));
	//registra na fila de eventos que eu quero identificar quando o tempo alterou de t para t+1
   	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	// Registra mouse na fila de eventos:
	al_register_event_source(event_queue, al_get_mouse_event_source());

	ALLEGRO_COLOR BKG_COLOR = al_map_rgb(0,0,0);
   	//avisa o allegro que agora eu quero modificar as propriedades da tela
   	al_set_target_bitmap(al_get_backbuffer(display));
	//colore a tela de preto (rgb(0,0,0))
   	al_clear_to_color(BKG_COLOR);     

   	//Bola bola;
   	Bola bolas[100];
   	int countBolas = 1;
   	criaBola(&bolas[0], SCREEN_W/2, SCREEN_H/2, 50, 1, 0, al_map_rgb(0,200,0));


   	int j;
   	for (j = 1; j < 20; j++) {
   		criaBola(&bolas[j], randomFloat(0, SCREEN_W), randomFloat(0, SCREEN_H), randomInt(0,100), 0, 0, al_map_rgb(200,0,0));
   		countBolas++;
   	}

   	ALLEGRO_EVENT ev;
   	//inicia o temporizador
   	al_start_timer(timer);

	while(playing) {
		al_wait_for_event(event_queue, &ev);
		
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			playing = 0;
		} else if (ev.type == ALLEGRO_EVENT_TIMER) {
	  		if(bolas[0].x > SCREEN_W || bolas[0].x < 0)
		  		bolas[0].dx = -bolas[0].dx;
	  		if(bolas[0].y > SCREEN_H || bolas[0].y < 0)
		  		bolas[0].dy = -bolas[0].dy;  
			  	
		  	bolas[0].x += bolas[0].dx;
		  	bolas[0].y += bolas[0].dy;
		  	al_clear_to_color(BKG_COLOR);
		  	verificaColisao(bolas, countBolas); 
	   	  	desenhaBolas(bolas, countBolas);
		  	al_flip_display();
	    } else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
	    	if (bolas[0].raio > 10) {
	    		bolas[0].raio -= 5;
	    		criaBola(&bolas[countBolas], (bolas[0].dx + bolas[0].raio) + bolas[0].x, (bolas[0].dy + bolas[0].raio) + bolas[0].y, 5, 0, 0, al_map_rgb(0,0,200));
	    		countBolas++;
	    	}
		} else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
			bolas[0].dx = (ev.mouse.x - bolas[0].x)/dist(ev.mouse.x, bolas[0].x, ev.mouse.y, bolas[0].y);
			bolas[0].dy = (ev.mouse.y - bolas[0].y)/dist(ev.mouse.x, bolas[0].x, ev.mouse.y, bolas[0].y);
		}
  }    

   return 0;   
}