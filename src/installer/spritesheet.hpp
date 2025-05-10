#pragma once
#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <string>
#include <filesystem>

const int DIRECTIONS = 8;

/* 
 * Creates a spritesheet from the given directory with sprites and then saves
 * it to the output path.
 * 
 * The directory should be set up in a way where each sprite is the same dimensions.
 * Each file must be a png and each file must be named the number that it is starting at 0. 
 * For example: 0.png 1.png, 2.png, ..., n.png where n is the number of the last frame.
 *
 * @param dir the directory with the frames for the sprite.
 * @param outputPath the output path where the spritesheet will be saved to.
 */
void createSpriteSheet(std::string dir, std::string outputPath);

/* 
 * Creates a spritesheet from the given directory with sprites that have directionals 
 * and then saves it to the output path.
 * 
 * The directory should be set up in a way where each sprite is the same dimensions.
 * Each file must be a png and each file must be named the number that it is starting at 0. 
 * For directions, the sprites must be organized by direction for that frame. 
 * So for the first frame in the animation, the first png should be whatever direction you choose
 * then the next png should be a different direction. The pattern of directions should keep up. The 
 * total amount of frames should be divisible by the number of directions. 
 * For example if you were just using the four cardinal directions (N,E,S,W) the directory should look
 * like so: 0.png (N, 1st Frame of animation), 1.png (E, 1st Frame of animation), 
 * 2.png (S, 1st Frame of animation), 3.png (W, 1st Frame of animation), 4.png (N, 2nd Frame of animation), 
 * 5.png (E, 2nd Frame of animation), 6.png (S, 2nd Frame of animation), 7.png (W, 2nd Frame of animation), 
 * and so on.
 *
 * At the current moment the number of directions is hardcoded to be 8 because that is how they 
 * are formatted for the use case in this project. If I eventually turn this spritesheet generation
 * into it's own CLI tool I will definetly change that.
 * 
 * @param dir the directory with the frames for the sprite.
 * @param outputPath the output path where the spritesheet will be saved to.
 */
void createDirectionalSpriteSheet(std::string dir, std::string outputPath);

#endif