# Working with the DueVGA Library

### Links
- [DueVGA Github Repo](https://github.com/stimmer/DueVGA/tree/master/VGA)
- [Stimmer's Project Website](https://stimmer.github.io/DueVGA/)


### Custom Shapes


### Locally Erasing
When working with the DueVGA library, I noticed that I was unable to perform fast animations without heavy flickering. It seems like it took longer to fill shapes than it did to draw a frame. Because of this, I started to explore animating in different ways, namely locally erasing and redrawing (rather than redrawing the entire frame).

**CURSOR EXAMPLE**
Essentially, create an array which stores the 'shape' of a cursor. Then, create a second 'buffer' array of the same size. 
```
int cursor_size = 9; //should be an odd number
// shape of a 10x10 px cursor
int cursor_1[9][9] = { 
  {0,0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0,0},
  {1,1,1,1,1,1,1,1,1},
  {0,0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0,0} };

// store what the cursor covered so that you can redraw it once the cursor moves
int cursor_buffer[9][9];

void draw_cursor (int x, int y) {
  // horizontal
  for(int i = 0; i<cursor_size; i++){
    // vertical
    for(int j = 0; j<cursor_size; j++) {
      //draw cursor
      VGA.drawPixel(x-4+i,y-4+j,cursor_1[i][j]);
    }
  }
}

void fill_cursor_buffer (int x, int y) {
  for(int i = 0; i<cursor_size; i++){
    for(int j = 0; j<cursor_size; j++) {
      //fill cursor buffer
      cursor_buffer[i][j] = VGA.getPPixelFast(x-4+i,y-4+j);
    }
  }
}
```
In the code, fill the buffer where you want to fil

*Limitations*: For now, it 1) draws over everything within the area of the array (not "transparent") and 2) with just one buffer array you need to move the cursor at least one cursor-width in any direction.

- **REDRAW LINE EXAMPLE**
