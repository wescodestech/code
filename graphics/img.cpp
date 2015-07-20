/* displays an image or sets root background
 *
 * gcc -Wall -W -g3 -o xrootbg xrootbg.c -lX11 -lImlib2
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <Imlib2.h>

int main(int argc, char **argv)
{
    Imlib_Image img;
    Display *dpy;
    Pixmap pix;
    Window root;
    Screen *scn;
    int width, height;
    const char *filename = NULL;
    GC gc;

    if (argc < 2)
    {
        fprintf(stderr, "usage: %s <image_file>\n", argv[0]);
        return 1;
    }
    filename = argv[1];

    img = imlib_load_image(filename);
    if (!img) {
        fprintf(stderr, "%s:Unable to load image\n", filename);
        fprintf(stderr, "usage: %s <image_file>\n", argv[0]);
        return 1;
    }
    imlib_context_set_image(img);
    width = imlib_image_get_width();
    height = imlib_image_get_height();

    dpy = XOpenDisplay(NULL);
    if (!dpy)
        return 0;
    scn = DefaultScreenOfDisplay(dpy);
    root = DefaultRootWindow(dpy);

    pix = XCreatePixmap(dpy, root, width, height,
        DefaultDepthOfScreen(scn));

    XSelectInput( dpy, root, ExposureMask|ButtonPressMask|KeyPressMask );
    gc = XCreateGC( dpy, root, 0, 0 );
//    XSetBackground( dpy, gc, white );
//    XSetForeground( dpy, gc, black );
    XClearWindow( dpy, root );
    XMapRaised( dpy, root );

    imlib_context_set_display(dpy);
    imlib_context_set_visual(DefaultVisualOfScreen(scn));
    imlib_context_set_colormap(DefaultColormapOfScreen(scn));
    imlib_context_set_drawable(pix);

    imlib_render_image_on_drawable(0, 0);
    XSetWindowBackgroundPixmap(dpy, root, pix);
    XClearWindow(dpy, root);

    while (XPending(dpy)) {
        XEvent ev;
        XNextEvent(dpy, &ev);
    }

    XEvent event;
    char text[255];
    KeySym key;
    while( 1 )
    {
                /* get the next event and stuff it into our event variable.
                   Note:  only events we set the mask for are detected!
                */
                XNextEvent( dpy, &event );

                if (event.type==Expose && event.xexpose.count==0)
                {
                        /* the window was exposed redraw it! */
                        XClearWindow( dpy, root );
                }
                if (event.type==KeyPress&&
                    XLookupString(&event.xkey,text,255,&key,0)==1)
                {
                /* use the XLookupString routine to convert the invent
                   KeyPress data into regular text.  Weird but necessary...
                */
                        if (text[0]=='q') {
                                XFreeGC( dpy, gc );
                                XDestroyWindow( dpy, root );
                                XCloseDisplay( dpy );
                                exit( 1 );
                        }
                        printf("You pressed the %c key!\n",text[0]);
                }
                if (event.type==ButtonPress) {
                /* tell where the mouse Button was Pressed */
                        int x=event.xbutton.x;
                        int y=event.xbutton.y;

                        strcpy(text,"X is FUN!");
                        XSetForeground( dpy, gc, rand()%event.xbutton.x%255 );
                        XDrawString( dpy, root, gc, x, y, text, strlen(text) );
                }
        }
    return 0;
}
