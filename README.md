# PointInPolygon

The function for calculationg is the point is inside the polygon or not. The polygon is defined by the coordinates of the vertices. We assume that the coords are placed in sequentially, in the clockwise order. The polygon can be concave, but without self-intersecting. 

To build the project run the following commands in the command line (from the project root folder):

mkdir build && cd build
cmake ..
cmake -build .

To run tests:
ctest -C Debug

To run the programm itself run:
./polygon       # on Linux / macOS

./Debug/polygon.exe     # on Windows

Currently the main function contains similar functions as in test, just to show results. Will be updated soon.