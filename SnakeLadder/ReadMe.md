Low Level Design for Snake and Ladder game

Requirements:
1. Create a snake and ladder application
2. The application should take input 'n' from the user. Where nXn is the board size.
3. snakes and ladders are placed randomly on board. Number of snake and ladder will be provided y client.
4. Players can be extended.
5. Dice also can be extended.
6. The game should continue till there are at least 2 players in the game.
7. Snake and ladder should not create a cycle.

Following oibjects are needed:
1. Snale and Ladder : Although two different objects but both does the same job. Position of player will jump to new position. So, will call out this as Jump class
2. cell
3. Board
4. Dice
5. Player
6. Game
7. Utility class to generate the random position.
