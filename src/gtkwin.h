#define UI_COMMAND (1 << 0)
#define UI_SCROLLS (1 << 1)
#define UI_MENUS   (1 << 2)
#define UI_FULLSCREEN (1 << 3)

void set_ui_elements(int mask);
