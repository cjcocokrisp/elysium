#pragma once
#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <string>
#include <toml++/toml.hpp>

class AssetManager {
public:
    AssetManager(std::string gamePath, std::string installFilePath);
    ~AssetManager();
    void copyGameAssets();
    private:
    std::string _gamePath;
    std::string _installFilePath;
    toml::table _installConfig;

    void decompileGameAssets();
    void createSpriteAssets();
    void createMusicAssets();
    void createInterfaceAssets();
    
};

#endif