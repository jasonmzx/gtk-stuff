
#include <iostream> 

#include "headertest/uwu.h"

#include <gtk/gtk.h>

// https://imagemagick.org/Magick++/tutorial/Magick++_tutorial.pdf
#include <Magick++.h> 


// this or add Magick:: to everything
using namespace Magick; 




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

    crop_image("gawr.jpg", "output.png", 200, 200, 200, 200);

    uwu();

    app = gtk_application_new ("org.gtk.exampcvle", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}