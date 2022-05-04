﻿#include "SpawnZombis.h"

#include "InputManager.h"
#include "Entidad.h"
#include "EntidadManager.h"
#include "Transform.h"
#include <time.h>
#include "FMODAudioManager.h"

const int POS_ZOMBIS_X = 1150;
const int POS_ZOMBIS_Y = 750;
const int MARGIN = 100;
const clock_t TIME_TO_SPAWN = 400;

bool SpawnZombis::init(const std::map<std::string, std::string>& mapa)
{
	return true;
}

void SpawnZombis::update()
{
	clock_t auxc = clock();
	if(auxc > lastZombie + TIME_TO_SPAWN){

		lastZombie = auxc;

		//std::cout << "Se crea un Zombie\n";
		Entidad* zombie = Entidad::instantiate("Zombie.prefab");
		Singleton<FMODAudioManager>::instance()->playMusic(5, false);

		// Los zombis se generan en las 4 esquinas
		int x = POS_ZOMBIS_X;
		int z = POS_ZOMBIS_Y;

		int mx = rand() % MARGIN - MARGIN / 2;
		int mz = rand() % MARGIN - MARGIN / 2;

		if (rand() % 2 == 1) {
			x = -x;
			x += mx;
		}

		if (rand() % 2 == 1) {
			z = -z;
			z += mz;
		}

		//std::cout << "x: " << x << " z: " << z << "\n";
		zombie->getComponent<Transform>()->setPosition(zombie->getComponent<Transform>()->getPosition() + Vectola3D(x, 0, z));
	}
}
