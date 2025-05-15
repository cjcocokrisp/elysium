#include "spritesheet.hpp"
#include "raylib.h"

namespace fs = std::filesystem;

// Calculates the total frames in a directory by counting .png files
int getTotalFrames(const std::string directory) {
    const fs::path path{directory};
    int totalFrames = 0;
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            const std::string filename = entry.path().filename().string();
            filename.find(".png") != std::string::npos ? totalFrames++ : 0;
        }
    }
    return totalFrames;
}

void createSpriteSheet(std::string directory, std::string outputPath) {
    // Get frame count from directory
    int totalFrames = getTotalFrames(directory);

    // Open first frame and calculate dimensions
    Image image = LoadImage((directory + "/0.png").c_str());
    int frameWidth = image.width, frameHeight = image.height;
    int sheetWidth = frameWidth * totalFrames;
    UnloadImage(image);

    // Create spritesheet and save it
    Color* sheetColors = new Color[sheetWidth * frameHeight];
    for (int i = 0; i < totalFrames; i++) {
        std::string filename = directory + "/" + std::to_string(i) + ".png";
        Image frame = LoadImage(filename.c_str());

        int colOffset = i * frameWidth;

        Color* frameColors = LoadImageColors(frame);
        for (int row = 0; row < frameHeight; row++) {
            for (int col = 0; col < frameWidth; col++) {
                int sheetIndex = (col * sheetWidth + colOffset) + row;
                int frameIndex = col * frameWidth + row;

                sheetColors[sheetIndex] = frameColors[frameIndex];
            }
        }
        UnloadImageColors(frameColors);
        UnloadImage(frame);
    }
    Image sheet{sheetColors, sheetWidth, frameHeight, 1, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8};
    ExportImage(sheet, outputPath.c_str());
    UnloadImage(sheet);
}

void createDirectionalSpriteSheet(std::string directory, std::string outputPath) {
    // Get frame count from directory
    int totalFrames = getTotalFrames(directory);
    
    // Open first frame and calculate dimensions
    Image image = LoadImage((directory + "/0.png").c_str());
    int frameWidth = image.width, frameHeight = image.height;
    int sheetWidth = frameWidth * (totalFrames / DIRECTIONS), sheetHeight = frameHeight * DIRECTIONS;
    UnloadImage(image);

    // Create spritesheet then save it and 
    Color* sheetColors = new Color[sheetWidth * sheetHeight];
    for (int i = 0; i < totalFrames; i++) {
        std::string filename = directory + "/" + std::to_string(i) + ".png";
        Image frame = LoadImage(filename.c_str());

        int rowOffset = (i % DIRECTIONS) * frameWidth;
        int colOffset = (i / DIRECTIONS) * frameHeight;
        
        Color* frameColors = LoadImageColors(frame);
        for (int row = 0; row < frameHeight; row++) {
            for (int col = 0; col < frameWidth; col++) {
                int sheetIndex = (col * sheetWidth + colOffset) + row + rowOffset * sheetWidth;
                int frameIndex = col * frameWidth + row;

                sheetColors[sheetIndex] = frameColors[frameIndex];
            }
        }
        UnloadImageColors(frameColors);
        UnloadImage(frame);
    }
    Image sheet{sheetColors, sheetWidth, sheetHeight, 1, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8};
    ExportImage(sheet, outputPath.c_str());
    UnloadImage(sheet);
}