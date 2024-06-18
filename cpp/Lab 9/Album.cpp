#include "Album.h"
#include <iostream>

using namespace std;

int Album::totalAlbums = 0;
double Album::totalSales = 0;

Album::Album(string title, const string artist, double price, int copies)
: albumtitle(title), artist(artist), price(price), copiesAvailable(copies) {
    totalAlbums += copies; 
}

void Album::purchaseAlbum() {

    if(totalAlbums > 0){
        totalAlbums--;
        totalSales += price;
        copiesAvailable--;
    } else {
        cout << "Not available" << endl;
    }

}

int Album::getTotalAlbums() {

    return totalAlbums;

}

int Album::getCopiesAvailable(){

    return copiesAvailable;

}

double Album::getTotalSales() {

    return totalSales;
}

string Album::getArtist(){
    return artist;
}

string Album::getTitle(){
    return albumtitle;
}

double Album::getprice(){
    return price;
}