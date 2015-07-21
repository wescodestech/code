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

Display* dpy;
Pixmap pix;
Screen* scn;
Window root;
GC gc;

Imlib_Image img;

// Define some X functions
bool InitX( int a_width, int a_height );
bool InitImlib( const char* a_filename, int& a_width, int& a_height );
void CloseX();
void EventLoop();
void Redraw();

int main(int argc, char **argv)
{
    int width;
    int height;
    const char* filename = NULL;

    if (argc < 2)
    {
        fprintf(stderr, "usage: %s <image_file>\n", argv[0]);
        return 1;
    }
    filename = argv[1];

    if( !InitImlib( filename, width, height ) )
    {
        fprintf( stderr, "Could not init imlib.\n" );
        return 1;
    }

    if( !InitX( width, height ) )
    {
        fprintf( stderr, "Could not init X.\n" );
    }

    EventLoop();

    return 0;
}

bool InitX( int a_width, int a_height )
{
    dpy = XOpenDisplay( NULL );
    if ( !dpy )
    {
        return false;
    }

    scn = DefaultScreenOfDisplay( dpy );
    root = DefaultRootWindow( dpy );

    pix = XCreatePixmap( dpy, root, a_width, a_height, DefaultDepthOfScreen(scn) );

    XSelectInput( dpy, root, ExposureMask|ButtonPressMask|KeyPressMask );
    gc = XCreateGC( dpy, root, 0, 0 );
    XClearWindow( dpy, root );
    XMapRaised( dpy, root );

    imlib_context_set_display( dpy );
    imlib_context_set_visual( DefaultVisualOfScreen( scn ) );
    imlib_context_set_colormap( DefaultColormapOfScreen( scn ) );
    imlib_context_set_drawable( pix );

    imlib_render_image_on_drawable( 0, 0 );
    XSetWindowBackgroundPixmap( dpy, root, pix );
    XClearWindow( dpy, root );

    while( XPending( dpy ) )
    {
        XEvent ev;
        XNextEvent( dpy, &ev );
    }
    return true;
}

bool InitImlib( const char* a_filename, int& a_width, int& a_height )
{
    img = imlib_load_image( a_filename );
    if ( !img ) {
        fprintf(stderr, "%s:Unable to load image\n", a_filename);
        return false;
    }
    imlib_context_set_image( img );
    a_width = imlib_image_get_width();
    a_height = imlib_image_get_height();
    return true;
}

void EventLoop()
{
    XEvent event;
    char text[255];
    KeySym key;
    while( 1 )
    {
        // get the next event and stuff it into our event variable.
        // Note:  only events we set the mask for are detected!
        XNextEvent( dpy, &event );

        if( event.type==Expose && event.xexpose.count==0 )
        {
            // The window was exposed redraw it!
            Redraw();
        }
        if( event.type==KeyPress &&
            XLookupString(&event.xkey,text,255,&key,0)==1 )
        {
            // Use the XLookupString routine to convert the invent
            // KeyPress data into regular text.  Weird but necessary...
            if (text[0]=='q')
            {
                CloseX();
            }
            else
            {
                printf("You pressed the %c key!\n",text[0]);
            }
        }
        if (event.type==ButtonPress)
        {
            // Tell where the mouse Button was Pressed
            int x=event.xbutton.x;
            int y=event.xbutton.y;

            strcpy(text,"X is FUN!");
            XSetForeground( dpy, gc, rand()%event.xbutton.x%255 );
            XDrawString( dpy, root, gc, x, y, text, strlen(text) );
        }
    }
}

void CloseX()
{
    XFreeGC( dpy, gc );
    XDestroyWindow( dpy, root );
    XCloseDisplay( dpy );
    exit( 1 );
}

void Redraw()
{
    XClearWindow( dpy, root );
}
