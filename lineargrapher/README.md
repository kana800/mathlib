### User-Interface and Usage

<todo mention graph>
<todo mention coordinate table>
<todo mention plotting>

#### Console Representation

The **coordinates** of the **console** are represented as mentioned below:

```cpp
   tlft   tmid    trgt
   x----------------x
   |       mm       |
   x----------------x
   blft   bmid    brgt
---
tlft -> top left point
tmid -> top mid point
trgt -> top right point
---
mmid -> mid point
---
blft -> bot left point
bmid -> bot mid point
brgt -> bot right point
---
``` 

The **graph** will be **plotted** according to the following **coordinates**. The origin of the **graph** will stand at the point `mmid` and lines will be **plotted/drawn** according to the `XRANGE` and `YRANGE` mentioned in `lineargrapher.h`. The **coordinates** are configured according the size of the console. Check out the function `InitConsoleCoordinates(COORD winsize)`.

The function `InitConsole()` *creates* the console and *initialize* all the necessary variables and the main entry point of the `linear grapher` is the `MainConsole()`. The flowchart below explain algorithm for the `MainConsole()`

<p style="text-align: center" align="center">
  <img src="https://github.com/kana800/mathlib/blob/main/lineargrapher/.images/mainconsole.png" alt="main console">
  <p align="center">
	Quick overview of the MainConsole() algorithm.
  </p>
</p>



---

#### Graph

The graph *drawing* process is handled by the function `drawGraph(COORD winSize)` in `lineargrapher.c`; 

As mentioned about the ranges for the graph are determined by `XRANGE` and `YRANGE`; There are several problems that need to be tackle when dealing with something like this.

- What would happen if the console size is too big and the since the `XRANGE` and `YRANGE` are small wouldnt this make the **graph** drawn much smaller ?
- What would happen if the user changes the size of the console ?

#### User-Input



---

### Parser/Scanner and `Input String`


#### `Input String`

`Input String` is structure that holds information about the user-input;

<p style="text-align: center" align="center">
  <img src="https://github.com/kana800/mathlib/blob/main/lineargrapher/.images/inputstring_t.png" alt="inputstring_t">
  <p align="center">
	Input String Structure
  </p>
</p>

The `input string` structure can be found in [`inputstring.h`](https://github.com/kana800/mathlib/blob/ef69099e4647815fe1bbf44386ec8e268e50fa51/lineargrapher/inputstring.h#L14). 

```c
typedef struct InputString {
	char string[MAXCHARCOUNT]; /*input string*/
	int size; /*current word count*/
	COORD* cursorpos; /*current cursor position*/
} inputstring_t;
```

The attributes `size` and `cursorpos` track the size and current position of the cursor. The `string` attribute holds the **"user input"**, The **`MAXCHARCOUNT`** determines the length of the string, by default it is set to `10`. 


<p style="text-align: center" align="center">
  <img src="https://github.com/kana800/mathlib/blob/main/lineargrapher/.images/inputstring_t_string.png" alt="inputstring_t">
  <p align="center">
	String Variable in Input String
  </p>
</p>

To create the `input string` struct you can use `is_createisstruct(COORD cursorpos)`; This function will create `inputstring_t` struct and initialize the *attributes*: `size` to be `0` and `cursorpos` to be argument `cursorpos`.

when the `is_addChar(inputstring_t* is, char c)` method is called the following process occurs.

<p style="text-align: center" align="center">
  <img src="https://github.com/kana800/mathlib/blob/main/lineargrapher/.images/is_addChar.png" alt="is_addChar">
  <p align="center">
         process for adding character to the input string structure
  </p>
</p>

---

#### Parsing
I thought of getting the user input and then **parsing**  the input and call the appropriate function.
For example if `add (4,3)` was the inputted by the user. It will _add the coordinate_ `(4,3)` _to the table_. To make it easier, I am going to make every method that user needs to input short.

- `add (4,3)` -> add coordinate
- `rmv <idx>` -> removes the coordinate with given index
- `plt <idx1>,<idx2>,<idx3>` -> plots the coordinates represented by the `idx1`, `idx2` and `idx3`

#### `add`


---


### Coordinates, Containers and `Linear-Grapher`

- Coordinate Structure:
```c
coord_t {
	int x;
        int y; 
};
```
This structure holds the coordinates;

- Coordinate Container:
```c
coordcontainer_t {
	coord_t * data; /*points to the coordinate data*/
	struct CoordContainer* next; /*points to the next struct*/
}
```

Coordinate Container is custom data structure that holds all the 
coordinates that the user inputs to the system. 

The **coordinate container** will imitate a **singly linked list**. 
This will allow me to control the size of the data structure the way I prefer.

<details>
<summary>Why not use Variable Length Array ?</summary>

> I simply don't know how many `coord_t` struct the user is going to input
the grapher and `copying` and `allocating` memory again and again when a
certain size limit is reached.

> One option is to let the user input the number of **coordinates** that they
are going to input at the start.

- [More about VLA](https://blog.joren.ga/vla-pitfalls)
- [Notes on VLA and other DS]()
</details>

- Global Container:
The size of the `coordcontainer_t` will be **tracked** by the 
linear grapher `GlobalContainer`. 

```c
GlobalContainer {
	coordcontainter_t* HEAD;
	int size;
} glbcontainer_t;
```

#### Adding a Coordinate to the Container

When user adds a coordinate through the `addcoordinate` (`lineargrapher.h`);
The `CreateCoordinateContainer` in `coordcontainer.h` will create a `coord_t`
typed coordinate and allocate memory for it.

<p style="text-align: center" align="center">
  <img src="https://github.com/kana800/mathlib/blob/main/lineargrapher/.images/addcoordinateflow.png" alt="adding coordinates">
  <p align="center">
	visual representation of the coordinate <i>adding</i> process.
  </p>
</p>

<todo Removing coordinate from the container>
