# Table of contents
* [Public API](#public-api)
  * [Namespace](#namespace-ppc)
  * [Application level](#application-level)
    * [Application](#class-application)
    * [Window](#class-window)
    * [Statusbar](#class-statusbar--public-window)
  * [Window level](#window-level)
    * [Label](#class-label--public-widget)
    * [Button](#class-button--public-widget)
    * [TextInput](#class-textinput--public-widget)
* [Internal workings](#internal-workings)
  * [Widget interface](#class-widget)
  * [Event types](#enum-class-eventtype)
* [Examples](#examples)

# Public API 

## `namespace ppc`
Every class and method is inside this namespace.


### Typedefs
* `typedef void (*callback)()` - interactive Widget callback function pointer type (for Buttons etc.)

## Application level
Windows exist at application level. 

### `class Application`
`Application` is the entry point for any
program using this library. It initializes ncurses and allows for windows to 
be created.

#### Constructors
* `Application()`
#### Public methods
* `shared_ptr<Window> NewWindow(Point position, Point size)`
* `void Draw()`
* `char GetKeyEvents()` - basically calls `wgetch()` on appropriate Window from ncurses
* `Event GetWindowEvents()` - not sure about return type for now
---
### `class Window`
#### Constructors
* `Window(Point position, Point size)` 
#### Public methods
* `template <class T> void AddWidget(T widget)`
* `void SetPosition(Point position)`
* `Point Position()`
* `void SetSize(Point size)`
* `Point Size()`
---
### `class Statusbar : public Window`
This pseudo-window spans the whole screen horizontally but is only 1 row high.
It can contain only plain text Labels. By default rendered with A_REVERSE attribute on (which reverses colors).

#### Enums
* `enum class Position`
  * `Top`
  * `Bottom`
#### Constructors
* `Statusbar()` - defaults to `Position::Bottom`
* `Statusbar(Position pos)`
#### Public methods
* `void AddLabel(Label label)`
* `void Draw()`
#### Public fields
* `Position pos`
---
## Window level
Controls (Label, Button etc.) exist at Window level.

### `class Label : public Widget`
#### Constructors
* `Label(Point position, string text)`
#### Public methods
* `void Draw() final`
#### Public fields
* `Point position`
* `string text`
---
### `class Button : public Widget`
#### Constructors
* `Button(Point position, string text, callback cb)` - not sure about the function pointer signature yet
#### Public methods
* `void Click()`
* `void Draw() final`
#### Public fields
* `Point position`
---
### `class TextInput : public Widget`
#### Constructors
* `TextInput(Point position, string label, callback cb)`
#### Public methods
* `string Text()` - return what user typed in
* `void Draw() final`
* `void Confirm()` - when user presses Enter fire the callback
#### Public fields
* `Point position`

# Internal workings

## Free functions
* `RawWindowDeleter(WINDOW *win)` - custom deleter for `unique_ptr<WINDOW>`
---
## `class Widget`
Abstract class every Widget (Label, Button etc.) inherits from.
### Public methods
* `virtual void Draw()`
---
## `enum class EventType`
Describes an internal event, such as closing current window or quitting the application.
* `AppExit`
* `WindowClose`

# Examples

```c++
#include "application.h" 
#include "window.h"
#include "point.h"
#include "label.h"

using namespace ppc; // or use ppc::Application etc.

int main() {
  Application app; // ncurses initialized here
  Window &win = app.NewWindow(Point(0, 0), Point(16, 10)); // Top left corner, 16x10 cells (x,y)
  Label label(1, 1, "Hello World!");
  win.AddWidget<Label>(label);
  app.Draw(); // Call Draw() once before the event loop to render everything at least once
  while (app.GetKeyEvents() != 'q') {
    app.Draw();
  }
  return 0; // ncurses cleaned up automatically by Application's destructor, guarantees the terminal won't be corrupted
}
```
Output:
```
+------------+
|Hello World!|
|            |
|            |
|            |
|            |
|            |
|            |
|            |
+------------+
```

The program quits after user presses the `q` key.
