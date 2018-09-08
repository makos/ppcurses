# Changelog
## 0.3.0 (WIP)
* Widgets
  * `widget.h` - interface, mediator between derived Widgets and Window
  * `label.h` - basic Label (read-only text) Widget
* `application.h`
  * Alias `WindowPtr = std::shared_ptr<Window>`
* `window.h`
  * Change `AddWidget` to use variadic template 
  * Alias `WidgetPtr = std::shared_ptr<Widget>`
## 0.2.0
* `application.h`
  * Change return type of `NewWindow` from `Window &` to `shared_ptr<Window>`
* `window.h`
  * Change protected `position` and `size` fields to private members
  * Use custom deleter `RawWindowDeleter` for `unique_ptr<WINDOW> curses_win_`
  * Trivial methods are now `inline`
## 0.1.0
* [Design draft](design_draft.md)
* Working prototype:
  * Application class handling:
    * Window creation
    * Keyboard input (delegates to the top-most Window)
  * Utility Point class
