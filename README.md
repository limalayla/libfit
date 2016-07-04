# libfit
C++ Library For CLI GUI, File Management And Other Cool Things

It is far from finished, but here is an overview of the current look and target of the library:


```c++
#include <libfit/all>

using namespace fit;

int main(int argn, char* argv[])
{
	// Create the app
    App ex(argn, argv);

	// Extract the ui, to perform action on it directly
    UI& console = ex.ui();

    // Adding widgets
    console.add("rect1" , new FWidget(FRect(0, 0, 3, 10)));
    console.add("rect2" , new FWidget(FRect(0, 50, 10, 50)));
    console.add("label1", new FLabel("hello world!", FRect(10, 2, 5, 7)));

    // Accessing a widget of the ui
    console["rect2"]->initPattern(FPattern::test);
  //console["rect1"]->hide();

    // Accessing directly the char grid
    console[5][2] = 'y';
    console[5][3] = 'a';
    console[5][4] = 'y';

    // Temporary workaround just to see a ui displayed
    // (The ui is supposed to update and display itself on its own)
	console.display();

	// Debug
    std::cout << console["label1"]->toString() << std::endl;
    std::cout << console.toString() << std::endl;

	// The app has a state, settable by the user
    return ex.state();
}
```

which produce the following:

```
+------------------------------------------------------------------------------+
|+--------+                                       *****************************|
||        |                                       *****************************|
|+--------+                                       *****************************|
|                                                 *****************************|
| yay                                             *****************************|
|                                                 *****************************|
|                                                 *****************************|
|                                                 *****************************|
|                                                 *****************************|
| hello w                                         *****************************|
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
+------------------------------------------------------------------------------+

FLabel {text= "hello world!", FWidget {FRect {h= 5, w= 7, FVec2 {x= 9, y= 1, FObject {11 [0x9efdc0]}}}}}
UI {nbWidgets= 3, FRect {h= 24, w= 80, FVec2 {x= 0, y= 0, FObject {8 [0x7ffe86902628]}}}}
0
```

This library is aimed to linux cli users, but should be cross-platform.


## Installation
Installation is done with cmake. So as usual, after having cloned the repo:
```bash
mkdir build && cd $_
cmake ..
make # To build the library and examples in the project (under the src and test subfolders of build)
# Or
sudo make install # To build then install the library and headers in the right place
```


###### ToDo:
* Redefine usefulness of a member grid is really useful for every widgets since the ui takes a copy of it
* Multi - thread support
* Evenements logic
* UI : Inputs
       Lists


###### New:
* Switched the build system from handmade makefile to cmake
* New Presentation


###### Previous:
* Implemented nodes (to be used by tree and linked lists)


###### Bugs:
* Nothing atm. Open an issue if you see any!
