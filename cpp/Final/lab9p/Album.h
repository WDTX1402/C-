#ifndef ALBUM_H
#define ALBUM_H
#include <string>

using namespace std;
class Album {
    private:
        string albumtitle;
        string artist;
        double price;
        int copiesAvailable;

        static int totalAlbums;
        static double totalSales;
    
    public:
        Album(const string title, const string artist, double price, int copies);
        void purchaseAlbum();
        static int getTotalAlbums();
        static double getTotalSales();
        int getCopiesAvailable();
        string getArtist();
        string getTitle();
        double getprice();

};
#endif