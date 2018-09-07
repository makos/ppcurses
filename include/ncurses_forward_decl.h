#ifndef PPCURSES_NCURSES_FORWARD_DECL_H_
#define PPCURSES_NCURSES_FORWARD_DECL_H_
// The struct name differs between PDCurses (Windows) and ncurses (linux)
#ifdef _WIN32
typedef struct _win WINDOW;
#endif

#ifdef __linux__
typedef struct _win_st WINDOW;
#endif

#endif  // PPCURSES_NCURSES_FORWARD_DECL_H_