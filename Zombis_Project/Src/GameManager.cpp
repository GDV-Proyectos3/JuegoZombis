#include "GameManager.h"
#include "OverlayManager.h"
#include <string>

GameManager* GameManager::_singleton = nullptr;

GameManager* GameManager::GetInstance() {
	return _singleton;
}

bool GameManager::Init() {
	if (_singleton != nullptr) return false;
	_singleton = new GameManager(); return true;
}

void GameManager::initGame()
{	
	// Crea un texto de puntuacion y un fondo
	Singleton<OverlayManager>::instance()->creaPanel(0.0f, 0.0f, "PuntosPanel", "Blanco", 0.25f, 0.08f);
	Singleton<OverlayManager>::instance()->creaTexto(0.0f, -0.08f, "POINTS:", "PuntosTexto", 0.05f, "PuntosTextoPanel", 0.25f, 0.25f);

	// Guarda el texto de puntuacion para que luego sea m�s facil obtenerlo
	Ogre::TextAreaOverlayElement* p = Singleton<OverlayManager>::instance()->getTexto("PuntosTextoPanel", "PuntosTexto");

	// Si encuentra el texto
	if (p != nullptr) p->setCaption("POINTS: " + std::to_string(points));

	// Crea un texto de puntuacion y un fondo
	Singleton<OverlayManager>::instance()->creaPanel(0.75f, 0.0f, "VidasPanel", "Blanco", 0.25f, 0.08f);
	Singleton<OverlayManager>::instance()->creaTexto(0.75f, -0.08f, "LIVES:", "VidasTexto", 0.05f, "VidasTextoPanel", 0.25f, 0.25f);

	// Guarda el texto de puntuacion para que luego sea m�s facil obtenerlo
	Ogre::TextAreaOverlayElement* v = Singleton<OverlayManager>::instance()->getTexto("VidasTextoPanel", "VidasTexto");

	// Si encuentra el texto
	if (v != nullptr) v->setCaption("VIDAS: " + std::to_string(lives));

}

int GameManager::getPoints()
{
	return points;
}

void GameManager::updatePointsText()
{
	Ogre::TextAreaOverlayElement* p = Singleton<OverlayManager>::instance()->getTexto("PuntosTextoPanel", "PuntosTexto");
	if (p != nullptr) p->setCaption("POINTS: " + std::to_string(points));
}

void GameManager::setPoints(int totalPoints)
{
	points = totalPoints;
	updatePointsText();
}

void GameManager::addPoints(int pointsToAdd)
{
	points += pointsToAdd;
	updatePointsText();
}

void GameManager::removePoints(int pointsToRemove)
{
	points -= pointsToRemove;
	updatePointsText();
}

void GameManager::updateLiveText()
{
	Ogre::TextAreaOverlayElement* v = Singleton<OverlayManager>::instance()->getTexto("VidasTextoPanel", "VidasTexto");
	if (v != nullptr) v->setCaption("VIDAS: " + std::to_string(lives));
}

int GameManager::getLives()
{
	return lives;
}

void GameManager::setLives(int totalLives)
{
	lives = totalLives;
	updateLiveText();
}

void GameManager::addLives(int livesToAdd)
{
	lives += livesToAdd;
	updateLiveText();
}

void GameManager::removeLives(int livesToRemove)
{
	lives -= livesToRemove;
	updateLiveText();
}

