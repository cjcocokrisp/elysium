#include "asset_manager.hpp"
#include <iostream>

AssetManager::AssetManager(std::string gamePath, std::string installFilePath) : 
_gamePath(gamePath), _installFilePath(installFilePath) {
    _installConfig = toml::parse_file(installFilePath);

}

AssetManager::~AssetManager() {

}

void AssetManager::copyGameAssets() {

}

void AssetManager::decompileGameAssets() {

}

void AssetManager::createSpriteAssets() {

} 

void AssetManager::createMusicAssets() {

}

void AssetManager::createInterfaceAssets() {

}