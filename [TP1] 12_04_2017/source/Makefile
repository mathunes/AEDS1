ALLEGRO_VERSION=5.0.10
MINGW_VERSION=4.7.0
FOLDER=../

FOLDER_NAME=allegro-$(ALLEGRO_VERSION)-mingw-$(MINGW_VERSION)
PATH_ALLEGRO=$(FOLDER)$(FOLDER_NAME)
LIB_ALLEGRO=\lib\liballegro-$(ALLEGRO_VERSION)-monolith-mt.a
INCLUDE_ALLEGRO=\include

all: agario.exe

agario.exe: agario.o
	gcc -o agario.exe agario.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

agario.o: agario.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c agario.c		
	 
clean:
	del agario.o
	del agario.exe