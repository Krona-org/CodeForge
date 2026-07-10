#pragma once

class GalloneConverter
{
public:
    GalloneConverter(int nGallons) : numberGallons(nGallons) { 
        cubeFootCapacity(); 
    };
    ~GalloneConverter() {};
    void setGallone(int nGallons) {
        numberGallons = nGallons; 
        cubeFootCapacity();
    };
    int getNumbersOfGallone() {
         return numberGallons; 
    };
    double getCapacityGallone() {
         return capacityGallone; 
    };
    double getTotalCapacity() {
         return totalCapacity; 
    };
private:
    void cubeFootCapacity() {
        totalCapacity = (double)numberGallons / capacityGallone;
    };
    int numberGallons;
    double totalCapacity;
    const double capacityGallone = 7.481;
};