#include "zombieMove.h"
#include "Entidad.h"
#include <iostream>
#include "Transform.h"
#include "grafoConObstaculos.h"
#include "RigidBody.h"
#include "EntidadManager.h"
#include "GameManager.h"

ZombieMove::ZombieMove()
{
}

ZombieMove::~ZombieMove()
{
}

bool ZombieMove::init(const std::map<std::string, std::string>& mapa)
{
	if (mapa.find("speed") == mapa.end())
		return false;

	std::string s = mapa.at("speed");
	_speed = stof(s);

	return true;
}

void ZombieMove::onCollisionStart(Entidad* other) {
	if (other->getName() == "Bala") {
		// Sumar punto
		GameManager::GetInstance()->addPoints(10);
		// Destruir bala
		other->setActive(false);
		// Destruir zombi
		entity_->setActive(false);
	}
}

void ZombieMove::update()
{
	// Busca la entidad del jugador
	if (!_player) _player = Singleton<EntidadManager>::instance()->getEntidadByID(0);

	Vectola3D aux = entity_->getComponent<Transform>()->getPosition();

	if (entity_->hasComponent<RigidBody>() && entity_->hasComponent<Transform>()){
		// Se calcula la direccion
		Vectola3D dir = _player->getComponent<Transform>()->getPosition() - entity_->getComponent<Transform>()->getPosition();

		// Importante normalizar y a�adir el speed
		dir = dir.normalize() * _speed;

		// CINEMATIC
		//entity_->getComponent<Transform>()->setPosition(entity_->getComponent<Transform>()->getPosition() + dir);

		// PHYSX
		entity_->getComponent<RigidBody>()->setVelocity(physx::PxVec3(dir.getX(), dir.getY(), dir.getZ()));
	}
}
