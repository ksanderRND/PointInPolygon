#include <iostream>
#include <vector>

using namespace std;

#define eps 0.0001

struct point
{
    double X;
    double Y;
};

typedef vector<point> polygon;


bool isInside(polygon pol, point p);

bool test1();
bool test2();
bool test3_1();
bool test3_2();
bool test3_3();
bool test4();
bool test5_1();
bool test5_2();
bool test6_1();
bool test6_2();

int main() {
    cout<<"Start\n";
    
    cout<<"test1: "<<(test1()? "passed\n":"NOT PASSED!\n");
    cout<<"test2: "<<(test2()? "passed\n":"NOT PASSED!\n");
    cout<<"test3.1: "<<(test3_1()? "passed\n":"NOT PASSED!\n");
    cout<<"test3.2: "<<(test3_2()? "passed\n":"NOT PASSED!\n");
    
    cout<<"test3.3: "<<(test3_3()? "passed\n":"NOT PASSED!\n");
    cout<<"test4: "<<(test4()? "passed\n":"NOT PASSED!\n");
    cout<<"test5.1: "<<(test5_1()? "passed\n":"NOT PASSED!\n");
    cout<<"test5.2: "<<(test5_2()? "passed\n":"NOT PASSED!\n");
    cout<<"test6.1: "<<(test6_1()? "passed\n":"NOT PASSED!\n");
    cout<<"test6.2: "<<(test6_2()? "passed\n":"NOT PASSED!\n");
   
}

bool isInside(polygon pol, point p){

    bool result = false;
    int size = static_cast<int>(pol.size());
    if(size<3) {
        cout<<"\nWarning! The poligon cannot consist of less than three points!\n";
        return false;
    }
    int j = size - 1;
    
    ///checking that point is on the apex
    for (int i = 0; i < size; i++) {
        if (pol[i].X == p.X && pol[i].Y==p.Y) {
            return true;
        }

        /// checking that point on the edge (on the line between apexes)
        if ( (abs( (pol[j].X-pol[i].X)*(p.Y-pol[i].Y) - (p.X-pol[i].X)*(pol[j].Y-pol[i].Y)) <= eps) && ( (p.X<=pol[i].X && p.Y<=pol[i].Y && p.X>=pol[j].X && p.Y>=pol[j].Y) || (p.X<=pol[j].X && p.Y<=pol[j].Y && p.X>=pol[i].X && p.Y>=pol[i].Y) ) ){
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


bool test1(){
    ///Simple triangle, the point is inside
    polygon triangle(3);
    triangle[0] = {-1, -1};
    triangle[1] = {0, 1};
    triangle[2] = {1, -1};
    point p = {0, 0};
    bool inside = (isInside(triangle, p)? true:false);
    return (inside? true:false);
}

bool test2(){
    ///Simple triangle, the point is outside
     polygon triangle(3);
    triangle[0] = {-1, -1};
    triangle[1] = {0, 1};
    triangle[2] = {1, -1};
    point p = {2, 0};
    bool inside = (isInside(triangle, p)? true:false);
    return (inside? false:true);
}

bool test3_1(){
    ///Triangle, the point is on the right edge
    polygon triangle(3);
    triangle[0] = {-2, -1};
    triangle[1] = {0, 1};
    triangle[2] = {2, -1};
    point p = {1, 0};
    bool inside = (isInside(triangle, p)? true:false);
    return (inside? true:false);
}

bool test3_2(){
    ///Triangle, the point is on the left edge
    polygon triangle(3);
    triangle[0] = {-2, -1};
    triangle[1] = {0, 1};
    triangle[2] = {2, -1};
    point p = {-1, 0};
    bool inside = (isInside(triangle, p)? true:false);
    return (inside? true:false);
}

bool test3_3(){
    ///Triangle, the point is on the horizontal edge
    polygon triangle(3);
    triangle[0] = {-2, -1};
    triangle[1] = {0, 1};
    triangle[2] = {2, -1};
    point p = {0, -1};
    bool inside = (isInside(triangle, p)? true:false);
    return (inside? true:false);
}

bool test4(){
    ///Triangle, the point is on the vertex
    polygon triangle(3);
    triangle[0] = {-1, -1};
    triangle[1] = {0, 1};
    triangle[2] = {1, -1};
    point p = {1, -1};
    bool inside = (isInside(triangle, p)? true:false);
    return (inside? true:false);
}

bool test5_1(){
    ///Rhombus, the point is on the level of a vertex inside the figure(the "ray" should come throw the vertex 
    ///     and this test shows that the algorythm works correctly)

    polygon rhombus(4);

    rhombus[0] = {-1, 0};
    rhombus[1] = {0, 1};
    rhombus[2] = {1, 0};
    rhombus[3] = {0, -1};
    point p = {0, 0};

    bool inside = (isInside(rhombus, p)? true:false);
    return (inside? true:false);

}

bool test5_2(){
    ///Rhombus, the point is on the level of a vertex outside the figure(the "ray" should come throw the vertex 
    ///     and this test shows that the algorythm works correctly)

    polygon rhombus(4);
    
    rhombus[0] = {-1, 0};
    rhombus[1] = {0, 1};
    rhombus[2] = {1, 0};
    rhombus[3] = {0, -1};
    point p = {2, 0};

    bool inside = (isInside(rhombus, p)? true:false);
    return (inside? false:true);

}

bool test6_1(){
    ///Concave polygon, (G-letter-figure), the point is in the inner region, but outside the figure

    polygon concave(12);
    concave[0] = {0, 3};
    concave[1] = {4, 5};
    concave[2] = {6, 4};
    concave[3] = {5, 3};
    concave[4] = {4, 4};
    concave[5] = {2, 3};
    concave[6] = {4, 2};
    concave[7] = {6, 2};
    concave[8] = {6, 3};
    concave[9] = {7, 3};
    concave[10] = {7, 1};
    concave[11] = {4, 1};
    
    point p = {4, 3};
    
    bool inside = (isInside(concave, p)? true:false);
    return (inside? false:true);
}

bool test6_2(){
    ///Concave polygon, (G-letter-figure), the point is inside the figure

    polygon concave(12);
    concave[0] = {0, 3};
    concave[1] = {4, 5};
    concave[2] = {6, 4};
    concave[3] = {5, 3};
    concave[4] = {4, 4};
    concave[5] = {2, 3};
    concave[6] = {4, 2};
    concave[7] = {6, 2};
    concave[8] = {6, 3};
    concave[9] = {7, 3};
    concave[10] = {7, 1};
    concave[11] = {4, 1};
    
    
    point p = {1, 3};
    bool inside = (isInside(concave, p)? true:false);
    return (inside? true:false);
}
