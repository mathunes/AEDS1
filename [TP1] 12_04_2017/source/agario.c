#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

const float FPS = 100; //FRAMES PER SECOND
const int SCREEN_W = 1200; //SCREEN WIDTH
const int SCREEN_H = 600; //SCREEN HEIGTH
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

float area(float radius) {
	return PI * pow(radius,2);
}

float circu(float radius) {
	return 2 * PI * radius;
}

typedef struct Object {
	float x;
	float y;
	float dx;
	float dy;
	float radius;
	ALLEGRO_COLOR color;
	int alive;
	float speed;
} Object;

void newObject (Object *b, float x, float y, float radius, float dx, float dy, ALLEGRO_COLOR color) {
	b->x = x;
	b->y = y;
	b->radius = radius;
	b->dx = dx;
	b->dy = dy;
	b->color = color;
	b->alive = 1;
	b->speed = 2.0;
}

void draw(Object *b) {
	al_draw_filled_circle((*b).x, (*b).y, (*b).radius, (*b).color);
}

void drawObjects(Object *b, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (b[i].alive)
			draw(&b[i]);
	}
}

void moveObject(Object *object) {
	(*object).x += (*object).dx / (*object).speed;
  	(*object).y += (*object).dy / (*object).speed;
}

void checkColision(Object *player, Object *objects, int countObjects) {
	int i;

	for (i = 0; i < countObjects; i++) {
		if (objects[i].alive && (*player).alive) {
			if ((*player).radius > objects[i].radius) {
				//CHECK IF THE POINT B[I] IS ON OR INSIDE THE CIRCLE B[0]
				//FORMULA: (x - xo)^2 + (y - yo)^2 <= r^2
				if ((pow((objects[i].x - (*player).x),2) + pow((objects[i].y - (*player).y),2)) <= pow((*player).radius,2)) {
					objects[i].alive = 0;
					(*player).radius = sqrt((area((*player).radius) + area(objects[i].radius))/PI);
					(*player).speed += 0.1;
				} else if ((pow(((*player).x - objects[i].x),2) + pow((*player).y - (objects[i].y),2)) <= pow(objects[i].radius,2)) {
					(*player).alive = 0;
					objects[i].radius = sqrt((area(objects[i].radius) + area((*player).radius))/PI);
					objects[i].speed += 0.1;
				}
			}
		}
	}
}

void checkBoundries(Object *object) {
	if((*object).x > SCREEN_W || (*object).x < 0)
  		(*object).dx = -(*object).dx;
	if((*object).y > SCREEN_H || (*object).y < 0)
  		(*object).dy = -(*object).dy;  
			  	
  	moveObject(object);
}

int checkWinning(Object *player, Object *enemy) {
	//CHECK IF THE POINT B[I] IS ON OR INSIDE THE CIRCLE B[0]
	//FORMULA: (x - xo)^2 + (y - yo)^2 <= r^2
	if ((pow(((*enemy).x - (*player).x),2) + pow(((*enemy).y - (*player).y),2)) <= pow((*player).radius,2)) {
		
		(*enemy).alive = 0;
		(*player).radius = sqrt((area((*player).radius) + area((*enemy).radius))/PI);
		
		return 0;
	} else if ((pow(((*player).x - (*enemy).x),2) + pow(((*player).y - (*enemy).y),2)) <= pow((*enemy).radius,2)) {
		
		(*player).alive = 0;
		(*enemy).radius = sqrt((area((*enemy).radius) + area((*player).radius))/PI);
		
		return 0;
	} else 
		return 1;
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

   	Object player;
	Object enemy;
   	float enemyMouseX, enemyMouseY;

	int countObjects;
   	Object objects[10000];

   	int i;

   	/*INITIALIZE PLAYER AND ENEMY OBJECTS*/
   	newObject(&player, randomFloat(0,SCREEN_W), randomFloat(0,SCREEN_H), 40, 1, 1, al_map_rgb(0,200,0));
   	newObject(&enemy, randomFloat(0,SCREEN_W), randomFloat(0,SCREEN_H), 40, 1, 1, al_map_rgb(200,0,0));

   	/*INITIALIZE SMALLER OBJECTS*/
   	for (countObjects = 0; countObjects < 100; countObjects++) {
   		newObject((objects + countObjects), randomFloat(0, SCREEN_W), randomFloat(0, SCREEN_H), randomFloat(1,20), 0, 0, al_map_rgb(0,0,200));
   	}

   	ALLEGRO_EVENT ev;
   	//inicia o temporizador
   	al_start_timer(timer);

	while(playing) {
		al_wait_for_event(event_queue, &ev);
		
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			/*END GAME ON WINDOW CLOSE*/
			playing = 0;
		} else if (ev.type == ALLEGRO_EVENT_TIMER) {

			/*RANDOMLY MAKE THE ENEMY MOVE AND CREATE OTHER OBJECTS*/
			if (!randomInt(0,150)) {
				/*CHANGE THE ENEMY DX AND DY*/
			  	enemyMouseX = randomFloat(0,SCREEN_W);
			  	enemyMouseY = randomFloat(0,SCREEN_H);

				enemy.dx = (enemyMouseX - enemy.x)/dist(enemyMouseX, enemy.x, enemyMouseY, enemy.y);
				enemy.dy = (enemyMouseY - enemy.y)/dist(enemyMouseX, enemy.x, enemyMouseY, enemy.y);

				/*MAKE THE ENEMY EXPEL OTHER OBJECTS*/
	    		if (enemy.radius > 10.0) {
	    			enemy.radius = sqrt((area(enemy.radius) - area(5.0))/PI);
	    			if (enemy.speed > 0.1) enemy.speed -= 0.1;
		    		newObject(&objects[countObjects], 
		    			(ev.mouse.x >= enemy.x) ? (enemy.x + enemy.radius) : (enemy.x - enemy.radius), 
		    			(ev.mouse.y >= enemy.y) ? (enemy.y + enemy.radius) : (enemy.y - enemy.radius),
		    			5, -enemy.dx, -enemy.dy, al_map_rgb(200,0,0));
	    			countObjects++;
	    		}
			}

			/*CHECK COLISION WITH THE SCREEN LIMITS*/
			checkBoundries(&player);
			checkBoundries(&enemy);
			for (i = 0; i < countObjects; i++) {
		  		checkBoundries(&objects[i]);	
		  	}

		  	al_clear_to_color(BKG_COLOR);

		  	/*CHECK THE COLISION BETWEEN THE TWO PLAYERS AND THE SMALL OBJECTS*/
			checkColision(&player, objects, countObjects);
		  	checkColision(&enemy, objects, countObjects);
			for (i = 0; i < countObjects; i++) {
		  		checkColision(&objects[i], objects, countObjects);	
		  	}

		  	/*CHECK IF THERE WAS A COLISION BETWEEN THE TWO PLAYERS, WICH MEANS THE GAME IS ENDED*/
		  	playing = checkWinning(&player, &enemy);

		  	/*DRAW EVERYTHING*/
		  	draw(&player);
		  	draw(&enemy);
	   	  	drawObjects(objects, countObjects);

		  	al_flip_display();
	    } else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
	    	/*CHANGE THE PLAYER DX AND DY BASED ON THE MOUSE CLICK*/
	    	player.dx = -(ev.mouse.x - player.x)/dist(ev.mouse.x, player.x, ev.mouse.y, player.y);
			player.dy = -(ev.mouse.y - player.y)/dist(ev.mouse.x, player.x, ev.mouse.y, player.y);

			/*CHECK IF THE PLAYER IS ABOVE THE MINIMUN RADIUS TO EXPEL ANOTHER OBJECTS*/
	    	if (player.radius > 10.0) {
	    		player.radius = sqrt((area(player.radius) - area(5.0))/PI);
	    		if (player.speed > 0.1) player.speed -= 0.1;
	    		newObject(&objects[countObjects], 
	    			(ev.mouse.x >= player.x) ? (player.x + player.radius) : (player.x - player.radius), 
	    			(ev.mouse.y >= player.y) ? (player.y + player.radius) : (player.y - player.radius),
	    			5, -player.dx, -player.dy, al_map_rgb(0,200,0));
	    		countObjects++;
	    	}

		}
  }    

   return 0;   
}