#include <iostream>

#include "geometry.h"

bool test1();
bool test2();
bool test3();
bool test4();
bool test5_1();
bool test5_2();
bool test6_1();
bool test6_2();

int main() {
    std::cout<<"Start\n";
    
    std::cout<<"test1: "<<(test1()? "passed\n":"NOT PASSED!\n");
    std::cout<<"test2: "<<(test2()? "passed\n":"NOT PASSED!\n");
    std::cout<<"test3.3: "<<(test3()? "passed\n":"NOT PASSED!\n");
    std::cout<<"test4: "<<(test4()? "passed\n":"NOT PASSED!\n");
    std::cout<<"test5.1: "<<(test5_1()? "passed\n":"NOT PASSED!\n");
    std::cout<<"test5.2: "<<(test5_2()? "passed\n":"NOT PASSED!\n");
    std::cout<<"test6.1: "<<(test6_1()? "passed\n":"NOT PASSED!\n");
    std::cout<<"test6.2: "<<(test6_2()? "passed\n":"NOT PASSED!\n");
   
}

bool test1(){
    std::cout<< "Simple triangle, the point is inside\n";
    Polygon triangle(3);
    triangle[0] = {-1, -1};
    triangle[1] = {0, 1};
    triangle[2] = {1, -1};
    Point p = {0, 0};
    bool inside = (isInside(triangle, p)? true:false);
    return (inside? true:false);
}

bool test2(){
    std::cout<< " Simple triangle, the Point is outside\n";
    Polygon triangle(3);
    triangle[0] = {-1, -1};
    triangle[1] = {0, 1};
    triangle[2] = {1, -1};
    Point p = {2, 0};
    bool inside = (isInside(triangle, p)? true:false);
    return (inside? false:true);
}

bool test3(){
    std::cout<< "Triangle, the Point is on the horizontal edge\n";
    Polygon triangle(3);
    triangle[0] = {-2, -1};
    triangle[1] = {0, 1};
    triangle[2] = {2, -1};
    Point p = {0, -1};
    bool inside = (isInside(triangle, p)? true:false);
    return (inside? true:false);
}

bool test4(){
    std::cout<< "Triangle, the Point is on the vertex\n";
    Polygon triangle(3);
    triangle[0] = {-1, -1};
    triangle[1] = {0, 1};
    triangle[2] = {1, -1};
    Point p = {1, -1};
    bool inside = (isInside(triangle, p)? true:false);
    return (inside? true:false);
}

bool test5_1(){
    std::cout<< "Rhombus, the Point is on the level of a vertex inside the figure\n";

    Polygon rhombus(4);

    rhombus[0] = {-1, 0};
    rhombus[1] = {0, 1};
    rhombus[2] = {1, 0};
    rhombus[3] = {0, -1};
    Point p = {0, 0};

    bool inside = (isInside(rhombus, p)? true:false);
    return (inside? true:false);

}

bool test5_2(){
    std::cout<< "Rhombus, the Point is on the level of a vertex outside the figure\n";

    Polygon rhombus(4);
    
    rhombus[0] = {-1, 0};
    rhombus[1] = {0, 1};
    rhombus[2] = {1, 0};
    rhombus[3] = {0, -1};
    Point p = {2, 0};

    bool inside = (isInside(rhombus, p)? true:false);
    return (inside? false:true);

}

bool test6_1(){
    std::cout<< "Concave Polygon, (G-letter-figure), the Point is in the inner region, but outside the figure\n";

    Polygon concave(12);
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
    
    Point p = {4, 3};
    
    bool inside = (isInside(concave, p)? true:false);
    return (inside? false:true);
}

bool test6_2(){
    std::cout<< "Concave Polygon, (G-letter-figure), the Point is inside the figure\n";

    Polygon concave(12);
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
    
    
    Point p = {1, 3};
    bool inside = (isInside(concave, p)? true:false);
    return (inside? true:false);
}
