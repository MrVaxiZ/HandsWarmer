#include "TextureManager.h"

bool TextureManager::loadTexture(const std::string& name, const std::string& filename) {
    // Create and load texture
    sf::Texture texture;
    if (!texture.loadFromFile(filename)) {
        return false; // loading failed
    }

    // Add texture to the map
    textures[name] = texture;
    return true;
}

sf::Texture& TextureManager::getTexture(const std::string& name) {
    return textures.at(name); // Will throw std::out_of_range if not found
}
