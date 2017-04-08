// TP4-EDA-WORMS.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "graficar.h"
#include"worms.h"
#include <allegro5/allegro.h>
#include "point.h"
int main()
{
	graficar GraficadorDeWorms;
	bool Walk = false;
	bool Walk2 = false;
	bool IsRight = true;
	bool IsRight2 = true;
	bool Quit = false;
	bool WaitForEnter = true;
	ALLEGRO_EVENT Eventos;//eventos de allegro
	ALLEGRO_EVENT_QUEUE * ColaDeEventos;
	worm p1;
	worm p2;
	GraficadorDeWorms.DrawBackgarund();
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if ((ColaDeEventos = al_create_event_queue()) == NULL)//inicializo la cola de eventos
	{
		fprintf(stderr, "failed to initialize Cola de eventos!\n");
		return -1;
	}

	if (!al_install_keyboard()) //inicializo el teclado
	{
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	al_register_event_source(ColaDeEventos, al_get_keyboard_event_source());//asigno los eventos del teclado a la cola de eventos

	while (!Quit)
	{
		
		
		while ( al_get_next_event(ColaDeEventos, &Eventos)==true)//chequeo que lei toda la cola de eventos
		{



			if (!WaitForEnter)
			{
				if (Eventos.type == ALLEGRO_EVENT_KEY_DOWN)//chequeo si se apreto una tecla
				{
					if (p1.getWormState() == STILL || p1.getWormState() == WARMING_UP)
					{
						switch (Eventos.keyboard.keycode) {

						case ALLEGRO_KEY_UP:

							p1.startJumping();
							break;

						case ALLEGRO_KEY_LEFT:
							p1.startMoving();
							IsRight = false;
							Walk = true;
							break;

						case ALLEGRO_KEY_RIGHT:
							p1.startMoving();
							IsRight = true;
							Walk = true;
							break;
						}
					}

					if (p2.getWormState() == STILL || p2.getWormState() == WARMING_UP)
					{
						switch (Eventos.keyboard.keycode) {

						case ALLEGRO_KEY_W:

							p2.startJumping();
							break;

						case ALLEGRO_KEY_A:
							p2.startMoving();
							IsRight2 = false;
							Walk2 = true;
							break;

						case ALLEGRO_KEY_D:
							p2.startMoving();
							IsRight2 = true;
							Walk2 = true;
							break;
						}
					}

					if (Eventos.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
					{
						Quit = true;
					}


				}
				if (Eventos.type == ALLEGRO_EVENT_KEY_UP)//chequeo si se solto una tecla
				{
					if (p1.getWormState() == STILL || p1.getWormState() == WARMING_UP)
					{
						switch (Eventos.keyboard.keycode) {
						case ALLEGRO_KEY_UP:

							break;

						case ALLEGRO_KEY_LEFT:
							Walk = false;
							break;

						case ALLEGRO_KEY_RIGHT:
							Walk = false;
							break;
						}
					}

					if (p2.getWormState() == STILL || p2.getWormState() == WARMING_UP)
					{
						switch (Eventos.keyboard.keycode) {
						case ALLEGRO_KEY_W:

							break;

						case ALLEGRO_KEY_A:
							Walk2 = false;
							break;

						case ALLEGRO_KEY_D:
							Walk2 = false;
							break;
						}
					}

					if (Eventos.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
					{
						Quit = true;
					}

				}

			}
			else
			{
				
				if (Eventos.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					WaitForEnter = false;
				}

			}

			
			
			
			
			
			


		}// hasta aca

		if (!WaitForEnter)
		{
			GraficadorDeWorms.DrawBackgarund();
			if (p1.getWormState() == STILL)
			{
				GraficadorDeWorms.SetWorm(p1.getPosition().getX(), p1.getPosition().getY(), p1.getFrameCount() - 1, p1.getWormState(), p1.lookRight());
				p1.continueAction();

			}
			if (p1.getWormState() == JUMPING || p1.getWormState() == FINISHING_JUMPING)
			{
				GraficadorDeWorms.SetWorm(p1.getPosition().getX(), p1.getPosition().getY(), p1.getFrameCount() - 1, p1.getWormState(), p1.lookRight());
				p1.continueAction();
			}
			if (p1.getWormState() == WARMING_UP&&Walk)
			{
				p1.setLookingWorm(IsRight);
				GraficadorDeWorms.SetWorm(p1.getPosition().getX(), p1.getPosition().getY(), p1.getFrameCount() - 1, p1.getWormState(), p1.lookRight());
				p1.continueAction();
			}
			else if (p1.getWormState() == WARMING_UP && !Walk)
			{

				p1.StopALL();
				GraficadorDeWorms.SetWorm(p1.getPosition().getX(), p1.getPosition().getY(), p1.getFrameCount() - 1, p1.getWormState(), p1.lookRight());
				p1.continueAction();
			}
			if (p1.getWormState() == WALKING)
			{

				GraficadorDeWorms.SetWorm(p1.getPosition().getX(), p1.getPosition().getY(), p1.getFrameCount() - 1, p1.getWormState(), p1.lookRight());
				p1.continueAction();
			}
			if (p1.getWormState() == FINISHING_WALKING)
			{

				GraficadorDeWorms.SetWorm(p1.getPosition().getX(), p1.getPosition().getY(), p1.getFrameCount() - 1, p1.getWormState(), p1.lookRight());
				p1.continueAction();
			}

			//**************************************worm2*********************************************************
			if (p2.getWormState() == STILL)
			{
				GraficadorDeWorms.SetWorm(p2.getPosition().getX(), p2.getPosition().getY(), p2.getFrameCount() - 1, p2.getWormState(), p2.lookRight());
				p2.continueAction();

			}
			if (p2.getWormState() == JUMPING || p2.getWormState() == FINISHING_JUMPING)
			{
				GraficadorDeWorms.SetWorm(p2.getPosition().getX(), p2.getPosition().getY(), p2.getFrameCount() - 1, p2.getWormState(), p2.lookRight());
				p2.continueAction();
			}
			if (p2.getWormState() == WARMING_UP&&Walk2)
			{
				p2.setLookingWorm(IsRight2);
				GraficadorDeWorms.SetWorm(p2.getPosition().getX(), p2.getPosition().getY(), p2.getFrameCount() - 1, p2.getWormState(), p2.lookRight());
				p2.continueAction();
			}
			else if (p2.getWormState() == WARMING_UP && !Walk2)
			{

				p2.StopALL();
				GraficadorDeWorms.SetWorm(p2.getPosition().getX(), p2.getPosition().getY(), p2.getFrameCount() - 1, p2.getWormState(), p2.lookRight());
				p2.continueAction();
			}
			if (p2.getWormState() == WALKING)
			{

				GraficadorDeWorms.SetWorm(p2.getPosition().getX(), p2.getPosition().getY(), p2.getFrameCount() - 1, p2.getWormState(), p2.lookRight());
				p2.continueAction();
			}
			if (p2.getWormState() == FINISHING_WALKING)
			{

				GraficadorDeWorms.SetWorm(p2.getPosition().getX(), p2.getPosition().getY(), p2.getFrameCount() - 1, p2.getWormState(), p2.lookRight());
				p2.continueAction();
			}

		}
		else
		{
			GraficadorDeWorms.Enter();
		}
		











		al_rest(1 / 50.0);
	}


	al_destroy_event_queue(ColaDeEventos);
	GraficadorDeWorms.DestroyAll();
	

    return 0;
}

