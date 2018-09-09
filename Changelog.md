# Changelog
## 0.3.0 (WIP)
* Widgets
  * `widget.hpp` - interface, mediator between derived Widgets and Window
  * `label.hpp` - basic Label (read-only text) Widget
* `application.hpp`
  * Alias `WindowPtr = std::shared_ptr<Window>`
* `window.hpp`
  * Change `AddWidget` to use variadic template 
  * Alias `WidgetPtr = std::shared_ptr<Widget>`
## 0.2.0
* `application.hpp`
  * Change return type of `NewWindow` from `Window &` to `shared_ptr<Window>`
* `window.hpp`
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
