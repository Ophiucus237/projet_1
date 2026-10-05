# Journal de développement — mon-rpg

## 2026-09-20 — Jour 0
- Création du repo, GDD, conventions
- Décisions : Godot 4, RPG tour par tour, GPL v3
- Prochaine session : installer Godot, premier sprite

## 2026-09-21 — Jour 1
- Import du projet dans Godot 4
- Input Map configurée (ZQSD/WASD/Flèches)
- Sprite placeholder créé (32x32)
- Scène Player.tscn : CharacterBody2D + Sprite + Collision + Camera
- Script player.gd : déplacement 8 directions + collisions
- Scène TestLevel.tscn : 5 murs + joueur
- Problème rencontré : Godot a écrasé .editorconfig, .gitignore, .gitattributes
  → résolu avec `git restore`
- Commit : `feat(player): déplacement top-down avec collisions`
- Prochaine session : animations (idle/walk), TileMap