# Global-Illumination

## Checkpoint 1 - Barebones

Barebones

![](https://github.com/VanessaY/Global-Illumination/blob/master/Images/Checkpt1Update.PNG)

Side view!

![](https://github.com/VanessaY/Global-Illumination/blob/master/Images/Checkpt1Sideview.PNG)
### Issues
~~I'm having quite a few problems.~~ I fixed all my problems! Writeup of problems is in past commits, I've cleared them and replaced them with how I fixed them. You can look at the history of this readme for my shame.
* Camera
    * I found out a few things.
         * Even though Eigen is column major, you still enter it in row major order. I think it has worked. There's probably something screwy with camera, but I've not noticed it. Coordinates are weird, though. I'm probably just not visualizing them correctly, though. 
* Triangle Intersection
    * This was a dumb mistake. I simply didn't translate the third point. Oops.


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
