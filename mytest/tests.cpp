#include <gtest/gtest.h>
#include "geometry.h"

TEST(TriangleWithPointInside, ReturnsExpected) {
    /// Simple triangle, the Point is inside
    Polygon triangle(3);
    triangle[0] = {-1, -1};
    triangle[1] = {0, 1};
    triangle[2] = {1, -1};
    Point point = {0, 0};
    EXPECT_TRUE(isInside(triangle, point));
}

TEST(TriangleWithPointOutside, ReturnsExpected) {
    /// Simple triangle, the Point is outside
    Polygon triangle(3);
    triangle[0] = {-1, -1};
    triangle[1] = {0, 1};
    triangle[2] = {1, -1};
    Point point = {2, 0};
    EXPECT_FALSE(isInside(triangle, point));
}

TEST(TriangleWithPointOnRightEdge, ReturnsExpected) {
    ///Triangle, the Point is on the edge
    Polygon triangle(3);
    triangle[0] = {-2, -1};
    triangle[1] = {0, 1};
    triangle[2] = {2, -1};
    Point point = {1, 0};
    EXPECT_TRUE(isInside(triangle, point));
}

TEST(TriangleWithPointOnVertex, ReturnsExpected) {
    ///Triangle, the Point is on the vertex
    Polygon triangle(3);
    triangle[0] = {-2, -1};
    triangle[1] = {0, 1};
    triangle[2] = {2, -1};
    Point point = {1, -1};
    EXPECT_TRUE(isInside(triangle, point));
}

TEST(RhombusPointInsideOneIntersection, ReturnsExpected) {
    ///Rhombus, the Point is on the level of a vertex INSIDE the figure(the "ray" should come throw the vertex 
    ///     and this test shows that the algorythm works correctly even if estimation ray has only 1 "intersection")

    Polygon rhombus(4);

    rhombus[0] = {-1, 0};
    rhombus[1] = {0, 1};
    rhombus[2] = {1, 0};
    rhombus[3] = {0, -1};
    Point point = {0, 0};
    EXPECT_TRUE(isInside(rhombus, point));
}

TEST(RhombusPointOutsideOneIntersection, ReturnsExpected) {
    ///Rhombus, the Point is on the level of a vertex OUTSIDE the figure(the "ray" should come throw the vertex 
    ///     and this test shows that the algorythm works correctly even if estimation ray has only 1 "intersection")

    Polygon rhombus(4);

    rhombus[0] = {-1, 0};
    rhombus[1] = {0, 1};
    rhombus[2] = {1, 0};
    rhombus[3] = {0, -1};
    Point point = {2, 0};
    EXPECT_FALSE(isInside(rhombus, point));
}

TEST(ConcaveWithPointInside, ReturnsExpected) {
    ///Concave Polygon, (G-letter-figure), the Point is in the inner region, but outside the figure

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
    
    Point point = {1, 3};
    
    EXPECT_TRUE(isInside(concave, point));
}


TEST(ConcaveWithPointOutside, ReturnsExpected) {
    ///Concave Polygon, (G-letter-figure), the Point is in the inner region, but outside the figure

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
    
    Point point = {4, 3};
    
    EXPECT_FALSE(isInside(concave, point));
}