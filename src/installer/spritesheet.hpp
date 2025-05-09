#pragma once
#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <string>
#include <filesystem>

const int DIRECTIONS = 8;

/* 
 * Creates a spritesheet from the given directory and then saves it to the output path.
 * 
 * TODO write more about the format of the directory and frames
 *
 * @param dir the directory with the frames for the sprite.
 * @param outputPath the output path where the spritesheet will be saved to.
 */
void createSpriteSheet(std::string dir, std::string outputPath);

#endif