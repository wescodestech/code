#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define PNG_DEBUG 3
#include <png.h>

void abort_( const char * s, ... )
{
    va_list args;
    va_start(args, s);
    vfprintf(stderr, s, args);
    fprintf(stderr, "\n");
    va_end(args);
    abort();
}

int x;
int y;

int width;
int height;
png_byte colorType;
png_byte bitDepth;

png_structp pngPtr;
png_infop infoPtr;
int numOfPasses;
png_bytep * rowPointers;

void ReadPngFile( char* filename )
{
        unsigned char header[8];

        // open file and test for it being a png
        FILE *fp = fopen( filename, "rb" );
        if( !fp )
        {
            abort_( "[ReadPngFile] File %s could not be opened for reading", filename );
        }

        fread( header, 1, 8, fp );
        if( png_sig_cmp( header, 0, 8 ) )
        {
            abort_("[ReadPngFile] File %s is not recognized as a PNG file", filename);
        }

        // Initialize
        pngPtr = png_create_read_struct( PNG_LIBPNG_VER_STRING, NULL, NULL, NULL );

        if( !pngPtr )
        {
            abort_("[ReadPngFile] png_create_read_struct failed");
        }

        infoPtr = png_create_info_struct( pngPtr );
        if( !infoPtr )
        {
            abort_("[ReadPngFile] png_create_info_struct failed");
        }

        if( setjmp( png_jmpbuf( pngPtr ) ) )
        {
            abort_("[ReadPngFile] Error during init_io");
        }

        png_init_io( pngPtr, fp );
        png_set_sig_bytes( pngPtr, 8 );

        png_read_info( pngPtr, infoPtr );

        width = png_get_image_width( pngPtr, infoPtr );
        height = png_get_image_height( pngPtr, infoPtr );
        colorType = png_get_color_type( pngPtr, infoPtr );
        bitDepth = png_get_bit_depth( pngPtr, infoPtr );

        numOfPasses = png_set_interlace_handling( pngPtr );
        png_read_update_info( pngPtr, infoPtr );

        // Read the file
        if( setjmp( png_jmpbuf( pngPtr ) ) )
        {
            abort_( "[ReadPngFile] Error during read_image" );
        }

        rowPointers = (png_bytep*) malloc( sizeof( png_bytep ) * height );
        for( y=0; y < height; ++y )
        {
            rowPointers[y] = (png_byte*) malloc( png_get_rowbytes( pngPtr,infoPtr ) );
        }

        png_read_image( pngPtr, rowPointers );

        fclose( fp );
}

void WritePngFile( char* filename )
{
        /* create file */
        FILE *fp = fopen( filename, "wb" );
        if( !fp )
        {
            abort_( "[WritePngFile] File %s could not be opened for writing", filename );
        }

        // Initialize
        pngPtr = png_create_write_struct( PNG_LIBPNG_VER_STRING, NULL, NULL, NULL );

        if( !pngPtr )
        {
            abort_( "[WritePngFile] png_create_write_struct failed" );
        }

        infoPtr = png_create_info_struct( pngPtr );
        if( !infoPtr )
        {
            abort_( "[WritePngFile] png_create_info_struct failed" );
        }

        if( setjmp( png_jmpbuf( pngPtr ) ) )
        {
            abort_( "[WritePngFile] Error during init_io" );
        }

        png_init_io( pngPtr, fp );
        
        // Write header
        if( setjmp( png_jmpbuf( pngPtr ) ) )
        {
            abort_( "[WritePngFile] Error during writing header" );
        }

        png_set_IHDR( pngPtr, infoPtr, width, height,
                     bitDepth, colorType, PNG_INTERLACE_NONE,
                     PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE );

        png_write_info( pngPtr, infoPtr );


        // write bytes
        if( setjmp( png_jmpbuf( pngPtr ) ) )
        {
            abort_( "[WritePngFile] Error during writing bytes" );
        }

        png_write_image( pngPtr, rowPointers );

        // End write
        if( setjmp( png_jmpbuf( pngPtr ) ) )
        {
            abort_( "[WritePngFile] Error during end of write" );
        }

        png_write_end( pngPtr, NULL );

        // Cleanup heap
        for ( y = 0; y < height; ++y )
        {
            free( rowPointers[y] );
        }
        free( rowPointers );
        fclose( fp );
}


void process_file( void )
{
    if( png_get_color_type( pngPtr, infoPtr ) == PNG_COLOR_TYPE_RGB )
    {
        abort_( "[process_file] input file is PNG_colorType_RGB but must be PNG_colorType_RGBA "
            "( lacks the alpha channel )" );
    }
    
    if( png_get_color_type( pngPtr, infoPtr ) != PNG_COLOR_TYPE_RGBA )
    {
        abort_( "[process_file] colorType of input file must be PNG_colorType_RGBA (%d) (is %d)",
            PNG_COLOR_TYPE_RGBA, png_get_color_type( pngPtr, infoPtr ) );
    }
    
    for( y = 0; y < height; ++y ) 
    {
        png_byte* row = rowPointers[y];
        for ( x = 0; x < width; ++x )
        {
                png_byte* ptr = &( row[x*4] );
                printf( "Pixel at position [ %d - %d ] has RGBA values: %d - %d - %d - %d\n",
                    x, y, ptr[0], ptr[1], ptr[2], ptr[3] );
    
                // set red value to 0 and green value to the blue one
                ptr[0] = 0;
                ptr[1] = ptr[2];
        }
    }
}


int main( int argc, char **argv )
{
    if ( argc != 2 )
            abort_( "Usage: program_name <file_in> <file_out>" );
    
    ReadPngFile( argv[1] );
    process_file();
    // WritePngFile( argv[2] );
    
    return 0;
}
