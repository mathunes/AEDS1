ALLEGRO_VERSION=5.0.10
MINGW_VERSION=4.7.0
FOLDER=../

FOLDER_NAME=allegro-$(ALLEGRO_VERSION)-mingw-$(MINGW_VERSION)
PATH_ALLEGRO=$(FOLDER)$(FOLDER_NAME)
LIB_ALLEGRO=\lib\liballegro-$(ALLEGRO_VERSION)-monolith-mt.a
INCLUDE_ALLEGRO=\include

all: teste.exe

teste.exe: teste.o
	gcc -o teste.exe teste.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

teste.o: teste.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c teste.c		
	 
clean:
	del teste.o
	del teste.exe