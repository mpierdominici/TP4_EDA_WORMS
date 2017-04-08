#include <stdint.h>
#include<allegro5\allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define CANT_IMAGE_WALK 15 //cantidad de imagenes para la caminata del worm
#define CANT_IMAGE_JUMP 10 //cantidad de imagenes para el salto del worm
class graficar
{
public:
	graficar();
	~graficar();
	void SetWorm(float _PosicionWormX, float _PosicionWormY, uint16_t _FpsCounter, uint16_t _Estado, bool _MiraDerecha);//setea la posicion, tiempo, y estado del robot
	void DrawBackgarund();//dibuja el fondo del juego
	void DestroyAll(); //destruye todo lo que se creo
	bool IsInitOk(); // devuelve true si se inicializo correctamente la clase
	void Enter();
private:
	float PosicionWormX;//posicion en x del worm
	float PosicionWormY;//posicion en y del worm
	bool IsCorrectedSet;//true si se inicializo correctamente memoria y si se inicializo correctamente allegro
	uint16_t FpsCounter;//contador de tiempo
	bool MiraDerecha;//bool que si esta en estado true el worm mira a la izquierda
	ALLEGRO_DISPLAY * Display;
	ALLEGRO_BITMAP * JumpBitmaps[CANT_IMAGE_JUMP];//arreglo de imagenes del worm caminando
	ALLEGRO_BITMAP * WalkBitmaps[CANT_IMAGE_WALK];//arreglo de imagenes del worm saltando
	ALLEGRO_BITMAP * DisplayImage;//imagen de fondo del display
	ALLEGRO_BITMAP * DisplayImageFondo;//imagen de fondo del display detrasa del scenario
	ALLEGRO_BITMAP * StartImageFondo;
};

