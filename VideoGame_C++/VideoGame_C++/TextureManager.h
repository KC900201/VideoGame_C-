#pragma once
#include <string>
#include <unordered_map>
#include "SDL2/SDL.h"

class TextureManager {
private:
	std::unordered_map<std::string, SDL_Texture *> textures;
	static SDL_Renderer *renderer;

public:
	~TextureManager();
	// MUST be done before you can use this class
	static void setRenderer(SDL_Renderer *r);

	void setTexture(const std::string &name, SDL_Texture *tex);
	SDL_Texture *getTexture(const std::string &name);

};