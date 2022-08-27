//Standard IO(s)
#include <iostream> 
#include <cstdio>

#include "headertest/uwu.h"

#include <gtk/gtk.h>

// https://imagemagick.org/Magick++/tutorial/Magick++_tutorial.pdf
#include <Magick++.h> 


//X11 to screenshot:
#include <X11/Xlib.h>
#include <X11/X.h>


//C_mag
#include "headers/CImg.h"

// this or add Magick:: to everything
using namespace Magick; 
using namespace cimg_library;


// Geometry::Geometry(unsigned int x, unsigned int y);
// Geometry::Geometry(const String& geometry);
// // examples:
// Geometry g1(100,200);   // numeric constructor
// Geometry g2(“300x400”); // string constructor
static int crop_image(std::string input, std::string output, Geometry g)
{
    // Construct the image object. Seperating image construction from the 
    // the read operation ensures that a failure to read the image file 
    // doesn't render the image object useless. 
    Image image;
    try { 
        // Read a file into image object 
        image.read( input );

        // Crop the image to specified size (width, height, xOffset, yOffset)
        image.crop( g );

        // Write the image to a file 
        image.write( output ); 
    } 
    catch( Exception &error_ ) 
    { 
        std::cout << "Caught exception: " << error_.what() << std::endl; 
    } 
}

static int crop_image(std::string input, std::string output, int x, int y, int width, int height)
{
    return crop_image(input, output, Geometry(x, y, width, height));
}







static void activate (GtkApplication* app, gpointer user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Nyah UWU");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  gtk_widget_show_all (window);
  
}



int main (int    argc, char **argv)
{
    InitializeMagick(*argv);
    GtkApplication *app;
    int status;

    Display *display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(display);

   XWindowAttributes gwa;

   XGetWindowAttributes(display, root, &gwa);
   int width = gwa.width;
   int height = gwa.height;

   XImage *image = XGetImage(display,root, 0,0 , width,height,AllPlanes, 2);

   unsigned char *array = new unsigned char[width * height * 3];

   unsigned long red_mask = image->red_mask;
   unsigned long green_mask = image->green_mask;
   unsigned long blue_mask = image->blue_mask;

   for (int x = 0; x < width; x++)
      for (int y = 0; y < height ; y++)
      {
         unsigned long pixel = XGetPixel(image,x,y);

         unsigned char blue = pixel & blue_mask;
         unsigned char green = (pixel & green_mask) >> 8;
         unsigned char red = (pixel & red_mask) >> 16;

         array[(x + width * y) * 3] = red;
         array[(x + width * y) * 3+1] = green;
         array[(x + width * y) * 3+2] = blue;
      }

   CImg<unsigned char> pic(array,width,height,1,3);
   pic.save_png("blah.png");

   printf("%ld %ld %ld\n",red_mask>> 16, green_mask>>8, blue_mask);



    crop_image("gawr.jpg", "output.png", 200, 200, 200, 200);

    uwu();

    app = gtk_application_new ("org.gtk.exampcvle", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}