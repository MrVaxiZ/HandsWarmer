#include "TextureManager.h"

bool TextureManager::loadTexture(const std::string& name, const std::string& filename) {
    sf::Texture texture;
    if (!texture.loadFromFile(filename)) {
        return false; // Loading failed
    }

    {
        std::lock_guard<std::mutex> lock(mutex); // Lock for thread safety
        textures[name] = std::move(texture);
    }
    return true;
}

sf::Texture& TextureManager::getTexture(const std::string& name) {
    std::lock_guard<std::mutex> lock(mutex); // Lock for thread safety
    return textures.at(name); // Will throw std::out_of_range if not found
}
