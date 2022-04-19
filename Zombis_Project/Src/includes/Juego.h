#pragma once
#ifdef JUEGO_EXPORTS
#define JUEGO_API __declspec(dllexport)
#else
#define JUEGO_API __declspec(dllimport)
#endif

/// <summary>
/// FUNCI�N PRINCIPAL PARA CARGAR EL JUEGO
/// </summary>
int LoadGame();

/// <summary>
/// Aqu� se registran los componentes �nicos de cada juego que por tanto no conoce el motor
/// </summary>
void RegistryGameComponents();

