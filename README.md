# so_long

## 📚 About the Project

**so_long** is a 2D graphical game project from the 42 coding school curriculum. The objective is to build a simple tile-based game using a minimal graphics library. The player must navigate a map, collect all items, and reach the exit — all while adhering to strict coding and graphical constraints.

This project is an introduction to basic game development, event handling, map parsing, and graphics programming in C using the **MiniLibX** library.

---

## 🎮 Game Objective

The player controls a character that must:

- Collect all collectibles (`C`)
- Avoid enemies *(bonus)*
- Reach the exit (`E`) only after collecting everything

---

## 🧩 Project Requirements

- Read and parse a map file with the `.ber` extension
- Render a graphical window representing the map grid
- Move the player using keyboard inputs (WASD or arrows)
- Validate map contents and structure (walls, collectibles, exit, start)
- Count and display the number of moves
- Handle game-ending conditions gracefully

---

## 🛠️ How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/so_long.git
   cd so_long
   ```

2. Compile the project:
   ```bash
   make
   ```

3. Run the game with a valid map:
   ```bash
   ./so_long maps/map1.ber
   ```

4. Controls:
   - `W` / `↑` – move up
   - `A` / `←` – move left
   - `S` / `↓` – move down
   - `D` / `→` – move right
   - `ESC` – exit the game

---

## 🗺️ Map Format

The map must be rectangular and consist of the following characters:

- `1` – wall  
- `0` – empty space  
- `P` – player start position  
- `C` – collectible  
- `E` – exit  

A valid map must contain at least one `P`, one `C`, and one `E`, and be fully enclosed by walls.

---

## 🧠 Skills Demonstrated

- Basic 2D game development  
- File and map parsing  
- Event-driven programming and keyboard handling  
- Use of the MiniLibX graphics library  
- Memory management and resource cleanup  
- Validation of user input and map files

---

## 🧪 Bonus Features (if applicable)

- Animations or dynamic elements  
- Enemy AI (patrolling, chasing)  
- Sound effects  
- UI/score display  
- Custom sprites or tilesets  
- Window resize support or fullscreen toggle

---

## 📁 Project Status

✅ Completed – fully functional and compliant with the mandatory requirements.  
🎯 Bonus – additional features implemented *(if applicable)*.

---

## 📫 Contact

Feel free to reach out via [GitHub](https://github.com/Nicolike20) if you have any questions or want to connect.

[![forthebadge](https://forthebadge.com/images/featured/featured-built-with-love.svg)](https://forthebadge.com)
