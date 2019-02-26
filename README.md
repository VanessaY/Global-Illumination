# Global-Illumination

## Checkpoint 1 - Barebones
![](https://github.com/VanessaY/Global-Illumination/blob/master/Images/Checkpt%201.PNG)
### Issues
I'm having quite a few problems.
* Camera
    * Rotating the camera is fine, but moving the camera is not. I've pulled the camera back a ways and altered the viewing angle and focus length so that the spheres (seen above) don't look janky. I fixed what I thought was the problem (transforming a point, a 4d vector with components XYZW, now normalizes so that the new X is X/W). This has not fixed it, though. Instead, it now disappears if it's moved away from the origin. I'm not sure why.
    * I have band-aided this by simply moving the spheres in world space.
    * Relevant files:
         * Point.cpp/.h for point transformation
         * Camera.cpp/h for camera view matrix initialization
         * Raytracer.cpp for camera parameters

* Triangle Intersection
    * I have not been able to get the triangle intersection to work. I know that it's not the ray spawning portion, because spheres work just fine, including collisions. Thus, it has to be the intersection function. I am still kind of unsure as to how Barycentric coordinates work, so I have simply copied what was on the slides. To my knowledge, they are correct.
    * As of right now, no triangle is showing up because the function is returning 0 for omega.
    * Relevant files:
         * Vector.cpp/.h for vector functions like add, subtract, dot, and cross
         * Triangle.cpp/.h for triangle intersection.


## Setting the Scene
![](https://github.com/VanessaY/Global-Illumination/blob/master/Setting%20the%20Scene/Img.PNG)
Everything is in XYZ order
### Plane
* Scale: 1 x 1 x 2
* Position: 5, 6, -3
* Rotation: 0, 0, 0

### Glass sphere
* Scale: 4 x 4 x 4
* Position: 4, 9, -3
* Rotation: 0, 0, 0

### Metal sphere
* Scale: 3 x 3 x 3
* Position: 7, 8, 0
* Rotation: 0, 0, 0

### Point light
* Position: 3, 13, -9

### Camera
* Position: 5, 10, -12
* Rotation: 6, 0, 0
