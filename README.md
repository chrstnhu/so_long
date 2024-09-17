# So long

Project 42 school

<img src="https://github.com/user-attachments/assets/f74553d6-f057-44b4-849b-282a77eaaaf0" width="400" />

Create a small 2d game with minilibx
## Functions autorized
* open, close
* read, write
* malloc, free
* perror, strerror
* exit

## Run
Git clone and go to project directory :

```bash
git clone git@github.com:chrstnhu/minishell.git && cd minishell
```

Download minilibx :
```bash
git clone https://github.com/42Paris/minilibx-linux
```

Make :
```bash
make
```

Run so_long :
```bash
./so_long map/test_valid_collectible.ber
```
## Test
* Try differents maps  (so_long/map)
* Try differents textures  (so_long/assets)

## Rules

<details>
  <summary> GAME </summary>

  * Player have to collect all collectible to exit
  * Player move with Keys (W,A,S,D) or (⭡, ⭠, ⭣, ⭢)
  * Player should not be able to move into walls
  * Display the number of move

</details>

<details>
  <summary> GRAPHIC MANAGEMENT </summary>

  * Use minilibx
  * Display the window
  * Close the window with the touch escap(ESC) or the cross ❌

</details>


<details>
  <summary> MAP </summary>

  * Content :
    | Signification | Char |
    |     :---:     | :--: |
    | Empty space | 0 |
    | Wall | 1 |
    | Collectible | C |
    | Exit | E |
    | Player | P |
  * Map must be rectagular
  * Map must be surrounded by walls
  * Chack valid path (player -> collectible -> exit)
  * File name terminating with .ber

</details>

  ### Bonus
* Implement enemy patrol and player lose when he hits an enmey
* Add sprite animation
* Display movement count on the window
