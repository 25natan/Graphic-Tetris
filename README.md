# SFML Tetris Game
Compile and run - in root directory:
```bash
# Compile using SFML lib and include and generate executable file
g++ -std=c++17 -I<SFML_INCLUDE_PATH> -L<SFML_LIB_PATH> $(ls source/*.cpp) -lsfml-graphics -lsfml-window -lsfml-system -o game
# Run executable file
./game
```

