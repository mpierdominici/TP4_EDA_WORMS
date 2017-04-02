#include "graficar.h"
#include<stdio.h>
#define ALTO_PANTALLA 696 //alto en pixeles del display
#define ANCHO_PANTALLA 1920 //ancho en pixeles del display

#define MAPA_POSICION_ORIGEN_X 701//origen de cordenadas del worm dentro de la imagne de fondo eje x
#define MAPA_POSICION_ORIGEN_y 616//origen de cordenadas del worm dentro de la imagne de fondo eje y

#define MAX_FPS_FOR_WALKING 50
//****************Path de las imagenes de caminar***************
#define WWALK_F1 "Imagenes/wwalking/wwalk-F1.png"
#define WWALK_F2 "Imagenes/wwalking/wwalk-F2.png"
#define WWALK_F3 "Imagenes/wwalking/wwalk-F3.png"
#define WWALK_F4 "Imagenes/wwalking/wwalk-F4.png"
#define WWALK_F5 "Imagenes/wwalking/wwalk-F5.png"
#define WWALK_F6 "Imagenes/wwalking/wwalk-F6.png"
#define WWALK_F7 "Imagenes/wwalking/wwalk-F7.png"
#define WWALK_F8 "Imagenes/wwalking/wwalk-F8.png"
#define WWALK_F9 "Imagenes/wwalking/wwalk-F9.png"
#define WWALK_F10 "Imagenes/wwalking/wwalk-F10.png"
#define WWALK_F11 "Imagenes/wwalking/wwalk-F11.png"
#define WWALK_F12 "Imagenes/wwalking/wwalk-F12.png"
#define WWALK_F13 "Imagenes/wwalking/wwalk-F13.png"
#define WWALK_F14 "Imagenes/wwalking/wwalk-F14.png"
#define WWALK_F15 "Imagenes/wwalking/wwalk-F15.png"
//**************************************************************

//*****************Path de las imagenes de saltar***************

#define WJUMP_F1 "Imagenes/wjump/wjump-F1.png"
#define WJUMP_F2 "Imagenes/wjump/wjump-F2.png"
#define WJUMP_F3 "Imagenes/wjump/wjump-F3.png"
#define WJUMP_F4 "Imagenes/wjump/wjump-F4.png"
#define WJUMP_F5 "Imagenes/wjump/wjump-F5.png"
#define WJUMP_F6 "Imagenes/wjump/wjump-F6.png"
#define WJUMP_F7 "Imagenes/wjump/wjump-F7.png"
#define WJUMP_F8 "Imagenes/wjump/wjump-F8.png"
#define WJUMP_F9 "Imagenes/wjump/wjump-F9.png"
#define WJUMP_F10 "Imagenes/wjump/wjump-F10.png"
//**************************************************************

//***************Path imagen de fondo***************************

#define IMAGEN_FONDO "Imagenes/Scenario.png"

//**************************************************************
bool AlegroOkSet();

//cosntructor de la clase graficar, si todo se pudo crear devolvera true,
//a traves del getter de IsCorrectedSet
//
//
//
//
graficar::graficar()
{
	MiraDerecha = false;
	if (AlegroOkSet() == true)
	{
		
		if ((Display = al_create_display(ANCHO_PANTALLA, ALTO_PANTALLA)) != NULL)
		{
			
			if ((JumpBitmaps[0] = al_load_bitmap(WJUMP_F2)) != NULL)
			{
				if ((JumpBitmaps[1] = al_load_bitmap(WJUMP_F2)) != NULL)
				{
					if ((JumpBitmaps[2] = al_load_bitmap(WJUMP_F3)) != NULL)
					{
						if ((JumpBitmaps[3] = al_load_bitmap(WJUMP_F4)) != NULL)
						{
							if ((JumpBitmaps[4] = al_load_bitmap(WJUMP_F5)) != NULL)
							{
								if ((JumpBitmaps[5] = al_load_bitmap(WJUMP_F6)) != NULL)
								{
									if ((JumpBitmaps[6] = al_load_bitmap(WJUMP_F7)) != NULL)
									{
										if ((JumpBitmaps[7] = al_load_bitmap(WJUMP_F8)) != NULL)
										{
											if ((JumpBitmaps[8] = al_load_bitmap(WJUMP_F9)) != NULL)
											{
												if ((JumpBitmaps[9] = al_load_bitmap(WJUMP_F10)) != NULL)//termina la inicializacion de los bitmap de jump
												{
													if ((WalkBitmaps[0] = al_load_bitmap(WWALK_F1)) != NULL)//inicia la inicializacion de los bitmpas de walk
													{
														if ((WalkBitmaps[1] = al_load_bitmap(WWALK_F2)) != NULL)
														{
															if ((WalkBitmaps[2] = al_load_bitmap(WWALK_F3)) != NULL)
															{
																if ((WalkBitmaps[3] = al_load_bitmap(WWALK_F4)) != NULL)
																{
																	if ((WalkBitmaps[4] = al_load_bitmap(WWALK_F5)) != NULL)
																	{
																		if ((WalkBitmaps[5] = al_load_bitmap(WWALK_F6)) != NULL)
																		{
																			if ((WalkBitmaps[6] = al_load_bitmap(WWALK_F7)) != NULL)
																			{
																				if ((WalkBitmaps[7] = al_load_bitmap(WWALK_F8)) != NULL)
																				{
																					if ((WalkBitmaps[8] = al_load_bitmap(WWALK_F9)) != NULL)
																					{
																						if ((WalkBitmaps[9] = al_load_bitmap(WWALK_F10)) != NULL)
																						{
																							if ((WalkBitmaps[10] = al_load_bitmap(WWALK_F11)) != NULL)
																							{
																								if ((WalkBitmaps[11] = al_load_bitmap(WWALK_F12)) != NULL)
																								{
																									if ((WalkBitmaps[12] = al_load_bitmap(WWALK_F13)) != NULL)
																									{
																										if ((WalkBitmaps[13] = al_load_bitmap(WWALK_F14)) != NULL)
																										{
																											if ((WalkBitmaps[14] = al_load_bitmap(WWALK_F15)) != NULL)
																											{
																												if ((DisplayImage = al_load_bitmap(IMAGEN_FONDO)) != NULL)
																												{
																													IsCorrectedSet = true;
																													return;
																												}
																												al_destroy_bitmap(DisplayImage);
																											}
																											al_destroy_bitmap(WalkBitmaps[14]);
																										}
																										al_destroy_bitmap(WalkBitmaps[13]);
																									}
																									al_destroy_bitmap(WalkBitmaps[12]);
																								}
																								al_destroy_bitmap(WalkBitmaps[11]);
																							}
																							al_destroy_bitmap(WalkBitmaps[10]);
																						}
																						al_destroy_bitmap(WalkBitmaps[9]);
																					}
																					al_destroy_bitmap(WalkBitmaps[8]);
																				}
																				al_destroy_bitmap(WalkBitmaps[7]);
																			}
																			al_destroy_bitmap(WalkBitmaps[6]);
																		}
																		al_destroy_bitmap(WalkBitmaps[5]);
																	}
																	al_destroy_bitmap(WalkBitmaps[4]);
																}
																al_destroy_bitmap(WalkBitmaps[3]);
															}
															al_destroy_bitmap(WalkBitmaps[2]);
														}
														al_destroy_bitmap(WalkBitmaps[1]);
													}
													al_destroy_bitmap(WalkBitmaps[0]);

												}
												al_destroy_bitmap(JumpBitmaps[9]);
											}
											al_destroy_bitmap(JumpBitmaps[8]);
										}
										al_destroy_bitmap(JumpBitmaps[7]);
									}
									al_destroy_bitmap(JumpBitmaps[6]);
								}
								al_destroy_bitmap(JumpBitmaps[5]);
							}
							al_destroy_bitmap(JumpBitmaps[4]);
						}
						al_destroy_bitmap(JumpBitmaps[3]);
					}
					al_destroy_bitmap(JumpBitmaps[2]);
				}
				al_destroy_bitmap(JumpBitmaps[1]);
			}
			al_destroy_bitmap(JumpBitmaps[0]);

		}
		al_destroy_display(Display);
	}
	IsCorrectedSet = false;
}

graficar::~graficar()
{
}




void graficar::SetWorm(float _PosicionWormX, float _PosicionWormY, uint16_t _FpsCounter, uint16_t _Estado, bool _MiraDerecha)
{
	MiraDerecha = _MiraDerecha;

	uint8_t SecuanciaDeFramesWalk[50]={3,3,3,3,3,0,1,2,3,4,5,6,7,8,9,10,10,11,12,13,14,3,3,4,5,6,7,8,9,10,10,11,12,13,14,3,3,4,5,6,7,8,9,10,10,11,12,13,14,3};//secuencian en que aparecen las imagenes en el timepo
	switch (_Estado)
	{
	case 1://caso walking
		if (_FpsCounter < MAX_FPS_FOR_WALKING)//valido que el fps este en el rango del maximo fps para walking
		{
			al_draw_bitmap(WalkBitmaps[SecuanciaDeFramesWalk[_FpsCounter]], MAPA_POSICION_ORIGEN_X + _PosicionWormX, MAPA_POSICION_ORIGEN_y - _PosicionWormY, MiraDerecha);
			al_flip_display();
		}
		else
		{
			//printf("llegue a los 50 frames del walking"); //printf for debugging
		}


		break;

	case 2://jumping

		break;
	}
	
}





//DrawBackgarund()
//dibija el fondo del display
//
//
void graficar::DrawBackgarund()
{
	al_draw_bitmap(DisplayImage, 0, 0,0);
	al_flip_display();
}

//DestroyAll()
//libera toda la memoria reservada
//
//
//
void graficar::DestroyAll()
{
	al_destroy_display(Display);
	al_destroy_bitmap(DisplayImage);
	for (int i = 0; i < CANT_IMAGE_WALK; i++)
	{
		al_destroy_bitmap(WalkBitmaps[i]);
	}
	for (int i = 0; i < CANT_IMAGE_JUMP; i++)
	{
		al_destroy_bitmap(JumpBitmaps[i]);
	}

}

bool graficar::IsInitOk()
{
	return IsCorrectedSet;
}

//AlegroOkSet()
//Devuelve: true si se pudo inicializar correctamente allegro y sus complementos, 
//caso contrario devuelve false
//
//
bool AlegroOkSet()//devuelve true si allegro se inicializo correctamente
{
	if (!al_init())//inicializo allegro, si hubo error devuelvo false
	{
		return false;
	}

	if (!al_init_image_addon())//devuelve false si no pudo inizializar ellegro image addon
	{
		return false;
	}

	return true;
}