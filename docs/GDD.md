# GDD — [Nom du jeu]

## Pitch
[Protagoniste] doit [objectif] en [contexte], mais [obstacle]. Le jeu se distingue par [mécanique/ton unique].

## Genre
Action-RPG, side-scroller

## Plateforme
PC (Windows)

## Durée visée
~5h, linéaire?, fin unique?, embranchements?, fins multiples?

## Boucle de gameplay
Exemple : Explorer → parler aux PNJ → combattre → progresser → boss final

## Mécaniques principales
Exemple, à changer :
- Déplacement top-down (flèches/ZQSD)
- Interaction (Espace/E)
- Combat tour par tour : Attaquer / Compétence / Objet / Fuir
- Inventaire simple
- Sauvegarde (1 slot) : Points de sauvegarde

## Contrôles
- **Déplacement** : ZQSD / WASD / Flèches (via Input Map Godot, touches physiques)
- **Interagir** : E / Espace (à implémenter)
- **Menu** : Échap (à implémenter)
- **Valider** : Entrée / Espace (à implémenter)

## État d'avancement
- ✅ Déplacement top-down avec collisions (Jour 1)
- ⬜ PNJ et dialogues
- ⬜ Combat tour par tour
- ⬜ Inventaire
- ⬜ Sauvegarde
- ⬜ Contenu (village, donjon, boss)
- ⬜ Polish et build

## Mécanique signature — Fuite contextuelle
Chaque ennemi (ou type d'ennemi) a une condition de fuite spécifique.
Fuir n'est pas un bouton "hasard" : c'est une action stratégique.

Exemples (à affiner) :
- Loup : fuir réussit si tu as un objet "viande" dans l'inventaire
- Bandit : fuir réussit si tu as moins de 50% PV (il te croit faible)
- Slime : fuir réussit toujours mais te fait perdre un objet
- Boss : fuir est impossible, sauf à un moment précis du combat

Conséquences :
- La fuite consomme un tour
- La fuite peut échouer → tour perdu
- Certaines fuites donnent un bonus (objet, information, réputation)
- Le joueur doit APPRENDRE les conditions (via essais, PNJ, indices)

## Contenu minimal (MVP)
- 5-10 zones
- 3 types d'ennemis + 1 boss
- Une dizaine de PNJ avec 2-3 dialogues
- 1 quête principale + 3 quêtes secondaires
- 2-3 armes (minimum)
- 2-3 armures (minimum)
- 2-3 pouvoirs (minimum)

## Ce que je NE fais PAS (anti-scope-creep)
- Pas de monde ouvert
- Pas de crafting
- Pas de classes multiples
- Pas de musique originale (assets libres)
- Pas de multijoueur
- Pas d'Action-RPG temps réel (pour ce jeu)

## Assets
Pixel art gratuit (Kenney, itch.io, OpenGameArt)
→ j'apprendrai le pixel art en parallèle

## Inspirations
Cave Story, Undertale, Mario & Luigi series, Swordigo, Magic Rampage