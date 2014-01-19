#ifndef HERO_ENGINE_DEF_H
#define HERO_ENGINE_DEF_H


#ifdef EXPORT
	#define HERO_ENGINE_API __declspec(dllexport)
#else
	#define HERO_ENGINE_API __declspec(dllimport)
#endif


#endif