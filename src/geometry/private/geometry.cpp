#include "geometry.h"
#include <iostream>

bool isInside(Polygon pol, Point p){

    bool result = false;
    int size = static_cast<int>(pol.size());
    if(size<3) {
        std::cout<<"\nWarning! The poligon cannot consist of less than three points!\n";
        return false;
    }
    int j = size - 1;
    
    ///checking that point is on the apex
    for (int i = 0; i < size; i++) {
        if (pol[i].X == p.X && pol[i].Y==p.Y) {
            return true;
        }

        /// checking that point on the edge (on the line between apexes)
        if ( (abs( (pol[j].X-pol[i].X)*(p.Y-pol[i].Y) - (p.X-pol[i].X)*(pol[j].Y-pol[i].Y)) <= eps) 
        && ( (p.X<=pol[i].X && p.Y<=pol[i].Y && p.X>=pol[j].X && p.Y>=pol[j].Y) 
        || (p.X<=pol[j].X && p.Y<=pol[j].Y && p.X>=pol[i].X && p.Y>=pol[i].Y) ) ) {
	 	    return true;
	    }
	 
        ///Calculating the crossed edges. If number of crosses odd then inside, otherwise - outside
        if ( (pol[i].Y < p.Y && pol[j].Y >= p.Y || pol[j].Y < p.Y && pol[i].Y >= p.Y) &&
             (pol[i].X + (p.Y - pol[i].Y) / (pol[j].Y - pol[i].Y) * (pol[j].X - pol[i].X) < p.X) ) {
	            result = !result; 
        	}
        	j = i;
        }
    
    return result;
}