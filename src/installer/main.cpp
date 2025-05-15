#include <iostream>
#include "asset_manager.hpp"

int main(int argc, char* argv[]) {
    std::cout << "this will install the project aka create the assets needed from games" << std::endl;

    AssetManager("", "../install_configs/template.toml");

    return 0;
}