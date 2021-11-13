# BasicIK
SDL C project for inverse kinematics.
Written to get a basic understanding of various SDL2 components, practice C, and learn the basics of calculating inverse kinematics.
Insipired by the [video](https://www.youtube.com/watch?v=hbgDqyy8bIw&ab_channel=TheCodingTrain) made by "The Coding Train" on YouTube.
## Requirements
Install SDL2  
```bash
sudo apt update && \
sudo apt install \
libsdl2-dev \
libsdl2-image-dev
```
## Build
In the repository base directory, run the `make` command.

## Run
```bash
./ik
```
### Argument options are
1. "--links <number of links>"
2. "--linkslen <pixel length of links>"
