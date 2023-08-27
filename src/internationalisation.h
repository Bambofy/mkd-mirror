// internationalisation.h
// InternationaliZation Dependances
#include <libintl.h>
#include <locale.h>

//~ For lazy developers only ;)
#define _(STRING)  gettext(STRING)
// ( La dernière ligne permet d'alléger le code. )

/* Ces inclusions suivantes sont à faire dans le fichier source, 
// celui qui contient votre int main( int argc, char * argv[] ) ?
// Par la suite, il faut instancier GetText :
    // Internationalization Initialization 
    // i18n: initializes the entire current locale of the program as per environment variables set by the user
    setlocale( LC_ALL, "" );    
    // i18n: Indicate the path of the i18n catalog file
    bindtextdomain( "mkd", "/usr/share/locale" );    
    // i18n: sets the message domain
    textdomain( "mkd" );
*/
// Ces dernières lignes lignes vont appeler le catalogue de traduction 
// dans /usr/share/locale, et appeler la section mkd de ce catalogue.
