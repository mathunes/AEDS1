ALLEGRO_VERSION=5.0.10
MINGW_VERSION=4.7.0
FOLDER=C:\Users\matheus.lima\Downloads\TP_AEDS1

FOLDER_NAME=\allegro-$(ALLEGRO_VERSION)-mingw-$(MINGW_VERSION)
PATH_ALLEGRO=$(FOLDER)$(FOLDER_NAME)
LIB_ALLEGRO=\lib\liballegro-$(ALLEGRO_VERSION)-monolith-mt.a
INCLUDE_ALLEGRO=\include

all: circles.exe passaro_andante.exe teclado.exe bouncer.exe louco.exe frogger.exe passaro_raivoso.exe

circles.exe: circles.o
	gcc -o circles.exe circles.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

circles.o: circles.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c circles.c		

passaro_andante.exe: passaro_andante.o
	gcc -o passaro_andante.exe passaro_andante.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

passaro_andante.o: passaro_andante.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c passaro_andante.c
	
passaro_raivoso.exe: passaro_raivoso.o
	gcc -o passaro_raivoso.exe passaro_raivoso.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

passaro_raivoso.o: passaro_raivoso.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c passaro_raivoso.c	
	
bouncer.exe: bouncer.o
	gcc -o bouncer.exe bouncer.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

bouncer.o: bouncer.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c bouncer.c	
	
teclado.exe: teclado.o
	gcc -o teclado.exe teclado.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

teclado.o: teclado.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c teclado.c	

louco.exe: louco.o
	gcc -o louco.exe louco.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

louco.o: louco.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c louco.c		
	
frogger.exe: frogger.o
	gcc -o frogger.exe frogger.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

frogger.o: frogger.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c frogger.c		
	
 
clean:
	del circles.o 
	del circles.exe
	del passaro_andante.o 
	del passaro_andante.exe
	del passaro_raivoso.o 
	del passaro_raivoso.exe	
	del louco.o 
	del louco.exe
	del teclado.o 
	del teclado.exe
	del bouncer.o 
	del bouncer.exe	
	del frogger.o
	del frogger.exe

