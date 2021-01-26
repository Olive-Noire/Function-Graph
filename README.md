# Function-Graph
for make a graphic of function

user manual (sorry for my bad english) :
-to change the window size (the script is made to adapt don't worry 😉)
go to line ~ 8 and change the defaults (500p / 500p)

-to modify the precision (the number of points on the curve) go to the loop and for line ~ 23 and modify the increment value (the smaller it is, the more precise the curve will be)

-change the expression of the function go to the end (line ~ 57) in the function f (double x) to modify the value return

now you no longer need a calculator in math class but rather bring your 13 Kilo tower with your RTX 3090 to simulate a curve 😁😉


2 optimisations (1.0.0) : 

-ordonne (verticale) limits (for square function)
-lat point (for decimal number not repassing in point)

compile with gcc (using command in end file)

g++ -m32 ./Sources/*cpp -o bin/Courbe -s -std=c++17 -I include -L lib/ -lSDL2main -lSDL2 -mwindows
