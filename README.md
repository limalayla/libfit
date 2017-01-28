# libfit
C++ Library For CLI GUI, File Management And Other Cool Things

It is far from finished, but here is an overview of the current look and target of the library:


```c++
#include "../src/core/app.hpp"
#include "../src/ui/flabel.hpp"
//#include <libfit/all>

using namespace fit;

int main(int argn, char* argv[])
{
	// Create the app
    App ex(argn, argv);

	// Extract UI to perform action on it directly
    UI& console = ex.ui();

    // Adding widgets
    console.add("rect1" , new FWidget(FRect(0, 0, 3, 10), &console));
    console.add("rect2" , new FWidget(FRect(0, 50, 10, 50), &console));
    console.add("label1", new FLabel("hello world!", FRect(10, 2, 5, 7), &console));

    // Accessing a widget of the ui
    console["rect2"]->initPattern(FPattern::test);
  //console["rect1"]->hide();

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
|                                                 *****************************|
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


## Documentation
Documentation is done with doxygen. In order to generate the documentation, just place yourself in the library's root directory, and execute `doxygen`. Documentation will be generated in the `doc/` directory.


###### New:
* Input handled with its own thread, pushing key sstrokes to a list of events
* UI thread too, refreshing itself every now and then
* Parent - son relation in UI


###### Previous:
* Documentation of every core classes
* Renamed height and width into row and col in fmatrix.hpp
* Implemented Strings List and used it in App
* Lots and lots of code cleaning


###### ToDo:
* Redefine usefulness of a member grid is really useful for every widgets since the ui takes a copy of it
* Multi - thread support
* Evenements logic
* UI : Inputs
       Lists
* Implement Trees
* Documentation with doxygen
* Inherit exception classes
* Add z-axis behavior
* Refresh UI only when changed
* More generic handling of events
* Cleaner refresh (console write)


###### Bugs:
* Tools::keyFromValue randomly throwing segmentation faults (haven't reproduced since some time)
* Open an issue if you see any!
