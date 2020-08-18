#include "TextureManager.h"
#include "SDL2/SDL.h"

SDL_Renderer* TextureManager::renderer = NULL;

TextureManager::~TextureManager() {
	for (auto& entry : textures) {
		SDL_DestroyTexture(entry.second);
	}

	textures.clear();
}

void TextureManager::setTexture(const std::string &name, SDL_Texture* tex) {
	textures[name] = tex;
}

SDL_Texture *TextureManager::getTexture(const std::string& name) {
	auto it = textures.find(name);
	if (textures.find(name) == textures.end()) {
		return NULL;
	}

	return it->second;
}

void TextureManager::setRenderer(SDL_Renderer *r) {
	renderer = r;
}

