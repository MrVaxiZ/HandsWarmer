#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <unordered_map>
#include <string>
#include <mutex>

#include <SFML/Graphics.hpp>

class TextureManager {
public:
    bool loadTexture(const std::string& name, const std::string& filename);
    sf::Texture& getTexture(const std::string& name);

private:
    std::unordered_map<std::string, sf::Texture> textures;
    std::mutex mutex; // Mutex for thread-safe access
};

#endif // TEXTUREMANAGER_H
