# lemin
Epitech Project, lemin

Subject:

Hex is an elaborate, magic-powered and self-building computer (not unlike the ‘shamble’, a kind of
magical device used by the Witches of the Discworld) and is housed in the basement of the High Energy
Magic Building at the Unseen University (UU) in the twin city of Ankh-Morpork.
Hex is a computer unlike any other. Programmed via ‘Softlore’, Hex runs and evolves under the watchful
eyes of wizard Ponder Stibbons, who becomes the de facto IT manager at UU because he’s the only one
who understands what he’s talking about.
Hex has its origins in a device created by some student Wizards in the High Energy Magic building.
In this form it was simply a complex network of glass tubes, containing ants. The wizards could then
use punched cards to control which tubes the ants could crawl through, enabling it to perform simple
mathematical functions.
https://en.wikipedia.org/wiki/Hex_(Discworld)

Let’s pay close attention to its calculation unit: an anthill with rooms and tunnels. A room can be connected
to an infinite number of other rooms by as many tunnels as needed, but a tunnel can only connect two
rooms.
It would be nice to build one of our own, but since we’re not really into DIY, let’s make a high-tech version:
a “Hex’ calculation unit” simulator.

The rooms’ coordinates will always be whole numbers. Please note that it is possible to insert comments
by using “#” and commands by using “##”.
##start indicates the next room is the anthill entrance, and ##end indicates the next room is the anthill
exit.

Any unknown commands will be ignored.
The objective of your program is to find the quickest way to make the ants cross over the anthill. To do so,
each single ant need to take the shortest route (and not necessarily the easiest), whithout walking on its
peers, and avoiding traffic jams.
At the beginning of the game, all of the ants are in the anthill entrance.
The goal is to lead them to the exit room, in a minimum amount of laps.
Each room could contain a single ant at a time (except ##start and ##end, which can contain as many as
needed).

With each lap, you can move each ant only once by following a tunnel (if the receiving room is clear).
You must show the result on the standard output, in this order: number_of_ants, rooms, tunnels and then
for each lap, a series of Pn-r where n is the number of the ant, and r the name of the room it gets into.
In the output, you must display a comment indicating the part that will follow. These comment must be
exactly like in the examples.

Usage:

./lemin < file

Example:


![alt text](https://raw.githubusercontent.com/alexandre10044/lemin/master/example.png)
