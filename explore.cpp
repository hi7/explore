#include "explore.hpp"

using namespace blit;

enum Direction { NE = 0, SE = 1, SW = 2, NW = 3 };

void init() {
    set_screen_mode(ScreenMode::hires);
}

bool isNorth(const Direction d) {
    return d == NE || d == NW;
}
bool isEast(const Direction d) {
    return d == NE || d == SE;
}
bool isSouth(const Direction d) {
    return d == SE || d == SW;
}
bool isWest(const Direction d) {
    return d == NW || d == SW;
}

/**
 * Draw text to surface using the specified font and the current pen.
 *
 * \param message Text to draw
 * \param p Point to align text to
 * \param d Direction of speech bubble
 */
void say(std::string_view message, const Point &p, const Direction d = NE) {
    int32_t width = message.length() * 6;
    int32_t height = 15;
    screen.pen = Pen(255, 255, 255);
    screen.rectangle(Rect(p.x + (isEast(d) ? +2 : -width -2), p.y + (isNorth(d) ? -16 : +2) , width, height));
    screen.rectangle(Rect(p.x + (isEast(d) ? +2 : -3), p.y + (isNorth(d) ? -2 : +1), 2, 2));
    screen.rectangle(Rect(p.x + (isEast(d) ? +1 : -1), p.y + (isNorth(d) ? -1 : 0), 1, 2));
    screen.pixel(Point(p.x, p.y));

    screen.pen = Pen(0, 0, 0);
    screen.pixel(Point(p.x +(isEast(d) ? width +1 : -width -2), p.y + (isNorth(d) ? -2 : +2)));
    screen.pixel(Point(p.x + (isEast(d) ? width+1 : -3), p.y + (isNorth(d) ? -16 : +16)));
    screen.pixel(Point(p.x + (isEast(d) ? +2 : -width-2), p.y + (isNorth(d) ? -16 : +16)));

    screen.text(message, minimal_font, Point(p.x + (isEast(d) ? +8 : -width +3), p.y + (isNorth(d) ? -12 : +6)));
}

///////////////////////////////////////////////////////////////////////////
//
// render(time)
//
// This function is called to perform rendering of the game. time is the 
// amount if milliseconds elapsed since the start of your game
//
void render(uint32_t time) {
    // clear the screen -- screen is a reference to the frame buffer and can be used to draw all things with the 32blit
    screen.clear();

    // draw some text at the top of the screen
    screen.alpha = 255;
    screen.mask = nullptr;
    say("hello mortal", Point(160, 120), NE);
}

///////////////////////////////////////////////////////////////////////////
//
// update(time)
//
// This is called to update your game state. time is the 
// amount if milliseconds elapsed since the start of your game
//
void update(uint32_t time) {
}