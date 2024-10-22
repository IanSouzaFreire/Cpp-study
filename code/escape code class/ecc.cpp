#include <iostream>
#include <cstdint>
#include <unistd.h>

struct Position {
  int x;
  int y;
};

typedef struct Position position_t;

class Terminal {
public:
  ~Terminal() {
    reset_attributes();
  }

  // Erase from cursor to end of screen
  void erase_to_end() {
    printf("\x1b[0J");
  }

  // Erase from cursor to end of the line
  void erase_to_line_end() {
    printf("\x1b[0K");
  }

  // Erase from cursor to beginning of screen
  void erase_to_begin() {
    printf("\x1b[1J");
  }

  // Erase from cursor to beginning of the line
  void erase_to_line_begin() {
    printf("\x1b[1K");
  }

  // Erase entire screen
  void erase() {
    printf("\x1b[2J");
  }

  // Erase current line
  void erase_line() {
    printf("\x1b[2K");
  }

  // Move the cursor up by n lines
  void go_up(const int& n = 1) {
    printf("\x1b[%dA", n);
  }

  // Move the cursor down by n lines
  void go_down(const int& n = 1) {
    printf("\x1b[%dB", n);
  }

  // Move the cursor down by n lines
  void go_right(const int& n = 1) {
    printf("\x1b[%dC", n);
  }

  // Move the cursor left by n lines
  void go_left(const int& n = 1) {
    printf("\x1b[%dD", n);
  }
  
  void hide_cursor() {
    printf("\x1b[?25l");
  }
  
  void show_cursor() {
    printf("\x1b[?25h");
  }
  
  // Set screen type
  void set_graphics(int n = 19) {
    printf("\x1b[=%dh", n);
  }
  
  // Set background based on RGB values
  void set_bg(uint8_t r, uint8_t g, uint8_t b) {
    printf("\x1b[48;2;%d;%d;%dm", r, g, b);
  }
  
  // Set foreground based on RGB values
  void set_fg(uint8_t r, uint8_t g, uint8_t b) {
    printf("\x1b[38;2;%d;%d;%dm", r, g, b);
  }
  
  // Move cursor to a specific position
  void move_to(const int& x, const int& y) {
    printf("\x1b[%d;%dH", y, x);
  }
  
  // Clear the entire screen
  void clear_screen() {
    printf("\x1b[2J");
  }
  
  // Clear the current line
  void clear_line() {
    printf("\x1b[2K");
  }
  
  // Set bold text
  void set_bold() {
    printf("\x1b[1m");
  }
  
  // Reset all attributes
  void reset_attributes() {
    printf("\x1b[0m");
  }
  
  // Set text to italic
  void set_italic() {
    printf("\x1b[3m");
  }
  
  // Set text to underline
  void set_underline() {
    printf("\x1b[4m");
  }
  
  // Set strikethrough text
  void set_strikethrough() {
    printf("\x1b[9m");
  }
  
  // Set foreground color using 8-bit color
  void set_fg_color_8bit(int color) {
    printf("\x1b[38;5;%dm", color);
  }
  
  // Set background color using 8-bit color
  void set_bg_color_8bit(int color) {
    printf("\x1b[48;5;%dm", color);
  }
  
  // Save current cursor position
  void save_cursor() {
    printf("\x1b[s");
  }
  
  // Restore saved cursor position
  void restore_cursor() {
    printf("\x1b[u");
  }
  
  // Enable line wrapping
  void enable_line_wrap() {
    printf("\x1b[?7h");
  }
  
  // Disable line wrapping
  void disable_line_wrap() {
    printf("\x1b[?7l");
  }

  // Function to enable mouse tracking
  void enable_mouse_tracking() {
    printf("\x1b[?1003h"); // Enable mouse tracking (button and motion)
    fflush(stdout);
  }

  // Function to disable mouse tracking
  void disable_mouse_tracking() {
    printf("\x1b[?1003l"); // Disable mouse tracking
    fflush(stdout);
  }

  // Function to get mouse position
  position_t get_mouse_pos() {
    char buf[32];
    int x = -1, y = -1;

    // Enable mouse tracking
    enable_mouse_tracking();

    // Read mouse events
    while (true) {
        if (read(STDIN_FILENO, buf, 1) != 1) break; // Read one byte

        // Check for mouse event
        if (buf[0] == '\x1b') {
            if (read(STDIN_FILENO, buf + 1, 2) == 2) {
                // Check for mouse report format
                if (buf[1] == '[' && (buf[2] == 'M' || buf[2] == 'm')) {
                    // Mouse event detected; extract x and y
                    int button = buf[3] - 32; // Button state
                    x = buf[4] - 32; // X coordinate
                    y = buf[5] - 32; // Y coordinate
                    break; // Exit loop after reading mouse position
                }
            }
        }
    }

    disable_mouse_tracking();

    position_t ret;

    if (x != -1 && y != -1) {
      ret = { x, y };
      return ret;
    }

    ret = { -1, -1 };
    return ret; // Error in getting position
  }
};

int main(void) {
  Terminal term;
  
  term.set_graphics(19);

  term.set_fg(0, 255, 0);
  term.set_bold();
  std::cout << "Hello World in Bold Green\n";
  term.reset_attributes();

  term.set_fg(255, 0, 0);
  std::cout << "Hello World in Red\n";
  term.reset_attributes();

  // Style is reset automatically when object is destroyed ;)
  return 0;
}